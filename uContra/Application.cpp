# include <SDL2/SDL_mixer.h>
# include <SDL2/SDL_image.h>
# include <string>
# include "Application.h"
# include "CCFG.h"

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
    
    //设置全局事件信息
    mainEvent = new SDL_Event();

    //加载全局音效
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    // 加载地图
    oMap = new Map(rR);
    //图标
    //其他初始化
    this->keyMenuPressed = this->movePressed = false;
    this->keyS = this->keyW = this->keyA = this->keyD = this->keyShift = false;
    
    this->keyAPressed = this->keyDPressed = false;

    this->mouseX = this->mouseY = 0;

    CCFG::keyIDA = SDLK_a;
    CCFG::keyIDS = SDLK_s;
    CCFG::keyIDD = SDLK_d;
    CCFG::KeyIDSpace = SDLK_SPACE;
    CCFG::keyIDShift = SDLK_LSHIFT;
}
Application::~Application(){
    delete mainEvent;
    SDL_DestroyRenderer(rR);
    SDL_DestroyWindow(window);
}

void Application::mainloop(){
    
}