#include <iostream>
#include <vector>
#include <time.h>
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


int main() {

	unsigned int n_max = 100;

	clock_t start = clock();

	vector<size_t> primes;

//	primes.push_back(2); //First prime number
	for (size_t n{2}; n <= n_max; ++n){
		if (isPrimeNumber(n)) {
			primes.push_back(n);
		}
	}

	cout << "There are " << primes.size() << " primes:" << endl;
	for (size_t j{0}; j<primes.size(); ++j)
		cout << primes[j] << endl;

	clock_t end = clock();
        double delta_t = double(end-start)/CLOCKS_PER_SEC;

        cout << "Time is:\n" << delta_t << endl;


	return 0;

}
