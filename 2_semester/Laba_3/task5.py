import os.path
def is_no_simpl(x):
	n = int(x / 2 + 1)
	a = list(range(n+1))
	a[1] = 0
	lst = []
	i = 2
	while i <= n:
	    if a[i] != 0:
	        lst.append(a[i])
	        if x % a[i] == 0:
	        	return True
	        for j in range(i, n+1, i):
	            a[j] = 0
	    i += 1
	return False

def task_3(number, power, div):
	number %= div
	mod = 1
	for i in range(power):
		mod *= number
		mod %= div
	return mod

def create_open_key():
	if os.path.exists('okey') == True:
		print("key already created")
		return map(int, open('okey').read().split())

	q = int(input("input core of simpl open key"))
	p = 2*q+1
	while is_no_simpl(q) or  is_no_simpl(p) :
		print("it's no simpl number or it doesn't fit")
		q = int(input("input simpl number"))
		p = 2*q + 1


	g = int(input("input generator: "))
	while task_3(g, q, p) == 1:
		print("it number doesn't fit")
		g = int(input("input other number: "))

	
	f = open('okey', 'w')
	f.write(str(g)+' '+str(p))
	f.close()
	return g, p

def create_close_key(g, p):	
	name = input("input name: ")
	if os.path.exists(name+".ckey") == True:
		print("you already have a key")
		f = open(name+".ckey", 'r')
		X, Y = map(int, f.read().split())
	else:
		f = open(name+".ckey", 'w')
		X = int(input("input close key: "))
		Y = task_3(g, X, p)
		f.write(str(X)+' '+str(Y))
	f.close()	
	f = open("users", 'r+')
	is_find = False
	for line in f:
		if line.find(name) == 0:
			is_find = True
	if is_find == False:
		f.write('\n'+name +' '+ str(Y))
	return name, X, Y

def send_messege(Z, name, username):# Ceaser
	alpha = ' abcdefghijklmnopqrstuvwxyz,.!?*1234567890=-+'
	while True:
		mes = input().strip()
		res = ''
		for c in mes:
			res += alpha[(alpha.index(c) + Z) % len(alpha)]
		f = open(username, 'w')
		f.write(res)
		f.close()

def wait_massege(Z, name):
	alpha = ' abcdefghijklmnopqrstuvwxyz,.!?*1234567890=-+'
	while True:
		input("update?")
		if os.path.exists(name) == True:
			print("you have new messege!")
			f = open(name)
			mes = f.read()
			res = ''
			for c in mes:
				res += alpha[(alpha.index(c) - Z) % len(alpha)]
			f.close()
			print(res)
			os.remove(name)
		else:
			print("you dont have messege...")

def find_user(name):
	f = open("users", 'r+')
	is_find = False
	for line in f:
		if line.find(name) == 0:
			is_find = True
			Y = int(line.split()[1])
	if is_find == False:
		Y = -1
	return Y

def main():
		g, p = create_open_key()
		print("g :: %d p :: %d" %(g,p))
		name, X, Y = create_close_key(g, p)
		print("you key :: %d, publish key :: %d" %(X,Y))

		username = input("write name interlocutor: ")
		user_pub_key = find_user(username)
		if user_pub_key == -1:
			print("interlocutor no find")
		else:
			Z = task_3(user_pub_key, X, p)
		is_wait_mes = True if input("wait or send? (w/s)").lower() == 'w' else False
		if is_wait_mes == True:
			wait_massege(Z, name)
		else:
			send_messege(Z, name, username)

if __name__ == "__main__":
    main()