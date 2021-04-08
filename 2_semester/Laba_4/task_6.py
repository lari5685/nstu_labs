#поиск самого большого палиндрома 
def find_max_palindrom(s):
	s2 = ['*']*(len(s)*2+1)
	for i in range(len(s)):
		s2[i*2+1] = s[i]

	p = [0] * len(s2) 
	c = 0
	maxLen = 1

	for i in range(len(s2)):

		while (i > p[i] and (i + p[i] + 1) < len(s2) and s2[i - p[i] - 1] == s2[i + p[i] + 1]):
			p[i] += 1

		if maxLen < p[i] :
			maxLen = p[i]
			begin = (i - maxLen) // 2

	return s[begin : begin + maxLen]


def main():
	string = "xxxaabaabaahxxcaacaac"
	print(find_max_palindrom(string))

if __name__ == "__main__":
	main()