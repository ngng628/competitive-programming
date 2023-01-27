main = -> {
}

def int(b = 0); gets.to_i + b end
def ints(b = 0); gets.split.map{ |x| x.to_i + b } end
def str; gets.chomp end
OO = (1<<62)-(1<<31)
main[]
