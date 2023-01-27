# include <SDL2/SDL_mixer.h>
# include <SDL2/SDL_image.h>
# include <string>
# include "Application.h"
# include "CCFG.h"
//类的静态需要初始化
Map* Application::oMap = new Map();
bool Application::mouseLeftPressed = false;
bool Application::mouseRightPressed = false;
int Application::mouseX = 0;
int Application::mouseY = 0;
bool Application::quitGame = false;

bool Application::movePressed = false;
bool Application::keyMenuPressed = false;
bool Application::keyS = false;
bool Application::keyW = false;
bool Application::keyA = false;
bool Application::keyD = false;
bool Application::keyShift = false;
bool Application::keyAPressed = false;
bool Application::keyDPressed = false;

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
    //图标
    std::string fileName = "files/images/ico.png";
    SDL_Surface* loadedSurface = IMG_LoadPNG_RW(SDL_RWFromFile(fileName.c_str(),"rb"));
    SDL_SetColorKey(loadedSurface,SDL_TRUE,SDL_MapRGB(loadedSurface->format,255,0,255));
    SDL_SetWindowIcon(window,loadedSurface);
    SDL_FreeSurface(loadedSurface);
    //设置全局事件信息
    mainEvent = new SDL_Event();

    //加载全局音效
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    // 加载地图
    oMap = new Map(rR);
    
    //其他初始化
    this->keyMenuPressed = this->movePressed = false;
    this->keyS = this->keyW = this->keyA = this->keyD = this->keyShift = false;
    
    this->keyAPressed = this->keyDPressed = false;

    this->mouseX = this->mouseY = 0;

    CCFG::keyIDA = SDLK_a;
    CCFG::keyIDS = SDLK_s;
    CCFG::keyIDD = SDLK_d;
    CCFG::keyIDSpace = SDLK_SPACE;
    CCFG::keyIDShift = SDLK_LSHIFT;
}
Application::~Application(){
    delete mainEvent;
    delete oMap;
    SDL_DestroyRenderer(rR);
    SDL_DestroyWindow(window);
}

void Application::mainloop(){
    
}