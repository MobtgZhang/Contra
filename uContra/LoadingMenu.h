# pragma once

# ifndef LOADINGMENU_HEADERS
# define LOADINGMENU_HEADERS
# include "Menu.h"

class LoadingMenu:public Menu{
private:
    unsigned int iTime;
public:
    LoadingMenu();
    ~LoadingMenu();

    void Update();
    void Draw(SDL_Renderer* rR);

    void updateTime();

    bool loadingType; // -- true = LOADING, false = GAME OVER
    
};

# endif
