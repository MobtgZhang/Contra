# pragma once
# ifndef ABOUTMENU_H
# define ABOUTMENU_H

# include "Menu.h"
# include "AboutMenu.h"


class AboutMenu:public Menu{
private:
    unsigned int iTime;
public:
    AboutMenu();
    ~AboutMenu();
    void Draw(SDL_Renderer* rR);
    void enter();
    void updateTime();
};

# endif
