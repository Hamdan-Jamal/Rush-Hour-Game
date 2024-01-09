//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
# include <cstdlib>
# include <ctime>
#include <string>
#include <cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
int pass_x1,pass_y1;
int loca_x1,loca_y1;
int c1=0; //variable for the random destination of pessenger
int t=1800; // variable for declaration of time // it will countdown in milliseconds and complete the 3 minutes.

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */

int Taxi; //variable for the change in taxi colors

void pas1() //random location of passenger 1
{
	srand(unsigned (time(0)));
	pass_x1= 205 + rand() % 355;
	pass_y1= 17 + rand() % 609;

}

void loc1() //random destination for passenger
{
srand(unsigned (time(0)));
	loca_x1= 205 + rand() % 355;
	loca_y1= 17 + rand() % 609;
}


void Menu()
{															   // Function for displaying the menu screen
	glClearColor(1 /*Red Component*/, 1,					   // 148.0/255/*Green Component*/,
				 1 /*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT);							   // Update the colors
	DrawSquare(310, 420, 220, colors[ORANGE]);
	DrawSquare(470, 420, 220, colors[ORANGE]);
	DrawString(475, 525, "Play", colors[BLACK]);
	DrawRoundRect(310, 320, 380, 90, colors[YELLOW], 0);
	DrawString(445, 355, "Leaderboard", colors[BLACK]);
    DrawString(25, 755, "Welcome to the RUSH HOUR, click on play to start the game.", colors[BLACK]);
	glutSwapBuffers();
}


void SetCanvasSize(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int xI = 13, yI = 725;

void drawTaxi_red()  // My red Taxi
{
	DrawSquare(xI + 2, yI, 13 + 4, colors[INDIAN_RED]);
	DrawTriangle(xI, yI, xI + 40, yI, xI + 20, yI + 10, colors[RED]);
	DrawCircle(xI + 19, yI, 5, colors[BLACK]);
	DrawCircle(xI + 2, yI, 5, colors[BLACK]);
	glutPostRedisplay();
	
	
}
void drawTaxi_yellow() //My Yelow taxi
{
	DrawSquare(xI + 2, yI, 13 + 4, colors[ORANGE]);
	DrawTriangle(xI, yI, xI + 40, yI, xI + 20, yI + 10, colors[ORANGE]);
	DrawCircle(xI + 19, yI, 5, colors[BLACK]);
	DrawCircle(xI + 2, yI, 5, colors[BLACK]);
	glutPostRedisplay();
	
	
}

int xs = 561, ys = 318;
void drawCar1() //drawing first random car
{
	DrawSquare(xs, ys, 25, colors[BLUE]);
	DrawCircle(xs + 5, ys, 4, colors[BLACK]);
	DrawCircle(xs + 18, ys, 4, colors[BLACK]);
	glutPostRedisplay();
	
}
int  xA = 470, yA = 320;
void drawCar2() //drawing second random car
{
DrawSquare(xA, yA, 25, colors[PURPLE]);
	DrawCircle(xA + 18, yA, 4, colors[BLACK]);
	DrawCircle(xA + 5, yA, 4, colors[BLACK]);
    	glutPostRedisplay();
	
}
bool flag = true;
void moveCar() //function for moving car
{

	if (xs > 10 && flag)
	{ // car1 moves right
		xs -= 8;
		// cout << "going left";
		if (xs < 450)

			flag = false;
	}
	else if (xs < 1010 && !flag)
	{ // car1 moves left
		// cout << "go right";
		xs += 8;
		if (xs > 730)
			flag = true;
	}
	glutPostRedisplay();
}
bool flag2 = true;
void moveCar2()
{

	if (yA > 1 && flag2)
	{ // car moves down
		yA -= 10;
		// cout << "going down";
		if (yA < 385)

			flag2 = false;
	}
	else if (yA < 1010 && !flag2)
	{ // car2 moves up
		// cout << "going up";
		yA += 10;
		if (yA > 700  )
			flag2 = true;
	}
	glutPostRedisplay();
}

/*
 * Main Canvas drawing function.
 * */

void TimerEnd(int m)
{


t--;
if (t==0)
{
	exit(1);
}
	
	glutTimerFunc(100, TimerEnd, 0);
}


	void
	GameDisplay() /**/
{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1 /*Red Component*/, 1,					   // 148.0/255/*Green Component*/,
				 1 /*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT);							   // Update the colors
	// Red Square

	DrawSquare(405, 75, 50, colors[BLACK]);	 // 9th coloumn
	DrawSquare(405, 120, 50, colors[BLACK]); // 9th coloumn
	DrawSquare(405, 170, 50, colors[BLACK]); // 9th coloumn
	DrawSquare(405, 220, 50, colors[BLACK]); // 9th coloumn
	DrawSquare(405, 265, 50, colors[BLACK]); // 9th coloumn
	DrawSquare(455, 265, 50, colors[BLACK]); // 10th coloumn
	DrawSquare(505, 265, 50, colors[BLACK]); // 11th coloumn
	DrawSquare(555, 265, 50, colors[BLACK]); // 12th coloumn
	DrawSquare(605, 265, 50, colors[BLACK]); // 13th coloumn
	DrawSquare(655, 265, 50, colors[BLACK]); // 14th coloumn
	DrawSquare(705, 265, 50, colors[BLACK]); // 15th coloumn
	DrawSquare(106, 210, 50, colors[BLACK]); // 3rd 4th coloumns Big box
	DrawSquare(106, 255, 50, colors[BLACK]); // 3rd 4th coloumns Big box
	DrawSquare(106, 290, 50, colors[BLACK]); // 3rd 4th coloumns Big box
	DrawSquare(155, 210, 50, colors[BLACK]); // 3rd 4th coloumns Big box
	DrawSquare(155, 255, 50, colors[BLACK]); // 3rd 4th coloumns Big box
	DrawSquare(155, 290, 50, colors[BLACK]); // 3rd 4th coloumns Big box
	DrawSquare(155, 500, 50, colors[BLACK]); // 4th coloumn
	DrawSquare(155, 455, 50, colors[BLACK]); // 4th coloumn
	DrawSquare(155, 535, 50, colors[BLACK]); // 4th coloumn
	DrawSquare(105, 535, 50, colors[BLACK]); // 3rd coloumn
	DrawSquare(355, 500, 50, colors[BLACK]); // 8th coloumn
	DrawSquare(355, 455, 50, colors[BLACK]); // 8th coloumn
	DrawSquare(355, 535, 50, colors[BLACK]); // 8th coloumn
	DrawSquare(305, 535, 50, colors[BLACK]); // 7th coloumn
	DrawSquare(655, 500, 50, colors[BLACK]); // 14th coloumn
	DrawSquare(655, 455, 50, colors[BLACK]); // 14th coloumn
	DrawSquare(655, 535, 50, colors[BLACK]); // 14th coloumn
	DrawSquare(705, 535, 50, colors[BLACK]); // 15th coloumn
	DrawSquare(755, 535, 50, colors[BLACK]); // 16th coloumn
	DrawSquare(805, 535, 50, colors[BLACK]); // 17th coloumn
	DrawSquare(855, 535, 50, colors[BLACK]); // 18th coloumn
	DrawSquare(855, 580, 50, colors[BLACK]); // 18th coloumn
	DrawSquare(855, 620, 50, colors[BLACK]); // 18th coloumn
	DrawSquare(155, 650, 50, colors[BLACK]); // line on 4 5 and 6 coloumn
	DrawSquare(205, 650, 50, colors[BLACK]); //
	DrawSquare(255, 650, 50, colors[BLACK]); //
	DrawSquare(505, 650, 50, colors[BLACK]); // line on 11th
	DrawSquare(555, 650, 50, colors[BLACK]); // line on 12th
	DrawSquare(605, 650, 50, colors[BLACK]); // line on 13th
	DrawSquare(655, 650, 50, colors[BLACK]); // line on 14th
	DrawSquare(705, 650, 50, colors[BLACK]); // line on 15th
	DrawSquare(755, 650, 50, colors[BLACK]); // line on 16th
	DrawSquare(805, 650, 50, colors[BLACK]); // line on 17th
	DrawSquare(855, 650, 50, colors[BLACK]); // line on 18th
	DrawSquare(905, 650, 50, colors[BLACK]); // line on 19th
	DrawSquare(955, 650, 50, colors[BLACK]); // line on 20th coloumn
	DrawSquare(806, 210, 50, colors[BLACK]); // 17th and 18th coloumns Big box
	DrawSquare(806, 255, 50, colors[BLACK]); // 17th and 18th coloumns Big box
	DrawSquare(806, 290, 50, colors[BLACK]); // 17th and 18th coloumns Big box
	DrawSquare(855, 210, 50, colors[BLACK]); // 17th and 18th coloumns Big box
	DrawSquare(855, 255, 50, colors[BLACK]); // 17th and 18th coloumns Big box
	DrawSquare(855, 290, 50, colors[BLACK]); // 17th and 18th coloumns Big box

	// Green Square
	// DrawSquare( 250 , 250 ,20,colors[GREEN]);

	// Display Score
	DrawString(50, 800, "Score=0", colors[DARK_SALMON]);

	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	// DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[GREEN] );
	DrawTriangle(157, 360, 197, 360, 177, 400, colors[GREEN]); // bush on 2nd tree trunk
	DrawTriangle(360, 603, 400, 603, 380, 643, colors[GREEN]); // bush on 2nd tree trunk
	DrawTriangle(860, 360, 900, 360, 880, 400, colors[GREEN]); // bush on 3rd tree trunk

	// DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	DrawLine(0, 785, 1020, 785, 3, colors[YELLOW]);
	DrawLine(3, 760, 1005, 760, 5, colors[BLACK]);
	DrawLine(5, 760, 5, 3, 5, colors[BLACK]);
	DrawLine(55.25, 760, 55.25, 3, 2, colors[BLACK]);
	DrawLine(105.25, 760, 105.25, 3, 2, colors[BLACK]);
	DrawLine(155.25, 760, 155.25, 3, 2, colors[BLACK]);
	DrawLine(205.25, 760, 205.25, 3, 2, colors[BLACK]);
	DrawLine(255.25, 760, 255.25, 3, 2, colors[BLACK]);
	DrawLine(305.25, 760, 305.25, 3, 2, colors[BLACK]);
	DrawLine(355.25, 760, 355.25, 3, 2, colors[BLACK]);
	DrawLine(405.25, 760, 405.25, 3, 2, colors[BLACK]);
	DrawLine(455.25, 760, 455.25, 3, 2, colors[BLACK]);
	DrawLine(505.25, 760, 505.25, 3, 2, colors[BLACK]);
	DrawLine(555.25, 760, 555.25, 3, 2, colors[BLACK]);
	DrawLine(605.25, 760, 605.25, 3, 2, colors[BLACK]);
	DrawLine(655.25, 760, 655.25, 3, 2, colors[BLACK]);
	DrawLine(705.25, 760, 705.25, 3, 2, colors[BLACK]);
	DrawLine(755.25, 760, 755.25, 3, 2, colors[BLACK]);
	DrawLine(805.25, 760, 805.25, 3, 2, colors[BLACK]);
	DrawLine(855.25, 760, 855.25, 3, 2, colors[BLACK]);
	DrawLine(905.25, 760, 905.25, 3, 2, colors[BLACK]);
	DrawLine(955.25, 760, 955.25, 3, 2, colors[BLACK]);
	DrawLine(1005.25, 760, 1005.25, 3, 5, colors[BLACK]);
	DrawLine(3, 5, 1005, 5, 5, colors[BLACK]);
	DrawLine(177, 338, 177, 360, 8, colors[BROWN]); // first tree
	DrawLine(380, 582, 380, 604, 8, colors[BROWN]); // 2nd tree
	DrawLine(880, 338, 880, 360, 8, colors[BROWN]); //3rd tree


//This will draw passenger 1:
	DrawCircle(135,605,6, colors[BLACK]);
	DrawRoundRect(133,590,4,10,colors[BLACK],0);
	DrawLine(130,582,135,590,2,colors[BLACK]);
	DrawLine(140,582,135,590,2,colors[BLACK]);
//This will draw passenger 2:
	DrawCircle(830,360,6, colors[BLACK]);
	DrawRoundRect(828,345,4,10,colors[BLACK],0);
	DrawLine(825,340,830,345,2,colors[BLACK]);
	DrawLine(835,340,830,345,2,colors[BLACK]);
// This will draw passenger 3:
	DrawCircle(685,603,6, colors[BLACK]);
	DrawRoundRect(683,588,4,10,colors[BLACK],0);
	DrawLine(680,582,685,589,2,colors[BLACK]);
	DrawLine(690,582,685,589,2,colors[BLACK]);
	// DrawCircle(50,670,10,colors[RED]);
	// DrawCircle(70,670,10,colors[RED]);
	// DrawCircle(90,670,10,colors[RED]);
	// DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	// DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);
	// DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	// DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	// DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
			DrawString(500, 800, "time : "+to_string(t), colors[BLACK]);

	//This is pessenger in red dot, my taxi can carry this one pessenger when we spacebar after going under it.
	DrawCircle(pass_x1,pass_y1,6, colors[RED]);

//cout<<"c1"<<c1;
	//Random destination for passenger 
     if(c1==1)
	  {
		 // cout<<loca_x1<<" "<<loca_y1;
         DrawSquare( loca_x1, loca_y1 ,20,colors[GREEN]);
	  }

	if ( Taxi == 1)
		drawTaxi_red();   //random selection of taxi color
	else {
		drawTaxi_yellow();
}
	
	drawCar1();         //This will draw a random moving car
	drawCar2();		   // This will draw a random moving car
	glutSwapBuffers(); // do not modify this line..
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */
//
void NonPrintableKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
	{
		// what to do when left key is pressed...
		if ((xI <= 11) or (((xI >= 127) and (xI <= 308)) and (yI <= 697) and (yI >= 638)) or ((xI >= 481) and (yI <= 699) and (yI >= 637)) or
			((xI >= 835) and (xI <= 907)) and (yI <= 699) and (yI >= 525) or ((xI >= 79) and (xI <= 205) or (xI >= 277) and (xI <= 403) or 
			(xI >= 277) and (xI <= 403) or (xI >= 625) and (xI <= 907)) and (yI <= 581) and (yI >= 527) or ((xI >= 133) and (xI <= 211)) and 
			(yI >= 443) and (yI <= 581) or
			(((xI >= 331) and (xI <= 403)) and (yI >= 443) and (yI <= 581)) or (((xI >= 625) and (xI <= 709)) and (yI >= 443) and (yI <= 581)) 
			or (((xI >= 79) and (xI <= 205)) and (yI <= 335) and (yI >= 197)) or (((xI >= 379) and (xI <= 757)) and (yI <= 311) and (yI >= 251))
			 or (((xI >= 379) and (xI <= 457)) and (yI <= 251) and (yI >= 65)) or (((xI >= 775) and (xI <= 907)) and (yI <= 335) and (yI >= 197))
			  or (((xI>=150) and (xI<=190)) and (yI<=390) and (yI>=338)) or (((xI>=345) and (xI<=380)) and (yI<=630) and (yI>=580)) or (((xI>=840)
			   and (xI<=880)) and (yI<=390) and (yI>=338) ))
		{

		}
		else
		{
			xI -= 6;
			cout << "Left key is pressed" << endl;
			cout << xI << "  " << yI << endl;
		}
	}
	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
	{// This is what to do when right key is pressed
		if ((xI >= 965) or (((xI >= 121) and (xI <= 302)) and (yI <= 697) and (yI >= 638)) or ((xI >= 469) and (yI <= 699) and (yI >= 637)) or
			((xI >= 817) and (xI <= 901)) and (yI <= 699) and (yI >= 525) or ((xI >= 67) and (xI <= 199) or (xI >= 265) and (xI <= 397) or (xI >= 265) and
			 (xI <= 397) or (xI >= 619) and (xI <= 901)) and (yI <= 581) and (yI >= 527) or ((xI >= 121) and (xI <= 205)) and (yI >= 443) and (yI <= 581) or
			(((xI >= 319) and (xI <= 397)) and (yI >= 443) and (yI <= 581)) or (((xI >= 613) and (xI <= 697)) and (yI >= 443) and (yI <= 581)) or (((xI >= 67)
			 and (xI <= 199)) and (yI <= 335) and (yI >= 197)) or (((xI >= 367) and (xI <= 751)) and (yI <= 311) and (yI >= 251)) or (((xI >= 367) and (xI <= 451))
			  and (yI <= 251) and (yI >= 65)) or (((xI >= 763) and (xI <= 901)) and (yI <= 335) and (yI >= 197)) or (((xI>=140) and (xI<=170)) and (yI<=390) and
			   (yI>=338)) or (((xI>=335) and (xI<=370)) and (yI<=630) and (yI>=580)) or (((xI>=830) and (xI<=870)) and (yI<=390) and (yI>=338) ))
		{
		}
		else
		{
			xI += 6;
			cout << "Right key is pressed" << endl;
			cout << xI << "  " << yI << endl;
		}
	}
	else if (key == GLUT_KEY_UP /*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{ //This is what to do when up key is pressed
		if ((yI >= 735) or (((xI >= 127) and (xI <= 302)) and (yI <= 697) and (yI >= 632)) or ((xI >= 475) and (yI <= 699) and (yI >= 631)) or
			((xI >= 823) and (xI <= 901)) and (yI <= 699) and (yI >= 513) or ((xI >= 73) and (xI <= 199) or (xI >= 271) and (xI <= 397) or (xI >= 271) 
			and (xI <= 397) or (xI >= 625) and (xI <= 901)) and (yI <= 581) and (yI >= 521) or ((xI >= 127) and (xI <= 205)) and (yI >= 437) and (yI <= 572) or
			(((xI >= 325) and (xI <= 397)) and (yI >= 437) and (yI <= 581)) or (((xI >= 619) and (xI <= 697)) and (yI >= 437) and (yI <= 581)) or (((xI >= 73) and 
			(xI <= 199)) and (yI <= 335) and (yI >= 191)) or (((xI >= 373) and (xI <= 751)) and (yI <= 311) and (yI >= 245)) or (((xI >= 373) and (xI <= 451)) and 
			(yI <= 251) and (yI >= 59)) or (((xI >= 775) and (xI <= 901)) and (yI <= 335) and (yI >= 191)))
		{
		}
		else
		{
			yI += 6;
			cout << "Up key is pressed" << endl;
			cout << xI << "  " << yI << endl;
		}
	}
	else if (key == GLUT_KEY_DOWN /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{ //this is what to do when down key is pressed
		if ((yI <= 15) or (((xI >= 127) and (xI <= 302)) and (yI <= 703) and (yI >= 638)) or ((xI >= 475) and (yI <= 705) and (yI >= 637)) or
			((xI >= 823) and (xI <= 901)) and (yI <= 705) and (yI >= 519) or ((xI >= 73) and (xI <= 199) or (xI >= 271) and (xI <= 397) or
			 (xI >= 271) and (xI <= 397) or (xI >= 625) and (xI <= 901)) and (yI <= 587) and (yI >= 527) or ((xI >= 127) and (xI <= 205)) and 
			 (yI >= 443) and (yI <= 578) or (((xI >= 325) and (xI <= 397)) and (yI >= 443) and (yI <= 587)) or (((xI >= 619) and (xI <= 697)) 
			 and (yI >= 443) and (yI <= 587)) or (((xI >= 73) and (xI <= 199)) and (yI <= 341) and (yI >= 197)) or (((xI >= 373) and (xI <= 751))
			  and (yI <= 317) and (yI >= 257)) or (((xI >= 373) and (xI <= 451)) and (yI <= 257) and (yI >= 71)) or (((xI >= 775) and (xI <= 901))
			   and (yI <= 341) and (yI >= 197)) or (((xI>=140) and (xI<=170)) and (yI<=400) and (yI>=338)) or (((xI>=335) and (xI<=380)) and 
			   (yI<=640) and (yI>=580)) or (((xI>=830) and (xI<=870)) and (yI<=400) and (yI>=338) ))
			 
		{
		}
		else
		{
			yI -= 6;
			cout << "Down key is pressed" << endl;
			cout << xI << "  " << yI << endl;
		}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */

void PrintableKeys(unsigned char key, int x, int y)
{
	if (key == 27 /* Escape key ASCII*/)
	{
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 32 ) 
	{
		if((pass_x1-xI>=-20 and pass_x1-xI<=-30) or (pass_y1-yI>=-20 and pass_y1-yI<=-30) or (pass_x1-xI>=20 and 
		pass_x1-xI<=30 or (pass_y1-yI>=20 and yI-pass_y1<=30)))
		{
            c1=1;
			
			pass_y1+=10000;
			//cout<<"c1"<<c1;;
		}

		if((loca_x1-xI>=-20 and loca_x1-xI<=-30) or (loca_y1-yI>=-20 and loca_y1-yI<=-30) or (loca_x1-xI>=20 and 
		loca_x1-xI<=30 or (loca_y1-yI>=20 and yI-loca_y1<=30)))
		{

			loca_x1+=10000;
		}
	
	}

	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m)
{

	// implement your functionality here
	moveCar();//
	moveCar2(); //these cars will move with the increase in seconds to produce an aesthetic sence

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y)
{
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y)
{
	cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
bool Mouse_left = true;
void MouseClicked(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		if (Mouse_left)
		{
			if ((x >= 311 and x <= 690) and (y >= 168 and y <= 352))
			{
				glutDisplayFunc(GameDisplay);
				Mouse_left = false;
			}
		}

		cout << GLUT_DOWN << " " << GLUT_UP << endl;
	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{

		cout << "Right Button Pressed" << endl;
	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char *argv[])
{

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
    pas1();
	loc1();
	InitRandomizer();
	Taxi=GetRandInRange(0,1000)%2;							   // seed the random number generator...
	glutInit(&argc, argv);						   // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);  // we will be using color display mode
	glutInitWindowPosition(50, 50);				   // set the initial position of our window
	glutInitWindowSize(width, height);			   // set the size of our window
	glutCreateWindow("Rush Hour by Hamdan Jamal"); // set the title of our game window
	SetCanvasSize(width, height);				   // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	// glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	glutDisplayFunc(Menu);			   // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys);   // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000, Timer, 0);
	glutTimerFunc(1000, TimerEnd, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved);	  // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it seems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
