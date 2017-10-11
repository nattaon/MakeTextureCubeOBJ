#include "fileedit.h"

FileEdit::FileEdit(QWidget *parent) :
QLineEdit(parent)
{
	setAcceptDrops(true);
}

void FileEdit::dragEnterEvent(QDragEnterEvent *e)
{

	e->accept();
	//qDebug() << "dragEnterEvent e->accept()";

	/*if (e->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")){
		e->acceptProposedAction();
	}*/
}

void FileEdit::dropEvent(QDropEvent *e)
{



	QList<QUrl> urls;
	urls = e->mimeData()->urls();
	

	if (urls.size() < 6)
	{
		foreach(QUrl url, urls)
		{
			
			this->setText(url.toLocalFile());
			//this->setText(url.toString());
		}	
	}
	else if (urls.size() == 6)
	{
		qDebug() << "urls.size() == 6";

	}


	/*QByteArray encoded = e->mimeData()->data("application/x-qabstractitemmodeldatalist");
	QDataStream strm(&encoded, QIODevice::ReadOnly);
	while (!strm.atEnd()){
		int row, col;
		QMap<int, QVariant> data;
		strm >> row >> col >> data;
		this->setText(data[0].toString());
	}*/
}
