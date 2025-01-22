def counte(b):
    if b =="up":
        return True
    elif b == "down":
        return False 
def decimal_to_binary(n):
    k = ""
    while(n!=0):
        k = (str(n%2))+k
        n = int(n/2)
    k = "00000"+k
    return k

i = 0 

while ((i >=0) and (i <16)):
    k = input("Enter whether up or down : - ")
    if counte(k):
        i+=1
        print(decimal_to_binary(i)[-5:])
    elif counte(k) == False:
        i-=1
        print(decimal_to_binary(i)[-5:])
else :
    print("You have exhausted the counter ")






