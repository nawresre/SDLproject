
#include <SDL/SDL.h>//inclure SDL.h pour permettre au programme d'être portable sur tous les systèmes.

#include<SDL/SDL_image.h> //Pour manipuler des images ayants des types autre que bmp

#include<SDL/SDL_mixer.h> //Pour manipuler de l’audio.

#include<SDL/SDL_ttf.h> //Pour manipuler des textes 



int main ( int argc, char** argv )

{
SDL_Surface *ecran;
SDL_Surface *image=NULL;
SDL_Surface * surfaceTexte;


 
int quitter = 1;
int play=0 ;
SDL_Rect positionimage;

SDL_Rect positiontext;
TTF_Font *font;
SDL_Color textColor;

    SDL_Surface *fond_options;
    SDL_Surface *fond_jeu;
    SDL_Surface *texte_surface;
    SDL_Surface *jouer_button;
    SDL_Surface *options_button;
    SDL_Surface *quitter_button;
    SDL_Surface *quitter_button2;
     SDL_Surface *jouer_button2;
    SDL_Surface *options_button2;
      SDL_Surface *FS_button;
    SDL_Surface *sound_button;
    SDL_Surface *son2_button;
    SDL_Surface *son1_button;
    SDL_Surface *son0_button;
    
    
    SDL_Rect position_jouer;
    SDL_Rect position_jouer2;
    SDL_Rect position_options;
    SDL_Rect position_options2;
    SDL_Rect position_quitter;
    SDL_Rect position_quitter2;
 SDL_Rect position_son1;
 
 
 
SDL_Event event;
char texte [100];
Mix_Music *musique=NULL;
Mix_VolumeMusic(100);

Mix_Chunk *son ;
     


SDL_Init( SDL_INIT_TIMER) ;
SDL_Init( SDL_INIT_AUDIO) ;
SDL_Init( SDL_INIT_VIDEO) ;


Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,1024);



if (SDL_Init(SDL_INIT_VIDEO) < 0){



printf("Echec d'initialisation de SDL : %s\n", SDL_GetError());

return 1;



}



else

printf("Bonjour le monde, SDL est initialisé avec succès.\n");

ecran = SDL_SetVideoMode(600, 430, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);

if ( ecran == NULL )

{

fprintf(stderr, "Echec de creation de la fenetre de 300*300: %s.\n", SDL_GetError());

return 1;



}


