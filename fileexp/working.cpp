//Roll no - 2018201088
//Name 	  - Anant Rawat
//Course  - M.Tech CSE 1st year

#include "work.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include<vector>
#include<string>
#include<iostream>
#include<sys/stat.h>

using namespace std;

 vector<string> list;
 vector<string> prev_dir;
 vector<string> for_dir;
 vector<string> par_dir;

 string home_dir;
 string current_dir;


int main()
{
		setbuf(stdout,NULL);
	//cout<<"Please enter the root";

current_dir=get_current_dir_name();

//getline(cin,current_dir);
    //current_dir="/home/anant/FileExplorer";
   
    //SETTING NON-CANONICAL
    	current_dir.assign(current_dir.c_str());
home_dir.assign(current_dir.c_str());
    struct termios old_tio, new_tio;
    tcgetattr(fileno(stdin), &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag&=~(ECHO | ICANON);
    tcsetattr(fileno(stdin),TCSANOW,&new_tio);
    access_dir(current_dir);
    pressed();
    

     tcsetattr(fileno(stdin),TCSANOW,&old_tio);
    return 0;
}
