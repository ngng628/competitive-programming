require "nglib/utils"
require "nglib/data_structure/static_range_sum"
require "nglib/data_structure/sparse_table"

class StronglyConnectedComponents
  alias Graph = Array(Array(Int64))

  getter leader : Array(Int64)
  getter graph : Graph
  getter groups : Array(Array(Int64))
  @n : Int64
  @order : Array(Int64)
  @fwd : Graph
  @bwd : Graph
  @closed : Array(Bool)

  def initialize(@fwd : Graph)
    @n = @fwd.size.to_i64
    @order = Array(Int64).new(@n)
    @leader = Array.new(@n, -1_i64)
    @bwd = Array.new(@n){ Array(Int64).new }
    @n.times do |i|
      @fwd[i].each do |j|
        @bwd[j] << i
      end
    end

    @closed = Array(Bool).new(@n, false)
    @n.times{ |i| dfs(i) }
    @order = @order.reverse
    ptr = rdfs

    @graph = Array.new(ptr){ Array(Int64).new }
    @groups = Array.new(ptr){ Array(Int64).new }
    @n.times do |i|
      @groups[@leader[i]] << i
      @fwd[i].each do |j|
        x, y = @leader[i], @leader[j]
        next if x == y
        @graph[x] << y
      end
    end
  end

  def same(u : Int, v : Int)
    leader[u] == leader[v]
  end

  def size
    @groups.size
  end

  def size(v : Int)
    @groups[leader[v]].size
  end

  private def dfs(i : Int)
    return if @closed[i]
    @closed[i] = true
    @fwd[i].each{ |j| dfs(j) }
    @order << i
  end

  private def rdfs
    ptr = 0_i64
    closed = Array.new(@n, false)
    @order.each do |s|
      next if closed[s]
      que = Deque(Int64).new
      que << s
      closed[s] = true
      @leader[s] = ptr
      until que.empty?
        now = que.shift
        @bwd[now].each do |nxt|
          next if closed[nxt]
          closed[nxt] = true
          @leader[nxt] = ptr
          que << nxt
        end
      end
      ptr += 1
    end
    ptr
  end
end

struct Int64
  def self.inf
    OO
  end
end

require "nglib/graph/weighted_edge"
require "nglib/graph/dijkstra"

class Array(T)
  def compress
    b = clone.sort.uniq
    map{ |s| b.bsearch_index{ |x| x >= s } || b.size }
  end

  def mapping
    b = clone.sort.uniq
    f, g = Hash(Int64, Int64).new, Hash(Int64, Int64).new
    each do |s|
      index = b.bsearch_index{ |x| x >= s } || b.size
      f[s] = index
      g[index] = s
    end
    {f, g}
  end
end

