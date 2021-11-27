#ifndef RLE_H
#define RLE_H

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

void RLE_pack(int arrCodes[], long long arrSize, string filePath, string fileType);
void RLE_unpack(int packedCode[], long long arrSize, string filePath);

#endif // RLE_H
