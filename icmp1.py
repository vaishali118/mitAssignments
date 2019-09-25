from scapy.all import *
import sys
conf.verb = 0
end=""
str1=[]
im =0
start =""
s1 = 0
e1 = 0
init_ip = ""
base_ip=""
target_ip=""
found = False
if(len(sys.argv)==1):
	print("please enter an ip address")
else:
	t_ip = sys.argv[1]
	for i in range (len(t_ip)):
		if(t_ip[i] == '-'):
			found = True
			im = i
			for j in range(i,len(t_ip)):
				for k in range (0,1):
					str1.append(str(t_ip[j]))

	if found == True:	
		for i in range(1,len(str1)):
			end = end+str(str1[i])

		for i in range(10,im):
			start = start+str(t_ip[i])

		s1 = int(start)
		e1 = int(end)


		for i in range(0,im):
			init_ip = init_ip+str(t_ip[i])
	
		for i in range(0,10):
			base_ip = base_ip+str(t_ip[i])
		

		if (e1 > s1):
			for i in range(s1,e1+1):
				target_ip=base_ip+str(i)
				request = IP(dst=target_ip)/ICMP()
				reply = sr1(request,timeout=2)
				if(reply is None):
					print target_ip, "is not reachable"
				else:
					print target_ip, "ip is up"
		elif(start > end):
			print("Invalid ip input please enter the ip in ascending order")
		else:
			print("both start ip and end ip cannot be same")
	else:
		for i in range (len(t_ip)):
			target_ip = target_ip+str(t_ip[i])
		request = IP(dst=target_ip)/ICMP()
		reply = sr1(request,timeout=2)
		if(reply is None):
 			print t_ip, "is not reachable"
		else:
			print t_ip, "ip is up"
