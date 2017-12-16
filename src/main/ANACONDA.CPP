/*                                                                         */
/*	 		      ANACONDA  (GAME)                              */
/*                                                                         */
/*	 		COPYRIGHT (C) 2003 and beyond  BY  Partha Pratim Sanyal       */
/*                      B.E(INFORMATION TECHNOLOGY)  IIIrd YR              */
/*	   FOR SUGGESTIONS contact me at partha_mact@rediffmail.com	   */
/*                                                                         */

       // INCLUDE LIBRARIES (ONLY USER DEFINED LIBRARY FILE )//

#include"outlook.h"
// THE SNAKE BODY STRUCTURE //
struct snake
	{
	 int x[150],y[150];
	} bug ;

// GLOBAL VARIABLES //
int part,m ,n ; // PART : SEGMENTS OF SNAKE BODY ,M,N: COOR OF HEAD OF SNAKE
int count; // COUNTS THE TIME TILL WHICH THE FOOD STAYS ON BOARD
int l,r,u,d;// FLAGS TO DETERMINE IN WHICH DIR SNAKE IS MOVING
int x1[10] ={ 40,220,70,460,560,390,420,490,250,540 }; //
int y1[10] ={ 250,340,140,60,90,290,370,200,150,210 }; //  HURDLES
int z[2]   ={ 300,300};  // FOOD COORDINATES //

// USER DEFINED FUNCTIONS //
int check1(),eat(),check2(),check3();
void control(),up(),down(),left(),right(),see();
inline void fill(int ,int ,int);
void define(int,int),showblock(),increase(),provide(int);
void food(),counter();

