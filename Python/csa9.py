def exor(a,b):
    if ((a == "1" and b =="0") or (a=="0" and b=="1")):
        return "1" 
    elif ((a =="0" and b == "0" ) or ( a =="1" and b == "1")):
        return "0" 
def selective_complement(a,b):
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
a = input("Enter a number : - " )
b = input("Enter another number : - ")
print("Selective complement is : - ", selective_complement(a,b))