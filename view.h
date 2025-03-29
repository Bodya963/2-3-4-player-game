#pragma once

#include "header.h"
#include "model.h"


class view 
{
    protected:
        model& view_model;

        Window* win;

        int pizda;

    public:

        view();

        void set_model( model&); 
        void set_window( Window*);
};

