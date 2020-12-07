#include <iostream>

int transf_KelvtoCels(double& T_K){

	double T_C;
	T_C = T_K - 273.15;

	std::cout << T_K << " Kelvin is equivalent to " << T_C << " Celsius" << std::endl;

	return T_C;
}

int transf_KelvtoFahrenh(double& T_K){

	double T_F;
	T_F = 1.8*T_K - 459.67;

	std::cout << T_K << " Kelvin is equivalent to " << T_F << " Fahrenheit" << std::endl;

	return T_K;
}
int main(){

	double T;
	std::string units;
	std::cout << "Please, enter the temperature with the units of the desired temperature in Celsius (C) or Fahrenheit (F)) that you would like to know\n";
	std::cin >> T;
	std::cin >> units;

	if(units == "C")
		transf_KelvtoCels(T);
	else if(units == "F")
		transf_KelvtoFahrenh(T);
	else
		std::cout << "The units are not Celsius or Fahrenheit, or the value is not correct\n" << std::endl;



}
