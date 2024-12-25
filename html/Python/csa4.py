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
def twos_complement(n):
    k = n[::-1]
    twos = ""
    l = 0 
    for j in k :
        if j=="1":   
            twos=j+twos
            l+=1
            break 
        else : 
            twos=j+twos
            l+=1
    while(l<len(k)):
        twos=ones_comp(k[l])+twos
        l+=1
    return twos 
a = input("Enter the binary number :- ")
print("Ones complement : - ", ones_compliment(a))
print("Twos complement : - " , twos_complement(a))


    


