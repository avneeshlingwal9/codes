import socket



port = 1812

while True:
    with socket.socket(socket.AF_INET , socket.SOCK_STREAM) as s : 
        s.connect(('localhost' , port))
        toask = input("Enter the ip address: ")
        s.sendall(toask.encode())
        mac = s.recv(1024).decode()
        print(f"MAC address is {mac}")


    




