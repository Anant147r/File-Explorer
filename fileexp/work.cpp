//Roll no - 2018201088
//Name 	  - Anant Rawat
//Course  - M.Tech CSE 1st year

#include "work.h"
extern vector<string> list;
extern vector<string> prev_dir;
extern vector<string> for_dir;
extern vector<string> par_dir;

extern string home_dir;
extern string current_dir;
void gotoxy(int x,int y)
{
printf("\033[%d;%df",y,x);
}

void access_dir(string dir_to_access)
{
	    

    list.clear();
	string str;
	
	DIR* a;
	struct dirent*p;
	a=opendir( dir_to_access.c_str());
		printf("\033[2J");
		printf("\033[0;0f");
	
	printf("          *****************************************************FILE EXPLORER************************************************\n\n\n");	
	
		
	printf("          DIRECTORY --->  %s\n\n",dir_to_access.c_str());	
	
	
	if(a==NULL)
	{
	printf("\n DIRECTORY DO NOT EXIST\n");
	printf("EITHER PRESS 'h' TO GO TO HOME OR AGAIN ENTER THE DIRECTORY");
	return;
	}	
	else
	{
	printf("\033[10C%s\r","NAME");
	printf("\033[30C%s\r","PERMISSIONS");
	printf("\033[80C%s\r","SIZE");
	printf("\n\n\n");

	while((p=readdir(a)) !=NULL)
      	{

             printf("\033[10C%s\r",p->d_name);
             
             
                
                 struct stat sbuf;
                 stat (p->d_name,&sbuf);
		
    printf( "\033[30C%s\r",(S_ISDIR(sbuf.st_mode)) ? "d" : "-");
    printf( "\033[31C%s\r",(sbuf.st_mode & S_IRUSR) ? "r" : "-");
    printf( "\033[32C%s\r",(sbuf.st_mode & S_IWUSR) ? "w" : "-");
    printf( "\033[33C%s\r",(sbuf.st_mode & S_IXUSR) ? "x" : "-");
    printf( "\033[34C%s\r",(sbuf.st_mode & S_IRGRP) ? "r" : "-");
    printf( "\033[35C%s\r",(sbuf.st_mode & S_IWGRP) ? "w" : "-");
    printf( "\033[36C%s\r",(sbuf.st_mode & S_IXGRP) ? "x" : "-");
    printf( "\033[37C%s\r",(sbuf.st_mode & S_IROTH) ? "r" : "-");
    printf( "\033[38C%s\r",(sbuf.st_mode & S_IWOTH) ? "w" : "-");
    printf( "\033[39C%s\r",(sbuf.st_mode & S_IXOTH) ? "x" : "-");
                  //Print the size
               printf("\033[80C %ld\r ",sbuf.st_size);
                        //Print the date and time of last modified
              printf("\033[100C %s\r",ctime(&sbuf.st_ctime));
		list.push_back(p->d_name);
        }    
gotoxy(0,9);
	current_dir.assign(dir_to_access.c_str());
	gotoxy(0,36);
	printf("1.goto <directory_name>   2.delete <file_path>  3.create <file_name> <file_path>  4.rename <old_file_path> <new_file_name>");
	gotoxy(0,9);
	closedir(a);
         }   
}







void gotoc()
{
char c[3];

string str,str2,str3;
int i=1,k=0,len;
str+="g";
printf("g");
read(0,c,3);

if(c[0]==27)
{
gotoxy(0,9);
return;
}
if(c[0]==127)
{
gotoxy(0,38);
printf("ENTER THE CCOMMAND AGAIN");
return ;
}
while(1)
{	
	write(1,c,3);
	i++;
	str+=c;
	if((i==4)&&(str.compare("goto")!=0))
	{
		gotoxy(0,38);
		str=" ";
	}
	else if((c[0]==32)&&(i>=4))
	{
		k=1;
	}
	if((k==1)&&(c[0]!=32))
	{
		str2=str2+c;
	}
	read(0,c,3);
	if(c[0]==127)
	{
		gotoxy(0,38);
		printf("ENTER THE COMMAND AGAIN");
		return;
	}

	if(c[0]=='\n')
	break;
	else if(c[0]==27)
	{
	gotoxy(0,9);
	return;
	}
}
len=str2.size();
if(len==5)
gotoxy(0,7);
str3=str2.substr(0,len);
prev_dir.push_back(current_dir);
access_dir(str3);
gotoxy(0,9);

}


