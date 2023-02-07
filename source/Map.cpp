# include "Map.h"
# include "CFG.h"

Map::Map(){

}

Map::Map(SDL_Renderer* rR){
    this->iMapWidth = 0;
    this->iMapHeight = 0;
    this->fXPos = 0;
    this->fYPos = 0;

    srand((unsigned)time(NULL));

    loadGameData(rR);
	loadLVL();
}

Map::~Map(){

}

void Map::Draw(SDL_Renderer* rR){

}

//加载第一关地图，Jungle
void Map::LoadJungle(){

}
//加载第二关地图，Maze Base 1
void Map::LoadMazeBaseA(){

}
//加载第三关地图，WaterFall
void Map::LoadMazeWaterFall(){

}
//加载第四关地图，Maze Base 2
void Map::LoadMazeBaseB(){

}
//加载第五关地图，Snow Field
void Map::LoadMazeSnowField(){
    
}
//加载第六关地图，Energy Zone
void Map::LoadMazeEnergyZone(){

}
//加载第七关地图，Hangar
void Map::LoadMazeHangar(){

}
//加载第八关地图，Alien"s Lair
void Map::LoadMazeAliensLair(){

}

// 加载地图的贴图数据
void Map::loadGameData(SDL_Renderer* rR){

}
// 加载地图
void Map::loadLVL(){

}


//地图开始的模块
int Map::getStartBlock() {
	return (int)(-fXPos - (-(int)fXPos) % 32) / 32;
}

//地图结束的模块
int Map::getEndBlock() {
	return (int)(-fXPos - (-(int)fXPos) % 32 + CCFG::GAME_WIDTH) / 32 + 2;
}
