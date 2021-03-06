/*******************************************************************************************************************************************************
 * David Canino (canino.david@gmail.com)
 *
 * Main website (GitHub): http://github.com/davidcanino/OpenGLExamples
 * 
 * Last update: April 2017
 *
 * This program is Free Software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.                                       
 *                                                                         
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License (http://www.gnu.org/licenses/gpl.txt) for more details.
 * 
 * main.cpp - the main function for the 'Example-010 (Old Mode)' example.
 *******************************************************************************************************************************************************/

/* First, we must understand which platform we are using. */
#include <cstdlib>
#include <iostream>
using namespace std;
#ifdef __APPLE__

	/* We are using a MacOSX platform (Macintosh). */
	#include "GL/glew.h"
	#include "GLUT/glut.h"
	#include "OpenGL/gl.h"

#else

	/* We are not using a MacOSX platform. Thus, we have a generic Unix-like platform, like the GNU/Linux, or a Microsoft Windows platform. */
	#include "GL/glew.h"
	#include "GL/glut.h"
	#include "GL/gl.h"

#endif

/// This flag identifies what graphic primitive must be exploited for rendering the cloud of several 3D points in the scene.
/**
 * It may be one of the following values:
 *
 * -) the 'GL_POINTS' value, used for rendering several independent 3D points;
 * -) the 'GL_LINES' value, used for rendering several independent lines;
 * -) the 'GL_LINE_STRIP' value, used for rendering an open line strip;
 * -) the 'GL_LINE_LOOP' value, used for rendering a closed line strip;
 * -) the 'GL_TRIANGLES' value, used for rendering several triangles;
 * -) the 'GL_POLYGON' value, used for rendering a unique polygon.
 */
int rendering;

/// This boolean flag is used for completing the textual interface.
bool eol=false;

/* Prototypes for all functions of interest! */
void draw();
void initialize();
void resize(int w,int h);
void manageKeys(unsigned char key, int x, int y);

/// The main function for the <i>'Example-010 (Old Mode)'</i> example.
int main(int argc,char **argv)
{
	/* We initialize everything, and create a very basic window! */
	cout<<endl<<"\tThis is the 'Example-010' Example, based on the (Old Mode) OpenGL."<<endl;
	cout<<"\tIt draws several graphic primitives, starting from a cloud of several 3D points."<<endl;
	cout<<"\tThe user can choose what graphic primitive must be exploited, as follows:"<<endl<<endl;
	cout << "\t-) the 'GL_POINTS' primitive is chosen by pressing the '0' key for drawing several independent 3D points;" << endl;
	cout << "\t-) the 'GL_LINES' primitive is chosen by pressing the '1' key for drawing several independent lines;" << endl;
	cout << "\t-) the 'GL_LINE_STRIP' primitive is chosen by pressing the '2' key for drawing an open line strip;" << endl;
	cout << "\t-) the 'GL_LINE_LOOP' primitive is chosen by pressing the '3' key for drawing a closed line loop;" << endl;
	cout << "\t-) the 'GL_TRIANGLES' primitive is chosen by pressing the '4' key for drawing several independent triangles;" << endl;
	cout << "\t-) the 'GL_POLYGON' primitive is chosen by pressing the '5' key for drawing only one polygon."<<endl<<endl;
	cout<<"\tIt is possible to end this program by pressing one among the 'Q' - 'q' - 'Esc' keys."<<endl<<endl;
	cout.flush();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(480,480);
	glutCreateWindow("The 'Example-010' Example, based on the (Old Mode) OpenGL");
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
	/* We update the projection and the modeling matrices! */
	glViewport(0, 0, w, h);
   	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	glOrtho(0,130,0,120,-1,1);
   	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity();
}

