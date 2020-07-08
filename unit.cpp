#include "global.h"
#include "unit.h"

int Troop::tu_count {0};
int Archer::au_count {0};
int Knight::ku_count {0};

const int Troop::troop_health  {6};
const int Troop::troop_damage  {2};
const int Troop::troop_cost    {4};
const int Troop::troop_move    {3};
const SDL_Colour Troop::troop_colour { 173, 14, 9, 250 };

const int Archer::archer_health {3};
const int Archer::archer_damage {1};
const int Archer::archer_cost   {2};
const int Archer::archer_move   {2};
const SDL_Colour Archer::archer_colour { 23, 130, 4, 250 };

const int Knight::knight_health {9};
const int Knight::knight_damage {3};
const int Knight::knight_cost   {6};
const int Knight::knight_move   {5};
const SDL_Colour Knight::knight_colour { 2, 17, 125, 250 };

auto getPos{
    [](const fGrid &grid, const SDL_Point &index) {
        SDL_Point point { 0, 0 };
        if (index.x > 0 && index.y > 0){
            point.x = grid.x0 + (index.x + 0.25)*grid.dz;
            point.y = grid.y0 + (index.y + 0.25)*grid.dz;
        } else if (index.x < 0 && index.y > 0) {
            point.x = grid.x0 + grid.w + (index.x - 2.75)*grid.dz;
            point.y = grid.y0 + (index.y + 0.25)*grid.dz;
        } else if (index.x > 0 && index.y < 0) {
            point.x = grid.x0 + (index.x + 0.25)*grid.dz;
            point.y = grid.y0 + grid.h + (index.y - 2.75)*grid.dz;
        } else if (index.x < 0 && index.y < 0) {
            point.x = grid.x0 + grid.w + (index.x - 2.75)*grid.dz;
            point.y = grid.y0 + grid.h + (index.y - 2.75)*grid.dz;
        }
        
        return point;
    }
};

//Soldier::Soldier(SDL_Point pos) : s_pos { pos } {}
//SDL_Point Soldier::get_pos () { return s_pos; }

Unit::Unit(const fGrid &grid, const SDL_Color &color, const SDL_Point &posIndex, int health, int move, Unit_Division division)
    : uColor { color }, pIndex { posIndex }, u_pos { getPos(grid, posIndex) }, u_health { health }, u_move { move }, u_division { division }, uColRect { u_pos.x, u_pos.y, 3*grid.dz, 3*grid.dz } 
{
    //int troop_n will be 9 for test: predefined numbers for later?

    std::cout << "position parameters:\tx = " << u_pos.x << "\ty = " << u_pos.y << '\n';
    
    //u_sold_rect.resize(9);
    for (int i {0}; i < 3; i++)
    {
        for (int j {0}; j < 3; j++)
        {
            //general should take variable window size in consideration
            if (i + j == 0)
            {
                u_sold_rect[0] = {static_cast<int>(u_pos.x), static_cast<int>(u_pos.y), grid.dz/2, grid.dz/2 };
            } else
            {
                u_sold_rect.push_back({ u_pos.x + j*grid.dz, u_pos.y + i*grid.dz, grid.dz/2, grid.dz/2 });    
            }
        }
    }

    //initialise col_rect
}

void Unit::updateDimensions(const fGrid &grid)
{
    u_pos = getPos(grid, pIndex);

    for (int i {0}; i < 3; i++)
    {
        for (int j {0}; j < 3; j++)
        {
            //general should take variable window size in consideration
            if (i + j == 0)
            {
                u_sold_rect[0] = {static_cast<int>(u_pos.x), static_cast<int>(u_pos.y), grid.dz/2, grid.dz/2 };
            } else
            {
                u_sold_rect[i+j] = { u_pos.x + j*grid.dz, u_pos.y + i*grid.dz, grid.dz/2, grid.dz/2 };    
            }
        }
    }

    //update col_rect
}

