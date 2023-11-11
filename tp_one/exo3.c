
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int taille = 1000;

void tri_parselection(int tab[], int taille)
{
    int min, temporaire, i, j;
    for (i = 0; i < taille - 1; i++)
    {
        min = i;
        for (j = i + 1; j < taille; j++)
        {
            if (tab[min] > tab[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temporaire = tab[i];
            tab[i] = tab[min];
            tab[min] = temporaire;
        }
    }
}

void tri_parinsertion(int tab[], int taille)
{
    int j, min;
    for (int i = 1; i < taille; i++)
    {
        min = tab[i];
        j = i;
        while ((j > 0) && (tab[j - 1] > min))
        {
            tab[j] = tab[j - 1];
            j--;
        }
        tab[j] = min;
    }
}

void fusion(int tab[], int dep, int mil, int fin)
{
    int n1 = mil - dep + 1;
    int n2 = fin - mil;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = tab[dep + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = tab[mil + 1 + j];
    }

    int i = 0, j = 0, k = dep;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            tab[k] = L[i];
            i++;
        }
        else
        {
            tab[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        tab[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        tab[k] = R[j];
        j++;
        k++;
    }
}

void tri_fusion(int tab[], int dep, int fin)
{
    if (dep < fin)
    {
        int mil = dep + (fin - dep) / 2;
        tri_fusion(tab, dep, mil);
        tri_fusion(tab, mil + 1, fin);
        fusion(tab, dep, mil, fin);
    }
}

int partitionner(int tab[], int debut, int fin)
{
    int pivot = tab[fin];
    int i = debut;

    for (int j = debut; j < fin; j++)
    {
        if (tab[j] < pivot)
        {
            int temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            i++;
        }
    }

    int temp = tab[i];
    tab[i] = tab[fin];
    tab[fin] = temp;

    return i;
}

void tri_Rapide(int tab[], int debut, int fin)
{
    if (debut < fin)
    {
        int pivotIndex = partitionner(tab, debut, fin);
        tri_Rapide(tab, debut, pivotIndex - 1);
        tri_Rapide(tab, pivotIndex + 1, fin);
    }
}

void tri_abul(int tab[], int taille)
{
    int temporaire;
    for (int i = 0; i < taille - 1; i++)
    {
        for (int j = 0; j < taille - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                temporaire = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temporaire;
            }
        }
    }
}

void affiche(int tab[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("tab[%d]=%d \n", i + 1, tab[i]);
    }
}

void affiche_all(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("tab1[%d]=%d\t   tab2[%d]=%d\t   tab3[%d]=%d\t   tab4[%d]=%d\t   tab5[%d]=%d\t     \n", i + 1, tab1[i], i + 1, tab2[i], i + 1, tab3[i], i + 1, tab4[i], i + 1, tab5[i]);
    }
}

int main()
{
    FILE *fichier_donnees = fopen("donnees2.csv", "w");
    FILE *gnuplotPipe = NULL;
    clock_t debut, fin;

    int tab1[taille], tab2[taille], tab3[taille], tab4[taille], tab5[taille];
    int i, r;
    setlocale(LC_ALL, "en_EU.utf8");
    srand(time(NULL));

    for (i = 0; i < taille; i++)
    {
        r = rand();
        tab1[i] = r;
        tab2[i] = r;
        tab3[i] = r;
        tab4[i] = r;
        tab5[i] = r;
    }

    int choix;
    do
    {
        printf("Menu de tri :\n");
        printf("1. Tri par selection\n");
        printf("2. Tri par insertion\n");
        printf("3. Tri fusion\n");
        printf("4. Tri rapide\n");
        printf("5. Tri a bulles\n");
        printf("6. Exécuter tous les tris\n");
        printf("0. Quitter\n");
        printf("Faites votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            // tabppeler la fonction de tri par sélection

            debut = clock();

            tri_parselection(tab1, taille);

            fin = clock();

            double temps_execution = (double)(fin - debut) / CLOCKS_PER_SEC;

            printf("Temps d'execution 1 : %f secondes\n", temps_execution);

            // affiche(tab1, taille);
            break;
        case 2:

            // appeler la fonction de tri par insertion
            debut = clock();

            tri_parinsertion(tab2, taille);

            fin = clock();

            double temps_execution2 = (double)(fin - debut) / CLOCKS_PER_SEC;

            printf("Temps d'execution 2: %f secondes\n", temps_execution2);

            //  affiche(tab2, taille);
            break;
        case 3:
            // appeler la fonction de tri fusion
            debut = clock();

            tri_fusion(tab3, 0, taille - 1);

            fin = clock();

            double temps_execution3 = (double)(fin - debut) / CLOCKS_PER_SEC;

            printf("Temps d'execution 3 : %f secondes\n", temps_execution3);

            //  affiche(tab3, taille);
            break;
        case 4:
            // appeler la fonction de tri rapide

            debut = clock();

            tri_Rapide(tab4, 0, taille - 1);

            fin = clock();

            double temps_execution4 = (double)(fin - debut) / CLOCKS_PER_SEC;

            printf("Temps d'execution 4 : %f secondes\n", temps_execution4);

            // affiche(tab4, taille);
            break;
        case 5:
            // tappeler la fonction de tri à bulles
            debut = clock();

            tri_abul(tab5, taille);

            fin = clock();

            double temps_execution5 = (double)(fin - debut) / CLOCKS_PER_SEC;

            printf("Temps d'execution 5 : %f secondes\n", temps_execution5);

            // affiche(tab5, taille);
            break;
        case 6:
            // tabppeler toutes les fonctions de tri
            debut = clock();

            tri_parselection(tab1, taille);
            tri_parinsertion(tab2, taille);
            tri_fusion(tab3, 0, taille - 1);
            tri_Rapide(tab4, 0, taille - 1);
            tri_abul(tab5, taille);

            fin = clock();
            double temps_execution6 = (double)(fin - debut) * 1000 / CLOCKS_PER_SEC;

            affiche_all(tab1, tab2, tab3, tab4, tab5, taille);
            printf("Temps d'execution  : %f secondes\n", temps_execution6);
            break;

        case 7:
            // Générer des données pour différentes tailles de tableau

            if (fichier_donnees == NULL)
            {
                printf("Erreur lors de l'ouverture du fichier de données.\n");
                break;
            }
            else
            {

                fprintf(fichier_donnees, "TailleTableau,SelectionSort,InsertionSort,MergeSort,QuickSort,BubbleSort\n");

                for (int n = 1000; n <= 80000; n += 1000)
                { // Modifier la plage de tailles au besoin
                    int tab1[n], tab2[n], tab3[n], tab4[n], tab5[n];

                    double temps_execution1, temps_execution2, temps_execution3, temps_execution4, temps_execution5;

                    for (int i = 0; i < n; i++)
                    {
                        r = rand();
                        tab1[i] = r;
                        tab2[i] = r;
                        tab3[i] = r;
                        tab4[i] = r;
                        tab5[i] = r;
                    }

                    debut = clock();
                    tri_parselection(tab1, n);
                    fin = clock();
                    temps_execution1 = (double)(fin - debut) / CLOCKS_PER_SEC;

                    debut = clock();
                    tri_parinsertion(tab2, n);
                    fin = clock();
                    temps_execution2 = (double)(fin - debut) / CLOCKS_PER_SEC;

                    debut = clock();
                    tri_fusion(tab3, 0, n - 1);
                    fin = clock();
                    temps_execution3 = (double)(fin - debut) / CLOCKS_PER_SEC;

                    debut = clock();
                    tri_Rapide(tab4, 0, n - 1);
                    fin = clock();
                    temps_execution4 = (double)(fin - debut) / CLOCKS_PER_SEC;

                    debut = clock();
                    tri_abul(tab5, n);
                    fin = clock();
                    temps_execution5 = (double)(fin - debut) / CLOCKS_PER_SEC;

                    fprintf(fichier_donnees, "%d,%lf,%lf,%lf,%lf,%lf\n", n, temps_execution1, temps_execution2, temps_execution3, temps_execution4, temps_execution5);
                }
                printf("Données générées et enregistrées dans 'donnees2.csv'\n");
            }
            fclose(fichier_donnees);
            choix = 8;
            break;
        case 8:
            gnuplotPipe = popen("gnuplot -persistent", "w");
            if (gnuplotPipe != NULL)
            {
                // Charger le fichier CSV et tracer les données
                fprintf(gnuplotPipe, "set terminal png\n");
                fprintf(gnuplotPipe, "set output 'all in one.png'\n");
                fprintf(gnuplotPipe, "set datafile separator ','\n");
                fprintf(gnuplotPipe, "set title 'Temps exécution des algorithmes de tri'\n");
                fprintf(gnuplotPipe, "set xlabel 'Taille du tableau'\n");
                fprintf(gnuplotPipe, "set ylabel 'Temps exécution (s)'\n");
                fprintf(gnuplotPipe, "set key top left\n");
                fprintf(gnuplotPipe, "set grid\n");
                fprintf(gnuplotPipe, "plot 'donnees2.csv' using 1:2 with linespoints title 'SelectionSort', \
                                          'donnees2.csv' using 1:3 with linespoints title 'InsertionSort', \
                                          'donnees2.csv' using 1:4 with linespoints title 'MergeSort', \
                                         'donnees2.csv' using 1:5 with linespoints title  'QuickeSort', \
                                          'donnees2.csv' using 1:6 with linespoints title  'BubbleSort' \n");

                fprintf(gnuplotPipe, "set terminal png\n");
                fprintf(gnuplotPipe, "set output 'fusion et rapide.png'\n");
                fprintf(gnuplotPipe, "set datafile separator ','\n");
                fprintf(gnuplotPipe, "set title 'Temps exécution des algorithmes de tri'\n");
                fprintf(gnuplotPipe, "set xlabel 'Taille du tableau'\n");
                fprintf(gnuplotPipe, "set ylabel 'Temps exécution (s)'\n");
                fprintf(gnuplotPipe, "set key top left\n");
                fprintf(gnuplotPipe, "set grid\n");
                fprintf(gnuplotPipe, "plot 'donnees2.csv' using 1:4 with linespoints title 'tri par fusion', \
                                           'donnees2.csv' using 1:5 with linespoints title  'tri rapide', \n");

                fprintf(gnuplotPipe, "set terminal png\n");
                fprintf(gnuplotPipe, "set output 'tri par sélection.png'\n");
                fprintf(gnuplotPipe, "set datafile separator ','\n");
                fprintf(gnuplotPipe, "set title 'Temps exécution des algorithmes de tri'\n");
                fprintf(gnuplotPipe, "set xlabel 'Taille du tableau'\n");
                fprintf(gnuplotPipe, "set ylabel 'Temps exécution (s)'\n");
                fprintf(gnuplotPipe, "set key top left\n");
                fprintf(gnuplotPipe, "set grid\n");
                fprintf(gnuplotPipe, "plot 'donnees2.csv' using 1:2 with linespoints title 'tri par sélection', \n");

                fprintf(gnuplotPipe, "set terminal png\n");
                fprintf(gnuplotPipe, "set output ' tri par insertion .png'\n");
                fprintf(gnuplotPipe, "set datafile separator ','\n");
                fprintf(gnuplotPipe, "set title 'Temps exécution des algorithmes de tri'\n");
                fprintf(gnuplotPipe, "set xlabel 'Taille du tableau'\n");
                fprintf(gnuplotPipe, "set ylabel 'Temps exécution (s)'\n");
                fprintf(gnuplotPipe, "set key top left\n");
                fprintf(gnuplotPipe, "set grid\n");
                fprintf(gnuplotPipe, "plot 'donnees2.csv' using 1:3 with linespoints title ' tri par insertion ', \n");

                fprintf(gnuplotPipe, "set terminal png\n");
                fprintf(gnuplotPipe, "set output 'tri a bull.png'\n");
                fprintf(gnuplotPipe, "set datafile separator ','\n");
                fprintf(gnuplotPipe, "set title 'Temps exécution des algorithmes de tri'\n");
                fprintf(gnuplotPipe, "set xlabel 'Taille du tableau'\n");
                fprintf(gnuplotPipe, "set ylabel 'Temps exécution (s)'\n");
                fprintf(gnuplotPipe, "set key top left\n");
                fprintf(gnuplotPipe, "set grid\n");
                fprintf(gnuplotPipe, "plot  'donnees2.csv' using 1:6 with linespoints title  'tri a bull' \n");

                fprintf(gnuplotPipe, "set terminal png\n");
                fprintf(gnuplotPipe, "set output 'tri rapide.png'\n");
                fprintf(gnuplotPipe, "set datafile separator ','\n");
                fprintf(gnuplotPipe, "set title 'Temps exécution des algorithmes de tri'\n");
                fprintf(gnuplotPipe, "set xlabel 'Taille du tableau'\n");
                fprintf(gnuplotPipe, "set ylabel 'Temps exécution (s)'\n");
                fprintf(gnuplotPipe, "set key top left\n");
                fprintf(gnuplotPipe, "set grid\n");
                fprintf(gnuplotPipe, "plot   'donnees2.csv' using 1:5 with linespoints title  'tri rapide', \n");

                fprintf(gnuplotPipe, "set terminal png\n");
                fprintf(gnuplotPipe, "set output ' tri par fusion.png'\n");
                fprintf(gnuplotPipe, "set datafile separator ','\n");
                fprintf(gnuplotPipe, "set title 'Temps exécution des algorithmes de tri'\n");
                fprintf(gnuplotPipe, "set xlabel 'Taille du tableau'\n");
                fprintf(gnuplotPipe, "set ylabel 'Temps exécution (s)'\n");
                fprintf(gnuplotPipe, "set key top left\n");
                fprintf(gnuplotPipe, "set grid\n");
                fprintf(gnuplotPipe, "plot  'donnees2.csv' using 1:4 with linespoints title 'tri par fusion', \n");

                // Fermer le processus GNUplot
                pclose(gnuplotPipe);
                printf("donnees2 ploter");
            }
            else
            {
                perror("Erreur lors de l'ouverture de GNUplot");
            }
            choix = 9;
            break;
        case 9:
            gnuplotPipe = popen("gnuplot -persistent", "w");
            if (gnuplotPipe != NULL)
            {
                // Charger le fichier CSV et tracer les données
                fprintf(gnuplotPipe, "set terminal png\n");
                fprintf(gnuplotPipe, "set output 'donnee10s.png'\n");
                fprintf(gnuplotPipe, "set datafile separator ','\n");
                fprintf(gnuplotPipe, "set title 'Temps exécution des algorithmes de tri'\n");
                fprintf(gnuplotPipe, "set xlabel 'Taille du tableau'\n");
                fprintf(gnuplotPipe, "set ylabel 'Temps exécution (s)'\n");
                fprintf(gnuplotPipe, "set key top left\n");
                fprintf(gnuplotPipe, "set grid\n");
                fprintf(gnuplotPipe, "plot 'donnees2.csv' using 1:4 with linespoints title 'MergeSort', \
                                           'donnees2.csv' using 1:5 with linespoints title  'QuickeSort', \n");

                // Fermer le processus GNUplot
                pclose(gnuplotPipe);
                printf("donnees2 ploter");
            }
            else
            {
                perror("Erreur lors de l'ouverture de GNUplot");
            }

        case 0:
            printf("Programme terminé.\n");
            break;
        default:
            printf("Choix invalide. Veuillez entrer un numéro valide.\n");
        }

    } while (choix != 0);
    return 0;
}