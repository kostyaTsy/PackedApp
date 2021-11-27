#include "LZ77.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Reading the file to the string
string ReadInitialFileToString(string filePath) {
    ifstream f(filePath);
    string out = "";

    if (f) {
        char symbol;
        while (f.get(symbol)) {
            out += symbol;
        }
    }

    f.close();
    return out;
}

// Reading the packed with initial file type in it file to the string
string ReadPackedFileToString(string filePath, string &fileType) {
    ifstream f(filePath);
    string out = "";

    if (f) {
        // getting type of initial file
        int fileTypeLen = f.get() - '0';
        for (int i = 0; i < fileTypeLen; i++) {
            fileType += static_cast<int>(f.get());
        }

        char symbol;
        while (f.get(symbol)) {
            out += symbol;
        }
    }

    f.close();
    return out;
}

// Converting decimal to binary
string DecToBin(int num) {
    string res = "";
    // TODO: Check
    if (num == 0) {
        return "0";
    }
    while (num > 0) {
        res += to_string(num % 2);
        num /= 2;
    }
    reverse(res.begin(), res.end());
    return res;

}

// Converting P|L into two decimal numbers
void ConvertBytesToTwoDecimals(int position, int lenght, int &posConv, int &lenConv) {
    string Len_str = DecToBin(lenght);
    while (Len_str.size() != 4) {
        Len_str = "0" + Len_str;
    }

    string pos_str = DecToBin(position);

    string res = pos_str + Len_str;

    while (res.size() != 16) {
        res = "0" + res;
    }

    pos_str = "";
    for (int i = 0; i < 8; i++) {
        pos_str += res[i];
    }
    posConv = stoi(pos_str, 0, 2);

    Len_str = "";
    for (int i = 8; i < 16; i++) {
        Len_str += res[i];
    }
    lenConv = stoi(Len_str, 0, 2);

}

// Reconverting bytes converted in packing to initial state to unpack file
void ReconvertBytes(int postion, int lenght, int &reconvPos, int &reconvLen) {
    string pos_str = DecToBin(postion);
    string len_str = DecToBin(lenght);

    while (len_str.size() != 8) {
        len_str = "0" + len_str;
    }
    while (pos_str.size() != 8) {
        pos_str = "0" + pos_str;
    }

    string res = pos_str + len_str;
    pos_str = "";
    for (int i = 0; i < 12; i++) {
        pos_str += res[i];
    }
    reconvPos = stoi(pos_str, 0, 2);

    len_str = "";
    for (int i = 12; i < 16; i++) {
        len_str += res[i];
    }
    reconvLen = stoi(len_str, 0, 2);

}

