//Roll no - 2018201088
//Name 	  - Anant Rawat
//Course  - M.Tech CSE 1st year

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include<vector>
#include<string>
#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
using namespace std;
void gotoxy(int x,int y);
void access_dir(string dir_to_acess);
void gotoc();
void r();
void rename();
void make_dir();
void check_for_dir(string dir_to_be_accessed);
void call_dir(int pos,string gained_dir);
void pressed();
 
