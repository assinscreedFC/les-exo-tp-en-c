#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void setup_tab(int tab[], int tai)
{
    int i;
    for (i = 0; i < tai; i++)
    {
        tab[i] = rand() % 100;
    }
}

void affichage(int tab[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        if ((i) % 10 == 0)
        {
            printf("|\n");
        }
        printf("|  %d  | ", tab[i]);
        if (tab[i] / 10 == 0)
            printf(" ");
    }
    printf("|\n");
}

void identique(int tab1[], int tab2[], int taille)
{
    int i;
    for (i = 0; i < taille; i++)
    {
        tab2[i] = tab1[i];
    }
}

void identique2(int tab0[], int tab1[], int tab2[], int tab3[], int tab4[], int tab5[], int taille)
{
    int i;
    for (i = 0; i < taille; i++)
    {
        tab1[i] = tab0[i];
        tab2[i] = tab0[i];
        tab3[i] = tab0[i];
        tab4[i] = tab0[i];
        tab5[i] = tab0[i];
    }
}

void permutation(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

double calcule_temps_exe(void (*foncTRI)(int[]), int tab[], int taille)
{
    clock_t debut = clock();
    foncTRI(tab);
    clock_t fin = clock();
    double tempsEXE = (double)(fin - debut) / CLOCKS_PER_SEC;
    return tempsEXE;
}

/*void tri_selection(int tab[])
{
    int tmp;

    for (int i = taille; i > 0; i--)
    {
        for (int j = 1; j <= i; j++) // debut de 1 et celle juste avant cest 0 on est pas en algo
        {
            if (tab[j - 1] > tab[j])
            {
                tmp = tab[j - 1];
                tab[j - 1] = tab[j];
                tab[j] = tmp;
            }
        }
    }
    affichage(tab);
}
*/

// fini
void tri_bulles(int tab[], int taille) // boucle whiles
{
    int temp;
    int i = taille;
    bool trie = true;
    while (i >= 0)
    {
        for (int j = 1; j <= i; j++)
        {
            if (tab[j - 1] > tab[j])
            {
                temp = tab[j];
                tab[j] = tab[j - 1];
                tab[j - 1] = temp;
            }
        }
        i--;
    }
}

// fini
void tri_selction(int tab[], int taille)
{
    int i = taille - 1;
    int j, temp, position, tempo;
    while (i >= 0)
    {
        temp = tab[i];
        tempo = -1;
        for (j = 0; j < i - 1; j++)
        {

            if (tab[j] > temp)
            {
                temp = tab[j];
                position = j;
                tempo = 101;
            }
        }
        if (tempo == 101)
        {
            permutation(&tab[i], &tab[position]);
        }
        i--;
    }
}

// fini
void tri_insertion(int tab[], int taille)
{
    int x;
    int j;

    for (int i = 1; i < taille; i++)
    {
        x = tab[i];
        j = i - 1;
        while (j >= 0 && tab[j] > x)
        {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = x;
    }
}

// a refaire
void tri_rapide(int tab[], int debut, int fin)
{
    int i, j, pivot;

    if (debut < fin)
    {
        pivot = debut;
        i = debut;
        j = fin;
        while (i < j)
        {
            while (tab[i] <= tab[pivot] && i < fin)
                i++;
            while (tab[j] > tab[pivot])
                j--;
            if (i < j)
            {
                permutation(&tab[i], &tab[j]);
            }
        }
        permutation(&tab[pivot], &tab[j]);
        tri_rapide(tab, debut, j - 1);
        tri_rapide(tab, j + 1, fin);
    }

    /* for (i = debut + 1; i < fin; i++)
    {
        if (tab[i] <= pivot)
        {
            permutation(pivot, tab[i]);
            mur++;
        }
    }

    if (debut < mur - 1)
        trie_rapide(tab, debut, mur - 1);

    if (mur + 1 < fin)
    {
        trie_rapide(tab, mur, fin);
    }*/
}

// fini mais a refaire si possible
void tri_fusion(int i, int j, int tab[], int tmp[])
{

    if (j <= i)
    {
        return;
    }

    int m = (i + j) / 2;

    tri_fusion(i, m, tab, tmp);     // trier la moitié gauche récursivement
    tri_fusion(m + 1, j, tab, tmp); // trier la moitié droite récursivement
    int pg = i;                     // pg pointe au début du sous-tableau de gauche
    int pd = m + 1;                 // pd pointe au début du sous-tableau de droite
    int c;                          // compteur
    // on boucle de i à j pour remplir chaque élément du tableau final fusionné
    for (c = i; c <= j; c++)
    {
        if (pg == m + 1)
        { // le pointeur du sous-tableau de gauche a atteint la limite
            tmp[c] = tab[pd];
            pd++;
        }
        else if (pd == j + 1)
        { // le pointeur du sous-tableau de droite a atteint la limite
            tmp[c] = tab[pg];
            pg++;
        }
        else if (tab[pg] < tab[pd])
        { // le pointeur du sous-tableau de gauche pointe vers un élément plus petit
            tmp[c] = tab[pg];
            pg++;
        }
        else
        { // le pointeur du sous-tableau de droite pointe vers un élément plus petit
            tmp[c] = tab[pd];
            pd++;
        }
    }
    for (c = i; c <= j; c++)
    { // copier les éléments de tmp[] à tab[]
        tab[c] = tmp[c];
    }
}

// manU
int main()
{
    int taille = 1000;
    int tab_selec[taille];
    int tab_inser[taille];
    int tab_bulles[taille];
    int tab_fusion[taille];
    int vide[taille];
    int tab_rapide[taille];
    int temp[taille];
    int choix;
    clock_t fin;
    clock_t debut;

    FILE *fichDataTemps = fopen("donnees_triage.csv", "w");

    srand(time(NULL));
    setup_tab(vide, taille);
    do
    {
        do
        {
            printf("|===================Menu===================|");
            printf("\n|| Taper 1 pour le trie par Selection     ||");
            printf("\n|| Taper 2 pour le trie par insertion     ||");
            printf("\n|| Taper 3 pour le trie a bulles          ||");
            printf("\n|| Taper 4 pour le trie par fusion        ||");
            printf("\n|| Taper 5 pour le trie rapide            ||");
            printf("\n|| Taper 6 pour creation du fichier csv   ||");
            printf("\n|| Taper 0 pour quitter                   ||\n");
            printf("--------------------------------------------\n");
            printf("-Votre choix : ");
            scanf("%d", &choix);
        } while (choix < 0 && choix > 5);

        switch (choix)
        {
        case 1:
            printf("\n------------------------Trie par Selection-----------------------\n");
            identique(vide, tab_selec, taille);
            printf(" \n  \n  ");
            clock_t debut1 = clock();
            tri_selction(tab_selec, taille);
            clock_t fin1 = clock();
            affichage(tab_selec, taille);
            double sec1 = (double)(fin1 - debut1) / CLOCKS_PER_SEC;
            printf("le temps d'execution est de %f secondes\n", sec1);
            printf("\n---------------------------FIN du trie---------------------------\n");
            break;
        case 2:
            printf("\n------------------------Trie par Insertion------------------------\n");
            identique(vide, tab_inser, taille);
            printf(" \n  \n  ");
            clock_t debut2 = clock();
            tri_insertion(tab_inser, taille);
            clock_t fin2 = clock();
            double sec2 = (double)(fin2 - debut2) / CLOCKS_PER_SEC;
            affichage(tab_inser, taille);
            printf("le temps d'execution est de %f secondes\n", sec2);
            printf("\n---------------------------FIN du trie---------------------------\n");
            break;
        case 3:
            printf("\n------------------------Trie a Bulles------------------------\n");
            identique(vide, tab_bulles, taille);
            printf(" \n  \n ");
            clock_t debut3 = clock();
            tri_bulles(tab_bulles, taille);
            clock_t fin3 = clock();
            double sec3 = (double)(fin3 - debut3) / CLOCKS_PER_SEC;
            affichage(tab_bulles, taille);
            printf("le temps d'execution est de %f secondes\n", sec3);

            printf("\n---------------------------FIN du trie---------------------------\n");
            break;
        case 4:
            printf("\n------------------------Trie par Fusion------------------------\n");
            identique(vide, tab_fusion, taille);
            printf(" \n  \n  ");
            clock_t debut4 = clock();
            tri_fusion(0, taille, tab_fusion, temp);
            clock_t fin4 = clock();
            double sec4 = (double)(fin4 - debut4) / CLOCKS_PER_SEC;
            affichage(tab_fusion, taille);
            printf("le temps d'execution est de %f secondes\n", sec4);
            printf("\n---------------------------FIN du trie---------------------------\n");
            break;
        case 5:
            printf("\n----------------------------Trie Rapide---------------------------\n");
            identique(vide, tab_rapide, taille);
            printf(" \n  \n  \n \n");
            clock_t debut5 = clock();
            tri_rapide(tab_rapide, 0, taille);
            clock_t fin5 = clock();
            double sec5 = (double)(fin5 - debut5) / CLOCKS_PER_SEC;
            affichage(tab_rapide, taille);
            printf("le temps d'execution est de %f secondes\n", sec5);
            printf("\n---------------------------FIN du trie---------------------------\n");
            break;
        case 6:

            if (fichDataTemps == NULL)
            {
                printf("erreur au niveau du fichier csv");
                return 0;
            }
            else
            {
                fprintf(fichDataTemps, "tailleTab,triSelection,triInsertion,triBulles,triFusion,triRapide\n");

                int finTaille = taille * 10;
                int pas = 100;

                for (int i = 10; i < 100000; i += 100)
                {
                    int debutTaille = i;
                    int vide[debutTaille];
                    setup_tab(vide, debutTaille);
                    identique2(vide, tab_bulles, tab_fusion, tab_inser, tab_rapide, tab_selec, debutTaille);

                    debut = clock();
                    tri_selction(tab_selec, debutTaille);
                    fin = clock();
                    double tempsExeTabSelec = (double)(fin - debut) / CLOCKS_PER_SEC;

                    debut = clock();
                    tri_insertion(tab_inser, debutTaille);
                    fin = clock();
                    double tempsExeTabInser = (double)(fin - debut) / CLOCKS_PER_SEC;

                    debut = clock();
                    tri_bulles(tab_bulles, debutTaille);
                    fin = clock();
                    double tempsExeTabBulles = (double)(fin - debut) / CLOCKS_PER_SEC;

                    debut = clock();
                    tri_fusion(0, taille, tab_fusion, temp);
                    fin = clock();
                    double tempsExeTabFusion = (double)(fin - debut) / CLOCKS_PER_SEC;

                    debut = clock();
                    tri_rapide(tab_rapide, 0, debutTaille);
                    fin = clock();
                    double tempsExeTabRapide = (double)(fin - debut) / CLOCKS_PER_SEC;
                    printf("debuttaille =%d", debutTaille);
                    fprintf(fichDataTemps, "%d,%lf,%lf,%lf,%lf,%lf\n", debutTaille, tempsExeTabSelec, tempsExeTabInser, tempsExeTabBulles, tempsExeTabFusion, tempsExeTabRapide);
                    debutTaille += pas;
                }
                printf("fichier des donnees en CSV cree.");
            }
            fclose(fichDataTemps);

        case 0:
            printf("---------------------FIN---------------------");
            return 0;
            break;
        default:
            break;
        }
    } while (choix != 0);
}