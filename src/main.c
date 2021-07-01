#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HIGHT 600
#define Board_WIDTH 100
#define Board_HIGHT 100

#define CELL_WIDTH ((float) SCREEN_WIDTH / Board_WIDTH)
#define CELL_HIGHT ((float) SCREEN_HIGHT / Board_HIGHT)



int scc(int code){
    if(code < 0){
        fprintf(stderr, "SDL error: %s\n",SDL_GetError());
        exit(1);
    }
    return code;
}

void *scp(void *ptr){
    if(ptr == NULL){
        fprintf(stderr,"SDL error: %s\n",SDL_GetError());
        exit(1);
    }
    return ptr;
}


void render_board(SDL_Renderer *renderer){
    scc(SDL_SetRenderDrawColor(renderer, 100, 100, 100,255));
    for (int x=0;x < Board_WIDTH; ++x){
        scc(SDL_RenderDrawLine(renderer,x * CELL_WIDTH,0,x * CELL_WIDTH,SCREEN_HIGHT));
    }
    for(int y=0;y<Board_HIGHT; ++y){
        scc(SDL_RenderDrawLine(renderer,0, y * CELL_HIGHT, SCREEN_WIDTH, y * CELL_HIGHT));
    }
}


int main(int argc,char *argv[]){
    scc(SDL_Init(SDL_INIT_VIDEO));

    SDL_Window *const window = scp(SDL_CreateWindow("Hunger Games?",0,0,SCREEN_WIDTH,SCREEN_HIGHT,SDL_WINDOW_RESIZABLE));
    SDL_Renderer *const renderer = scp(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED));

    scc(SDL_RenderSetLogicalSize(renderer,SCREEN_WIDTH,SCREEN_HIGHT));

    int quit = 0;
    while (!quit){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:{
                    quit = 1;
                }break;
            }
        }
        scc(SDL_SetRenderDrawColor(renderer, 3, 7, 30,255));
        scc(SDL_RenderClear(renderer));

        render_board(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_Quit();

    return 0;
}