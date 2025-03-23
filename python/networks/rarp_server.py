import socket
NETWORK = {
 '02:00:00:c4:59:ff' : '192.168.1.168',
 '02:00:00:ff:08:58' : '192.168.1.140',
 '02:00:00:07:ef:84' : '192.168.1.171',
 '02:00:00:68:a2:10' : '192.168.1.230',
 '02:00:00:5a:ff:91' : '192.168.1.115',
 '02:00:00:7f:bd:45' : '192.168.1.134',
 '02:00:00:d3:d0:d3' : '192.168.1.199',
 '02:00:00:47:89:c6' : '192.168.1.166',
 '02:00:00:4e:c2:4e' : '192.168.1.189',
 '02:00:00:7a:ba:68' : '192.168.1.92',
}
SERVER_IP = '127.0.0.1'
SERVER_PORT = 1812

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serversocket.bind((SERVER_IP , SERVER_PORT))
serversocket.listen(5)
while True:
    conn , addr = serversocket.accept()
    print(f"Connected to {addr}")
    mac = conn.recv(512).decode()
    ip = NETWORK.get(mac)
    if ip is not None:
        conn.sendall(ip.encode())
    else:
        conn.send("Unable to connect".encode())
serversocket.close()
