#include "view.h"

view::view()
{
    grass_texture.loadFromFile( "sprites/grass.png");
    plant_texture.loadFromFile( "sprites/plant.png");
    water_texture.loadFromFile( "sprites/water.png");
    back_texture.loadFromFile( "sprites/back.png");

    grass_sprite.setTexture( grass_texture);
    plant_sprite.setTexture( plant_texture);
    water_sprite.setTexture( water_texture);
    back_sprite.setTexture( back_texture);

    water_box = water_sprite.getGlobalBounds();
    plant_box = plant_sprite.getGlobalBounds();
}

void view::run()
{
    
    while( win->isOpen())
    {
        Event event;
        
        while( win->pollEvent( event) or !view_model->finish)
        {

            win->clear();
            
            if( event.type == Event::Closed)
            {
                win->close();
                return;
            }
            

            for( auto& pl : view_model->players)
            {
                // if( is_collision( pl))
                // {
                //     break;
                // }

                pl->rot = pl->tank_sprite.getRotation();
                
                if( Keyboard::isKeyPressed( pl->buttom))
                {
                    pl->tank_sprite.move(1.5 * cos( PI * (pl->rot - 90) / 180), 1.5 * sin( PI * (pl->rot - 90) / 180) );
                    
                    pl->flag_rot = 1;
                }
                else
                {
                    if( pl->flag_rot == 1)
                    {
                        pl->grad = 0 - pl->grad;
                        pl->flag_rot = 0;
                    }

                    pl->tank_sprite.rotate( pl->grad);
                }
            }

            
            draw_map();
            
            draw();

            win->display();

        }    
 
        
    }
    
}

bool view::is_collision( player * pl)
{
    FloatRect tank_box = pl->tank_sprite.getGlobalBounds();

    if( tank_box.intersects( water_box))
    {
        printf("gg\n");
        return true;
    }

    return false;
}

void view::draw()
{
    for( auto& pl : view_model->players)
    {
        draw_pl( pl);
    }
}

void view::draw_pl( player * pl)
{
    win->draw( pl->tank_sprite);
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

    
    back_sprite.setPosition( 0, 0);

    float xscale = (view_model->model_map->width * TAILSIZE) / 1000.0;
    float yscale = (view_model->model_map->height * TAILSIZE) / 1000.0;

    back_sprite.setScale(xscale , yscale);

    win->draw( back_sprite);

    for( int i = 0; i < view_model->model_map->height; i++)
    {
        for( int j = 0; j < view_model->model_map->width; j++)
        {
            int tile = view_model->get_tile( i, j);

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
    }
}


