#include "text.h"

Text::Text(const std::string text, const std::string font, int ptsize, const SDL_Colour color, const SDL_Rect target_rect)
{
    this->text = text;
    this->font = font;
    this->ptsize = ptsize;
    this->color = color;
    this->target_rect = target_rect;

    int control = this->generateTxtTexture();
    std::cout << "Returned from generateTxtTexture with flag " << control << '\n';
}

void Text::assign(const std::string text, const std::string font, int ptsize, const SDL_Colour color, const SDL_Rect target_rect)
{
    std::cout << "Call to text.assign().\n";
    this->text = text;
    this->font = font;
    this->ptsize = ptsize;
    this->color = color;
    this->target_rect = target_rect;

    int control = this->generateTxtTexture();
    std::cout << "Returned from generateTxtTexture with flag " << control << '\n';

}

int Text::generateTxtTexture()
{
    if(txtTexture)
    {
        SDL_DestroyTexture(txtTexture);
        txtTexture = nullptr;
    }

    std::cout << "Call to generateTxtTexture.\n";
    TTF_Font *txt_font { TTF_OpenFont(font.c_str(), ptsize) };
    if (!txt_font) {
        std::cout << "Unable to load font.\n";
        txtTexture = nullptr;
    } else {
        SDL_Surface *surface { TTF_RenderText_Blended(txt_font, text.c_str(), color) };
        txtTexture = SDL_CreateTextureFromSurface(renderer, surface);

        TTF_CloseFont(txt_font);
        SDL_FreeSurface(surface);
    }

    if(txtTexture) { return 1; }
    else { return 0; }
}

void Text::displayText()
{
    if (txtTexture)
        {
            int texW = 0;
            int texH = 0;
            SDL_QueryTexture(txtTexture, NULL, NULL, &texW, &texH);
            SDL_Rect dstrect = { target_rect.x, target_rect.y, texW, texH };


            SDL_RenderCopy(renderer, txtTexture, NULL, &dstrect);
        } else { std::cout << "Text texture noninitialised: " << text << '\n'; }
}

void Text::destroyTxtTexture()
{
    if(txtTexture)
    {
        SDL_DestroyTexture(txtTexture);
        txtTexture = nullptr;
    }
}