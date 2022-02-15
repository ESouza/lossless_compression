/* Requirements simple lossless data compression algorithm and implement it as a C++ class.
 * Will feed your class an input file that contains various words.
 * Your class will read these words, keep track of when it finds a new word that it did not encounter previously and assign a number to that word.
 * Your program will write an output file that contains the compressed data which will be the numbers that are associated with the words that were in the input file.
 * For example, if my input file had the following text: “test this file test test test”, then the output file might look like this: “0 1 2 0 0 0”.
 *
 * Eduardo Souza
 * Programming Assignment 1
 */

#include <iostream>
#include <algorithm>
#include "Compress.h"

using namespace std;

int main() {
    string line;

    try
    {
        ifstream inFile;

        inFile.open("/Users/eduardosouza/CLionProjects/lossless_compression/input2.dat");
        //outFile.open("/Users/eduardosouza/CLionProjects/lossless_compression/output.dat");

        if(!inFile)
        {
            cout << "Input file not found!";
            return 1;
        }

        Compress myInputToBeCompressed;
        myInputToBeCompressed.ProcessFile(inFile);

        inFile.close();
        //outFile.close();
    }
    catch (exception& ex)
    {
        cerr << "Error happened: " << ex.what() << endl;
        system("pause");
        return 1;
    }

    return 0;
}
