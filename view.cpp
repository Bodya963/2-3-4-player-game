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
    plant_texture.loadFromFile( "sprites/plant.png");
    water_texture.loadFromFile( "sprites/water.png");
    back_texture.loadFromFile( "sprites/back.png");

    grass_sprite.setTexture( grass_texture);
    plant_sprite.setTexture( plant_texture);
    water_sprite.setTexture( water_texture);
    back_sprite.setTexture( back_texture);

    back_sprite.setPosition( 0, 0);

    float xscale = (view_model->model_map->width * TAILSIZE) / 1000.0;
    float yscale = (view_model->model_map->height * TAILSIZE) / 1000.0;

    printf(" %f, %f\n", xscale, yscale);
    back_sprite.scale(xscale , yscale);
    win->draw( back_sprite);

    for( int i = 0; i < view_model->model_map->height; i++)
    {
        for( int j = 0; j < view_model->model_map->width; j++)
        {
            int tile = view_model->get_tile( i, j);

            printf("%c", tile);

            Sprite sprite;
            if( tile == 'g')
            {
                sprite = grass_sprite;
            }
            else if( tile == 'p')
            {
                sprite = plant_sprite;
            }
            else if( tile == 'w')
            {
                sprite = water_sprite;
            }

            sprite.setPosition( j * TAILSIZE, i * TAILSIZE);
            win->draw( sprite);
        }
        printf("\n");
    }
}