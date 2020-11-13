#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

template <typename T>
void print_vector(const vector<T>& v){

	for (const auto &x: v)
		cout << x << "\n";
	cout << endl;
}

template <typename T>
void mean_and_median(const vector<T>& v){

	double mean{0}, median{0};
	size_t length{v.size()};

	for (const auto &x: v){
		mean += x;
		if (length % 2 == 0)
			median = (v[length/2 + 1] + v[length/2]) / 2;
		else
			median = v[length/2];}
	
	mean = mean / length;

	if (length % 2 == 0){
		cout << "The length is an even number " << length << "\n";
		cout << "v[" << length/2 << "] = " << v[length/2] << " and v[" << length/2 +1 << "] = " << v[length/2 + 1] << endl;
	}else{
		cout << "The length is an odd number" << length << "\n";
		cout << "v[" << length/2 << "] = " << v[length/2] << endl;
	}
			
	cout << "Mean = " << mean << "\n";
	cout << "Median = " << median << endl;

}
	

int main(int argc, char* argv[]){

	if (argc < 2){
		cerr << "You should provide the file.txt. Like this: " << argv[0] << " file.txt" << endl;
		exit(-1);
	}

	string filename{argv[1]}; //setting argv[1] "=" filename
	ifstream file{filename, ifstream::in}; // open the file for input purposes (to read)
	if (!file.is_open()){
		cerr << "The file is not found or something happened" << endl;
	exit(-1);
	}

	double n;
	vector<double> v;

	while (file >> n)
		v.push_back(n);

	file.close();

	sort( v.begin(), v.end() );

	print_vector(v);

	mean_and_median(v);

	return 0;


}
