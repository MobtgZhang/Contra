# ifndef MENUMANAGER_HEADERS
# define MENUMANAGER_HEADERS

# include "Img.h"
# include "MainMenu.h"
# include "LoadingMenu.h"
# include "AboutMenu.h"
# include "OptionsMenu.h"
# include "PauseMenu.h"

class MenuManager{
private:
    CImg* activeOption;

    MainMenu* oMainMenu;
    LoadingMenu* oLoadingMenu;
    AboutMenu* oAboutMenu;
    OptionsMenu* oOptionsMenu;
    PauseMenu* oPauseMenu;
public:
    MenuManager();
    ~MenuManager();
    
    enum gameState {
        eMainMenu,
        eGameLoading,
        eGame,
        eAbout,
        eOptions,
        ePause,
    };

    gameState currentGameState;

    CImg* getActiveOption();
    void setActiveOption(SDL_Renderer* rR);
    
    void setKey(int keyID);
    void keyPressed(int iDir);

    int getViewID();
	void setViewID(gameState viewID);
    OptionsMenu* getOptions();
    LoadingMenu* getLoadingMenu();
    AboutMenu* getAboutMenu();
    void resetActiveOptionID(gameState ID);
    void setBackgroundColor(SDL_Renderer* rR);

    void enter();
    void escape();

    void Update();
};

# endif

