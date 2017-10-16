#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include <QFileInfo>
#include <opencv2/opencv.hpp>
#include "writeobjmtl.h"


namespace Ui {
	class MainWindow;
}



class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void AddPointsToSourceTree(int x, int y);

	std::vector<cv::Point2f> t1_pos, t2_pos, t3_pos, t4_pos, t5_pos, t6_pos;//U direction

private:
	Ui::MainWindow *ui;
	cv::Mat open_img, source_img, target_img;
	std::vector<cv::Mat> history_img;
	std::vector<cv::Point2f> source_img_points, target_img_points;

	QString GetOpenImageFilename();
	QString GetSaveImageFilename();
	//void SourceImageMouseCallback(int e, int x, int y, int d, void *ptr);

	WriteOBJMTL *write_file;


	private slots:
	void ButtonOpenSourceImagePressed();
	void ButtonOpenTargetImagePressed();

	void ButtonRotCCWPressed();
	void ButtonRotCWPressed();

	void ButtonFlipVerticalPressed();
	void ButtonFlipHorizontalPressed();

	void ButtonRemovePointPressed();
	void ButtonClearallPointPressed();

	void ButtonNewImagePressed();
	void ButtonSaveImagePressed();
	void ButtonPerspectiveTransformPressed();


	void TreeSourcePointClicked(QTreeWidgetItem *current_select_item);

	void PressedCombineTexturePNG();
	void PressedCreateOBJ_MTL();
	void PressedShowObject();

};

#endif // MAINWINDOW_H
