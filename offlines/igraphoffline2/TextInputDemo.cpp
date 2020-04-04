# include "iGraphics.h"

char str[100], str2[100];
int len;
int mode,k,r,g=10,b=255,x=400,l=0;
int s[]={0,0,0,0,0,0,0};

void colorchange()
{
    g+=10;
    b-=10;
    if(g>=255)
        g=10;
    if(b<=10)
        b=255;

}

void drawTextBox()
{
	iSetColor(255, 255, 255);
	iRectangle(50, 150, 350, 30);
}
void slide()
{
    x--;
    if(x==(-60*strlen(str2)))
        x=430;

}

void drawsegments(int j){




        iSetColor(r, g, b);
		if(s[0]==1)
            iFilledRectangle(x+j*60,255,2,43);
        if(s[1]==1)
            iFilledRectangle(x+j*60,302,2,43);
        if(s[2]==1)
            iFilledRectangle(x+j*60+6,345,43,2);
        if(s[3]==1)
            iFilledRectangle(x+j*60+53,302,2,43);
        if(s[4]==1)
            iFilledRectangle(x+j*60+6,300,43,2);
        if(s[5]==1)
            iFilledRectangle(x+j*60+53,255,2,43);
        if(s[6]==1)
            iFilledRectangle(x+j*60+6,255,43,2);



}
void setsegments(char gs[])
{
    int i,j;
    for(j=0;j<strlen(gs);j++){
            for(int q=0;q<7;q++)
            s[q]=0;
    switch(gs[j]){
    case 'A' :
        for(i=0;i<7;i++)
        {
            if(i!=6)
                s[i]=1;
        }
        drawsegments(j);
        break;
    case 'b' :
        for(i=0;i<7;i++)
        {
            if(i!=2 && i!=3)
                s[i]=1;
        }
        drawsegments(j);
        break;
     case 'C' :
        for(i=0;i<7;i++)
        {
            if(i!=3 && i!=4 && i!=5)
                s[i]=1;
        }
        drawsegments(j);
        break;
      case 'D':
        for(i=0;i<7;i++)
        {
            if(i!=4)
                s[i]=1;
        }
        drawsegments(j);
        break;
     case 'E':
        for(i=0;i<7;i++)
        {
            if(i!=3 && i!=5)
                s[i]=1;
        }
        drawsegments(j);
        break;
     case 'F':
        for(i=0;i<7;i++)
        {
            if(i!=3 && i!=5 && i!=6)
                s[i]=1;
        }
        drawsegments(j);
        break;
    case '0':
        for(i=0;i<7;i++)
        {
            if(i!=4)
                s[i]=1;
        }
        drawsegments(j);
        break;
    case '1':
        for(i=0;i<7;i++)
        {
            if(i!=0 && i!=1 && i!=2 && i!=4 && i!=6)
                s[i]=1;
        }
        drawsegments(j);
        break;
    case '2':
        for(i=0;i<7;i++)
        {
            if(i!=1 && i!=5)
                s[i]=1;
        }
        drawsegments(j);
        break;
    case '3':
        for(i=0;i<7;i++)
        {
            if(i!=1 && i!=0)
                s[i]=1;
        }
        drawsegments(j);
        break;
    case '4':
        for(i=0;i<7;i++)
        {
            if(i!=0 && i!=2 && i!=6)
                s[i]=1;
        }
        drawsegments(j);
        break;
    case '5':
        for(i=0;i<7;i++)
        {
            if(i!=3 && i!=0)
                s[i]=1;
        }
        drawsegments(j);
        break;
    case '6':
        for(i=0;i<7;i++)
        {
            if(i!=3)
                s[i]=1;
        }
        drawsegments(j);
        break;
    case '7':
        for(i=0;i<7;i++)
        {
            if(i!=1 && i!=4 && i!=0 && i!=6)
                s[i]=1;
        }
        drawsegments(j);
        break;
    case '8':
        for(i=0;i<7;i++)
        {

                s[i]=1;
        }
        drawsegments(j);
        break;
    case '9':
        for(i=0;i<7;i++)
        {
            if(i!=0  )
                s[i]=1;
        }
        drawsegments(j);
        break;
    }
    }
}


/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();
	if(mode == 1)
    {
        iSetColor(255, 90, 0);
        iText(55, 160, str);

    }
	setsegments(str2);
	drawTextBox();
	if(mode==0) iSetColor(255,0,255);
    else iSetColor(255,90,0);
	iText(10, 30, "Click to activate the box, enter to finish.");

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
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
		if(mx >= 50 && mx <= 400 && my >= 150 && my <= 180 && mode == 0)
		{
			mode = 1;
		}
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


    if(mode == 1)
    {
        if(key == '\r')
        {

            mode = 0;
            strcpy(str2, str);
            printf("%s\n", str2);
            for(l = 0; l < len; l++)
                str[l] = 0;
            len = 0;
        }
        else
        {

            str[len] = key;
            len++;
        }
    }

	if(key == 'x')
	{
		//do something with 'x'
		exit(0);
	}
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
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}

	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.
	len = 0;
	mode = 0;
    str[0]= 0;


	iSetTimer(50,colorchange);
	iSetTimer(10,slide);
	iInitialize(500, 500, "TextSlider");
	return 0;
}
