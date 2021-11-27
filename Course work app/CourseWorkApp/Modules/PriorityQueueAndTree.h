#ifndef PRIORITYQUEUEANDTREE_H
#define PRIORITYQUEUEANDTREE_H

#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

// Declaring type of Node to queue and tree
struct Node {
    char symbol;
    int freq;
    Node *prev, *next;
    // pointers to building the tree
    Node *left, *right;
};

struct Tree {
    Node *head;
};

// Type of queue
struct Queue {
    Node *front, *rear;
};

Node* FillNode(char symbol, int freq);
Node* GetItem(Queue *queue);
Queue* InsertToQueue(Queue *queue, Node *node);
Queue* InitializeQueue(Queue *queue);
Node* BuildTree(Node *leftData, Node *rightData);
void TreeTraversal(Node *tree, unordered_map<char, string> &codeMap, string codeStr, char symb);


#endif // PRIORITYQUEUEANDTREE_H
