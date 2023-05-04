#include <iostream>
using namespace std;



int fibonacci(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	n = fibonacci(n - 1) + fibonacci(n - 2);
	return n;
}

void fibAusgabe(int n)
{
	for(int i = n; i >= 0; i--)
	{
		cout << fibonacci(i) << endl;
	}
}

int main()
{
	int n = 38;
	fibAusgabe(n);

	return 0;
}
