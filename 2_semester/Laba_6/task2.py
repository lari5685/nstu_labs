
def decrypt(messege, key):
	k = 0
	encrypt_messege = ''
	slovar = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ/.,|+=-_()*&^%$#@!?1234567890"
	for item in messege:
		encrypt_messege += slovar[(slovar.find(item) - slovar.find(key[k]))%len(slovar)]
		k += 1
		if k == len(key): 
			k = -1
	return encrypt_messege

def encrypt(messege, key):
	k = 0
	encrypt_messege = ''
	slovar = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ/.,|+=-_()*&^%$#@!?1234567890"
	for item in messege:
		encrypt_messege += slovar[(slovar.find(item) + slovar.find(key[k]))%len(slovar)]
		k += 1
		if k == len(key): 
			k = -1
	return encrypt_messege


def main():
	messege = "Hello world"
	key = "m1r"

	print(messege, key)

	dec_messege = encrypt(messege, key)
	print(dec_messege)

	print(decrypt(dec_messege, key))

if __name__ == "__main__":
	main()