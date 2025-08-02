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

    int rData = 0;
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

int pop(liste* myList)
{
    int pValue = 0;
    if(myList != NULL && myList->first != NULL)
    {
        node* temp = myList->first;
        pValue = temp->val;
        myList->first = temp->next;
        (myList->size)--;
        free(temp);
    }

    return pValue;
}

void clear(liste* myList)
{
    assert(myList != NULL);
    
    if(myList->first != NULL)
    {
        pop(myList);
        clear(myList);
    }
}

void clearBuffer()
{

    while(getchar() != '\n');
}


