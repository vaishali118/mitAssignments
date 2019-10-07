import crypt

f = open('mypassword.txt','r')
mypasshash = f.read()
mypass = mypasshash.split(':')[1]
print mypass
h_id,salt = mypass.split('$')[1:3]
print h_id
print salt
'''h_id =6
salt = 'wO9LRFdiLN.zOyO0'
input_salt = '${}${}'.format(h_id, salt)
print input_salt
password = 'abc123'

calcHashValue = crypt.crypt(password, input_salt)
print(calcHashValue)'''
