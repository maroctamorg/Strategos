#ifndef GLOBAL_H
#define GLOBAL_H

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <array>
#include <vector>
#include <initializer_list>
#include <cassert>


enum GAME_STATE
{
    NOINPUT,
    UPDATE,
    TERMINATE,
    ANIMATION,
};

enum Player
{
    ZERO,
    P1,
    P2,
};

enum move_direction
{
    NONTOWARD,
    FORTH,
    BACK,
    UP,
    DOWN,
    UP_FORTH,
    DOWN_FORTH,
    UP_BACK,
    DOWN_BACK,
};

enum cartesian
{
    NONE,
    X,
    Y,
};

enum Unit_Division
{
    EMPTY,
    TROOP, 
    ARCHER,
    KNIGHT,
};

enum Army_enum
{
    NOTHING,
    ARMY1,
    ARMY2,
};


typedef struct
{
    Uint8 r, g, b, a;
    
} Colour;

typedef struct
{
    bool active, pressed;
} state;

extern const int W_W;
extern const int W_H;

enum gRatio {
    UNDEFINED,
    REGULAR,
    WIDE,
    TALL,
    DOUBLE,
};

typedef struct{
    int x0, y0;
    int xG, yG, w, h, dz;
} fGrid;

inline bool isContained(SDL_Point cursor_pos, SDL_Rect rect) {
    return (cursor_pos.x > rect.x && cursor_pos.x < (rect.x + rect.w) && cursor_pos.y > rect.y && cursor_pos.y < (rect.y + rect.h));
}

extern SDL_Window *window;
extern SDL_Renderer *renderer;



#endif
