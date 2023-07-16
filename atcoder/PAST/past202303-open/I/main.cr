def int(b = 0)
  read_line.to_i64 + b
end

def ints(b = 0)
  read_line.split.map { |x| x.to_i64 + b }
end

def str
  read_line.chomp
end

macro chmax(a, b)
 ({{a}} <= {{b}} && ({{a}} = {{b}}))
end

macro chmin(a, b)
 ({{a}} >= {{b}} && ({{a}} = {{b}}))
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

record Hand, n : Int32, c : Char, index : Int32 do
  include Comparable(Hand)

  def <=>(other : self)
    if n == other.n
      if c != other.c
        other.c <=> c
      else
        other.index <=> index
      end
    else
      n <=> other.n
    end
  end
end

n = int
x = str.chars
s = (1..n).map { str.chars }
ans = (0...n).map { |i|
  res = Hand.new(Int32::MIN, '?', -1)
  x.each_combination(3) do |(x1, x2, x3)|
    s[i].each_combination(2) do |(s1, s2)|
      hand = {x1, x2, x3, s1, s2}
      ni = 0
      ci = '?'
      ('A'..'Z').reverse_each do |alpha|
        if chmax(ni, hand.count(alpha))
          ci = alpha
        end
      end
      chmax(res, Hand.new(ni, ci, i + 1))
    end
  end
  res
}.sort![-1].index

puts ans
