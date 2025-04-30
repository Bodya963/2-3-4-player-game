#include "model.h"

model::model()
{
    int initial_map[ 10][ 10] =
    {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 2, 2, 2, 0, 0, 0},
        { 0, 0, 0, 0, 2, 2, 2, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    for( int i = 0; i < 10; ++i)
    {
        for( int j = 0; j < 10; ++j)
        {
            map[ i][ j] = initial_map[ i][ j];
        }
    }
}

int model::get_tile( int x, int y)
{
    if( x >= 0 && x < 10 && y >= 0 && y < 10)
    {
        return map[ x][ y];
    }
    return -1;
}

bool model::is_collidable( int x, int y)
{
    int tile = get_tile( x, y);
    return tile == 1;
}