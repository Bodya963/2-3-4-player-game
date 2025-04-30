#pragma once

#include "header.h"
#include "model.h"

class view 
{
private:
    model* view_model;
    RenderWindow* win;

    Texture grass_texture;
    Texture wall_texture;
    Texture water_texture;
    Texture back_texture;

    Sprite grass_sprite;
    Sprite wall_sprite;
    Sprite water_sprite;
    Sprite back_sprite;

public:
    view();
    void set_model(model* model);
    void set_window(RenderWindow* window);
    void draw_map();
};