# include<stdio.h>
# include "debug.h"
Debug::Debug(){
    this->mainWindow = SDL_GL_GetCurrentWindow();
    this->screenSurface = SDL_GetWindowSurface();
    if ((this->err_fp = fopen("error.out","w"))!=NULL){
        this->GameTip("error.out open failed.",SDL_MESSAGEBOX_ERROR);
    }
    if((this->log_fp = fopen("log.out","w"))!=NULL){
        this->GameTip("log.out open failed.",SDL_MESSAGEBOX_ERROR);
    }
}
Debug::~Debug(){
    SDL_DestroyWindow(this->mainWindow);
    SDL_Quit();
    fclose(this->err_fp);
    fclose(this->log_fp);
}
int Debug::GameTip(char* tip_msg,SDL_MessageBoxFlags flag){
    SDL_ShowSimpleMessageBox(flag,"Error",tip_msg,NULL);
    return 0;
}
int Debug::GameTip(double num){
    char*s = new char[20];
    sprintf(s,"%f",num);
    this->GameTip(s,SDL_MESSAGEBOX_INFORMATION);
    delete[]s;
    return 0;
}
int Debug::GameError(char * err_msg){
	fprintf(this->err_fp,"%s\n", err_msg);
	return 0;
}
int Debug::GameLog(char* log_msg){
    fprintf(this->log_fp,"%s\n",log_msg);
    return 0;
}
int Debug::GameLog(double num){
    char*s = new char[20];
    sprintf(s,"%f",num);
    this->GameLog(s);
    delete[]s;
    return 0;
}