void r()
{
	
	char c[3];
	printf("d");
	string str1;
	read(0,c,3);
	if(c[0]==27)
	{
		gotoxy(0,9);
		return; 			
	}		
	else if(c[0]=='e')
	{
		printf("e");
		read(0,c,3);
		if(c[0]==27)
		{
			gotoxy(0,9);
			return;
		}
		while(c[0]!='\n')
		{
			if(c[0]==27)
			{
				gotoxy(0,9);
				return;
			}
			else if(c[0]==32)
			{	
				write(1,c,3);
				read(0,c,3);
				continue;
			}
			else
			{	
				write(1,c,3);
				str1+=c;
				read(0,c,3);				
			}		
		}		


	}
	gotoxy(0,38);
	str1=str1.substr(4,str1.size()-4);
	cout<<str1;
	char *ch = const_cast<char*>(str1.c_str());
	int k=remove(ch);
	if(k==0)
	{
		gotoxy(0,38);
		printf("\033[2K");
		printf("FILE REMOVED");
		gotoxy(0,9);
		return;
	}
	else 
	{
		gotoxy(0,38);
		printf("\033[2K");
		printf("FILE DO NOT EXIST");
		gotoxy(0,9);	
	}
}

void rename()
{
	string str1,str2,str3,str4;
	char c[3];
	printf("r");
	str1+="c";
	read(0,c,3);
	if(c[0]==27)
	{
		gotoxy(0,9);
		return;
	}
	while(c[0]!=32)
	{
		write(1,c,3);
		str1+=c;
		read(0,c,3);
		if(c[0]==27)
		{
			gotoxy(0,9);
			return;
		}
		
	}
	write(1,c,3);
			read(0,c,3);
		if(c[0]==27)
		{
			gotoxy(0,9);
			return;
		}
		while(c[0]!=32)
		{
			write(1,c,3);
			str2+=c;
			read(0,c,3);
			if(c[0]==27)
			{
				gotoxy(0,9);
				return;
			}				
		}
		write(1,c,3);
		read(0,c,3);
		if(c[0]==27)
		{
			gotoxy(0,9);
			return;
		}		
		while(c[0]!='\n')
		{
			str3+=c;
			write(1,c,3);
			read(0,c,3);
			if(c[0]==27)
			{	
				gotoxy(0,9);
				return;
			}	
		}
	int i,l;
	l=str2.size();
	for(i=l-1;i>=0;i--)
	{
		if(str2[i]=='/')
		break;	
	}
	str4=str2.substr(0,i+1);
	str4=str4+str3;
	
	char *ch1 = const_cast<char*>(str2.c_str());
	char *ch2 = const_cast<char*>(str4.c_str());
	int result=rename(ch1,ch2);
	if(result==0)
	{
		printf("\033[2K");
		gotoxy(0,38);
		printf("RENAMED");
		gotoxy(0,9);
		return;
	}
	else
	{
		printf("\033[2K");
		gotoxy(0,38);
		printf("NOT RENAMED");
		gotoxy(0,9);
		return;
	}
}

void make_dir()
{
	string str1,file,str2;
	char c[3];
	read(0,c,3);
	while(c[0]!=32)
	{
		if(c[0]==27)
		{
			gotoxy(0,9);
			return;
		}		
		write(1,c,3);
		read(0,c,3);
	}
	write(1,c,3);
	read(0,c,3);
	while(c[0]!=32)
	{
		if(c[0]==27)
		{
			gotoxy(0,9);
			return;	
		}
		write(1,c,3);
		file+=c;
		read(0,c,3);
	}
	write(1,c,3);
	read(0,c,3);
	while(c[0]!='\n')
		{
			if(c[0]==27)
			{
				gotoxy(0,9);
				return;
			}
			else
			{	
				write(1,c,3);
				str1+=c;
				read(0,c,3);				
			}		
		}
str2=str1+"/"+file;
char *ch = const_cast<char*>(str2.c_str());
int k,i,flag=0;
k=file.size();
for(i=0;i<k;i++)
{
	if(file[i]=='.')
	{
		flag=1;
		break;		
	}
}
if(flag==0)
{
	
	if(!mkdir(ch, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH))
	{
		printf("Created");	
	}
	else
	printf("Not Created");
}

else
{
	int fd=open(ch,O_CREAT + O_WRONLY,0644);
	if(fd==-1)
	printf("Unable to create file");
	else
	printf("FIle created");	
}

gotoxy(0,9);
}

