//
//  jouer.c
//  Go Ball
//
//  Created by Gery THRASIBULE on 27/05/2014.
//  Copyright (c) 2014 CTGV. All rights reserved.
//

#include "header.h"

void jouer ( SDL_Surface *ecran , int *niveau , int *scoreActuel )
{
    int jouer = 1;
    int vitesseDeBalle = 80;
    int vie = 3;
    while ( jouer == 1 )
    {
        SDL_Surface *balle = NULL, *brique = NULL , *barreD = NULL , *barreM = NULL , *barreG = NULL , *victoire = NULL , *barreM2 = NULL , *barreM3 = NULL , *brique3coups = NULL , *brique2coups = NULL , *brique1coup = NULL , *briqueno = NULL;
        balle = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/balle_normale.png");
        barreD = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/pad_droite.png");
        brique3coups = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/brique_3fois_3(3).png");
        brique2coups = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/brique_3fois_2(2).png");
        brique1coup = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/brique_3fois_1(2).png");
        briqueno = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/brique_incassable.png");
        barreM = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/pad_centre.png");
        barreM2 = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/pad_centre.png");
        barreM3 = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/pad_centre.png");
        barreG = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/pad_gauche.png");
        brique = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/brique_normale.png");
        victoire = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/nice.png");
        
        //Lancement d'une fonction jeux dans une boucle de jeu.
        jeux( ecran , &jouer , niveau , balle , brique , barreD , barreM , barreG , victoire , barreM2 , barreM3 , brique3coups , brique2coups , brique1coup , briqueno , &vitesseDeBalle , &vie , scoreActuel);
        
        SDL_FreeSurface(barreD);
        SDL_FreeSurface(barreM);
        SDL_FreeSurface(briqueno);
        SDL_FreeSurface(brique1coup);
        SDL_FreeSurface(brique2coups);
        SDL_FreeSurface(brique3coups);
        SDL_FreeSurface(barreM2);
        SDL_FreeSurface(barreM3);
        SDL_FreeSurface(barreG);
        SDL_FreeSurface(balle);
        SDL_FreeSurface(brique);
    }
}
void jeux(  SDL_Surface *ecran , int *jouer , int *niveau , SDL_Surface *balle , SDL_Surface *brique , SDL_Surface *barreD , SDL_Surface *barreM , SDL_Surface *barreG , SDL_Surface *victoire , SDL_Surface *barreM2 , SDL_Surface *barreM3 , SDL_Surface *brique3coups , SDL_Surface *brique2coups , SDL_Surface *brique1coup , SDL_Surface *briqueno , int *vitesseDeBalle , int *vie , int *scoreActuel)
{
    
    SDL_Surface *explo = NULL , *ballex3 = NULL , *colle = NULL , *agrandir = NULL , *retrecir = NULL , *fond = NULL , *barreM4 = NULL , *barreM5 = NULL , *balle2 = NULL , *vitessePlus = NULL , *vitesseMoins = NULL , *imgVie1 = NULL , *imgVie2 = NULL , *imgVie3 = NULL , *imgNiveau = NULL , *gameOver , *imgPause = NULL , *texte = NULL;
    SDL_Rect position, positionBalle , positionBarreM , positionBarreM2 , positionBarreM3 , positionBarreG , positionBarreD , positionVictoire , positionFond , positionBarreM4 , positionBarreM5 , positionBalle2 , positionVie , positionNiveau , positionTexte;
    SDL_Rect positionBonus;
    SDL_Event event;
    TTF_Init();
    TTF_Font *police = NULL;
    SDL_Color blanc = {223,223,223};
    char point[20];
    explo = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Bonus_BalleExplo.png");
    colle = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Bonus_Stick.png");
    retrecir = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Malus_TaillePad.png");
    fond = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/game_background.png");
    agrandir = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Bonus_TaillePad.png");
    ballex3 = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Bonus_Balle_2.png");
    barreM4 = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/pad_centre.png");
    barreM5 = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/pad_centre.png");
    balle2 = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/balle_bonus.png");
    vitessePlus = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Malus_AugmenterVitesseBalle.png");
    vitesseMoins = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Bonus_ReduireVitesseBalle.png");
    imgVie1 = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/vie_1.png");
    imgVie2 = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/vie_2.png");
    imgVie3 = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/vie_3.png");
    imgNiveau = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Niveau 1.png");
    gameOver = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/gameover.png");
    imgPause = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/pause.png");
    int continuer = 1, BriqueRestantes = 0, i = 0, j = 0 , start = 0 , charger = 0 , bougerX = 0 , bougerY = -1 , a = 0 , xavant = 0 , yavant = 1 , tour = 0  , sauvniveau = 0 , bougerX2 = 0 , bougerY2 = -1 , xavant2 = 0 , yavant2 = 0;
    int temps = 0 , tempsAvant = 0 , temps1 = 0 , tempsAvant1 = 0 , pause = 0 , bonus = 0 , positionDonne = 0 , caseBonusx = 0 , caseBonusy = 0 , bonusActif = 0 , temps2 = 0 , tempsAvant2 = 0;
    int bougerBalle = 0 , x = 0 , b = 0 , tour2 = 0 , jeulance = 0 , scorePrecedent = 0 ,scoreActuel2 = 0;
    int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] = {{0}} , posXavant[NB_BLOCS_LARGEUR] = {0} , posYavant[NB_BLOCS_HAUTEUR] = {0} , posXavant2[NB_BLOCS_LARGEUR] = {0} , posYavant2[NB_BLOCS_HAUTEUR] = {0};
    
    police = TTF_OpenFont("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/STENCIL.TTF", 30);
    sprintf( point , "%d", *scoreActuel);
    texte = TTF_RenderText_Solid(police, point, blanc);
    
    //Chargement du niveau.
    if ( charger == 0 )
    {
        if ( chargerNiveau(carte , *niveau ) == 0)
        {
            fprintf (stderr, "Erreur lors du chargement du niveau \n");
        }
        
        charger = 1;
        
        for (i = 0 ; i < NB_BLOCS_HAUTEUR ; i++)
        {
            for (j = 0 ; j < NB_BLOCS_LARGEUR ; j++)
            {
                if (carte[i][j] == BARRED )
                {
                    positionBarreD.x = i;
                    positionBarreD.y = j;
                }
                if (carte[i][j] == BARREM )
                {
                    positionBarreM.x = i;
                    positionBarreM.y = j;
                }
                if (carte[i][j] == BARREM2 )
                {
                    positionBarreM2.x = i;
                    positionBarreM2.y = j;
                }
                if (carte[i][j] == BARREM3 )
                {
                    positionBarreM3.x = i;
                    positionBarreM3.y = j;
                }
                if (carte[i][j] == BARREG )
                {
                    positionBarreG.x = i;
                    positionBarreG.y = j;
                }
                if ( carte[i][j] == BALLE )
                {
                    positionBalle.x = i;
                    positionBalle.y = j;
                }
            }
        }
        positionFond.x = 0;
        positionFond.y = 0;
    }
    while ( continuer == 1)
    {
        //Lancement d'une boucle dans la boucle
        SDL_FillRect( ecran , NULL , SDL_MapRGB ( ecran->format , 0 , 0 , 0 ));
        SDL_BlitSurface(fond , NULL , ecran , &positionFond);
        BriqueRestantes = 0;
        positionVictoire.x = 0;
        positionVictoire.y = 0;
        
        if (  jeulance == 0 && *niveau == 1) {
            positionNiveau.x = 0;
            positionNiveau.y = 0;
            SDL_BlitSurface(imgNiveau , NULL , ecran , &positionNiveau);
            SDL_Flip(ecran);
            SDL_Delay(3000);
            jeulance++;
        }
        
        if ( *vie == 3) {
            positionVie.x = 600;
            positionVie.y = 15;
            SDL_BlitSurface( imgVie3 , NULL , ecran , &positionVie);
        }
        else if ( *vie == 2) {
            SDL_BlitSurface( imgVie2 , NULL , ecran , &positionVie);
        }
        else if ( *vie == 1) {
            SDL_BlitSurface( imgVie1 , NULL , ecran , &positionVie);
        }
        else if ( *vie == 0 ) {
            positionNiveau.x = 0;
            positionNiveau.y = 0;
            SDL_BlitSurface( gameOver , NULL , ecran , &positionNiveau);
            SDL_Flip(ecran);
            SDL_Delay(4000);
            *jouer = 0;
            continuer = 0;
            *niveau = 1;
            
        }
        
        if (*scoreActuel != scorePrecedent) {
            
            sprintf( point , "%d", *scoreActuel);
            SDL_FreeSurface(texte);
            texte = TTF_RenderText_Solid(police, point, blanc );
            
        }
        
        scorePrecedent = *scoreActuel;
        positionTexte.x = 20;
        positionTexte.y = 20;
        SDL_BlitSurface( texte , NULL , ecran , &positionTexte);
        
        
        //On vérifie qu'il reste des briques.
        for ( i = 0 ; i < NB_BLOCS_HAUTEUR ; i++ )
        {
            for ( j = 0 ; j < NB_BLOCS_LARGEUR ; j++ )
            {
                position.x = i * TAILLE_BLOC;
                position.y = j * TAILLE_BLOC;
                
                switch( carte[i][j])
                {
                    case VIDE:
                        break;
                    case BRIQUE:
                        SDL_BlitSurface( brique , NULL , ecran , &position);
                        BriqueRestantes = 1;
                        break;
                    case BRIQUE3COUPS:
                        SDL_BlitSurface( brique3coups , NULL , ecran , &position);
                        BriqueRestantes = 1;
                        break;
                    case BRIQUE2COUPS:
                        SDL_BlitSurface( brique2coups , NULL , ecran , &position);
                        BriqueRestantes = 1;
                        break;
                    case BRIQUE1COUP:
                        SDL_BlitSurface( brique1coup , NULL , ecran , &position);
                        BriqueRestantes = 1;
                        break;
                    case BRIQUENO:
                        SDL_BlitSurface( briqueno , NULL , ecran , &position);
                        break;
                    default:
                        break;
                }
            }
        }
        
        //Bonus.
        if ( bonus == RETRECIR && bonusActif == ACTIF )
        {
            position.x = positionBarreM.x * TAILLE_BLOC;
            position.y = positionBarreM.y * TAILLE_BLOC;
            SDL_BlitSurface( barreG , NULL, ecran, &position);
            
            position.x = positionBarreM2.x * TAILLE_BLOC;
            position.y = positionBarreM2.y * TAILLE_BLOC;
            SDL_BlitSurface( barreM , NULL, ecran, &position);
            
            position.x = positionBarreM3.x * TAILLE_BLOC;
            position.y = positionBarreM3.y * TAILLE_BLOC;
            SDL_BlitSurface( barreD , NULL, ecran, &position);
        }
        else if ( bonus == GRANDIR && bonusActif == ACTIF )
        {
            positionBarreM5.x = positionBarreD.x + DIRECDROITE;
            positionBarreM4.x = positionBarreG.x + DIRECGAUCHE;
            positionBarreM5.y = positionBarreD.y;
            positionBarreM4.y = positionBarreG.y;
            position.x = positionBarreM5.x * TAILLE_BLOC;
            position.y = positionBarreM5.y * TAILLE_BLOC;
            SDL_BlitSurface( barreD , NULL, ecran, &position);
            
            position.x = positionBarreM.x * TAILLE_BLOC;
            position.y = positionBarreM.y * TAILLE_BLOC;
            SDL_BlitSurface( barreM , NULL, ecran, &position);
            
            position.x = positionBarreM2.x * TAILLE_BLOC;
            position.y = positionBarreM2.y * TAILLE_BLOC;
            SDL_BlitSurface( barreM2 , NULL, ecran, &position);
            
            position.x = positionBarreM3.x * TAILLE_BLOC;
            position.y = positionBarreM3.y * TAILLE_BLOC;
            SDL_BlitSurface( barreM3 , NULL, ecran, &position);
            
            position.x = positionBarreM4.x * TAILLE_BLOC;
            position.y = positionBarreM4.y * TAILLE_BLOC;
            SDL_BlitSurface( barreG , NULL, ecran, &position);
            
            position.x = positionBarreG.x * TAILLE_BLOC;
            position.y = positionBarreG.y * TAILLE_BLOC;
            SDL_BlitSurface( barreM4 , NULL, ecran, &position);
            
            position.x = positionBarreD.x * TAILLE_BLOC;
            position.y = positionBarreD.y * TAILLE_BLOC;
            SDL_BlitSurface( barreM5 , NULL, ecran, &position);
        }
        else
        {
            position.x = positionBarreD.x * TAILLE_BLOC;
            position.y = positionBarreD.y * TAILLE_BLOC;
            SDL_BlitSurface( barreD , NULL, ecran, &position);
            
            position.x = positionBarreM.x * TAILLE_BLOC;
            position.y = positionBarreM.y * TAILLE_BLOC;
            SDL_BlitSurface( barreM , NULL, ecran, &position);
            
            position.x = positionBarreM2.x * TAILLE_BLOC;
            position.y = positionBarreM2.y * TAILLE_BLOC;
            SDL_BlitSurface( barreM2 , NULL, ecran, &position);
            
            position.x = positionBarreM3.x * TAILLE_BLOC;
            position.y = positionBarreM3.y * TAILLE_BLOC;
            SDL_BlitSurface( barreM3 , NULL, ecran, &position);
            
            position.x = positionBarreG.x * TAILLE_BLOC;
            position.y = positionBarreG.y * TAILLE_BLOC;
            SDL_BlitSurface( barreG , NULL, ecran, &position);
        }
        
        position.x = positionBalle.x * TAILLE_BLOC;
        position.y = positionBalle.y * TAILLE_BLOC;
        SDL_BlitSurface( balle , NULL, ecran, &position);
        
        if ( bonus == BALLEX2 && bonusActif == ACTIF )
        {
            if ( x == 0 )
            {
                positionBalle2.x = positionBarreM2.x;
                positionBalle2.y = positionBarreM2.y + DIRECHAUT;
                bougerX2 = 0;
                bougerY2 = -1;
                x++;
            }
            position.x = positionBalle2.x * TAILLE_BLOC;
            position.y = positionBalle2.y * TAILLE_BLOC;
            SDL_BlitSurface( balle2 , NULL, ecran, &position);
        }
        
        
        
        if ( bonusActif == INACTIF )
        {
            if ( bonus == EXPLOSIF )
            {
                if ( positionDonne == 0 )
                {
                    positionBonus.x = caseBonusx;
                    positionBonus.y = caseBonusy;
                    positionDonne = 1;
                }
                position.x = positionBonus.x * TAILLE_BLOC;
                position.y = positionBonus.y * TAILLE_BLOC;
                SDL_BlitSurface( explo , NULL, ecran, &position );
                temps2 = SDL_GetTicks();
                if ( (temps2-tempsAvant2) > VITESSEBONUS )
                {
                    //Fonction qui fais bouger les bonus et dit si ils ont été récupéré par la raquette ou pas.
                    deplacerBonus( carte , &positionBonus , &positionDonne , &bonusActif , &bonus );
                    tempsAvant2 = temps2;
                }
            }
            else if ( bonus == COLLANT )
            {
                if ( positionDonne == 0 )
                {
                    positionBonus.x = caseBonusx;
                    positionBonus.y = caseBonusy;
                    positionDonne = 1;
                }
                position.x = positionBonus.x * TAILLE_BLOC;
                position.y = positionBonus.y * TAILLE_BLOC;
                SDL_BlitSurface( colle , NULL, ecran, &position );
                temps2 = SDL_GetTicks();
                if ( (temps2-tempsAvant2) > VITESSEBONUS )
                {
                    deplacerBonus( carte , &positionBonus , &positionDonne , &bonusActif , &bonus );
                    tempsAvant2 = temps2;
                }
            }
            else if ( bonus == RETRECIR )
            {
                if ( positionDonne == 0 )
                {
                    positionBonus.x = caseBonusx;
                    positionBonus.y = caseBonusy;
                    positionDonne = 1;
                }
                position.x = positionBonus.x * TAILLE_BLOC;
                position.y = positionBonus.y * TAILLE_BLOC;
                SDL_BlitSurface( retrecir , NULL, ecran, &position );
                temps2 = SDL_GetTicks();
                if ( (temps2-tempsAvant2) > VITESSEBONUS )
                {
                    deplacerBonus( carte , &positionBonus , &positionDonne , &bonusActif , &bonus );
                    tempsAvant2 = temps2;
                }
            }
            else if ( bonus == GRANDIR )
            {
                if ( positionDonne == 0 )
                {
                    positionBonus.x = caseBonusx;
                    positionBonus.y = caseBonusy;
                    positionDonne = 1;
                }
                position.x = positionBonus.x * TAILLE_BLOC;
                position.y = positionBonus.y * TAILLE_BLOC;
                SDL_BlitSurface( agrandir , NULL, ecran, &position );
                temps2 = SDL_GetTicks();
                if ( (temps2-tempsAvant2) > VITESSEBONUS )
                {
                    deplacerBonus( carte , &positionBonus , &positionDonne , &bonusActif , &bonus );
                    tempsAvant2 = temps2;
                }
            }
            else if ( bonus == BALLEX2 )
            {
                if ( positionDonne == 0 )
                {
                    positionBonus.x = caseBonusx;
                    positionBonus.y = caseBonusy;
                    positionDonne = 1;
                }
                position.x = positionBonus.x * TAILLE_BLOC;
                position.y = positionBonus.y * TAILLE_BLOC;
                SDL_BlitSurface( ballex3 , NULL, ecran, &position );
                temps2 = SDL_GetTicks();
                if ( (temps2-tempsAvant2) > VITESSEBONUS )
                {
                    deplacerBonus( carte , &positionBonus , &positionDonne , &bonusActif , &bonus );
                    tempsAvant2 = temps2;
                }
            }
            
            else if ( bonus == VITESSEMOINS)
            {
                if ( positionDonne == 0 )
                {
                    positionBonus.x = caseBonusx;
                    positionBonus.y = caseBonusy;
                    positionDonne = 1;
                }
                position.x = positionBonus.x * TAILLE_BLOC;
                position.y = positionBonus.y * TAILLE_BLOC;
                SDL_BlitSurface( vitesseMoins , NULL, ecran, &position );
                temps2 = SDL_GetTicks();
                if ( (temps2-tempsAvant2) > VITESSEBONUS )
                {
                    deplacerBonus( carte , &positionBonus , &positionDonne , &bonusActif , &bonus );
                    tempsAvant2 = temps2;
                }
            }
            else if ( bonus == VITESSEPLUS)
            {
                if ( positionDonne == 0 )
                {
                    positionBonus.x = caseBonusx;
                    positionBonus.y = caseBonusy;
                    positionDonne = 1;
                }
                position.x = positionBonus.x * TAILLE_BLOC;
                position.y = positionBonus.y * TAILLE_BLOC;
                SDL_BlitSurface( vitessePlus , NULL, ecran, &position );
                temps2 = SDL_GetTicks();
                if ( (temps2-tempsAvant2) > VITESSEBONUS )
                {
                    deplacerBonus( carte , &positionBonus , &positionDonne , &bonusActif , &bonus );
                    tempsAvant2 = temps2;
                }
                
            }
        }
        
        else if ( bonusActif == ACTIF )
        {
            if ( bonus == EXPLOSIF )
            {
                balle = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/balle_explosive.png");
            }
            if (bonus == VITESSEMOINS) {
                *vitesseDeBalle = 120;
            }
            if (bonus == VITESSEPLUS) {
                *vitesseDeBalle = 40;
            }
            if ( bonus == AUCUN )
            {
                balle = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/balle_normale.png");
                *vitesseDeBalle = VITESSEBALLE;
                bonusActif = 0;
                x = 0;
                b = 0;
                tour2 = 0;
            }
        }
        
        //Si il y a plus de brique on passe au niveau suivant.
        if ( BriqueRestantes == 0 )
        {
            sauvniveau = *niveau;
            SDL_BlitSurface( victoire , NULL , ecran , &positionVictoire );
            SDL_Flip(ecran);
            SDL_Delay(1000);
            *jouer = 0;
            continuer = 0;
            *niveau = *niveau + 1;
            *vitesseDeBalle = VITESSEBALLE;
            *vie = 3;
            if ( *niveau <= 4 )
            {
                if ( sauvniveau != *niveau )
                {
                    if (  *niveau == 2 ) {
                        imgNiveau = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Niveau 2.png");
                        positionNiveau.x = 0;
                        positionNiveau.y = 0;
                        SDL_BlitSurface(imgNiveau , NULL , ecran , &positionNiveau);
                        SDL_Flip(ecran);
                        SDL_Delay(2000);
                    }
                    else if (  *niveau == 3 ) {
                        imgNiveau = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Niveau 3.png");
                        positionNiveau.x = 0;
                        positionNiveau.y = 0;
                        SDL_BlitSurface(imgNiveau , NULL , ecran , &positionNiveau);
                        SDL_Flip(ecran);
                        SDL_Delay(2000);
                    }
                    else if (  *niveau == 4 ) {
                        imgNiveau = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Niveau 4.png");
                        positionNiveau.x = 0;
                        positionNiveau.y = 0;
                        SDL_BlitSurface(imgNiveau , NULL , ecran , &positionNiveau);
                        SDL_Flip(ecran);
                        SDL_Delay(2000);
                    }
                    *jouer = 1;
                }
            }
            
        }
        
        SDL_Flip(ecran);
        
        //Si la balle n'a pas encore  quitté la raquette.
        if ( start == 0 )
        {
            SDL_WaitEvent(&event);
            switch ( event.type )
            {
                case SDL_QUIT:
                    continuer = 0;
                    *jouer = 0;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        *jouer = 0;
                        *niveau = 1;
                        break;
                    case SDLK_UP:
                        start = 1;
                        //Fonction qui déplace la balle et gère les collisions.
                        deplacerBalle( carte , &positionBalle , &positionBarreM , HAUT , &bougerX , &bougerY , &xavant , &yavant , &bonus , &caseBonusx , &caseBonusy , &bonusActif , &start , vie , scoreActuel);
                        break;
                    case SDLK_SPACE:
                        start = 1;
                        deplacerBalle( carte , &positionBalle , &positionBarreM , HAUT , &bougerX , &bougerY , &xavant , &yavant , &bonus , &caseBonusx , &caseBonusy , &bonusActif , &start ,vie , scoreActuel);
                        break;
                    case SDLK_RIGHT:
                        //Fonction qui déplace la raquette et gère les collisions.
                        deplacerBarre( carte , &positionBarreG , &positionBarreM , &positionBarreM2 , &positionBarreM3 , &positionBarreD , &positionBarreM4 , &positionBarreM5 , DROITE , &bougerBalle , &bonus , &bonusActif );
                        if ( bougerBalle == 1 )
                        {
                            deplacerBalle( carte , &positionBalle , &positionBarreM ,  DROITE , &bougerX , &bougerY , &xavant , &yavant , &bonus , &caseBonusx , &caseBonusy , &bonusActif , &start , vie , scoreActuel);
                        }
                        bougerBalle = 0;
                        break;
                    case SDLK_LEFT:
                        deplacerBarre( carte , &positionBarreG , &positionBarreM , &positionBarreM2 , &positionBarreM3 , &positionBarreD , &positionBarreM4 , &positionBarreM5 , GAUCHE , &bougerBalle , &bonus , &bonusActif );
                        if ( bougerBalle == 1 )
                        {
                            deplacerBalle( carte , &positionBalle , &positionBarreM , GAUCHE , &bougerX , &bougerY , &xavant , &yavant , &bonus , &caseBonusx , &caseBonusy , &bonusActif , &start , vie , scoreActuel);
                        }
                        bougerBalle = 0;
                        break;
                    default:
                        break;
                }
                    break;
                default :
                    break;
            }
        }
        
        //Si la balle a enfin été lancé.
        else if ( start == 1 )
        {
            temps1 = SDL_GetTicks();
            if ( (temps1-tempsAvant1) > VITESSEBARRE )
            {
                SDL_PollEvent(&event);
                switch( event.type )
                {
                    case SDL_QUIT:
                        continuer = 0;
                        *jouer = 0;
                        *niveau = 1;
                        break;
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            continuer = 0;
                            *jouer = 0;
                            *niveau = 1;
                            break;
                        //Menu Pause
                        case SDLK_p:
                            pause = 1;
                            do
                            {
                                positionNiveau.x = 0;
                                positionNiveau.y = 0;
                                SDL_BlitSurface( imgPause , NULL , ecran , &positionNiveau);
                                SDL_Flip(ecran);
                                SDL_WaitEvent(&event);
                                switch ( event.type )
                                {
                                    case SDL_QUIT:
                                        continuer = 0;
                                        *jouer = 0;
                                        pause = 0;
                                        break;
                                    case SDL_KEYDOWN:
                                        switch(event.key.keysym.sym)
                                    {
                                        case SDLK_ESCAPE:
                                            continuer = 0;
                                            *jouer = 0;
                                            pause = 0;
                                            break;
                                        case SDLK_SPACE:
                                            pause = 0;
                                            break;
                                        case SDLK_o:
                                            pause = 0;
                                            break;
                                        default:
                                            break;
                                    }
                                        break;
                                    default :
                                        break;
                                }
                            }while ( pause == 1);
                            break;
                        case SDLK_RIGHT:
                            deplacerBarre( carte , &positionBarreG , &positionBarreM , &positionBarreM2 , &positionBarreM3 , &positionBarreD , &positionBarreM4 , &positionBarreM5 , DROITE , &bougerBalle , &bonus , &bonusActif );
                            break;
                        case SDLK_LEFT:
                            deplacerBarre( carte , &positionBarreG , &positionBarreM , &positionBarreM2 , &positionBarreM3 , &positionBarreD , &positionBarreM4 , &positionBarreM5 , GAUCHE , &bougerBalle , &bonus , &bonusActif );
                            break;
                        default:
                            break;
                    }
                        break;
                    default:
                        break;
                }
                if ( bonus == AUCUN )
                {
                    positionDonne = 0;
                }
                tempsAvant1 = temps1;
            }
            temps = SDL_GetTicks();
            if ( (temps-tempsAvant) > *vitesseDeBalle )
            {
                
                if ( a == 12 )
                {
                    a = 0;
                }
                
                posXavant[a] = positionBalle.x;
                posYavant[a] = positionBalle.y;
                
                if (( a == 0 ) && (tour > 0 ))
                {
                    //Servant a avoir la position précédente de la balle pour mieux la rediriger.
                    xavant = posXavant[11] - positionBalle.x;
                    yavant = posYavant[11] - positionBalle.y;
                }
                else if ( tour > 0)
                {
                    xavant = posXavant[a-1] - positionBalle.x;
                    yavant = posYavant[a-1] - positionBalle.y;
                }
                
                deplacerBalle( carte , &positionBalle , &positionBarreM ,RIEN , &bougerX , &bougerY , &xavant , &yavant , &bonus , &caseBonusx , &caseBonusy , &bonusActif , &start , vie , scoreActuel);
                
                scoreActuel2 = 0;
                //Si il y a 2 balles.
                if ( bonus == BALLEX2 && bonusActif  == ACTIF )
                {
                    if ( b == 12 )
                    {
                        b = 0;
                    }
                    
                    posXavant2[b] = positionBalle2.x;
                    posYavant2[b] = positionBalle2.y;
                    
                    if (( b == 0 ) && (tour2 > 0 ))
                    {
                        xavant2 = posXavant2[11] - positionBalle2.x;
                        yavant2 = posYavant2[11] - positionBalle2.y;
                    }
                    else if ( tour2 > 0)
                    {
                        xavant2 = posXavant2[b-1] - positionBalle2.x;
                        yavant2 = posYavant2[b-1] - positionBalle2.y;
                    }
                    
                    deplacerBalle( carte , &positionBalle2 , &positionBarreM , RIEN , &bougerX2 , &bougerY2 , &xavant2 , &yavant2 , &bonus , &caseBonusx , &caseBonusy , &bonusActif , &start , vie , &scoreActuel2);
                    
                    b++;
                    tour2++;
                }
                tempsAvant = temps;
                
                
                a++;
                tour++;
            }
        }
        
    }
    SDL_FreeSurface(explo);
    SDL_FreeSurface(ballex3);
    SDL_FreeSurface(colle);
    SDL_FreeSurface(agrandir);
    SDL_FreeSurface(retrecir);
    SDL_FreeSurface(fond);
    SDL_FreeSurface(barreM4);
    SDL_FreeSurface(barreM5);
    SDL_FreeSurface(balle2);
    SDL_FreeSurface(vitessePlus);
    SDL_FreeSurface(vitesseMoins);
    SDL_FreeSurface(imgVie1);
    SDL_FreeSurface(imgVie2);
    SDL_FreeSurface(imgVie3);
    SDL_FreeSurface(imgNiveau);
    SDL_FreeSurface(gameOver);
    SDL_FreeSurface(imgPause);
    SDL_FreeSurface(texte);
}
void deplacerBarre( int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] , SDL_Rect *posG , SDL_Rect *posM , SDL_Rect *posM2 , SDL_Rect *posM3 , SDL_Rect *posD , SDL_Rect *posM4 , SDL_Rect *posM5 , int direction , int *bougerBalle , int *bonus , int *bonusActif )
{
    switch(direction)
    {
        //Déplace la raquette vers la droite.
        case DROITE:
            if ( *bonus == RETRECIR && *bonusActif == ACTIF )
            {
                if ( posM3->x < NB_BLOCS_LARGEUR - 1 )
                {
                    carte[posG->x][posG->y] = VIDE;
                    carte[posM->x][posM->y] = VIDE;
                    carte[posM2->x][posM2->y] = VIDE;
                    carte[posM3->x][posM3->y] = VIDE;
                    carte[posD->x][posD->y] = VIDE;
                    posD->x++;
                    posM->x++;
                    posM2->x++;
                    posM3->x++;
                    posG->x++;
                    carte[posG->x][posG->y ] = VIDE;
                    carte[posM->x][posM->y ] = BARREG;
                    carte[posM2->x][posM2->y ] = BARREM;
                    carte[posM3->x][posM3->y ] = BARRED;
                    carte[posD->x][posD->y ] = VIDE;
                }
                
            }
            else if ( *bonus == GRANDIR && *bonusActif == ACTIF )
            {
                if ( posM5->x < NB_BLOCS_LARGEUR - 1 )
                {
                    carte[posG->x][posG->y] = VIDE;
                    carte[posM->x][posM->y] = VIDE;
                    carte[posM2->x][posM2->y] = VIDE;
                    carte[posM3->x][posM3->y] = VIDE;
                    carte[posM4->x][posM4->y] = VIDE;
                    carte[posM5->x][posM5->y] = VIDE;
                    carte[posD->x][posD->y] = VIDE;
                    posD->x++;
                    posM->x++;
                    posM2->x++;
                    posM4->x++;
                    posM5->x++;
                    posM3->x++;
                    posG->x++;
                    posM4->x = posG->x + DIRECGAUCHE;
                    posM4->y =  posG->y;
                    carte[posG->x][posG->y] = BARREM4;
                    carte[posM4->x][posM4->y] = BARREG;
                    carte[posM->x][posM->y ] = BARREM;
                    carte[posM2->x][posM2->y ] = BARREM2;
                    carte[posM3->x][posM3->y ] = BARREM3;
                    posM5->x = posD->x + DIRECDROITE;
                    posM5->y =  posD->y;
                    carte[posM5->x][posM5->y] = BARRED;
                    carte[posD->x][posD->y ] = BARREM5;
                }
            }
            else
            {
                if ( posD->x < NB_BLOCS_LARGEUR - 1 )
                {
                    carte[posG->x][posG->y] = VIDE;
                    carte[posM->x][posM->y] = VIDE;
                    carte[posM2->x][posM2->y] = VIDE;
                    carte[posM3->x][posM3->y] = VIDE;
                    carte[posD->x][posD->y] = VIDE;
                    posD->x++;
                    posM->x++;
                    posM2->x++;
                    posM3->x++;
                    posG->x++;
                    carte[posG->x][posG->y ] = BARREG;
                    carte[posM->x][posM->y ] = BARREM;
                    carte[posM2->x][posM2->y ] = BARREM2;
                    carte[posM3->x][posM3->y ] = BARREM3;
                    carte[posD->x][posD->y ] = BARRED;
                    *bougerBalle = 1;
                }
            }
            break;
        case GAUCHE:
            if ( *bonus == RETRECIR && *bonusActif == ACTIF )
            {
                if ( posM->x > 0 )
                {
                    carte[posG->x][posG->y] = VIDE;
                    carte[posM->x][posM->y] = VIDE;
                    carte[posM2->x][posM2->y] = VIDE;
                    carte[posM3->x][posM3->y] = VIDE;
                    carte[posD->x][posD->y] = VIDE;
                    
                    posD->x--;
                    posM->x--;
                    posM2->x--;
                    posM3->x--;
                    posG->x--;
                    
                    carte[posG->x][posG->y ] = VIDE;
                    carte[posM->x][posM->y ] = BARREG;
                    carte[posM2->x][posM2->y ] = BARREM;
                    carte[posM3->x][posM3->y ] = BARRED;
                    carte[posD->x][posD->y ] = VIDE;
                }
            }
            else if ( *bonus == GRANDIR && *bonusActif == ACTIF )
            {
                if ( posM4->x > 0 )
                {
                    carte[posG->x][posG->y] = VIDE;
                    carte[posM->x][posM->y] = VIDE;
                    carte[posM2->x][posM2->y] = VIDE;
                    carte[posM3->x][posM3->y] = VIDE;
                    carte[posM4->x][posM4->y] = VIDE;
                    carte[posM5->x][posM5->y] = VIDE;
                    carte[posD->x][posD->y] = VIDE;
                    posD->x--;
                    posM->x--;
                    posM2->x--;
                    posM4->x--;
                    posM5->x--;
                    posM3->x--;
                    posG->x--;
                    posM4->x = posG->x + DIRECGAUCHE;
                    posM4->y =  posG->y;
                    carte[posG->x][posG->y] = BARREM4;
                    carte[posM4->x][posM4->y] = BARREG;
                    carte[posM->x][posM->y ] = BARREM;
                    carte[posM2->x][posM2->y ] = BARREM2;
                    carte[posM3->x][posM3->y ] = BARREM3;
                    posM5->x = posD->x + DIRECDROITE;
                    posM5->y =  posD->y;
                    carte[posM5->x][posM5->y] = BARRED;
                    carte[posD->x][posD->y ] = BARREM5;
                }
            }
            else
            {
                if ( posG->x > 0 )
                {
                    carte[posG->x][posG->y] = VIDE;
                    carte[posM->x][posM->y] = VIDE;
                    carte[posM2->x][posM2->y] = VIDE;
                    carte[posM3->x][posM3->y] = VIDE;
                    carte[posD->x][posD->y] = VIDE;
                    
                    posD->x--;
                    posM->x--;
                    posM2->x--;
                    posM3->x--;
                    posG->x--;
                    
                    carte[posG->x][posG->y ] = BARREG;
                    carte[posM->x][posM->y ] = BARREM;
                    carte[posM2->x][posM2->y ] = BARREM2;
                    carte[posM3->x][posM3->y ] = BARREM3;
                    carte[posD->x][posD->y ] = BARRED;
                    *bougerBalle = 1;
                }
            }
            
            break;
        default:
            break;
    }
}
void deplacerBalle( int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] , SDL_Rect *posB , SDL_Rect *posM , int direction , int *bougerX , int *bougerY , int *xavant , int *yavant , int *bonus , int *caseBonusx , int *caseBonusy , int *bonusActif , int *start , int *vie , int *scoreActuel)
{
    
    int i = 0 , b = 0 ;
    switch( direction )
    {
        //Deplace la balle vers la droite
        case DROITE:
            
            posB->x++;
            posB->y = NB_BLOCS_HAUTEUR - 2;
            *bougerX = 0;
            *bougerY = 0;
            
            break;
        case GAUCHE:
            
            posB->x--;
            posB->y = NB_BLOCS_HAUTEUR - 2;
            *bougerX = 0;
            *bougerY = 0;
            
            break;
        //Deplace la balle vers le haut au lancement.
        case HAUT:
            
            if( carte[posB->x][posB->y + DIRECBAS] == BARREM2 )
            {
                musique(1 , 0);
                *bougerX = DIRECLINE;
                *bougerY = DIRECHAUT;
            }
            else if ( carte[posB->x][posB->y + DIRECBAS] == BARREM )
            {
                musique(1 , 0);
                *bougerX = DIRECGAUCHE;
                *bougerY = DIRECHAUT;
                b++;
            }
            else if ( carte[posB->x][posB->y + DIRECBAS] == BARREG )
            {
                musique(1 , 0);
                *bougerX = DIRECGAUCHE;
                *bougerY = DIRECHAUT;
            }
            else if ( carte[posB->x][posB->y + DIRECBAS] == BARRED )
            {
                musique(1 , 0);
                *bougerX = DIRECDROITE;
                *bougerY = DIRECHAUT;
            }
            else if ( carte[posB->x][posB->y + DIRECBAS] == BARREM3 )
            {
                musique(1 , 0);
                *bougerX = DIRECDROITE;
                *bougerY = DIRECHAUT;
                b++;
            }
            
            break;
            
            for ( i = 0 ; i < 2 ; i++ )
            {
            //Gère les collisions et déplace la balle en fonction des collisions. On appel deux fois plus avoir la meilleur redirection possible.
            case RIEN:
                if ( carte[posB->x][posB->y + DIRECHAUT ] == BRIQUE || carte[posB->x][posB->y + DIRECHAUT ] == BRIQUE1COUP || carte[posB->x][posB->y + DIRECHAUT ] == BRIQUE2COUPS || carte[posB->x][posB->y + DIRECHAUT ] == BRIQUE3COUPS || carte[posB->x][posB->y + DIRECHAUT ] == BRIQUENO )
                {
                    if ( posB->y + DIRECHAUT > -1 )
                    {
                        if ( *bougerY == DIRECHAUT )
                        {
                            if ( *xavant == DIRECGAUCHE )
                            {
                                if ( posB->x != NB_BLOCS_LARGEUR - 1 )
                                {
                                    if ( *yavant == DIRECBAS )
                                    {
                                  
                                        *bougerX = DIRECDROITE;
                                        *bougerY = DIRECBAS;
                                        //Fonction qui casse les briques.
                                        casseur( carte , posB->x , posB->y + DIRECHAUT , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel );
                                    }
                                }
                                
                            }
                            
                            else if ( *xavant == DIRECLINE )
                            {
                                if ( *yavant == DIRECBAS )
                                {
                                    
                                    *bougerX = DIRECLINE;
                                    *bougerY = DIRECBAS;
                                    casseur( carte , posB->x , posB->y + DIRECHAUT , bonus , caseBonusx , caseBonusy , bonusActif  , scoreActuel);
                                }
                            }
                            else if  ( *xavant == DIRECDROITE )
                            {
                                if ( *yavant == DIRECBAS)
                                {
                                   
                                    *bougerX = DIRECGAUCHE;
                                    *bougerY = DIRECBAS;
                                    casseur( carte , posB->x , posB->y + DIRECHAUT , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                                }
                            }
                        }
                    }
                }
                if ( carte[posB->x][posB->y + DIRECBAS] == BRIQUE || carte[posB->x][posB->y + DIRECBAS] == BRIQUE1COUP || carte[posB->x][posB->y + DIRECBAS] == BRIQUE2COUPS || carte[posB->x][posB->y + DIRECBAS] == BRIQUE3COUPS || carte[posB->x][posB->y + DIRECBAS] == BRIQUENO )
                {
                    if ( posB->y + DIRECBAS < NB_BLOCS_HAUTEUR )
                    {
                        if ( *bougerY == DIRECBAS )
                        {
                            if ( *xavant == DIRECGAUCHE )
                            {
                                if ( *yavant == DIRECHAUT)
                                {
                                    
                                    *bougerX = DIRECDROITE;
                                    *bougerY = DIRECHAUT;
                                    casseur( carte , posB->x , posB->y + DIRECBAS  , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                                }
                            }
                            else if ( *xavant == DIRECLINE )
                            {
                                if ( *yavant == DIRECHAUT)
                                {
                                    
                                    *bougerX = DIRECLINE;
                                    *bougerY = DIRECHAUT;
                                    casseur( carte , posB->x , posB->y + DIRECBAS , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                                }
                            }
                            else if  ( *xavant == DIRECDROITE )
                            {
                                if ( *yavant == DIRECHAUT)
                                {
                                    
                                    *bougerX = DIRECGAUCHE;
                                    *bougerY = DIRECHAUT;
                                    
                                    casseur( carte , posB->x , posB->y + DIRECBAS , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                                }
                                
                            }
                        }
                    }
                    
                    
                }
                if ( carte[posB->x + DIRECDROITE][posB->y] == BRIQUE ||  carte[posB->x + DIRECDROITE][posB->y] == BRIQUE1COUP ||  carte[posB->x + DIRECDROITE][posB->y] == BRIQUE2COUPS ||  carte[posB->x + DIRECDROITE][posB->y] == BRIQUE3COUPS ||  carte[posB->x + DIRECDROITE][posB->y] == BRIQUENO )
                {
                    if ( posB->x + DIRECDROITE < NB_BLOCS_LARGEUR )
                    {
                        
                        if  ( *xavant == DIRECGAUCHE )
                        {
                            if ( *xavant != DIRECLINE )
                            {
                                if ( *yavant == DIRECBAS)
                                {
                                    
                                    *bougerX = DIRECGAUCHE;
                                    *bougerY = DIRECHAUT;
                                    casseur( carte , posB->x + DIRECDROITE , posB->y , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                                }
                                else if ( *yavant == DIRECHAUT )
                                {
                                    
                                    *bougerX = DIRECGAUCHE;
                                    *bougerY = DIRECBAS;
                                    casseur( carte , posB->x + DIRECDROITE , posB->y , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                                }
                            }
                            
                        }
                    }
                    
                    
                }
                if ( carte[posB->x + DIRECGAUCHE][posB->y] == BRIQUE || carte[posB->x + DIRECGAUCHE][posB->y] == BRIQUE1COUP || carte[posB->x + DIRECGAUCHE][posB->y] == BRIQUE2COUPS || carte[posB->x + DIRECGAUCHE][posB->y] == BRIQUE3COUPS || carte[posB->x + DIRECGAUCHE][posB->y] == BRIQUENO )
                {
                    if ( posB->x + DIRECGAUCHE > -1 )
                    {
                        if ( *xavant != DIRECLINE )
                        {
                            if ( *xavant == DIRECDROITE )
                            {
                                if ( *yavant == DIRECHAUT)
                                {
                                    
                                    *bougerX = DIRECDROITE;
                                    *bougerY = DIRECBAS;
                                    casseur( carte , posB->x + DIRECGAUCHE , posB->y , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                                }
                                else if ( *yavant == DIRECBAS )
                                {
                                    
                                    *bougerX = DIRECDROITE;
                                    *bougerY = DIRECHAUT;
                                    casseur( carte , posB->x + DIRECGAUCHE , posB->y , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                                }
                            }
                        }
                    }
                    
                    
                }
                if ( *xavant != DIRECLINE )
                {
                    if ( carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS] == BRIQUE ||  carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS] == BRIQUE1COUP ||  carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS] == BRIQUE2COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS] == BRIQUE3COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS] == BRIQUENO )
                    {
                        if ( posB->x + DIRECDROITE < NB_BLOCS_LARGEUR && posB->y + DIRECBAS < NB_BLOCS_HAUTEUR )
                        {
                            if ( carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS] == carte[posB->x + *bougerX ][posB->y + *bougerY ] )
                            {
                               
                                *bougerX = DIRECGAUCHE;
                                *bougerY = DIRECHAUT;
                                casseur( carte , posB->x + DIRECDROITE , posB->y + DIRECBAS , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                            }
                            
                        }
                    }
                    if ( carte[posB->x + DIRECGAUCHE][posB->y + DIRECBAS] == BRIQUE || carte[posB->x + DIRECGAUCHE][posB->y + DIRECBAS] == BRIQUE1COUP || carte[posB->x + DIRECGAUCHE][posB->y + DIRECBAS] == BRIQUE2COUPS || carte[posB->x + DIRECGAUCHE][posB->y + DIRECBAS] == BRIQUE3COUPS || carte[posB->x + DIRECGAUCHE][posB->y + DIRECBAS] == BRIQUENO )
                    {
                        if ( posB->x + DIRECGAUCHE > 0 && posB->y + DIRECBAS < NB_BLOCS_HAUTEUR )
                        {
                            if ( carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS] == carte[posB->x + *bougerX ][posB->y + *bougerY ] )
                            {
                                
                                *bougerX = DIRECDROITE;
                                *bougerY = DIRECHAUT;
                                casseur( carte , posB->x + DIRECGAUCHE , posB->y + DIRECBAS , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                            }
                        }
                        
                    }
                    
                    
                    if ( posB->x + DIRECDROITE < NB_BLOCS_LARGEUR && posB->y + DIRECHAUT > 0 )
                    {
                        if ( carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT] == BRIQUE || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT] == BRIQUE1COUP || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT] == BRIQUE2COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT] == BRIQUE3COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT] == BRIQUENO )
                        {
                            if ( carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT] == carte[posB->x + *bougerX ][posB->y + *bougerY ] )
                            {
                                
                                *bougerX = DIRECGAUCHE;
                                *bougerY = DIRECBAS;
                                casseur( carte , posB->x + DIRECDROITE , posB->y + DIRECHAUT , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                            }
                        }
                    }
                    if (posB->x + DIRECGAUCHE > 0 && posB->y + DIRECHAUT > 0) {
                        
                        if ( carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT] == BRIQUE || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT] == BRIQUE1COUP || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT] == BRIQUE2COUPS || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT] == BRIQUE3COUPS || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT] == BRIQUENO )
                        {
                            if ( carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT] == carte[posB->x + *bougerX ][posB->y + *bougerY ] )
                            {
                                
                                *bougerX = DIRECDROITE;
                                *bougerY = DIRECBAS;
                                casseur( carte , posB->x + DIRECGAUCHE , posB->y + DIRECHAUT , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                            }
                        }
                    }
                }
                if ( posB->y == 0)
                {
                    
                    if ( *xavant == DIRECGAUCHE )
                    {
                        if ( *yavant == DIRECBAS)
                        {
                            if ( carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS ] != BRIQUE || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS ] != BRIQUE1COUP || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS ] != BRIQUE2COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS ] != BRIQUE3COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS ] != BRIQUENO )
                            {
                                *bougerX = DIRECDROITE;
                                *bougerY = DIRECBAS;
                            }
                        }
                    }
                    
                    else if ( *xavant == DIRECLINE )
                    {
                        if ( *yavant == DIRECBAS)
                            if ( carte[posB->x + DIRECLINE ][posB->y + DIRECBAS ] != BRIQUE || carte[posB->x + DIRECLINE ][posB->y + DIRECBAS ] != BRIQUE1COUP || carte[posB->x + DIRECLINE ][posB->y + DIRECBAS ] != BRIQUE2COUPS || carte[posB->x + DIRECLINE ][posB->y + DIRECBAS ] != BRIQUE3COUPS || carte[posB->x + DIRECLINE ][posB->y + DIRECBAS ] != BRIQUENO )
                            {
                                {
                                    *bougerX = DIRECLINE;
                                    *bougerY = DIRECBAS;
                                }
                            }
                    }
                    
                    else if  ( *xavant == DIRECDROITE )
                    {
                        if ( carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS ] != BRIQUE || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS ] != BRIQUE1COUP || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS ] != BRIQUE2COUPS || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS ] != BRIQUE3COUPS || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS ] != BRIQUENO )
                        {
                            if ( *yavant == DIRECBAS)
                            {
                                *bougerX = DIRECGAUCHE;
                                *bougerY = DIRECBAS;
                            }
                        }
                    }
                    
                }
                if ( posB->y + 1 == NB_BLOCS_HAUTEUR )
                {
                        if ( carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT ] != BRIQUE || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT ] != BRIQUE1COUP || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT ] != BRIQUE2COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT ] != BRIQUE3COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT ] != BRIQUENO )
                        {
                            if ( *bonusActif != ACTIF) {
                                *bonus = AUCUN;
                                //Fonction qui gère les vies.
                                viePerdu ( carte , start , posB , posM , xavant , yavant , vie , scoreActuel);
                            }
                            
                        }
                    *bonus = AUCUN;
                }
                if ( posB->x + DIRECDROITE == NB_BLOCS_LARGEUR )
                {
                    if ( *xavant != DIRECLINE )
                    {
                        if ( *yavant == DIRECBAS )
                        {
                            if ( carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT] != BRIQUE || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT] != BRIQUE1COUP || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT] != BRIQUE2COUPS || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT] != BRIQUE3COUPS || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT] != BRIQUENO )
                            {
                                *bougerX = DIRECGAUCHE;
                                *bougerY = DIRECHAUT;
                            }
                        }
                        
                        if ( *yavant == DIRECHAUT )
                        {
                            if ( carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS ] != BRIQUE || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS ] != BRIQUE1COUP || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS ] != BRIQUE2COUPS || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS ] != BRIQUE3COUPS || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS ] != BRIQUENO )
                            {
                                *bougerX = DIRECGAUCHE;
                                *bougerY = DIRECBAS;
                            }
                        }
                    }
                    
                    
                }
                if ( posB->x == 0  )
                {
                    if ( *xavant != DIRECLINE )
                    {
                        if ( *yavant == DIRECBAS )
                        {
                            if ( carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT ] != BRIQUE || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT ] != BRIQUE1COUP || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT ] != BRIQUE2COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT ] != BRIQUE3COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT ] != BRIQUENO )
                            {
                                
                                *bougerX = DIRECDROITE;
                                *bougerY = DIRECHAUT;
                                
                            }
                        }
                        else if ( *yavant == DIRECHAUT )
                        {
                            if ( carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS ] != BRIQUE || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS ] != BRIQUE1COUP || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS ] != BRIQUE2COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS ] != BRIQUE3COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS ] != BRIQUENO )
                            {
                                *bougerX = DIRECDROITE;
                                *bougerY = DIRECBAS;
                            }
                        }
                    }
                }
                if ( carte[posB->x][posB->y + DIRECBAS] == BARREM || carte[posB->x][posB->y + DIRECBAS] == BARREM3 )
                {
                    musique(1 , 0);
                    if ( *xavant == DIRECGAUCHE )
                    {
                        if ( *yavant == DIRECHAUT )
                        {
                            *bougerX = DIRECDROITE;
                            *bougerY = DIRECHAUT;
                            b++;
                        }
                    }
                    else if ( *xavant == DIRECLINE )
                    {
                        if ( *yavant == DIRECHAUT)
                        {
                            if ( carte[posB->x][posB->y + DIRECBAS] == BARREM )
                            {
                                musique(1 , 0);
                                *bougerX = DIRECGAUCHE ;
                                *bougerY = DIRECHAUT;
                                b++;
                            }
                            if ( carte[posB->x][posB->y + DIRECBAS] == BARREM3 )
                            {
                                musique(1 , 0);
                                *bougerX = DIRECDROITE ;
                                *bougerY = DIRECHAUT;
                                b++;
                            }
                        }
                    }
                    else if  ( *xavant == DIRECDROITE )
                    {
                        if ( *yavant == DIRECHAUT)
                        {
                            musique(1 , 0);
                            *bougerX = DIRECGAUCHE ;
                            *bougerY = DIRECHAUT;
                            b++;
                        }
                    }
                }
                if ( carte[posB->x][posB->y + DIRECBAS] == BARREM4 || carte[posB->x][posB->y + DIRECBAS] == BARREM5 )
                {
                    musique(1 , 0);
                    if ( *xavant == DIRECGAUCHE )
                    {
                        if ( *yavant == DIRECHAUT )
                        {
                            *bougerX = DIRECDROITE;
                            *bougerY = DIRECHAUT;
                            
                        }
                    }
                    else if ( *xavant == DIRECLINE )
                    {
                        if ( *yavant == DIRECHAUT)
                        {
                            if ( carte[posB->x][posB->y + DIRECBAS] == BARREM4 )
                            {
                                *bougerX = DIRECGAUCHE;
                                *bougerY = DIRECHAUT;
                                
                            }
                            if ( carte[posB->x][posB->y + DIRECBAS] == BARREM5 )
                            {
                                *bougerX = DIRECDROITE ;
                                *bougerY = DIRECHAUT;
                                
                            }
                        }
                    }
                    else if  ( *xavant == DIRECDROITE )
                    {
                        if ( *yavant == DIRECHAUT)
                        {
                            *bougerX = DIRECGAUCHE;
                            *bougerY = DIRECHAUT;
                            
                        }
                    }
                }
                if ( carte[posB->x][posB->y + DIRECBAS] == BARREM2 )
                {
                    musique(1 , 0);
                    *bougerX = DIRECLINE;
                    *bougerY = DIRECHAUT;
                }
                if ( carte[posB->x][posB->y + DIRECBAS] == BARRED )
                {
                    musique(1 , 0);
                    *bougerX = DIRECDROITE;
                    *bougerY = DIRECHAUT;
                }
                if ( carte[posB->x + DIRECGAUCHE][posB->y + DIRECBAS] == BARRED )
                {
                    if (posB->x + DIRECGAUCHE > 0) {
                        musique(1 , 0);
                        *bougerX = DIRECDROITE;
                        *bougerY = DIRECHAUT;
                    }
                    
                }
                if ( carte[posB->x][posB->y + DIRECBAS] == BARREG )
                {
                    musique(1 , 0);
                    *bougerX = DIRECGAUCHE;
                    *bougerY = DIRECHAUT;
                }
                if ( carte[posB->x + DIRECDROITE][posB->y + DIRECBAS] == BARREG )
                {
                    if (posB->x + DIRECDROITE < NB_BLOCS_LARGEUR) {
                        musique(1 , 0);
                    *bougerX = DIRECGAUCHE;
                    *bougerY = DIRECHAUT;
                    }
                }
                if ( carte[posB->x + DIRECGAUCHE][posB->y + DIRECBAS] == BARRED && posB->x + DIRECDROITE == NB_BLOCS_LARGEUR )
                {
                    if (posB->x + DIRECGAUCHE > 0) {

                    musique(1 , 0);
                    *bougerX = DIRECGAUCHE;
                    *bougerY = DIRECHAUT;
                    }
                }
                if ( carte[posB->x + DIRECDROITE][posB->y + DIRECBAS] == BARREG && posB->x + DIRECGAUCHE == -1 )
                {
                    if (posB->x + DIRECDROITE < NB_BLOCS_LARGEUR) {
                    musique(1 , 0);
                    *bougerX = DIRECDROITE;
                    *bougerY = DIRECHAUT;
                    }
                }
                if ( posB->x + DIRECGAUCHE == -1 && posB->y - 1 == -1 )
                {
                    *bougerX = DIRECDROITE;
                    *bougerY = DIRECBAS;
                }
                if ( posB->y + 1 == NB_BLOCS_HAUTEUR && posB->x + DIRECDROITE == NB_BLOCS_LARGEUR )
                {
                    if ( *bonusActif != ACTIF) {
                        *bonus = AUCUN;
                        viePerdu ( carte , start , posB , posM , xavant , yavant , vie , scoreActuel);
                    }
                    *bonus = AUCUN;
                }
                if ( posB->y + 1 == NB_BLOCS_HAUTEUR  && posB->x + DIRECGAUCHE == -1 )
                {
                    if ( *bonusActif != ACTIF) {
                        *bonus = AUCUN;
                        viePerdu ( carte , start , posB , posM , xavant , yavant , vie , scoreActuel);
                    }
                    *bonus = AUCUN;
                }
                if ( posB->x == NB_BLOCS_LARGEUR - 1 &&  posB->y - 1 == -1 )
                {
                    *bougerX = DIRECGAUCHE;
                    *bougerY = DIRECBAS;
                }
                if ( posB->y == 0 && ( carte[posB->x][posB->y + DIRECBAS] == BRIQUE || carte[posB->x][posB->y + DIRECBAS] == BRIQUE1COUP || carte[posB->x][posB->y + DIRECBAS] == BRIQUE2COUPS || carte[posB->x][posB->y + DIRECBAS] == BRIQUE3COUPS || carte[posB->x][posB->y + DIRECBAS] == BRIQUENO ) )
                {
                    if ( posB->y  + DIRECBAS > 0 )
                    {
                       
                        *bougerX = DIRECLINE;
                        *bougerY = DIRECBAS;
                        casseur( carte , posB->x + DIRECGAUCHE , posB->y + DIRECBAS , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                    }
                    
                }
                if ( posB->y == 0 && ( carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS] == BRIQUE || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS] == BRIQUE1COUP || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS] == BRIQUE2COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS] == BRIQUE3COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS] == BRIQUENO ) )
                {
                    if ( posB->x + DIRECDROITE < NB_BLOCS_LARGEUR && posB->y  + DIRECBAS > 0 )
                    {
                        if ( *xavant != DIRECLINE )
                        {
                            
                            *bougerX = DIRECGAUCHE;
                            *bougerY = DIRECBAS;
                            casseur( carte , posB->x + DIRECDROITE , posB->y + DIRECBAS , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                        }
                    }
                    
                }
                if ( posB->y == 0 &&  ( carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS] == BRIQUE || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS] == BRIQUE1COUP || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS] == BRIQUE2COUPS || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS] == BRIQUE3COUPS || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS] == BRIQUENO ))
                {
                    if ( posB->x + DIRECGAUCHE > 0 && posB->y  + DIRECBAS > 0 )
                    {
                        if ( *xavant != DIRECLINE )
                        {
                            
                            *bougerX = DIRECDROITE;
                            *bougerY = DIRECBAS;
                            casseur( carte , posB->x + DIRECGAUCHE , posB->y + DIRECBAS , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                        }
                    }
                }
                if ( posB->x == 0 && ( carte[posB->x][posB->y + DIRECHAUT ] == BRIQUE || carte[posB->x][posB->y + DIRECHAUT ] == BRIQUE1COUP || carte[posB->x][posB->y + DIRECHAUT ] == BRIQUE2COUPS || carte[posB->x][posB->y + DIRECHAUT ] == BRIQUE3COUPS || carte[posB->x][posB->y + DIRECHAUT ] == BRIQUENO ) )
                {
                    if ( posB->y + DIRECHAUT > NB_BLOCS_HAUTEUR )
                    {
                        
                        *bougerX = DIRECDROITE;
                        *bougerY = DIRECBAS;
                        casseur( carte , posB->x , posB->y + DIRECHAUT , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                    }
                    
                }
                if ( posB->x == NB_BLOCS_LARGEUR - 1 && ( carte[posB->x][posB->y + DIRECHAUT ] == BRIQUE || carte[posB->x][posB->y + DIRECHAUT ] == BRIQUE1COUP || carte[posB->x][posB->y + DIRECHAUT ] == BRIQUE2COUPS || carte[posB->x][posB->y + DIRECHAUT ] == BRIQUE3COUPS || carte[posB->x][posB->y + DIRECHAUT ] == BRIQUENO ) )
                {
                    if ( posB->y + DIRECHAUT > NB_BLOCS_HAUTEUR )
                    {
                      
                        *bougerX = DIRECGAUCHE;
                        *bougerY = DIRECBAS;
                        casseur( carte , posB->x , posB->y + DIRECHAUT , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                    }
                }
                if ( posB->x == 0 && ( carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT]  == BRIQUE || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT]  == BRIQUE1COUP || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT]  == BRIQUE2COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT]  == BRIQUE3COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECHAUT]  == BRIQUENO ) )
                {
                    if ( posB->x + DIRECDROITE < NB_BLOCS_LARGEUR && posB->y  + DIRECHAUT < NB_BLOCS_HAUTEUR )
                    {
                        if ( *xavant != DIRECLINE )
                        {
                           
                            *bougerX = DIRECDROITE;
                            *bougerY = DIRECBAS;
                            casseur( carte , posB->x + DIRECDROITE , posB->y + DIRECHAUT , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                        }
                    }
                    
                }
                if ( posB->x == NB_BLOCS_LARGEUR - 1 && ( carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT]  == BRIQUE || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT]  == BRIQUE1COUP || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT]  == BRIQUE2COUPS || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT]  == BRIQUE3COUPS || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECHAUT]  == BRIQUENO ) )
                {
                    if ( posB->x + DIRECGAUCHE > 0 && posB->y  + DIRECHAUT < NB_BLOCS_HAUTEUR )
                    {
                        if ( *xavant != DIRECLINE )
                        {
                            
                            *bougerX = DIRECGAUCHE;
                            *bougerY = DIRECBAS;
                            casseur( carte , posB->x + DIRECGAUCHE , posB->y + DIRECHAUT , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                        }
                    }
                }
                if ( posB->x == 0 && ( carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS]  == BRIQUE || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS]  == BRIQUE1COUP || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS]  == BRIQUE2COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS]  == BRIQUE3COUPS || carte[posB->x + DIRECDROITE ][posB->y + DIRECBAS]  == BRIQUENO ) )
                {
                    if ( posB->x + DIRECDROITE < NB_BLOCS_LARGEUR && posB->y  + DIRECBAS < NB_BLOCS_HAUTEUR )
                    {
                        if ( *xavant != DIRECLINE )
                        {
                         
                            *bougerX = DIRECDROITE;
                            *bougerY = DIRECHAUT;
                            casseur( carte , posB->x + DIRECDROITE , posB->y + DIRECBAS , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                        }
                    }
                }
                if ( posB->x == 0 && carte[posB->x ][posB->y + DIRECBAS]  == BARREG )
                {
                    musique(1 , 0);
                    if ( *xavant != DIRECLINE )
                    {
                        *bougerX = DIRECDROITE;
                        *bougerY = DIRECHAUT;
                    }
                    if ( *xavant == DIRECLINE )
                    {
                        *bougerX = DIRECLINE;
                        *bougerY = DIRECHAUT;
                    }
                }
                if ( posB->x == NB_BLOCS_LARGEUR - 1 && carte[posB->x ][posB->y + DIRECBAS]  == BARRED )
                {
                    musique(1 , 0);
                    if ( *xavant != DIRECLINE )
                    {
                        *bougerX = DIRECGAUCHE;
                        *bougerY = DIRECHAUT;
                    }
                    if ( *xavant == DIRECLINE )
                    {
                        *bougerX = DIRECLINE;
                        *bougerY = DIRECHAUT;
                    }
                }
                if ( posB->x == NB_BLOCS_LARGEUR - 1 && ( carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS]  == BRIQUE || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS]  == BRIQUE1COUP || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS]  == BRIQUE2COUPS || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS]  == BRIQUE3COUPS || carte[posB->x + DIRECGAUCHE ][posB->y + DIRECBAS]  == BRIQUENO  ) )
                {
                    if ( posB->x + DIRECGAUCHE > -1 && posB->y  + DIRECBAS > -1 )
                    {
                        if ( *xavant != DIRECLINE )
                        {
                            
                            *bougerX = DIRECGAUCHE;
                            *bougerY = DIRECHAUT;
                            casseur( carte , posB->x + DIRECGAUCHE , posB->y + DIRECBAS , bonus , caseBonusx , caseBonusy , bonusActif , scoreActuel);
                        }
                    }
                }
                break;
            default:
                break;
                
            }
    }
    
    if ( posB->y + *bougerY > -1 && posB->y + *bougerY < NB_BLOCS_HAUTEUR )
    {
        if ( posB->x + *bougerX > -1 && posB->x + *bougerX < NB_BLOCS_LARGEUR )
        {
            
            if ( b > 0 )
            {
                //Donne un effet à la balle si elle tape entre le milieu et l'extrémité de la raquette.
                posB->y = posB->y + *bougerY + DIRECHAUT;
            }
            else
            {
                //Bouge la balle en Y.
                posB->y = posB->y + *bougerY;
            }
             //Bouge la balle en X.
            posB->x = posB->x + *bougerX;

        }
    }
    
    if( *bonus == COLLANT && *bonusActif == ACTIF )
    {
        if ( carte[posB->x][posB->y + DIRECBAS] == BARREM2 || carte[posB->x][posB->y + DIRECBAS] == BARREM || carte[posB->x][posB->y + DIRECBAS] == BARREG || carte[posB->x][posB->y + DIRECBAS] == BARRED || carte[posB->x][posB->y + DIRECBAS] == BARREM3 )
        {
            *start = 0;
            *bougerX = 0;
            *bougerY = 0;
            
        }
    }
    
}

