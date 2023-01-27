# include "Application.h"
# include "CCFG.h"
# include <SDL2/SDL_mixer.h>
# include <SDL2/SDL_image.h>
# include <string>

Application::Application(){
    this->quitGame = false;
    this->iFPS = 0;
    this->iNumOfFPS = 0;
    this->lFPSTime = 0;

    //初始化SDL
    SDL_Init(SDL_INIT_VIDEO| SDL_INIT_TIMER| SDL_INIT_AUDIO);

    //创建窗口
    window = SDL_CreateWindow("uContra",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                    CCFG::GAME_WIDTH,CCFG::GAME_HEIGHT,SDL_WINDOW_SHOWN);
    if(window == NULL){
        quitGame = true;
    }
    //创建渲染
    rR = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    //创建图标
    /*std::string fileName = "files/images/ico.png";
    SDL_Surface* loadedSurface = IMG_LoadJPG_RW(SDL_RWFromFile(fileName.c_str(),"rb"));
    SDL_SetColorKey(loadedSurface,SDL_TRUE,SDL_MapRGB(loadedSurface->format,0,0,0));

    SDL_SetWindowIcon(window,loadedSurface);
    SDL_FreeSurface(loadedSurface);
    */

    //设置全局事件信息
    mainEvent = new SDL_Event();

    //加载全局音效
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    // 加载地图
    
    //图标

}
Application::~Application(){
    delete mainEvent;
    SDL_DestroyRenderer(rR);
    SDL_DestroyWindow(window);
}

void Application::mainloop(){
    
}