void main()
{
 outlook();
}
void playgame()
{
 loading();
 int i;
 score = 0;
 m = n = 30;
 count = 50;
 part = 5;
 randomize();
 clearviewport();
 setcolor(RED);
 setfillstyle(SOLID_FILL,RED);
 rectangle(0,0,getmaxx(),getmaxy());
 rectangle(20,20,getmaxx()-20,getmaxy()-20);
 floodfill(5,5,RED);
 setcolor(GREEN);
 settextstyle(SANS_SERIF_FONT,0,2);
 outtextxy(getmaxx()/2,10,"ANACONDA");
 settextstyle(TRIPLEX_FONT,0,1);
 outtextxy(300,467,"DESIGNED BY PARTHA PRATIM SANYAL");
 setcolor(BLUE);
 itoa(score,s,10);
 setcolor(BLUE);
 outtextxy(520,467,"SCORE");
 outtextxy(580,467,s);
 for(i=0;i<part;i++)
 {
  bug.x[i] = m;
  bug.y[i] = n;
  fill(bug.x[i],bug.y[i],RED);
  n+=10;
 }
 n-=10;
 showblock();
 while(!kbhit())
     ;
 l=0, r=0, u =0, d =1;
 down();
 control();
}
inline void fill(int a,int b,int col)
{
  setcolor(col);           // BITWISE FILLUP OF SNAKE BODY //
  setfillstyle(SOLID_FILL,col);
  circle(a,b,5);
  floodfill(a,b,col);
}
void define(int e,int f)
{
		       // DEFINING THE NEW POSITION OF THE SNAKE BODY
 for(int i=0;i<part-1;i++)
 {
   bug.x[i] = bug.x[i+1];
   bug.y[i] = bug.y[i+1];
 }
  bug.x[i] =e;bug.y[i]=f;
}
void control()
{
 while(1)
 {
  int key = 0;
  key = getkey();  // CONTROL WHICH TAKES USER RESPONSE
  counter();
  switch(key)
  {
   case 72:if(d ==1)
	    down();
	   else
	    up();
	   break;
   case 80:if(u==1)
	    up();
	   else                     // 72 up |80 down |75 left| 77 right
	    down();
	   break;
   case 75:if(r==1)
	    right();
	   else
	    left();
	   break;
   case 77:if(l==1)
	    left();
	   else
	    right();
	   break;
   case 1: over();
   default : if(l) left();
	     if(u) up();
	     if(r) right();
	     if(d) down();
  }
 }
}
void up()
{

  while(!kbhit())
	   {
	    u =1;l=r=d=0;
	    counter();    // GOING UP
	    count++;
	    see();
	    if(check1()&&check2())
	    {
	     if(n==30)
	     n = 460;
	     fill(bug.x[0],bug.y[0],BLACK);
	     define(m,n-=10);
	     fill(m,n,RED);
	     delay(speed);
	    }
	    else over();
	  }
}
void down()
{

  while(!kbhit())
	   {
	     d = 1; l=r=u=0;
	    counter();
	    count++;
	    see();                // GOING DOWN
	    if(check1()&&check2())
	    {
	     if(n==450)
	     n = 20;
	     fill(bug.x[0],bug.y[0],BLACK);
	     define(m,n+=10);
	     fill(m,n,RED);
	     delay(speed);
	    }
	    else over();
	   }
}
void left()
{

  while(!kbhit())
	   {
	     l = 1; r=u=d=0;
	    counter();
	    count++;
	    see();           // GOING LEFT
	    if(check1()&&check2())
	    {
	     if(m==30)
	     m = 620;
	     fill(bug.x[0],bug.y[0],BLACK);
	     define(m-=10,n);
	     fill(m,n,RED);
	     delay(speed);
	    }
	    else over();
	   }
}
void right()
{

   while(!kbhit())
	   {
	      r = 1; l=u=d=0;
	    counter();
	    count++;
	    see();
	    if(check1()&&check2())   // GOING RIGHT
	    {
	     if(m==610)
	     m = 20;
	     fill(bug.x[0],bug.y[0],BLACK);
	     define(m+=10,n);
	     fill(m,n,RED);
	     delay(speed);
	    }
	    else over();
	   }
}
int check1()
{
 for(int i=0;i<10;i++)
 {
  if(  (abs(m-x1[i])<=9 ) &&(abs(n-y1[i])<=9) )
  {                   // CHECKS WHETHER THE SNAKE MEETS A HURDLE//
    fill(m,n,MAGENTA);
    return(0);
  }
  if(  (abs(n-y1[i])<=9 )&&(abs(m-x1[i])<=9) )
  {
    fill(m,n,MAGENTA);
    return(0);
  }
 }
 return(1);
}
void showblock()
{
  for(int i=0;i<10;i++)        // SHOWS THE HURDLES ON THE SCREEN
  fill(x1[i],y1[i],BLUE);
}
void food()
{
  z[0] = x2[rand()%16];
  z[1] = y2[rand()%16];     // SHOWS THE FOOD ON THE SCREEN
  if( (check3() )&&(z[0]!=0) )
    fill(z[0],z[1],GREEN);
  else
    food();
}
int eat()
{
 int o,p;
 o = abs(m-z[0]);
 p = abs(n-z[1]);
 if( (o<=9)&&(p<=9))           // CHECKS WHETHER SNAKE EATS THE FOOD
 return(1);
 else return(0);
}
void increase()
{
   int i=part;
   part+=2;
   if(l==1)
   {
    if(m<=50)           // INCREASES THE BODY OF THE SNAKE BY TWO BITS
    m = 610;
    m-=10;                  // WHEN THE SNAKE WAS MOVING LEFT
    bug.x[i]=m;
    fill(m,n,RED);
    m-=10;
    bug.x[i+1]=m;
    bug.y[i]=bug.y[i+1] = n;
   }
   if(r==1)
   {
    if(m>=590)
    m = 30;              // WHEN IT WAS MOVING RIGHT
    m+=10;
    bug.x[i]=m;
    fill(m,n,RED);
    m+=10;
    bug.x[i+1]=m;
    bug.y[i]=bug.y[i+1] = n;
   }
   if(u==1)
   {
    if(n<=30)
    n = 450;
    n-=10;            // WHEN IT WAS MOVING UP
    bug.y[i]=n;
    fill(m,n,RED);
    n-=10;
    bug.y[i+1]=n;
    bug.x[i]=bug.x[i+1] = m;
   }
   if(d==1)
   {
     if(n>=430)
     n = 30;
    n+=10;
    bug.y[i]=n;       // WHEN IT WAS MOVING DOWN
    fill(m,n,RED);
    n+=10;
    bug.y[i+1]=n;
    bug.x[i]=bug.x[i+1] = m;
   }
  fill(m,n,RED);
}
void provide(int col)
{
  fill(z[0],z[1],col); // PROVIDE FOOD
  count = 0;
  food();
}
void see()
{
 if(eat())
  {	// WHEN THE SNAKE EATS THE FOOD
    switch(speed)
    {
     case 90 :score+=100; break;
     case 75 :score+=200; break;
     case 60 :score+=300; break;
     case 50 :score+=400; break;
     case 35 :score+=500; break;
     default :score+=100; break;
    }
    setfillstyle(SOLID_FILL,RED);      //ERASING OLD SCORE
    bar(550,460,620,480);
    itoa(score,s,10);
    sound(200);
    delay(200);
    nosound();
    settextstyle(TRIPLEX_FONT,0,1);
    setcolor(BLUE);
    outtextxy(580,467,s);
    increase();
    provide(RED);
  }
}
void counter()
{
 if(count>50)
 provide(BLACK);
}
int check2()      // CHECKS WHETHER THE SNAKE HAS TOUCHED ITS OWN BODY //
{
 for(int i=0;i<=part-5;i++)
 {
  if((m==bug.x[i])&&(n==bug.y[i]))
  return(0);
 }
 return(1);
}
int check3()
{
 for(int i = 0;i<part;i++)
 {                   // CHECKS WHETHER FOOD IS PROVIDED ON THE BODY ITSELF //
  if(  (z[0]==bug.x[i])&&(z[1]==bug.y[i]) )
  return(0);
 }
 return(1);
}

