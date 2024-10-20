def conversion(a,b,n):
    idex = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    c =""
    d = 0
    dct = dict()
    mdct = dict()
    for i in range(len(idex)):
        dct[i]= idex[i]
    for i in range(len(idex)):
        mdct[idex[i]]= i 
    if a==10:
        n = int(n)
        while(n!=0):
            k = n%b
            c=dct[k]+c
            n = int(n/b)
        return c
    elif b ==10:
        for i in range(len(n)):
            s = n[::-1]
            d = d+(mdct[s[i]])*(a**i)
        return d 
    else :
        n = conversion(a,10,n)
        n = conversion(10,b,n)
        return n 
    
l = int(input("Enter the number of times you want to use : - "))
for i in range(l):
    a = int(input("Enter the radix from you want to convert : - "))
    b = int(input("Enter the radix you want to convert to : -  "))
    n = input("Enter the number : - ")
    print("Conversion is : - " , conversion(a,b,n))











