//
//  Musique.c
//  Go ball ctgv
//
//  Created by Gery THRASIBULE on 04/06/2014.
//  Copyright (c) 2014 test. All rights reserved.
//

#include "header.h"

void musique( int bruitage , int fin ) {
    
    Mix_Chunk *menu = NULL;
    Mix_Chunk *paddle = NULL;
    Mix_Chunk *brique = NULL;
    Mix_Music *music = NULL;

    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    
    menu = Mix_LoadWAV("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/menu.wav");
    music = Mix_LoadMUS("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/MusiqueJeux4.wav");
    paddle = Mix_LoadWAV("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/paddle.wav");
    brique = Mix_LoadWAV("/Users/Gery/Documents/Programmation/Go ball ctgv/Go ball ctgv/brique.wav");

        if (bruitage == 0) {
            Mix_PlayChannel( -1, menu, 0 );
        }
        if (bruitage == 1) {
            Mix_PlayChannel( -1, paddle, 0 );
        }
        if (bruitage == 2) {
            if( Mix_PlayingMusic() == 0 )
            {
//                Mix_PlayMusic( music, -1 );
            }
            
        }
        if (bruitage == 3) {
            Mix_PlayChannel( -1, brique, 0 );
        }
    
    if (fin == 1) {

        Mix_FreeMusic( music );
        Mix_FreeChunk( brique );
        Mix_FreeChunk( paddle );
        Mix_FreeChunk( menu  );
    }
}