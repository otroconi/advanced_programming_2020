#include <iostream>
#include <utility>
#include <array>
#include <iomanip>
using namespace std;

/* Matrix with static array std::array */

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

	T matrix_t{};
	for (size_t i{0}; i<cols; ++i){
		for (size_t j{0}; j<rows; ++j){
			matrix_t[i*rows + j] = matrix[j*cols + i];
		}
	}
	swap(matrix_t,matrix);
			
}

int main() {

	constexpr size_t rows{2}, cols{5};
	array<double, rows*cols> matrix; //static array std::array because we are defining here the rows and cols

	for (size_t i{0}; i<rows; ++i)
		for (size_t j{0}; j<cols; ++j)
			matrix[i*cols + j] = 10*i + j; 
	print_ma(matrix,rows,cols);

//	int x=10, y=20;

//	std::swap(x,y);

	transpose_ma(matrix,rows,cols);

	print_ma(matrix,cols,rows);

	return 0;

}
