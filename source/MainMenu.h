# pragma once
# ifndef MAINMENU_H
# define MAINMENU_H

# include"CImg.h"
# include"Menu.h"

class MainMenu:public Menu{
private:
    bool selectLevel;
    int activeLevel;
    SDL_Rect rSelectLevel;
    
public:
    MainMenu();
    ~MainMenu();
    void Draw(SDL_Renderer* rR);
};

# endif
