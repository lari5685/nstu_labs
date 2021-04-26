def sliv(res, ans, n):
	if n == 1:
		return res
	number = n
	k = 1
	for i in range(n-1,0,-1):
		if ans[i-1] == '+':
			res = res - number + number*10 + n + 1
			return res
		elif ans[i-1] == '-':
			res = res + number - number*10 - n - 1
			return res
		elif ans[i-1] == '_':
			number += i * 10**k
			k += 1
	return res - number + number*10 + n + 1


def fun(m, n, res, ans):
	if (n == 9):
		if (res == m):
			ans[8] = '2'
		else:
			ans[8] = '1'
		return ans
	ans[n-1] = '+'
	if fun(m, n+1, res+n+1, ans)[8] == '2':
		return ans
	ans[n-1] = '-'
	if fun(m, n+1, res-n-1, ans)[8] == '2':
		return ans
	ans[n-1] = '_'
	if fun(m, n+1, sliv(res, ans, n), ans)[8] == '2':
			return ans
	return ans

a = fun(12+3456789, 1, 1, ['0','0','0','0','0','0','0','0','0'])
s = ''
for i in range(8):
	s += str(i+1)
	if a[i] != '_':
		s += ' ' + a[i] + ' '
s+='9'
print(s)