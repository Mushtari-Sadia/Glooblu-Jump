/*
	author: Prof. Ashikur rahman
	last modified: April 29, 2017
	*/
#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
#define PI 3.1416
#include<windows.h>
#include<mmsystem.h>
#include <string>

int pic_x=120, pic_y=150,jump=0,stfall=0,obst_x,obst_x2=obst_x-800;

int game_over=0;
int storescore;
int coin=0;
int level=0,level_speed=15;
int game_start=0;
int game=0;
int life=3;
int lifetime=0;

int score=0;
int jumpdown=0;
int stfallup=0;
int helpon=0;




int scores[10000];
char result[7];
char result_on[7];
char high_result[7];
int high_score=0;
char coins[7];
//char lifes[2];
int counts=0;
int r=10,b=255;

void lifetimef()
{
    lifetime++;
}

void colorchange()
{
    r+=10;
    b-=10;
    if(r>=255)
        r=10;
    if(b<=10)
        b=255;

}


void gameover()
{
    if(level==1 && game_over==0){
    if(obst_x-10==pic_x || obst_x+10==pic_x || obst_x+400-10==pic_x || obst_x+400+10==pic_x || obst_x+800-10==pic_x || obst_x+800+10==pic_x || obst_x+1200+10==pic_x || obst_x+1200-10==pic_x || obst_x2-10==pic_x || obst_x2+10==pic_x || obst_x2+400-10==pic_x || obst_x2+400+10==pic_x || obst_x2+800-10==pic_x || obst_x2+800+10==pic_x || obst_x2+1200+10==pic_x || obst_x2+1200-10==pic_x)
    {
        if(pic_y>=150 && pic_y<=200)
        {
            lifetimef();
            if(lifetime>2)
            {
                life--;
                PlaySound(TEXT("gameover1.wav"),NULL,SND_ASYNC);
                lifetime=0;
            }
            if(life==0){
            game_over=1;
            coin=0;
            game_start=0;
            PlaySound(TEXT("gameover.wav"),NULL,SND_ASYNC);
            }

        }
    }



    }


    else if(level==2  && game_over==0 )
    {
        if(obst_x==pic_x || obst_x+400==pic_x || obst_x+800==pic_x || obst_x+1200==pic_x || obst_x2==pic_x || obst_x2+450==pic_x || obst_x2+850==pic_x || obst_x2+1250==pic_x)
    {
        if(pic_y>=150 && pic_y<=200)
        {
           lifetimef();
            if(lifetime>2)
            {
                life--;
                PlaySound(TEXT("gameover1.wav"),NULL,SND_ASYNC);
                lifetime=0;
            }
            if(life==0){
            game_over=1;
            coin=0;
            game_start=0;
            PlaySound(TEXT("gameover.wav"),NULL,SND_ASYNC);

        }
    }
    }
    }
    else if(level==3  && game_over==0 )
    {
        if(obst_x-30==pic_x || obst_x+30==pic_x || obst_x+400-40==pic_x || obst_x+400+40==pic_x || obst_x+800-40==pic_x || obst_x+840==pic_x || obst_x+1240==pic_x || obst_x+1200-40==pic_x || obst_x2-30==pic_x || obst_x2+30==pic_x || obst_x2+400-40==pic_x || obst_x2+400+40==pic_x || obst_x2+800-40==pic_x || obst_x2+840==pic_x || obst_x2+1240==pic_x || obst_x2+1200-40==pic_x ){
        if(pic_y>=150 && pic_y<=190)
        {
            lifetimef();
            if(lifetime>2)
            {
                life--;
                PlaySound(TEXT("gameover1.wav"),NULL,SND_ASYNC);
                lifetime=0;


            }
            if(life==0){
            game_over=1;
            coin=0;
            game_start=0;
            PlaySound(TEXT("gameover.wav"),NULL,SND_ASYNC);
        }
        }
    }
    }


}

void showlife()
{
    iSetColor(255,255,255);
    iFilledRectangle(700,453,75,25);
    iSetColor(255,0,0);
    iRectangle(700-1,453-1,75+2,25+2);
    if(level!=0 && game_over==0)
    {
        if(life==3)
    {
        iShowBMP(700,453,"heart.bmp");
    }
    if (life >=2)
    {
        iShowBMP(725,453,"heart.bmp");
    }
    if(life>=1)
    {
        iShowBMP(750,453,"heart.bmp");
    }
    }

}

//SCORE STORING
void scorefunc()
{
    if (game_over==0)
    {
        score++;
        if ( score>=50)
        {
            level=2;
            level_speed=10;
        }
         if ( score>=90)
        {
            level=3;
            level_speed=5;


        }
        }


}

