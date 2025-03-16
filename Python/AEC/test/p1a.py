marks1 = int(input("Enter the marks for subject 1 "))
marks2 = int(input("Enter the marks for subject 2 "))
marks3 = int(input("Enter the marks for subject 3 "))

if marks1 > marks3 and marks2 > marks3:
    avg = ( marks1 + marks2 )/2
elif marks1 > marks2 and marks3 > marks2:
    avg = ( marks1 + marks3 )/2
else:
    avg = (marks2 + marks3)/2

print(f"the average out of the best two is {avg}")
