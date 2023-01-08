# ifndef DEBUG_H
# define DEBUG_H
# include<stdio.h>
# include<SDL.h>
class Debug{
public:
    Debug();
    ~Debug();
    int GameError(char* err_msg);
    int GameLog(char* log_msg);
    int GameLog(double num);
    int GameTip(char* tip_msg,SDL_MessageBoxFlags flag);
    int GameTip(double num);
private:
    FILE*log_fp;
    FILE*err_fp;
    SDL_Window* mainWindow;
    SDL_Surface* screenSurface;
    unsigned int screen_height;
    unsigned int screen_width;
};
extern Debug debug;
# endif

