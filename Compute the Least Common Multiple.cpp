#include <iostream>
#include <algorithm> 

#include <cmath> 
#include<vector> 

using namespace std;

long GCD(long a, long b);
long long lcm(long long a, long long b) ;

int main() {
	long long a, b;
	cin >> a >> b;
	
	cout <<  lcm(a, b) << endl;
}

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

long long lcm(long long a, long long b) 
{
 long long lcmm;
 if(GCD(a,b)!=0)
 { lcmm = (a*b)/(GCD(a,b)) ;}
 else
 { lcmm= a*b;}
 
 return lcmm;
	

}