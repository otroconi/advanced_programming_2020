#include <iostream>

void get_int(int64_t& n){

	while(!(std::cin >> n)){
		std::cout << "\t Bang!!! Bad choice, give me an integer\n" << std::endl;
	std::cin.clear();
	std::cin.ignore(10000,'\n');
	}

	

}

int main(){

	std::cout << "Please write something \n";
	std::int64_t n;

	get_int(n);

	return 0;


}
