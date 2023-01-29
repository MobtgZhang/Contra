# ifndef CCFG_HEADERS
# define CCFG_HEADERS
# include"Music.h"

class CCFG{
private:
    static Music* oMusic;
    
public:
    CCFG();
    ~CCFG();

    static int GAME_WIDTH,GAME_HEIGHT;
    static int keyIDA,keyIDS,keyIDD,keyIDSpace,keyIDShift;

    static Music* getMusic();

};
# endif

