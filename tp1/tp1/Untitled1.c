#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool tri_vrai(int tab[], int taille)
{
    int i = 0;
    bool tri = true;

    while (i < taille && tri == true)
    {
        if (tab[i] > tab[i + 1])
        {
            tri = false;
        }
        else
        {
            i++;
        }
    }
    return tri;
}

bool val_exi(int tab[], int taille, int val)
{
    int i = 0;
    bool exi = false;
    while (i < taille && exi == false)
    {
        if (tab[i] == val)
            exi = true;
        else
            i++;
    }

    return exi;
}

int occu_tab(int tab[], int taille, int val)
{
    int i = 0;
    int occu = 0;

    for (i = 0; i < taille; i++)
    {
        if (tab[i] == val)
            occu++;
    }
    return occu;
}

int main()
{
    int tab[50];
    int tai, i;
    int val;
    int occur;

    printf("entrez le taille du tableau : ");
    scanf("%d", &tai);

    for (i = 0; i < tai; i++)
    {
        printf("%d : ", i + 1);
        scanf("%d ", &tab[i]);
    }

    if (tri_vrai(tab, tai) == true)
        printf("le tableau est trie ");
    else
        printf("le tableau n'est pas trie ");

    printf("\n entrez la valeur a chercher  : ");
    scanf("%d", &val);

    if (val_exi(tab, tai, val) == true)
        printf("la valeur %d existe ", val);
    else
        printf("la valeur %d n'existe pas", val);

    printf("\n entrez une valeur : ");
    scanf("%d", &occur);
    printf("la valeur %d est repete %d fois ", val, occu_tab(tab, tai, val));

    return 0;
}

