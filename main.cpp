#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <array>

using namespace std;

bool hasDuplicates(string line)
{
    stringstream ss(line);
    string word = "";
    string latestWord = "";
    bool foundDuplicated = false;
    int counter = 0;

    while(ss >> word){
        ++counter;

        if(word == latestWord){
            foundDuplicated = true;
        }
        latestWord = word;

        if(foundDuplicated)
        {
            cout << counter << " = " << word << endl;
        }

    }

    while(getline(ss, word, ' '))
    {
        if(word == latestWord){
            foundDuplicated = true;
        }
        latestWord = word;
    }
    return foundDuplicated;
}

int main() {
    string line;
    ifstream inFile;
    ofstream outFile;
    int counter = 0;

    inFile.open("/Users/eduardosouza/CLionProjects/lossless_compression/input2.dat");
    outFile.open("/Users/eduardosouza/CLionProjects/lossless_compression/output.dat");

    if(!inFile)
    {
        cout << "Fudeu o file sumiu!";
        return 1;
    }


    if(inFile.is_open())
    {
        while(getline(inFile, line)) {
            counter++;
            if(hasDuplicates(line)) {
                cout << counter << " : " << line << endl;
            }
        }
        string myArray[5];

        for(int i=0; i < 5; ++i) {
            inFile >> myArray[i];
            outFile << myArray[i] << "\n";
        }


        inFile.close();
    }


    return 0;
}
