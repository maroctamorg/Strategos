#ifndef UNIT_H
#define UNIT_H

#include "global.h"
/*
class Soldier
{
private:
    SDL_Point s_pos;

public:
    Soldier(SDL_Point pos);
    SDL_Point get_pos();

};
*/

class Unit
{
private:
    int u_troop_n { 9 };
    int u_health { 0 };
    //Soldier u_general;
    SDL_Point pIndex { 1, 1 };
    SDL_Point u_pos { 0, 0 };
    int u_move { 0 };
    std::vector<SDL_Rect> u_sold_rect { {0, 0, 0, 0} };
    SDL_Color uColor { 100, 100, 100, 250 };

    state uState { true, false };

public:

    int posUSelect { 0 };

    SDL_Rect uColRect { 0, 0, 0, 0 };

    Unit_Division u_division { EMPTY };

    Unit() = default;

    Unit(const fGrid &grid, const SDL_Color &color, const SDL_Point &pos, int health, int move, Unit_Division division);

    void updateDimensions(const fGrid &grid);

    void display();

    int get_pos(cartesian coord);
    int get_health();

    bool Clicked(const SDL_Point &cursor_pos);
    void activate();
    void deactivate();

    Unit* uSelect(int pos);
    void uDeSelect();

    bool isActive();
    bool isSelected();

    void move(move_direction direction, fGrid grid);
    void take_damage(int damage);
    int attack();
    
    //add click and select functionalities

    
    SDL_Rect* get_sold_rect(int i);
    //int attack(Unit_Division foe);
};

class Troop : public Unit
{
private:
    int tu_id { 0 };
    static int tu_count;

public:
    static const int troop_health;
    static const int troop_damage;
    static const int troop_cost;
    //adjust move to actual pixel distances
    static const int troop_move;
    static const SDL_Color troop_colour;

    Troop() = default;
    Troop(const fGrid grid, SDL_Point pos);

};

class Archer : public Unit
{
private:
    int au_id { 0 };
    static int au_count;

public:
    static const int archer_health;
    static const int archer_damage;
    static const int archer_cost;
    //adjust move to actual pixel distances
    static const int archer_move;
    static const SDL_Color archer_colour;

    Archer() = default;
    Archer(const fGrid grid, SDL_Point pos);

};

class Knight : public Unit
{
private:
    int ku_id { 0 };
    static int ku_count;

public:
    static const int knight_health;
    static const int knight_damage;
    static const int knight_cost;
    //adjust move to actual pixel distances
    static const int knight_move;
    static const SDL_Color knight_colour;

    Knight() = default;
    Knight(const fGrid grid, SDL_Point pos);

};

#endif