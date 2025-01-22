
def exxor():
    res =""
    m = input("Enter a number:- ")
    n = input("Enter another number : - ")
    if len(m) >= len(n) :
        for i in range(len(n)-1,-1,-1):
            res+= exxr(m[i],n[i])
        for i in range(len(m)-1,len(n)-1,-1):
            res+=exxr(m[i],'0')
        return res[::-1]
    if len(n) > len(m) :
        for i in range(len(m)-1,-1,-1):
            res+= exxr(m[i],n[i])
        for i in range(len(n)-1,len(m)-1,-1):
            res+=exxr('0',n[i])
        return res[::-1]
    


def exxr(m,n):
    if( (m =="0" and n=="0" ) or ( m =="1" and n =="1")):
        return "0"
    elif ( (m == "1" and n == "0")or (m =="0" and n =="1")):
        return "1"
    
def orr(m,n):
    if (m =="0" and n=="0" ):
        return "0"
    elif ((m == "1" and n == "0")or (m =="0" and n =="1")or ( m =="1" and n =="1")):
        return "1"
def aan(m,n):
    if( (m =="0" and n=="0" ) or ( m =="1" and n =="0")or ( m =="0" and n =="1")):
        return "0"
    elif (m == "1" and n == "1"):
        return "1"
def orrr():
    res =""
    m = input("Enter a number:- ")
    n = input("Enter another number : - ")
    if len(m) >= len(n) :
        for i in range(len(n)-1,-1,-1):
            res+= orr(m[i],n[i])
        for i in range(len(m)-1,len(n)-1,-1):
            res+=orr(m[i],'0')
        return res[::-1] 
    if len(n)> len(m) :
        for i in range(len(m)-1,-1,-1):
            res+= orr(m[i],n[i])
        for i in range(len(n)-1,len(m)-1,-1):
            res+=orr('0',n[i])
        return res[::-1] 
def aaan():
    res =""
    m = input("Enter a number:- ")
    n = input("Enter another number : - ")
    if len(m) >= len(n) :
        for i in range(len(n)-1,-1,-1):
            res+= aan(m[i],n[i])
        for i in range(len(m)-1,len(n)-1,-1):
            res+=aan(m[i],'0')
        return res[::-1] 
    if len(n)> len(m) :
        for i in range(len(m)-1,-1,-1):
            res+= aan(m[i],n[i])
        for i in range(len(n)-1,len(m)-1,-1):
            res+=aan('0',n[i])
        return res[::-1] 
print(exxor())
print(aaan())
print(orrr())
print(orr('1','0'))
