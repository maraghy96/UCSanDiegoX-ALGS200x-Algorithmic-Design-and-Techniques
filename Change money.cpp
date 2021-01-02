#include<iostream>
#include<math.h>

using namespace std;

int minNumberOfCoins(int n);

int main()
{
	int m;
	cin >> m;

	cout << minNumberOfCoins(m) << endl;

}

int minNumberOfCoins(int n)
{
	int min = 0;
	if (n < 5) 
	{
		return n;

	}

	if (n > 5 && n < 10)
	{
		min = 1 + (n - 5);
		return min;

	}
	else
	{
		if (n % 10 == 0)
		{
			min = n / 10;

		}
		else if (n % 5 == 0)
		{
			int c = n - 5;
			min = 1 + (c / 10);
		}
		else 
		{
			min = ((n - (n % 10)) / 10) + minNumberOfCoins(n % 10);
		
		}

		return min;

	}


}
