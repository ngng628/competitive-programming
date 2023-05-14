# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

s = str.chars
t = str.chars

shash = s.tally
thash = t.tally

atcoder = ['a', 't', 'c', 'o', 'd', 'e', 'r']
atcoder.each do |c|
  shash[c] = 0
  thash[c] = 0
end
shash['@'] = 0
thash['@'] = 0

if shash != thash
  puts "No"
  exit
end

shash = s.tally
thash = t.tally

atcoder.each do |c|
  shash[c] = 0 unless shash.has_key?(c)
  thash[c] = 0 unless thash.has_key?(c)
end
shash['@'] = 0 unless shash.has_key?('@')
thash['@'] = 0 unless thash.has_key?('@')

atcoder.each do |c|
  if shash[c] < thash[c]
    diff = (shash[c] - thash[c]).abs
    if shash['@'] >= diff
      shash['@'] -= diff
    else
      puts "No"
      exit
    end
  elsif shash[c] > thash[c]
    diff = (shash[c] - thash[c]).abs
    if thash['@'] >= diff
      thash['@'] -= diff
    else
      puts "No"
      exit
    end
  end
end

puts "Yes"