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

    if( argc != 2)
    {
        printf( "Not such map: less or more args\n");
        exit(1);
    }

    map main_map( argv[1]);

    main_model.set_map( &main_map);

    RenderWindow win( VideoMode( main_map.width * TAILSIZE, main_map.height * TAILSIZE), "TANKI Z", Style::Default);

    main_view.set_model( &main_model);
    main_view.set_window( &win);
    
    win.clear();

    main_view.draw_map();

    while( win.isOpen())
    {
        Event event;

        while( win.pollEvent( event))
        {
            if( event.type == Event::Closed)
            {
                win.close();
            }
        }    
        
        win.display();
    }
    
    return 0;
}