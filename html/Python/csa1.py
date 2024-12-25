def conversion(m,n,number):
    cnv = dict()
    ster = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    revd = dict()
    j = 0
    for i in ster:
        cnv[i] = j
        revd[j] = i 
        j+=1        
    if n==10  : 
        k = number[::-1]
        count = 0 
        cnvrt = 0 
        for h in k:
            cnvrt = cnvrt + (m**count)*(cnv[h])
            count+=1 
        return cnvrt     
    elif m == 10 :
        number = int(number)
        cnvrt = ""
        obj = ""
        while(number/n!=0):
            obj = revd[number%n]
            cnvrt=obj+cnvrt
            number = int(number/n)
        return cnvrt
    else : 
        num_1 = conversion(m,10,number)
        cnvrt = conversion(10,n,num_1)
        return cnvrt 
a = int(input("Enter the radix from you want to convert : -  "))
b = int(input("Enter the radix to you want to convert : -  "))
number = input("Enter the number : - ")
print(conversion(a,b,number))







    