array = list(map(int, input().split()))
res  = []

for element in array[::-1]:
	string = str(element)
	string = string[::-1]
	a = int(string)
	res.append(a)
for element in res:
	print(element, end =  " ")

