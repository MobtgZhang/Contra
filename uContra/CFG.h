# ifndef CCFG_HEADERS
# define CCFG_HEADERS
# include "Img.h"
# include"Music.h"
# include"Text.h"
# include"MenuManager.h"

class CCFG{
private:
    static CImg* tSMBLOGO;
    static Music* oMusic;
    static Text* oText;
    static MenuManager* oMM;
public:
    CCFG();
    ~CCFG();

    static int GAME_WIDTH,GAME_HEIGHT;
    static int keyIDA,keyIDS,keyIDD,keyIDSpace,keyIDShift;

    static Music* getMusic();
    static CImg* getSMBLogo();
    static Text* getText();

    static MenuManager* getMM();
    static std::string getKeyString(int keyID);
    static bool canMoveBackward;
};
# endif

