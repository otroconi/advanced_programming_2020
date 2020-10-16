#include <iostream>

void get_int(int64_t& n){

	while(!(std::cin >> n)){
		std::cout << "\t Bang!!! Bad choice, give me an integer\n" << std::endl;
	std::cin.clear();
	std::cin.ignore(10000,'\n');
	}

}


void get_double(double& N){

	while(!(std::cin >> N)){
		std::cout << "\t Bang!!! bad choice, give me a double\n" << std::endl;
	std::cin.clear();
	std::cin.ignore(10000,'\n');
	}

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
