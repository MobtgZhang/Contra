# ifndef MAP_HEADERS
# define MAP_HEADERS

# include<SDL2/SDL.h>
# include<SDL2/SDL_mixer.h>
# include<vector>
class Map{
private:
    float fXpos,fYPos;
public:
    Map();
    Map(SDL_Renderer* rR);
    ~Map();
};

# endif