void highscorefunc()
    {
        if(counts==0){

        FILE *f1;
         f1 = fopen("score.txt","r");

   while(!feof(f1)){
    fscanf(f1, "%d", &scores[game]);
    game++;
}
    game++;
       FILE *f;
        if (game==1){high_score = score;
                f = fopen("score.txt","w");
                 fprintf(f,"%d ",score);
                 fprintf(f,"\n");}
        else{
        f = fopen("score.txt","a");
        fprintf(f,"%d ",score);
        fprintf(f,"\n");}


        fclose(f);
        FILE *fp;
        fp = fopen("score.txt","r");
        int i=0;
        while(fscanf(fp,"%d\n",&scores[i])==1)
        {

        i++;
        }

        fclose(f);

        for(i=0;i<game;i++)
        {

            if(scores[i]>high_score)
               {
                   high_score=scores[i];
                   if(game>=1)
                   {
                       PlaySound(TEXT("highscore.wav"),NULL,SND_ASYNC);
                   }
               }

        }

        counts+=1;
    }
    }

void jumpup()
{

    if(jump==1)
    {
       if(pic_y<=300) pic_y+=10;
       else if(pic_y>300) stfall=1;
    }
    else if(jumpdown==1)
    {

        pic_y-=10;

    if(pic_y==20)
    {

        stfallup=1;
        jumpdown=0;
    }
    }

}



void falldown()
{
    if(stfall==1)
    {

        jump=0;
        pic_y-=10;

    if(pic_y<=150)
    {

        stfall=0;
    }
    }

    else if(stfallup==1)
    {
        jumpdown=0;
        if(pic_y>=20) pic_y+=10;
       if(pic_y>=150)
       {
           stfallup=0;

        }
}
}


void helpdraw()
{
    if(level==0 || level==1 || level == 2 || level ==3){
    iShowBMP(5,460,"help.bmp");
    if(helpon==1)
    {
        /*iSetColor(0,0,255);
        iText(5,440,"PRESS UP TO JUMP UP",GLUT_BITMAP_8_BY_13);
        iText(5,425,"PRESS DOWN TO JUMP DOWN(LVL 3)",GLUT_BITMAP_8_BY_13);*/
        iShowBMP(25,330-100,"instructions.bmp");
    }
    }
}
void obstacleslide()
{
    obst_x-=5;
    if(obst_x==-1230)
        obst_x=1030;
}

void obstacle2slide()
{
    obst_x2-=5;
    if(obst_x2==-1230)
        obst_x2=1030;
}


void candyobstacledraw2()
{
    iSetColor(220,198,0);
    iFilledRectangle(obst_x2,150,5,30);
    //iSetColor(0,65,0);
    iSetColor(r,0,b);
    iFilledCircle(obst_x2+2,180,20);
    iSetColor(255,0,130);
    iFilledCircle(obst_x2+2,180,10);
    iSetColor(255,255,255);
    iFilledCircle(obst_x2+2,180,5);

    iSetColor(220,198,0);
    iFilledRectangle(obst_x2+400,150,5,50);
    iSetColor(148, 1, 137);
    iFilledCircle(obst_x2+402,200,20);
    //iSetColor(255,0,130);
    iSetColor(r,0,b);
    iFilledCircle(obst_x+402,200,10);
    iSetColor(255,255,255);
    iFilledCircle(obst_x2+402,200,5);

    iSetColor(220,198,0);
    iFilledRectangle(obst_x2+800,150,5,30);
    iSetColor(3,1,220);
    iFilledCircle(obst_x2+802,180,20);
    //iSetColor(255,0,130);
    iSetColor(r,0,b);
    iFilledCircle(obst_x2+802,180,10);
    iSetColor(r,20,b);
    iFilledCircle(obst_x2+802,180,5);

    iSetColor(220,198,0);
    iFilledRectangle(obst_x2+1200,150,5,50);
    //iSetColor(200,0,200);
    iSetColor(r,0,255);
    iFilledCircle(obst_x2+1202,200,20);
    iSetColor(r,105,b);
    iFilledCircle(obst_x2+1202,200,10);
    iSetColor(255,255,255);
    iFilledCircle(obst_x2+1202,200,5);
}
void candyobstacledraw()
{
    iSetColor(220,198,0);
    iFilledRectangle(obst_x,150,5,30);
    iSetColor(r,10,b);
    iFilledCircle(obst_x+2,180,20);
    iSetColor(r,5,b);
    iFilledCircle(obst_x+2,180,10);
    iSetColor(255,255,255);
    iFilledCircle(obst_x+2,180,5);

    iSetColor(220,198,0);
    iFilledRectangle(obst_x+400,150,5,50);
    iSetColor(r,0,255);
    iFilledCircle(obst_x+402,200,20);
    iSetColor(r,100,b);
    iFilledCircle(obst_x+402,200,10);
    iSetColor(255,255,255);
    iFilledCircle(obst_x+402,200,5);

    iSetColor(220,198,0);
    iFilledRectangle(obst_x+800,150,5,30);
    iSetColor(200,0,b);
    iFilledCircle(obst_x+802,180,20);
    iSetColor(255,0,130);
    iFilledCircle(obst_x+802,180,10);
    iSetColor(255,255,255);
    iFilledCircle(obst_x+802,180,5);

    iSetColor(220,198,0);
    iFilledRectangle(obst_x+1200,150,5,50);
    iSetColor(r,0,100);
    iFilledCircle(obst_x+1202,200,20);
    iSetColor(255,0,130);
    iFilledCircle(obst_x+1202,200,10);
    iSetColor(255,255,255);
    iFilledCircle(obst_x+1202,200,5);


}

