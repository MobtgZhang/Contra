# ifndef APPLICATION_H
# define APPLICATION_H
# include<SDL2/SDL.h>

class Application{
public:
    Application();
    ~Application();
private:
    //判游戏是否退出
    SDL_Window* window;
	SDL_Renderer* rR;
	SDL_Event* mainEvent;
};
# endif
