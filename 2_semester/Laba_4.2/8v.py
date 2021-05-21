def outdomino(spisok, keys):
	for i in keys:
		if i == -1:
			break
		print(spisok[i], end = ' ')
	print()

def revers(a, n):
	a[n][0], a[n][1] = a[n][1], a[n][0]

def domino(spisok, keys, n = 0):
	is_find = False
	if n == len(keys):
		outdomino(spisok, keys)
		return
	for i in range(len(spisok)):
		if i in keys:
			continue
		if n == 0:
			is_find = True
			keys[0] = i
			domino(spisok, keys, 1)
			if spisok[i][1] != spisok[i][0]:
				revers(spisok, i)
				domino(spisok, keys, 1)
				revers(spisok, i)
		elif spisok[i][0] == spisok[keys[n-1]][1]: 
			keys[n] = i
			domino(spisok, keys, n+1)
			keys[n] = -1
			is_find = True
		elif spisok[i][1] == spisok[keys[n-1]][1] and spisok[i][1] != spisok[i][0]: 
			keys[n] = i
			revers(spisok, i)
			domino(spisok, keys, n+1)
			revers(spisok, i)
			keys[n] = -1
			is_find = True
	if not is_find:
		outdomino(spisok, keys)
	return

def main():
	spisok = [[1,2], [2,3], [5,6], [2,2], [5,3]]
	keys = [-1 for i in range(len(spisok))]
	domino(spisok, keys)

main()