//
// Created by Eduardo Souza on 2/14/22.
//

#ifndef LOSSLESS_COMPRESSION_COMPRESS_H
#define LOSSLESS_COMPRESSION_COMPRESS_H

#include <fstream>

using namespace std;

class Compress
{
public:
    void ProcessFile(ifstream&);
    void WriteProcessFile(ifstream&);
};

#endif //LOSSLESS_COMPRESSION_COMPRESS_H
