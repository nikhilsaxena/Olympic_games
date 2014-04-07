#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

union REGS i,o;
//int scan,ascii;
int scan,x2,y2,status,ch,m,n,x1dir=0,x1,y1,wdir=1,ydir=1,flag=0,ll;
int initmouse();
int *a,*b,*button;
int arrows=0,j,x,y,i1,ch,k,loc,snd;
char ar[4],br[4];
double score=0,arr=5;
unsigned int goalkeeper,ball;
int light=0,shootout=0,c=1,ch,ascii,scan,cx,cy,radius,p,diameter,nn,play=1,g1,z,lef=0,rig=0,mid=0;
int xl=140,yl,rl,goal=0,miss=0;
void *goalkeepersize,*ballsize;



//void showmouseptr();
/*void showmouseptr()
 {
 i.x.ax=1;
 int86(0x33,&i,&o);
 } */

void  restrictmouseptr(int x1,int y1,int x2,int y2)
 {
 i.x.ax=7;
 i.x.cx=x1;
 i.x.dx=x2;
 int86(0x33,&i,&o);
 i.x.ax=8;
 i.x.cx=y1;
 i.x.dx=y2;
 int86(0x33,&i,&o);
 }





int initmouse()
{
i.x.ax=0;
int86(0x33,&i,&o);
return 0;
}

void showmouseptr()
{
i.x.ax=1;
int86(0X33,&i,&o);
}

void getmouseptr(int *button,int *a,int *b)
{
i.x.ax=3;
int86(0X33,&i,&o);
*button=o.x.bx;
*a=o.x.cx;
*b=o.x.dx;
}


void mousereg()
{
int x2,y2;
initmouse();
showmouseptr();
restrictmouseptr(20,20,630,420);

}

void getkey()
{
i.h.ah=0x00;
int86(0x16,&i,&o);
ascii=o.h.al;
scan=o.h.ah;
}




lights(int xl,int light)
{
//xl=200;
setlinestyle(0,0,1);
yl=75;
rl=20;
if(light==1)
{
setfillstyle(1,GREEN);
fillellipse(xl,yl,rl,rl);

if((shootout==6)&&(goal>=4))
  {
   delay(200);
   cleardevice();
   setcolor(RED);
   settextstyle(0,0,3);
   outtextxy(280,200,"YOU WIN");

   ch=getch();
   if(ch==27)
   {
   exit(0);
   }
  }
  else if((shootout==6)&&(goal<4))
    {
    delay(200);
    cleardevice();
    setcolor(RED);
    settextstyle(0,0,3);
    outtextxy(280,200,"GAME OVER");
    ch=getch();
    if(ch==27)
     {
     exit(0);
     }
    }


}
if(light==0)
{
setfillstyle(1,RED);
fillellipse(xl,yl,rl,rl);
if((shootout==6)&&(goal>=4))
  {
   delay(200);
   cleardevice();
   setcolor(RED);
   settextstyle(0,0,3);
   outtextxy(280,200,"YOU WIN");
   ch=getch();
   if(ch==27)
   {
   exit(0);
   }
  }
  else if((shootout==6)&&(goal<4))
    {
    delay(200);
    cleardevice();
    setcolor(RED);
    settextstyle(0,0,3);
    outtextxy(280,200,"GAME OVER");
    ch=getch();
    if(ch==27)
     {
     exit(0);
     }
    }


}

//printf("END");

//xl+50;
}


