def selective_clear(m,n):
    if ((m =="0" and n=="0")or ( m=="1" and n =="0") or( m=="0" and n=="1")):
        return "0"
    elif  (m=="1" and n=="1"):
        return "1"
def compl(n):
    if n=="1":
        return "0"
    elif n=="0":
        return "1"
def cpln(n):
    l=""
    for i in n :
        l+=compl(i)
    return l 

def sell():
    n = input("Enter a number :- ")
    m = input("Enter another number :- ")
    m = cpln(m)
    print(m)
    
    res=""
    if len(m)>= len(n):
        for i in range(len(n)-1,-1,-1):
            res=selective_clear(m[i],n[i])+res
        for i in range(len(m)-1,len(n),-1):
            res=selective_clear(m[i],"0")+res
        return res 
    elif len(n)>len(m):
        for i in range(len(m)-1,-1,-1):
            res=selective_clear(m[i],n[i])+res
        for i in range(len(n)-1,len(m),-1):
            res=selective_clear(n[i],"0")+res
        return res 
print(sell())
