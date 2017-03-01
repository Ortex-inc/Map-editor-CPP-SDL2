#ifndef SOUND_H
#define SOUND_H
#include <SDL2/SDL_mixer.h>
#include <iostream>
//decalre
Mix_Music *music = NULL;
Mix_Chunk *fx = NULL;


void soundTrack(const char* src){
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
//Initialisation de l'API Mixer

   {

      std::cout<<Mix_GetError()<<std::endl;

   }
	   music = Mix_LoadMUS(src);
	   Mix_PlayMusic( music, -1 );

	 }

void effect(const char* src){
fx= Mix_LoadWAV( src );
if(Mix_PlayChannel( -1, fx, 0 )){
 std::cout<<Mix_GetError()<<std::endl;
//  Mix_FreeChunk( fx );
 
};

}
#endif
