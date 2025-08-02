#include<stdio.h>
#include "liste.h"

int main(void)
{
    liste myList;
    initialize(&myList);

    int donnee;
    char choice;

    while(1)
    {
        printf("i = inserer donnee\n");
        printf("e = enlever donnee\n");
        printf("a = afficher liste\n");
        printf("f = Fin du programme\n");
        printf("Quelle operation, souhaitez vous effectuer sur la liste?\n");
        scanf("%c", &choice);

        switch (choice)
        {
        case 'i':
        case 'I':
            printf("Entrez la valeur a inserer: ");
            scanf("%d", &donnee);
            add(&myList, donnee);
            break;
        
        case 'e':
        case 'E':
            printf("Entrez la donnee a enlever: ");
            scanf("%d", &donnee);
            rmve(&myList, donnee);
            break;
        
        case 'a':
        case 'A':
            displayList(&myList);
            printf("\n\n");
            break;
        
        case 'f':
        case 'F':
            printf("Le programme termine\n");
            clear(&myList);
            return 0;

        default:
            printf("Commande erronee\n");
        }

        clearBuffer();
    }
}