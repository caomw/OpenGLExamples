/*******************************************************************************************************************************************************
 * David Canino (canino.david@gmail.com)
 *
 * Main website (GitHub): http://github.com/davidcanino/OpenGLExamples
 * 
 * Last update: March 2017
 *
 * This program is Free Software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.                                       
 *                                                                         
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License (http://www.gnu.org/licenses/gpl.txt) for more details.
 * 
 * main.cpp - the main function for the 'Example-025 (Old Mode)' example
 *******************************************************************************************************************************************************/

/* First, we must understand which platform we are using. */
#if defined(_MSC_VER)

	/* We are using the Microsoft Visual Studio, thus we must fix the bug, regarding the 'min()' and the 'max()' template functions. */
	#define NOMINMAX
	#include <algorithm>
	using namespace std;

#endif
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
#ifdef __APPLE__

	/* We are using a MacOSX platform (Macintosh). */
	#include "GL/glew.h"
	#include "GLUT/glut.h"
	#include "OpenGL/gl.h"

#else

	/* We are not using a MacOSX platform. Thus, we have a generic Unix-like platform, like the GNU Linux, or a Microsoft Windows platform. */
	#include "GL/glew.h"
	#include "GL/glut.h"
	#include "GL/gl.h"

#endif

/// The coefficients of the equation, describing the custom <i>'Parabola'</i> curve of interest.
/**
 * The custom 'Parabola' curve of interest is described by the equation 'a x^2 + b x +c =0 ', where 'a' is not null (clearly).
 */
float a,b,c;

/// The number of the samples, used for approximating the custom <i>'Parabola'</i> curve of interest.
unsigned int num_samples;

/// The x- and the y-ranges for the scene of interest.
float xmin,xmax,ymin,ymax;

/// The vertex coordinates <i>'(xv,yv)'</i> for the custom <i>'Parabola'</i> curve of interest.
float xv,yv;

/// The radius <i>'R'</i> for the interval <i>['xv-R,xv+R']</i> , where the custom <i>'Parabola'</i> curve of interest must be drawn.
/**
 * In this case, the 'Parabola' curve of interest is centered with respect to its vertex '(xv,yv)'.
 */
float radius;

/* Prototypes for all functions of interest! */
void draw();
void initialize();
void resize(int w,int h);
void manageKeys(unsigned char key, int x, int y);
float evaluateParabola(float x);
void exportEquation();

