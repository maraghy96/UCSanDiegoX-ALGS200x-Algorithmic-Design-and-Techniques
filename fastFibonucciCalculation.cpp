#include<iostream>

#include <cmath> 
#include<vector> 

using namespace std;


uint64_t Fibo(uint64_t  f[50000], int n) {

	//if (f <= 1) { return 1; }

	//else
	//	return Fibo(f - 1) + Fibo(f - 2);
	
	f[0] = 0;
	f[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];

	}
	return f[n];

}

int main()

{


	int n;
	cin >> n;
	uint64_t f[50000];
	cout <<  Fibo(f, n) << endl;






	return 0;

}