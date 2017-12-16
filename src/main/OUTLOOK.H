
#include"tune.h"
#include"high.h"

// GLOBAL VARIABLES //
int x[4],speed=90,score=0;
char s[5];

// DEFINITION OF FOOD COORDINATES  //
int x2[16] ={90,60,240,360,480,570,580,120,160,250,400,290,340,330,470,320 };
int y2[16] ={130,180,100,80,380,420,290,120,260,400,310,170,190,100,330,220 };
// USER DEFINED FUNCTIONS
void instructions(),refresh(),disclaimer();
int check();
int getkey();
void intro(),playgame(),module(),credits(),options(),page3();
void page2(int ,int,int,int),over();
void highdisp(int),loading();
void outlook()
{
  refresh();
  page3();
  getkey();
  intro();     // MAIN FUNCTION OF HEADER FILE
  getkey();
  instructions();
  getkey();
  clearviewport();
  page2(4,2,2,2);
  x[0] =1;x[1] =x[2]=x[3]=0;
  module();
}
void page2(int a,int b,int c,int d)
{                     // HELPS USER TO CHANGE OPTIONS
     settextjustify(CENTER_TEXT,CENTER_TEXT);
     setcolor(YELLOW);
     settextstyle(TRIPLEX_FONT,0,5);
     outtextxy(getmaxx()/2,textheight("V"),"ANACONDA");
     settextstyle(SANS_SERIF_FONT,0,3);
     setcolor(11);
     outtextxy(getmaxx()/2+10,getmaxy()/2+170,"MAULANA AZAD NATIONAL INSTITUTE OF TECHNOLOGY");
     outtextxy(getmaxx()/2,getmaxy()-textheight("V"),"BHOPAL 462 007");
     setcolor(12);
     settextstyle(TRIPLEX_FONT,0,4);
     rectangle(0,0,getmaxx(),getmaxy());

     setcolor(a);outtextxy(getmaxx()/2,150,"New Game");
     setcolor(b);outtextxy(getmaxx()/2,200,"Options");
     setcolor(c);outtextxy(getmaxx()/2,250,"High Scores");
     setcolor(d);outtextxy(getmaxx()/2,300,"Exit");

  }
void intro()    // A COOL INTRODUCTION
{
    int x,y,i=0;
    clearviewport();
     setcolor(12);
     rectangle(0,0,getmaxx(),getmaxy());
     setcolor(10);
     settextstyle(TRIPLEX_FONT,0,5);
     settextjustify(CENTER_TEXT,CENTER_TEXT);
      x=getmaxx()/2;
      y=getmaxy()/2;

      while(i!=5000)
      {
       putpixel(random(getmaxx()),random(getmaxy()),random(16));
       i++;
      }
     outtextxy(x,y-200,"EXTREME GRAPHICS");
     settextstyle(DEFAULT_FONT,0,1);
     setcolor(MAGENTA);
     outtextxy(x,y-170,"INFORMATION MANAGEMENT GROUP");
     setcolor(RED);
     outtextxy(x,y-100,"Presents");
     settextstyle(GOTHIC_FONT,0,7);
     setcolor(LIGHTBLUE);
     outtextxy(x,y-30,"ANACONDA");
     settextstyle(TRIPLEX_FONT,0,2);
     setcolor(12);
     outtextxy(x,y+50,"The Game of a deadly Snake");
     settextstyle(DEFAULT_FONT,0,1);
     setcolor(10);
     tune(1);
     outtextxy(x,y+200,"Press any key to continue");

}
void credits()
{                    // THE TAILPIECE //
  clearviewport();
  setcolor(RED);
  rectangle(0,0,getmaxx(),getmaxy());
  settextjustify(CENTER_TEXT,CENTER_TEXT);
  settextstyle(3,0,6);
  outtextxy(getmaxx()/2, 50,"CREDITS");
  line(getmaxx()/2-100,85,getmaxx()/2+100,85);
  settextstyle(TRIPLEX_FONT,0,4);
  setcolor(LIGHTRED);
  outtextxy(getmaxx()/2,400,"moksh_walia@yahoo.co.in");
  setcolor(MAGENTA);
  outtextxy(getmaxx()/2,200,"&");
  setcolor(GREEN);
  outtextxy(getmaxx()/2,350,"partha_mact@rediffmail.com");
  setcolor(RED);
  outtextxy(getmaxx()/2,300,"Contact us at :");
  setcolor(YELLOW);
  outtextxy(getmaxx()/2,150,"PARTHA PRATIM SANYAL");
  setcolor(LIGHTGREEN);
  outtextxy(getmaxx()/2,250,"MOKSH WALIA ");
  setcolor(CYAN);
  outtextxy(getmaxx()/2,450,"3rd yr IT , MANIT Bhopal 462007");
  setcolor(LIGHTBLUE);
  outtextxy(150,100,"Coding by :");
  tune(2);
  getkey();
  closegraph();
  exit(0);
}
void page3()                /* TO PRINT THE TITLE OF THE GAME */
{
	int i,j;
	setcolor(GREEN);
	settextstyle(TRIPLEX_FONT,0,4);
	outtextxy(getmaxx()/2-230,getmaxy()/2-50,"Press any key to continue.....");
	getkey();
	disclaimer();
	clearviewport();
	settextstyle(0,0,1);
	for(i=0;i<=1000;i++)
	putpixel(random(640),random(450),random(16));
	for(i=0,j=500;i<=250;i+=5,j-=5)
	{
		settextstyle(1,0,7);
		setcolor(10);
		outtextxy(i,150,"A A O D");
		outtextxy(j,150," N C N A");
		setcolor(0);
		sound(200+j*10);
		delay(10);
		outtextxy(i,150,"A A O D");
		outtextxy(j,150," N C N A");
	}
	setcolor(RED);
	ellipse(getmaxx()/2,getmaxy()/2,0,360,300,200);

	setcolor(10);
	settextstyle(1,0,7);
	nosound();
	outtextxy(j-70,150,"ANACONDA");
	settextstyle(1,0,2);
	setcolor(RED);
	for(i=340,j=340;i<=495;i+=5,j-=5)
	{
		outtextxy(i-10,240,"*");
		outtextxy(j-10,240,"*");
		delay(20);
	}
	outtextxy(j-10,240,"*");
 }