void cityobstacledraw()
{
    iSetColor(255,204,255);
    iFilledRectangle(obst_x,150,30,100);
    iSetColor(256,256,256);
    iFilledRectangle(obst_x+3.5,8.25+150,7.5,16.5);
     iFilledRectangle(obst_x+3.5,150+8.25+33,7.5,16.5);
      iFilledRectangle(obst_x+3.5,150+8.25+66,7.5,16.5);
       iFilledRectangle(obst_x+3.5+15,8.25+150,7.5,16.5);
     iFilledRectangle(obst_x+3.5+15,150+8.25+33,7.5,16.5);
      iFilledRectangle(obst_x+3.5+15,150+8.25+66,7.5,16.5);



    iSetColor(255,102,102);
    iFilledRectangle(obst_x+400,150,30,100);
    iSetColor(204,102,255);
       iFilledRectangle(400+obst_x+3.5,8.25+150,7.5,16.5);
     iFilledRectangle(400+obst_x+3.5,150+8.25+33,7.5,16.5);
      iFilledRectangle(400+obst_x+3.5,150+8.25+66,7.5,16.5);
       iFilledRectangle(400+obst_x+3.5+15,8.25+150,7.5,16.5);
     iFilledRectangle(400+obst_x+3.5+15,150+8.25+33,7.5,16.5);
      iFilledRectangle(400+obst_x+3.5+15,150+8.25+66,7.5,16.5);
    iSetColor(102,0,153);
     iFilledRectangle(obst_x+800,150,30,100);
    iSetColor(153,204,255);
        iFilledRectangle(obst_x+3.5+800,8.25+150,7.5,16.5);
     iFilledRectangle(obst_x+3.5+800,150+8.25+33,7.5,16.5);
      iFilledRectangle(obst_x+3.5+800,150+8.25+66,7.5,16.5);
       iFilledRectangle(obst_x+3.5+15+800,8.25+150,7.5,16.5);
     iFilledRectangle(obst_x+3.5+15+800,150+8.25+33,7.5,16.5);
      iFilledRectangle(obst_x+3.5+15+800,150+8.25+66,7.5,16.5);
    iSetColor(0,153,153);
       iFilledRectangle(obst_x+1200,150,30,100);
    iSetColor(0,51,51);
     iFilledRectangle(obst_x+3.5+1200,8.25+150,7.5,16.5);
     iFilledRectangle(obst_x+3.5+1200,150+8.25+33,7.5,16.5);
      iFilledRectangle(obst_x+3.5+1200,150+8.25+66,7.5,16.5);
       iFilledRectangle(obst_x+3.5+15+1200,8.25+150,7.5,16.5);
     iFilledRectangle(obst_x+3.5+15+1200,150+8.25+33,7.5,16.5);
      iFilledRectangle(obst_x+3.5+15+1200,150+8.25+66,7.5,16.5);



}

