# include "AboutMenu.h"
# include "CFG.h"

AboutMenu::AboutMenu(){
    lMO.push_back(new MenuOption("MAIN MENU",150,340));

    this->numOfMenuOptions = lMO.size();

}

AboutMenu::~AboutMenu(){

}

void AboutMenu::Draw(SDL_Renderer* rR){
    
}

void AboutMenu::enter(){
    CCFG::getMM()->resetGameState(CCFG::getMM()->eMainMenu);
    CCFG::getMM()->setGameState(CCFG::getMM()->eMainMenu);
    //reset();
    CCFG::getMusic()->StopMusic();
}

void AboutMenu::updateTime(){
    this->iTime = SDL_GetTicks();
}

