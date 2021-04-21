import math
def find_x(number, divisor):
	z_1 = 1; z_2 = 0 
	first = divisor
	second = number
	q = first // second
	remainder = first % second

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

d, m = 7, 10
print("%d * D mod %d = 1" %(d, m))
print("D =", find_x(7, 10))