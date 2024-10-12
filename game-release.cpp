// Name        : Javeria Rahman
// Student ID  : 23i-0137
// Department  : Artificial Intelligence
// Section     : A
// Copyright   : (c) Reserved


#ifndef TETRIS_CPP_
#define TETRIS_CPP_
#include "util.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sstream> 
   
using namespace std;

void SetCanvasSize(int width, int height) 
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1); 
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
}


//Main Canvas drawing function
double startx=400,starty=400;
int counter = 0, counter3 = 0, counter4 = 0;

int foodx[5];
int foody[5];

int counter6 = 1;
int counter5 = 0;
int score = 0;
int length = 3;
int powerFoodx;
int powerFoody;
int hurdlex1;
int hurdlex2;
int hurdlex3;
int hurdley1;
int hurdley2;
int i, j;

char directionprev;
char direction;

long bodyx[10000000];
long bodyy[10000000];



int highscore;
int frame;

bool flag = true;
bool easy = false;
bool hard = false;
bool hsc = false;
bool power = false;
bool top = true;
bool bottom = true;
bool hurdle = false;
bool food = false;
bool hurdle1 = true;
bool hurdle2 = true;
bool hurdle3 = true;
bool menu = false;
bool displayHighscore = false;
bool levels = false;


void Display()
{
    glClearColor(0.1, 0.7, 0.2, 0);
    glClear(GL_COLOR_BUFFER_BIT); 
    
    int counter2;
    int printx;
    int printy;
    
    if (menu)
    {
        string continueGame = "Continue Game", restart = "Restart Game", highsc = "Highscore", level = "Change Level", exit = "Exit";
        if (counter5 == 0)
        {
            DrawString( 410, 450, ">", colors[BLACK]);
        }
        else if (counter5 == 1)
        {
            DrawString( 410, 400, ">", colors[BLACK]);
        }
        else if (counter5 == 2)
        {
            DrawString( 410, 350, ">", colors[BLACK]);
        }
        else if (counter5 == 3)
        {
            DrawString( 410, 300, ">", colors[BLACK]);
        }
        else if (counter5 == 4)
        {
            DrawString( 410, 250, ">", colors[BLACK]);
        }
        DrawString( 430, 450, continueGame, colors[BLACK]); 
        DrawString( 430, 400, restart, colors[BLACK]); 
        DrawString( 430, 350, level, colors[BLACK]); 
        DrawString( 430, 300, highsc, colors[BLACK]); 
        DrawString( 430, 250, exit, colors[BLACK]); 
    }
    else if (displayHighscore)
    {
        string max = to_string(highscore);
        DrawString(500, 380, max, colors[BLACK]);
    }
    else if (levels)
    {
        string easy = "Easy", medium = "Medium", hard = "Hard";
        if (counter6 == 0)
        {
            DrawString( 410, 450, ">", colors[BLACK]);
        }
        else if (counter6 == 1)
        {
            DrawString( 410, 400, ">", colors[BLACK]);
        }
        else if (counter6 == 2)
        {
            DrawString( 410, 350, ">", colors[BLACK]);
        }
        DrawString( 430, 450, easy, colors[BLACK]); 
        DrawString( 430, 400, medium, colors[BLACK]); 
        DrawString( 430, 350, hard, colors[BLACK]);        
    }
    else if ((flag) || (easy) || (hard))
    {
    
        int x = 400;
        int y = 400;

        // Snake's movement
        if (direction == 'r')
        {   
            startx = startx+7;
            if (startx+7 > 1010)
            {
                startx = 0;
            }
        
            for (counter2 = length-1; counter2 > 0; counter2--)
            {
                bodyx[counter2] = bodyx[counter2-1];
                bodyy[counter2] = bodyy[counter2-1];
            }  
            bodyx[0] = startx;
            bodyy[0] = starty;  
            for (counter2 = 0; counter2 < length; counter2++)
            {
                printx = bodyx[counter2];
                printy = bodyy[counter2];
                DrawCircle(printx, printy, 7, colors[29]);
            }       
        }
        else if (direction == 'l')
        {
            startx = startx-7;
            if (startx-7 < 0)
            {
                startx = 1010;
            }
        
            for (counter2 = length-1; counter2 > 0; counter2--)
            {
                bodyx[counter2] = bodyx[counter2-1];
                bodyy[counter2] = bodyy[counter2-1];
            } 
            bodyx[0] = startx;
            bodyy[0] = starty;  
            for (counter2 = 0; counter2 < length; counter2++)
            {
                printx = bodyx[counter2];
                printy = bodyy[counter2];
                DrawCircle(printx, printy, 7, colors[29]);
            }  
        }
        else if (direction == 'u')
        {
            starty = starty+7;
            if (starty >= 700)
            {
                starty = 0;
            }
        
            for (counter2 = length-1; counter2 > 0; counter2--)
            {
                bodyx[counter2] = bodyx[counter2-1];
                bodyy[counter2] = bodyy[counter2-1];
            } 
            bodyx[0] = startx;
            bodyy[0] = starty;  
            for (counter2 = 0; counter2 < length; counter2++)
            {
                printx = bodyx[counter2];
                printy = bodyy[counter2];
                DrawCircle(printx, printy, 7, colors[29]);
            }      
        }
        else if (direction == 'd')
        { 
            starty = starty-7;
            if (starty <= 0)
            {
                starty = 700;
            }
        
            for (counter2 = length-1; counter2 > 0; counter2--)
            {
                bodyx[counter2] = bodyx[counter2-1];
                bodyy[counter2] = bodyy[counter2-1];
            }   
            bodyx[0] = startx;
            bodyy[0] = starty;  
            for (counter2 = 0; counter2 < length; counter2++)
            {
                printx = bodyx[counter2];
                printy = bodyy[counter2];
                DrawCircle(printx, printy, 7, colors[29]);
            }         
        }
        else
        {
            for (counter2 = 0; counter2 < length; counter2++)
            {
                DrawCircle(x, y, 7, colors[29]);
                bodyx[counter2] = x;
                bodyy[counter2] = y;
                x = x - 7;
            } 
            direction = 'r';
        }
    
        // Allocating food position
        if ((counter == 600) || (counter == 0))
        {
            for (int i = 0; i < 5; i++)
            {
                foodx[i] = rand()%1000;
                while (foodx[i] == foodx[i-1])
                {
                    foodx[i] = rand()%1000;
                    while (!food)
                    {
                        food = true;
                        for (counter2 = 0; counter2 < length; counter2++)
                        {
                            if (((bodyx[counter2]+7 >= foodx[i]-4) && (bodyx[counter2]-7 <=  foodx[i]+4) && (bodyy[counter2]+7 >= foody[i]-4) && (bodyy[counter2]+7 <= foody[i]+4)) || ((bodyx[counter2]+7 >= foodx[i]+4) && (bodyx[counter2]-7 <= foodx[i]+4) && (bodyy[counter2]+7 >= foody[i]-4) && (bodyy[counter2]+7 <= foody[i]+4)))
                            {
                                food = false;
                            }
                        }
                        for (counter2 = 0; counter2 < length; counter2++)
                        {
                            while (!food)
                            {
                                foodx[i] = rand()%1000;
                            }
                        }
                    }
                }
                foody[i] = (rand()%600)+18;
                while (foody[i] == foody[i-1])
                {
                    foody[i] = rand()%600;
                    while (!food)
                    {
                        food = true;
                        for (counter2 = 0; counter2 < length; counter2++)
                        {
                            if (((bodyx[counter2]+7 >= foodx[i]-4) && (bodyx[counter2]-7 <=  foodx[i]+4) && (bodyy[counter2]+7 >= foody[i]-4) && (bodyy[counter2]+7 <= foody[i]+4)) || ((bodyx[counter2]+7 >= foodx[i]+4) && (bodyx[counter2]-7 <= foodx[i]+4) && (bodyy[counter2]+7 >= foody[i]-4) && (bodyy[counter2]+7 <= foody[i]+4)))
                            {
                                food = false;
                            }
                        }
                        for (counter2 = 0; counter2 < length; counter2++)
                        {
                            while (!food)
                            {
                                foodx[i] = rand()%1000;
                            }
                        }
                    }
                }
            }
            counter = 0;
        }
        
        // Power food
        if (counter3 == 2000) 
        {
            for (int i = 0; i < 5; i++)
            {
                powerFoodx = rand()%1000;
                for (counter2 = 0; counter2 < length; counter2++)
                {
                    while ((powerFoodx == bodyx[counter2]) && (powerFoody == bodyy[counter2]))
                    {
                        powerFoodx = rand()%1000;
                    }
                }
                powerFoody = rand()%600;
                for (counter2 = 0; counter2 < length; counter2++)
                {
                    while ((powerFoodx == bodyx[counter2]) && (powerFoody == bodyy[counter2]))
                    {
                        powerFoody = rand()%600;
                    }
                }
            }
            power = true;
        }
        if (counter3 >= 2000)
        {
            DrawCircle(powerFoodx , powerFoody, 9, colors[1]);
            if (counter3 >= 2500)
            {
                counter3 = 0;
                power = false;
            }
        }
        
        // Drawing Food
        for (int i = 0; i < 5; i++)
        {
            DrawSquare(foodx[i] , foody[i], 8, colors[65]);  
        }
        
        // Eating food
        for (int i=0; i<5; i++)
        {
            if (((startx+8 >= foodx[i]+4) && (startx-8 <= foodx[i]+4) && (starty+8 >= foody[i]+4) && (starty-8 <= foody[i]+4)) || ((startx+8 >= foodx[i]-4) && (startx-8 <= foodx[i]-4) && (starty+8 >= foody[i]-4) && (starty-8 <= foody[i]-4)))
            {
                score = score + 5;
                length++;
                foodx[i]=rand()%1000;
                foody[i] = rand()%600;
                while ((foodx[i] == foodx[i-1]) || (foodx[i] == foodx[i-2]))
                {
                    foodx[i] = rand()%1000;
                    for (counter2 = 0; counter2 < length; counter2++)
                    {
                        while ((foodx[i] == bodyx[counter2]) && (foody[i] == bodyy[counter2]))
                        {
                            foodx[i] = rand()%1000;
                        }
                    }
                }
                while ((foody[i] == foody[i-1]) || (foody[i] == foody[i-2]))
                {
                    foody[i] = rand()%600;
                    for (counter2 = 0; counter2 < length; counter2++)
                    {
                        while ((foodx[i] == bodyx[counter2]) && (foody[i] == bodyy[counter2]))
                        {
                            foody[i] = rand()%600;
                        }
                    }
                }
            }
        }
        
        if (power)
        {
            if (((startx+8 >= powerFoodx-10) && (startx-8 <= powerFoodx+10) && (starty+8 >= powerFoody-10) && (starty-8 <= powerFoody+10)) || ((startx+8 >= powerFoodx+10) && (startx-8 <= powerFoodx-10) && (starty+8 >= powerFoody-10) && (starty-8 <= powerFoody+10)))
            {
                score = score + 20;
                length++;
                counter3 = 0;
            }
        }
        
    
        // Hurdles
        if (counter4 == 1050)
        {
            hurdlex1 = rand()%1000;
            if (!easy)
            {
                hurdlex2 = rand()%1000;
                while (hurdlex1 == hurdlex2)
                {
                    hurdlex2 = rand()%1000;
                }
            }
            hurdley1 = rand()%400; 
            hurdley2 = hurdley1 + 200; 
            while ((!hurdle1) || (!hurdle2))
            {
                hurdle1 = true;
                hurdle2 = true;
                for (counter2 = 0; counter2 < length; counter2++)
                {
                    if (!hurdle1)
                    {
                        hurdlex1 = rand()%1000;
                    }
                    if (!hurdle2)
                    {
                        hurdlex2 = rand()%1000;
                    }
                }
                for (counter2 = 0; counter2 < length; counter2++)
                {
                    while (hurdlex1 == bodyx[counter2])
                    {
                        hurdle1 = false;
                    }
                    if (!easy)
                    {
                        while (hurdlex2 == bodyx[counter2])
                        {
                            hurdle2 = false;
                        }
                    }
                }
            }
            
            hurdle = true;
        }
    
        // Drawing hurdle
        if (counter4 >= 1050)
        {
            DrawLine(hurdlex1 , hurdley1,  hurdlex1, hurdley2, 20, colors[0] );
            if (!easy)
            {
               DrawLine(hurdlex2 , hurdley1,  hurdlex2, hurdley2, 20, colors[0] );
            }
            if (bottom)
            {
                hurdley1 = hurdley1 + 5;
                hurdley2 = hurdley2 + 5;
                if (hurdley2 >= 650)
                {
                    top = true;
                    bottom = false;
                }
            }
            else if (top)
            {
                hurdley1 = hurdley1 - 5;
                hurdley2 = hurdley2 - 5;
                if (hurdley1 <= 0)
                {
                    top = false;
                    bottom = true;
                }
            }
            if (counter4 >= 2100)
            {
                counter4 = 0;
                hurdle = false;
            }
        }
        
        
        // For hard only
        if (hard)
        {
            DrawLine(0 , 696,  1010, 696, 100, colors[0] );
            DrawLine(0 , 4,  1010, 4, 100, colors[0] );
        }
        
        counter++;
        counter3++;
        counter4++;
    } 
    
    
    // Game Over
    if ((!menu) && (!levels) && (!displayHighscore))
    {
        for (counter2 = 0; counter2 < length; counter2++)
        {
            if (((bodyx[0] == bodyx[counter2]) && (bodyy[0] == bodyy[counter2]) && (counter2 != 0)) || ((hurdle) && (((bodyx[counter2] + 7 >= hurdlex1-5) && (bodyx[counter2] + 7 <= hurdlex1 + 5) && (bodyy[counter2] + 7 <= hurdley2) && (bodyy[counter2]+7 >= hurdley1)) || ((bodyx[counter2] - 7 >= hurdlex1-5) && (bodyx[counter2] - 7 <= hurdlex1 + 5) && (bodyy[counter2] + 7 <= hurdley2) && (bodyy[counter2]+7 >= hurdley1)) || ((bodyx[counter2] + 7 >= hurdlex1-5) && (bodyx[counter2] + 7 <= hurdlex1 + 5) && (bodyy[counter2] - 7 <= hurdley2) && (bodyy[counter2]-7 >= hurdley1)) || ((bodyx[counter2] - 7 >= hurdlex1-5) && (bodyx[counter2] - 7 <= hurdlex1 + 5) && (bodyy[counter2] - 7 <= hurdley2) && (bodyy[counter2]-7 >= hurdley1)))) || ((hurdle) && (!easy) && (((bodyx[counter2] + 7 >= hurdlex2-5) && (bodyx[counter2] + 7 <= hurdlex2 + 5) && (bodyy[counter2] + 7 <= hurdley2) && (bodyy[counter2]+7 >= hurdley1)) || ((bodyx[counter2] - 7 >= hurdlex2-5) && (bodyx[counter2] - 7 <= hurdlex2 + 5) && (bodyy[counter2] + 7 <= hurdley2) && (bodyy[counter2]+7 >= hurdley1)) || ((bodyx[counter2] + 7 >= hurdlex2-5) && (bodyx[counter2] + 7 <= hurdlex2 + 5) && (bodyy[counter2] - 7 <= hurdley2) && (bodyy[counter2]-7 >= hurdley1)) || ((bodyx[counter2] - 7 >= hurdlex2-5) && (bodyx[counter2] - 7 <= hurdlex2 + 5) && (bodyy[counter2] - 7 <= hurdley2) && (bodyy[counter2]-7 >= hurdley1)))) || (((!easy) && (!flag)) && ((bodyy[0] + 7 >= 688) || (bodyy[0] - 7 <= 12))))
            {
                if (score>highscore)
                {
                    highscore = score;
                    hsc = true;
                }
                if (hsc)
                {
                    DrawString( 350, 420, "You Made A New High Score!", colors[BLACK]); 
                    DrawString( 440, 350, "Game Over!", colors[BLACK]);
                    DrawString( 361, 100, "Press Spacebar to continue", colors[BLACK]);
                    DrawString( 340, 50, "Press Backspace to go to menu", colors[BLACK]);
                    flag = false;
                    easy = false;
                    hard = false;
                }
                else
                {
                    DrawString( 440, 350, "Game Over!", colors[BLACK]); 
                    DrawString( 361, 100, "Press Spacebar to continue", colors[BLACK]);
                    DrawString( 340, 50, "Press Backspace to go to menu", colors[BLACK]);
                    flag = false;
                    easy = false;
                    hard = false;
                }
            }
        } 
    }
    
    // Score display
    string sc = to_string(score);
    DrawString( 447, 650, "Score :    ", colors[BLACK]); 
    DrawString( 532, 650, sc, colors[BLACK]); 
     
    glutSwapBuffers(); 
}

