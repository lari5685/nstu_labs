
def add_friend(friends, name_1, name_2):
	if name_1 == name_2:
		return
	if type(friends.get(name_1)) != type(set()):
		friends[name_1] = set()
	if type(friends.get(name_2)) != type(set()):
		friends[name_2] = set()
	friends[name_1].add(name_2)
	friends[name_2].add(name_1)

def count_friend(friends, name_1):
	if type(friends.get(name_1)) != type(set()):
		return 0
	return len(friends.get(name_1))

def is_friend(friends, name_1, name_2):
	if type(friends.get(name_1)) != type(set()):
		return False
	for item in friends.get(name_1):
		if item == name_2:
			return True
	return False



friends = {'a': {'b'}, 'b' : {'a'}}
while True:
	args = list(input().split())
	comand = args[0]
	if (comand == "FRIENDS" or comand == "0"):
		add_friend(friends, args[1], args[2])
	if (comand == "COUNT" or comand == "1"):
		print(count_friend(friends, args[1]))
	if (comand == "QUESTION" or comand == "2"):
		if is_friend(friends, args[1], args[2]):
			print('YES')
		else:
			print('NO')