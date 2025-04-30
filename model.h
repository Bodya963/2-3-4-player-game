#pragma once

#include "header.h"

class model 
{
    
private:
    int map[10][10]; // Карта 10x10
public:
    model();
    int get_tile(int x, int y); // Получить тип плитки
    bool is_collidable(int x, int y); // Проверка коллизии
};