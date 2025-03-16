def bin2dec(N):
    dec = 0
    pow = 0
    rem = 0
    while N!= 0:
        rem = N%10
        dec = dec + rem*2**pow
        N = N//10
        pow+=1

    return dec
print(bin2dec(11))

def oct2hex(O):
    dec = 0
    pow = 0
    rem = 0
    while O != 0:
        rem = O%10
        dec = dec + rem*8**pow
        O=O//10
        pow += 1
    
    hex = "0123456789ABCDEF"
    h=""

    while dec != 0:
        rem = dec%16
        h = hex[rem] + h
        dec = dec//16
    return h

print(oct2hex(256))