void cityobstacledraw2()
{
 iSetColor(255,204,255);
    iFilledRectangle(obst_x2,150,30,100);
    iSetColor(256,256,256);
    iFilledRectangle(obst_x2+3.5,8.25+150,7.5,16.5);
     iFilledRectangle(obst_x2+3.5,150+8.25+33,7.5,16.5);
      iFilledRectangle(obst_x2+3.5,150+8.25+66,7.5,16.5);
       iFilledRectangle(obst_x2+3.5+15,8.25+150,7.5,16.5);
     iFilledRectangle(obst_x2+3.5+15,150+8.25+33,7.5,16.5);
      iFilledRectangle(obst_x2+3.5+15,150+8.25+66,7.5,16.5);



    iSetColor(255,102,102);
    iFilledRectangle(obst_x2+400,150,30,100);
    iSetColor(204,102,255);
       iFilledRectangle(400+obst_x2+3.5,8.25+150,7.5,16.5);
     iFilledRectangle(400+obst_x2+3.5,150+8.25+33,7.5,16.5);
      iFilledRectangle(400+obst_x2+3.5,150+8.25+66,7.5,16.5);
       iFilledRectangle(400+obst_x2+3.5+15,8.25+150,7.5,16.5);
     iFilledRectangle(400+obst_x2+3.5+15,150+8.25+33,7.5,16.5);
      iFilledRectangle(400+obst_x2+3.5+15,150+8.25+66,7.5,16.5);
    iSetColor(102,0,153);
     iFilledRectangle(obst_x2+800,150,30,100);
    iSetColor(153,204,255);
        iFilledRectangle(obst_x2+3.5+800,8.25+150,7.5,16.5);
     iFilledRectangle(obst_x2+3.5+800,150+8.25+33,7.5,16.5);
      iFilledRectangle(obst_x2+3.5+800,150+8.25+66,7.5,16.5);
       iFilledRectangle(obst_x2+3.5+15+800,8.25+150,7.5,16.5);
     iFilledRectangle(obst_x2+3.5+15+800,150+8.25+33,7.5,16.5);
      iFilledRectangle(obst_x2+3.5+15+800,150+8.25+66,7.5,16.5);
    iSetColor(0,153,153);
       iFilledRectangle(obst_x2+1200,150,30,100);
    iSetColor(0,51,51);
     iFilledRectangle(obst_x2+3.5+1200,8.25+150,7.5,16.5);
     iFilledRectangle(obst_x2+3.5+1200,150+8.25+33,7.5,16.5);
      iFilledRectangle(obst_x2+3.5+1200,150+8.25+66,7.5,16.5);
       iFilledRectangle(obst_x2+3.5+15+1200,8.25+150,7.5,16.5);
     iFilledRectangle(obst_x2+3.5+15+1200,150+8.25+33,7.5,16.5);
      iFilledRectangle(obst_x2+3.5+15+1200,150+8.25+66,7.5,16.5);

}


void spaceobstacles1()
{
    //mercury
    iSetColor(210, 105, 30);
    iFilledCircle(obst_x,150+30,30);
    iSetColor(47, 79, 79);
    iFilledCircle(obst_x-1.5,150+20.25,4);
    iFilledCircle(obst_x+16.5,150+11.25,5);
    iFilledCircle(obst_x-10.5,150+6.25,3);
    iFilledCircle(obst_x+12.5,150+20.25,4);
    iFilledCircle(obst_x+16.5,150+50.25,5);
    iFilledCircle(obst_x-10.5,150+16.25,3);
    iFilledCircle(obst_x-11.5,150+25.25,4);
    iFilledCircle(obst_x+16.5,150+23.25,5);
    iFilledCircle(obst_x-20.5,150+40.25,3);


    //venus
    iSetColor(233-50, 150-50, 122-50);
    iFilledCircle(obst_x+400,150+40,40);
    iSetColor(233, 150, 122);
    iFilledCircle(obst_x+400,150+35,35);


    //earth
    /*iSetColor(50, 50, 139);
    iFilledCircle(obst_x+800,150+40,40);*/
    //iSetColor(72, 61, 139);
    iSetColor(0, 191, 255);
    iFilledCircle(obst_x+800,150+35,35);
    iSetColor(127, 255, 0);
    iFilledCircle(obst_x+800-1.5,150+20.25,4);
    iFilledCircle(obst_x+800+16.5,150+11.25,5);
    iFilledCircle(obst_x+800-10.5,150+6.25,3);
    iFilledCircle(obst_x+800+12.5,150+20.25,4);
    iFilledCircle(obst_x+800+16.5,150+50.25,5);
    iFilledCircle(obst_x+800-10.5,150+16.25,3);
    iFilledCircle(obst_x+800-11.5,150+25.25,4);
    iFilledCircle(obst_x+800+16.5,150+23.25,5);
    iFilledCircle(obst_x+800-20.5,150+40.25,3);



    //mars
    iSetColor(150,34,34);
    iFilledCircle(obst_x+1200,150+40,40);
    iSetColor(178, 34, 34);
    iFilledCircle(obst_x+1200,150+35,35);

    iSetColor(154,30,30);
    iFilledCircle(obst_x+1200-1.5,150+20.25,4);
    iFilledCircle(obst_x+1200+16.5,150+11.25,5);
    iFilledCircle(obst_x+1200-10.5,150+6.25,3);

    iFilledCircle(obst_x+1200-11.5,150+25.25,8);
    iFilledCircle(obst_x+1200+16.5,150+23.25,5);
    iFilledCircle(obst_x+1200-20.5,150+40.25,9);

    /*saturn
    iSetColor(189-50, 183-50, 107-50);
    iFilledCircle(obst_x+1600,150+40,40);
     iSetColor(189, 183, 107);
    iFilledCircle(obst_x+1600,150+35,35);*/

}

