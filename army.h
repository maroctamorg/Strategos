#include "global.h"
#include "unit.h"


class Army
{
private:

protected: 


    //substitute below and above for:
    std::vector<Troop> mTroop{};
    std::vector<Archer> mArcher{};
    std::vector<Knight> mKnight{};
    
    //figure out how to handle army construction and review troop/archer/knight/mage units implementation
        //use std::vector for each division -> std::vector.resize()

public:

    Army() = default;

    Army(const fGrid &grid, const std::vector<SDL_Point> &tInitPos, const std::vector<SDL_Point> &aInitPos, const std::vector<SDL_Point> &kInitPos);

    void updateDimensions(const fGrid &grid);

    void display();

    void move(move_direction dir, Unit_Division division, int index);

    void remove(Unit_Division division, int index);
};
