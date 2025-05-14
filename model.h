#pragma once

#include "header.h"

class map
{
public:
    char name[NAMESIZE];
    int **tails; // Двухмерный массив
    
    int height;
    int width;
public:
    map( char *);
    ~map();

};




class model 
{
public:
    map * model_map;
public:
    model();

    int get_tile(int x, int y); // Получить тип плитки
    bool is_collidable(int x, int y); // Проверка коллизии

    void set_map( map* map1); 
};