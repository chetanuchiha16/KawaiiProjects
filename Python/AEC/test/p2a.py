def fib(N):
    if N == 1:
        return 0
    elif N == 2:
        return 1
    else:
        return fib(N-1) + fib(N-2)

Number = int(input("Enter the Number to find the "))
if Number < 0:
    print("Error")
else:
    print("the answer is ", fib(Number))