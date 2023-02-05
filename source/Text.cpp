# include "Text.h"

Text::Text(int fontSize){
	this->fontSize = 128;

	if (TTF_Init() != 0){
		std::cout<<"Error for initialize the fonts! Error: "<<SDL_GetError() <<std::endl;
	}
	// 打开字体库
    ttfFont = TTF_OpenFont("files/fonts/simhei.ttf", fontSize);
    if (ttfFont == 0){
		std::cout<<"Open TTF file failed! Error: "<<SDL_GetError() <<std::endl;
	}

}
Text::~Text(){
	if (ttfFont!=NULL){ 
		TTF_CloseFont(ttfFont); 
	    ttfFont = nullptr;
	}
	TTF_Quit();
}

void Text::Draw(SDL_Renderer* rR, std::string sText, int X, int Y,int iR,int iG, int iB){
	auto color = SDL_Color{ 
			(unsigned char)iR,
			(unsigned char)iG,
			(unsigned char)iB,
			255 
	};
    SDL_Surface *sdlSurface = TTF_RenderText_Blended(ttfFont,sText.c_str(),color);
    tText = SDL_CreateTextureFromSurface(rR, sdlSurface);

    SDL_QueryTexture(tText, NULL, NULL, &rRect.w, &rRect.h);
	rRect.x = X;rRect.y = Y;
	SDL_RenderCopy(rR,tText,NULL,&rRect);
}

void Text::setFont(int fontSize,std::string fileName){
	if (ttfFont!=NULL){ 
		TTF_CloseFont(ttfFont); 
	    ttfFont = TTF_OpenFont(fileName.c_str(), fontSize);
	}
}

