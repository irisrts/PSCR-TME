#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <vector>
#include "HashMap.hh"

int main () {
	using namespace std;
	using namespace std::chrono;
	//using namespace std::vector;

	ifstream input = ifstream("./WarAndPeace.txt");

	auto start = steady_clock::now();
	cout << "Parsing War and Peace" << endl;
	size_t nombre_lu = 0;

	vector<pair<string, int>> v = {};

	// prochain mot lu
	string word;
	// une regex qui reconnait les caractères anormaux (négation des lettres)
	regex re( R"([^a-zA-Z])");
	while (input >> word) {
		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");
		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);
		int trouve = 0;
		for (auto & element : v) {
			if (element.first == word) {
				trouve = 1;
				element.second+=1;
				break;
			}
		}


		/*for (auto i = v.begin(),_end = v.end(); i != _end; ++i){
			pair<string, int> element = *i;
			if(word == element.get(0)){
				trouve = 1;
				element.get(1)+=1;
				break;
			}
		}*/
		if (!trouve){
			pair<string, int> nouveau(word, 1);
			v.push_back(nouveau);
		}

		// word est maintenant "tout propre"
		if (nombre_lu % 100 == 0)
			// on affiche un mot "propre" sur 100
			cout << nombre_lu << ": "<< word << endl;
		//nombre_lu++;
	}
	input.close();

	cout << "Finished Parsing War and Peace" << endl;
	cout << v.size() << endl;
	auto end = steady_clock::now();
    cout << "Parsing took "
              << duration_cast<milliseconds>(end - start).count()
              << "ms.\n";

    cout << "Found a total of " << nombre_lu << " words." << endl;

    return 0;
}


