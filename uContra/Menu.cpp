# include "Menu.h"
# include "CFG.h"

Menu::Menu(){
    this->activeMenuOption = 0;
}

Menu::~Menu(){

}

void Menu::Update(){

}

void Menu::Draw(SDL_Renderer* rR){
    for(unsigned int k=0;k<lMO.size();k++){
        CCFG::getText()->Draw(rR, lMO[k]->getText(), lMO[k]->getXPos(), lMO[k]->getYPos());
    }

	CCFG::getMM()->getActiveOption()->Draw(rR, lMO[activeMenuOption]->getXPos() - 32, lMO[activeMenuOption]->getYPos());
}

void Menu::updateActiveButton(int iDir) {
	switch(iDir) {
		case 0:
			if (activeMenuOption - 1 < 0) {
				activeMenuOption = numOfMenuOptions - 1;
			} else {
				--activeMenuOption;
			}
			break;
		case 2:
			if (activeMenuOption + 1 >= numOfMenuOptions) {
				activeMenuOption = 0;
			} else {
				++activeMenuOption;
			}
			break;
		default:
			break;
	}
}
