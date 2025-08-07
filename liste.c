#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<limits.h>
#include "liste.h"

// Initialisation avec un noeud bidon, un noeud qui va faciliter les manipulations d'ajout, on ne se sert pas de son contenu
void initialize(liste* myList)
{
    assert(myList != NULL);
    node* new = malloc(sizeof(*new));
    new->next = NULL;
    new->val = INT_MAX;
    myList->first = new;
    myList->size = 0;
}

// Ajoute une valeur à la liste en respectant l'ordre
void add(liste* myList, const int data)
{
    assert(myList != NULL);

    node* new = malloc(sizeof(*new));
    new->val = data;
    new->next = NULL;

    node* actual = myList->first;

    while(actual->next != NULL && actual->next->val < data)
        actual = actual->next;
    
    if(actual->next == NULL)
        actual->next = new;
    
    else
    {
        new->next = actual->next;
        actual->next = new;
    }

    (myList->size)++;
}

int rmve(liste* myList, const int data)
{
    assert(myList != NULL);

    int rData = EOF;
    node* actual = myList->first;
    while(actual->next != NULL && actual->next->val != data)
        actual = actual->next;
        
    if(actual->next != NULL)
    {
        node* temp = actual->next;
        rData = temp->val;
        actual->next = temp->next;
        (myList->size)--;
        free(temp);
    }

    return rData;
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
void freeAllNodes(liste* myList)
{
    clear(myList);
    node* temp = myList->first;
    myList->first = temp->next;
    myList->size = 0;
    free(temp);
}
void clear(liste* myList)
{
    assert(myList != NULL);
    
    int pValue = 0;
    while (myList->first->next != NULL)
    {
        node* temp = myList->first->next;
        myList->first->next = temp->next;
        (myList->size)--;
        free(temp);
    }
}

void clearBuffer()
{

    while(getchar() != '\n');
}


