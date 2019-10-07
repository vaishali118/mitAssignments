import nmap
nm=nmap.PortScanner()
scanned=nm.scan('192.168.43.139-175','1')
print(scanned)
for host in nm.all_hosts():
	print(host)
	print('Host:'+host+ '('+nm[host].hostname()+')')
	print('status:'+nm[host].state())
	print('protocols:'+str(nm[host].all_protocols()))
        
	for proto in nm[host].all_protocols():
		#print(nm[host][proto].keys())
		#print('mac address:' + nm['host'][hostip]['addresses']['mac'])
		for port in nm[host][proto].keys():
			print(nm[host][proto][port]['product'])
	print('')
