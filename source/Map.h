# pragma once
# ifndef MAP_H
# define MAP_H
# include <SDL2/SDL.h>

class Map{
private:
    float fXPos,fYPos;

    // 加载地图的大小
    int iMapWidth, iMapHeight;
public:
    Map();
    Map(SDL_Renderer* rR);
    ~Map();

    void Draw(SDL_Renderer* rR);

    //加载第一关地图，Jungle
    void LoadJungle();
    //加载第二关地图，Maze Base 1
    void LoadMazeBaseA();
    //加载第三关地图，WaterFall
    void LoadMazeWaterFall();
    //加载第四关地图，Maze Base 2
    void LoadMazeBaseB();
    //加载第五关地图，Snow Field
    void LoadMazeSnowField();
    //加载第六关地图，Energy Zone
    void LoadMazeEnergyZone();
    //加载第七关地图，Hangar
    void LoadMazeHangar();
    //加载第八关地图，Alien"s Lair
    void LoadMazeAliensLair();
    // 加载地图的贴图数据
    void loadGameData(SDL_Renderer* rR);
    // 加载地图
    void loadLVL();
    
    int getStartBlock();
    int getEndBlock();
};

# endif