void viePerdu ( int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] , int *start , SDL_Rect *posB , SDL_Rect *posM , int *xavant , int *yavant , int *vie , int *scoreActuel) {
    
    //Vie Perdu on remet la balle sur la raquette.
    
    *scoreActuel = *scoreActuel - 50;
    *start = 0 , *xavant = 0 , *yavant = 1;
    carte[posB->x][posB->y] = VIDE;
    posB->x = posM->x + DIRECDROITE;
    posB->y = NB_BLOCS_HAUTEUR - 2;
    carte[posB->x][posB->y] = BALLE;
    *vie = *vie - 1;
    
}

void casseur ( int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] , int valeurx , int valeury ,int *bonus , int *caseBonusx , int *caseBonusy , int *bonusActif , int *scoreActuel )
{
    int x = 0 , i = 0 , j = 0;
    if ( *bonus == EXPLOSIF && *bonusActif == ACTIF )
    {
        if ( ( carte[valeurx][valeury] == BRIQUE || carte[valeurx][valeury] == BRIQUE3COUPS || carte[valeurx][valeury] == BRIQUE2COUPS || carte[valeurx][valeury] == BRIQUE1COUP ) && carte[valeurx][valeury] != BRIQUENO )
        {
            musique(3 , 0);
            *scoreActuel = *scoreActuel + 30;
            //Balle explosive qui explose les briques aux alentoures.
            for ( i = CASEEXPLOSIONNEG ; i < CASEEXPLOSION  ; i++ )
            {
                for ( j = CASEEXPLOSIONNEG ; j < CASEEXPLOSION  ; j++ )
                {
                    if ( carte[valeurx + i][valeury + j] != BRIQUENO )
                    {
                        
                        if ( valeurx + i > -1 && valeury + j > -1 && valeurx + i < NB_BLOCS_LARGEUR && valeury + j < NB_BLOCS_HAUTEUR )
                        {
                            if ( ( carte[valeurx + i][valeury + j] == BRIQUE || carte[valeurx + i][valeury + j] == BRIQUE3COUPS || carte[valeurx + i][valeury + j] == BRIQUE2COUPS || carte[valeurx + i][valeury + j] == BRIQUE1COUP ) && carte[valeurx + i][valeury + j ] != BRIQUENO )
                            {
                                //Vérifie que les briques on été cassé par deux.
                                if ( (valeurx + i) + DIRECGAUCHE > -1 && ( valeurx + i )+ DIRECDROITE < NB_BLOCS_LARGEUR )
                                {
                                    if ( carte[(valeurx + i) + DIRECGAUCHE ][valeury + j] != BRIQUENO && carte[(valeurx + i) + DIRECDROITE ][valeury + j] != BRIQUENO  )
                                    {
                                        carte[( valeurx + i ) + DIRECDROITE ][valeury + j] = VIDE;
                                        carte[( valeurx + i ) + DIRECGAUCHE ][valeury + j] = VIDE;
                                    }
                                    
                                }
                            }
                            carte[valeurx + i][valeury + j] = VIDE;
                        }
                    }
                    
                }
            }
        }
    }
    else
    {
        //Si la brique n'est pas une brique incassable.
        if ( carte[valeurx][valeury] != BRIQUENO )
        {
            //Si c'est une brique normale , on la casse.
            if ( carte[valeurx][valeury] == BRIQUE )
            {
                *scoreActuel = *scoreActuel + 10;
                carte[valeurx][valeury] = VIDE;
                x = 1;
                if ( carte[valeurx + DIRECDROITE ][valeury] == BRIQUE )
                {
                    carte[valeurx + DIRECDROITE ][valeury] = VIDE;
                    
                }
                else if ( carte[valeurx + DIRECGAUCHE ][valeury] == BRIQUE )
                {
                    carte[valeurx + DIRECGAUCHE ][valeury] = VIDE;
                }
            }
            //Si c'est une brique cassable en 3 coups , on la transforme en brique cassable en 2 coups.
            else if ( carte[valeurx][valeury] == BRIQUE3COUPS )
            {
              
                carte[valeurx][valeury] = BRIQUE2COUPS;
                if ( carte[valeurx + DIRECDROITE ][valeury] == BRIQUE3COUPS )
                {
                    carte[valeurx + DIRECDROITE ][valeury] = BRIQUE2COUPS;
                    
                }
                else if ( carte[valeurx + DIRECGAUCHE ][valeury] == BRIQUE3COUPS )
                {
                    carte[valeurx + DIRECGAUCHE ][valeury] = BRIQUE2COUPS;
                }
            }
            //Si c'est une brique cassable en 2 coups , on la transforme en brique cassable en 1 coup.
            else if ( carte[valeurx][valeury] == BRIQUE2COUPS )
            {
               
                carte[valeurx][valeury] = BRIQUE1COUP;
                if ( carte[valeurx + DIRECDROITE ][valeury] == BRIQUE2COUPS )
                {
                    carte[valeurx + DIRECDROITE ][valeury] = BRIQUE1COUP;
                    
                }
                else if ( carte[valeurx + DIRECGAUCHE ][valeury] == BRIQUE2COUPS )
                {
                    carte[valeurx + DIRECGAUCHE ][valeury] = BRIQUE1COUP;
                }
            }
            //Si c'est une brique cassable en 1 coup , on la casse.
            else if ( carte[valeurx][valeury] == BRIQUE1COUP )
            {
                carte[valeurx][valeury] = VIDE;
                x = 1;
                *scoreActuel = *scoreActuel + 20;
                if ( carte[valeurx + DIRECDROITE ][valeury] == BRIQUE1COUP )
                {
                    carte[valeurx + DIRECDROITE ][valeury] = VIDE;
                    
                }
                else if ( carte[valeurx + DIRECGAUCHE ][valeury] == BRIQUE1COUP )
                {
                    carte[valeurx + DIRECGAUCHE ][valeury] = VIDE;
                }
            }
        }
        
    }
    //Générateur de bonus.
    if ( x == 1 )
    {
        srand(time(NULL));
        if ( *bonus == AUCUN )
        {
            //On génère un nombre aléatoire entre le minimum et le maximum.
            *bonus = rand() % ( MAX - MIN + 1);
            
        }
        //Si le nombre sortie correspond au nombre d'un bonus , on lui attribue sa position.
        if ( *bonus == EXPLOSIF || *bonus == COLLANT || *bonus == RETRECIR || *bonus == GRANDIR || *bonus == BALLEX2 || *bonus == VITESSEMOINS || *bonus == VITESSEPLUS )
        {
            *caseBonusx = valeurx;
            *caseBonusy = valeury;
        }
        else
        {
            *bonus = AUCUN;
        }
    }
}

void deplacerBonus( int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] , SDL_Rect *posBonus , int *positionDonne , int *bonusActif , int *bonus )
{
    //Vérifie si le bonus est inactif et le déplace.
    if ( *bonusActif == INACTIF )
    {
        if( carte[ posBonus->x ][ posBonus->y + DIRECBAS ] == BARRED || carte[ posBonus->x ][ posBonus->y + DIRECBAS ] == BARREM || carte[ posBonus->x ][ posBonus->y + DIRECBAS ] == BARREM2 || carte[ posBonus->x ][ posBonus->y + DIRECBAS ] == BARREM3 || carte[ posBonus->x ][ posBonus->y + DIRECBAS ] == BARREG )
        {
            *bonusActif = ACTIF;
            *positionDonne = 0;
            carte[posBonus->x][posBonus->y] = VIDE;
        }
        else if ( posBonus->y + DIRECBAS  == NB_BLOCS_HAUTEUR )
        {
            *bonus = AUCUN;
            *bonusActif = INACTIF;
            *positionDonne = 0;
            carte[posBonus->x][posBonus->y] = VIDE;
            
        }
        posBonus->y++;
    }
}