void middle()
{
//int c=1;
 cx=315;
 cy=420;
 nn=8;
 diameter=20;
 radius=10;
 for(p=nn;p>=1;p--)


  {
  setcolor(WHITE);
  setfillstyle(1,WHITE);
  fillellipse(cx,cy,radius,radius);
  delay(10);
  setcolor(0);
  setfillstyle(1,0);
  fillellipse(cx,cy,radius,radius);
  cy=cy-16;
  delay(20);
  }

  setcolor(WHITE);
  setfillstyle(1,WHITE);
  fillellipse(cx,cy,radius,radius);
  delay(50);
   setcolor(GREEN);
  setlinestyle(0,1,3);
  line(11,300,629,300);
  getkey();
  if(ascii==27)
  {
   closegraph();
   exit(0);
  }
  if((scan==75)&&(c==1))
  {
    putimage(205,225,goalkeepersize,OR_PUT);
    delay(20);
    setcolor(0);
    setfillstyle(1,0);
    bar(293,225,338,298);
    floodfill(300,250,0);
    c=0;
    lef=1;
   }
  else if((scan==77)&&(c==1))
  {
    putimage(380,225,goalkeepersize,OR_PUT);
    delay(20);
    setcolor(0);
    setfillstyle(1,0);
    bar(293,225,338,298);
    floodfill(300,250,0);
    c=0;
    rig=1;
   }
   else if((scan==80)&&(c==1))
   {
   c=0;
   mid=1;
   }
//   lights(xl,light);
 fflush(stdin);
if(p==0 && mid==1)
 {
  setcolor(15);
  settextstyle(0,0,2);
  outtextxy(280,150,"SAVED");
  sound(3300);
  delay(300);
  setcolor(0);
  goal++;
 // nosound();
  outtextxy(280,150,"SAVED");
  nosound();
  light=1;
  }
  else
  {
  setcolor(15);
  settextstyle(0,0,2);
  sound(2900);
  outtextxy(270,150,"MISSED");
  delay(300);
  setcolor(0);
  outtextxy(270,150,"MISSED");
  nosound();
  light=0;
  miss++;
  }

  xl=xl+50;
lights(xl,light);
fflush(stdin);
//printf("%d",goal);
}




void right()
{
cx=315;
cy=420;
nn=9;
diameter=20;
radius=10;
for(p=nn;p>=1;p--)
 {
 setcolor(WHITE);
 setfillstyle(1,WHITE);
 fillellipse(cx,cy,radius,radius);
 delay(10);
 setcolor(0);
 setfillstyle(1,0);
 fillellipse(cx,cy,radius,radius);
 cx=cx+10;
 cy=cy-16;
 delay(20);
 }
 setcolor(WHITE);
 setfillstyle(1,WHITE);
 fillellipse(cx,cy,radius,radius);
   delay(50);
    setcolor(GREEN);
  setlinestyle(0,1,3);
  line(11,300,629,300);
 // delay(50);
  getkey();
if(ascii==27)
 {
 closegraph();
 exit(0);
 }
if((scan==75)&&(c==1))
 {
  putimage(205,225,goalkeepersize,OR_PUT);
  delay(20);
  setcolor(0);
  setfillstyle(1,0);
  bar(293,225,338,298);
  floodfill(300,250,0);
  c=0;
  lef=1;
 }
else if((scan==77)&&(c==1))
 {
  putimage(380,225,goalkeepersize,OR_PUT);
  delay(20);
  setcolor(0);
  setfillstyle(1,0);
  bar(293,225,338,298);
  floodfill(300,250,0);
  c=0;
  rig=1;
  }
 else if((scan==80)&&(c==1))
 {
  c=0;
  mid=1;
 }
// lights(xl,light);
 fflush(stdin);
if(p==0 && rig==1)
 {
  setcolor(15);
  settextstyle(0,0,2);
  sound(3300);
  outtextxy(280,150,"SAVED");
  delay(300);
  setcolor(0);
  outtextxy(280,150,"SAVED");
  nosound();
  light=1;
  goal++;
  }
  else
  {
  setcolor(15);
  settextstyle(0,0,2);
  sound(2900);
  outtextxy(270,150,"MISSED");
  delay(300);
  setcolor(0);
  outtextxy(270,150,"MISSED");
  nosound();
  light=0;
  miss++;
  }
  xl=xl+50;
lights(xl,light);
fflush(stdin);
//printf("%d",goal);
}

