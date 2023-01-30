# include <SDL2/SDL_mixer.h>
# include <SDL2/SDL_image.h>
# include <string>
# include "Application.h"
# include "CFG.h"
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

    CCFG::getMM()->setActiveOption(rR);
    CCFG::getSMBLogo()->setImg("contra",rR);
    CCFG::getMusic()->PlayMusic();
    
    //其他初始化
    this->keyMenuPressed = this->movePressed = false;
    this->keyS = this->keyW = this->keyA = this->keyD = this->keyShift = false;
    
    this->keyAPressed = this->keyDPressed = this->firstDir = false;

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
    SDL_Quit();
}

void Application::mainloop(){
    lFPSTime = SDL_GetTicks();
    while(!quitGame && mainEvent->type != SDL_QUIT){
        frameTime = SDL_GetTicks();
        SDL_PollEvent(mainEvent);
        SDL_RenderClear(rR);

        //设置菜单管理的背景颜色
        CCFG::getMM()->setBackgroundColor(rR);
        SDL_RenderFillRect(rR,NULL);

        Input();
		MouseInput();
		Update();
		Draw();
        
        
        //FPS 显示设置
        CCFG::getText()->Draw(rR, "FPS:" + std::to_string(iNumOfFPS), CCFG::GAME_WIDTH - CCFG::getText()->getTextWidth("FPS:" + std::to_string(iNumOfFPS), 8) - 8, 5, 8);
		if(SDL_GetTicks() - 1000 >= lFPSTime) {
			lFPSTime = SDL_GetTicks();
			iNumOfFPS = iFPS;
			iFPS = 0;
		}
		++iFPS;



		SDL_RenderPresent(rR);
        if(SDL_GetTicks() - frameTime < MIN_FRAME_TIME){
            SDL_Delay(MIN_FRAME_TIME - (SDL_GetTicks() - frameTime));
        }
    }
}

Map* Application::getMap(){
    return oMap;
}

void Application::Input(){
    switch(CCFG::getMM()->getViewID()){
        case MenuManager::gameState::eGameLoading:
            break;
        default:
            InputMenu();
            break;
    }
}

void Application::MouseInput() {
	switch(mainEvent->type) {
		case SDL_MOUSEBUTTONDOWN: {
			switch (mainEvent->button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftPressed = true;
					break;
				case SDL_BUTTON_RIGHT:
					mouseRightPressed = true;
					break;
			}
			break;
		}
		case SDL_MOUSEMOTION: {
			
			SDL_GetMouseState(&mouseX, &mouseY);
			//CCFG::getMM()->getConsole()->print("x:" + std::to_string(mouseX));
			//CCFG::getMM()->getConsole()->print("y:" + std::to_string(mouseY));
			break;
		}
		case SDL_MOUSEBUTTONUP: {
			switch (mainEvent->button.button) {
				case SDL_BUTTON_LEFT:
					mouseLeftPressed = false;
					break;
				case SDL_BUTTON_RIGHT:
					mouseRightPressed = false;
					break;
			}
			break;
		}
		case SDL_MOUSEWHEEL:
			if(mainEvent->wheel.timestamp > SDL_GetTicks() - 2) {
				//CCFG::getMM()->getLE()->mouseWheel(mainEvent->wheel.y);
			}
			break;
	}
}


void Application::InputPlayer(){

}

void Application::InputMenu(){
    if(mainEvent->type == SDL_KEYDOWN){
        CCFG::getMM()->setKey(mainEvent->key.keysym.sym);

        switch(mainEvent->key.keysym.sym){
            case SDLK_s: case SDLK_DOWN:
                if(!keyMenuPressed){
                    CCFG::getMM()->keyPressed(2);
                    keyMenuPressed = true;
                }
                break;
            case SDLK_w: case SDLK_UP:
                if(!keyMenuPressed){
                    CCFG::getMM()->keyPressed(0);
                    keyMenuPressed = true;
                }
                break;
            case SDLK_KP_ENTER: case SDLK_RETURN:
                if(!keyMenuPressed) {
                    CCFG::getMM()->enter();
                    keyMenuPressed = true;
                }
                break;
            case SDLK_ESCAPE:
				if(!keyMenuPressed) {
					CCFG::getMM()->escape();
					keyMenuPressed = true;
				}
				break;
            case SDLK_LEFT: case SDLK_d:
				if(!keyMenuPressed) {
					CCFG::getMM()->keyPressed(3);
					keyMenuPressed = true;
				}
				break;
			case SDLK_RIGHT: case SDLK_a:
				if(!keyMenuPressed) {
					CCFG::getMM()->keyPressed(1);
					keyMenuPressed = true;
				}
				break;
        }
    }

    if(mainEvent->type == SDL_KEYUP){
        switch(mainEvent->key.keysym.sym){
            case SDLK_s: case SDLK_DOWN: case SDLK_w: case SDLK_UP: case SDLK_KP_ENTER: case SDLK_RETURN: case SDLK_ESCAPE: case SDLK_a: case SDLK_RIGHT: case SDLK_LEFT: case SDLK_d:
                keyMenuPressed = false;
                break;
        }
    }
}

void Application::Update(){
	CCFG::getMM()->Update();
}

void Application::Draw(){
    CCFG::getMM()->Draw(rR);
}

