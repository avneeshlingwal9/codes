def decimal_to_binary(n):
    n = int(n)
    k = ""
    f = "00000"
    if n == "0":
        return f 
    while ( n!=0):
        k+=str(n%2)
        n = int(n/2)
    f = f+k[::-1]
    return f[-1:-6:-1][::-1]
n = input("Enter up or down:- ")
if n =="up":
    for i in range(32):
        print(decimal_to_binary(i))
elif n =="down":
    for i in range(31,-1,-1):
        print(decimal_to_binary(i))