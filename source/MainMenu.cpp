# include "MainMenu.h"
# include "MenuOption.h"
# include "CFG.h"
# include "Application.h"

MainMenu::MainMenu(){
    this->lMO.push_back(new MenuOption("START",256,384));
    this->lMO.push_back(new MenuOption("OPTIONS",256,4161));
    this->lMO.push_back(new MenuOption("ABOUT",256,448));

    this->numOfMenuOptions = lMO.size();
    this->activeMenuOption = 0;

}

MainMenu::~MainMenu(){

}

void MainMenu::Draw(SDL_Renderer* rR){
    CCFG::getLogo()->Draw(rR,160,0);
    Menu::Draw(rR);
    CCFG::getText()->Draw(rR, "MOBTGZHANG", 4, CCFG::GAME_HEIGHT - 4 - 8, 8, 0, 0, 0);
    if(selectLevel){
        SDL_SetRenderDrawBlendMode(rR,SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(rR,251,251,251,20);
        SDL_RenderFillRect(rR, &rSelectLevel);
		SDL_SetRenderDrawColor(rR, 255, 255, 255, 255);
        rSelectLevel.x += 1;
		rSelectLevel.y += 1;
		rSelectLevel.h -= 2;
		rSelectLevel.w -= 2;
		SDL_RenderDrawRect(rR, &rSelectLevel);
		rSelectLevel.x -= 1;
		rSelectLevel.y -= 1;
		rSelectLevel.h += 2;
		rSelectLevel.w += 2;

        CCFG::getText()->Draw(rR, "SELECT LEVEL", rSelectLevel.x + rSelectLevel.w/2 - CCFG::getText()->getTextWidth("SELECT WORLD")/2, rSelectLevel.y + 16, 16, 255, 255, 255);


        SDL_SetRenderDrawBlendMode(rR, SDL_BLENDMODE_NONE);
		//Application::getMap()->setBackgroundColor(rR);
    }
}

