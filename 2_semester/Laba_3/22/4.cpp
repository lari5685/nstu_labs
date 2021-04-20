#include <iostream>

using namespace std;

int func(int number, int divisor)
{
    int z, z_1=1, z_2=0, q, remainder, first = divisor, second = number;
    q=(first / second);
    remainder = (first % second);

    while (remainder !=0 )
    {
        z=z_2-q*z_1;
        first = second;
        second = remainder;
        q=(first / second);
        remainder = (first % second);
        z_2=z_1;
        z_1=z;
    }

    if (z < 0) z += divisor;

    return z;
}

int main()
{
    int number_in, divisor_in;

    cout<<"Введите число и его делитель: ";
    cin >> number_in >> divisor_in;
    cout<<number_in<<" * z"<< " mod "<< divisor_in << " = 1" << endl;
    cout <<number_in<< " * " << func(number_in, divisor_in) << " mod "<< divisor_in << " = 1" << endl;

    return 0;
}
