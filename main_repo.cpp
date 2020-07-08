#include "global.h"
#include "unit.h"
#include "army.h"

const int WINDOW_WIDTH { 1040 };
const int WINDOW_HEIGHT { 740 };

//eventually express everything in terms of this rather than window_sizes so as to be scalable
const int X_GRID { 50 };
const int Y_GRID { 35 };

int main (int argc, char *argv[])
{
    //display field grating
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    //SDL_RenderPresent(renderer);

    
    //gets generates 3 divisions for max 3 units
    //need to create SDL_Rect array afterall

    /*   
    int division_number[4] {};
    std::cout   <<  "Input number of units for each division...\n";
    std::cout   <<  "Troop: ";
    std::cin    >>  division_number[TROOP]; //handle input properly
    std::cout   <<  "\nArcher: ";
    std::cin    >>  division_number[ARCHER];
    std::cout   <<  "\nKnight: ";
    std::cin    >>  division_number[KNIGHT];

    //gets start from user; prints divisions at play
    std::cout << "Is this correct (y/n)?\n";
    std::cout << "1 : " <<  division_number[TROOP]   << '\t';
    std::cout << "2 : " <<  division_number[ARCHER]  << '\t';
    std::cout << "3 : " <<  division_number[KNIGHT]  << '\n';

    std::cout << "Then let us begin.\n";
    
    //generates units
    if (division_number[TROOP] != 0 && division_number[TROOP] <= 3)
    {
        std::array<Troop, 3>  troop_units {NULL, NULL, NULL};
        int i {0};
        while (i < *division_number)
        {
            troop_units[i] = ;
        }
        
    }

*/
/*

    //main start menu: user input
    int troop_u_number {0};
    int archer_u_number {0};
    int knight_u_number {0};

    std::array<Troop*, 5> troop_units { nullptr };
    std::array<Archer*, 5> archer_units { nullptr };
    std::array<Archer*, 5> knight_units { nullptr };

    std::cout << "Player 1, design army:\n";
    
    std::cout << "TROOP units : ";
    std::cin >> troop_u_number;
    for (int i{0}; i < troop_u_number; i++)
    {
        SDL_Point initial_pos {0,0};
        int troop_un{0};
        std::cout << "Troop 1 initial x_position (top left): ";
        std::cin >> initial_pos.x;
        std::cout << "Troop 1 initial y_position (top left): ";
        std::cin >> initial_pos.x;
        std::cout << "Number of soldiers (9, 20 or 30): ";
        std::cin >> troop_un;
        Troop troop {troop_un, initial_pos};
        troop_units.at(i) = &troop;
    }

    std::cout << "ARCHER units : ";
    std::cin >> archer_u_number;
    for (int i{0}; i < archer_u_number; i++)
    {
        SDL_Point initial_pos {0,0};
        int archer_un{0};
        std::cout << "Troop 1 initial x_position (top left): ";
        std::cin >> initial_pos.x;
        std::cout << "Troop 1 initial y_position (top left): ";
        std::cin >> initial_pos.x;
        std::cout << "Number of soldiers (9, 20 or 30): ";
        std::cin >> archer_un;
        Archer archer {archer_un, initial_pos};
        archer_units.at(i) = &archer;
    }

*/

    Troop troop_unit { 9, { 40, 40 } };
    Archer archer_unit { 9, { 120, 40 } };
    Knight knight_unit { 9, { 120, 120 } };

    //Troop troop_unit2 { 9, { WINDOW_WIDTH - 40, 40 } };
    //Archer archer_unit2 { 9, { WINDOW_WIDTH - 120, 40 } };
    //Knight knight_unit2 { 9, { WINDOW_WIDTH - 120, 120 } };

    //division Troop {&troop_unit};
    //division Troop2 {&troop_unit2};

    //army army_1{ Troop, {&archer_unit}, {&knight_unit} };
    //army army_2{ Troop2, {&archer_unit2}, {&knight_unit2} };


    //if(start): gameloop
    std::cout << "\n\n\n";
    std::cout << "Insert 0 at any point to quit...\n\n";
    
    bool done { false };
    const char move_cmd[] {"1 : FORTH\t2 : BACK\t3 : UP\t4 : DOWN\n"};
    int division {0};
    int mv_cmd {0};
    while(!done)
    {
        //display setup
        SDL_SetRenderDrawColor(renderer, 116, 116, 117, 250);
        SDL_RenderClear(renderer);
        //top left corner
        SDL_SetRenderDrawColor(renderer, 30, 30, 20, 250);
        for (int i { 20 }; i <= WINDOW_WIDTH - 20; i += 20)
        {
            SDL_RenderDrawLine(renderer, i, 20, i, WINDOW_HEIGHT - 20);
        }
        for (int i { 20 }; i <= WINDOW_HEIGHT - 20; i += 20)
        {
            SDL_RenderDrawLine(renderer, 20, i, WINDOW_WIDTH - 20, i);
        }

        SDL_SetRenderDrawColor(renderer, 173, 14, 9, 250);
        for (int i {0}; i < 9; i++) {   SDL_RenderFillRect(renderer, troop_unit.get_sold_rect(i));  }

        SDL_SetRenderDrawColor(renderer, 23, 130, 4, 250);
        for (int i {0}; i < 9; i++){    SDL_RenderFillRect(renderer, archer_unit.get_sold_rect(i)); }

        SDL_SetRenderDrawColor(renderer, 2, 17, 125, 250);
        for (int i {0}; i < 9; i++){    SDL_RenderFillRect(renderer, knight_unit.get_sold_rect(i)); }

        SDL_RenderPresent(renderer);

        //user input: select division + move command
        std::cout << "\t\t\tSELECT DIVISION\n1 : TROOP\t2 : ARCHER\t3 : KNIGHT\n";
        std::cin >> division;
        std::cout << mv_cmd << '\n';
        if (division == 0) { done = true; break; };

        std::cout << "\t\t\tMOVE COMMANDS\n" << move_cmd;
        std::cin >> mv_cmd;
        std::cout << mv_cmd << '\n';
        if (mv_cmd == 0) { done = true; break; };

        //update renderer

        switch(division)
        {
        case TROOP:
            troop_unit.move(static_cast<move_direction>(mv_cmd));
            break;
        case ARCHER:
            archer_unit.move(static_cast<move_direction>(mv_cmd));
            break;
        case KNIGHT:
            knight_unit.move(static_cast<move_direction>(mv_cmd));
            break;
        default:
            std::cout << "Invalid input for move command. Try again.\n";

        }

    }


    SDL_Event event;
    bool exit {false};
    while (!exit)
    {
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            exit = true;
            break;
        }

    }

    //SDL_Delay(10000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

    

//setup
    //display main menu
    //get user choice of field
    //get user1 choice of army
        //unit: division, n_troops
        //max number units: 9
        //max number troops/unit: 9
    //get user2 choice of army
    //get user1 army disposition
    //get user2 army disposition
//game dynamics
    //handle turn based input
        //handle move divisions
        //handle attacks (rectangle collision?)
    //handle health updates and deaths
//outcome
    //handle point allocation
    //in online: point currencies and troop costs
}