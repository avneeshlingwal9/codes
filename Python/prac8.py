def selective_set(m,n):
    if (m =="0" and n=="0"):
        return "0"
    elif ((m=="0" and n=="1")or (m=="1" and n=="0")or(m=="1"and n=="1")):
        return "1"
def sel():
    n = input("Enter a number :- ")
    m = input("Enter another number :- ")
    res=""
    if len(m)>= len(n):
        for i in range(len(n)-1,-1,-1):
            res=selective_set(m[i],n[i])+res
        for i in range(len(m)-1,len(n),-1):
            res=selective_set(m[i],"0")+res
        return res 
    elif len(n)>=len(m):
        for i in range(len(m)-1,-1,-1):
            res=selective_set(m[i],n[i])+res
        for i in range(len(n)-1,len(m),-1):
            res=selective_set(n[i],"0")+res
        return res 
print(sel())