#include "huffman.h"
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include "PriorityQueueAndTree.h"
#include <iostream>

using namespace std;

// Converting decimal to binary
string DecToBinCode(int num) {
    string res = "";
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

// Reading the initial file and calculating frequency of chars from file
vector<char> ReadInitialFile(string filePath) {
    ifstream f(filePath);

    vector<char> InCode;

    // Checking if file opened
    if (f) {
        char symbol;
        while (f.get(symbol)) {
            InCode.push_back(symbol);
        }
    }

    f.close();

    return InCode;
}

// Reading the packed file and converts it to binary code
string ReadPackedFile(string filePath, string &fileType, unordered_map<string, char> &haffmanTable) {
    ifstream f(filePath);

    string binaryCodeFile = "";

    if (f) {
        // Finding the length of file
        f.seekg(0, ios::end);
        long long size = f.tellg();
        f.seekg(0);

        long long tmpSize = 1;

        // Getting type of initial file
        int fileTypeLen = f.get() - '0';
        for (int i = 0; i < fileTypeLen; i++) {
            fileType += static_cast<int>(f.get());
            tmpSize++;
        }

        // Getting huffmanTable
        int sizeOfTable = f.get() + 1;
        tmpSize++;
        if (sizeOfTable < 0) sizeOfTable += 256;

        string codeOfSymbol = "";
        char el; // Value in map
        for (int i = 0; i < sizeOfTable; i++) {
            el = f.get();
            getline(f, codeOfSymbol);
            haffmanTable[codeOfSymbol] = el;
            // +1 - /n +1 f.get() type of record from file
            tmpSize += codeOfSymbol.size() + 2;
        }


        // Count of zeros of the last element
        int numOfZero = 0;
        string tmpCode = "";
        char symbol;
        // Getting packed code from file
        while (f.get(symbol)) {

            // Finding zeros of the last element
            if (tmpSize == (size - 2)) {
                numOfZero = static_cast<int>(symbol);
                f.get(symbol);

                int newNum = static_cast<int>(symbol);
                if (newNum < 0) newNum += 256;
                tmpCode = DecToBinCode(newNum);
                // Adding zeroes
                for (int i = 0; i < numOfZero; i++) {
                    tmpCode = "0" + tmpCode;
                }
                binaryCodeFile += tmpCode;
                break;
            }

            int num = static_cast<int>(symbol);
            if (num < 0) {
                num += 256;
            }
            tmpCode = DecToBinCode(num);

            // Adding 0
            while (tmpCode.size() != 8) {
                tmpCode = "0" + tmpCode;
            }
            binaryCodeFile += tmpCode;

            // Counting the position in the file
            tmpSize++;
        }
    }

    f.close();
    return binaryCodeFile;
}

// Writing packed code to file with initial file type
void WritePackedCodeToFile(string filePath, string packedCode, unordered_map<char, string> haffmanTable, string fileType) {
    string tmp8bitsStr = "";
    ofstream out(filePath);

    out << fileType.size();
    out << fileType;

    out << static_cast<char>(haffmanTable.size() - 1);
    // Writing of haffmanTable to the out file
    for (auto el: haffmanTable) {
        out << el.first;
        out << el.second;
        out << "\n";
    }

    // Generating 8 bits sequence and writing it to file
    // Changed int i to unsigned long i
    for (unsigned long i = 0; i < packedCode.size(); i++) {
        tmp8bitsStr += packedCode[i];
        if (tmp8bitsStr.size() == 8 || i == packedCode.size() - 1) {
            // Counting number of 0 in the tmp8bitsStr to the unpack file correctly
            if (i == packedCode.size() - 1) {
                unsigned long j = 0;
                while (tmp8bitsStr[j] != '1' and j != tmp8bitsStr.size()) {
                    j++;
                }
                out << static_cast<char>(j);
            }
            out << static_cast<char>(stoi(tmp8bitsStr, 0, 2));
            tmp8bitsStr = "";
        }
    }

    out.close();
}

// Generating string of converted char to code from haffman table
string GenOutPackedCode(vector<char> initialCode, unordered_map<char, string> haffmanTable) {
    string outStr = "";

    for (unsigned long i = 0; i < initialCode.size(); i++) {
        outStr += haffmanTable[initialCode[i]];
    }

    return outStr;

}

// Packing file using haffman algorithm
void Huffman_pack(string oldFilePath, string newFilePath, string fileType) {
    unordered_map<char, int> freqOfChar;
    vector<char> fileCode;

    fileCode = ReadInitialFile(oldFilePath);

    // Filling map of frequency of symbols
    for (unsigned long i = 0; i < fileCode.size(); i++) {
        freqOfChar[fileCode[i]]++;
    }

    // Initialize freqQueue
    Queue *freqQueue = nullptr;
    freqQueue = InitializeQueue(freqQueue);

    // Filling priority queue
    unordered_map<char, int>::iterator it;
    for (it = freqOfChar.begin(); it != freqOfChar.end(); it++) {
        Node *node = FillNode(it->first, it->second);
        InsertToQueue(freqQueue, node);
    }

    // Building the tree and node of the tree appending to the queue by its priority
    while (freqQueue->front != freqQueue->rear) {
        Node *tmpTreeNode = BuildTree(GetItem(freqQueue), GetItem(freqQueue));
        InsertToQueue(freqQueue, tmpTreeNode);
    }

    // Traversal the tree to generating codes of each symbol
    // Building Haffman table
    unordered_map<char, string> haffmanTable;
    TreeTraversal(freqQueue->front, haffmanTable, "", '\0');

    string genStrCode = GenOutPackedCode(fileCode, haffmanTable);

    // Writing packed code to file of typeFile type
    WritePackedCodeToFile(newFilePath, genStrCode, haffmanTable, fileType);

    // Cleaning the memory of queue and tree
    FreeTree(freqQueue->front);
    free(freqQueue);
}

// Unpacking file with haffman algorithm
void Huffman_unpack(string packedFilePath, string unpackedFilePath) {
    unordered_map<string, char> haffmanTable;

    string fileType = "";
    string packedCode = ReadPackedFile(packedFilePath, fileType, haffmanTable);

    unpackedFilePath += "." + fileType;
    ofstream unpackedFile(unpackedFilePath);

    string unpackedCode = "";

    string tmpCodeOfSymbol = "";

    // Iterating throw the packedCode to unpack it
    // Reading symbol until find match in the haffamn table
    for (unsigned long i = 0; i < packedCode.size(); i++) {
        tmpCodeOfSymbol += packedCode[i];
        if (haffmanTable.find(tmpCodeOfSymbol) != haffmanTable.end()) {
            unpackedCode += haffmanTable[tmpCodeOfSymbol];
            tmpCodeOfSymbol = "";
        }

    }

    unpackedFile << unpackedCode;
    unpackedFile.close();
}
