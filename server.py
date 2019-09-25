import socket
import sys

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
port = 3125
s.bind(('0.0.0.0', port))
print ('Socket binded to port 3125')
s.listen(3)
print ('socket is listening')



while True:
    c, addr = s.accept()
    print ('Got connection from ', addr)

    print("")
    usr1 = int(input("Enter shared prime number:"))#prime.......#g
    usr2 = int(input("Enter shared base number:"))#base or primitive....#n
    print("")
    print("Shared prime is:",usr1)
    print("Shared base is:",usr2)
    print("")

    pr_k1 = 6 #...x
    pr_k2 = 15 #...y

    B = str((usr1**pr_k2) % usr2)

    A=int(c.recv(1024))
    print ("New public key received from client:",A)
    
    c.send(B.encode())
    key2 = (A**pr_k2) % usr2
    print("Shared msg from client:",key2)
    c.close()


'''import socket                                         

serversocket = socket.socket(
	        socket.AF_INET, socket.SOCK_STREAM) 

host = socket.gethostname()                           

port = 9999                                           

serversocket.bind((host, port))                                  

serversocket.listen(5)                                           

while True:
  
   clientsocket,addr = serversocket.accept()      

   print("Got a connection from %s" % str(addr))
    
   msg = 'Thank you for connecting'+ "\r\n"
   clientsocket.send(msg.encode('ascii'))
   g = int(input("Enter shared prime from server:"))
   #clientsocket.close()
'''
