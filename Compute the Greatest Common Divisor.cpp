#include <iostream>

#include <cmath> 
#include<vector> 

using namespace std;

long GCD(long a, long b)
{
	if (b ==0)
	{
		return a;

	}

	
		
			if (a>b) {
				long c = (a % b);
				return GCD(b, c);
			}
			else
			{
				long c = (b%a);
				return GCD(a, c);
			}
		
	
}
int main() {
  int a, b;
  cin >> a >> b;
  cout << GCD(a,b) << endl;
  return 0;
}
