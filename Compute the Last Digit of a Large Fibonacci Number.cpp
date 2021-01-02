#include<iostream>

#include <cmath> 
#include<vector> 

using namespace std;


long long Fibo(long long f[1000000], int n) {

	//if (f <= 1) { return 1; }

	//else
	//	return Fibo(f - 1) + Fibo(f - 2);


	f[0] = 0;
	f[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		f[i] = (( f[i - 1]  +  f[i - 2]) % 10);

	}
	return f[n] ;


}


int main()

{


	int n;
	cin >> n;
	long long f[1000000];
	cout << Fibo(f, n) << endl;

	return 0;

}
