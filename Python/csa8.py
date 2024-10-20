def orr(a,b):
    if (a =="0" and b =="0") :
        return "0"
    elif (( a =="1" and b == "0") or ( a == "0" and b =="1") or ( a == "1" and b =="1")):
        return "1"
def selective_selection(a,b):
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
a = input("Enter a number :- ")
b = input("Enter another number : -  ")
print("Selective selection : - ", selective_selection(a,b))

