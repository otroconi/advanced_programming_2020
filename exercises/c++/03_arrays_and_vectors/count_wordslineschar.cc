#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <chrono>
#include <cstdlib>
#include <cctype>

using namespace std;

typedef map<string, int> StrIntMap;

void countWords(istream& in, StrIntMap& words) {

	string s;

	while (in >> s) {
			++words[s];
	}
}

void countStuff(istream& in, int& chars, int& words, int& lines){

	char cur = '\0';
	char last = '\0';
	chars = lines = words = 0;

	string s;


	while(in.get(cur)) {
		if(cur == '\n' || (cur == '\f' && last == '\r'))
			++lines;
		else 
			++chars;
		if(!isalnum(cur) && isalnum(last))
			++words;
		
		last = cur;
	}

	if(chars > 0){
		if(isalnum(last))
			++words;
		
		++lines;
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

	int c, w, l;

	countStuff(file, c, w, l);

	cout << "chars: " << c << '\n';
	cout << "words: " << w << '\n';
	cout << "lines: " << l << endl;


/*	StrIntMap w;
	countWords(file, w);

	for (StrIntMap::iterator p = w.begin(); p != w.end(); ++p) {
		cout << p -> first << " occurred " << p -> second << " times. \n";
	}*/

	return 0;

}