void check_for_dir (string dir_to_be_accessed) {
    int status,t=0;
    struct stat st_buf;
	string xd="xdg-open";
	string fto;
   
    status = stat (dir_to_be_accessed.c_str(), &st_buf);
   
    if (S_ISREG (st_buf.st_mode)) {
	
	fto=xd+" "+dir_to_be_accessed;
	system(fto.c_str());
	access_dir(current_dir);
t=1;	  
}	
if (S_ISDIR (st_buf.st_mode)&&(t!=1)) {

	access_dir(dir_to_be_accessed);  
}

}


void call_dir(int pos,string gained_dir)
{
    string dir_to_be_accessed;
    prev_dir.push_back(current_dir);    
    dir_to_be_accessed=gained_dir+"/"+list[pos];
	check_for_dir(dir_to_be_accessed);
     
}



void pressed()
{
int pos=0;
    string temp;
    char c[3];

	
	read(0,c,3);
    while(1)
    {
        
        if(c[2]=='A')
        {		
	if(pos>0)
	{
	    write(1,c,3);
		
            pos--;
	}        
	}
        else if(c[2]=='B')
        {
	if(pos<list.size()-1)	 
	{
	   write(1,c,3);
	   
            pos++;
        }
	} 
       
        else if(c[0]=='\n')
        {
		
            call_dir(pos,current_dir);
		pos=0;
	}	
	else if(c[2]=='D')        
	{
	if(prev_dir.size()!=0)
	{	
            for_dir.push_back(current_dir);
            current_dir.assign(prev_dir[prev_dir.size()-1]);
            prev_dir.pop_back();
            access_dir(current_dir);
		pos=0;
	}        
}
	else if(c[2]=='C')        
	{
	if(for_dir.size()!=0)
	{
            prev_dir.push_back(current_dir);
            current_dir.assign(for_dir[for_dir.size()-1]);
            for_dir.pop_back();
            access_dir(current_dir);
		pos=0;;
        }}
	
	else if(c[0]=='h')
	{	
		string s;
		s.assign(home_dir);
	  	  prev_dir.push_back(current_dir);
	    
		access_dir(s);
		pos=0;	

	}
	else if(c[0]==127)
	{
	int i=0;
	int l=home_dir.size();
	l--;
	int cur=current_dir.size();
	cur--;
	while(home_dir[l]!='/')
	{
		
		if(home_dir[l]==current_dir[cur])
		{			
			l--;
			cur--;
		}		
		else break;
	}
	
	if(home_dir[l]=='/')
	{
		gotoxy(0,9);
		c[0] = c[1] = c[2] = '\0';
		read(0,c,3);
		continue;
	}
	else
	{	
	for(i=0;i<list.size();i++)
	{

		if(list[i].compare("..")==0)
		{
		prev_dir.push_back(current_dir);		
		access_dir(current_dir+"/"+list[i]);
		pos=0;
		break;
		}
	}
	}
	
	}
	else if(c[0]==':')
	{
	
	gotoxy(0,38);
	printf("\033[2K");
	
	read(0,c,3);
	if(c[0]=='g')	
	gotoc();
	else if(c[0]=='d')
	r();	
	
	else if(c[0]=='r')
	rename();		

	else if(c[0]=='c')
	{
		gotoxy(0,38);
		write(1,c,3);
		make_dir();
	}
	
	else
	printf("NO SUCH COMMAND IN THE MODE"); 
	pos=0;
	gotoxy(0,9);
	}
	
	else if((c[0]==27)&&(c[2]=='\0'))
		gotoxy(0,9);

	c[0] = c[1] = c[2] = '\0';
	read(0,c,3);
    }
}

