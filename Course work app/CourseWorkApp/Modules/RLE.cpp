#include "RLE.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Adding elements form tmpVector to fillVector
void FillVector(vector<int> tmpVector, vector<int>& fillVector) {
    for (unsigned long i = 0; i<tmpVector.size(); i++) {
        fillVector.push_back(tmpVector[i]);
    }
}

// Converting T|P bytes in one packed number
vector<int> ConvertBytesToNum(vector<int> tmpPackedCode) {

    // Res vector of converted bytes to number
    vector<int> res;

    int ConvNum = 0;
    for (unsigned long i = 0; i < tmpPackedCode.size(); i++) {
        // Converting T|P and filling vector with nums
        if (tmpPackedCode[i] == 1) {
            ConvNum = 128 + tmpPackedCode[i+1];
            res.push_back(ConvNum);
            res.push_back(tmpPackedCode[i+2]);
            i += 2;
        }
        else {
            ConvNum = tmpPackedCode[i+1];
            res.push_back(ConvNum);
            int cntOfNums = tmpPackedCode[i+1] + 1;
            i++;
            for (int j = 0; j < cntOfNums; j++) {
                res.push_back(tmpPackedCode[i+1]);
                i++;
            }
        }
    }

    return res;
}

// Writing packed code to the file
void WritePackedCodeToFile(string filePath, string fileType, vector<int> code) {
    ofstream out(filePath);
    // writing data of format to file (size|format  ->  5txt)
    out << fileType.size();
    out << fileType;

    for (unsigned long i = 0; i < code.size(); i++) {
        out << static_cast<char>(code[i]);
    }
    out.close();
}

// Writing unpacked code to the file
void WriteUnpackedCode(string filePath, vector<int> code) {
    ofstream out(filePath);
    for (unsigned long i = 0; i < code.size(); i++) {
        out << static_cast<char>(code[i]);
    }
    out.close();
}

// Packed file's code with RLE algorithm
// arrCodes - array of bites from file
void RLE_pack(int arrCodes[], long long arrSize, string filePath, string fileType) {
    // Converted array to packing (T|P), T - repeat or not, P - number of rep - 2 or number of elements - 1
    vector<int> tmpPackedCode;

    // Converted vector to full packed code of the file
    vector<int> finallyPackedCode;

    vector<int> tmpCodes;
    // Max lenght of sequence
    int MAXSIZE = 128;


    int IsRepeated = 0;
    for (int i = 0; i < arrSize-1;) {
        // finding repeated elements
        while (arrCodes[i] == arrCodes[i+1] && i < arrSize - 1 && tmpCodes.size() < (unsigned long)MAXSIZE) {
            tmpCodes.push_back(arrCodes[i]);
            IsRepeated = 1;
            i++;
        }
        // filling Vector with repeated elements
        if (IsRepeated == 1) {
            // pushing (repeat/not)|(number of repeat - 2/number of el-1)
            tmpPackedCode.push_back(IsRepeated);
            tmpPackedCode.push_back((int)tmpCodes.size()-1);

            tmpPackedCode.push_back(arrCodes[i]);
            i++;
            // Clear vector and backs the memory to vector
            tmpCodes.clear();
            tmpCodes.shrink_to_fit();
        }

        // finding not repeated elemnts
        while (arrCodes[i] != arrCodes[i+1] && i < arrSize - 1 && tmpCodes.size() < (unsigned long)MAXSIZE) {
            tmpCodes.push_back(arrCodes[i]);
            IsRepeated = 0;
            i++;
        }
        // filling vector with not repeated elements
        if (IsRepeated == 0 || i == arrSize-1) {
            if (i == arrSize - 1) {
                IsRepeated = 0;
                tmpCodes.push_back(arrCodes[i]);
            }
            tmpPackedCode.push_back(IsRepeated);
            tmpPackedCode.push_back((int)tmpCodes.size()-1);
            FillVector(tmpCodes, tmpPackedCode);

            tmpCodes.clear();
            tmpCodes.shrink_to_fit();
        }
    }

    finallyPackedCode = ConvertBytesToNum(tmpPackedCode);

    WritePackedCodeToFile(filePath, fileType, finallyPackedCode);
}

// Unpacking file with RLE algorithm
void RLE_unpack(int packedCode[], long long arrSize, string filePath) {
    vector<int> UnpackedCode;
    int NumberOfRepeatings = 0;

    // Converting packedCode to unpackCode
    for (int i = 0; i < arrSize; i++) {
        if (packedCode[i] >= 128) {
            NumberOfRepeatings = packedCode[i] - 128 + 2;
            for (int j = 0; j < NumberOfRepeatings; j++) {
                UnpackedCode.push_back(packedCode[i+1]);
            }
            i++;
        }
        else {
            NumberOfRepeatings = packedCode[i] + 1;
            for (int j = 0; j < NumberOfRepeatings; j++) {
                UnpackedCode.push_back(packedCode[i+1]);
                i++;
            }
        }
    }

    WriteUnpackedCode(filePath, UnpackedCode);
}
