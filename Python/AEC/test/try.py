#y = [print(f"Enter {x} ") or x for x in range(1,5)]
#print(y)
x=[4,3,2,1]
x.extend(x for x in [1,2,3,4])

print(x)