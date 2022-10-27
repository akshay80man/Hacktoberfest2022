// C++ program to check if a number
// is good prime or not
#include<bits/stdc++.h>
using namespace std;

// Function to check if a
// number is Prime or not
bool isPrime (int n)
{

	// Corner cases
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	// This is checked so that we can
	// skip middle five numbers in loop
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for(int i = 5; i * i <= n; i += 6)
	{
	if (n % i == 0 || n % (i + 2) == 0)
		return false;
	}
	return true;
}

// Function to check if the
// given number is Good prime
bool isGoodprime (int n)
{

	// Smallest good prime is 5
	// So the number less than 5
	// can not be a Good prime

	if (n < 5)
		return false;

	int prev_prime = n - 1;
	int next_prime = n + 1;

	while (prev_prime >= 2)
	{
		
		// Calculate first prime number < n
		while (!isPrime(prev_prime))
		{
			prev_prime--;
		}

		// Calculate first prime number > n
		while (!isPrime(next_prime))
		{
			next_prime++;
		}

		// Check if product of next_prime
		// and prev_prime is less than n^2
		if ((prev_prime * next_prime) >= n * n)
			return false;

		prev_prime -= 1;
		next_prime += 1;
	}
	return true;
}

// Driver code
int main()
{
	int n = 11;

	if (isGoodprime(n))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}

// This code is contributed by himanshu77