/// The main function for the <i>'Example-025 (Old Mode)'</i> example.
int main(int argc,char **argv)
{
	float vmin,vmax,h;

	/* We initialize everything, and create a very basic window! */
	cout<<endl<<"\tThis is the 'Example-025' Example, based on the (Old Mode) OpenGL."<<endl;
	cout<<"\tIt draws a polyline (formed by an arbitrary number of samples), which approximates a custom 'Parabola' curve of equation 'a x^2 + b x + c = 0' with vertex '(xv,yv)'."<<endl;
	cout<<"\tThe coefficients '(a,b,c)', as well as the radius 'R' for determing the x-range '[xv-R,xv+R]' where the 'Parabola' curve is drawn, are provided by the user, which can also:"<<endl<<endl;
	cout<<"\t\t-) increase the number of the samples for the polyline of interest by pressing the '+' key;"<<endl;
	cout<<"\t\t-) decrease the number of the samples for the polyline of interest by pressing the '-' key."<<endl<<endl;
	cout<<"\tIt is possible to end this program by pressing one among the 'Q' - 'q' - 'Esc' keys."<<endl<<endl;
	cout.flush();
	cout<<"\tPlease, insert all coefficients '(a,b,c)' for the equation 'a x^2 + b x + c = 0' (separated by spaces), describing the 'Parabola' curve of interest: ";
	cin>>a>>b>>c;
	if( (!cin) || (a==0) )
	{
		cout<<endl<<"\tPLEASE, INSERT VALID COEFFICIENTS '(a,b,c)' FOR THE EQUATION 'a x^2 + b x + c = 0' (SEPARATED BY SPACES), DESCRIBING THE 'PARABOLA' CURVE OF INTEREST."<<endl<<endl;
		cout.flush();
		return EXIT_FAILURE;
	}
	
	/* If we arrive here, we can compute the vertex '(xv,yv)' for the custom 'Parabola' curve of interest. */
	xv=-b/(2.0*a);
	yv=evaluateParabola(xv);
	cout<<"\tIn this case, the 'Parabola' curve of interest has equation ";
	exportEquation();
	cout<<", and vertex '(xv,yv)' = ("<<xv<<","<<yv<<")."<<endl<<endl;
	cout.flush();
	
	/* Now, we read the radius 'R' for determing the x-range '[xv-R,xv+R]' where the 'Parabola' curve is drawn. */
	cout<<"\tPlease, insert the radius 'R' (positive and not null), used for determining the x-range [";
	if(xv==0) cout<<"-R,+R]";
	else cout<<xv<<"-R,"<<xv<<"+R]";
	cout<<", where the 'Parabola' curve is drawn: ";
	cin>>radius;
	if( (!cin) || (radius<=0) )
	{
		cout<<endl<<"\tPLEASE, INSERT  A VALID VALUE FOR THE RADIUS 'R' (POSITIVE AND NOT NULL), USED FOR DETERMINING THE X-RANGE [";
		if(xv==0) cout<<"-R,+R]";
		else cout<<xv<<"-R,"<<xv<<"+R]";
		cout<<", WHERE THE 'PARABOLA' CURVE IS DRAWN."<<endl<<endl;
		cout.flush();
		return EXIT_FAILURE;
	}
	
	/* Now, we complete everything! */
	xmin=xv-radius;
	xmax=xv+radius;
	cout<<"\tThe x-range for the 'Parabola' of interest is: ["<<xmin<<","<<xmax<<"]."<<endl;
	vmin=evaluateParabola(xmin);
	vmax=evaluateParabola(xmax);
	ymin=min((float)min(vmin,vmax),yv);
	ymax=max((float)max(vmin,vmax),yv);
	cout<<"\tThe y-range for the 'Parabola' curve of interest: ["<<ymin<<","<<ymax<<"]"<<endl<<endl;
	h=fabs(ymin-ymax);
	
	/* If we arrive here, we can draw the polyline, approximating the 'Parabola' curve of interest. */
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
	glutInitWindowPosition(0,0);
	if(h==2*radius) glutInitWindowSize(500,500);
	else if(2*radius>h) { glutInitWindowSize(1000,1000*h/(2*radius)); }
	else { glutInitWindowSize(1000*2*radius/h,1000); }
	glutCreateWindow("The 'Example-025' Example, based on the (Old Mode) OpenGL");
	glutDisplayFunc(draw);
	glutReshapeFunc(resize);
	glutKeyboardFunc(manageKeys);
	glewExperimental = GL_TRUE;
   	glewInit();
   	initialize(); 
	glutMainLoop();
	return EXIT_SUCCESS;
}

/// This function exports the human-readable version of the equation for the <i>'Parabola'</i> curve of interest on the standard output.
void exportEquation()
{
	/* Now, we check the 'a' value in the equation 'ax^2+bx+c=0'. */
	cout<<"'";
	if(a>0)
	{
		if(fabs(a)!=1.0) cout<<fabs(a);
		cout<<"x^2 ";
	}
	else if(a<0)
	{
		cout<<"-";
		if(fabs(a)!=1.0) cout<<fabs(a);
		cout<<" x^2 ";
	}	
	
	/* Now, we check the 'a' value in the equation 'ax^2+bx+c=0'. */
	if(b>0)
	{
		if(fabs(b)!=1.0) cout<<"+ "<<fabs(b)<<" x ";
		else cout<<"+ x ";
	}
	else if(b<0)
	{
		if(fabs(b)!=1.0) cout<<"- "<<fabs(b)<<" x ";
		else cout<<"- x ";
	}

	/* Finally, we check the 'c' value in the equation 'ax^2+bx+c=0'. */
	if(c>0) { cout<<"+ "<<fabs(c)<<" "; }
	else if(c<0) { cout<<"- "<<fabs(c)<<" "; }
	cout<<"= 0'";
}

/// This function evaluates the y-value for equation, describing the custom <i>'Parabola'</i> curve of interest, at a given x-coordinate.
float evaluateParabola(float x) { return (a*x*x+b*x+c); }

