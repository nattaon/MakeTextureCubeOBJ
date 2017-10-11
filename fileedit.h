#ifndef FILEEDIT_H
#define FILEEDIT_H
#include <QMainWindow>
#include <QLineEdit>
#include <QDropEvent>
#include <QUrl>
#include <QDebug>
#include <QMimeData>

class FileEdit : public QLineEdit
{
	Q_OBJECT
public:
	explicit FileEdit(QWidget *parent = 0);

	void dragEnterEvent(QDragEnterEvent *e);
	void dropEvent(QDropEvent *e);
};

#endif // FILEEDIT_H