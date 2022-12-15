import example

c = example.Coordinate(2, 5)
m = example.Matrix(c)
print(m)

print(m.getVal().getX())

m.doubleVal()

print(m.getVal().getX())

c2 = example.Coordinate(66, 77)
m.setVal(c2)

print(m.getVal().getX())