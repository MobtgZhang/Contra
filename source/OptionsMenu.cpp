# include "OptionsMenu.h"
# include "CFG.h"
# include "Application.h"

OptionsMenu::OptionsMenu(){
    rRect.x = 32;
	rRect.y = 48;
	rRect.w = 403;
	rRect.h = 324;

    this->lMO.push_back(new MenuOption("VOLUME", 73, 65));
	this->lMO.push_back(new MenuOption("LEFT", 73, 89));
	this->lMO.push_back(new MenuOption("DOWN", 73, 113));
	this->lMO.push_back(new MenuOption("RIGHT", 73, 137));
	this->lMO.push_back(new MenuOption("UP", 73, 161));
	this->lMO.push_back(new MenuOption("A", 73, 185));
	this->lMO.push_back(new MenuOption("B", 73, 209));
	this->lMO.push_back(new MenuOption("X", 73, 233));
	this->lMO.push_back(new MenuOption("Y", 73, 257));
	this->lMO.push_back(new MenuOption("CAN MOVE BACKWARD", 73, 281));
	this->lMO.push_back(new MenuOption("MAIN MENU", 73, 305));

    this->numOfMenuOptions = lMO.size();

    this->inSetKey = this->resetSetKey = false;

    rSetKeyRect.x = 75;
	rSetKeyRect.y = 284;
	rSetKeyRect.w = 369;
	rSetKeyRect.h = 71;

	rVolumeBG.x = 185;
	rVolumeBG.y = 65;
	rVolumeBG.h = 16;
	rVolumeBG.w = 200;

	rVolume.x = 185;
	rVolume.y = 65;
	rVolume.h = 16;
	rVolume.w = 100;

	this->escapeToMainMenu = true;
}


OptionsMenu::~OptionsMenu(){

}

void OptionsMenu::setEscapeToMainMenu(bool escapeToMainMenu){
    this->escapeToMainMenu = escapeToMainMenu;
}

void OptionsMenu::updateVolumeRect(){
    rVolume.w = CCFG::getMusic()->getVolume()*2;
}

void OptionsMenu::enter(){
	switch (activeMenuOption){
	case OptionsMenu::optionVOLUME:
		CCFG::getMusic()->PlayChunk(CCFG::getMusic()->cP_1UP);
		break;
	case optionLEFT: case optionDOWN: case optionRIGHT: case optionUP:
    case optionA: case optionB: case optionX: case optionY:
		inSetKey = true;
		break;
	case optionMOVEBACKWARD:
		CCFG::canMoveBackward = !CCFG::canMoveBackward;
		break;
	case optionMAINMENU:
		//Application::getMap()->resetGameData();
		CCFG::getMM()->setGameState(CCFG::getMM()->eMainMenu);
	default:
		break;
	}
}


void OptionsMenu::updateActiveButton(int iDir){
	if((activeMenuOption == OptionsMenu::optionVOLUME) && (iDir == Menu::iLEFT_ITEM || iDir == Menu::iRIGHT_ITEM) ){
		switch(iDir){
			case Menu::iLEFT_ITEM:
				if(CCFG::getMusic()->getVolume()>0){
					CCFG::getMusic()->setVolume(CCFG::getMusic()->getVolume() - 5);
				}else{
					CCFG::getMusic()->setVolume(0);
				}
				break;
			case Menu::iRIGHT_ITEM:
				if(CCFG::getMusic()->getVolume()<100){
					CCFG::getMusic()->setVolume(CCFG::getMusic()->getVolume() + 5);
				}else{
					CCFG::getMusic()->setVolume(100);
				}
				break;
			default:
				break;
		}
		updateVolumeRect();
		CCFG::getMusic()->PlayChunk(CCFG::getMusic()->cP_1UP);
	}
	if(!inSetKey){
		Menu::updateActiveButton(iDir);
	}
}

void OptionsMenu::escape(){
    if(inSetKey){
        resetSetKey = true;
    }else{
        if(escapeToMainMenu){
            //Application::getMap()->resetGameData();
            CCFG::getMM()->setGameState(CCFG::getMM()->eMainMenu);
        }else{
            CCFG::getMM()->setGameState(CCFG::getMM()->ePause);
        }
    }
}

void OptionsMenu::Draw(SDL_Renderer* rR){
	SDL_SetRenderDrawBlendMode(rR, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(rR, 4, 4, 4, 235);
	SDL_RenderFillRect(rR, &rRect);
	SDL_SetRenderDrawColor(rR, 255, 255, 255, 255);
	rRect.x += 1;
	rRect.y += 1;
	rRect.h -= 2;
	rRect.w -= 2;
	SDL_RenderDrawRect(rR, &rRect);
	rRect.x -= 1;
	rRect.y -= 1;
	rRect.h += 2;
	rRect.w += 2;

	for(unsigned int i = 0; i < lMO.size(); i++) {
		if(i == activeMenuOption) {
			CCFG::getText()->Draw(rR, lMO[i]->getText(), lMO[i]->getXPos(), lMO[i]->getYPos(), 16, 255, 255, 255);
		} else {
			CCFG::getText()->Draw(rR, lMO[i]->getText(), lMO[i]->getXPos(), lMO[i]->getYPos(), 16, 90, 90, 90);
		}
	}

	SDL_SetRenderDrawColor(rR, 4, 4, 4, 245);
	SDL_RenderFillRect(rR, &rVolumeBG);

	SDL_SetRenderDrawColor(rR, activeMenuOption == 0 ? 150 : 90, activeMenuOption == 0 ? 150 : 90, activeMenuOption == 0 ? 150 : 90, 255);
	SDL_RenderFillRect(rR, &rVolume);

	if(activeMenuOption == 0) {
		SDL_SetRenderDrawColor(rR, 255, 255, 255, 255);
		SDL_RenderDrawRect(rR, &rVolumeBG);
	} else {
		SDL_SetRenderDrawColor(rR, 160, 160, 160, 55);
		SDL_RenderDrawRect(rR, &rVolumeBG);
	}

	
















	if(inSetKey) {
		SDL_SetRenderDrawColor(rR, 20, 20, 20, 245);
		SDL_RenderFillRect(rR, &rSetKeyRect);
		SDL_SetRenderDrawColor(rR, 255, 255, 255, 255);
		rSetKeyRect.x += 1;
		rSetKeyRect.y += 1;
		rSetKeyRect.h -= 2;
		rSetKeyRect.w -= 2;
		SDL_RenderDrawRect(rR, &rSetKeyRect);
		rSetKeyRect.x -= 1;
		rSetKeyRect.y -= 1;
		rSetKeyRect.h += 2;
		rSetKeyRect.w += 2;

		CCFG::getText()->Draw(rR, "PRESS KEY FOR " + lMO[activeMenuOption]->getText(), 92, rSetKeyRect.y + 16, 16, 255, 255, 255);
		CCFG::getText()->Draw(rR, "PRESS ESC TO CANCEL", 92, rSetKeyRect.y + 40, 16, 255, 255, 255);
	}

	SDL_SetRenderDrawBlendMode(rR, SDL_BLENDMODE_NONE);



}

void OptionsMenu::Update(){
	if(resetSetKey){
		inSetKey = false;
		resetSetKey = false;
	}
}

