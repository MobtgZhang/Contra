# pragma once
# ifndef ABOUTMENU_HEADERS
# define ABOUTMENU_HEADERS
# include <SDL2/SDL.h>
# include "Menu.h"

class AboutMenu: public Menu{
private:
    unsigned int iTime;
public:
    AboutMenu();
    ~AboutMenu();
    void Update();
    void Draw(SDL_Renderer* rR);
    void enter();
    void updateTime();
};

# endif
