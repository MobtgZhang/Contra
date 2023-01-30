# include "MainMenu.h"
# include "CFG.h"

MainMenu::MainMenu(){
    this->lMO.push_back(new MenuOption("1 PLAYER GAME",178,276));
    this->lMO.push_back(new MenuOption("OPTIONS", 222, 308));
	this->lMO.push_back(new MenuOption("ABOUT", 237, 340));

    this->numOfMenuOptions = lMO.size();

    this->selectStage = false;
    
    rSelectStage.x = 122;
	rSelectStage.y = 280;
	rSelectStage.w = 306;
	rSelectStage.h = 72;

    this->activeStageID = 0;
}

MainMenu::~MainMenu(){

}

void MainMenu::Update(){
    CCFG::getMusic()->StopMusic();
    Menu::Update();
}

void MainMenu::Draw(SDL_Renderer* rR){
    //注意窗口大小为800*448
    CCFG::getSMBLogo()->Draw(rR,160,0);
    Menu::Draw(rR);
}

void MainMenu::enter(){

}

void MainMenu::escape() {
	selectStage = false;
}

void MainMenu::updateActiveButton(int iDir) {

}

