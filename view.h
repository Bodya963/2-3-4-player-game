#pragma once

#include "header.h"
#include "model.h"

class view 
{
private:
    model* view_model;
    RenderWindow* win;

    Texture grass_texture;
    Texture plant_texture;
    Texture water_texture;
    Texture back_texture;

    Sprite grass_sprite;
    Sprite plant_sprite;
    Sprite water_sprite;
    Sprite back_sprite;

    FloatRect water_box;
    FloatRect plant_box;

public:
    view();
    void set_model(model* model);
    void set_window(RenderWindow* window);
    void draw_map();

    void run();
    void draw_pl( player * pl);
    void draw();
    bool is_collision( player * pl);
};