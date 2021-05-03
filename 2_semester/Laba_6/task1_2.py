N = 3
M = 3;
N, M = map(int,input().split())
temp = [0 for i in range(M)]
vec = []

for i in range(N):
	vec.append(list(map(int, input().split())))

max_index = vec.index(max(vec))
min_index = vec.index(min(vec))
vec[max_index], vec[min_index] = vec[min_index], vec[max_index]

for vect in vec:
	for item in vect:
		print(item, end = ' ')
	print()