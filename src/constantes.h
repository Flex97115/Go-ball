//
//  constantes.h
//  Go Ball
//
//  Created by Gery THRASIBULE on 27/05/2014.
//  Copyright (c) 2014 CTGV. All rights reserved.
//

#ifndef Go_Ball_constantes_h
#define Go_Ball_constantes_h


#define TAILLE_BLOC         34
#define NB_BLOCS_LARGEUR    20
#define NB_BLOCS_HAUTEUR    20
#define LARGEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_LARGEUR
#define HAUTEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_HAUTEUR
#define VITESSEBALLE        80
#define VITESSEBARRE        50
#define DIRECGAUCHE         -1
#define DIRECDROITE          1
#define DIRECHAUT           -1
#define DIRECBAS             1
#define DIRECLINE            0
#define MAX                  30
#define MIN                  1
#define VITESSEBONUS        150
#define CASEEXPLOSION        3
#define CASEEXPLOSIONNEG    -3

enum{ DROITE , GAUCHE ,HAUT , RIEN };
enum{ VIDE , BARREG , BARREM , BARRED , BALLE , BRIQUE , BARREM2 , BARREM3 , BRIQUE3COUPS , BRIQUENO , BRIQUE2COUPS , BRIQUE1COUP , BARREM4 , BARREM5 };
enum{ AUCUN , EXPLOSIF , COLLANT , RETRECIR , GRANDIR , BALLEX2 , VITESSEPLUS , VITESSEMOINS};
enum{ INACTIF , ACTIF };

#endif
