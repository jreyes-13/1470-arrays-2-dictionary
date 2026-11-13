#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>  
#include <cstring>

using namespace std;
using namespace std::chrono;

const bool DEBUG = true;
const int MAX_WORDS = 1000;// 466551;


void initialize(string dictionary[]) {
	for (int i = 0; i < MAX_WORDS; i++) {
		dictionary[i] = "";
	}
}

void loadDictionary(string dictionary[], bool& successful) {
	ifstream file("dictionary.txt");

	if (!file) {
		successful = false;
		return;
	}	
	for (int i = 0; !file.eof() && i < MAX_WORDS; i++) {
		file >> dictionary[i];		
	}
	
	file.close();
	successful = true;
}

void print(const string dictionary[]) {
	for (int i = 0; i < MAX_WORDS; i++) {
		cout << i + 1 << " " << dictionary[i] << endl;
	}
}

int countWord(const string dictionary[]) {
	int count = 0;
	for (int i = 0; i < MAX_WORDS; i++) {
		if (dictionary[i] != " ") {
			count++;			
		}		
	}
	return count;
}


int main() {
	string dictionary[MAX_WORDS];
	bool loaded = false;

	auto start = high_resolution_clock::now();
	initialize(dictionary);
	auto end = high_resolution_clock::now();
	
	auto duration = duration_cast<microseconds>(end - start);
	if (DEBUG) cout << "DEBUGGING: Initialization took " << duration.count() << " microseconds.\n";


	start = high_resolution_clock::now();
	loadDictionary(dictionary, loaded);
	end = high_resolution_clock::now();
	
	duration = duration_cast<microseconds>(end - start);
	if (DEBUG) cout << "DEBUGGING: Loading took " << duration.count() << " microseconds.\n";

	if (!loaded) {
		cout << "Failed to load dictionary." << endl;
		return 1;
	}

	start = high_resolution_clock::now();
	cout << "Loaded " << countWord(dictionary) << " words from dictionary." << endl;
	end = chrono::high_resolution_clock::now();
	if (DEBUG) cout << "DEBUGGING: Counting task took " << duration.count() << " microseconds.\n";

	return 0;
}





