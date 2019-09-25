

def isprime(q):
    for i in range(2,int(q**0.5)+1):
        if q%i==0:
            return False

    return True
n = input("enter value of n:")
g = input("enter value of g:")
x = input("enter value of x:")
y = input("enter value of y:")

if isprime(n) and isprime(g):
    A = pow(g,x)%n
    B = pow(g,y)%n
    K1 = pow(B,x)%n
    K2 = pow(A,y)%n
    if K1==K2:
        print"key exchange successfull."
    else:
        print"key is corrupted."
else:
    print"invalid input."

