# ifndef MAP_HEADERS
# define MAP_HEADERS

# include<SDL2/SDL.h>
# include<SDL2/SDL_mixer.h>
# include<vector>
# include"Event.h"

class Map{
private:
    float fXpos,fYPos;
    Event* oEvent;

    void load_Title(); // 加载开始标题部分
    void load_Jungle(); // 第一关
    void load_MazeBase1(); // 第二关
    void load_WaterFall(); // 第三关
    void load_MazeBase2(); // 第四关
    void load_SnowField(); // 第五关
    void load_EnergyZone(); // 第六关
    void load_Hangar(); // 第七关
    void load_AlienLair(); //第八关
    void load_Airplane(); //飞机炸岛动画
    void load_Trimplet(); //显示最后制作人员

    
public:
    Map();
    Map(SDL_Renderer* rR);
    ~Map();
    
    void Update();

    void UpdateMinions();
	void UpdateMinionsCollisions();
	void UpdateBlocks();
	void UpdateMinionBlokcs();



    Event* getEvent();

    // Loading
    void resetGameData();
    void setBackgroundColor(SDL_Renderer* rR);
    
};

# endif
