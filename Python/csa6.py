def decimal_to_binary(n):
    k = ""
    while(n!=0):
        k = k +(str(n%2))
        n = int(n/2)
    return k[::-1]
def summ( m ,n ,c):
    s = '0' 
    if ( m== '0' and n =='0' and c =='0' ):
        s = '0' 
        c = '0' 
        return (s,c)
    elif ( (m =='0' and n =='1' and c =='0') or ( m=='1' and n =='0' and c =='0')):
        s = '1' 
        c = '0' 
        return (s,c)
    elif ( m == '0' and n == '0' and c == '1'):
        s = '1' 
        c = '0'
        return (s,c)
    elif ( (m== '0' and n == '1' and c =='1') or ( m=='1' and n == '0' and c=='1')):
        s = '0'
        c ='1'
        return (s,c)
    elif ( m == '1' and n == '1' and c =='0'):
        s = '0' 
        c = '1' 
        return (s,c)
    elif ( m== '1' and n =='1' and c == '1'):
        s = '1'
        c ='1'
        return (s,c)
    else :
        return "Error","Error"


def sum_binary(n,m):
    n_binary = n[::-1]
    m_binary = m[::-1]
    r_binary = ""
    c= '0'
    s = '0' 
    i =0
    j = 0 
    if  len(n_binary)> len(m_binary):
        while i < len(n_binary):
            if j >= len(m_binary):
                s,c = summ(n_binary[i],'0',c)
                r_binary= s + r_binary
                i+=1

            else :
                s,c = summ(n_binary[i],m_binary[j],c)
                r_binary=s+r_binary
                i+=1 
                j+=1
    elif  len(m_binary)> len(n_binary):
        while j < len(m_binary):
            if i >= len(n_binary):
                s,c = summ('0',m_binary[j],c)
                r_binary= s+r_binary
                j+=1

            else :
                s,c = summ(n_binary[i],m_binary[j],c)
                r_binary=s+r_binary
                i+=1 
                j+=1
    else : 
        while(i < len(n_binary)):
            s,c = summ(n_binary[i],m_binary[j],c)
            r_binary= s+r_binary
            i+=1 
            j+=1

    r_binary = c + r_binary
    return r_binary

n = input("Enter a number : - ")
m = input("Enter a number : - ")
print("sum:- ", sum_binary(n,m))