void left()
{
cx=315;
cy=420;
nn=9;
diameter=20;
radius=10;
for(p=nn;p>=1;p--)
 {
 setcolor(WHITE);
 setfillstyle(1,WHITE);
 fillellipse(cx,cy,radius,radius);
 delay(10);
 setcolor(0);
 setfillstyle(1,0);
 fillellipse(cx,cy,radius,radius);
 cx=cx-10;
 cy=cy-16;
 delay(20);
 }
 setcolor(WHITE);
 setfillstyle(1,WHITE);
 fillellipse(cx,cy,radius,radius);
 delay(50);

    setcolor(GREEN);
  setlinestyle(0,1,3);
  line(11,300,629,300);
  getkey();
if(ascii==27)
 {
 closegraph();
 exit(0);
 }
if((scan==75)&&(c==1))
 {
  putimage(205,225,goalkeepersize,OR_PUT);
  delay(20);
  setcolor(0);
  setfillstyle(1,0);
  bar(293,225,338,298);
  floodfill(300,250,0);
  c=0;
  lef=1;
 }
else if((scan==77)&&(c==1))
 {
  putimage(380,225,goalkeepersize,OR_PUT);
  delay(20);
  setcolor(0);
  setfillstyle(1,0);
  bar(293,225,338,298);
  floodfill(300,250,0);
  c=0;
  rig=1;
  }
else if((scan==80)&&(c==1))
 {
  c=0;
  mid=1;
  }
  fflush(stdin);
if(p==0 && lef==1)
 {
  setcolor(15);
  settextstyle(0,0,2);
  sound(3300);
  outtextxy(280,150,"SAVED");
  delay(300);
  setcolor(0);
  outtextxy(280,150,"SAVED");
  nosound();
  light=1;
  goal++;
  }
  else
  {
  setcolor(15);
  settextstyle(0,0,2);
  sound(2900);
  outtextxy(270,150,"MISSED");
  delay(300);
  setcolor(0);
  outtextxy(270,150,"MISSED");
  nosound();
  light=0;
  miss++;
  }
  xl=xl+50;
lights(xl,light);
fflush(stdin);
///printf("%d",goal);
}

void goalie()
{
setcolor(BROWN);
ellipse(315,235,0,360,10,10);
setfillstyle(1,BROWN);
fillellipse(315,235,10,10);
setfillstyle(1,RED);
bar(305,246,325,265);
bar(300,246,305,250);
bar(325,246,330,250);
setfillstyle(1,BLUE+10);
bar(305,266,325,285);
setcolor(0);
line(315,275,315,285);
setcolor(BROWN);
setlinestyle(0,1,3);
line(308,286,308,297);//LEGS
line(322,286,322,297);
line(299,246,295,265);//HAND
line(331,246,335,265);

goalkeeper=imagesize(293,225,338,300);
goalkeepersize=malloc(goalkeeper);
getimage(293,225,338,300,goalkeepersize);

}


void display()
{
    setcolor(WHITE);
    settextstyle(0,0,2);
    sound(6000);
    outtextxy(280,150,"READY");
    delay(300);
    setcolor(0);
    nosound();
    outtextxy(280,150,"READY");
    delay(200);
    setcolor(WHITE);
    sound(4400);
    outtextxy(310,150,"1");
    delay(100);
    setcolor(0);
    nosound();
    outtextxy(310,150,"1");
    delay(200);
    setcolor(15);
    sound(4400);
    outtextxy(310,150,"2");
    delay(100);
    setcolor(0);
    nosound();
    outtextxy(310,150,"2");
    delay(200);
    setcolor(15);
    sound(4400);
    outtextxy(310,150,"3");
    delay(100);
    setcolor(0);
    nosound();
    outtextxy(310,150,"3");
    setcolor(15);
    delay(200);
    sound(9000);
    outtextxy(280,150,"SHOOT");
    delay(200);
    setcolor(0);
    nosound();
    outtextxy(280,150,"SHOOT");
    delay(100);
 }


