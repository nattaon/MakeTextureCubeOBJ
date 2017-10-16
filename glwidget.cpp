#include "glwidget.h"
#include <GL/glut.h>
#include <iostream>
using namespace std;

static GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
static GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
static GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
static GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

static GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
static GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
static GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
static GLfloat high_shininess[] = { 100.0 };

GLWidget::GLWidget(QWidget *parent) :
QGLWidget(parent)
{
	ResetWindow();

}

void GLWidget::initializeGL()
{
	//std::cout << "initializeGL" << std::endl;
	//windowsize=500*500
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glClearColor(0.1, 0.1, 0.1, 1);
	//glClearColor(1.0, 1.0, 1.0, 1);//white background
	//glClearColor(0.0, 0.0, 0.0, 1);//black background

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

}
void GLWidget::paintGL()
{
	//std::cout << "paintGL" << std::endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(xMove, yMove, zMove);


	//std::cout << "rotation " << xRot << " " << yRot << " " << zRot << std::endl;

	glRotatef(xRot, 1.0, 0.0, 0.0);
	glRotatef(yRot, 0.0, 1.0, 0.0);
	glRotatef(zRot, 0.0, 0.0, 1.0);

	glScalef(zoom, zoom, zoom);

	DrawAxis(axis_length);
	DrawBin();



}
void GLWidget::resizeGL(int w, int h)
{
	//be called at first time
	//std::cout << "resizeGL w*h:" << w <<"*"<< h <<std::endl;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float length = 500;
	glOrtho(-1 * length, length, -1 * length, length, -1 * length, length);
	//glOrtho(-250.0, 250.0, -250.0, 250.0, -250.0, 250.0);
	//glOrtho(-1 * bin_w*2, bin_w*2, -1 * bin_h*2, bin_h*2, -1 * bin_d*2, bin_d*2);//left,right,bottom,top,near.far
	//glOrtho(-2, +2, -2, +2, 1.0, 15.0);

	glMatrixMode(GL_MODELVIEW);

}
void GLWidget::ResetWindow()
{
	//xRot = 45;
	//yRot = 375;
	//zRot = 0;
	axis_length = 200;
	xLen = 50;
	yLen = 50;
	zLen = 50;

	//box17
	xRot = 30;
	yRot = 30;
	zRot = 0;

	xMove = -296;
	yMove = -124;
	zMove = 0;

	zoom = 1.6;

	hasTexture = false;


	updateGL();
}


static void qNormalizeAngle(int &angle)
{
	while (angle < 0)
		angle += 360;
	while (angle > 360)
		angle -= 360;
}


void GLWidget::setXRotation(int angle)
{
	qNormalizeAngle(angle);
	if (angle != xRot) {
		xRot = angle;
		cout << "rotation x,y,z= " << xRot << "," << yRot << "," << zRot << endl;
		//emit xRotationChanged(angle);
		updateGL();
	}
}

void GLWidget::setYRotation(int angle)
{
	qNormalizeAngle(angle);
	if (angle != yRot) {
		yRot = angle;
		//emit yRotationChanged(angle);
		updateGL();
	}
}

void GLWidget::setZRotation(int angle)
{
	qNormalizeAngle(angle);
	if (angle != zRot) {
		zRot = angle;
		//emit zRotationChanged(angle);
		updateGL();
	}
}
void GLWidget::setXTranslation(int value)
{
	xMove += value;
	std::cout << "Move x,y :" << xMove << "," << yMove << std::endl;
	updateGL();
}
void GLWidget::setYTranslation(int value)
{
	yMove -= value;
	std::cout << "Move x,y :" << xMove << "," << yMove << std::endl;
	updateGL();

}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
	//react on left click, right click, wheel pressed
	lastPos = event->pos();
	//std::cout << lastPos.x() << "," << lastPos.y() << std::endl;
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
	int dx = event->x() - lastPos.x();
	int dy = event->y() - lastPos.y();

	//std::cout << "dx:dy " << dx << ":" << dy << std::endl;

	if (event->buttons() & Qt::LeftButton)
	{
		setXRotation(xRot + dy);
		setYRotation(yRot + dx);
	}
	else if (event->buttons() & Qt::RightButton)
	{
		setXRotation(xRot + dy);
		setZRotation(zRot + dx);
	}
	else if (event->buttons() & Qt::MidButton)
	{
		setXTranslation(dx);
		setYTranslation(dy);
	}

	lastPos = event->pos();
}
void GLWidget::wheelEvent(QWheelEvent *event)
{

	//mouse wheel up = zoom in
	if (event->delta() == 120)
	{
		zoom += 0.1;
	}
	//mouse wheel up = zoom out
	else if (event->delta() == -120)
	{
		zoom -= 0.1;
	}
	else
	{
		std::cout << "delta value forbidden " << event->delta() << std::endl;
	}
	std::cout << "zoom=" << zoom << std::endl;
	updateGL();
}


void GLWidget::DrawAxis(float length)
{
	glPushMatrix();
	{
		glLineWidth(3.0);
		glBegin(GL_LINES);
		glColor3d(1.0, 0.0, 0.0);//red
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(length, 0.0, 0.0);

		glColor3d(0.0, 1.0, 0.0);//green
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(0.0, length, 0.0);

		glColor3d(0.0, 0.0, 1.0);//blue
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(0.0, 0.0, length);
		glEnd();
		glLineWidth(1.0);
	}
	glPopMatrix();
}

void GLWidget::DrawBin()
{

	glPushMatrix();
	{
		glTranslatef(xLen / 2, yLen / 2, zLen / 2);
		glScalef(xLen, yLen, zLen);
		glColor3d(1.0, 1.0, 1.0);
		glutWireCube(1.0);
		//glutSolidCube(1.0);

	}
	glPopMatrix();	
	

	
}

/********************************************************/



void GLWidget::ShowObject(int width, int height, int depth, QStringList imagenamelist)
{
	


}
