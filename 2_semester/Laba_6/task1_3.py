import random

def is_main_simetr(vec):
	n = len(vec)
	for i in range(n-1):
		for j in range(i+1,n):
			if (vec[i][j] != vec[j][i]):
				return	False
	return True

def is_nomain_simetr(vec):
	n = len(vec)
	for i in range(n-1):
		for j in range(n-(i+1)):
			if (vec[i][j] != vec[n - 1 - j][n - 1 - i]):
				return	False
	return	True


n = 3
n = int(input())
main_vector = []
for _ in range(n):
	main_vector.append([int(random.random() * 100) % 5 + 1 for _ in range(n)])

for line in main_vector:
	for item in line:
		print(item, end=' ')
	print()


if is_main_simetr(main_vector):
	print("YES")
else:
	print("NO")

if is_nomain_simetr(main_vector): 
	print("YES")
else:
	print("NO")