void football()
{
int a,i,j,a1=0,arr[10];
rectangle(10,10,630,460);
//shoot=0;
 goalie();
//balls();
 setlinestyle(0,1,3);
 setcolor(GREEN);
 line(11,300,629,300);
// line(430,300,629,300);
 setcolor(WHITE);
 line(200,200,430,200);
 line(200,200,200,300);
 line(430,200,430,300);
// ellipse(315,300,180,360,120,90);
 setlinestyle(0,1,1);
 setfillstyle(1,15);
// rectangle(160,50,480,100);
 rectangle(250,130,380,190);
// setfillstyle(1,BLUE);
// floodfill(180,80,BLUE);
 setcolor(BLUE);
 bar(160,50,480,100);
 setfillstyle(1,15);
 fillellipse(315,420,10,10);



 for(a=0;a<6;a++)
 {
  arr[a]=random(6);
 }
 for(i=0;i<6;i++)
 {

   if((shootout==6)&&(goal>=4))
  {
//  printf("END");
   delay(200);
   cleardevice();
   setcolor(RED);
   settextstyle(0,0,3);
   outtextxy(280,200,"YOU WIN");
   ch=getch();
   if(ch==27)
   {
   exit(0);
   }
  }
  else
  {
    if((shootout==6)&&(goal<3))
    {
    delay(200);
    cleardevice();
    setcolor(RED);
    settextstyle(0,0,3);
    outtextxy(280,200,"GAME OVER");
    ch=getch();
    if(ch==27)
     {
     exit(0);
     }
    }
  }

//  }
  // shoot=shoot++;
   delay(120);
   putimage(293,225,goalkeepersize,OR_PUT);
   display();
 // c=1;
  if(arr[i]==0)
  {
  lef=0;rig=0;mid=0;c=1;
  left();
  }
  else if(arr[i]==1)
  {
  lef=0;rig=0;mid=0;c=1;
  right();
  }
  else if(arr[i]==2)
  {
  lef=0;rig=0;mid=0; c=1;
  middle();
  }
  else if(arr[i]==3)
  {
   lef=0;rig=0;mid=0; c=1;
  left();
  }
  else if(arr[i]==4)
  {
   lef=0;rig=0;mid=0; c=1;
  right();
  }
  else if(arr[i]==5)
  {
   lef=0;rig=0;mid=0;c=1;
  middle();
  }
  else if(arr[i]==6)
  {
   lef=0;rig=0;mid=0;c=1;
  left();
  }
  else if(arr[i]==7)
  {
   lef=0;rig=0;mid=0;c=1;
  right();
  }
  else if(arr[i]==8)
  {
   lef=0;rig=0;mid=0;c=1;
  middle();
  }
  else if(arr[i]==9)
  {
   lef=0;rig=0;mid=0;c=1;
  left();
  }
  delay(250);
shootout++;
setcolor(0);
setfillstyle(1,0);
bar(202,202,428,298);
floodfill(205,250,0);
//printf("END");
//c=1;
}
}



void level2()
{
cleardevice();
rectangle(10,10,630,460);
restrictmouseptr(0,0,0,0);
setcolor(RED);
settextstyle(0,0,4);
outtextxy(220,220,"LEVEL 2");
settextstyle(0,0,3);
setcolor(WHITE);
outtextxy(240,280,"FOOTBALL");
delay(1000);
cleardevice();

football();

}





void gameover()
{
setcolor(0);
bar(11,11,629,440);
setcolor(WHITE);
outtextxy(250,280,"TOTAL SCORE");
gcvt(score,4,ar);
outtextxy(350,280,ar);
settextstyle(0,0,3);
setcolor(RED);
outtextxy(220,200,"GAME OVER");
settextstyle(0,0,1);
setcolor(WHITE);
outtextxy(250,320,"Press Esc to Quit");
outtextxy(250,340,"Press Spacebar to play again");
ch=getch();
if(ch==27)
 {
 exit(0);
 }
 else if(ch==32)
 {
// arrow=0;
 arrows=0;
 score=0;
 arr=5;
 main();
 }
}

