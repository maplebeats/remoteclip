#coding=utf-8

import socket
import time
BUF_SIZE = 1024
host = "0.0.0.0"
port = 9999

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind((host, port))

server.listen(1)

client, address = server.accept()

while True:
    data = client.recv(BUF_SIZE)
    print(data)
    client.send("ok\n")
    time.sleep(1)

