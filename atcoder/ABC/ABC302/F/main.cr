require "nglib/utils"

module NgLib
  class BinaryBfsGraph
    private struct Edge
      getter to : Int32
      getter weight : Int32
      def initialize(t : Int, w : Int)
        @to = t.to_i32
        @weight = w.to_i32
      end
    end

    getter size : Int32
    getter graph : Array(Array(Edge))

    # $n$ 頂点 $0$ 辺からなるグラフを作成します。
    #
    # ```
    # graph = BfsGraph.new(n)
    # ```
    def initialize(n : Int)
      @size = n.to_i64.to_i32
      @graph = Array.new(@size) { [] of Edge }
    end

    # 辺 $(u, v, w)$ を追加します。
    #
    # $w$ は $0$ または $1$ である必要があります。
    #
    # `directed` が `true` の場合、
    # 有向グラフとみなして、$u$ から $v$ への辺のみ生やします。
    #
    # ```
    # graph = BfsGraph.new(n)
    # graph.add_edge(u, v)                 # => (u) <---w---> (v)
    # graph.add_edge(u, v, directed: true) # => (u) ----w---> (v)
    # ```
    def add_edge(u : Int, v : Int, w : Int, directed : Bool = false)
      raise Exception.new("w should be 0 or 1") unless w.in?({0, 1})
      @graph[u.to_i32] << Edge.new(v, w)
      @graph[v.to_i32] << Edge.new(u, w) unless directed
    end

    # 全点対間の最短経路長を返します。
    #
    # ```
    # dists = graph.shortest_path
    # dists # => [[0, 1, 3], [1, 0, 2], [1, 1, 0]]
    # ```
    def shortest_path
      (0...@size).map { |s| shortest_path(s) }
    end

    # 始点 `start` から各頂点への最短経路長を返します。
    #
    # ```
    # dist = graph.shortest_path(start: 2)
    # dist # => [3, 8, 0, 7, 1]
    # ```
    def shortest_path(start : Int)
      deque = Deque.new([start.to_i32])
      dist = Array.new(@size) { |i| i == start ? 0_i64 : OO }
      until deque.empty?
        from = deque.shift
        @graph[from].each do |e|
          d = dist[from] + e.weight
          if d < dist[e.to]
            dist[e.to] = d
            if e.weight == 0
              deque.unshift(e.to)
            else
              deque << e.to
            end
          end
        end
      end
      dist
    end

    # 始点 `start` から終点 `dest` への最短経路長を返します。
    #
    # ```
    # dist = graph.shortest_path(start: 2, dest: 0)
    # dist # => 12
    # ```
    def shortest_path(start : Int, dest : Int)
      shortest_path(start)[dest]
    end
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

n, m = ints
graph = NgLib::BinaryBfsGraph.new(n + m)
n.times do |i|
  a = int
  s = ints -1
  s.each do |j|
    graph.add_edge(i, n + j, 0, directed: true)
    graph.add_edge(n + j, i, 1, directed: true)
  end
end
ans = graph.shortest_path(start: 0 + n, dest: m - 1 + n)
puts ans >= OO ? -1 : ans - 1
