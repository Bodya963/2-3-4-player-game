#include "view.h"

view::view()
{
    pizda = 0;
}

void view::set_model( model& model)
{
    view_model = model;
}

void view::set_window( Window * window)
{
    win = window;
}