void stick1(loc)
{
snd=0;
setcolor(0);
gcvt(score,4,ar);
outtextxy(180,240,ar);
gcvt(arr,4,br);
outtextxy(550,240,br);
setcolor(WHITE);
 if(loc>=257 && loc<267)
  {
   score=score+100;
   outtextxy(100,250,"Points:100");
  }
 if(loc>=247 && loc<257)
  {
   score=score+70;
   outtextxy(100,250,"Points:70");
  }
 if(loc>267 && loc<=277)
  {
   score=score+70;
   outtextxy(100,250,"Points:70");
  }
 if(loc>=237 && loc<247)
  {
   score=score+50;
   outtextxy(100,250,"Points:50");
  }
 if(loc>277 && loc<=287)
  {
   score=score+50;
   outtextxy(100,250,"Points:50");
  }
 if(loc>=227 && loc<237)
  {
   score=score+40;
   outtextxy(100,250,"Points:40");
  }
 if(loc>287 && loc<=297)
  {
   score=score+40;
   outtextxy(100,250,"Points:40");
  }
 if(loc>=217 && loc<227)
  {
   score=score+30;
   outtextxy(100,250,"Points:30");
  }
 if(loc>297 && loc<=307)
  {
   score=score+30;
   outtextxy(100,250,"Points:30");
  }
  settextstyle(1,0,3);
  outtextxy(80,240,"Total Score:");
  gcvt(score,4,ar);
  outtextxy(180,240,ar);
  outtextxy(480,200,"Arrows Left");
 // gcvt(arr,4,br);
 // outtextxy(550,240,br);

for(n=n;n>11;n--)
 {
   snd=snd+1;
   setfillstyle(1,8);
   bar(n,11,n+90,15);
    setfillstyle(1,7);
   bar(n+10,16,n+80,20);
    setfillstyle(1,9);
   bar(n+20,21,n+70,25);
    setfillstyle(1,14);
   bar(n+30,26,n+60,30);
    setfillstyle(1,4);
   bar(n+40,31,n+50,35);

   setcolor(BROWN);
  if(loc>=257 && loc<=267)
    {
    line(n-loc+309,35,n-loc+309,55);
     if(snd==1)
      sound(1500);
     if(snd==3)
      nosound();
     if(snd==5)
      sound(1500);
     if(snd==15)
      nosound();
    }
   if(loc>=247 && loc<257)
    {
    line(n-loc+309,30,n-loc+309,50);
     if(snd==1)
      sound(1300);
     if(snd==5)
      sound(1100);
     if(snd==15)
      nosound();
     }
   if(loc>267 && loc<=277)
     {
    line(n-loc+309,30,n-loc+309,50);
     if(snd==1)
      sound(1300);
     if(snd==5)
      sound(1100);
     if(snd==15)
      nosound();
     }
  if(loc>=237 && loc<247)
  {
   line(n-loc+309,25,n-loc+309,45);
   if(snd==1)
    sound(1300);
   if(snd==5)
    sound(1100);
   if(snd==10)
    sound(900);
   if(snd==20)
    nosound();
  }
  if(loc>277 && loc<=287)
  {
   line(n-loc+309,25,n-loc+309,45);
   if(snd==1)
    sound(1300);
   if(snd==5)
    sound(1100);
   if(snd==10)
    sound(900);
   if(snd==20)
    nosound();
  }
  if(loc>=227 && loc<237)
  {
   line(n-loc+309,20,n-loc+309,40);
   if(snd==1)
    sound(1300);
   if(snd==5)
    sound(1100);
   if(snd==10)
    sound(900);
   if(snd==15)
    sound(800);
   if(snd==20)
    nosound();
  }
  if(loc>287 && loc<=297)
  {
   line(n-loc+309,20,n-loc+309,40);
   if(snd==1)
    sound(1300);
   if(snd==5)
    sound(1100);
   if(snd==10)
    sound(900);
   if(snd==15)
    sound(800);
   if(snd==20)
    nosound();
  }
  if(loc>=217 && loc<227)
  {
   line(n-loc+309,15,n-loc+309,35);
   if(snd==1)
    sound(1300);
   if(snd==5)
    sound(1100);
   if(snd==10)
    sound(900);
   if(snd==15)
    sound(800);
   if(snd==20)
    sound(700);
   if(snd==25)
    nosound();
  }
  if(loc>297 && loc<=307)
  {
   line(n-loc+309,15,n-loc+309,35);
   if(snd==1)
    sound(1300);
   if(snd==5)
    sound(1100);
   if(snd==10)
    sound(900);
   if(snd==15)
    sound(800);
   if(snd==20)
    sound(700);
   if(snd==25)
    nosound();
  }

  delay(20);
  setcolor(0);

  setfillstyle(1,0);
  bar(n,11,n+90,15);
  bar(n+10,16,n+80,20);
  bar(n+20,21,n+70,25);
  bar(n+30,26,n+60,30);
  bar(n+40,31,n+50,35);

  if(loc>=257 && loc<267)
  line(n-loc+309,35,n-loc+309,55);
  if(loc>=247 && loc<257)
  line(n-loc+309,30,n-loc+309,50);
  if(loc>257 && loc<=277)
  line(n-loc+309,30,n-loc+309,50);
  if(loc>=237 && loc<247)
  line(n-loc+309,25,n-loc+309,45);
  if(loc>277 && loc<=287)
  line(n-loc+309,25,n-loc+309,45);
  if(loc>=227 && loc<237)
  line(n-loc+309,20,n-loc+309,40);
  if(loc>287 && loc<=297)
  line(n-loc+309,20,n-loc+309,40);
  if(loc>=217 && loc<227)
  line(n-loc+309,15,n-loc+309,35);
  if(loc>297 && loc<=307)
  line(n-loc+309,15,n-loc+309,35);


  if(kbhit())
  {
   int ch=getch();
    if(ch==27)
    {
     closegraph();
     exit(0);
    }
   }
 }
 n=535;
 j=300;
 k=0;

 setcolor(0);
 if(loc>=257 && loc<=267)
  outtextxy(100,250,"Points:100");
 if(loc>=247 && loc<257)
  outtextxy(100,250,"Points:70");
 if(loc>267 && loc<=277)
  outtextxy(100,250,"Points:70");
 if(loc>=237 && loc<247)
  outtextxy(100,250,"Points:50");
 if(loc>277 && loc<=287)
  outtextxy(100,250,"Points:50");
 if(loc>=227 && loc<237)
  outtextxy(100,250,"Points:40");
 if(loc>287 && loc<=297)
  outtextxy(100,250,"Points:40");
 if(loc>=217 && loc<227)
  outtextxy(100,250,"Points:30");
 if(loc>297 && loc<=307)
  outtextxy(100,250,"Points:30");
  outtextxy(550,240,br);
 if((score<300)&&(arrows==5))
 {
 gameover();
 }
 if((score>=300)&&(arrows==5))
 {
 level2();
 }
 target();
}




