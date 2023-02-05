# pragma once
# ifndef OPTIONSMENU_H
# define OPTIONSMENU_H

# include "Menu.h"

class OptionsMenu:public Menu{
private:
    SDL_Rect rRect;
    SDL_Rect rVolumeBG;
    SDL_Rect rVolume;
    
public:
    OptionsMenu();
    ~OptionsMenu();
};
# endif
