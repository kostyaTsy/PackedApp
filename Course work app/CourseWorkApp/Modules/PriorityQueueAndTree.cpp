#include "PriorityQueueAndTree.h"
#include <unordered_map>
#include <string>

using namespace std;

// Filling node with symbol and frequency of symbol
Node* FillNode(char symbol, int freq) {
    Node *node = new Node();

    node -> symbol = symbol;
    node -> freq = freq;
    node -> prev = nullptr;
    node -> next = nullptr;

    node -> left = nullptr;
    node -> right = nullptr;

    return node;
}

// Getting item from the queue
Node* GetItem(Queue *queue) {
    Node *node = queue->front;

    if (queue->front != queue->rear) {
        queue -> front = queue -> front -> next;
        //delete queue->front->prev;
        queue->front->prev = nullptr;
    }
    else {
        queue->front = nullptr;
        queue->rear = nullptr;
    }

    return node;
}

// Initialization of Queue
Queue* InitializeQueue(Queue *queue) {
    queue = new Queue;
    queue->front = nullptr;
    queue->rear = nullptr;

    return queue;
}

// Inserting data to priority queue
Queue* InsertToQueue(Queue *queue, Node *node) {
//    Node *node = FillNode(symbol, freq);
      Node *tmpNode;

    // Checking if queue is empty
    if (queue->front == queue->rear && queue->front == nullptr){
        queue->front = node;
        queue->rear = node;
    }
    else if (queue->front == queue->rear) {
        queue->front->next = node;
        node->prev = queue->front;
        queue->rear = node;
    }
    // Inserting to the queue according to the priority
    else {
        tmpNode = queue->front;
        while (tmpNode->next != nullptr && node->freq > tmpNode->freq) {
            tmpNode = tmpNode->next;
        }
        // Insertion to the end
        if (tmpNode->next == nullptr && node->freq > tmpNode->freq) {
            node->prev = tmpNode;
            node->next = nullptr;
            tmpNode->next = node;

            queue->rear = node;
        }
        // Insertion to the beginning
        else if (tmpNode == queue->front) {
            node->next = tmpNode;
            tmpNode->prev = node;
            queue->front = node;
        }
        // Insertion to the queue to the position from the beginning to the end
        else {
            node->prev = tmpNode->prev;
            node->next = tmpNode;
            tmpNode->prev->next = node;
            node->next->prev = node;
        }

    }

    return queue;
}

// Reinitialization of node
Node* ReInitNode(Node *leftData) {
    leftData -> next = nullptr;
    leftData -> prev = nullptr;

    return leftData;
}


// Building the tree
Node* BuildTree(Node *leftData, Node *rightData) {
    Node *treeNode = new Node;
    treeNode -> symbol = '\0';
    // Calculating frequnecy
    treeNode -> freq = leftData -> freq + rightData -> freq;

    ReInitNode(treeNode);
    ReInitNode(leftData);
    ReInitNode(rightData);

    treeNode -> left = leftData;
    treeNode -> right = rightData;

    return treeNode;
}

// Recursion tree traversal to define code of each symbol in tree and write to hash map
// map char - string (string is binary code of char in the tree)
void TreeTraversal(Node *tree, unordered_map<char, string> &codeMap, string codeStr, char symb) {
    if (tree == nullptr) {
        if (codeMap.find(symb) == codeMap.end()) {
            // Write to codeMap
            codeStr.erase(codeStr.size()-1);
            codeMap[symb] = codeStr;
        }
    }
    else {
        symb = tree->symbol;
        TreeTraversal(tree->left, codeMap, codeStr+"0", symb);
        symb = tree->symbol;
        TreeTraversal(tree->right, codeMap, codeStr+"1", symb);
    }

}

// Cleaning memmory of tree
void FreeTree(Node *tree) {
    if (tree != nullptr) {
        FreeTree(tree->left);
        FreeTree(tree->right);
        free(tree);
    }
}
