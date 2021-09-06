#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<c:\\tc\\bin\\box.cpp>
#include<c:\\tc\\bin\\UPC.cpp>	
int f1c=0, f1r=0, f2r=0, f2c=0, f3r=0, f3c=0,body=1;
	      int gameover()
	       {
		  delay(400);
		  for(int r=2; r<=23; r++)
		  {
		     for(int c=1; c<=76; c+=15)
		     {
		       gotoxy(c,r); cout<<"               ";
		     }
		     delay(40);
		  }
		  clrscr();
		  int start;
		  char yesno[9];
		  gotoxy(36,13);  cout<<"GAME OVER!!";
		  gotoxy(30,14);  cout<<"Do you want to play again?";
		  gotoxy(36,16);  cout<<"yes or no";
		  gotoxy(40,17);  cin>>yesno;
		  if (strcmp(yesno,"yes")==0) start=1;
		  else if (strcmp(yesno,"no")==0) start=0;
		       else { cout<<"Wrong choice"; start=2; }
		  return start;
		}

	   void start()
	   {
	     clrscr();
	       gotoxy(35,10);  cout<<"WELCOME TO";
	       gotoxy(38,11);  cout<<"SNAKE";
	       gotoxy(60,23);  cout<<"Press any key";
	       getch();
	     clrscr();
		 cout<<endl<<endl<<endl<<"\t\t       RULES OF THE GAME";
		 cout<<endl<<endl<<endl<<"(1) Use the keys 'w' 'a' 's' & 'd' to move the snake ('*')."
		     <<endl<<endl<<"(2) Eat the fruits ('"<<(char)15<<"') to grow and score."
		     <<endl<<endl<<"(3) The snake can't move in opposite direction of its motion \n    or else it will die."
		     <<endl<<endl<<"(4) The snake can not cross the borders."
		     <<endl<<endl<<"(5) The snake can only change direction when the whole body is \n    in a single row or a column.";
	       gotoxy(60,23);  cout<<"Press any key";
	       getch();
	     }

	     void checkfruit(int &c, int &r)
	     {
	       if (c==f1c && r==f1r)
		 {
		   f1c=0; f1r=0; body++;
		   gotoxy(71,4); cout<<body-1;
		 }
		      if (c==f2c && r==f2r)
		       {
			 f2c=0; f2r=0; body++;
			 gotoxy(71,4); cout<<body-1;
			}
	       if (c==f3c && r==f3r)
		 {
		   f3c=0; f3r=0; body++;
		   gotoxy(71,4); cout<<body-1;
		 }
	      }

