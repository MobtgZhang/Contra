# include "MainMenu.h"
# include "MenuOption.h"
# include "CFG.h"

MainMenu::MainMenu(){
    this->lMO.push_back(new MenuOption("START",256,352));
    this->lMO.push_back(new MenuOption("OPTIONS",256,384));
    this->lMO.push_back(new MenuOption("ABOUT",256,416));

    this->numOfMenuOptions = lMO.size();
    this->activeMenuOption = 0;

}

MainMenu::~MainMenu(){

}

void MainMenu::Draw(SDL_Renderer* rR){
    CCFG::getLogo()->Draw(rR,160,0);
    Menu::Draw(rR);
    //CCFG::getText()->Draw(rR, "WWW.LUKASZJAKOWSKI.PL", 4, CCFG::GAME_HEIGHT - 4 - 8, 8, 0, 0, 0);

	//CCFG::getText()->Draw(rR,"START",240,288,255,255,255);
    //CCFG::getText()->Draw(rR,"OPTIONS",240,320,255,255,255);
    //CCFG::getText()->Draw(rR,"ABOUT",240,352,255,255,255);
}

