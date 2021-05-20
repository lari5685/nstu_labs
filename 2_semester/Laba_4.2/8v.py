def outdomino(spisok, keys):#вывод последовательности
	for i in keys:
		if i == -1:
			break
		print(spisok[i], end = ' ')
	print()

def revers(a, n):#переворачивает кость
	a[n][0], a[n][1] = a[n][1], a[n][0]

def domino(spisok, keys, n = 0):
	is_find = False#флаг нашли ли мы следующую кость
	if n == len(keys):# если все кости раставлены, выводим и выходим
		outdomino(spisok, keys) 
		return
	for i in range(len(spisok)):#проверяем все кости
		if i in keys:#если такая уже использовалась, пропускаем шаг
			continue
		if n == 0:#если мы в первые зашли в рекурсию
			is_find = True
			keys[0] = i#заполняем 0-ой элемент 
			domino(spisok, keys, 1)#входим в рекурсию для поиска остальных
			if spisok[i][1] != spisok[i][0]:# если кость не семетрична 
				revers(spisok, i)# переварачиваем
				domino(spisok, keys, 1)# и заходим еще раз
				revers(spisok, i)# возращаем на место
		elif spisok[i][0] == spisok[keys[n-1]][1]: # если 2 номер на прошлой кости совпадает с 1 номером i-ой кости
			keys[n] = i
			domino(spisok, keys, n+1)# входим глубже в рекурсию 
			keys[n] = -1# после выполнения, возрвщаем индекс к -1
			is_find = True 
		elif spisok[i][1] == spisok[keys[n-1]][1] and spisok[i][1] != spisok[i][0]: 
			#если 2 номер на прошлой кости совпадает с 2 номером i-ой кости и кость не семетрична
			keys[n] = i
			revers(spisok, i)# переварачиваем
			domino(spisok, keys, n+1)# входим глубже в рекурсию 
			revers(spisok, i)# возращаем на место
			keys[n] = -1
			is_find = True
	if not is_find:# если мы не нашли следующую кость 
		outdomino(spisok, keys)# выводим что у нас получилось
	return

def main():#здесь программа начинаеться
	spisok = [[1,2], [2,3], [5,6], [2,2], [5,3]] # здечь доступные кости
	keys = [-1 for i in range(len(spisok))] # запоняем масив для порядка костей -1(-1 это не занято)
	domino(spisok, keys)#входим в рекурсию

main()