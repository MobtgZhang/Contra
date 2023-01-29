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
        eLoading,
        eGame,
        eAbout,
        eOptions,
        ePasue,
    };

    gameState currentGameState;

    CImg* getActiveOption();
    void setActiveOption(SDL_Renderer* rR);
    
    int getViewID();
	void setViewID(gameState viewID);
    OptionsMenu* getOptions();
    LoadingMenu* getLoadingMenu();
    AboutMenu* getAboutMenu();
    void resetActiveOptionID(gameState ID);
};

# endif

