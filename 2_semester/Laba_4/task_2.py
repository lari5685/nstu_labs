'''

С клавиатуры вводятся два числа a, b (1 ≤ 𝑎 ≤ 𝑏 ≤ 𝑛). Необходимо отсортировать по
неубыванию все элементы с номерами от a до b, после чего вывести на экран.

'''

from random import *


def generator(count):
	main_list = []
	for _ in range(count):
		main_list.append(randint(-100,100)) 
	return main_list

def sort_list(main_list, first, second):
	for i in range(first, second+1):
		for j in range(i, second+1):
			if main_list[i] < main_list[j]:
				main_list[i], main_list[j] = main_list[j], main_list[i]

def main():
	count = 10 #int(input(Enter n: ))
	first = 2  #int(input(Enter a: ))
	second= 8  #int(input(Enter b: ))

	main_list = generator(count)

	for element in main_list:
		print(element, end = ' ')
	print()

	sort_list(main_list, first, second)

	for element in main_list:
		print(element, end = ' ')
	print()



if __name__ == "__main__":
	main()