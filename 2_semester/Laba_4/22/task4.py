def  step(a, b, p):
	m = int(p ** (0.5) + 1)
	a_vector = []
	for i in range(0,m):
		a_vector.append(a**((i+1)*m)%p)

	for j in range(0,m):
		temp = (a**j)*b % p
		for i in range(0,m):
			if a_vector[i] == temp:
				return (i+1)*m - j

print(step(2, 21740, 30323))


