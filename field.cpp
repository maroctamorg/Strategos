#include "field.h"

auto genFgrid{
        [](gRatio g_ratio) {
            fGrid grid {};

            int a {0};
            int w {0};
            int b {0};

            int wW, wH;
            SDL_GetWindowSize(window, &wW, &wH);

            switch (g_ratio)
            {
                case REGULAR:
                    grid.xG = 50;
                    grid.yG = 35;
                    
                    a = (4*wH/5)%grid.yG;
                    grid.h = 4*wH/5 - a;
                    
                    w = grid.xG*(4*wH/5)/grid.yG;
                    grid.w = grid.xG*grid.h/grid.yG;
                    
                    b = grid.w - w;
                    grid.dz = grid.h/grid.yG;

                    grid.x0 = wW/4 + b/2;
                    grid.y0 = wH/10 + a/2;

                    break;
                
                case WIDE:

                case TALL:

                case DOUBLE: 

                case UNDEFINED:
                    std::cout << "Invalid (undefined) grid ratio passed into genFgrid in field.cpp\n";
                    break;
            }

            return grid;
        }
    };

Field::Field(gRatio g_ratio, bool enabled)
    :   gridRatio { g_ratio }, f_grid { genFgrid(g_ratio) }, effen { enabled } 
{

    std::cout << "Call to Field constructor.\n";

    std::cout << "fgrid.xG: " << f_grid.xG << '\n';
    std::cout << "fgrid.yG: " << f_grid.yG << '\n';
    std::cout << "fgrid.w: " << f_grid.w << '\n';
    std::cout << "fgrid.h: " << f_grid.h << '\n';

}

void Field::updateDimensions()
{
    int x, y, w, h;
    SDL_GetWindowSize(window, &w, &h);
    SDL_GetWindowPosition(window, &x, &y);

    f_grid = genFgrid(gridRatio);
    
}

void Field::display()
{
    std::cout << "Field display called.\n";
    //top left corner
    SDL_Rect target_rect { f_grid.x0, f_grid.y0, f_grid.w, f_grid.h };
    SDL_SetRenderDrawColor(renderer, 128, 94, 0, 250);
    SDL_RenderFillRect(renderer, &target_rect);


    SDL_SetRenderDrawColor(renderer, 102, 75, 0, 250);
    for (int i { target_rect.x }; i <= target_rect.x + target_rect.w; i += f_grid.dz)
    {
        SDL_RenderDrawLine(renderer, i, target_rect.y, i, target_rect.y + target_rect.h);
    }
    for (int i { target_rect.y }; i <= target_rect.y + target_rect.h; i += f_grid.dz)
    {
        SDL_RenderDrawLine(renderer, target_rect.x, i, target_rect.x + target_rect.w, i);
    }

    SDL_Rect lCorner { f_grid.x0, f_grid.y0, f_grid.dz, f_grid.h };
    SDL_Rect rCorner { f_grid.x0 + f_grid.w - f_grid.dz, f_grid.y0, f_grid.dz, f_grid.h };

    SDL_Rect uCorner { f_grid.x0, f_grid.y0, f_grid.w, f_grid.dz };
    SDL_Rect dCorner { f_grid.x0, f_grid.y0 + f_grid.h - f_grid.dz, f_grid.w, f_grid.dz };

    SDL_SetRenderDrawColor(renderer, 77, 56, 0, 250);
    
    SDL_RenderFillRect(renderer, &lCorner);
    SDL_RenderFillRect(renderer, &rCorner);
    SDL_RenderFillRect(renderer, &uCorner);
    SDL_RenderFillRect(renderer, &dCorner);
}