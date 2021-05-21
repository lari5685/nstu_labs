def graf(gr, color, k = 0):
	n = len(gr)
	is_find = False
	if k == 0:
		color[0] = 1
		graf(gr, color, 1)
		return
	if k == n:
		for i in range(0, n):
			for j in range(0, n):
				if gr[i][j] == 1:
					if color[i] == color[j]:
						return False
		return True
	while (not is_find):
		color[k] = color[k] + 1
		if color[k] > n:
			color[k] = 0
			return False
		is_find = graf(gr, color, k+1)
	return True

def main():
	m = [[0,1,1,0,0,0,0,0],[1,0,1,0,0,0,0,0],[1,1,0,1,1,1,0,0],[0,0,1,0,0,0,0,0],[0,0,1,0,0,1,0,0],[0,0,1,0,1,0,1,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,1,1,0]];
	l = [[0,0,0,0,0,0,0,1,0,0,0],[0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,0,1],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,0],[0,0,0,0,0,0,0,1,0,0], [1,1,1,1,0,1,1,0,1,1], [0,0,0,0,0,1,0,1,0,0], [0,0,0,1,0,0,0,1,0,0]]
	gr = [[0,1,1,1],[1,0,0,1],[1,0,0,1], [1,1,1,0]]
	color = [0 for i in range(10)]
	graf(l, color)
	print(color)
	print(max(color))

main()