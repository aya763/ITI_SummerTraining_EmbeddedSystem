

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef enum ERROR_t {
    ERROR,
    NO_ERROR
}ERROR_t;


typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
}node;

void insertIntoList(int value);


ERROR_t deleteFromList(int value);


int getIndex(int value);


ERROR_t updateValue(int old, int new_value);


int printList();

#endif 
