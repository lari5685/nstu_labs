import math

def modul(num, pow, div): #find modul in a^x mod m = modul task3
	num= num % div
	res = 1
	for i in range (1, pow+1):
		res*=num
		res= res % div
	return res


def find_d(number, divisor): #find D in C*D mod m = 1 task4
	z_1 = 1; z_2=0 
	first = divisor
	second = number
	q=(first // second)
	remainder = (first % second)

	while remainder != 0:
		z = z_2 - q * z_1
		first = second
		second = remainder
		q = first // second
		remainder = first % second
		z_2 = z_1
		z_1 = z

	if z < 0: 
		z += divisor

	return z

def decode(line): # string to vector <int>
	decode_line = []
	for item in line:
		decode_line.append(ord(item))
	return decode_line;

def main():
	public_key = 293

	private_key_C = int(input("Enter your privat key: "))
	private_key_D = find_d(private_key_C, public_key-1)

	answer = input("Send or receive(s/r): ")
	if answer == 's':
		line = input("Enter your message: ")							# m
		dec_line = decode(line)

		print("Say this key B(x1): ")
		for  item in dec_line:
			print(modul(item, private_key_C, public_key), end = " ") 	# x1
		print()

		x2_line = list(map(int, input("Enter code from B(x2): ").split()))# x2
		print("Say this key B(x3): ")
		for item in x2_line:
			print(modul(item, private_key_D, public_key), end = " ") 	# x3
		print()
	elif answer == 'r':
		x1_line = list(map(int, input("Enter code from A(x1): ").split()))# x3

		print("Say this key A(x2): ")
		for item in x1_line:
			print(modul(item, private_key_C, public_key), end = " ") # x2
		print()

		x3_line = list(map(int, input("Enter code from A(x3): ").split())) # x3
			
		print("Your message: ");
		for item in x3_line:
			print(chr(modul(item, private_key_D, public_key)), end = "") # x4 or m
	


if __name__ == "__main__":
	main()