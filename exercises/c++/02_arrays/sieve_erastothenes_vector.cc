#include <iostream>
#include <cmath>
#include <vector>
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

	clock_t start = clock();

	vector<size_t> primes;

	for (size_t n{2}; n<=N; ++n){
		if(isPrimeNumber(n))
			primes.push_back(n);
	}

	cout << "There are " << primes.size() << " primes:" << endl;

	for (size_t j{0}; j<primes.size(); ++j)
		cout << primes[j] << endl;

	clock_t end = clock();
        double delta_t = double(end-start)/CLOCKS_PER_SEC;

        cout << "Time is:\n" << delta_t << endl;

	return 0;


}
