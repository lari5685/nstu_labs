def task_1(vec, M):
	temp = [0 for i in range(M)]
	for item in vec:
		for i in range(M):
			item[i] = 10000000000 * (i+1);

def main():
	N = 3
	M = 3
	N, M = map(int,input().split())
	vec = []

	for i in range(N):
		vec.append([])
		for _ in range(M):
			vec[i].append(0)

	task_1(vec, M)

	for vect in vec:
		for item in vect:
			print(item, end = ' ')
		print()
	
main()