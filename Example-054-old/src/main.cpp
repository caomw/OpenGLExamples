/*******************************************************************************************************************************************************
 * David Canino (canino.david@gmail.com)
 *
 * Main website (GitHub): http://github.com/davidcanino/OpenGLExamples
 * 
 * Last update: February 2017
 *
 * This program is Free Software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.                                       
 *                                                                         
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License (http://www.gnu.org/licenses/gpl.txt) for more details.
 * 
 * main.cpp - the main function for the 'Example-054 (Old Mode)' example
 *******************************************************************************************************************************************************/

/* First, we must understand which platform we are using. */
#include <cstdlib>
#include <iostream>
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

/// The rendering mode for the scene of interest (filled triangles, if mode=0 | wireframe triangles, if mode=1 | triangles points, if mode=2).
int mode=0;

/// The number of the vertices to be analyzed for drawing the <i>'Square Annulus'</i> shapes of interest.
int num=3;

/// This plain array contains the Euclidean coordinates of the vertices for the <i>'Square Annulus'</i> shapes of interest by using the <i>'vertex array'</i> mechanism.
static GLfloat vertices[] = {
	30,30,0,
	10,10,0,
	70,30,0,
	90,10,0,
	70,70,0,
	90,90,0,
	30,70,0,
	10,90,0
};

/// This plain arrays contains the colors of the vertices for the <i>'Square Annulus'</i> shape of interest by using the <i>'vertex array'</i> mechanism.
static GLfloat colors[] = {
	1,1,1,
	1,0,0,
	0,1,0,
	0,0,1,
	1,1,0,
	1,0,1,
	0,1,1,
	1,0,0
};

/// This plain array indicates the indices for the locations of interest in the <i>'vertex array'</i> mechanism.
static unsigned int inds[10] = { 0,1,2,3,4,5,6,7,0,1 };

/* Prototypes for all functions of interest! */
void initialize();
void resize(int w,int h);
void manageKeys(unsigned char key, int x, int y);
void draw();

/// The main function for the <i>'Example-054 (Old Mode)'</i> example.
int main(int argc,char **argv)
{
	/* We initialize everything, and create a very basic window! */
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("The 'Example-054' Example, based on the (Old Mode) OpenGL");
	glutDisplayFunc(draw);
	glutReshapeFunc(resize);
	glutKeyboardFunc(manageKeys);
	glewExperimental = GL_TRUE;
   	glewInit();
   	initialize(); 
	glutMainLoop();
	return EXIT_SUCCESS;
}

/// This function updates the viewport for the scene when it is resized. */
void resize(int w, int h)
{
	/* We update the projections and the modeling matrices! */
	glViewport(0, 0, w, h);
   	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	glOrtho(0,100,0,100,-1,1);
   	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity();
}

/// This function is the keyboard input processing routine for the OpenGL window of interest.
void manageKeys(unsigned char key, int x, int y)
{
	/* We are interested only in the 'q' - 'Q' - 'Esc' - ' ' - '+' - '-' keys */
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
		
		/* We update the rendering mode. */
		mode=(mode+1)%3;
		glutPostRedisplay();
		break;
		
		case '+':
		
		/* We increase the number of the vertices to be considered. */
		if(num<10) num=num+1;
		else if(num==10) num=3;
		glutPostRedisplay();
		break;
		
		case '-':
		
		/* We decrease the number of the vertices to be considered. */
		if(num>3) num=num-1;
		else cout<<"\tThe minimum number 3 of the vertices is reached"<<endl;
		glutPostRedisplay();
		break;

		default:

    	/* Other keys are not important for us */
    	break;
	}
}

/// This function initializes the OpenGL window of interest.
void initialize() 
{
	/* We initialize the OpenGL window of interest! */
	cout<<endl<<"\tThis is the 'Example-054' Example, based on the (Old Mode) OpenGL"<<endl<<endl;
	cout<<"\tDrawing the 'Square Annulus' shape by using only one triangle strip and the vertex array technique, based on the 'glDrawElements()' statement. It is possible to:"<<endl<<endl;
	cout<<"\t-) change the rendering mode by pressing the ' ' key"<<endl;
	cout<<"\t-) modify the number of the vertices to be considered by pressing the '+' (increase) and the '-' (decrease) keys"<<endl<<endl;
	cout.flush();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	mode=0;
	num=3;
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3,GL_FLOAT,0,vertices);
	glColorPointer(3,GL_FLOAT,0,colors);
}

/// This function draws only one triangle strip, forming the <i>'Square Annulus'</i> shape of interest, in the OpenGL window of interest.
void draw()
{
	/* We draw only one triangle strip, forming the 'Square Annulus' shape of interest. Here, the 'vertex array' technique is exploited. */
	glClear(GL_COLOR_BUFFER_BIT);
	if(mode==0) glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	if(mode==1) glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	if(mode==2) glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
	glPointSize(8);
	glLineWidth(2);
	glDrawElements(GL_TRIANGLE_STRIP,num,GL_UNSIGNED_INT,inds);
	glFlush();
	cout<<"\tDrawn the 'Square Annulus' of interest by using "<<num<<" vertices"<<endl;
	cout.flush();
}
