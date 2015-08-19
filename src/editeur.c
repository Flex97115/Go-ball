//
//  editeur.c
//  Go Ball
//
//  Created by Gery THRASIBULE on 27/05/2014.
//  Copyright (c) 2014 CTGV. All rights reserved.
//

#include "header.h"


void editeur( SDL_Surface* ecran , int *niveau )
{
    //Edition des niveaux.
    SDL_Surface  *fond = NULL , *balle = NULL, *brique = NULL , *barreD = NULL , *barreM = NULL , *barreM2 = NULL , *barreM3 = NULL , *barreG = NULL , *brique3coups = NULL , *brique2coups = NULL , *brique1coup = NULL , *briqueno = NULL;
    SDL_Rect position , positionFond;
    SDL_Event event;
    
    int continuer = 1 , clicDroit = 0 , clicGauche = 0;
    int objetactuel = BRIQUE , i = 0 , j = 0;
    int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] = {{0}};
    
    balle = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/balle_normale.png");
    barreD = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/pad_droite.png");
    brique3coups = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/brique_3fois_1.png");
    brique2coups = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/brique_3fois_2.png");
    brique1coup = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/brique_3fois_3.png");
    briqueno = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/brique_incassable.png");
    barreM = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/pad_centre.png");
    barreM2 = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/pad_centre.png");
    barreM3 = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/pad_centre.png");
    barreG = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/pad_gauche.png");
    brique = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/brique_normale.png");
    fond = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/game_background.png");
    
    while ( continuer == 1 )
    {
        SDL_WaitEvent(&event);
        switch ( event.type )
        {
            case SDL_QUIT :
                continuer = 0;
                break;
            case SDL_MOUSEBUTTONDOWN :
                if ( event.button.button == SDL_BUTTON_LEFT )
                {
                    carte[event.button.x / TAILLE_BLOC ][event.button.y / TAILLE_BLOC ] = objetactuel;
                    clicGauche = 1;
                    
                }
                else if ( event.button.button == SDL_BUTTON_RIGHT )
                {
                    carte[event.button.x / TAILLE_BLOC ][event.button.y / TAILLE_BLOC ] = VIDE;
                    clicDroit = 1;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if ( event.button.button == SDL_BUTTON_LEFT )
                {
                    clicGauche = 0;
                }
                else if (event.button.button == SDL_BUTTON_RIGHT )
                {
                    clicDroit = 0;
                }
                break;
            case SDL_MOUSEMOTION :
                if ( clicDroit == 1 )
                {
                    carte[event.button.x / TAILLE_BLOC ][event.button.y / TAILLE_BLOC ] = VIDE;
                }
                else if ( clicGauche == 1 )
                {
                    carte[event.button.x / TAILLE_BLOC ][event.button.y / TAILLE_BLOC ] = objetactuel;
                }
                break;
            case SDL_KEYDOWN:
                switch ( event.key.keysym.sym )
            {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                case SDLK_s:
                    sauvegarderNiveau(carte , *niveau);
                    break;
                case SDLK_c:
                    chargerNiveau(carte , *niveau );
                    break;
                case SDLK_a:
                    objetactuel = BRIQUE;
                    break;
                case SDLK_z:
                    objetactuel = BALLE;
                    break;
                case SDLK_e:
                    objetactuel = BARREG;
                    break;
                case SDLK_r:
                    objetactuel = BARREM;
                    break;
                case SDLK_t:
                    objetactuel = BARREM2;
                    break;
                case SDLK_y:
                    objetactuel = BARREM3;
                    break;
                case SDLK_u:
                    objetactuel = BARRED;
                    break;
                case SDLK_i:
                    objetactuel = BRIQUE3COUPS;
                    break;
                case SDLK_o:
                    objetactuel = BRIQUENO;
                    break;
                case SDLK_RIGHT:
                    if ( *niveau < 4 )
                    {
                        *niveau = *niveau + 1;
                        if ( chargerNiveau( carte , *niveau ) == 0 )
                        {
                            for ( i = 0 ; i < NB_BLOCS_LARGEUR ; i++ )
                            {
                                for ( j = 0 ; j < NB_BLOCS_HAUTEUR ; j++ )
                                {
                                    carte[i][j] = VIDE;
                                }
                            }
                        }
                    }
                    
                    break;
                case SDLK_LEFT:
                    if ( *niveau - 1 > 0 )
                    {
                        *niveau = *niveau - 1;
                        if ( chargerNiveau( carte , *niveau ) == 0 )
                        {
                            for ( i = 0 ; i < NB_BLOCS_LARGEUR ; i++ )
                            {
                                for ( j = 0 ; j < NB_BLOCS_HAUTEUR ; j++ )
                                {
                                    carte[i][j] = VIDE;
                                }
                            }
                        }
                    }
                    break;
                    
                default:
                    break;
            }
                break;
                
        }
        
        SDL_FillRect(ecran , NULL , SDL_MapRGB(ecran -> format , 255 , 255 ,255 ));
        positionFond.x = 0;
        positionFond.y = 0;
        SDL_BlitSurface(fond , NULL , ecran , &positionFond);
        
        for ( i = 0 ; i < NB_BLOCS_LARGEUR ; i++ )
        {
            for ( j = 0 ; j < NB_BLOCS_HAUTEUR ; j++ )
            {
                position.x = i * TAILLE_BLOC;
                position.y = j * TAILLE_BLOC;
                
                switch( carte[i][j])
                {
                    case BARREG:
                        SDL_BlitSurface( barreG , NULL , ecran , &position );
                        break;
                    case BARREM:
                        SDL_BlitSurface( barreM , NULL , ecran , &position );
                        break;
                    case BARREM2:
                        SDL_BlitSurface( barreM2 , NULL , ecran , &position );
                        break;
                    case BARREM3:
                        SDL_BlitSurface( barreM3 , NULL , ecran , &position );
                        break;
                    case BARRED:
                        SDL_BlitSurface( barreD , NULL , ecran , &position );
                        break;
                    case BALLE:
                        SDL_BlitSurface( balle , NULL , ecran , &position );
                        break;
                    case BRIQUE:
                        SDL_BlitSurface( brique , NULL , ecran , &position );
                        break;
                    case BRIQUENO:
                        SDL_BlitSurface( briqueno , NULL , ecran , &position );
                        break;
                    case BRIQUE3COUPS:
                        SDL_BlitSurface( brique3coups , NULL , ecran , &position );
                        break;
                    default:
                        break;
                }
            }
        }
        
        SDL_Flip(ecran);
    }
    
    SDL_FreeSurface(barreD);
    SDL_FreeSurface(barreM);
    SDL_FreeSurface(barreM2);
    SDL_FreeSurface(barreM3);
    SDL_FreeSurface(briqueno);
    SDL_FreeSurface(brique1coup);
    SDL_FreeSurface(brique2coups);
    SDL_FreeSurface(brique3coups);
    SDL_FreeSurface(barreG);
    SDL_FreeSurface(balle);
    SDL_FreeSurface(brique);
    
}


