#ifndef CONVERTFILES_H
#define CONVERTFILES_H

#include <stdio.h>
#include <string>
using namespace std;

int* ConvertFileToCode(string filePath, long long &size);
int* ConvertPackedFile(string filePath, long long &size, string &fileType);
string FindingFileType(string path);


#endif // CONVERTFILES_H
