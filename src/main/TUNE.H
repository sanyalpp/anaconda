// INCLUDE LIBRARIES //
#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>

void tune(int);

 void tune(int ch)
  {
 int sbrk =30,
     enote=150,
     qnote=300,
     hnote=600,
     dot_hnote=900,
    c1=256,d1=287,e1=323,f1=342,g1=384,a1=431,a1s=456;
   switch(ch)
   {
   case 1:

     sound(f1);   delay(enote);   nosound(); delay(sbrk);
     sound(f1);   delay(enote);   nosound(); delay(sbrk);
     sound(g1);   delay(enote);   nosound(); delay(sbrk);
     sound(a1);   delay(enote);   nosound(); delay(sbrk);

     sound(f1);   delay(enote);   nosound(); delay(sbrk);
     sound(a1);   delay(enote);   nosound(); delay(sbrk);
     sound(g1);   delay(enote);   nosound(); delay(sbrk);
     sound(c1);   delay(enote);   nosound(); delay(sbrk);


     sound(f1);   delay(enote);   nosound(); delay(sbrk);
     sound(f1);   delay(enote);   nosound(); delay(sbrk);
     sound(g1);   delay(enote);   nosound(); delay(sbrk);
     sound(a1);   delay(enote);   nosound(); delay(sbrk);

     sound(f1);   delay(qnote);   nosound(); delay(sbrk);
     sound(e1);   delay(qnote);   nosound(); delay(sbrk);

     sound(f1);   delay(enote);   nosound(); delay(sbrk);
     sound(f1);   delay(enote);   nosound(); delay(sbrk);
     sound(g1);   delay(enote);   nosound(); delay(sbrk);
     sound(a1);   delay(enote);   nosound(); delay(sbrk);

     sound(a1s);  delay(enote);   nosound(); delay(sbrk);
     sound(a1);   delay(enote);   nosound(); delay(sbrk);
     sound(g1);   delay(enote);   nosound(); delay(sbrk);
     sound(f1);   delay(enote);   nosound(); delay(sbrk);

     sound(e1);   delay(enote);   nosound(); delay(sbrk);
     sound(c1);   delay(enote);   nosound(); delay(sbrk);
     sound(d1);   delay(enote);   nosound(); delay(sbrk);
     sound(e1);   delay(enote);   nosound(); delay(sbrk);

     sound(f1);   delay(qnote);   nosound(); delay(sbrk);

     sound(f1);   delay(qnote);   nosound(); delay(sbrk);
     break;
   case 2:
     sound(e1);   delay(qnote);   nosound(); delay(sbrk);
     sound(e1);   delay(qnote);   nosound(); delay(sbrk);

     sound(e1);   delay(hnote);   nosound(); delay(sbrk);

     sound(e1);   delay(qnote);   nosound(); delay(sbrk);
     sound(e1);   delay(qnote);   nosound(); delay(sbrk);

     sound(e1);   delay(hnote);   nosound(); delay(sbrk);

     sound(e1);   delay(qnote);   nosound(); delay(sbrk);

     sound(g1);   delay(qnote);   nosound(); delay(sbrk);

     sound(c1);   delay(qnote);   nosound(); delay(sbrk);

     sound(d1);   delay(qnote);   nosound(); delay(sbrk);

     sound(e1);   delay(dot_hnote); nosound(); delay(qnote);
     break;
    }
  }
