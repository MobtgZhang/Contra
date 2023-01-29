# ifndef MUSIC_HEADERS
# define MUSIC_HEADERS

# include<SDL2/SDL_mixer.h>
# include<string>
# include<vector>

class Music{
private:
    std::vector<Mix_Music*> vMusic;
    std::vector<Mix_Chunk*> vChunk;

    int iVolume;
public:
    Music();
    ~Music();

    bool musicStopped;

    enum eMusic{
        mNOTHING, //什么也没有
        mTITLE,   //开始
        mINTRODUCTION,  //介绍部分
        mJUNGLE,    //第一、七关：丛林
        mMAZEFORTRESS,  //第二、四关：地下室迷宫
        mMAZEFORTRESSBOSS,  // 第二、四关： BOSS
        mWATERFALL,  //第三关：瀑布
        mFROTRESSOFICE, // 第五关：下雪森林
        mFORTRESSODFLAME, // 第六关：火焰堡垒
        mHORRIBLEHEARTBEAT, // 第八关：怪兽心脏
        mTRIUMPHANTRETURN, // 关卡通关音乐
        mTRIUMPHANTRETURNBOSS,// 最后BOSS通关音乐
        mSANDINISTAENDING, //最后介绍音乐
        mGAMEOVER, //游戏结束音乐
    };
    eMusic currentMusic;

    enum eChunk{
        cAIRPLANEMOTOR,
        cALARM,
        cBOMBING0,
        cBOMBING1,
        cBOMBING2,
        cBOMBING3,
        cBONUS,
        cF_GUN,
        cL_GUN,
        cM_GUN,
        cN_GUN,
        cS_GUN,
        cFLAME,
        cHITSND0,
        cHITSND1,
        cHITSND2,
        cP_1UP,
        cP_DEATH,
        cP_LANDING,
        cP_SHOCK,
        cPIPEBOMB,
        cROBOT_LANDING,
        cSTONE_LANDING
    };

    void PauseMusic();
    void PlayMusic();
    void PlayChunk(eChunk chunkID);
    void PlayMusic(eMusic musicID);
    void StopMusic();
    Mix_Music* loadMusic(std::string fileName);
    Mix_Chunk* loadChunk(std::string fileName);

    int getVolume();
    void setVolume(int iVolume);

};
# endif
