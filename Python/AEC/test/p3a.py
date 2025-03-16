def count(Sent):
    wc = dc = uc = lc = 0
    wc = len(Sent.split())
    
    for char in Sent:
        if char.isdigit():
            dc +=1
        elif char.isupper():
            uc += 1
        elif char.islower():
            lc += 1

    return wc,dc,uc,lc

S = input("Enter the sentence ")

wc, dc , uc ,lc = count(S)

print(f"word count is {wc} \ndigit count is {dc}\n lower count is {lc}\n upper count is {uc}")
