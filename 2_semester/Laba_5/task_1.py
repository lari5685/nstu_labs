def create_train(Trains, Towns, name_train, args):
	for item in args:
		if type(Trains.get(name_train)) != type(set()):
			Trains[name_train] = set()
		if type(Towns.get(item)) != type(set()):
			Towns[item] = set()
		Trains[name_train].add(item)
		Towns[item].add(name_train)

def trains_for_town(Towns, name):
	res = ''
	res += name + " : "
	if type(Towns.get(name)) != type(set()):
		return 'ErrInput'
	for item in Towns.get(name):
		res += item + " "
	return res

def towns_for_train(Trains, Towns, name):
	res = ''
	if name != "":
		res += name + " : "
		if type(Trains.get(name)) != type(set()):
			return 'ErrInput'
		for item in Trains.get(name):
			res += item + " "
		res += "\n"
	for train in Towns: 
		res += "\n" + train + " : "
		for item in Towns.get(train):
			if (item != name):
				res += item + " ";
	
	return res


def trains(Trains, Towns):
	res = ''
	for train in Towns: 
		res += "\n" + train + " : "
		for item in Towns.get(train):
			res += item + " ";
	res += "\n"
	for train in Trains: 
		res += "\n" + train + " : "
		for item in Trains.get(train):
			res += item + " ";
	return res


Trains = { "train" : {"a", "b"}} 
Towns =  { "a" : {"train"}, "b" : {"train"}}
while True:
	args = list(input().split())		
	comand = args[0]
	if comand == "CREATE_TRAIN" or comand == '0':
		create_train(Trains, Towns, args[1], args[2:])
	if comand == "TRAINS_FOR_TOWN" or comand == '1':
		print(trains_for_town(Towns, args[1]))
	if comand == "TOWNS_FOR_TRAIN" or comand == "2":
		print(towns_for_train(Trains, Towns, args[1]))
	if comand == "TRAINS" or comand == "3": 
		print(trains(Trains, Towns))