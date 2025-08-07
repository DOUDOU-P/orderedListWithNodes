#ifndef LISTE_H_INCLUDED
    #define LISTE_H_INCLUDED
    typedef struct node node;
    struct node
    {
        int val;
        node* next;
    };

    typedef struct liste liste;
    struct liste
    {
       node* first;
       size_t size;
    };

    void initialize(liste*);
    void add(liste*, const int);
    int rmve(liste*, const int);
    void displayList(liste*);
    size_t getListSize(liste*);
    int pop(liste*);
    void clear(liste*);
    void clearBuffer();
    void freeAllNodes(liste*);
    
#endif