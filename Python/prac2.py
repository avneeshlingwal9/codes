def dec_to_binar(n):
    k =""
    n = int(n)
    while(n!=0):
        k = str(n%2)+k
        n = int(n/10)
    return k
def bnar_to_dec(n):
    k = 0 
    n = n[::-1]
    for i in range(len(n)):
        k = k + int(n[i])*(2**i)



    return k 



    


n = int(input("Enter a number :- "))
n_1 = int(input("Enter another number : - "))
print(bnar_to_dec('1000'))
print("Left shifting : - ", n >> n_1)
print("Right shifting : - ", n_1 <<n)
