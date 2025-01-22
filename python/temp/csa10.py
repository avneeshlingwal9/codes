def aand(a,b):
    if (( a == "0" and b =="0") or ( a =="1" and b =="0") or ( a =="0" and b =="1")):
        return "0"
    elif ( a =="1" and b =="1") :
        return "1"
def ones_comp(n):
    if n =="1":
        return "0"
    elif n =="0":
        return "1"
def ones_compliment(n):     
    res=""
    for i in n : 
        res+=ones_comp(i)
    return res 
def selective_clear(a,b):

    b_1 = a[::-1]
    b_2 = ones_compliment(b)[::-1]   
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
a = input("Enter a number :- ")
b = input("Enter another number : - ")
print(selective_clear(a,b))