void shoot()
{
if((score<300)&&(arrows==5))
 {
 gameover();
 }
if((score>=300)&&(arrows==5))
 {
 level2();
 }
 arr=arr-1;
 arrows=arrows+1;
// arrow++;
 setcolor(0);
  for(ll=25;ll<=25*arrows;ll+=25)
 {
  outtextxy(500,200+ll,"_______");
  outtextxy(550,204+ll,"<");
 }
// setcolor(WHITE);
// printf("%d",arrows);
 a:
 for(n=n;n>11;n--)
 {
  if(k==350 && n>=237 && n<287)
  {
   int loc=n;
   stick1(loc);
  }
  if(k==360 && n>=217 && n<237)
  {
   int loc=n;
   stick1(loc);
  }
  if(k==360 && n>=287 && n<=307)
  {
   int loc=n;
   stick1(loc);
  }

  if(k==420)
  {
   settextstyle(0,0,2);
   setcolor(RED);
   outtextxy(240,200,"YOU MISSED");
   delay(800);
   setcolor(0);
   outtextxy(240,200,"YOU MISSED");
   k=0;
  // arrows++;
  target();
  }
 // k=0;
 settextstyle(1,0,1);
  k=k+10;
  setfillstyle(1,8);
  setcolor(2);
   bar(n,11,n+90,15);
  setfillstyle(1,7);
   bar(n+10,16,n+80,20);
  setfillstyle(1,9);
   bar(n+20,21,n+70,25);
  setfillstyle(1,14);
   bar(n+30,26,n+60,30);
  setfillstyle(1,4);
   bar(n+40,31,n+50,35);

  line(309,400-k,309,420-k);

  delay(20);

  setcolor(0);
  setfillstyle(1,0);
  bar(n,11,n+90,15);
  bar(n+10,16,n+80,20);
  bar(n+20,21,n+70,25);
  bar(n+30,26,n+60,30);
  bar(n+40,31,n+50,35);

  line(309,400-k,309,420-k);


  if(kbhit())
  {
    int ch=getch();
    if(ch==27)
    {
     closegraph();
     exit(0);
    }
  }
 }
 n=n;
 j=300;
 if(arrows==5)
 {

  gameover();
 }
 goto a;
}


