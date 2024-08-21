#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"




int main() 
{
    insertIntoList(10);
    insertIntoList(20);
    insertIntoList(30);
	printf("List: ");
    printList();
	deleteFromList(20);
	printf("List after delete: ");
	printList();
	printf("Index of 30 :%d\n",getIndex(30));
	updateValue(10,50);
	printf("List after Update: ");
	printList();
    
    return 0;
}