image= IMG_Load ("backg1.jpg");
fond_options = IMG_Load("backg.jpg");
    fond_jeu = IMG_Load("bgj.png");



 if (image == NULL || fond_options == NULL || fond_jeu == NULL)
    {
        fprintf(stderr, "Erreur de chargement des fonds : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
SDL_Rect dstRect = {0, 0, 960, 525};
    SDL_BlitSurface(image, NULL, ecran, &dstRect);

    // Loading buttons
    jouer_button = IMG_Load("play1.png");
    options_button = IMG_Load("option1.png");
    quitter_button = IMG_Load("leave.png");
    quitter_button2 = IMG_Load("leave2.png");
jouer_button2=IMG_Load("play2.png");
options_button2=IMG_Load("option2.png");
FS_button=IMG_Load("FS.png");
 sound_button=IMG_Load("sound.png");
    // Verification of button loading
    if (jouer_button == NULL || options_button == NULL || quitter_button == NULL)
    {
        fprintf(stderr, "Erreur de chargement des boutons : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    
    positionimage.x=0;

positionimage.y=0;




    position_jouer.x=260;
    position_jouer.y=210;
     position_jouer2.x=260;
    position_jouer2.y=210;


     position_options.x=260;
     position_options.y=270;
     position_options2.x=260;
     position_options2.y=270;
     
     position_quitter.x=260;
     position_quitter.y=330;
    


TTF_Init();
positiontext.x=200;
positiontext.y=140;
// Code RGB pour la couleur noire
textColor.r=192;
textColor.g=192;
textColor.b=192;

font = TTF_OpenFont( "arial.ttf", 30 );
surfaceTexte = TTF_RenderText_Solid(font, "Echos Of Equality ", textColor );



musique=Mix_LoadMUS("musique.mp3");
Mix_PlayMusic(musique,-1);
son = Mix_LoadWAV("son.wav");


      
while(quitter) 

{


SDL_BlitSurface(image,NULL,ecran, &positionimage);
SDL_BlitSurface(jouer_button, NULL, ecran, &position_jouer);
SDL_BlitSurface(options_button, NULL, ecran, &position_options);
SDL_BlitSurface(quitter_button, NULL, ecran, &position_quitter);
surfaceTexte = TTF_RenderText_Solid(font, "Echos Of Equality ", textColor );

SDL_BlitSurface(surfaceTexte, NULL, ecran, &positiontext);
SDL_PollEvent(&event);



switch (event.type)

     { case SDL_QUIT: quitter = 0;

    break;
    case SDL_KEYDOWN:

          switch (event.key.keysym.sym)

            {

             case SDLK_ESCAPE:

             quitter = 0;

             break;
             

            }
            
            //nekliki aal o tod5l option
            if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == 			SDLK_o))
		{
		fond_options = IMG_Load("backg.jpg");
               SDL_BlitSurface(fond_options, NULL, ecran, &positionimage);
                     break;
		}
	    //nekliki aal p tod5l play
	    if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_p)) 
		{
		SDL_BlitSurface(fond_jeu, NULL, ecran, &positionimage);
		}
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_f)) 
		
                    {SDL_WM_ToggleFullScreen(ecran);
                    
                    break;}
		
		
		//tod5l iterface play
            case SDL_MOUSEBUTTONUP:
		
		if(event.motion.x>=260 && event.motion.x<=260+122 &&event.motion.y>=210 &&event.motion.y<=210+31)
		{
               SDL_BlitSurface(fond_jeu, NULL, ecran, &positionimage);
                            
		break;
		}
		// get to option inerface
		else  if(event.motion.x>=260 && event.motion.x<=260+122 &&event.motion.y>=270 &&event.motion.y<=270+31)
		{fond_options = IMG_Load("backg.jpg");
	SDL_BlitSurface(fond_options, NULL, ecran, &positionimage);
	SDL_BlitSurface(FS_button, NULL, ecran, &position_quitter);
	SDL_BlitSurface(sound_button, NULL, ecran, &position_jouer);
                    
                     { 
                     if(event.motion.x>=260 && event.motion.x<=260+122 &&event.motion.y>=330 &&event.motion.y<=330+31)
                    SDL_WM_ToggleFullScreen(ecran);
 }
                     break;
                }
                
                if(event.motion.x>=260 && event.motion.x<=260+122 &&event.motion.y>=330 &&event.motion.y<=330+31) 
{   SDL_QUIT: quitter = 0;}

             case SDL_MOUSEMOTION: 
		if(event.motion.x>=260 && event.motion.x<=260+122 &&event.motion.y>=210 &&event.motion.y<=210+31)
		{Mix_PlayChannel(-1, son, 0);
	SDL_BlitSurface(jouer_button2, NULL, ecran, &position_jouer2); 	
	
	break;
                } 
		if(event.motion.x>=260 && event.motion.x<=260+122 &&event.motion.y>=330 &&event.motion.y<=330+31)
		{
	SDL_BlitSurface(quitter_button2, NULL, ecran, &position_quitter);
	Mix_PlayChannel(-1,son,0);
                     break;
		} 
                else  if(event.motion.x>=260 && event.motion.x<=260+122 &&event.motion.y>=270 &&event.motion.y<=270+31)
                {Mix_PlayChannel(-1,son,0);
	
	SDL_BlitSurface(options_button2, NULL, ecran, &position_options2);
		 }
break;
	}
SDL_Flip(ecran);
}

SDL_FreeSurface(image);
SDL_FreeSurface(fond_options);
    SDL_FreeSurface(fond_jeu);
    SDL_FreeSurface(jouer_button);
    SDL_FreeSurface(options_button);
     SDL_FreeSurface(options_button2);
    SDL_FreeSurface(quitter_button);
    SDL_FreeSurface(jouer_button2);

Mix_CloseAudio();
Mix_FreeMusic(musique);
Mix_FreeChunk(son);
SDL_FreeSurface (surfaceTexte);
TTF_CloseFont (font);
TTF_Quit();

SDL_Quit();

return 0;
}


