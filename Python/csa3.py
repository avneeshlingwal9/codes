def decimal_to_binary(n):
    k = ""
    while(n!=0):
        k = k +(str(n%2))
        n = int(n/2)
    return k[::-1]
def bnary_to_decimal(n):
    k = 0 
    for i in range(len(n)):
        k = k + (2**i)*int(n[i])
    return k 

def exor(a,b):
    if ((a == "1" and b =="0") or (a=="0" and b=="1")):
        return "1" 
    elif ((a =="0" and b == "0" ) or ( a =="1" and b == "1")):
        return "0" 
def orr(a,b):
    if (a =="0" and b =="0") :
        return "0"
    elif (( a =="1" and b == "0") or ( a == "0" and b =="1") or ( a == "1" and b =="1")):
        return "1"
def aand(a,b):
    if (( a == "0" and b =="0") or ( a =="1" and b =="0") or ( a =="0" and b =="1")):
        return "0"
    elif ( a =="1" and b =="1") :
        return "1"
def exxor(a,b):
    b_1 = a[::-1]
    b_2 = b[::-1]   
    res = ""
    if len(a)>=len(b):
        for i in range(len(b)):
            res+=exor(b_1[i],b_2[i])
        for i in range(len(b),len(a)):
            res+=exor(b_1[i],"0")        
    if len(b)> len(a):
        for i in range(len(a)):
            res+=exor(b_1[i],b_2[i])
        for i in range(len(a),len(b)):
            res+=exor("0",b_2[i])
    return(res[::-1])                

def aorr(a,b):
    b_1 = a[::-1]
    b_2 = b[::-1]   
    res = ""
    if len(a)>=len(b):
        for i in range(len(b)):
            res+=orr(b_1[i],b_2[i])
        for i in range(len(b),len(a)):
            res+=orr(b_1[i],"0")        
    if len(b)> len(a):
        for i in range(len(a)):
            res+=orr(b_1[i],b_2[i])
        for i in range(len(a),len(b)):
            res+=orr("0",b_2[i])
    return(res[::-1]) 
def eand(a,b):
    b_1 = a[::-1]
    b_2 = b[::-1]   
    res = ""
    if len(a)>=len(b):
        for i in range(len(b)):
            res+=aand(b_1[i],b_2[i])
        for i in range(len(b),len(a)):
            res+=aand(b_1[i],"0")        
    if len(b)> len(a):
        for i in range(len(a)):
            res+=aand(b_1[i],b_2[i])
        for i in range(len(a),len(b)):
            res+=aand("0",b_2[i])
    return(res[::-1])
k = input("Enter a number : - ")
m = input("Enter a number :- ")
print("x-or = ",exxor(k,m))
print("or = ",aorr(k,m))
print("and = " ,eand(k,m))




