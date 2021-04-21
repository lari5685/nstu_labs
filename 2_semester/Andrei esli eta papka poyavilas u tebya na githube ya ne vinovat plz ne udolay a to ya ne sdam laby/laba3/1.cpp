#include <iostream>
#include <map>
using namespace std; 

double F(double x)
{
	if (x <= -7)
		return 0;
	if (x <= -3)
		return x + 7;
	if (x <= 3)
		return x * x;
	if (x <= 4)
		return -2 * x + 8;
	return 0;

}

int main()
{
	map <double, double> function;
	for (double i = -9; i < 8; i += 1)
	{
			function[i] = F(i);
	}
	cout << " x  |  y" << endl << "----|----" << endl;	
	for (const auto& i : function) 
	{
    	if (i.first >= 0)
   			cout << " " << i.first << "  |  " << i.second <<endl;
   		else 
   			cout << i.first << "  |  " << i.second <<endl;
    }
}
