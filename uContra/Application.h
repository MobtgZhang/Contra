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
    long frameTime;
    static const int MIN_FRAME_TIME = 16;
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
    static Map *oMap;
    static int mouseX,mouseY;
    static bool mouseLeftPressed,mouseRightPressed;
    //判游戏是否退出
    static bool quitGame;
    void mainloop();

};
# endif
