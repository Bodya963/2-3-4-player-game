#include "view.h"

view::view()
{
}

void view::set_model( model* model)
{
    view_model = model;
}

void view::set_window( RenderWindow* window)
{
    win = window;
}

void view::draw_map()
{
    if( !win || !view_model) return;

    grass_texture.loadFromFile( "sprites/grass.png");
    wall_texture.loadFromFile( "sprites/wall.png");
    water_texture.loadFromFile( "sprites/water.png");
    back_texture.loadFromFile( "sprites/back.png");

    grass_sprite.setTexture( grass_texture);
    wall_sprite.setTexture( wall_texture);
    water_sprite.setTexture( water_texture);
    back_sprite.setTexture( back_texture);

    back_sprite.setPosition( 0, 0);
    win->draw( back_sprite);

    const int tile_size = 100;

    for( int i = 0; i < 10; ++i)
    {
        for( int j = 0; j < 10; ++j)
        {
            int tile = view_model->get_tile( i, j);

            Sprite sprite;
            if( tile == 0)
            {
                sprite = grass_sprite;
            }
            else if( tile == 1)
            {
                sprite = wall_sprite;
            }
            else if( tile == 2)
            {
                sprite = water_sprite;
            }

            sprite.setPosition( i * tile_size, j * tile_size);
            win->draw( sprite);
        }
    }
}