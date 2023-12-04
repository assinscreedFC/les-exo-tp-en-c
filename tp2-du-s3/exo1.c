#include <stdio.h>
#include <stdlib.h>

typedef struct arbres
{
    int value;
    struct arbres *left;
    struct arbres *right;
} arbres;

arbres *new_neud(int x)
{
    arbres *n = malloc(sizeof(*n));
    n->value = x;
    n->left = NULL;
    n->right = NULL;

    if (n == NULL)
    {
        printf("erreur n NULL");
        return;
    }
    else
    {
        printf("\n value is %d\n", n->value);
        return n;
    }
}

int taille(arbres *tailles)
{
    if (tailles == NULL)
    {
        return 0;
    }
    else
    {
        return taille(tailles->left) + taille(tailles->right) + 1;
    }
}

arbres *new_arbre(arbres *arbre, int x)
{
    printf("1");
    if (arbre == NULL)
    {
        printf("arbre");
        arbre = new_neud(x);
    }
    else if (taille(arbre->left) <= taille(arbre->right))
    {
        if (arbre->left == NULL)
        {
            printf("\nleft");
            arbre->left = new_neud(x);
        }
        else
        {
            new_arbre(arbre->left, x);
        }
    }
    else
    {
        if (arbre->right == NULL)
        {
            printf("\nright");
            arbre->right = new_neud(x);
        }
        else
        {
            new_arbre(arbre->right, x);
        }
    }

    return arbre;
}

arbres *fusion_arbre(arbres *gauche, arbres *droite, int x)
{
    arbres *n = malloc(sizeof(*n));
    n->value = x;
    n->left = gauche;
    n->right = droite;

    return n;
}

void sup(arbres *n)
{

    if (n == NULL)
    {

        return;
    }

    printf("suppression de %d\n", n->value);
    sup(n->left);
    sup(n->right);
    free(n);
}
int compare(arbres *arbre1, arbres *arbre2)
{
    if (arbre1->value != arbre2->value)
    {
        return 1;
    }
    compare(arbre1->left, arbre2->left);
    compare(arbre1->right, arbre2->right);
    return 0;
}

int main()
{
    arbres *arbre = NULL;

    /*  arbres *arbre2 = new_neud(88);
   arbres *arbre1 = new_neud(99);*/

    //   arbre = fusion_arbre(arbre1, arbre2, 111);
    int choix;
    int val = 1;
    int x;

    printf("Enter choice (1 to add nodes): ");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        while (val != 0)
        {
            printf("Enter value of x: \n");
            scanf("%d", &x);

            arbre = new_arbre(arbre, x);

            printf("Finish adding? (0 to finish, 1 to continue): ");
            scanf("%d", &val);
        }
        break;
    default:
        break;
    }
    arbres *arbre1 = NULL;

    arbre1 = fusion_arbre(new_neud(69), new_neud(88), 55);
    printf("abre value is %d", arbre1->value);

    //   arbre1 = new_neud(69);
    int z = taille(arbre);
    printf("taille de l'arbre %d\n", z);
    z = compare(arbre1, arbre);
    printf("vrai 1 faux 0: %d\n", z);
    sup(arbre);
    sup(arbre1);

    return 0;
}
