# include "MenuManager.h"
# include "Application.h"

MenuManager::MenuManager(void) {
	this->currentGameState = eMainMenu;

	this->oMainMenu = new MainMenu();
	this->oLoadingMenu = new LoadingMenu();
	this->oAboutMenu = new AboutMenu();
	this->oOptionsMenu = new OptionsMenu();
	this->oPauseMenu = new PauseMenu();
}


MenuManager::~MenuManager(void) {
	delete activeOption;
	delete oMainMenu;
	delete oLoadingMenu;
	delete oAboutMenu;
}


CImg* MenuManager::getActiveOption(){
    return activeOption;
}

void MenuManager::setActiveOption(SDL_Renderer* rR) {
	activeOption = new CImg("active_option", rR);
}

int MenuManager::getViewID(){
    return currentGameState;
}
void MenuManager::setViewID(gameState viewID){
    this->currentGameState = viewID;
}

OptionsMenu* MenuManager::getOptions(){
    return oOptionsMenu;
}


void MenuManager::resetActiveOptionID(gameState ID){
    switch(ID) {
		case eMainMenu:
			oMainMenu->activeMenuOption = 0;
			break;
		case eOptions:
			oOptionsMenu->activeMenuOption = 0;
			break;
		case ePasue:
			oPauseMenu->activeMenuOption = 0;
			break;
	}
}

LoadingMenu* MenuManager::getLoadingMenu() {
	return oLoadingMenu;
}

AboutMenu* MenuManager::getAboutMenu() {
	return oAboutMenu;
}

void MenuManager::setBackgroundColor(SDL_Renderer* rR) {
	switch(currentGameState) {
		case eMainMenu:
			Application::getMap()->setBackgroundColor(rR);
			break;
		case eGameLoading:
			SDL_SetRenderDrawColor(rR, 0, 0, 0, 255);
			break;
		case eGame:
			Application::getMap()->setBackgroundColor(rR);
			break;
		case eAbout:
			oAboutMenu->setBackgroundColor(rR);
			break;
	}
}