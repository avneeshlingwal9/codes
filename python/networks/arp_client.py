import socket


arp_cache ={}
port = 12546

while True:
    with socket.socket(socket.AF_INET , socket.SOCK_STREAM) as s : 
        s.connect(('localhost' , port))
        ip = input("Enter the ip address: ")
        s.sendall(ip.encode())
        mac = s.recv(1024).decode()
        if(mac != 'Not found'):
            arp_cache[ip] = mac
        print(f"The MAC address is {mac}")

    