// TODO: fix packing end of file
// TODO: fix the algorithm (finding the longest word)
// packing file using LZ77 algorithm
void LZ77_pack(string olfFilePath, string newFilePath, string fileType) {
    // tmp constants
    // windowsSize - size of 12 bits  windowSize + maxCodeLen = 2 bytes
    // maxCodeLen - size of 4 bits (17-2)
    int windowSize = 4096;
    int maxCodeLen = 16;

    ofstream out(newFilePath);

    // writing to file type of initial file (first char is the size of fyle type then file type)
    out << fileType.size();
    out << fileType;

    string codeStr = ReadInitialFileToString(olfFilePath);

    // tmpCodeStr -  string to store prev part of string until index i to finding occurrences in a string
    // strToOccurr - string in which will be stored chars to finding occurrence in the tmpCodeStr
    string tmpCodeStr = "";
    string strToOccurr = "";

    // String that defines places of compression like (00100010) means that 1 and 5 compressed bits
    string byteStrToDefinePlacesOfCompression = "";

    // storing 8 bytes to write to the file
    vector<int> tmpCodeVector;

    // TODO: Debug string delete
    string tmpPackedStr;

    int cntOfStrAfterOverflowWindSize = 0;
    int pos = 0;
    int backToPos = 0;
    int IsAdd = 0;
    for (unsigned long i = 0; i < codeStr.size(); i++) {
        strToOccurr += codeStr[i];

        // Finding the index of occurrence of strToOccurr in the tmpCodeStr
        if (strToOccurr.size() >= 4 && (tmpCodeStr.size() >= strToOccurr.size())) {

            // TODO: check this part of code with i over winodowSize
            while (tmpCodeStr.find(strToOccurr) != string::npos && (int)strToOccurr.size() <= maxCodeLen &&
                    (int)tmpCodeStr.size() + (int)strToOccurr.size() < windowSize && i < codeStr.size()) {
                pos = (int)tmpCodeStr.find(strToOccurr);
                i++;
                strToOccurr += codeStr[i];
                IsAdd = 1;
            }
            if (IsAdd == 1) {
                i--;
                strToOccurr.erase(strToOccurr.size()-1, 1);
                IsAdd = 0;
            }
            pos = (int)tmpCodeStr.find(strToOccurr);

            // Checking if strToOccurr in tmpCodeStr
            if (pos != string::npos) {
                if (cntOfStrAfterOverflowWindSize > 0) {
                    pos += cntOfStrAfterOverflowWindSize;
                }
                backToPos = (int)(i - (strToOccurr.size() - 1) - pos);

                int convPos = 0;
                int convLen = 0;
                ConvertBytesToTwoDecimals(backToPos - 1, (int)strToOccurr.size() - 2, convPos, convLen);

                tmpCodeVector.push_back(convPos);
                tmpCodeVector.push_back(convLen);
                byteStrToDefinePlacesOfCompression += "1";

                tmpCodeStr += strToOccurr;
                // TODO: check this
//                if ((strToOccurr.size() != maxCodeLen) && (i != codeStr.size() - 1)) {
//                    strToOccurr = "";
//                }
                strToOccurr = "";
            }
        }

        // adding char to tmpCodeStr
        if (((int)strToOccurr.size() == maxCodeLen) || (i == codeStr.size() - 1) ) {
            tmpCodeStr += strToOccurr[0];

            int ConvertCharToInt = static_cast<int>(strToOccurr[0]);
            if (ConvertCharToInt < 0) {
                ConvertCharToInt += 256;
            }
            tmpCodeVector.push_back(ConvertCharToInt);

            byteStrToDefinePlacesOfCompression += "0";
            if ((int)strToOccurr.size() == maxCodeLen) {
                i = i - (strToOccurr.size() - 1);
            }
            else {
                i = i - strToOccurr.size() + 1;
            }

            strToOccurr = "";
        }
        // Cutting the string
        if ((int)tmpCodeStr.size() >= windowSize) {
            cntOfStrAfterOverflowWindSize++;
            tmpCodeStr.erase(0, 1);
        }

        if (byteStrToDefinePlacesOfCompression.size() == 8 || i == codeStr.size() - 1) {
            // Writing to file
            int ConvertedBytesPosOfCompression = stoi(byteStrToDefinePlacesOfCompression, 0, 2);
            tmpCodeVector.insert(tmpCodeVector.begin(), ConvertedBytesPosOfCompression);
            byteStrToDefinePlacesOfCompression = "";


            for (unsigned long j = 0; j < tmpCodeVector.size(); j++) {
                out << static_cast<char>(tmpCodeVector[j]);
                tmpPackedStr += static_cast<char>(tmpCodeVector[j]);
            }
            tmpCodeVector.clear();
            tmpCodeVector.shrink_to_fit();
        }

    }

    out.close();
}

// Unpacking file with LZ77 algorithm
void LZ77_unpack(string packedFilePath, string newFilePath) {
    string fileType;
    string packedCode = ReadPackedFileToString(packedFilePath, fileType);
    string unpackedCode = "";

    newFilePath += "." + fileType;
    ofstream out(newFilePath);

    int posOfCompression = 0;
    string binaryPosOfCompression = "";
    string tmpText = "";
    int position = 0, length = 0;
    // unpacking file
    for (unsigned long i = 0; i < packedCode.size(); i++) {
        posOfCompression = static_cast<int>(packedCode[i]);
        if (posOfCompression < 0) {
            posOfCompression += 256;
        }
        binaryPosOfCompression = DecToBin(posOfCompression);

        if (packedCode.size() - i >= 8) {
            // extending binary number to 8 bits
            while (binaryPosOfCompression.size() != 8) {
                binaryPosOfCompression = "0" + binaryPosOfCompression;
            }
        }
        else {
            // TODO: Check "packedCode.size() - i - 1" or "packedCode.size() - i - 2"
            if (packedCode.size() - i - 1 != 0) {
                while (binaryPosOfCompression.size() != packedCode.size() - i - 1) {
                    binaryPosOfCompression = "0" + binaryPosOfCompression;
                }
            }
        }

        for (int j = 0; j < (int)binaryPosOfCompression.size(); j++) {
            i++;
            if (binaryPosOfCompression[j] == '0') {
                unpackedCode += packedCode[i];
            }
            else {
                position = static_cast<int>(packedCode[i]);
                if (position < 0) {
                    position += 256;
                }
                length = static_cast<int>(packedCode[i+1]);
                if (length < 0) {
                    length += 256;
                }
                int reconvPos = 0, reconvLen = 0;

                ReconvertBytes(position, length, reconvPos, reconvLen);
                reconvPos++;
                reconvLen += 2;

                tmpText = unpackedCode.substr(unpackedCode.size() - reconvPos, reconvLen);
                unpackedCode += tmpText;
                i++;
            }
        }
    }

    out << unpackedCode;

    out.close();
}
