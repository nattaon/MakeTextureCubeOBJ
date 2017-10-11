#ifndef FILEEDITMULTIPLE_H
#define FILEEDITMULTIPLE_H
#include <QMainWindow>
#include <QTextEdit>
#include <QDropEvent>
#include <QUrl>
#include <QDebug>
#include <QMimeData>
#include <QStringList>


class FileEditMultiple : public QTextEdit
{
	Q_OBJECT
public:
	explicit FileEditMultiple(QWidget *parent = 0);

	void dragEnterEvent(QDragEnterEvent *e);
	void dropEvent(QDropEvent *e);

	QStringList textureList;
};

#endif // FILEEDITMULTIPLE_H