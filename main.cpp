#include "header.h"

// Классы --------------------

#include "view.h"
#include "model.h"
#include "controller.h"

//----------------------------


int main ()
{
    view main_view;
    model main_model;
    controller main_controller;

    RenderWindow win( VideoMode( 1000, 1000), "TANKI Z", Style::Default);

    main_view.set_model( &main_model);
    main_view.set_window( &win);

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

        win.clear();

        main_view.draw_map();

        win.display();
    }

    return 0;
}