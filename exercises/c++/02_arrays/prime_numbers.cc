#include <iostream>
#include <time.h> //To measure the time of the program
using namespace std;

int isPrimeNumber(const unsigned int n){

	bool isPrime = true;

	if (n == 0 || n==1) {
		isPrime = false;
	}
	else {
		for (size_t i=2; i<=(0.5*n); ++i) {
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

/* Function that prints all prime numbers from 0 to 100*/
int prime_numbers(const unsigned int n) {

	for (std::size_t i{2}; i < n; ++i){
		for (std::size_t j{2}; j < i; ++j) {
			if ( i % j == 0)
				break;
			else if (i == j+1)
				std::cout << i << std::endl;

		}
	}


}


int main() {

	unsigned int n_max = 100;
	unsigned int i{1};

//	prime_numbers(n);

	clock_t start = clock(); //Starting to measure the time

	auto primes = new int[n_max]; //Allocating space in the heap

	primes[0]=2; //First prime number
	for (size_t n{3}; n < n_max; ++n){
		if (isPrimeNumber(n)) {
			primes[i++] = n;
		}
	}

	for (size_t j{0}; j<i; ++j)
		cout << "primes[" << j << "] =" << primes[j] << endl;

	clock_t end = clock(); //end to measure time
	double delta_t = double(end-start)/CLOCKS_PER_SEC;

	cout << "Time is:\n" << delta_t << endl;

	delete[] primes; //Free the memory in the heap

	return 0;

}
