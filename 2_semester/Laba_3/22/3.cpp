#include <iostream>
using namespace std;

int func(int number, int power, int div)
{
    power = power % (div-1);
    number= number % div;
    int res = 1;
    for (int x =1; x<=power; x++)
    {
        res*=number;
        res= res % div;
    }
    return res;
}

int main()
{
    int number, power, div;
    cout << "Enter a number and a power of the number: ";
    cin >> number >> power;
    cout << "Enter a div: ";
    cin >> div;
    cout << "res is " <<  func(number, power, div);
}