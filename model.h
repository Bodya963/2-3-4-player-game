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

class player
{
public:
    char name[NAMESIZE];

    Texture tank_texture;
    Sprite tank_sprite;

    Vector2f start_pos;

    Keyboard::Key buttom;

    float rot;
public:
    player( char * name_file, Vector2f start_p, Keyboard::Key bt);

};


class model 
{
public:
    map * model_map;
    std::list<player*> players;

    bool finish;
public:
    model();

    int get_tile(int x, int y); // Получить тип плитки
    bool is_collidable(int x, int y); // Проверка коллизии

    void set_map( map* map1); 
    void set_player( player * pl);
};