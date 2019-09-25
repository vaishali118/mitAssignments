import socket
import struct

s = socket.socket()
port = 3125
s.connect(('localhost', port))
print("")
usr1 = int(input("Enter shared prime number:"))#prime.......#g
usr2 = int(input("Enter shared base number:"))#base or primitive....#n

print("")
print("Shared prime is:",usr1)
print("Shared base is:",usr2)
print("")

pr_k1 = 6 #...x
pr_k2 = 15 #...y

A = str((usr1**pr_k1) % usr2)

#z = input("enter key")
s.send(A.encode())
B = int(s.recv(1024))
print("New public key received from server:",B)
key1 = (B**pr_k1) % usr2
print("Shared msg from server:",key1)
s.close()


'''import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 

host = socket.gethostname()                           

port = 9999

s.connect((host, port))                               

msg = s.recv(1024)                                     

s.close()
print (msg.decode('ascii'))
'''
