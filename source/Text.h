#pragma once

# ifndef TEXT_H
# define TEXT_H
# include<SDL2/SDL_ttf.h>
# include<string>
# include<iostream>

class Text
{
private:
	int fontSize;

	TTF_Font *ttfFont;
	SDL_Texture* tText;
	SDL_Rect rRect;
public:
	Text(int fontSize=16);
	~Text();
	void Draw(SDL_Renderer* rR, std::string sText, int X, int Y,int iR=255,int iG=255, int iB=255);
	void setFont(int fontSize,std::string fileName="files/fonts/simhei.ttf");

};

#endif
