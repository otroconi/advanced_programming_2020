#include <iostream>
#include <fstream>
#include <string>
#include <map>
//#include <unordered_map>
#include <chrono>
#include <cstdlib>
#include <iterator>
//#include <algorithm>
using namespace std;
using namespace std::chrono;

typedef map<string, int> StrIntMap;

void countWords(istream& in, StrIntMap& words) {

	string s;

	while (in >> s) {
			++words[s];
	}
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

	auto t0 = high_resolution_clock::now();

	StrIntMap w;
	countWords(file, w);


	for (StrIntMap::iterator p = w.begin(); p != w.end(); ++p) {
		cout << p -> first << " occurred " << p -> second << " times. \n";
	}

	auto tf = high_resolution_clock::now();

	auto elapsed = duration_cast<chrono::milliseconds>(tf-t0);

	cout << "\n elapsed_time= " << elapsed.count() << "[milliseconds]" << endl;

	return 0;

}