void spaceobstacles2()
{
    //mercury
    iSetColor(210, 105, 30);
    iFilledCircle(obst_x2,150+30,30);
    iSetColor(47, 79, 79);
    iFilledCircle(obst_x2-1.5,150+20.25,4);
    iFilledCircle(obst_x2+16.5,150+11.25,5);
    iFilledCircle(obst_x2-10.5,150+6.25,3);
    iFilledCircle(obst_x2+12.5,150+20.25,4);
    iFilledCircle(obst_x2+16.5,150+50.25,5);
    iFilledCircle(obst_x2-10.5,150+16.25,3);
    iFilledCircle(obst_x2-11.5,150+25.25,4);
    iFilledCircle(obst_x2+16.5,150+23.25,5);
    iFilledCircle(obst_x2-20.5,150+40.25,3);


    //venus
    iSetColor(233-50, 150-50, 122-50);
    iFilledCircle(obst_x2+400,150+40,40);
    iSetColor(233, 150, 122);
    iFilledCircle(obst_x2+400,150+35,35);


    //earth
    /*iSetColor(50, 50, 139);
    iFilledCircle(obst_x2+800,150+40,40);*/
    //iSetColor(72, 61, 139);
    iSetColor(0, 191, 255);
    iFilledCircle(obst_x2+800,150+35,35);
    iSetColor(127, 255, 0);
    iFilledCircle(obst_x2+800-1.5,150+20.25,4);
    iFilledCircle(obst_x2+800+16.5,150+11.25,5);
    iFilledCircle(obst_x2+800-10.5,150+6.25,3);
    iFilledCircle(obst_x2+800+12.5,150+20.25,4);
    iFilledCircle(obst_x2+800+16.5,150+50.25,5);
    iFilledCircle(obst_x2+800-10.5,150+16.25,3);
    iFilledCircle(obst_x2+800-11.5,150+25.25,4);
    iFilledCircle(obst_x2+800+16.5,150+23.25,5);
    iFilledCircle(obst_x2+800-20.5,150+40.25,3);



    //mars
    iSetColor(150,34,34);
    iFilledCircle(obst_x2+1200,150+40,40);
    iSetColor(178, 34, 34);
    iFilledCircle(obst_x2+1200,150+35,35);

    iSetColor(154,30,30);
    iFilledCircle(obst_x2+1200-1.5,150+20.25,4);
    iFilledCircle(obst_x2+1200+16.5,150+11.25,5);
    iFilledCircle(obst_x2+1200-10.5,150+6.25,3);

    iFilledCircle(obst_x2+1200-11.5,150+25.25,8);
    iFilledCircle(obst_x2+1200+16.5,150+23.25,5);
    iFilledCircle(obst_x2+1200-20.5,150+40.25,9);

    /*saturn
    iSetColor(189-50, 183-50, 107-50);
    iFilledCircle(obst_x+1600,150+40,40);
     iSetColor(189, 183, 107);
    iFilledCircle(obst_x+1600,150+35,35);*/




}


/*void glooblu()
{
    //draw glooblu

    iSetColor(120,0,255);
	iFilledCircle(pic_x, pic_y+30,30);
	iSetColor(255,0,120);
	iFilledCircle(pic_x,pic_y+30,25);
	iSetColor(255,0,0);
	iFilledCircle(pic_x,pic_y+30,20);
	iSetColor(255,255,255);
	iFilledCircle(pic_x,pic_y+30,10);
	iSetColor(0,0,0);
	iFilledCircle(pic_x,pic_y+30,5);
}*/

