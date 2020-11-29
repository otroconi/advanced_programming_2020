#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map> //elements stored in arbitrary order. Store element using hash table
#include <chrono>
#include <iterator>

using namespace std;
using namespace std::chrono;

typedef unordered_map<string, int> StrIntUOMap;

void countWords(istream& in, StrIntUOMap& words) {

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

	StrIntUOMap w;
	countWords(file, w);


	for (StrIntUOMap::iterator p = w.begin(); p != w.end(); ++p) {
		cout << p -> first << " occurred " << p -> second << " times. \n";
	}

	auto tf = high_resolution_clock::now();

	auto elapsed = duration_cast<chrono::milliseconds>(tf-t0);

	cout << "\n elapsed_time= " << elapsed.count() << "[milliseconds]" << endl;

	return 0;

}