/// This function is the keyboard input processing routine for the OpenGL window of interest.
void manageKeys(unsigned char key, int x, int y)
{
	/* We are interested only in the 'q' - 'Q' - 'Esc' - '+' - '-' keys */
	switch (key)
	{
		case 'q':
	
		/* The key is 'q', thus we can exit from this program. */
		cout<<endl;
		cout.flush();
		exit(EXIT_SUCCESS);
		break;
		
		case 'Q':
	
		/* The key is 'Q', thus we can exit from this program. */
		cout<<endl;
		cout.flush();
		exit(EXIT_SUCCESS);
		break;
		
		case 27:
	
		/* The key is 'Esc', thus we can exit from this program. */
		cout<<endl;
		cout.flush();
		exit(EXIT_SUCCESS);
		break;
		
		case '+':
		
		/* The key is '+', thus we increase the number of the samples in the polyline of interest! */
		num_samples=num_samples+1;
		glutPostRedisplay();
		break;
		
		case '-':
		
		/* The key is '-', thus we decrease the number of the samples (if possible) in the polyline of interest. */
		if(num_samples>3) num_samples=num_samples-1;
		else cout<<"\tThe minimum number 3 of samples is reached, and it is not possible to decrease again this number."<<endl;
		cout.flush();
		glutPostRedisplay();
		break;
	
		default:

    	/* Other keys are not important for us! */
    	break;
	}
}

/// This function updates the viewport for the scene when it is resized. */
void resize(int w, int h)
{
	float x0,x1,y0,y1;

	/* First, we set properly the x-range. */
	x0=xmin-0.1*fabs(xmin);
	x1=xmax+0.1*fabs(xmax);
	y0=ymin-0.1*fabs(ymin);
	y1=ymax+0.1*fabs(ymax);
	if(xmin==0)
	{
		x1=xmax+0.1*fabs(xmax);
		x0=-0.1*fabs(xmax);
	}
	else if(xmax==0)
	{
		x0=xmin-0.1*fabs(xmin);
		x1=0.1*fabs(xmin);
	}
	
	/* Now, we set properly the y-range. */
	if(ymin==0)
	{
		y1=ymax+0.1*fabs(ymax);
		y0=-0.1*fabs(ymax);
	}
	else if(ymax==0)
	{
		y0=ymin-0.1*fabs(ymin);
		y1=0.1*fabs(ymin);
	}
	
	/* We update the projections and the modeling matrices! */
	glViewport(0, 0, w, h);
   	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	glOrtho(x0,x1,y0,y1,-1,1);
   	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity();
}

/// This function initializes the OpenGL window of interest.
void initialize() 
{
	/* We initialize the OpenGL window of interest! */
	glClearColor(1.0, 1.0, 1.0, 0.0);
	num_samples=3;
	cout<<"\tThe polyline, approximating the 'Parabola' curve of equation ";
	exportEquation();
	cout<<", in the x-range ["<<xv-radius<<","<<xv+radius<<"], and with vertex ('"<<xv<<","<<yv<<"'), is initially formed by "<<num_samples<<" samples (the minimum number as possible), thus by "<<num_samples<<" vertices and "<<num_samples<<" edges."<<endl<<endl;
	cout.flush();
}

/// This function draws the polyline (in <i>'red'</i>), approximating the <i>'Parabola'</i> curve of interest, in the main OpenGL window.
void draw()
{
	float d,x;

	/* We draw the polyline (in 'red'), approximating the <i>'Parabola'</i> curve of interest, in the main OpenGL window. */
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_STRIP);
	d=(2*radius)/(num_samples-1);
	for(unsigned int k=0;k<num_samples;k++)
	{
		x=xmin+k*d;
		glVertex3f(x,evaluateParabola(x),0);
	}
	
	/* If we arrive here, all is ok */
	glEnd();
	glFlush();
	cout<<"\tThe polyline, approximating the 'Parabola' curve of interest, is currently formed by "<<num_samples<<" samples, thus by "<<num_samples<<" vertices and "<<num_samples<<" edges."<<endl;
	cout.flush();
}
