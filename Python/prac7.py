def addit(m,n,c):
    if (m == "0" and n =="0" and c=="0"):
        return('0','0')
    elif(m =="0" and n == "1" and c =="0"):
        return('1','0')
    elif(m =="1" and n == "0" and c =="0"):
        return('1','0')
    elif(m =="1" and n == "1" and c =="0"):
        return('0','1')
    elif(m =="0" and n == "1" and c =="1"):
        return('0','1')
    elif(m =="1" and n == "1" and c =="1"):
        return('1','1')
    elif(m =="0" and n == "0" and c =="1"):
        return('1','0')
    elif(m =="1" and n == "0" and c =="1"):
        return('0','1')
def addb(n,m):
    sm=""
    c="0"
    res=""
    if len(m) >= len(n):
        for i in range(len(n)-1,-1,-1):
            sm,c = addit(m[i],n[i],c)
            res=sm+res
        for i in range(len(m)-1,len(n),-1):
            sm,c = addit(m[i],"0",c)
            res+=sm+res
    elif len(n) >= len(m):
        for i in range(len(m)-1,-1,-1):
            sm,c = addit(n[i],m[i],c)
            res=sm+res
        for i in range(len(n)-1,len(m),-1):
            sm,c = addit(n[i],"0",c)
            res=sm+res
    if c=="1":
        res=c+res
    return res
def ons(n):
    if n=="1":
        return "0"
    elif n=="0":
        return "1"
def ons_c():
    k = input("Enter a number : - ")
    l =""
    for i in k:
        l+=ons(i)
    return l 
def two_s(k):
    k = k[::-1]
    j= ""
    m = 0 
    for i in range(len(k)) : 
        if k[i]!= "1":
            j +="0" 
            m+=1
        elif k[i] == "1":
            j+="1"
            m +=1
            break 
    for i in range(m,len(k)):
        j+=ons(k[i])
    return j[::-1]
def sub():
    n = input("Enter the number to subtract from :- ")
    m = input("Enter the number to be subtracted from: - ")
    m = two_s(m)
    r = addb(n,m)
    return r
print(sub())

