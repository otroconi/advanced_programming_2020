#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> // elements stored in sort order. Elements are stored internally as Balance Binary Search tree (BST) 
#include <unordered_map> //elements stored in arbitrary order. Store element using hash table
#include <chrono>
#include <iterator>
#include <algorithm>

using namespace std;
using namespace std::chrono;

template <typename T>
void removeDuplicates(vector<T>& v){
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (auto& x: v)
		cout << x << "\n";
	cout << endl;

}

void usevector(istream& in){

	vector<string> words;
	string s;

	while (in >> s)
		words.push_back(s);

	removeDuplicates<string>(words);

}

void usemap(istream& in) {

	typedef map<string, int> StrIntMap;

	string s;

	StrIntMap words;	

	while (in >> s)
		++words[s];

	for (StrIntMap::iterator p = words.begin(); p != words.end(); ++p) 
		cout << p -> first << " occurred " << p -> second << " times. \n";
}

void useUOmap(istream& in) {

	typedef unordered_map<string, int> StrIntUOMap;

	string s;

	StrIntUOMap words;
	
	while (in >> s)
		++words[s];

	for (StrIntUOMap::iterator p = words.begin(); p != words.end(); ++p) 
		cout << p -> first << " occurred " << p -> second << " times. \n";
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

	/* Uncomment the method: vector, map or unordered map which time you want to measure and comment the others*/

	auto t0 = high_resolution_clock::now();

	usevector(file);

//	usemap(file);

//	useUOmap(file);

	auto tf = high_resolution_clock::now();

	auto elapsed = duration_cast<std::chrono::milliseconds>(tf-t0);

	cout << "\n elapsed_time = " << elapsed.count() << "[milliseconds]" << endl;

	return 0;

}
