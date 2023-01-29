#include "LoadingMenu.h"
#include "CFG.h"
#include "Application.h"

/* ******************************************** */

LoadingMenu::LoadingMenu(void) {
	this->iTime = 0;
	this->loadingType = true;
}

LoadingMenu::~LoadingMenu(void) {

}

/* ******************************************** */

void LoadingMenu::Update() {
	
}

void LoadingMenu::Draw(SDL_Renderer* rR) {
	
}

/* ******************************************** */

void LoadingMenu::updateTime() {
	this->iTime = SDL_GetTicks();
}

