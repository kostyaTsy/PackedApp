#ifndef LZ77_H
#define LZ77_H

#include <stdio.h>
#include <string>
using namespace std;

void LZ77_pack(string olfFilePath, string newFilePath, string fileType);
void LZ77_unpack(string packedFilePath, string newFilePath);

#endif // LZ77_H
