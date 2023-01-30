# ifndef PLAYER_HEADERS
# define PLAYER_HEADERS

# include<SDL2/SDL.h>

class Player{
private:
    float fXPos, fYPos;
public:
    Player(SDL_Renderer* rR, float fXPos, float fYPos);
    ~Player();

    void Draw(SDL_Renderer* rR);
    void Update();
    void updateXPos(int iN);
	void updateYPos(int iN);
    
};

# endif
