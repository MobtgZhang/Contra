# pragma once
# ifndef ABOUTMENU_HEADERS
# define ABOUTMENU_HEADERS
# include <SDL2/SDL.h>
# include "Menu.h"

class AboutMenu: public Menu{
private:
    unsigned int iTime;
    int cR, cG, cB, nR, nG, nB;
public:
    AboutMenu();
    ~AboutMenu();
    void Update();
    void Draw(SDL_Renderer* rR);
    void enter();
    void updateTime();
    void setBackgroundColor(SDL_Renderer* rR);
};

# endif