target()
{
 a:
 for(n=535;n>11;n--)
 {
  setfillstyle(1,8);
  bar(n,11,n+90,15);
  setfillstyle(1,7);
  bar(n+10,16,n+80,20);
  setfillstyle(1,9);
  bar(n+20,21,n+70,25);
  setfillstyle(1,14);
  bar(n+30,26,n+60,30);
  setfillstyle(1,4);
  bar(n+40,31,n+50,35);
  delay(20);
  setfillstyle(SOLID_FILL,0);
  bar(n,11,n+90,15);
  bar(n+10,16,n+80,20);
  bar(n+20,21,n+70,25);
  bar(n+30,26,n+60,30);
  bar(n+40,31,n+50,35);


 if(kbhit())
  {
  ch=getch();
    if(ch==27)
     {
     exit(0);
     }
     else if(ch==32)
     {
     shoot();
     }
    }
 }
 n=535;
 goto a;
}




archery()
{
cleardevice();
//exit(0);
restrictmouseptr(0,0,0,0);
settextstyle(0,0,4);
setcolor(RED);
outtextxy(220,220,"LEVEL 1");
settextstyle(0,0,3);
setcolor(WHITE);
outtextxy(240,280,"ARCHERY");
delay(1000);
cleardevice();
setcolor(WHITE);
rectangle(10,10,630,460);
settextstyle(1,0,4);
outtextxy(80,240,"Total Score:");
outtextxy(480,200,"Arrows Left");
 for(ll=25;ll<=125;ll+=25)
 {
  outtextxy(500,200+ll,"_______");
  outtextxy(550,204+ll,"<");
 }

setcolor(WHITE);
ellipse(309,440,0,180,80,30);
setcolor(WHITE);
line(231,440,389,440);
setcolor(GREEN);
line(309,440,309,400);
target();
}


/*void instructions()
{
}

void scores()
{
}  */


void credits()
{
cleardevice();
restrictmouseptr(10,10,10,10);
setfillstyle(1,WHITE);
floodfill(600,450,WHITE);
setcolor(RED);
rectangle(20,20,620,450);
settextstyle(0,0,2);
setcolor(BLUE);
outtextxy(180,30,"OLYMPIC GAMES 2012");
settextstyle(0,0,1);
setcolor(42+WHITE);
outtextxy(130,60,"This project is designed and developed by:-");
setcolor(RED);
outtextxy(180,90,"1.Nikhil Saxena");
setcolor(6);
outtextxy(320,90,"Roll No-1016413026");

setcolor(RED);
outtextxy(180,120,"2.Ambica Gupta");
setcolor(6);
outtextxy(320,120,"Roll No-1016413003");

setcolor(RED);
outtextxy(180,150,"3.Aman Saxena");
setcolor(6);
outtextxy(320,150,"Roll No-1016413002");

setcolor(RED);
outtextxy(180,180,"4.Ayush Katiyar");
setcolor(6);
outtextxy(320,180,"Roll No-1016413013");
setcolor(41+WHITE);
outtextxy(152,210,"We also Thanks ");
setcolor(RED);
outtextxy(280,210,"Pranay Bhattacharaya Sir");
setcolor(41+WHITE);
outtextxy(152,240,"For providing us this topic to work on.");
setcolor(BLUE);
outtextxy(270,270,"Thank You.");
outtextxy(425,425,"Press Esc to Exit.");
//outtextxy(450,435," key to go back");
scan=getch();
if(ch==27)
{
 exit(0);
}


/*scanf("%d",&scan);
if(scan=='e')
 {
 start();
  }
  else
  {
  delay(10);
  } */
}