void main()
{
      int cpu;
      //cpu=upc();
      cpu=1;   
  if(cpu==1)
  {
      start();
      int mstart=1,highscore=1,rr,cc;      //mstart=start in gameover();
    abc:
      while(mstart==1)
  {
      clrscr();
      randomize();
	char move='^',newmove;
	int r, newbody, c; f1c=0; f1r=0; f2r=0; f2c=0; f3r=0; f3c=0;
	box();
	c=random(50)+5;
	r=random(17)+5;

		 if(highscore<body)
		{
		 gotoxy(76,7);
		 cout<<body-1;
		 highscore=body;
		}
		 else
		 {
		  gotoxy(76,7);
		  cout<<highscore-1;
		 }
	gotoxy(c,r);  cout<<"*";
	body=1;
 do
{
      randomize();

     if(f1c==0)
     {
       f1c=random(20)+2;
       f1r=random(10)+10;
       gotoxy(f1c,f1r);  cout<<(char)15;
       gotoxy(c,r);  //to get cursor back to snake
     }
     if(f2c==0)
     {
       f2c=random(20)+10;
       f2r=random(8)+10;
       gotoxy(f2c,f2r); cout<<(char)15;
       gotoxy(c,r);
     }
     if(f3c==0)
     {
       f3c=random(20)+30;
       f3r=random(20)+3;
       gotoxy(f3c,f3r); cout<<(char)15;
       gotoxy(c,r);
     }

     newmove=getch();
     newbody=body;  //to check for any fruit WHILE turning

   switch(newmove)
 {
  case 'w':   if(body>1)
	 {
	      switch(move)
	    {
	      case 's': mstart=gameover();
			goto abc;

	      case 'a': for(int taw=newbody-1; taw>=1; --taw)
			{
			  rr=r-newbody+taw;
			  if (rr>=23 || rr<=2 || c>=60 || c<=1)
			  {
			    mstart=gameover();
			    goto abc;
			  }

			  gotoxy(c+taw,r); cout<<" ";
			  gotoxy(c, rr); cout<<"*";
				  checkfruit(c,rr);
				  delay(150);
			}
			r=r-newbody+1;
			break;
	      case 'd': for(int tdw=newbody-1; tdw>=1; --tdw)
			{
			  rr=r-newbody+tdw;

			  if (r>=23 || r<=2 || c>=60 || c<=1)
			  {
			    mstart=gameover();
			    goto abc;
			  }

			  gotoxy(c-tdw, r); cout<<" ";
			  gotoxy(c,rr); cout<<"*";
			    checkfruit(c,rr);
			    delay(150);
			 }
			 r=r-newbody+1;
			  break;
	     default: cout<<"";
	     }//switch move
	 }//if

	     while(!kbhit())
	    {
			  if (r-1>=23 || r-1<=2 || c>=60 || c<=1)
			  {
			    mstart=gameover();
			    goto abc;
			  }

	       gotoxy(c,r+(body-1)); cout<<" ";
	       gotoxy(c,--r); cout<<"*";
		 delay(150);
		 checkfruit(c,r);
	    }
	     break;
//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
  case 'a':  if(body>1)
	    {
	      switch(move)
	      {
		case 'd': mstart=gameover();
			  goto abc;

		case 's': for(int tsa=newbody-1; tsa>=1; --tsa)
			  {
			    cc=c-newbody+tsa;

			    if (r>=23 || r<=2 || cc>=60 || cc<=1)
			  {
			    mstart=gameover();
			    goto abc;
			  }

			    gotoxy(c,r-tsa); cout<<" ";
			    gotoxy(cc,r); cout<<"*";
			       checkfruit(cc,r);
			       delay(150);
			  }//for
			  c=c-newbody+1;
			  break;

		case 'w': for(int twa=newbody-1; twa>=1; --twa)
			 {
			   cc=c-newbody+twa;

			   if (r>=23 || r<=2 || cc>=60 || cc<=1)
			  {
			    mstart=gameover();
			    goto abc;
			  }

			   gotoxy(c,r+twa); cout<<" ";
			   gotoxy(cc,r); cout<<"*";
			      checkfruit(cc,r);
			      delay(150);
			  }
			   c=c-newbody+1;
			   break;
		default: cout<<""; break;
	      }//switch move
	    }//if body
	    while(!kbhit())
	    {
			    if (r>=23 || r<=2 || c-1>=60 || c-1<=1)
			  {
			    mstart=gameover();
			    goto abc;
			  }
		    gotoxy(c+body-1,r); cout<<" ";
		    gotoxy(--c,r); cout<<"*";
		      delay(150);
		      checkfruit(c,r);
	    }
	    break;
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  case 's': if (body>1)
	   {
	     switch(move)
	     {
	       case 'w': mstart=gameover();
			 goto abc;

	       case 'a': for(int tas=newbody-1; tas>=1; --tas)
			 {
			   rr=r+newbody-tas;

			   if (rr>=23 || rr<=2 || c>=60 || c<=1)
			  {
			    mstart=gameover();
			    goto abc;
			  }

			   gotoxy(c+tas,r); cout<<" ";
			   gotoxy(c, rr); cout<<"*";
			       checkfruit(c,rr);
			       delay(150);
			 }
			  r=r+newbody-1;
			  break;

	       case 'd': for(int tds=newbody-1; tds>=1; --tds)
			 {
			   rr=r+newbody-tds;

			   if (rr>=23 || rr<=2 || c>=60 || c<=1)
			  {
			    mstart=gameover();
			    goto abc;
			  }

			   gotoxy(c-tds,r); cout<<" ";
			   gotoxy(c, rr); cout<<"*";
			       checkfruit(c,rr);
			     delay(150);
			 }
			 r=r+newbody-1;
			 break;
	       default: cout<<"";
	     }//switch move
	   }//if body

	    while(!kbhit())
	   {
		       if (r+1>=23 || r+1<=2 || c>=60 || c<=1)
		      {
			mstart=gameover();
			goto abc;
		      }
	    gotoxy(c,r-body+1); cout<<" ";
	    gotoxy(c,++r); cout<<"*";
	    delay(150);
		    checkfruit(c,r);
	    }
	    break;
//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
   case 'd': if (body>1)
	    {
	      switch(move)
	      {
		case 'a': mstart=gameover();
			  goto abc;
			  //break;
		case 's': for(int tsd=newbody-1; tsd>=1; --tsd)
			  {
			    cc=c+newbody-tsd;

			    if (r>=23 || r<=2 || cc>=60 || cc<=1)
			  {
			    mstart=gameover();
			    goto abc;
			  }

			    gotoxy(c, r-tsd); cout<<" ";
			    gotoxy(cc, r); cout<<"*";
			       checkfruit(cc,r);
			    delay(150);
			  }
			    c=c+newbody-1;
			    break;
		case 'w': for(int twd=newbody-1; twd>=1; --twd)
			  {
			    cc=c+newbody-twd;

			    if (r>=23 || r<=2 || cc>=60 || cc<=1)
			  {
			    mstart=gameover();
			    goto abc;
			  }
			    gotoxy(c,r+twd); cout<<" ";
			    gotoxy(cc,r); cout<<"*";
			      checkfruit(cc,r);
			    delay(150);
			  }
			    c=c+newbody-1;
			    break;
		default: cout<<""; break;
	      }//switch move
	    }//if body

	     while(!kbhit())
	   {
			     if (r>=23 || r<=2 || c>=60 || c<=1)
			  {
			    mstart=gameover();
			    goto abc;
			  }
	    gotoxy(c-body+1,r); cout<<" ";
	    gotoxy(++c,r); cout<<"*";
	    delay(150);
		    checkfruit(c,r);
	   }
	    break;
//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd

  default: gotoxy(c,r); cout<<"*";
	   break;
 }//switch
   move=newmove; // to check the next move and get the effect of turning
//   highscore=body; //check for highscore

 }while(newmove=='w' || newmove=='a' || newmove=='s' || newmove=='d');
  }//mstart while


	    if (mstart==0)
	    {
	      clrscr();
	      gotoxy(35,13);
	      cout<<"THANK YOU!";
	      gotoxy(15,16);
	      cout<<"Try to beat your personal highscore of ";
	      if(highscore>body) cout<<highscore-1;
	      else               cout<<body-1;
	      cout<<" next time!";
	    }

	    else if( mstart==2)
	    {
	      clrscr();
	      gotoxy(35,13);
	      cout<<"WRONG CHOICE!";
	      gotoxy(35,14);
	      cout<<"Enter Again";
	      mstart=gameover();
	      goto abc;
	    }

 }//main if cpu==1

 else  cout<<"";

 getch();
}//end
