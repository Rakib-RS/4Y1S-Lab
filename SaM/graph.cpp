#include <graphics.h>
#include <conio.h>

main(){
   int gd = DETECT, gm;

   initgraph(&gd, &gm,(char*)"");
   circle(320,240,300);
   getch();
   closegraph();
   return 0;
}
