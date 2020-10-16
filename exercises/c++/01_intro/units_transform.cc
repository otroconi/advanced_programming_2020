#include <iostream>

int transf_CelstoKelv(double& T_C){

	double T_K;
	T_K = T_C + 273.15;

	std::cout << T_C << " Celsius is equivalent to " << T_K << " Kelvin" << std::endl;

	return T_K;
}

int transf_FahretoKelv(double& T_F){

	double T_K;
	T_K = ((T_F-32)*0.56) + 273.15;

	std::cout << T_F << " Fahrenheit is equivalent to " << T_K << " Kelvin" << std::endl;

	return T_K;
}
int main(){

	double T;
	std::string units;
	std::cout << "Please, enter the temperature with the units in Celsius (C) or Fahrenheit (F))\n";
	std::cin >> T;
	std::cin >> units;

	if(units == "C")
		transf_CelstoKelv(T);
	else if(units == "F")
		transf_FahretoKelv(T);
	else
		std::cout << "The units are not Celsius or Fahrenheit, or the value is not correct\n" << std::endl;



}
