# record Edge, from : Int32, to : Int32, weight : Int32 do
#   property from
#   property to
#   property weight
# end

class Edge
  property from : Int32
  property to : Int32
  property weight : Int32

  def initialize(@from, @to, @weight)
  end
end

e = Edge.new(0, 0, 0)
a = [e]
p! a[0].from
a[0].from = 999
p! a[0].from
