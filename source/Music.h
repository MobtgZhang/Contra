# pragma once
# ifndef MUSIC_H
# define MUSIC_H
# include<vector>
# include<string>
# include<SDL2/SDL_mixer.h>

/**
 * Mix_Chunk结构代表一个样本,或者换句话说是一个声音效果.
 * Mix_Music结构代表的一段音乐,可以为在延长的时间周期,通常重复播放.
 * 
*/
class Music{
private:
    std::vector<Mix_Music*> vMusic;
    std::vector<Mix_Chunk*> vChunk;
    int iVolume;
    bool musicStopped;
public:
    Music();
    ~Music();

    enum eChunk{
        cAIRPLANE_MOTOR,
        cALARM,
        cBOMBING_0,
        cBOMBING_1,
        cBOMBING_2,
        cBOMBING_3,
        cBOMBING_4,
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
        cPAUSE,
        cPIPEBOMB,
        cROBOT_LANDING,
        cSTONE_LANDING
    };

    enum eMusic {
        mNOTHING,
        mTITLE,
        mINTRODUCTION,
        mJUNGLE,
        mTRIUMPHANT,
        mMAZEFORTRESS,
        mMAZEFORTRESSBOSS,
        mWATERFALL,
        mFORTRESSICE,
        mFORTRESSFLAME,
        mHORRIBLEHEARTBEAT,
        mTRIUMPHANTBOSS,
        mSANDINISTA,
        mGAMEOVER
    };

    eMusic currentMusic;


    // 播放音乐
    void PlayMusic();
    void PlayMusic(eMusic musicID,int loops=-1);
    void StopMusic();
    void PauseMusic();
    void changeMusic();
    void PlayChunk(eChunk chunkID);

    Mix_Music* loadMusic(std::string fileName);
    Mix_Chunk* loadChunk(std::string fileName);

    void setVolume(int iVolume);
    int getVolume();
};
# endif
