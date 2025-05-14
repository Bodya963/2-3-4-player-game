#include "model.h"

map::map( char * name_file)
{
    strcpy( name, name_file);

    FILE * fd = fopen( name_file, "r");

    if( fd == NULL)
    {
        printf(" map: fopen cant open file\n");
        exit(1);
    }

    fscanf( fd, "%d %d\n", &height, &width);

    if( (height * TAILSIZE) > MAXHEIGHT or ( width * TAILSIZE) > MAXHWIDTH or height < 0 or width < 0)
    {
        printf( " map: ERROR size window in map file\n");
        exit(1);
    }
    
    tails = new int*[height]{};
    for( int i = 0; i < height; i++)
    {
        tails[i] = new int[width]{};
    }

    for( int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tails[i][j] = fgetc( fd);
        }
        
        fgetc(fd);
    }

    for( int i = 0 ; i < height; i++)
    {
        for ( int j = 0; j < width; j++)
        {
            printf("%c", tails[i][j]);
        }
        printf("\n");
    }

}

map::~map()
{
    for( int i = 0; i < height; i++)
    {
        delete[] tails[i];
    }

    delete[] tails;
}


player::player( char * name_file, Vector2f start_p, Keyboard::Key bt)
{
    strcpy( name, name_file);

    grad = 2;
    flag_rot = 0;

    buttom = bt;

    tank_texture.loadFromFile( name_file);

    tank_sprite.setTexture( tank_texture);

    tank_sprite.setOrigin( TAILSIZE/2 , TAILSIZE/2 + 5);
    tank_sprite.setPosition( start_p);

    start_pos = start_p;
}

model::model()
{
    finish = 0;
}

void model::set_map( map * map1)
{
    model_map = map1;
}

void model::set_player( player * pl)
{
    players.push_back( pl);
}

int model::get_tile( int x, int y)
{
    if( x >= 0 && x < model_map->height && y >= 0 && y < model_map->width)
    {
        return model_map->tails[x][y];
    }
    return -1;
}

bool model::is_collidable( int x, int y)
{
    int tile = get_tile( x, y);
    return tile == 1;
}