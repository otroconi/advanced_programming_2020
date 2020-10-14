#include <iostream>
#include <string>

int main(){

	std::string s1, s2;
	int64_t i{1};

	if(!(std::getline(std::cin,s1)))
		return 0;

	s2 = s1;

	while(std::getline(std::cin,s1)){
		if(s2 == s1)
			++i;
		else{
			std::cout << "\t" << i << ":" << s2 << std::endl;

			i = 1;
			s2 = s1;
		}
		

	}




}
