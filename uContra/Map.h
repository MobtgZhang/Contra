# ifndef MAP_HEADERS
# define MAP_HEADERS

# include<SDL2/SDL.h>
# include<SDL2/SDL_mixer.h>
# include<vector>
class Map{
private:
    float fXpos,fYPos;

    void load_Jungle(); // 第一关
    void load_MazeBase1(); // 第二关
    void load_WaterFall(); // 第三关
    void load_MazeBase2(); // 第四关
    void load_SnowField(); // 第五关
    void load_EnergyZone(); // 第六关
    void load_Hangar(); // 第七关
    void load_AlienLair(); //第八关


public:
    Map();
    Map(SDL_Renderer* rR);
    ~Map();
};

# endif