void start()
{
int y1=30,r;
status=initmouse();
//showmouseptr();
//getmouseptr(&button,&x,&y);
for(r=10;r<=629;r+=20)
 {
  setcolor(BLUE);
  circle(r,y1,10);
  setfillstyle(1,r+WHITE);
  floodfill(r,y1,BLUE);
  delay(20);
 }
for(y1=30;y1<=420;y1+=20)
 {
  setcolor(BLUE);
  circle(r,y1,10);
  setfillstyle(1,y1+WHITE);
  floodfill(r,y1,BLUE);
  delay(20);
 }
for(r=629;r>=10;r-=20)
 {
  setcolor(GREEN);
  circle(r,y1,10);
  setfillstyle(1,r+RED);
  floodfill(r,y1,GREEN);
  delay(20);
 }
for(y1=432;y1>=30;y1-=20)
 {
  setcolor(BLUE);
  circle(r,y1,10);
  setfillstyle(1,y1+150+WHITE);
  floodfill(r,y1,BLUE);
  delay(20);

 }
 setcolor(WHITE);
 rectangle(25,50,615,415);
 r=615-25;
 y1=425-50;
 setfillstyle(1,90+WHITE);
 floodfill(r,y1 ,WHITE);
 settextstyle(0,0,3);
 rectangle(80,60,550,100);
 setfillstyle(1,WHITE);
 //floodfill(460,40,WHITE);
 setcolor(BLUE);
 outtextxy(100,70,"OLYMPIC GAMES 2012");
 delay(50);
 setcolor(BLUE);
 circle(290,125,20);
 delay(50);
 setcolor(BLACK);
 circle(320,125,20);
 delay(50);
 setcolor(RED);
 circle(350,125,20);
 delay(50);
 setcolor(YELLOW);
 circle(305,150,20);
 delay(50);
 setcolor(GREEN);
 circle(335,150,20);
 setfillstyle(0,2);
 setcolor(8);
 settextstyle(0,0,2);
 setcolor(BLACK);
 outtextxy(240,200,"PLAY GAME");
 outtextxy(240,230,"INSTRUCTIONS");
 outtextxy(240,260,"CREDITS");
 outtextxy(240,290,"EXIT");
// outtextxy(240,320,"EXIT");
setfillstyle(SOLID_FILL,RED);
//setcolor(WHITE);
//rectangle(240,200,390,215);
//rectangle(240,290,300,305);
//rectangle(240,260,350,275);
mousereg();
flag=0;
restrictmouseptr(10,10,630,420);

  while(flag==0)
   {
    showmouseptr();

    getmouseptr(&button,&a,&b);
	   if(button==1)
		{
		 x2=a;y2=b;
		if((x2>240 && x2<390 )&& (y2>200 && y2<215))
		   {
		    flag=1;
		  //  break;
		// archery();
		    //break;
		    }
	       else if((x2>240 && x2<350 )&& (y2>260 && y2<275))
		    {
		    flag=2;
		  //  break;
		    }
		else if((x2>240 && x2<300 )&& (y2>290 && y2<305))
		    {
		     flag=3;

		    //break;
		      }
		  }
       }

  if(flag==1)
  {
  cleardevice();
  archery();
/* setcolor(0);
 setfillstyle(1,0);
 bar(10,10,450,630);
 floodfill(250,250,0);  */
  }
  if(flag==2)
  {
  cleardevice();
  credits();
  }
  if(flag==3)
  {
  exit(0);
  }
}




int main(void)
{

int gd=DETECT,gm;


initgraph(&gd,&gm,"C:\TC\BGI");
start();
//closegraph();

//setbkcolor(WHITE);
//ball();
//cleardevice();
//closegraph();
getch();
}
