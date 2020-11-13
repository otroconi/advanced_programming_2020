#include <iostream>
#include <utility>
#include <array>
#include <iomanip>
#include <sstream>
using namespace std;

/* Matrix using dynamic array (allocating memory in heap with new) */
template <typename T>
void print_ma(const T& matrix, size_t rows, size_t cols){ 
	for (size_t i{0}; i<rows; ++i){
		for (size_t j{0}; j<cols; ++j)
			cout << setw(2) << matrix[i*cols + j] << " ";
		cout << endl;
	}
}

template <typename T>
void transpose_ma(T& matrix, size_t rows, size_t cols){ //Not declare const T& matrix because you will get an error (you are swapping inside the function)

	auto matrix_t = new int[cols*rows]; //allocating memory in heap because the rows and cols are read from command line-->dynamic array
	for (size_t i{0}; i<cols; ++i){
		for (size_t j{0}; j<rows; ++j){
			matrix_t[i*rows + j] = matrix[j*cols + i];
		}
	}
	swap(matrix_t,matrix);

	delete[] matrix_t; // now matrix_t is a dangling pointer but memory is "free"
	matrix_t = nullptr; // now is not a dangling pointer and the memory is free :)
			
}

int main(int argc, char* argv[]) {

	if (argc < 3){
		cerr << "You should provide the file.txt. Like this: " << argv[0] << " #rows #cols " << endl;
		exit(-1);
	}

	size_t rows, cols;
	{
		istringstream is1{argv[1]};
		is1 >> rows;

		istringstream is2{argv[2]};
		is2 >> cols;
	}

	auto matrix = new int[rows*cols];

	for (size_t i{0}; i<rows; ++i)
		for (size_t j{0}; j<cols; ++j)
			matrix[i*cols + j] = 10*i + j; 
	print_ma(matrix,rows,cols);

//	int x=10, y=20;

//	std::swap(x,y);

	transpose_ma(matrix,rows,cols);

	print_ma(matrix,cols,rows);

	delete[] matrix; //now matrix is a dangling pointer but memory is "free"
	matrix = nullptr; // now is not a dangling pointer and the memory is free :)

	return 0;

}
