#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QDebug>
#include <QStringList>
#include <QString>
#include <QMouseEvent>
#include <QKeyEvent>
#include "RgbImage.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent=0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
	//automatic enable function
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);
	//void keyPressEvent(QKeyEvent * event);


	void ResetWindow();
	void ShowObject(int width, int heihgt, int depth, QStringList imagename);



	public slots:
	// slots for xyz-rotation slider
	void setXRotation(int angle);
	void setYRotation(int angle);
	void setZRotation(int angle);

	void setXTranslation(int value);
	void setYTranslation(int value);

private:
	//void draw();

	int xRot;
	int yRot;
	int zRot;
	float xMove;
	float yMove;
	float zMove;
	float zoom;
	QPoint lastPos;
	int axis_length;
	float xLen, yLen, zLen;
	GLuint *textures;

	bool hasTexture;


	void DrawAxis(float length);
	void DrawBin();
};

#endif // GLWIDGET_H
