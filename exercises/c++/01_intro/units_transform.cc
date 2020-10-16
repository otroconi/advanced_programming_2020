#include <iostream>

int transf_Kelvin(double& T_C){

	double T_K;
	T_K = T_C + 273.15;

	std::cout << T_C << " Celsius is equivalent to " << T_K << " Kelvin" << std::endl;

	return T_K;
}

int main(){

	double T_C;
	std::cout << "Please, enter the temperature in Celsius\n";
	std::cin >> T_C;

	transf_Kelvin(T_C);



}
