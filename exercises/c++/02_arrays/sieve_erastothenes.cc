#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

int isPrimeNumber(unsigned int n){

	bool isPrime = true;
	size_t n_top = sqrt(n);

	if (n == 0 || n==1) {
		isPrime = false;
	}
	else {
		for (size_t i=2; i<=n_top; ++i) {
			if (n%i == 0) {
				isPrime= false;
				break;
			}
		}
	}
//	if (isPrime)
//		cout << n << " is a prime number" << endl;

	return isPrime;
}

int main() {

	cout << "Please insert an integer number N up to you want the primes numbers: ";
	int64_t N;
	while(!(cin >> N) || N <= 0) {
		std::cout << "\t Bang!!! you have to introduce the length, i.e. a positive integer number. Please, try again!\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return -1;

	}

	unsigned int i{0};
	/* Let's allocate memory in the heap, because the size of the array is known at runtime*/

	clock_t start = clock();

	auto primes = new unsigned int[N];


	primes[0] = 2; //First element of the prime numbers
	for (size_t n{3}; n<=N; ++n){
		if(isPrimeNumber(n))
			primes[++i] = n;
	}

	for (size_t j{0}; j<=i; ++j)
		cout << "primes[" << j << "] =" << primes[j] << endl;

	clock_t end = clock();
        double delta_t = double(end-start)/CLOCKS_PER_SEC;

        cout << "Time is:\n" << delta_t << endl;

	delete[] primes;

	return 0;


}
