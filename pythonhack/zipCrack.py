import zipfile

f = open("dictionary.txt","r")
listofpass=f.readlines()
for password in listofpass:
	print password[:-1]
	try:
		zipF = zipfile.ZipFile("secure.zip")	
		zipF.extractall(pwd=password[:-1])
		print "Trying the password",password[:-1]
		print password[:-1],"is the matching password"
		break
	except:
		print password[:-1], "not matching"
