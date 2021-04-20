import math

def graf_2(x,n):
	res=0
	for i in range(0,n):
		res += x**(2*i)/(math.factorial(2*i))
	return res

def main():
	print("x\t","ch(x)")
	for i in range (0,10):
		print(str(i) + "\t"+ str(graf_2(i,10)))


if __name__ == "__main__":
	main()
