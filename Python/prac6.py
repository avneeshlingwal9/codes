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
def addb():
    n = input("Enter the number :- ")
    m = input("Enter another number :- ")
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