void Unit::display()
{
    std::cout << "Call to unit.display().\n";
    SDL_SetRenderDrawColor(renderer, uColor.r, uColor.g, uColor.b, uColor.a);
        for (int i {0}; i < 9; i++) {   SDL_RenderFillRect(renderer, &u_sold_rect[i]);  }

    if(isSelected()) {
        SDL_SetRenderDrawColor(renderer, 250, 0, 0, 250);
        SDL_RenderDrawRect(renderer, &uColRect);
    }
    
}

int Unit::get_pos(cartesian coord)
{
    switch (coord)
    {
    case X:
        return u_pos.x;
        break;
    case Y:
        return u_pos.y;
        break;
    default:
        std::cout << "ERROR: UNDEFINED COORDINATE FOR POSITION REQUEST. TERMINATING...\n";
        //HANDLE ERROR
        break;
    }
    
}

int Unit::get_health(){ return u_health; }

bool Unit::Clicked(const SDL_Point &cursor_pos)
{
    std::cout << "Call to Unit.uSelect.\n";
    bool control { false };

    //YET TO BE IMPLEMENTED
    if (isContained(cursor_pos, uColRect))
    {
        control = true;
    }

    return control;
}

void Unit::activate()     {   uState.active  =   true;   }
Unit* Unit::uSelect() {
    uState.pressed =   true;
    return this;
}
void Unit::deactivate()   {   uState.active  =   false;  }


bool Unit::isActive()     {   return uState.active;  }
bool Unit::isSelected()    {   return uState.pressed; }



void Unit::move(move_direction direction, fGrid grid)
{
    SDL_Point move{0, 0};

    switch (direction)
    {
    case FORTH:
        move.x = u_move*grid.dz;
        break;
    case BACK:
        move.x = -u_move*grid.dz;
        break;
    case UP:
        move.y = -u_move*grid.dz;
        break;
    case DOWN:
        move.y = u_move*grid.dz;
        break;
    default:
        std::cout << "ERROR: UNDEFINED DIRECTION FOR MOVE COMMAND. TERMINATING...\n";
        //HANDLE ERROR
        break;
    }
    

    uColRect.x += move.x;
    uColRect.y += move.y;
    for (int i{0}; i < u_sold_rect.size(); i++) {
        u_sold_rect[i].x += move.x;
        u_sold_rect[i].y += move.y;
    }
    
}



void Unit::take_damage(int damage) { this->u_health -= damage; }

int Unit::attack()
{
    int damage {0};
    switch (this->u_division)
    {
    case TROOP:    
        damage = Troop::troop_damage;
        break;
    case ARCHER:
        damage = Archer::archer_damage;
        break;
    case KNIGHT:
        damage = Knight::knight_damage;
        break;
    default:
        std::cout << "ERROR: UNDEFINED SUBJECT FOR ATTACK COMMAND. CORRUPTED CLASS. TERMINATING...\n";
        //HANDLE ERROR
        break;
    }
    return damage;
}


SDL_Rect* Unit::get_sold_rect(int i)
{
    std::cout << &(u_sold_rect[i]) << '\n';
    return &(u_sold_rect[i]);}


Troop::Troop(const fGrid grid, SDL_Point pos) : Unit(grid, Troop::troop_colour, pos, Troop::troop_health, Troop::troop_move, TROOP)
{
    tu_count++;
    tu_id = tu_count;
}

Archer::Archer(const fGrid grid, SDL_Point pos) : Unit(grid, Archer::archer_colour, pos, Archer::archer_health, Archer::archer_move, ARCHER)
{
    au_count++;
    au_id = au_count;
}

Knight::Knight(const fGrid grid, SDL_Point pos) : Unit(grid, Knight::knight_colour, pos, Knight::knight_health, Knight::knight_move, KNIGHT)
{
    ku_count++;
    ku_id = ku_count;
}