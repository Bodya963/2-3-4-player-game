#include "header.h"

// Классы --------------------

#include "view.h"
#include "model.h"
#include "controller.h"

//----------------------------


int main (int argc, char** argv)
{
    view main_view;
    model main_model;
    controller main_controller;
    
    main_view.set_model( &main_model);
    
    if( argc != 2)
    {
        printf( "Not such map: less or more args\n");
        exit(1);
    }
    
    map main_map( argv[1]);
    
    main_model.set_map( &main_map);
    
    RenderWindow win( VideoMode( main_map.width * TAILSIZE, main_map.height * TAILSIZE), "TANKI Z", Style::Default);

    main_view.set_window( &win);

    Vector2f start_pos(150.0, 150.0);
    Vector2f start_pos1(500.0, 500.0);
    player pl_1("sprites/blue_tank.PNG", start_pos, Keyboard::Key::F );
    player pl_2("sprites/gold_tank.PNG", start_pos1, Keyboard::Key::J );

    main_model.set_player( &pl_1);
    main_model.set_player( &pl_2);
    
    win.clear();

    main_view.draw_map();

    main_view.run();
    
    return 0;
}