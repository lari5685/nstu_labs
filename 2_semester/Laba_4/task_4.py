'''

Выполнить программную реализацию метода «шаг младенца, шаг великана» и
алгоритма исчисления порядка и решить с помощью компьютера следующие
уравнения: 
	2^x mod 30203 = 24322

'''

import math
def find_x(a, p, y):
	m = int(math.sqrt(p)) + 1
	u =[]
	
	for j in range(1, m):
		u.append((a ** (j*m)) % p)

	find_i = 0
	while True:
		v = (y * a ** find_i % p)

		if v in u:
			find_j = u.index(v) + 1
			break
		find_i += 1

	x = (m * find_j - find_i) % p

	return x
	
def main():
	print("2^x mod 30203 = 24322")
	print("x =", find_x(2, 30203, 24322))

if __name__ == "__main__":
	main()