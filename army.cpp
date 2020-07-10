#include "global.h"
#include "unit.h"
#include "army.h"



Army::Army(const fGrid &grid, const std::vector<SDL_Point> &tInitPos, const std::vector<SDL_Point> &aInitPos, const std::vector<SDL_Point> &kInitPos)
    : mTroop{}, mArcher{}, mKnight{}
{
    //mTroop.resize(tInitPos.size());
    //mArcher.resize(aInitPos.size());
    //mKnight.resize(kInitPos.size());

    for (int i{0}; i < tInitPos.size(); i++) {
        Troop troop { grid, tInitPos[i] };
        mTroop.push_back(troop);
    }

    for (int i{0}; i < aInitPos.size(); i++) {
        Archer archer { grid, aInitPos[i] };
        mArcher.push_back(archer);
    }

    for (int i{0}; i < kInitPos.size(); i++) {
        Knight knight { grid, kInitPos[i] };
        mKnight.push_back(knight);
    }

}

void Army::updateDimensions(const fGrid &grid)
{
    for(int i{0}; i < mTroop.size(); i++)
    {
        mTroop[i].updateDimensions(grid);
    }
}

/*Unit Army::get_unit(Unit_Division division, int div_n)
{
    switch(division)
    {
    case TROOP:
        if (div_n >= 0 && div_n < m_tn)
        {
            return m_tunits[div_n];
        } else
        {
            std::cout << "Out of bounds index for army.get_unit call\n";
            return;
        }
    case ARCHER:
        if (div_n >= 0 && div_n < m_an)
        {
            return a_units[div_n];
        } else
        {
            std::cout << "Out of bounds index for army.get_unit call.\n";
            return;
        }
    case KNIGHT:
        if (div_n >= 0 && div_n < m_kn)
        {
            return k_units[div_n];
        } else
        {
            std::cout << "Out of bounds index for army.get_unit call.\n";
            return;
        }
    default:
        std::cout << "Invalid input for army.get_unit.\n";
        return;
    }
}
*/

void Army::display()
{
    //std::cout << "Call to army.display().\n";

    for (int i{0}; i < mTroop.size(); i++)
    {
        mTroop[i].display();
    }

    for (int i{0}; i < mArcher.size(); i++)
    {
        mArcher[i].display();
    }

    for (int i{0}; i < mKnight.size(); i++)
    {
        mKnight[i].display();
    }
}


/*
void Army::move(move_direction dir, Unit_Division division, int index)
{
    switch(division)
    {
    case TROOP:
        if (index > 0 && index < mTroop.size()) {
            mTroop[index].move(dir);
        }
        break;
    case ARCHER:
        if (index > 0 && index < mArcher.size()) {
            mArcher[index].move(dir);
        }
        break;
    case KNIGHT:
        if (index > 0 && index < mKnight.size()) {
            mKnight[index].move(dir);
        }
        break;
    default:
        std::cout << "Invalid input for army.move call.\n";    
    }
}

void Army::remove(Unit_Division division, int index)
{
    switch(division)
    {
    case TROOP:
        mTroop.erase(mTroop.begin() + index);
        break;

    case ARCHER:
        mArcher.erase(mArcher.begin() + index);
        break;

    case KNIGHT:
        mKnight.erase(mKnight.begin() + index);
        break;
    default:
        std::cout << "Invalid division input for army.remove call.\n";
    }
}
*/
