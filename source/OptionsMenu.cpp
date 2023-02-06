# include "OptionsMenu.h"
# include "CFG.h"
# include "Application.h"

OptionsMenu::OptionsMenu(){
    rRect.x = 58;
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
	this->lMO.push_back(new MenuOption("X", 73, 257));
	this->lMO.push_back(new MenuOption("Y", 73, 305));
	this->lMO.push_back(new MenuOption("CAN MOVE BACKWARD", 73, 353));
	this->lMO.push_back(new MenuOption("MAIN MENU", 73, 401));

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


