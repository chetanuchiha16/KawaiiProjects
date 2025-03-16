string1 = input ("Enter the string 1: ")
string2 = input ("Enter the string 2: ")

if len(string1) < len(string2):
    low = len(string1)
    high = len(string2)
else:
    low = len(string2)
    high = len(string1)

match_count = 0
for i in range(low):
    if string1[i] == string2[i]:
        match_count += 1
sim = 0
sim = match_count/high
print(sim)