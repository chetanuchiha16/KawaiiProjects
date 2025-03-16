def palin(N):
    S = str(N)
    rev = S[::-1]
    if rev == S:
        print( "the given integer is palindrome ") 
    else:
        print("The int is not palindrome ")
    for i in range(10):
        if S.count(str(i)) > 0:
            print(f"{str(i)} occurs {S.count(str(i))} times")

palin(2321)

    

