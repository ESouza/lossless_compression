//
// Created by Eduardo Souza on 2/14/22.
//

#include "Compress.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

void Compress::ProcessFile(ifstream& inFile) {
    string currentWord;
    vector<string> WordDictionary;
    vector<string> TemporaryWordsHolder;
    vector<int> CompressedMap;
    ofstream outFile;

    // This should be moved into its own function and be added to the compress.h file. I just added here for lack of time.
    outFile.open("/Users/eduardosouza/CLionProjects/lossless_compression/output.dat");

    if (inFile.is_open()) {
        //Created a temporary Words placeholder and push every word from file into this vector.
        while (inFile >> currentWord) {
            TemporaryWordsHolder.push_back(currentWord);
        }
    }

    // Loop through the temp words holder and pushed every word that is not repeating into the WordDictionary Vector.
    for (int i = 0; i <= TemporaryWordsHolder.size(); i++) {
        if (find(WordDictionary.begin(), WordDictionary.end(), TemporaryWordsHolder[i]) != WordDictionary.end()) {

        } else {
            WordDictionary.push_back(TemporaryWordsHolder[i]);
        }
    }

    for (int i = 0; i < TemporaryWordsHolder.size(); i++) {
        for (int a = 0; a < WordDictionary.size(); a++) {
            if (TemporaryWordsHolder[i] == WordDictionary[a]) {
                CompressedMap.push_back(a);
            }
        }
    }

    for (int i: CompressedMap){
        std::cout << CompressedMap[i] << ' ' << endl;

        if (outFile.is_open()) {
            outFile << CompressedMap[i] << ' ';
        }
    }

    outFile.close();

    // Quick for loop to simply display word dictionary and compressed file on console for debugging
//    for (string i: WordDictionary)
//    {
//        std::cout << i << ' ' << endl;
//    }

}
