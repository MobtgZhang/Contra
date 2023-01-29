#ifndef MENU_HEADERS
#define MENU_HEADERS

# include <vector>
# include <SDL2/SDL.h>
# include "MenuOption.h"

class Menu{
public:
	Menu();
	~Menu();

	std::vector<MenuOption*> lMO;

	int activeMenuOption;
	int numOfMenuOptions;

	virtual void Update();
	virtual void Draw(SDL_Renderer* rR);
	
	// ------- 0 = TOP, 1 = RIGHT, 2 = BOTTON, 3 = LEFT
	virtual void updateActiveButton(int iDir);
};

# endif