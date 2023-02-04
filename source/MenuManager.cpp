# include "MenuManager.h"
MenuManager::MenuManager(){
    this->currentGame = eMainMenu;
    this->oMainMenu = new MainMenu();
}

MenuManager::~MenuManager(){
    delete oMainMenu;
}

gameState MenuManager::getGameState(){
    return currentGame;
}
void MenuManager::setGameState(gameState state){
    this->currentGame = state;
}


void MenuManager::setBackgroundColor(SDL_Renderer* rR){
    switch (currentGame){
    case eMainMenu:
        SDL_SetRenderDrawColor(rR,0,0,0,255);
        break;
    default:
        break;
    }
}

void MenuManager::Draw(SDL_Renderer* rR){
    switch(currentGame){
        case eMainMenu:
            oMainMenu->Draw(rR);
    }
}

void MenuManager::Update(){

}