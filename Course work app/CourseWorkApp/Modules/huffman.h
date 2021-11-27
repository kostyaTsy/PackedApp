#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

void Huffman_pack(string oldFilePath, string newFilePath, string fileType);
void Huffman_unpack(string packedFilePath, string newFilePath);

#endif // HUFFMAN_H
