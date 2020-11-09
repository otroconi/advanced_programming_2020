#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>
using namespace std;

/*This is the algorithm advise from wikipedia using vector*/
int main(){

	cout << "Please insert an integer number N up to you want the primes numbers: ";
	int64_t N;
	while(!(cin >> N) || N <= 0) {
		std::cout << "\t Bang!!! you have to introduce the length, i.e. a positive integer number. Please, try again!\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return -1;

	}

	size_t n_top = sqrt(N);

	clock_t start = clock();//starting the clock

	vector<bool> primes(N, true);

	for (size_t i{2}; i<n_top; ++i){
		if (primes[i]){
			for (size_t j{i*i}; j<=N; j+=i){
				primes[j] = false;
			}
		}
	}

	for (size_t i{2}; i<=N; ++i)
		if (primes[i])
			cout << i << endl;

	clock_t end = clock(); //end to measure time
	double delta_t = double(end-start)/CLOCKS_PER_SEC;

	cout << "Time is:\n" << delta_t << endl;

	return 0;

}
