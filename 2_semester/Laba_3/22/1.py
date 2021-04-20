import math

def graf_1(x):
	if -5 <= x and x < -2:
		return -0.5*x - 1.5
	if -2 <= x and x <= 2:
		return 2*math.cos(2*x)
	if 2 < x and x <= 5:
		return 0.5*x - 1.5

def main():
	print("x\ty")
	for i in range (-5,5):
		print(str(i) + "\t"+ str(graf_1(i)))


if __name__ == "__main__":
	main()