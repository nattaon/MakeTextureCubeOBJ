#include "FileEditMultiple.h"

FileEditMultiple::FileEditMultiple(QWidget *parent) :
QTextEdit(parent)
{
	setAcceptDrops(true);
}

void FileEditMultiple::dragEnterEvent(QDragEnterEvent *e)
{

	e->accept();
	//qDebug() << "dragEnterEvent e->accept()";

	/*if (e->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")){
	e->acceptProposedAction();
	}*/
}

void FileEditMultiple::dropEvent(QDropEvent *e)
{



	QList<QUrl> urls;
	urls = e->mimeData()->urls();

	this->setText("");
	textureList.clear();

	foreach(QUrl url, urls)
	{
		textureList << url.toLocalFile();
		this->append(url.toLocalFile());

		//this->setText(url.toString());
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
