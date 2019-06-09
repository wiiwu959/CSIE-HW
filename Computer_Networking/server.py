from socket import *
import socket

host = '127.0.0.1'
port = 80
serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket.bind((host, port))
serverSocket.listen(5) 
print("Server is ready on port:",port)

while True:
	connectionSocket, addr = serverSocket.accept()
	try:
		print("Connection from: " + str(addr))
		message = connectionSocket.recv(1024)
		filename = message.split()[1]
		print(message.decode())
		
		f = open(filename[1:], 'r')
		connectionSocket.sendall("200 OK\n\n".encode())
		
		for l in f.readlines():
			print('Sent ', repr(l))
			connectionSocket.sendall(l.encode())
			l = f.read(1024)
	except IOError:
		connectionSocket.sendall("404 Not Found\n".encode())
	connectionSocket.close()