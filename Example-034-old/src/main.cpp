/*******************************************************************************************************************************************************
 * David Canino (canino.david@gmail.com)
 *
 * Main website (GitHub): http://github.com/davidcanino/OpenGLExamples
 * 
 * Last update: January 2017
 *
 * This program is Free Software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.                                       
 *                                                                         
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License (http://www.gnu.org/licenses/gpl.txt) for more details.
 * 
 * main.cpp - the main function for the 'Example-034 (Old Mode)' example
 *******************************************************************************************************************************************************/
 
/* First, we must understand which platform we are using. */
#include <cstdlib>
#include <iostream>
#include <cmath>
#define PI 3.14159265358979324
using namespace std;
#ifdef __APPLE__

	/* We are using a MacOSX platform (Macintosh) */
	#include "GL/glew.h"
	#include "GLUT/glut.h"
	#include "OpenGL/gl.h"

#else

	/* We are not using a MacOSX platform. Thus, we have a generic Unix-like platform, like the GNU Linux, or a Microsoft Windows platform. */
	#include "GL/glew.h"
	#include "GL/glut.h"
	#include "GL/gl.h"

#endif

/// This flag indicates what projection we must exploit.
int projection=0;

/* Prototypes for all functions of interest! */
void initialize();
void resize(int w,int h);
void manageKeys(unsigned char key, int x, int y);
void draw();

/// The main function for the <i>'Example-034 (Old Mode)'</i> example.
int main(int argc,char **argv)
{
	/* We initialize everything, and create a new window! */
	cout<<endl<<"\tThis is the 'Example-034' Example, based on the (Old Mode) OpenGL"<<endl<<endl;
	cout.flush();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("The 'Example-034' Example, based on the (Old Mode) OpenGL");
	glutReshapeFunc(resize);
	glutKeyboardFunc(manageKeys);
	glutDisplayFunc(draw);
	glewExperimental = GL_TRUE;
   	glewInit();
   	initialize(); 
	glutMainLoop();
	return EXIT_SUCCESS;
}

/// This function initializes the OpenGL window of interest.
void initialize() 
{
	/* We initialize the OpenGL window of interest! */
	cout<<"\tWe draw a helix and choose what is the projection to be used (orthographic or prospective) by pressing the ' ' key."<<endl<<endl;
	cout.flush();
	glClearColor(1.0, 1.0, 1.0, 0.0);
	projection=0;
}

// This function is the keyboard input processing routine for the OpenGL window of interest.
void manageKeys(unsigned char key, int x, int y)
{
	/* We are interested only in the 'q' - 'Q' - 'Esc' - '<space bar>' keys */
	switch (key)
	{
		case 'q':
	
		/* The key is 'q' */
		cout<<endl;
		cout.flush();
		exit(EXIT_SUCCESS);
		break;
		
		case 'Q':
	
		/* The key is 'Q' */
		cout<<endl;
		cout.flush();
		exit(EXIT_SUCCESS);
		break;
		
		case 27:
	
		/* The key is 'Esc' */
		cout<<endl;
		cout.flush();
		exit(EXIT_SUCCESS);
		break;
		
		case ' ':
		
		/* The key is ' ', thus we change the projection of interest! */
		projection=(projection+1)%2;
		resize(500,500);
		glutInitWindowSize(500,500);
		glutPostRedisplay();
		break;

		default:

    	/* Other keys are not important for us */
    	break;
	}
}

/// This function updates the viewport for the scene when it is resized. */
void resize(int w, int h)
{
   /* We update the projections and the modeling matrices! */
	glViewport(0, 0, w, h);
   	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	if(projection==0) glOrtho(-50.0, 50.0, -50.0, 50.0, 0.0, 100.0);
   	else glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
   	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity();
}

/// This function draws the 3D helix by using the projection (requested by the user) in the OpenGL scene of interest.
void draw()
{
	/* First, we clear everything. Then, we draw the 3D helix of interest. */
	glClear(GL_COLOR_BUFFER_BIT);
   	glColor3f(1.0, 0.0, 0.0);
   	glLineWidth(2);
   	glBegin(GL_LINE_STRIP);
   	for(double t = -10 * PI; t <= 10 * PI; t += PI/20.0) { glVertex3f(20.0 * cos(t), 20.0 * sin(t), t - 60.0); }
   	glEnd();
   	glFlush();
   	cout<<"\tDrawn the 3D helix of interest by using the ";
   	if(projection==0) cout<<"orthogonal projection [-50,50] x [-50,50] x [0,100] (see the 'glOrtho()' function)"<<endl;
   	else cout<<"perspective projection [-5,5,-5,5,5,100] (see the 'glFrustum()' function)"<<endl;
   	cout.flush();
}
