//
//  prototype.h
//  Go Ball
//
//  Created by Gery THRASIBULE on 27/05/2014.
//  Copyright (c) 2014 CTGV. All rights reserved.
//

#ifndef Go_Ball_prototype_h
#define Go_Ball_prototype_h

void jouer ( SDL_Surface *ecran , int *niveau , int *scoreActuel );
void deplacerBalle( int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] , SDL_Rect *posB , SDL_Rect *posM  , int direction , int *bougerX , int *bougerY , int *xavant , int *yavant , int *bonus , int *caseBonusx , int *caseBonusy , int *bonusActif , int *start , int *vie , int *scoreActuel );
void casseur ( int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] , int valeurx , int valeury , int *bonus , int *caseBonusx , int *caseBonusy , int *bonusActif , int *scoreActuel);
void deplacerBarre( int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] , SDL_Rect *posG , SDL_Rect *posM , SDL_Rect *posM2 , SDL_Rect *posM3 , SDL_Rect *posD , SDL_Rect *posM4 , SDL_Rect *posM5 , int direction , int *bougerBalle , int *bonus , int *bonusActif );
void editeur(SDL_Surface *ecran , int *niveau );
void changerniveau( SDL_Surface *ecran , int niveau );
void jeux( SDL_Surface *ecran , int *jouer , int *niveau , SDL_Surface *balle , SDL_Surface *brique , SDL_Surface *barreD , SDL_Surface *barreM , SDL_Surface *barreG , SDL_Surface *victoire , SDL_Surface *barreM2 , SDL_Surface *barreM3 , SDL_Surface *brique3coups , SDL_Surface *brique2coups , SDL_Surface *brique1coup , SDL_Surface *briqueno , int *vitesseDeBalle , int *vie , int *scoreActuel);
void gestionBonus( int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] , int valeurx , int valeury , int *bonus , int *caseBonusx , int *caseBonusy );
void deplacerBonus ( int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] , SDL_Rect *posBonus , int *positionDonne , int *bonusActif , int *bonus );
void SDL_Delay(Uint32 ms);
Uint32 vitesseballe(Uint32 intervalle, void *parametre);
Uint32 SDL_GetTicks(void);
void musique( int bruitage , int fin);
void viePerdu ( int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] , int *start , SDL_Rect *posB , SDL_Rect *posM , int *xavant , int *yavant , int *vie , int *scoreActuel );

#endif
