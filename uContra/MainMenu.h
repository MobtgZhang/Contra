# ifndef MAINMENU_HEADERS
# define MAINMENU_HEADERS

# include<SDL2/SDL.h>
# include"Menu.h"

class MainMenu:public Menu{
private:
    bool selectStage;
    int activeStageID;

    SDL_Rect rSelectStage;
public:
    MainMenu();
    ~MainMenu();

    void Update();
    void Draw(SDL_Renderer* rR);
    void enter();
    void escape();

    void updateActiveButton(int iDir);
};
# endif
