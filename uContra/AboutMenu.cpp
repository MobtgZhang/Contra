# include "AboutMenu.h"

AboutMenu::AboutMenu(){
    this->cR = 93;
	this->cG = 148;
	this->cB = 252;
}
AboutMenu::~AboutMenu(){

}

void AboutMenu::Update(){

}

void AboutMenu::Draw(SDL_Renderer* rR){

}

void AboutMenu::enter(){

}

void AboutMenu::updateTime(){
    
}


void AboutMenu::setBackgroundColor(SDL_Renderer* rR) {
	SDL_SetRenderDrawColor(rR, cR, cG, cB, 255);
}

