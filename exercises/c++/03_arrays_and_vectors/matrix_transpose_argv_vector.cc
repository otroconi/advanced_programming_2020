#include <iostream>
#include <utility>
#include <array>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

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

	vector<double> matrix_t(cols*rows);
	for (size_t i{0}; i<cols; ++i){
		for (size_t j{0}; j<rows; ++j){
			matrix_t[i*rows + j] = matrix[j*cols + i];
		}
	}
	swap(matrix_t,matrix);

//	delete[] matrix_t;
			
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


/*	constexpr size_t rows{2}, cols{5};*/
	vector<double> matrix(rows*cols,0);

	for (size_t i{0}; i<rows; ++i)
		for (size_t j{0}; j<cols; ++j)
			matrix[i*cols + j] = 10*i + j; 
	print_ma(matrix,rows,cols);

//	int x=10, y=20;

//	std::swap(x,y);

	transpose_ma(matrix,rows,cols);

	print_ma(matrix,cols,rows);

//	delete[] matrix;

	return 0;



}
