require "nglib/utils"

n = int
s = (1..n).map { line = str.chars; t = line.reverse5; {line, t}.min }
puts s.uniq.size
