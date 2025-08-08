#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<limits.h>
#include "liste.h"

// Initialisation avec un noeud bidon, un noeud qui va faciliter les manipulations d'ajout, on ne se sert pas de son contenu
void initialize(liste* myList)
{
    node* newNode = malloc(sizeof(*newNode));
    assert(myList != NULL && newNode != NULL);
    newNode->next = NULL;
    newNode->val = INT_MAX;
    myList->first = newNode;
    myList->size = 0;
}

// Ajoute une valeur à la liste en respectant l'ordre
void add(liste* myList, const int data)
{
    
    node* newNode = malloc(sizeof(*newNode));

    assert(myList != NULL && newNode != NULL);
    newNode->val = data;
    newNode->next = NULL;

    node* actual = myList->first;

    while(actual->next != NULL && actual->next->val < data)
        actual = actual->next;

    newNode->next = actual->next;
    actual->next = newNode;

    (myList->size)++;
}

int rmve(liste* myList, const int data)
{
    assert(myList != NULL);

    node* actual = myList->first;
    while(actual->next != NULL && actual->next->val != data)
        actual = actual->next;
        
    if(actual->next != NULL)
    {
        node* temp = actual->next;
        actual->next = temp->next;
        (myList->size)--;
        free(temp);
        return 1;
    }

    return 0;
}

void displayList(liste* myList)
{
    assert(myList != NULL);
    node* actual = myList->first->next;

    while(actual != NULL)
    {
       printf("%d -> ", actual->val);
       actual = actual->next;
    }

    printf("NULL\n");
}

size_t getListSize(liste* myList)
{
    assert(myList != NULL);
    return myList->size;
}

void clear(liste* myList)
{
    assert(myList != NULL);
    
    while (myList->first->next != NULL)
    {
        node* temp = myList->first->next;
        myList->first->next = temp->next;
        free(temp);
    }

    myList->size = 0;
}

void freeAllNodes(liste* myList)
{
    clear(myList);
    free(myList->first);
    myList->first = NULL;
}

void clearBuffer()
{

    while(getchar() != '\n');
}


