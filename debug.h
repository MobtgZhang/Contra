# ifndef DEBUG_H
# define DEBUG_H
# include<stdio.h>
class Debug{
public:
    Debug();
    ~Debug();
    int GameError(char* err_msg);
    int GameLog(char* log_msg);
    int GameLog(double num);
    int GameTip(char* tip_msg);
    int GameTip(double num);
private:
    FILE*log_fp;
    FILE*err_fp;
};
extern Debug debug;
# endif

