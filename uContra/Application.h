# ifndef APPLICATION_H
# define APPLICATION_H
# include<SDL2/SDL.h>
# include "Map.h"

class Application{
private:
    SDL_Window* window;
	SDL_Renderer* rR;
	SDL_Event* mainEvent;

    // ----- FPS -----
    unsigned long lFPSTime;
    int iNumOfFPS,iFPS;
    // ----- INPUT KEYS -----
    static bool movePressed,keyMenuPressed,keyS,keyW,keyA,keyD,keyShift;
    static bool keyAPressed,keyDPressed;

    // ----- true = RIGHT, false = LEFT
    bool firstDir;

public:
    Application();
    ~Application();
public:
    Map *oMap;
    static int mouseX,mouseY;
    //判游戏是否退出
    static bool quitGame;
    void mainloop();

};
# endif
