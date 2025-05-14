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

model::model(){}

void model::set_map( map * map1)
{
    model_map = map1;
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