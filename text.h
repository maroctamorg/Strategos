#ifndef TEXT_H
#define TEXT_H

#include "global.h"

class Text
{
private:

    std::string text { "DEFAULT INITIALISATION OF TEXT OBJECT" };
    std::string font { "Krungthep.ttf" };
    int ptsize { 20 };
    SDL_Colour color { 0, 0, 0, 250 };
    SDL_Rect target_rect { 500, 500, 800, 500 };

    SDL_Texture *txtTexture;

public:
    Text() = default;
    Text(const std::string text, const std::string font, int ptsize, const SDL_Colour color, const SDL_Rect target_rect);
    void assign(const std::string text, const std::string font, int ptsize, const SDL_Colour color, const SDL_Rect target_rect);
    int generateTxtTexture();
    void displayText();
    void destroyTxtTexture();

};

#endif