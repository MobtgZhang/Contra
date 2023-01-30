# include "Map.h"
# include "CFG.h"


Map::Map(){
    
}
Map::Map(SDL_Renderer* rR){
    oPlayer = new Player(rR, 84, 368);

    oEvent = new Event();
}

Map::~Map(){
    delete oEvent;
}
// 加载开始标题部分
void Map::load_Title(){
    
} 
// 第一关
void Map::load_Jungle(){

}

// 第二关
void Map::load_MazeBase1(){
    
}
// 第三关
void Map::load_WaterFall(){

}
// 第四关
void Map::load_MazeBase2(){

}
// 第五关
void Map::load_SnowField(){

}
// 第六关
void Map::load_EnergyZone(){

}
// 第七关
void Map::load_Hangar(){

}
//第八关
void Map::load_AlienLair(){

}

//飞机炸岛动画
void Map::load_Airplane(){

}

//显示最后制作人员
void Map::load_Trimplet(){

} 

Event* Map::getEvent(){
    return oEvent;
}

Player* Map::getPlayer(){
    return oPlayer;
}

void Map::resetGameData(){
	
}

void Map::setBackgroundColor(SDL_Renderer* rR) {
	SDL_SetRenderDrawColor(rR, 0, 0, 0, 255);
}


void Map::UpdateMinions(){

}

void Map::UpdateMinionsCollisions(){

}

void Map::UpdateBlocks(){

}

void Map::UpdateMinionBlokcs(){

}

void Map::Draw(SDL_Renderer* rR){

}

void Map::Update(){
    
}


void Map::DrawMap(SDL_Renderer* rR){
    
}  

void Map::DrawGameLayout(SDL_Renderer* rR){

}

void Map::moveMap(int nX, int nY) {
	if (fXPos + nX > 0) {
		oPlayer->updateXPos((int)(nX - fXPos));
		fXPos = 0;
	}
	else {
		this->fXPos += nX;
	}
}


int Map::getStartBlock() {
	return (int)(-fXPos - (-(int)fXPos) % 32) / 32;
}

int Map::getEndBlock() {
	return (int)(-fXPos - (-(int)fXPos) % 32 + CCFG::GAME_WIDTH) / 32 + 2;
}

