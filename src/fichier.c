//
//  fichier.c
//  Go Ball
//
//  Created by Gery THRASIBULE on 27/05/2014.
//  Copyright (c) 2014 CTGV. All rights reserved.
//

#include "header.h"



int chargerNiveau(int Niveau[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] , int level )
{
    //Chargement du niveau.
    FILE* fichier = NULL;
    char ligneFichier[NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1] = {0};
    int i = 0, j = 0;
    if( level == 1 )
    {
        fichier = fopen("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/niveaux.lvl", "r");
    }
    else if ( level == 2 )
    {
        fichier = fopen("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/niveau2.lvl", "r");
    }
    else if ( level == 3 )
    {
        fichier = fopen("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/niveau3.lvl", "r");
    }
    else if ( level == 4 )
    {
        fichier = fopen("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/niveau4.lvl", "r");
    }
    if (fichier == NULL)
    {
        return 0;
    }
    
    fgets(ligneFichier, NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1, fichier);
    
    for (i = 0 ; i < NB_BLOCS_HAUTEUR ; i++)
    {
        for (j = 0 ; j < NB_BLOCS_LARGEUR ; j++)
        {
            switch (ligneFichier[(i * NB_BLOCS_LARGEUR) + j])
            {
                case '0':
                    Niveau[j][i] = 0;
                    break;
                case '1':
                    Niveau[j][i] = 1;
                    break;
                case '2':
                    Niveau[j][i] = 2;
                    break;
                case '3':
                    Niveau[j][i] = 3;
                    break;
                case '4':
                    Niveau[j][i] = 4;
                    break;
                case '5':
                    Niveau[j][i] = 5;
                    break;
                case '6':
                    Niveau[j][i] = 6;
                    break;
                case '7':
                    Niveau[j][i] = 7;
                    break;
                case '8':
                    Niveau[j][i] = 8;
                    break;
                case '9':
                    Niveau[j][i] = 9;
                    break;
                default:
                    break;
            }
        }
    }
    
    fclose(fichier);
    return 1;
}

int sauvegarderNiveau(int Niveau[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] , int level )
{
    //Sauvegarde des niveaux édités.
    FILE* fichier = NULL;
    int i = 0, j = 0;
    
    if( level == 1 )
    {
        fichier = fopen("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/niveaux.lvl", "w");
    }
    else if ( level == 2 )
    {
        fichier = fopen("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/niveau2.lvl", "w");
    }
    else if ( level == 3 )
    {
        fichier = fopen("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/niveau3.lvl", "w");
    }
    else if ( level == 4 )
    {
        fichier = fopen("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/niveau4.lvl", "w");
    }
    if (fichier == NULL)
    {
        printf("ERREUR , %d \n" , level);
        return 0;
    }
    
    for (i = 0 ; i < NB_BLOCS_LARGEUR ; i++)
    {
        for (j = 0 ; j < NB_BLOCS_HAUTEUR ; j++)
        {
            fprintf(fichier, "%d", Niveau[j][i]);
        }
    }
    
    fclose(fichier);
    return 1;
}

