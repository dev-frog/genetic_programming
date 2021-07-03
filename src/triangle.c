#include "./triangle.h"
#include <SDL2/SDL.h>

void swap_ints(int *x,int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

Triangle triangle_sorted_by_y(Triangle t){
    if(t.y1 > t.y2) { 
        swap_ints(&t.x1, &t.x2);
        swap_ints(&t.y1, &t.y2);
    }
    if(t.y2 > t.y3) { 
        swap_ints(&t.x2, &t.x3);
        swap_ints(&t.y2, &t.y3);
    }
    if(t.y1 > t.y2) { 
        swap_ints(&t.x1, &t.x2);
        swap_ints(&t.y1, &t.y2);
    }
    return t;
}


void fill_triangle(SDL_Renderer *render,Triangle t){
    t  = triangle_sorted_by_y(t);
}