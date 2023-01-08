/*
    this->mainWindow = NULL;
    this->screenSurface = NULL;
    this->screen_height = 480;
    this->screen_width = 640;
    if (SDL_Init(SDL_INIT_VIDEO)<0){
        this->GameError(SDL_GetError());
    }else{
        this->mainWindow = SDL_CreateWindow("Contra",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
            this->screen_width,this->screen_height);
        if(this->mainWindow==NULL){
            this->GameError(SDL_GetError());
        }else{
			this->screenSurface = SDL_GetWindowSurface(this->mainWindow);
			SDL_FillRect(this->screenSurface,NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			SDL_UpdateWindowSurface(this->mainWindow);
            SDL_Event e;
            bool quit = false;
            while( quit == false ){
                while(SDL_PollEvent(&e)){
                     if(e.type == SDL_QUIT) quit = true; 
                }
            }
		}
    }*/