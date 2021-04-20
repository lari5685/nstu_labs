def func(number_f, power_f, divisor_f):
    number_f= number_f % divisor_f
    remainder = 1
    for i in range (1, power_f+1):
        remainder*=number_f
        remainder= remainder % divisor_f
    return remainder

print("Enter a number and a power of the number: ")
number, power =map(int, input().split())
print("Enter a divisor: ")
divisor = int(input())
print("Remainder is", func(number, power, divisor))