void NonPrintableKeys(int key, int x, int y) 
{
    if ((flag) || (easy) || (hard))
    {
        if (key == GLUT_KEY_LEFT) 
        {
            if (direction != 'r') 
            {
                directionprev = direction;
                direction = 'l';
            }
        }   
        else if (key == GLUT_KEY_RIGHT) 
        {
            if (direction != 'l') 
            {
                directionprev = direction;
                direction = 'r';
            }
        }   
        else if (key == GLUT_KEY_UP)
        {
            if (direction != 'd') 
            {
                directionprev = direction;
                direction = 'u';
            }
        }
        else if (key == GLUT_KEY_DOWN)   
        {
            if (direction != 'u') 
            {
                directionprev = direction;
                direction = 'd';
            }
        }
    }
    
    if (menu)
    {
        if (key == GLUT_KEY_UP)
        {
            counter5--;
            if (counter5 == -1)
            {
                counter5 = 4;
            }
        }
        else if (key == GLUT_KEY_DOWN)   
        {
            counter5++;
            if (counter5 == 5)
            {
                counter5 = 0;
            }
        }
    }
    
    if (levels)
    {
        if (key == GLUT_KEY_UP)
        {
            counter6--;
            if (counter6 == -1)
            {
                counter6 = 2;
            }
        }
        else if (key == GLUT_KEY_DOWN)   
        {
            counter6++;
            if (counter6 == 3)
            {
                counter6 = 0;
            }
        }
    }
    
    glutPostRedisplay();
}

