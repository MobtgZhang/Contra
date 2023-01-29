# ifndef TEXT_HEADERS
# define TEXT_HEADERS

# include "Img.h"

class Text{
private:
    CImg* FONT;
    
    SDL_Rect rCrop;
    SDL_Rect rRect;

    int fontSize;
    int extraLeft,nextExtraLeft;

    int getPos(int iChar);
    void checkExtra(int iChar);
public:
    Text();
    ~Text();

    void Draw(SDL_Renderer* rR, std::string sText, int X, int Y, int fontSize = 16);
	void Draw(SDL_Renderer* rR, std::string sText, int X, int Y, int fontSize, int iR, int iG, int iB);
	void DrawCenterX(SDL_Renderer* rR, std::string sText, int Y, int fontSize = 16, int iR = 255, int iG = 255, int iB = 255);
	void Draw(SDL_Renderer* rR, std::string sText, int X, int Y, int iWidth, int iHeight);
	void DrawWS(SDL_Renderer* rR, std::string sText, int X, int Y,int iR, int iG, int iB, int fontSize = 16);

	int getTextWidth(std::string sText, int fontSize = 16);

	// ----- SET FONT IMG
	void setFont(SDL_Renderer* rR, std::string fileName);
    
};

# endif
