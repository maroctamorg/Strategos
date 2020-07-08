#ifndef FIELD_H
#define FIELD_H

#include "global.h"

class Field
{
private:
    gRatio gridRatio;
    int xG, yG;

    bool effen;

public:
    fGrid f_grid;

    void updateDimensions();

    Field() = default;
    Field(gRatio g_ratio, bool enabled);
    ~Field() {};

    void display();
    void getUinput();

};

#endif