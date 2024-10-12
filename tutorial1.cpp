#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
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
#include<cmath>  
using namespace std;

void display ();

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(1000, 700);
    
    glutCreateWindow ("Trial");
    
    glutDisplayFunc(display);
    
    glutMainLoop();
}
#endif

void display()
{

}


