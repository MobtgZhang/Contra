# include "Menu.h"
# include "CFG.h"

Menu::Menu(){
    this->activeMenuOption = 0;
}

Menu::~Menu(){

}

void Menu::Draw(SDL_Renderer* rR){
    for(unsigned int k=0;k<lMO.size();k++){
        CCFG::getText()->Draw(rR,lMO[k]->getText(),lMO[k]->getXPos(),lMO[k]->getYPos());
    }
    CCFG::getMM()->getActiveOption()->Draw(rR,lMO[activeMenuOption]->getXPos()-32,lMO[activeMenuOption]->getXPos());
}

void Menu::Update(){

}
