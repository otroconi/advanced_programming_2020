#include <iostream>
#include <algorithm> //to use sort(vector.begin(),vector.end())
#include <vector> //to store the words in a vector
using namespace std;

template <typename T>
void removeDuplicates(vector<T>& v){
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (auto& x: v)
		cout << x << "\n";
	cout << endl;

}

int main(){

	vector<string> words;
	string line;
	cout << "Enter some words, one per line and when you finish press enter"<< endl;
	while(getline(cin, line)){
		if(line.size() == 0)
			break;
		else		
			words.push_back(line);
	}

	for (auto& x: words)
		cout << x << "\n";
	cout << endl;

	removeDuplicates<string>(words);


	return 0;


}
