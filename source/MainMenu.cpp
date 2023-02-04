# include "MainMenu.h"
# include "CFG.h"

MainMenu::MainMenu(){

}

MainMenu::~MainMenu(){

}

void MainMenu::Draw(SDL_Renderer* rR){
    CCFG::getLogo()->Draw(rR,160,0);
    //CCFG::getText()->Draw(rR, "WWW.LUKASZJAKOWSKI.PL", 4, CCFG::GAME_HEIGHT - 4 - 8, 8, 0, 0, 0);
	//CCFG::getText()->Draw(rR,"START",240,288,255,255,255);
    //CCFG::getText()->Draw(rR,"OPTIONS",240,320,255,255,255);
    //CCFG::getText()->Draw(rR,"ABOUT",240,352,255,255,255);
}

