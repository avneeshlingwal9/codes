import socket
NETWORK = {
    '192.168.1.1': '00:0A:95:9D:68:16',
    '192.168.1.2': '00:0A:95:9D:68:17',
    '192.168.1.3': '00:0A:95:9D:68:18',
    '192.168.1.4': '00:0A:95:9D:68:19',
    '192.168.1.5': '00:0A:95:9D:68:1A',
    '192.168.1.6': '00:0A:95:9D:68:1B',
    '192.168.1.7': '00:0A:95:9D:68:1C',
    '192.168.1.8': '00:0A:95:9D:68:1D',
    '192.168.1.9': '00:0A:95:9D:68:1E',
    '192.168.1.10': '00:0A:95:9D:68:1F',
}
SERVER_IP = '127.0.0.1'
SERVER_PORT = 12546
serversocket = socket.socket(socket.AF_INET , socket.SOCK_STREAM)
serversocket.bind(('127.0.0.1' , SERVER_PORT))
serversocket.listen(5)
while True:
    c,addr = serversocket.accept()
    print(f"Connected to {addr}")
    ip = c.recv(1024).decode()
    mac = NETWORK.get(ip)
    if mac is not None:
        c.send(mac.encode())
    else:
        c.send("Not found".encode())
    
    
    

serversocket.close()