#                                           .O,                                        
#                                          :o.                                         
#                                        'd'          :c;.                            c
#                                       lc  dKl     ;d,.,cl:.           oOx.           
#                                     .x.   .,.   'd:.......:ll;.       'lc            
#                                   .;0;        .ol............'col;.                  
#                                .:do;xl       cd'.................,col;.              
#                           .,cdd:'   od     'x;........:..............':ol;.          
#                     ..;lddc,.       od    od....l:...;x.........,........,lo;        
#              .,:loodl;.          .,,kx. .kk:....k,...lo........od.........;.:x,      
#       .,coool:,.                  ....;lkodl....O:...dk.......;Oo........:x...oo     
#    :dl;'.                                .lk:...Ok...xkc......xcx.......,k'....:x    
#  ;k,                                        :x:.Olx'.O'd;....;o.O......;Oc......cx   
#  O,                       .                   ;xO;.cOO..ll,..l: x,...,dck,.......dc  
#  k:                      lKd                    oO. KK   .;cld; dc;lOc.;d........,0  
#  dl                       .                      cx.cO.         .,.KW..x'.........0. 
#  oc         .ll;.                                 :k.l:            ;l,k,...;:.....0. 
#  o,         kkxkOOOOOOOOOkkkkxl:'.                 ;x.,.           .dOoccod:.....cO  
#  x..o.     lOxxxxxxxxxxxxxxxxxxkXOOdc'              oc    .l;,,,;coo:...ol......o0,  
#  O  '     xOxxxxxxxxxxxxxxxxxxxxKOxxkOOd;           .0.   '0:ccc:,,,0ccd;....;lx0l   
# .x      .Okxxxxxxxxxxxxxxxxxxxxx0KxxxxxxkOo.         O'    do'''''''OllOkoooolckl    
# ;l     .OkxxxxxxxxxxxxxxxxxxxxxxOKxxxxxkOxk0l        kkollll0kdoddxkK0Oxllooool.     
# c:     kKxxxxxxxxxxxxxxxxxxxxxxx0XkxxxxkXxxxOO       k'  ;d. .k,....':ok0dc;..   .'::
# o,    xO00xxxxxxxxxxxxxxxxxxxxxxKOKxxxxxXdoOk0;     .O  ;d  .k.         .cd,ckccc;lx,
# d,   c0xx0Kkxxxxxxxxxxxxxxxxxxx0O.KkxxxkX. .0K;     lk:lOo;;Oo;kd;     ' .x;:c      .
# d,  .0KxxxkK0kxxxxxxxxxxxxxxxx0k. l0xxxOx   O0     'O::k; .kckO: Okollxxkx. k.       
# d,  xod0xxxxK00OxxxxxxxxxxxxO0l.  'XxxkK'  ;K,    .Oxxo.  .o x: ;O;;xo..K. l:        
# l;  0:;d0xxxkO.;ok0OkO00OkO0l.     KkkKc';d0,   ;olxx     ,dd; 'Kkkk, 'Oc 'x         
# :l  K:;;o0kxxKc   .':c..:o,.       O0OlO0Kd. 'ol. :d      lO' ;00x;. ck'  O.         
# 'x  0c;;;cO0xkXk,               '. cdk00x..cOx   ol     .od.  ,c.  'k;   d;          
#  0. kl;;;;;oO0OK0,              ,ccO00KOokk.'x. o:   'cx0; .::c:. od    ;d           
#  ;d..xd:;;;;;cdkkk,...    ..';llc::,...   ;d..xkc  .klld.      ol ol   .k            
#    ,llokkolcccloddkK0K00ck00xodoo:.         cl '   .o..d:      c. ,k   k.            
#       .,:c::;,..  ;d  .0;k. ;lodxkKo         .d'        :x;'.....:xc  lc             
#                   lx :OOOol       'O           :o.        dOooodd0.  .O              
#                  lxc:,k:O .d;     ll            .dc        ld;;;;O'  l;              
#               .c, dk:k;.k   oOcc,,O.              ,x.       Oc;;;x:  x.              
#             .ld.'lkd;,:cdlc;;0, .:'                 dxcc:;,'kdllld0;',..    ;loodoool
#           ,ol.     .oo.    ...' .:::cccl:.           :x. .............';codOc;;;;;;;;
#        :kd,          co                 .'c,          'k.                  ,dx:;;;;;;
#         .:llld;,;:....O'                               .x:                  .ko;;;;;;
#               'lkcodxdxO.                                ;x,                :kc;;;;;;
#                ;k;;;;;;dx                                  o0'               ;Kd;;;;;

n = int
skills = (1..n - 1).map { ints }
q = int
queries = (1..q).map { ints }

graph = Array.new(n) { [] of NgLib::Edge }
scc_graph = Array.new(n) { [] of Int64 }
skills.each_with_index do |(l, a), i|
  graph[a - 1] << NgLib::Edge.new(i + 1, l)
  scc_graph[a - 1] << i + 1
end

scc = StronglyConnectedComponents.new(scc_graph)

# 技 i を覚えるのに必要な最小コスト
dist = [-OO] * n
dist[0] = 0
queue = Deque({Int64, Int64}).new
queue << {0_i64, -1_i64}
until queue.empty?
  from, par = queue.pop
  graph[from].each do |(to, w)|
    next if to == par
    chmax(dist[to], Math.max(dist[from], w))
    queue << {to, from}
  end
end

n.times do |i|
  dist[i] = OO if dist[i] == -OO
  dist[i] = OO if scc.size(i) >= 2
end

# 技 i を覚えるための最小コスト
rmq = NgLib::SparseTable(Int64).max(dist)

# レベル x 以下の技は何個？
lvs = [] of Int64
queries.each do |(t, x)|
  lvs << x if t == 1
end
f, g = (dist + lvs).mapping
cnt = [0_i64] * f.size
dist.each_with_index do |lv, i|
  cnt[f[lv]] += 1
end
csum = NgLib::StaticRangeSum(Int64).new(cnt)

queries.each do |(t, x)|
  y = x
  case t
  when 1
    ans = csum[0..f[x]]
    puts ans
  when 2
    ans = dist[y - 1]
    puts ans >= OO ? -1 : ans
  end
end
