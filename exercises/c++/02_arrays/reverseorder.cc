#include <iostream>

//Declaration and definition of the funtion Initial_Array
template <typename T>
T* Initial_Array(std::size_t length) {
	T* array{new T[length]}; // to allocate in the heap

	for (std::size_t i{0}; i < length; ++i)
		std::cin >> array[i];

	return array;

}

//Declaration and definition of the funtion Reverse_Array
template <typename T>
void Reverse_Array(const T* const array, std::size_t length) {

	while(length--)  // note the post-decrement
    		std::cout << "array[" << length << "] = " << array[length] << std::endl; // With this option you print all the array in reverse
/*
	for (std::size_t i{length - 1}; i != 0; --i)  // This is another option to reverse the array, but it prints until array[1]
		std::cout << "array[" << i << "] = " << array[i] << std::endl;

	std::cout << "array[0] = " << * array << std::endl; // To print the first element array[0] "manually"

	*/
}

int main() {

	std::cout << "Please insert array length: ";
	std::int64_t length;
	while(!(std::cin >> length) || length <= 0) {
		std::cout << "\t Bang!!! you have to introduce the length, i.e. a positive integer number. Please, try again!\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return -1;
//		std::cin >> length;

	}

	std::cout << "The length of the array is\n" << length << '\n'
		  << "Now introduce " << length << " integer numbers" << std::endl;
	auto* integer_values = Initial_Array<int>(length);

	std::cout << " The reverse array is:" << std::endl;
	Reverse_Array(integer_values, length);


	delete[] integer_values;
	integer_values = nullptr;

	std::cout << "The length of the array is\n" << length << '\n'
		  << "Now introduce " << length << " double numbers" << std::endl;
	auto* double_values = Initial_Array<double>(length);

	std::cout << " The reverse array is:" << std::endl;
	Reverse_Array(double_values, length);


	delete[] double_values;
	double_values = nullptr;

	return 0;

}
