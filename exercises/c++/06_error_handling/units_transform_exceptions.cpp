#include <iostream>

/*Working with exceptions in the units transformation of temperatures code of folder 01_intro*/

struct Negative_temperature {};

struct Bigger_than_expected {};

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

int transf_units(double & T, std::string units){
	double T_new;
	if (units == "C"){
		T_new = transf_KelvtoCels(T);
		return 0;
	} else if (units == "F"){
		T_new = transf_KelvtoFahrenh(T);
		return 0;
	} else
		std::cout << "Invalid units\n" << std::endl;
		
};

double temperature_input(double T, std::string units ) {
	//test the pre-conditions
	double T_transf;

	if ( T < 0)
		throw Negative_temperature{};
	if ( T > 100)
		throw Bigger_than_expected{};
	else
		return transf_units(T, units);
};

int main(){
	try {
		double T;
		std::string units;
		std::cout << "Please, enter the temperature with the units of the desired temperature in Celsius (C) or Fahrenheit (F)) that you would like to know\n";
		std::cin >> T;
		std::cin >> units;

		auto T_check = temperature_input(T, units);

		return 0;
	} catch (const Negative_temperature) {
		std::cerr << "The temperature in Kelvin should be a positive number\n";
		return 1;
	} catch (const Bigger_than_expected) {
		std::cerr << "The temperature should be less than 100 Kelvin\n";
		return 2;
	} catch ( ... ) {
		std::cerr << "Unknown exception.Aborting.\n";
		return 3;
	}
}