void PrintableKeys(unsigned char key, int x, int y) {
    if (key == KEY_ESC) 
    {
        exit(1);
    }
    else if (int(key) == 32)
    {  
        if ((!flag) && (!easy) && (!hard))
        {
            if (counter6 == 0)
            {
                easy = true;
            }
            else if (counter6 == 1)
            {
                flag = true;
            }
            else if (counter6 == 2)
            {
                hard = true;
            }
            length = 3;
            score = 0;
            startx=400,starty=400;
            direction = ' ';
            hsc = false;
            power = false;
            top = true;
            bottom = true;
            hurdle = false;
            food = false;
            hurdle1 = true;
            hurdle2 = true;
            hurdle3 = true;
            counter = 0;
            counter3 = 0;
            counter4 = 0;
            levels = false;
            displayHighscore = false;
            menu = false;
        }
    }
    else if (int(key) == 8)
    {
        flag = false;
        easy = false;
        hard = false;
        menu = true;
        counter5 = 0;
    }
    else if (int(key) == 13)
    {
        if (menu)
        {
            if (counter5 == 0)
            {
                if (counter6 == 0)
                {
                    easy = true;
                }
                else if (counter6 == 1)
                {
                    flag = true;
                }
                else if (counter6 == 2)
                {
                    hard = true;
                }
                levels = false;
                displayHighscore = false;
                menu = false;
            }
            else if (counter5 == 1)
            {
                if (counter6 == 0)
                {
                    easy = true;
                }
                else if (counter6 == 1)
                {
                    flag = true;
                }
                else if (counter6 == 2)
                {
                    hard = true;
                }
                startx=400,starty=400;
                direction = ' ';
                length = 3;
                score = 0;
                hsc = false;
                power = false;
                top = true;
                bottom = true;
                hurdle = false;
                food = false;
                hurdle1 = true;
                hurdle2 = true;
                hurdle3 = true;
                counter = 0;
                counter3 = 0;
                counter4 = 0;
                levels = false;
                displayHighscore = false;
                menu = false;
            }
            else if (counter5 == 2)
            {
                levels = true;
                displayHighscore = false;
                menu = false;
            }
            else if (counter5 == 3)
            {
                displayHighscore = true;
                menu = false;
                levels = false;
            }
            else
            {
                exit(1);
            }
        }
        
        else if (levels)
        {
            if (counter6 == 0)
            {
                easy = true;
                flag = false;
                hard = false;
                counter5 = 0;
            }
            else if (counter6 == 1)
            {
                easy = false;
                flag = true;
                hard = false;
                counter5 = 0;
            }
            else if (counter6 == 2)
            {
                easy = false;
                flag = false;
                hard = true;
                counter5 = 0;
            }
            levels = false;
            menu = true;
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

void Timer(int frame) 
{

// implement your functionality here
	glutPostRedisplay();
        if (hard)
        {
            frame = 110;
        }
        else if (flag)
        {
            frame = 260;
        }
        else if (easy)
        {
            frame = 250;
        }
        glutTimerFunc(frame / FPS, Timer, 0);
}


int main(int argc, char*argv[]) 
{
    int width = 1010, height = 700; 
    InitRandomizer(); // seed the random number generator...
    glutInit(&argc, argv); 

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
    glutInitWindowPosition(50, 50); 
    glutInitWindowSize(width, height); 
    glutCreateWindow("PF's Snake Game"); 
    SetCanvasSize(width, height); 

    srand(time(0));
    glutDisplayFunc(Display); 
    glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
    glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
    
    
        if (hard)
        {
            frame = 110;
        }
        else if (flag)
        {
            frame = 180;
        }
        else if (easy)
        {
            frame = 250;
        }
    glutTimerFunc(frame, Timer, 0);
    glutPostRedisplay();

    glutMainLoop();
    return 1;
}
#endif 

