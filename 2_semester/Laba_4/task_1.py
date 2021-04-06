'''
В одномерном массиве, состоящем из n вещественных элементов, вычислить:
1. Сумму отрицательных элементов.
2. Произведение элементов, расположенных между максимальным и минимальным
элементами.
Упорядочить элементы массива по возрастанию.
'''

from random import *

def generator(count, is_print):
	main_list = []
	for _ in range(count):
		main_list.append(randint(-10,10)) 
	if is_print:
		print(main_list)
	return main_list

def task_1(main_list):
	sumElemets = 0
	for element in main_list:
		if element < 0:
			sumElemets += element
	return sumElemets

def find_min(main_list):
	min = 101
	for element in main_list:
		if min > element:
			min = element
	return min

def	find_max(main_list):
	max = -101
	for element in main_list:
		if max < element:
			max = element
	return max

def find_min_element(main_list):
	min = find_min(main_list)
	for i in range(len(main_list)):
		if min == main_list[i]:
			return i

def find_max_element(main_list):
	max = find_max(main_list)
	for i in range(len(main_list)):
		if max == main_list[i]:
			return i

def task_2(main_list):
	min = find_min_element(main_list)
	max = find_max_element(main_list)
	if max > min:
		first = min
		second = max
	else:
		first = max
		second = min
	multiply = 1
	for i in range(first, second):
		multiply *= main_list[i]
	return multiply


def main():
	count = 10 #int(input("enter n: "))

	main_list = generator(count, True)

	print(task_1(main_list))

	print(task_2(main_list))



if "__main__" == __name__:
	main()