#include <iostream>
#include "ap_error.h"

/*Working with assert in the units transformation of temperatures code of folder 01_intro*/
/* In this case we introduce a macro defined in ap_error.h */

struct Temperature_invalid {
	std::string message;
	Temperature_invalid(std::string s): message{std::move(s)} {};
	const char* what() const { return message.c_str(); }
};

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

	AP_ERROR(T >= 0 && T <= 100, Temperature_invalid)
		<< "The temperature should be a positive and less or equal to 100 number.\n\nYou passed "
		<< T << ".\n";
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
	} catch (const Temperature_invalid& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 2;
	} catch ( ... ) {
		std::cerr << "Unknown exception.Aborting.\n";
		return 3;
	}
}

