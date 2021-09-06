/*#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main()         */
int upc()
{
    clrscr();
    randomize();
    int u, p, upc=2;
    char user[20], pass[20], cap, captcha[4], cent[6];
    gotoxy(30,10);
    cout<<"Enter Username: ";
    gets(user);

    gotoxy(30,11);
    cout<<"Enter password: ";
     int c=0;
     do
     {
       gotoxy(46+c,11);
       pass[c]=getch();
       cout<<"*";
       c++;
     } while(c<=7) ;
    pass[8]='\0';
    getch();

    u=strcmp(user,"rahul444");
    p=strcmp(pass,"rahul444");

    if (u!=0 || p!=0)
    {
      clrscr();
      cout<<"ACCESS DENIED";
      upc=0;
    }
    else if(u==0 && p==0)
    {
       for(int a=0; a<4;)
       {
	 cap=(char)random(123);
	 if( (cap>='A'&&cap<='Z')||(cap>='a'&&cap<='z')||(cap>='0'&&cap<='9') )
	 {
	   captcha[a]=cap;
	   a++;
	 }
       }//for

       captcha[4]='\0';

       gotoxy(40,15);
       cout<<captcha;
       gotoxy(25,16);
       cout<<"Enter captcha code to verify: ";
       gotoxy(55,16);
       gets(cent);

	  if(strcmp(captcha, cent)==0)
	  {
	     clrscr();
	     cout<<"ACCESS GRANTED";
	     cout<<"\nPress any key to continue";
	     getch();
	     upc=1;
	  }

	  else
	  {
	     clrscr();
	     cout<<"ACCESS DENIED";
	     cout<<"\nPress any key to exit";
	     getch();
	     upc=0;
	  }


     }//if u=0 p=0

     return upc;
}