/// This function draws the cloud of several 3D points in the OpenGL window of interest by using the graphic primitive, chosen by the user.
void draw()
{
	/* We draw the cloud of several 3D points in the OpenGL window of interest by using the graphic primitive, chosen by the user. */
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0);
	glLineWidth(2.0);
	glColor3f(1,0,0);
	glBegin(rendering);
	glVertex3f(20,80,0);
	glVertex3f(20,50,0);
	glVertex3f(50,20,0);
	glVertex3f(80,20,0);
	glVertex3f(110,50,0);
	glVertex3f(110,80,0);
	glVertex3f(80,100,0);
	glVertex3f(50,100,0);
	glEnd();
	glFlush();
}

/// This function initializes the OpenGL window of interest.
void initialize() 
{
	/* We initialize the OpenGL window of interest! */
	glClearColor(1.0, 1.0, 1.0, 0.0); 
	rendering=GL_POINTS;
	eol=false;
	cout<<"\tThe 'GL_POINTS' primitive is initially used for drawing several independents 3D points in the current scene."<<endl<<endl;
	cout.flush();
}

/// This function is the keyboard input processing routine for the OpenGL window of interest.
void manageKeys(unsigned char key, int x, int y)
{
	/* We are interested only in the 'q' - 'Q' - 'Esc' - '0' - '1' - '2' - '3' - '4' - '5' keys. */
	switch (key)
	{
		case 'q':
	
		/* The key is 'q', thus we can exit from this program. */
		if(eol) cout<<endl;
		cout.flush();
		exit(EXIT_SUCCESS);
		break;
		
		case 'Q':
	
		/* The key is 'Q', thus we can exit from this program. */
		if(eol) cout<<endl;
		cout.flush();
		exit(EXIT_SUCCESS);
		break;
		
		case 27:
	
		/* The key is 'Esc', thus we can exit from this program. */
		if(eol) cout<<endl;
		cout.flush();
		exit(EXIT_SUCCESS);
		break;
		
		case '0':
		
		/* The key is '0', thus the 'GL_POINTS' primitive is used for drawing several independent 3D points in the current scene. */
		rendering=GL_POINTS;
		cout<<"\tThe 'GL_POINTS' primitive is used for drawing several independents 3D points in the current scene."<<endl;
		cout.flush();
		eol=true;
		glutPostRedisplay();
		break;
		
		case '1':
		
		/* The key is '1', thus the 'GL_LINES' primitive is used for drawing several independent lines in the current scene. */
		rendering=GL_LINES;
		cout<<"\tThe 'GL_LINES' primitive is used for drawing several independent lines in the current scene."<<endl;
		cout.flush();
		eol=true;
		glutPostRedisplay();
		break;
		
		case '2':
		
		/* The key is '2', thus the 'GL_LINE_STRIP' primitive is used for drawing an open line strip in the current scene. */
		rendering=GL_LINE_STRIP;
		cout<<"\tThe 'GL_LINE_STRIP' primitive is used for drawing an open line strip in the current scene."<<endl;
		cout.flush();
		eol=true;
		glutPostRedisplay();
		break;
		
		case '3':
		
		/* The key is '3', thus the 'GL_LINE_LOOP' primitive is used for drawing a closed line loop in the current scene. */
		rendering=GL_LINE_LOOP;
		cout<<"\tThe 'GL_LINE_LOOP' primitive is used for drawing a closed line loop in the current scene."<<endl;
		cout.flush();
		eol=true;
		glutPostRedisplay();
		break;
		
		case '4':
		
		/* The key is '4', thus the 'GL_TRIANGLES' primitive is used for drawing several triangles in the current scene. */
		rendering=GL_TRIANGLES;
		cout<<"\tThe 'GL_TRIANGLES' primitive is used for drawing several independent triangles in the current scene."<<endl;
		cout.flush();
		eol=true;
		glutPostRedisplay();
		break;

		case '5':
		
		/* The key is '5', thus the 'GL_POLYGON' primitive is used for drawing only one polygon in the current scene. */
		rendering=GL_POLYGON;
		cout<<"\tThe 'GL_POLYGON' primitive is used for drawing only one polygon in the current scene."<<endl;
		cout.flush();
		eol=true;
		glutPostRedisplay();
		break;
		
		default:

    	/* Other keys are not important for us! */
    	break;
	}
}
