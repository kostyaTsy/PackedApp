#include "convertFiles.h"
#include <string>
#include <fstream>

// Converting file to code to pack it
int* ConvertFileToCode(string filePath, long long &size) {
    ifstream f(filePath);
    size = 0;
    int *arr = nullptr;

    // checking is file opened
    if (f) {
        // finding the length of the file
        f.seekg(0, ios::end);
        size = f.tellg();
        f.seekg(0);

        // locating array
        arr = new int[size];
        int cntOfArr = 0;

        // writing symbols from the file to array
        char symbol;
        int code = 0;
        while (f.get(symbol)) {
            code = static_cast<int>(symbol);
            if (code < 0) {
                code += 256;
            }
            arr[cntOfArr] = code;
            cntOfArr++;
        }
    }
    f.close();
    return arr;
}


// Convert packed file to code to unpack it
int* ConvertPackedFile(string filePath, long long &size, string &fileType) {
    ifstream f(filePath);
    size = 0;
    int *arr = nullptr;

    fileType = ".";
    // checking is file opened
    if (f) {
        // finding the length of the file
        f.seekg(0, ios::end);
        size = f.tellg();
        f.seekg(0);

        // finding file type
        int sizeFileType = f.get() - '0';
        for (int i = 0; i < sizeFileType; i++) {
            fileType += static_cast<int>(f.get());
        }

        size = size - (sizeFileType + 1);

        // locating array
        arr = new int[size];
        int cntOfArr = 0;

        // writing symbols from the file to array
        char symbol;
        int code = 0;
        while (f.get(symbol)) {
            code = static_cast<int>(symbol);
            if (code < 0) {
                code += 256;
            }
            arr[cntOfArr] = code;
            cntOfArr++;
        }
    }
    f.close();
    return arr;
}

// Finding initial file type in packed file (for RLE algorithm)
string FindingFileType(string path) {
    string fileType;

    ifstream f(path);

    if (f) {
        int fileTypeLen = f.get() - '0';
        for (int i = 0; i < fileTypeLen; i++) {
            fileType += static_cast<int>(f.get());
        }
        return fileType;
    }

    return "";
}
