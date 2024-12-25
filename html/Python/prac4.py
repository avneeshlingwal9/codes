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
def two_s():
    k = input("Enter a number :- ")
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
print(ons_c())
print(two_s())


