#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

using namespace std;
void settextcolor(int color);
int main()
{
    while(1)
    {
    int gnum,rnum;
    settextcolor(8);
    cout<<"Enter any number from 1 to 10 = ";
    cin>>gnum;

    rnum= rand()%10 +1 ;
    if(rnum==gnum)
    {
        //system("Color 0A");
        settextcolor(2);
        cout<<"It matched!!!\n";
    }
    else
    {
        //system("Color 1A");
        settextcolor(5);
        cout<<"Not Matched. Try Again!!\n";
        cout<<"\n";
    }
    }
   
    getch();
}

 void settextcolor(int color)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }