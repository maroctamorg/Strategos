#include "global.h"

const int W_W { 1200 };
const int W_H { 740 };

inline bool isContained(SDL_Point cursor_pos, SDL_Rect rect) {
    return (cursor_pos.x > rect.x && cursor_pos.x < (rect.x + rect.w) && cursor_pos.y > rect.y && cursor_pos.y < (rect.y + rect.h));
}

SDL_Window *window { nullptr };
SDL_Renderer *renderer { nullptr };
