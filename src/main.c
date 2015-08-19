//
//  main.c
//  Go Ball
//
//  Created by Gery THRASIBULE on 27/05/2014.
//  Copyright (c) 2014 CTGV. All rights reserved.
//

#include "header.h"


int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL , *ctgv = NULL , *menu = NULL , *play = NULL , *score = NULL , *shop = NULL , *credit = NULL , *fondScore = NULL , *texte = NULL , *creditImg = NULL;
    SDL_Rect positionMenu , positionPlay , positionScore , positionShop , positionCredit , positionCTGV , positionTexte;
    SDL_Event event;
    TTF_Init();
    TTF_Font *police = NULL;
    SDL_Color blanc = {223,223,223};
    char point[20];
    police = TTF_OpenFont("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/STENCIL.TTF", 65);
    int continuer = 1 , niveau = 0 , scoreActuel = 0;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    ecran = SDL_SetVideoMode( LARGEUR_FENETRE , HAUTEUR_FENETRE , 32 , SDL_HWSURFACE | SDL_DOUBLEBUF );
    SDL_WM_SetCaption("Go Ball !" , NULL );
    
    
    ctgv = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/GO_BALL.png");
    positionCTGV.x = 0;
    positionCTGV.y = 0;
    SDL_BlitSurface(ctgv , NULL , ecran , &positionCTGV);
    SDL_Flip(ecran);
    SDL_Delay(5000);
    
    
    SDL_FreeSurface(ctgv);
    
    menu = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Menu_bleu.png");
    positionMenu.x = 0;
    positionMenu.y = 0;
    play = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Play_Bleu.png");
    positionPlay.x = 10;
    positionPlay.y = 326;
    score = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Scores_Bleu.png");
    positionScore.x = 10;
    positionScore.y = 462;
    shop = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Shop_Bleu.png");
    positionShop.x = 346;
    positionShop.y = 326;
    credit = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Credits_Bleu.png");
    positionCredit.x = 346;
    positionCredit.y = 462;
    fondScore = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/fondScore.jpg");
    creditImg = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/CREDITS.png");
    
    musique(2 , 2);
    while ( continuer == 1 )
    {
            musique(2 , 1);
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_MOUSEMOTION:
                if ( ( event.motion.x > positionPlay.x && event.motion.x < 334 ) && ( event.motion.y > positionPlay.y && event.motion.y < 450 ) )
                {
                    //Apparition du Play Jaune
                    musique(0 , 0);
                    play = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Play_Jaune.png");
                }
                else
                {
                    //Reapparition du Play Bleu
                    play = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Play_Bleu.png");
                }
                
                if ( ( event.motion.x > positionShop.x && event.motion.x <  671 ) && ( event.motion.y > positionShop.y && event.motion.y < 450 ) )
                {
                    musique(0 , 0);
                    shop = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Shop_Jaune.png");
                }
                else
                {
                    shop = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Shop_Bleu.png");
                }
                
                if ( ( event.motion.x > positionScore.x && event.motion.x < 334 ) && ( event.motion.y > positionScore.y && event.motion.y < 586 ) )
                {
                    musique(0 , 0);
                    score = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Scores_Jaune.png");
                }
                else
                {
                    score = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Scores_Bleu.png");
                }
                
                if ( ( event.motion.x > positionCredit.x && event.motion.x < 671 ) && ( event.motion.y > positionCredit.y && event.motion.y < 586 ) )
                {
                    musique(0 , 0);
                    credit = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Credits_Jaune.png");
                }
                else
                {
                    credit = IMG_Load("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/Credits_Bleu.png");
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if ( ( event.button.x > positionPlay.x && event.button.x < 334 ) && ( event.button.y > positionPlay.y && event.button.y < 450 ) )
                {
                    //Lancement du jeu
                    niveau = 1;
                    jouer(ecran , &niveau , &scoreActuel );
                }
                if ( ( event.button.x > positionShop.x && event.button.x <  671 ) && ( event.button.y > positionShop.y && event.button.y < 450 ) )
                {
                    niveau = 1;
//                    editeur(ecran , &niveau );
                    system("open http://www.google.fr");
                }
                if ( ( event.button.x > positionScore.x && event.button.x < 334 ) && ( event.button.y > positionScore.y && event.button.y < 586 ) )
                {

                    sprintf( point , " votre score : %d", scoreActuel);
                    texte = TTF_RenderText_Solid(police, point, blanc );
                    positionTexte.x = 10;
                    positionTexte.y = 300;
                    SDL_BlitSurface ( fondScore , NULL , ecran , &positionMenu);
                    SDL_BlitSurface( texte , NULL , ecran , &positionTexte);
                    SDL_Flip(ecran);
                    SDL_Delay(2000);
                    SDL_FreeSurface(texte);
                    
                }
                if ( ( event.button.x > positionCredit.x && event.button.x < 671 ) && ( event.button.y > positionCredit.y && event.button.y < 586 ) )
                {
                    SDL_BlitSurface( creditImg , NULL , ecran , &positionMenu);
                    SDL_Flip(ecran);
                    SDL_Delay(5000);

                }
                break;
                
        }
        
        SDL_FillRect(ecran , NULL , SDL_MapRGB(ecran->format , 0, 0, 0));
        SDL_BlitSurface(menu , NULL , ecran , &positionMenu);
        SDL_BlitSurface(play , NULL , ecran , &positionPlay);
        SDL_BlitSurface(shop , NULL , ecran , &positionShop);
        SDL_BlitSurface(score , NULL , ecran , &positionScore);
        SDL_BlitSurface(credit , NULL , ecran , &positionCredit);
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(play);
    SDL_FreeSurface(menu);
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(credit);
    SDL_FreeSurface(shop);
    SDL_FreeSurface(score);
    SDL_FreeSurface(fondScore);
    SDL_FreeSurface(creditImg);
    musique( 4 , 1 );
    SDL_Quit();
    return 0;
}



