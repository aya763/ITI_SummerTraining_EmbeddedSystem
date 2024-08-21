

#include <stdio.h>
#include <stdlib.h>

#include"LinkedList.h"

node* head = NULL;

void insertIntoList(int value) 
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL) 
	{
        head = newNode;
    } 
	else 
	{
		node* temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newNode;
        newNode->prev = temp;
    }
}


ERROR_t deleteFromList(int value) 
{
    node* current = head;
    while (current != NULL) 
	{
        if (current->data == value) 
		{
            
            if (current->prev != NULL) 
			{
                current->prev->next = current->next;
            } 
			else 
			{
                
                head = current->next;
            }
            if (current->next != NULL) 
			{
                current->next->prev = current->prev;
            }
            free(current);
            return NO_ERROR;
        }
        current = current->next;
    }
    return ERROR;
}


int getIndex(int value) 
{
    node* current = head;
    int index = 0;
    while (current != NULL) 
	{
        if (current->data == value) 
		{
            return index;
        }
        current = current->next;
        index++;
    }
    return -1; 
}


ERROR_t updateValue(int old, int new_value) 
{
    node* current = head;
    while (current != NULL) 
	{
        if (current->data == old) 
		{
            current->data = new_value;
            return NO_ERROR;
        }
        current = current->next;
    }
    return ERROR; 
}


int printList() 
{
    node* current = head;
    while (current != NULL) 
	{
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}




