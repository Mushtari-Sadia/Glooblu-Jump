# include "iGraphics.h"
#include<time.h>
# define PI 3.1416

double s,m,h;
int ho,mi,se;
int sec;
int minx;
int hrx;
double x=200,y=295;
double x1=200,y_1=270;
double x2=200,y_2=250;







void sh(){

    s=sec*(PI/30);

        x=200+95*sin(s);
        y=200+95*cos(s);



sec++;

}



void mh(){

    m=minx*(PI/1800);


        x1=200+70*sin(m);
        y_1=200+70*cos(m);



minx++;

}




void hh(){

    h=hrx*(PI/21600);




        x2=200+50*sin(h);
        y_2=200+50*cos(h);

hrx++;
}






void iDraw() {


    iClear() ;
    iSetColor(20, 200, 200);
	iFilledCircle(200,200,115);

	iSetColor(255,255,255);
	iFilledCircle(200,200,100);
    iSetColor(0,0,255);
    iLine(200,200,x,y);
    iSetColor(255,0,255);
    iLine(200,200,x1,y_1);
    iSetColor(0,255,80);
    iLine(200,200,x2,y_2);





	iSetColor(0,0,0);
	iText(196,304,"12");
	iText(250,288,"1");
	iText(287,250,"2");
	iText(305,200,"3");
	iText(290,150-4,"4");
	iText(250,105,"5");
	iText(198,90,"6");
	iText(113-8,150-10,"8");
	iText(150,113-13,"7");
	iText(90,200,"9");
	iText(113-11,250+2,"10");
	iText(150-5,288+1,"11");
    iSetColor(0,0,0);
	iFilledCircle(200,200,5);
	//place your drawing codes here



}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{

	//place your codes for other keys here
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


	//place your codes for other keys here
}


int main() {


  int choice;
     printf("Please enter 1 for system time or enter 2 for user input:");
    scanf("%d",&choice);
    if (choice==1)
    {
        time_t now;
        struct tm *now_tm;

        now = time(NULL);
        now_tm = localtime(&now);
        ho = now_tm->tm_hour;
        mi = now_tm ->tm_min;
        se = now_tm ->tm_sec;
    }
    if(choice==2)
    {
        printf("Enter hour,minute and second respectively\n");
        scanf("%d %d %d",&ho,&mi,&se);
    }
    sec=se;
    minx=mi*60;
    if(ho==12)
        ho=0;
    hrx=ho*3600+mi*60;



    iSetTimer(1000,sh);

    iSetTimer(1000,mh);

    iSetTimer(1000,hh);



	iInitialize(400, 400, "clock");
	return 0;
}