void module()
{
 while(1)
 {
 int key,i; //   TAKES USER INPUT  AS SHE SURFS THROUGH THE CHOICES PROVIDED
 fflush(stdin);
 key = getkey();
 switch(key)
 {
  case 72: i = check();
	   if((i==0)||(i==1)){ page2(4,2,2,2); x[0] =1;x[1] =x[2] =x[3] =0;}
	   if(i==2) { page2(2,4,2,2);x[1] = 1; x[0] = x[2] =x[3] =0; }
	   if(i==3) { page2(2,2,4,2);x[2] = 1; x[0] = x[1] =x[3] = 0;}
	   break;
  case 80: i = check();
	   if(i==0){ page2(2,4,2,2);x[1] = 1; x[0] = x[2] =x[3] =0; }
	   if(i==1){ page2(2,2,4,2);x[2] = 1; x[0] = x[1] =x[3] = 0;}
	   if((i==2)||(i==3)) { page2(2,2,2,4);x[0] = x[1] =x[2] =0; x[3] = 1;}
	   break;
  case 28: i = check();
	   if(i==0) playgame();
	   if(i==3) credits();
	   if(i==2)
	   {
	    int high=highscore(0);
	    highdisp(high);
	    page2(4,2,2,2);x[0]=1;
	    x[1]=x[2]=x[3]=0;
	   }
	   if(i==1) options();
	   break;
  case 1 : credits();
 }
 }
}
int check()
{
 int i;     // CHECKS WHERE THE USER DEFINED CHOICE IS AT PRESENT //
 for(i=0;i<4;i++)
 {
  if(x[i]==1)
  return(i);
 }
 return(0);
}
void options()
{
 int ch;        // OPTION OF SPEED //
 char u[6];
 clearviewport();
 setcolor(RED);

 rectangle(0,0,getmaxx(),getmaxy());

 settextjustify(CENTER_TEXT,CENTER_TEXT);
 settextstyle(3,0,3);
 setcolor(GREEN);
 outtextxy(getmaxx()/2,200,"LEVELS - 1 TO 5 Please Enter Your choice");
 fflush(stdout);
 gotoxy(40,20);
 scanf("%d",&ch);

 switch(ch)
 {
  case 1:speed = 90;
	 break;
  case 2:speed = 75;
	 break ;
  case 3:speed = 60;
	 break ;
  case 4:speed = 50;
	 break ;
  case 5:speed = 35;
	 break ;
  default : speed = 90;
 }
 x[0]=1;x[1]=x[2]=x[3]=0;
 clearviewport();
 page2(4,2,2,2);
 module();
}
int getkey()    // FUNCTION WHICH RETURNS THE SCAN CODE OF THE KEY HIT//
{
 union REGS i,o;
 while(!kbhit())
     ;
 i.h.ah = 0;
 int86(22,&i,&o);
 return(o.h.ah);
}
void over()
{
 sound(700);
 delay(500);
 nosound();              // GAME OVER , DISPLAYS SCORE
 getkey();
 clearviewport();
 setcolor(LIGHTRED);
 rectangle(0,0,getmaxx(),getmaxy());
 settextjustify(CENTER_TEXT,CENTER_TEXT);
 setcolor(RED);
 settextstyle(4,0,6);
 outtextxy(getmaxx()/2,getmaxy()/2-40,"GAME OVER");
 settextstyle(DEFAULT_FONT,0,2);
 setcolor(GREEN);
 outtextxy(getmaxx()/2,getmaxy()/2+20,"YOUR SCORE");
 itoa(score,s,10);
 outtextxy(getmaxx()/2,getmaxy()/2+60,s);
 settextstyle(SANS_SERIF_FONT,0,3);
 setcolor(MAGENTA);
 if(score==highscore(score))
 outtextxy(getmaxx()/2+10,getmaxy()/2+80,"THIS IS THE HIGHEST SCORE TILL NOW");
 getkey();
 refresh();
  x[0] =1;x[1] =x[2]=x[3]=0;
  speed = 80;
  page2(4,2,2,2);
  module();
}
void highdisp(int high)
{                          // DISPLAYS THE UPTODATE HIGHEST SCORE //
 clearviewport();
 setcolor(LIGHTRED);
 rectangle(0,0,getmaxx(),getmaxy());
 setcolor(CYAN);
 outtextxy(getmaxx()/2-10,getmaxy()/2-40,"HIGHEST SCORE");
 settextstyle(TRIPLEX_FONT,0,5);
 setcolor(RED);
 itoa(high,s,10);
 outtextxy(getmaxx()/2-10,getmaxy()/2,s);
 getkey();
 refresh();
 return;
}
void instructions()
{                     // INSTRUCTION HOW TO PLAY THE GAME //
 clearviewport();
 setcolor(LIGHTRED);
 rectangle(0,0,getmaxx(),getmaxy());
 settextstyle(SANS_SERIF_FONT,0,3);
 settextjustify(LEFT_TEXT,CENTER_TEXT);
 setcolor(LIGHTRED);
 outtextxy(40,80,"CONTROLS :-");
 setcolor(GREEN);
 outtextxy(40,120,"# USE ARROY KEYS TO SELECT AN OPTION ");
 outtextxy(40,160,"  FROM MENU AND PRESS ENTER.");
 setcolor(MAGENTA);
 outtextxy(40,200,"# ARROW KEYS ARE ALSO MEANT FOR ");
 outtextxy(40,240,"  SNAKE NAVIGATION.");
 setcolor(CYAN);
 outtextxy(40,280,"# THE SNAKE ENHANCES ITS BODY BY ");
 outtextxy(40,320,"  TWO BITS WHEN IT EATS A GREEN BIT." );
 setcolor(RED);
 outtextxy(40,360,"# THE BLUE BITS ARE HURDLES,NEVER TOUCH THEM !");
 setcolor(YELLOW);
 outtextxy(40,400,"  ENJOY THE GAME , PRESS ENTER TO CONTINUE.");
}
void refresh()
{
 int gd = DETECT,gm;        // TO REFRESH THE SCREEN
 closegraph();
 initgraph(&gd,&gm,"C:\\TC\\BGI");
}
void loading()
{                   // A SIMULATION OF LOADING SEQUENCE //
 clearviewport();
 setcolor(LIGHTRED);
 rectangle(0,0,getmaxx(),getmaxy());
 settextstyle(TRIPLEX_FONT,0,6);
 settextjustify(CENTER_TEXT,CENTER_TEXT);
 setcolor(YELLOW);
 outtextxy(getmaxx()/2,getmaxy()/2-70,"LOADING.......");
 setcolor(MAGENTA);
 outtextxy(getmaxx()/2,getmaxy()/2,"Please wait");
 setcolor(GREEN);
 rectangle(220,320,420,350);
 rectangle(216,317,424,354);
 setcolor(BLUE);
 rectangle(218,318,422,352);
 setcolor(RED);
 for(int i=0;i<199;i++)
 {
  line(221+i,321,221+i,349);
  delay(10);
 }
}
void disclaimer()
{
 FILE * fp;
 char st[56];
 int i=40,k;
 fp = fopen("readme~1.txt","r");
 clearviewport();
 randomize();
 settextstyle(TRIPLEX_FONT,0,2);
 while(fgets(st,55,fp)!=NULL)
 {
  setcolor(LIGHTRED);
  rectangle(0,0,getmaxx(),getmaxy());
  k = random(15);
  if((k!=0)&&(k!=1)&&(k!=7)&&(k!=8))
  setcolor(k);
  outtextxy(20,i,st);
  i+=20;
  if(i==440)
  {
   setcolor(YELLOW);
   settextstyle(GOTHIC_FONT,0,4);
   outtextxy(300,i,"Press Enter to continue......");
   i = 0;
   getkey();
   clearviewport();
   settextstyle(TRIPLEX_FONT,0,2);
  }
 }
 outtextxy(20,i+40,"Press any key to continue...");
 getkey();
 fclose(fp);
}