import socket

SERVER_IP = '127.0.0.1'
SERVER_PORT = 1812

while True:
    with socket.socket(socket.AF_INET , socket.SOCK_STREAM) as s:
        s.connect((SERVER_IP , SERVER_PORT))
        mac = input("Enter the MAC address: ")
        s.send(mac.encode())
        ip = s.recv(512).decode()
        print(f"The IP address assigned is  {ip}")