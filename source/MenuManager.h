# pragma once
# ifndef MENUMANAGER_H
# define MENUMANAGER_H
# include "MainMenu.h"
# include "Text.h"

enum gameState{
        eMainMenu,
        eGameLoading,
        eGame,
        eAbout,
        eOptions,
        ePause
};

class MenuManager{
private:
    MainMenu* oMainMenu;
    gameState currentGame;
public:
    MenuManager();
    ~MenuManager();

    gameState getGameState();
    void setGameState(gameState state);
    void setBackgroundColor(SDL_Renderer* rR);
    void Draw(SDL_Renderer* rR);
    void Update();
};

# endif
