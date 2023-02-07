# include "AboutMenu.h"
# include "CFG.h"

AboutMenu::AboutMenu(){
    lMO.push_back(new MenuOption("MAIN MENU",150,340));

    this->numOfMenuOptions = lMO.size();

}

AboutMenu::~AboutMenu(){

}

void AboutMenu::Draw(SDL_Renderer* rR){
    CCFG::getText()->DrawWS(rR, "CONTRA V 1.0 - C++ AND SDL2", 150, 128, 0, 0, 0);
	CCFG::getText()->DrawWS(rR, "AUTHOR: MOBTGZHANG", 150, 160, 0, 0, 0);

	CCFG::getText()->DrawWS(rR, "CREATE IN YEAR OF 2023", 150, 192, 0, 0, 0);
	CCFG::getText()->DrawWS(rR, "MOBTGZHANG.GITHUB.IO", 150, 224, 0, 0, 0);

	for(unsigned int i = 0; i < lMO.size(); i++) {
		CCFG::getText()->DrawWS(rR, lMO[i]->getText(), lMO[i]->getXPos(), lMO[i]->getYPos(), 0, 0, 0);
	}

	CCFG::getMM()->getActiveOption()->Draw(rR, lMO[activeMenuOption]->getXPos() - 48, lMO[activeMenuOption]->getYPos()-4);
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

