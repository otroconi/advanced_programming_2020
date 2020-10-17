#include <iostream>
#include <limits>

void get_int(int64_t& n){

	while(!(std::cin >> n)){
		std::cout << "\t Bang!!! Bad choice, give me an integer press enter and give me the same integer again\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		std::cin >> n;
	}

	std::cout << "cin takes valid this number\n" << n << std::endl;
}


void get_double(double& N){

	while(!(std::cin >> N)){
		std::cout << "\t Bang!!! bad choice, give me a double press enter and give me the same double again\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		std::cin >> N;
	}
 
	std::cout << "cin takes valid this number\n" << N << std::endl;
	
}

int main(){

	double N;
	std::cout << "Please write something \n";
//	std::int64_t n;  //Uncomment if you want to call get_int
	std::cin >> N;	

//	get_int(n); //Uncomment if you want to call get_int

	get_double(N);

	return 0;


}
