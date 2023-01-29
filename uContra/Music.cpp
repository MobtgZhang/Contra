# include "Music.h"
Music::Music(){
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    // 加载MP3 文件
    vMusic.push_back(loadMusic("title"));
    vMusic.push_back(loadMusic("introduction"));
    vMusic.push_back(loadMusic("1,7-jungle"));
    vMusic.push_back(loadMusic("2,4-maze"));
    vMusic.push_back(loadMusic("2,4-mazeboss"));
    vMusic.push_back(loadMusic("3-waterfall"));
    vMusic.push_back(loadMusic("5-ice"));
    vMusic.push_back(loadMusic("6-flame"));
    vMusic.push_back(loadMusic("8-heartbeat"));
    vMusic.push_back(loadMusic("triumphant"));
    vMusic.push_back(loadMusic("triumphantboss"));
    vMusic.push_back(loadMusic("ending"));
    vMusic.push_back(loadMusic("gameover"));
    // 加载WAV文件
    vMusic.push_back(loadMusic("airplane_motor"));
    vMusic.push_back(loadMusic("alarm"));
    vMusic.push_back(loadMusic("bombing0"));
    vMusic.push_back(loadMusic("bombing1"));
    vMusic.push_back(loadMusic("bombing2"));
    vMusic.push_back(loadMusic("bombing3"));
    vMusic.push_back(loadMusic("f_gun"));
    vMusic.push_back(loadMusic("l_gun"));
    vMusic.push_back(loadMusic("m_gun"));
    vMusic.push_back(loadMusic("n_gun"));
    vMusic.push_back(loadMusic("s_gun"));
    vMusic.push_back(loadMusic("flame"));
    vMusic.push_back(loadMusic("p_1up"));
    vMusic.push_back(loadMusic("p_death"));
    vMusic.push_back(loadMusic("p_landing"));
    vMusic.push_back(loadMusic("p_shock"));
    vMusic.push_back(loadMusic("pipebomb"));
    vMusic.push_back(loadMusic("robot_landing"));
    vMusic.push_back(loadMusic("stone_landing"));
    //设置音量高低
    setVolume(100);
    this->currentMusic = mNOTHING;
}

Music::~Music(){
    for(unsigned int k=0;k<vMusic.size();k++){
        Mix_FreeMusic(vMusic[k]);
    }
    vMusic.clear();
    for(unsigned int k=0;k<vChunk.size();k++){
        Mix_FreeChunk(vChunk[k]);
    }
    vChunk.clear();
    Mix_CloseAudio();
}

void Music::PlayChunk(eChunk chunkID) {
	Mix_VolumeChunk(vChunk[chunkID], iVolume);
	Mix_PlayChannel(-1, vChunk[chunkID], 0);
}

void Music::PlayMusic() {
	if(currentMusic != mNOTHING) {
		Mix_PlayMusic(vMusic[currentMusic - 1], -1);
		musicStopped = false;
	} else {
		StopMusic();
	}
}

void Music::PlayMusic(eMusic musicID) {
	if(musicID != mNOTHING) {
		Mix_PlayMusic(vMusic[musicID - 1], -1);
		musicStopped = false;
		currentMusic = musicID;
	} else {
		StopMusic();
		currentMusic = mNOTHING;
	}
}

void Music::StopMusic() {
	if(!musicStopped) {
		Mix_HaltMusic();
		musicStopped = true;
	}
}

void Music::PauseMusic() {
	if(Mix_PausedMusic() == 1) {
		Mix_ResumeMusic();
		musicStopped = false;
	} else {
		Mix_PauseMusic();
		musicStopped = true;
	}
}

Mix_Music* Music::loadMusic(std::string fileName){
    fileName = "files/musics" + fileName + ".mp3";
    return Mix_LoadMUS(fileName.c_str());
}

Mix_Chunk* Music::loadChunk(std::string fileName){
    fileName = "files/chunks" + fileName + ".wav";
    return Mix_LoadWAV(fileName.c_str());
}

int Music::getVolume(){
    return iVolume;
}

void Music::setVolume(int iVolume){
    this->iVolume = iVolume;
    Mix_VolumeMusic(iVolume);
}