void showscore()
{
    if(game_over==0 && level!=0)
    {
        iSetColor(0,0,255);
        itoa(score,result_on,10);
        iText(220,460,result_on,GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,0,255);
        iText(100,460,"SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
    }

}
void glooblu()
{
    //draw glooblu
    if(level == 1 || level == 2){
    iSetColor(255,250,250);

	iFilledEllipse(pic_x-25,pic_y+55,10,15);
	iFilledEllipse(pic_x+25,pic_y+55,10,15);
	iSetColor(255,153,153);
    iFilledEllipse(pic_x-25,pic_y+55,5,8);
	iFilledEllipse(pic_x+25,pic_y+55,5,8);

    iSetColor(255,250,250);
	iFilledEllipse(pic_x, pic_y+30,37,27);
	iSetColor(0,0,0);
	iFilledCircle(pic_x-13,pic_y+40,5);
	iFilledCircle(pic_x+13,pic_y+40,5);
	//iFilledCircle(pic_x,pic_y+25,3);

		iLine(pic_x-30,pic_y+25,pic_x-45,pic_y+25);
	iLine(pic_x+30,pic_y+25,pic_x+45,pic_y+25);
	iLine(pic_x-30,pic_y+27,pic_x-45,pic_y+32);
	iLine(pic_x+30,pic_y+27,pic_x+45,pic_y+32);
	iLine(pic_x-30,pic_y+23,pic_x-45,pic_y+18);
	iLine(pic_x+30,pic_y+23,pic_x+45,pic_y+18);

	iSetColor(255,1,0);
	iFilledEllipse(pic_x,pic_y+17,10,3);
	iSetColor(255,153,153);
	iFilledCircle(pic_x-23,pic_y+25,7);
    iFilledCircle(pic_x+23,pic_y+25,7);
    iSetColor(255,255,255);
    iLine(pic_x-13,pic_y+40,pic_x-18,pic_y+43);
    iLine(pic_x+13,pic_y+40,pic_x+18,pic_y+43);

	/*

	iSetColor(255,0,120);
	iFilledCircle(pic_x,pic_y+30,25);
	iSetColor(255,0,0);
	iFilledCircle(pic_x,pic_y+30,20);
	iSetColor(255,255,255);
	iFilledCircle(pic_x,pic_y+30,10);
	iSetColor(0,0,0);
	iFilledCircle(pic_x,pic_y+30,5);*/
    }

     else if(level==3)

    {

        iSetColor(255,250,250);

	iFilledEllipse(pic_x-11,pic_y+40,6,10);
	iFilledEllipse(pic_x+11,pic_y+40,6,10);
	iSetColor(255,153,153);
    iFilledEllipse(pic_x-11,pic_y+40,4,9);
	iFilledEllipse(pic_x+11,pic_y+40,4,9);

    iSetColor(255,250,250);
	iFilledEllipse(pic_x, pic_y+30,20,13);
	iSetColor(0,0,0);
	iFilledCircle(pic_x-6,pic_y+35,3);
	iFilledCircle(pic_x+6,pic_y+35,3);
	//iFilledCircle(pic_x,pic_y+25,3);

		/*iLine(pic_x-17,pic_y+30,pic_x-20,pic_y+30);
	iLine(pic_x+30,pic_y+25,pic_x+45,pic_y+25);
	iLine(pic_x-30,pic_y+27,pic_x-45,pic_y+32);
	iLine(pic_x+30,pic_y+27,pic_x+45,pic_y+32);
	iLine(pic_x-30,pic_y+23,pic_x-45,pic_y+18);
	iLine(pic_x+30,pic_y+23,pic_x+45,pic_y+18);*/

	iSetColor(255,1,0);
	iFilledEllipse(pic_x,pic_y+25,5,1.5);
	iSetColor(255,153,153);
	iFilledCircle(pic_x-13,pic_y+30,4);
    iFilledCircle(pic_x+13,pic_y+30,4);
    /*iSetColor(255,255,255);
    iLine(pic_x-13,pic_y+40,pic_x-18,pic_y+43);
    iLine(pic_x+13,pic_y+40,pic_x+18,pic_y+43);/*

	/*

	iSetColor(255,0,120);
	iFilledCircle(pic_x,pic_y+30,25);
	iSetColor(255,0,0);
	iFilledCircle(pic_x,pic_y+30,20);
	iSetColor(255,255,255);
	iFilledCircle(pic_x,pic_y+30,10);
	iSetColor(0,0,0);
	iFilledCircle(pic_x,pic_y+30,5);*/

	//SPACESHIP
	   iSetColor(135,206,250);
	iCircle(pic_x,pic_y+30,30);
	iSetColor(255,0,255);
	iFilledEllipse(pic_x,pic_y,20,7.5);
	iFilledEllipse(pic_x,pic_y+10,40,10);
	iSetColor(255,215,0);
	iFilledCircle(pic_x,pic_y+8,3);
	iFilledCircle(pic_x-10,pic_y+9,2.5);
	iFilledCircle(pic_x+10,pic_y+9,2.5);
	iFilledCircle(pic_x-20,pic_y+10,2);
	iFilledCircle(pic_x+20,pic_y+10,2);
	iFilledCircle(pic_x-30,pic_y+11,1.5);
	iFilledCircle(pic_x+30,pic_y+11,1.5);
	iSetColor(256,256,256);
	iLine(pic_x,pic_y-7.5,pic_x,pic_y-18);
	iLine(pic_x-6,pic_y-7.5,pic_x-13,pic_y-15);
	iLine(pic_x+6,pic_y-7.5,pic_x+13,pic_y-15);
	iSetColor(0,0,256);
	iFilledCircle(pic_x-.5,pic_y-18,3);
	iFilledCircle(pic_x-13.5,pic_y-15,3);
	iFilledCircle(pic_x+13.5,pic_y-15,3);

    }

}

void drawcoins()
{
    if(level!=3){
    //coins
	if(pic_x<=obst_x){
	iSetColor(233, 150, 122);
	iFilledCircle(obst_x,300,13);
	iSetColor(255, 215, 0);
	iFilledCircle(obst_x,300,10);
	iSetColor(255,255,255);
	iPoint(obst_x+4,302,1);

    iSetColor(233, 150, 122);
	iFilledCircle(obst_x+1200,300,13);
	iSetColor(255, 215, 0);
	iFilledCircle(obst_x+1200,300,10);
	iSetColor(255,255,255);
	iPoint(obst_x+1204,302,1);
	}

	if(pic_x==obst_x && pic_y>290 && game_over==0)
    {
        coin++;
        score+=5;

    }


if(pic_x<=obst_x2){
	iSetColor(233, 150, 122);
	iFilledCircle(obst_x2,300,13);
	iSetColor(255, 215, 0);
	iFilledCircle(obst_x2,300,10);
	iSetColor(255,255,255);
	iPoint(obst_x2+4,302,1);

    iSetColor(233, 150, 122);
	iFilledCircle(obst_x2+1200,300,13);
	iSetColor(255, 215, 0);
	iFilledCircle(obst_x2+1200,300,10);
	iSetColor(255,255,255);
	iPoint(obst_x2+1204,302,1);
	}

	if(pic_x==obst_x2)
    {
        coin++;
        score+=5;

    }
}
}





void iDraw() {
	//place your drawing codes here

	iClear();
    //iSetColor(255,255,255);
    //iFilledRectangle(0,0,1000,500);


    if(level==1)
    {
        iShowBMP(0,0,"candyland2.bmp");
        iSetColor(255,0,0);
        iText(200,400,"LEVEL ONE : CANDYLAND",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(level==2)
    {
        iShowBMP(0,0,"night.bmp");
        iSetColor(0,255,0);
        iText(200,400,"LEVEL TWO : METROPOLIS",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(level==3)
    {
        iShowBMP(0,0,"galaxy.bmp");
        iSetColor(255,255,255);
        iText(200,400,"LEVEL THREE : GALACTICA",GLUT_BITMAP_TIMES_ROMAN_24);
    }

    glooblu();



	drawcoins();
	showscore();
	showlife();


    //showing coins in screen while playing
    if(level!=0 && level!=3){
    itoa(coin,coins,10);
    //itoa(life,lifes,10);
    iSetColor(255,0,0);
    iText(900-10,453,coins,GLUT_BITMAP_TIMES_ROMAN_24);
    //iText(10,443,lifes,GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(233, 150, 122);
	iFilledCircle(850,460,13);
	iSetColor(255, 215, 0);
	iFilledCircle(850,460,10);
	iSetColor(255,255,255);
	iPoint(854,462,1);}

	//the bridge
	if(level==1)
    {
    iSetColor(205,102,29);
	iFilledRectangle(0,140,1000,10);
	//iSetColor(248,193,249);
	iSetColor(255,255,255);
	iFilledRectangle(0,120,1000,20);
	iSetColor(205,102,29);
	iFilledRectangle(0,110,1000,10);
	//to show that the ball moves
	for(int pl=0; pl<=1000;pl+=100){
        //iSetColor(r, 0, b);
        //iSetColor(240,242,2);
        iSetColor(255,0,0);
        iFilledRectangle(obst_x+pl,120,20,20);
        iFilledRectangle(obst_x2+pl,120,20,20);
        /*iLine(obst_x+pl,0,obst_x+pl+100,150);
        iLine(obst_x+pl+100,0,obst_x+pl,150);
        iLine(obst_x2+pl,0,obst_x2+pl+100,150);
        iLine(obst_x2+pl+100,0,obst_x2+pl,150);*/
    }

	}
	else if(level==2)
    {
        iSetColor(107, 92, 134);
        iFilledRectangle(0,140,1000,10);
	//to show that the ball moves
	for(int pl=0; pl<=1000;pl+=100){
        iSetColor(107, 92, 134);
        iFilledRectangle(obst_x+pl,0,10,150);
        iFilledRectangle(obst_x+pl,0,100,10);
        iFilledRectangle(obst_x+pl+100,0,10,150);
        iLine(obst_x+pl,0,obst_x+pl+100,150);
        iLine(obst_x+pl+100,0,obst_x+pl,150);

        iFilledRectangle(obst_x2+pl,0,10,150);
        iFilledRectangle(obst_x2+pl,0,100,10);
        iFilledRectangle(obst_x2+pl+100,0,10,150);
        iLine(obst_x2+pl,0,obst_x2+pl+100,150);
        iLine(obst_x2+pl+100,0,obst_x2+pl,150);

    }
    }
    if(level==1)
    {
        //iShowBMP(obst_x+300,300,"candy1.bmp");
        candyobstacledraw();
        candyobstacledraw2();
        //candyobstaclebmp1();
        //candyobstaclebmp2();
    }
    else if(level==2)
    {
        cityobstacledraw();
        cityobstacledraw2();
    }
    else if(level==3)
    {
        spaceobstacles1();
        spaceobstacles2();
    }


	//gameover

	gameover();
	if(game_over==1)
    {
        highscorefunc();
        if(level==1){
        iClear();
        iSetColor(255,0,0);
        iShowBMP(0,0,"gameover.bmp");

        iText(10,450,"PRESS a TO RESTART",GLUT_BITMAP_TIMES_ROMAN_24);
        itoa(score,result,10);
        itoa(high_score,high_result,10);

        //show score
        iText(600,250,result,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(720,116,high_result,GLUT_BITMAP_TIMES_ROMAN_24);}
        //level=1;
        //level_speed=10;
        else if(level==2){
            iClear();
        iSetColor(255,255,255);
        iShowBMP(0,0,"gameover2.bmp");

        iText(10,480,"PRESS a TO RESTART",GLUT_BITMAP_TIMES_ROMAN_24);


        itoa(score,result,10);
        itoa(high_score,high_result,10);

        //show score
        iSetColor(255,0,0);
        iText(600-60,250+40,result,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(720-30,116+20,high_result,GLUT_BITMAP_TIMES_ROMAN_24);
        }

        else if(level==3){
            iClear();
        iSetColor(255,255,255);
        iShowBMP(0,0,"gameover3.bmp");

        iText(10,480,"PRESS a TO RESTART",GLUT_BITMAP_TIMES_ROMAN_24);


        itoa(score,result,10);
        itoa(high_score,high_result,10);

        //show score
        iSetColor(255,0,0);
        iText(600,240,result,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(720,116-34,high_result,GLUT_BITMAP_TIMES_ROMAN_24);
        }

    }


	if(game_start==0 && game_over==0)
    {
        if(level==0)
        {
            iShowBMP(125,0,"menu.bmp");
        }

    }
/*    startgame

    if(game_start==0)
    {
        if(level==1) iText(100,300,"PRESS a TO START GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    }*/
    helpdraw();

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
    void iMouseMove(int mx, int my) {


	//place your codes here


}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		if(mx >=5 && mx <=25 && my>=460 && my<=480)
    {
        if(helpon==0)
        {
            helpon=1;
        }
        else
        {
            helpon=0;
        }
    }
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'x') {
		//do something with 'x'
		exit(0);
	}
	//place your codes for other keys here
    if (key == 'a')
    {

        life=3;
        counts=0;
        game_over=0;
        coin=0;
        pic_y=150;
        if(level==0)
            level=1;

        game_start=1;

        storescore=score;
        score=0;

        iResumeTimer(2);
        iResumeTimer(3);
        iResumeTimer(4);

    }
    //if (key == 's')




}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	if (key == GLUT_KEY_LEFT) {

	}
	if (key == GLUT_KEY_RIGHT) {

	}
	if (key == GLUT_KEY_UP) {
		jump=1;
        PlaySound(TEXT("Jump.wav"),NULL,SND_ASYNC);



	}
	if (key == GLUT_KEY_DOWN) {
            if(level==3)
        {
            jumpdown=1;
            PlaySound(TEXT("Jump.wav"),NULL,SND_ASYNC);
        }

	}
	//place your codes for other keys here
}

int main() {
	//place your own initialization codes here.
        PlaySound(TEXT("background.wav"),NULL,SND_ASYNC | SND_LOOP);


	iSetTimer(10,jumpup);
	iSetTimer(10,falldown);
	iSetTimer(level_speed,obstacleslide);
	iSetTimer(1000,scorefunc);
    iSetTimer(level_speed,obstacle2slide);
    iSetTimer(50,colorchange);
    iSetTimer(1000,lifetimef);
    if(game_start==0)
    {
        iPauseTimer(2);
        iPauseTimer(3);
        iPauseTimer(4);
    }

	iInitialize(1000, 500, "GLOOBLU JUMP");
	return 0;
}
