#include "mainwindow.h"
#include "build/ui_mainwindow.h"

using namespace cv;
using namespace std;
void SourceImageMouseCallback(int e, int x, int y, int d, void *ptr);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	
    ui->setupUi(this);

	connect(ui->btn_src_open, SIGNAL(clicked()), this, SLOT(ButtonOpenSourceImagePressed()));
	connect(ui->btn_tar_open, SIGNAL(clicked()), this, SLOT(ButtonOpenTargetImagePressed()));

	connect(ui->btn_rot_ccw, SIGNAL(clicked()), this, SLOT(ButtonRotCCWPressed()));
	connect(ui->btn_rot_cw, SIGNAL(clicked()), this, SLOT(ButtonRotCWPressed()));

	connect(ui->btn_remove_point, SIGNAL(clicked()), this, SLOT(ButtonRemovePointPressed()));
	connect(ui->btn_clearall_point, SIGNAL(clicked()), this, SLOT(ButtonClearallPointPressed()));

	connect(ui->btn_new_img, SIGNAL(clicked()), this, SLOT(ButtonNewImagePressed()));
	connect(ui->btn_save_img, SIGNAL(clicked()), this, SLOT(ButtonSaveImagePressed()));
	connect(ui->btn_perspective, SIGNAL(clicked()), this, SLOT(ButtonPerspectiveTransformPressed()));

	connect(ui->tree_src_point, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(TreeSourcePointClicked(QTreeWidgetItem *)));


	//radio button
	ui->rb_1front->setChecked(true);
	ui->rb_2back->setChecked(false);
	ui->rb_3left->setChecked(false);
	ui->rb_4right->setChecked(false);
	ui->rb_5top->setChecked(false);
	ui->rb_6bottom->setChecked(false);

	connect(ui->btn_combine_png, SIGNAL(clicked()), this, SLOT(PressedCombineTexturePNG()));
	connect(ui->btn_create_obj, SIGNAL(clicked()), this, SLOT(PressedCreateOBJ_MTL()));
	connect(ui->btn_show_obj, SIGNAL(clicked()), this, SLOT(PressedShowObject()));

	write_file = new WriteOBJMTL();
}


MainWindow::~MainWindow()
{
    delete ui;
}




QString MainWindow::GetOpenImageFilename()
{
	QString filename = QFileDialog::getOpenFileName(this,
		tr("Open source image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

	return filename;
}

QString MainWindow::GetSaveImageFilename()
{
	QString filename = QFileDialog::getSaveFileName(this,
		tr("Save source image"), "", tr("Image Files (*.bmp)"));

	return filename;
}

void MainWindow::ButtonOpenSourceImagePressed()
{
	QString filename = ui->in_src_open->text();

	QFileInfo check_file(filename);
	if (check_file.exists() && check_file.isFile())
	{
		//qDebug() << "check_file.exists()";

	}
	else
	{
		filename = GetOpenImageFilename();
		if (filename.trimmed().isEmpty()) return;

	}


	open_img = imread(filename.toStdString(), CV_LOAD_IMAGE_COLOR);

	//src – input array.
	//dst – output array of the same size and type as src.
	//flipCode – a flag to specify how to flip the array; 
	///0 means flipping around the x - axis. 
	///positive value(for example, 1) means flipping around y - axis.
	///Negative value(for example, -1) means flipping around both axes.
	flip(open_img, source_img, 1); // mirror image due to kinect capture

	source_img.copyTo(open_img);
	imshow("Source Image", source_img);


	//determine source area need more code at wrap perspective
	setMouseCallback("Source Image", SourceImageMouseCallback, this);

	ButtonClearallPointPressed();
}
void MainWindow::ButtonOpenTargetImagePressed()
{

	QString filename = GetOpenImageFilename();
	if (filename.trimmed().isEmpty()) return;

	target_img = imread(filename.toStdString(), CV_LOAD_IMAGE_COLOR);
	imshow("Target Image", target_img);

}

void MainWindow::ButtonRotCCWPressed()
{
	//CCW = flip y * transpose
	Mat transposM, flipM, finalM;

	transpose(target_img, transposM);
	flip(transposM, finalM, 0);

	finalM.copyTo(target_img);
	imshow("Target Image", target_img);

}
void MainWindow::ButtonRotCWPressed()
{
	//CW = flip x * transpose
	Mat transposM, flipM, finalM;

	transpose(target_img, transposM);
	flip(transposM, finalM, 1);

	finalM.copyTo(target_img);
	imshow("Target Image", target_img);

}

void MainWindow::ButtonNewImagePressed()
{

	QString txt_width = ui->in_width->text();
	QString txt_height = ui->in_height->text();
	QString txt_depth = ui->in_depth->text();

	float convert2pixel = 3.7795;

	int w = convert2pixel*txt_width.toInt();
	int h = convert2pixel*txt_height.toInt();
	int d = convert2pixel*txt_depth.toInt();

	//1 mm = 3.7795

	if (ui->rb_1front->isChecked() || ui->rb_2back->isChecked())
	{
		//int_rows,int_cols
		target_img = Mat(h, w, CV_8UC3, Scalar(255, 255, 255));
	}
	else if (ui->rb_3left->isChecked() || ui->rb_4right->isChecked())
	{
		target_img = Mat(h, d, CV_8UC3, Scalar(255, 255, 255));
	}
	else if (ui->rb_5top->isChecked() || ui->rb_6bottom->isChecked())
	{
		target_img = Mat(d, w, CV_8UC3, Scalar(255, 255, 255));
	}

	cout << "new img " << target_img.cols << " x " << target_img.rows << endl;
	imshow("Target Image", target_img);


	//clear point vector
	target_img_points.clear();
	target_img_points.shrink_to_fit();

	//add 4 corners point (rectangular image)
	target_img_points.push_back(Point2f(0, 0));
	target_img_points.push_back(Point2f(0, target_img.rows));
	target_img_points.push_back(Point2f(target_img.cols, target_img.rows));
	target_img_points.push_back(Point2f(target_img.cols, 0));


}


void MainWindow::ButtonSaveImagePressed()
{
	QString filename = GetSaveImageFilename();
	if (filename.trimmed().isEmpty()) return;

	imwrite(filename.toStdString(), target_img);

	target_img = Mat();
	destroyWindow("Target Image");
}



/////////////////////////////////////////////

void MainWindow::ButtonRemovePointPressed()
{
	if (source_img_points.size() <= 0) return;

	QTreeWidgetItem *current_item = ui->tree_src_point->currentItem();
	int current_index = ui->tree_src_point->currentIndex().row();
	delete current_item;

	source_img_points.erase(source_img_points.begin() + current_index);

	//cout << "cleare clicked point" << endl;
	//cout << source_img_points << endl;


}
void MainWindow::ButtonClearallPointPressed()
{
	if (source_img_points.size() <= 0) return;

	for (int i = 0; i < source_img_points.size(); i++)
	{
		QTreeWidgetItem *current_item = ui->tree_src_point->topLevelItem(0);
		delete current_item;
	}

	source_img_points.clear();
	source_img_points.shrink_to_fit();

	//cout << "cleare clicked point" << endl;
	//cout << source_img_points << endl;

}

///////////////////////////////////////////////



void MainWindow::ButtonPerspectiveTransformPressed()
{
	cout << " Calculating Homography " << endl;
	cout << source_img_points.size() << " - " << target_img_points.size() << endl;

	Mat H = findHomography(source_img_points, target_img_points, 0);
	warpPerspective(open_img, target_img, H, target_img.size());

	//Mat source_transform;
	//warpPerspective(open_img, source_transform, H, target_img.size());

	//Mat transformed_gray, transformed_gray_inv;
	//Mat src_final, tar_final;
	//cvtColor(source_transform, transformed_gray, CV_BGR2GRAY);
	//threshold(transformed_gray, transformed_gray, 0, 255, CV_THRESH_BINARY);
	//bitwise_not(transformed_gray, transformed_gray_inv);
	//target_img.copyTo(tar_final, transformed_gray_inv);
	//target_img = source_transform + tar_final;

	imshow("Target Image", target_img);

	//H.release();
	//source_transform.release();
	//transformed_gray.release();
	//transformed_gray_inv.release();
	//src_final.release();
	//tar_final.release();

}


void MainWindow::TreeSourcePointClicked(QTreeWidgetItem *current_select_item)
{

}


////////////////SOURCE IMAGE//////////////////////

void SourceImageMouseCallback(int e, int x, int y, int d, void *ptr)
{
	MainWindow *mainWindow = (MainWindow *)(ptr);
	if (e == EVENT_LBUTTONDOWN)
	{
		cout << x << " " << y << endl;
		mainWindow->AddPointsToSourceTree(x, y);
	}
}

void MainWindow::AddPointsToSourceTree(int x, int y)
{
	if (source_img_points.size() >= 4)
	{
		cout << "source img : reach 4 selected points" << endl;
		return;
	}

	source_img_points.push_back(Point2f(float(x), float(y)));

	QTreeWidgetItem *new_item = new QTreeWidgetItem(ui->tree_src_point);
	new_item->setText(0, QString::number(x) + "," + QString::number(y));
	ui->tree_src_point->addTopLevelItem(new_item);

	circle(source_img, Point(x, y), 2, Scalar(0, 0, 255), 4);
	imshow("Source Image", source_img);
}

/********************************************************************************/
void MainWindow::PressedCombineTexturePNG()
{
	if (ui->textEdit->textureList.count() != 6)
	{
		QMessageBox::information(0, QString("PressedCombineTexturePNG()"), QString("No texture files"), QMessageBox::Ok);
		return;

	}

	//qDebug() << ui->textEdit->textureList.count();

	//theTexMap[i] = item.toStdString().c_str();
	qDebug() << ui->textEdit->textureList[0];


	Mat texture1_front = imread(ui->textEdit->textureList[0].toStdString());
	Mat texture2_back = imread(ui->textEdit->textureList[1].toStdString());
	Mat texture3_left = imread(ui->textEdit->textureList[2].toStdString());
	Mat texture4_right = imread(ui->textEdit->textureList[3].toStdString());
	Mat texture5_top = imread(ui->textEdit->textureList[4].toStdString());
	Mat texture6_bottom = imread(ui->textEdit->textureList[5].toStdString());

	qDebug() << "Width : " << texture1_front.cols;
	qDebug() << "Height: " << texture1_front.rows;
	qDebug() << "Depth: " << texture5_top.rows;

	
	/*if (texture1_front.rows + texture2_back.rows + texture5_top.rows + texture6_bottom.rows > 2048)
	{//texture img height is not fit
		qDebug() << "Height: " << texture1_front.rows + texture2_back.rows + texture5_top.rows + texture6_bottom.rows;
		//return;
	}
	else if (texture1_front.cols + texture3_left.cols > 1024)
	{//texture img width is not fit
		qDebug() << "texture Width : " << texture1_front.cols + texture3_left.cols;
		//return;
	}*/
	int tex_w = 2048;
	int tex_h = 2048;
	Mat texture_img = Mat(tex_h, tex_w, CV_8UC3, Scalar(0, 0, 0));//h x w

	Mat texture_imgroi;
	
	int roi_x1,roi_y1,roi_w, roi_h;
	int roi_x2, roi_y2;
	
	t1_pos.clear();
	t2_pos.clear();
	t3_pos.clear();
	t4_pos.clear();
	t5_pos.clear();
	t6_pos.clear();


	roi_x1 = 0;
	roi_y1 = 0;
	roi_w = texture1_front.cols;
	roi_h = texture1_front.rows;
	roi_x2 = roi_x1 + roi_w;
	roi_y2 = roi_y1 + roi_h;
	texture_imgroi = Mat(texture_img, Rect(roi_x1, roi_y1, roi_w, roi_h));
	texture1_front.copyTo(texture_imgroi);
	//texture_imgroi.release();
	t1_pos.push_back(Point2f((float)roi_x1 / tex_w, 1.0 - (float)roi_y1 / tex_h));
	t1_pos.push_back(Point2f((float)roi_x1 / tex_w, 1.0 - (float)roi_y2 / tex_h));
	t1_pos.push_back(Point2f((float)roi_x2 / tex_w, 1.0 - (float)roi_y2 / tex_h));
	t1_pos.push_back(Point2f((float)roi_x2 / tex_w, 1.0 - (float)roi_y1 / tex_h));

	//cout << t1_pos;

	roi_x1 = 0;
	roi_y1 = texture1_front.rows;
	roi_w = texture2_back.cols;
	roi_h = texture2_back.rows;
	roi_x2 = roi_x1 + roi_w;
	roi_y2 = roi_y1 + roi_h;
	texture_imgroi = Mat(texture_img, Rect(roi_x1, roi_y1, roi_w, roi_h));
	texture2_back.copyTo(texture_imgroi);
	//texture_imgroi.release();
	t2_pos.push_back(Point2f((float)roi_x1 / tex_w, 1.0 - (float)roi_y1 / tex_h));
	t2_pos.push_back(Point2f((float)roi_x1 / tex_w, 1.0 - (float)roi_y2 / tex_h));
	t2_pos.push_back(Point2f((float)roi_x2 / tex_w, 1.0 - (float)roi_y2 / tex_h));
	t2_pos.push_back(Point2f((float)roi_x2 / tex_w, 1.0 - (float)roi_y1 / tex_h));

	roi_x1 = texture1_front.cols;
	roi_y1 = 0;
	roi_w = texture3_left.cols;
	roi_h = texture3_left.rows;
	roi_x2 = roi_x1 + roi_w;
	roi_y2 = roi_y1 + roi_h;
	texture_imgroi = Mat(texture_img, Rect(roi_x1, roi_y1, roi_w, roi_h));
	texture3_left.copyTo(texture_imgroi);
	//texture_imgroi.release();
	t3_pos.push_back(Point2f((float)roi_x1 / tex_w, 1.0 - (float)roi_y1 / tex_h));
	t3_pos.push_back(Point2f((float)roi_x1 / tex_w, 1.0 - (float)roi_y2 / tex_h));
	t3_pos.push_back(Point2f((float)roi_x2 / tex_w, 1.0 - (float)roi_y2 / tex_h));
	t3_pos.push_back(Point2f((float)roi_x2 / tex_w, 1.0 - (float)roi_y1 / tex_h));

	roi_x1 = texture1_front.cols;
	roi_y1 = texture1_front.rows;
	roi_w = texture4_right.cols;
	roi_h = texture4_right.rows;
	roi_x2 = roi_x1 + roi_w;
	roi_y2 = roi_y1 + roi_h;
	texture_imgroi = Mat(texture_img, Rect(roi_x1, roi_y1, roi_w, roi_h));
	texture4_right.copyTo(texture_imgroi);
	//texture_imgroi.release();
	t4_pos.push_back(Point2f((float)roi_x1 / tex_w, 1.0 - (float)roi_y1 / tex_h));
	t4_pos.push_back(Point2f((float)roi_x1 / tex_w, 1.0 - (float)roi_y2 / tex_h));
	t4_pos.push_back(Point2f((float)roi_x2 / tex_w, 1.0 - (float)roi_y2 / tex_h));
	t4_pos.push_back(Point2f((float)roi_x2 / tex_w, 1.0 - (float)roi_y1 / tex_h));

	roi_x1 = 0;
	roi_y1 = texture1_front.rows + texture2_back.rows;
	roi_w = texture5_top.cols;
	roi_h = texture5_top.rows;
	roi_x2 = roi_x1 + roi_w;
	roi_y2 = roi_y1 + roi_h;
	texture_imgroi = Mat(texture_img, Rect(roi_x1, roi_y1, roi_w, roi_h));
	texture5_top.copyTo(texture_imgroi);
	//texture_imgroi.release();
	t5_pos.push_back(Point2f((float)roi_x1 / tex_w, 1.0 - (float)roi_y1 / tex_h));
	t5_pos.push_back(Point2f((float)roi_x1 / tex_w, 1.0 - (float)roi_y2 / tex_h));
	t5_pos.push_back(Point2f((float)roi_x2 / tex_w, 1.0 - (float)roi_y2 / tex_h));
	t5_pos.push_back(Point2f((float)roi_x2 / tex_w, 1.0 - (float)roi_y1 / tex_h));

	roi_x1 = 0;
	roi_y1 = texture1_front.rows + texture2_back.rows + texture5_top.rows;
	roi_w = texture6_bottom.cols;
	roi_h = texture6_bottom.rows;
	roi_x2 = roi_x1 + roi_w;
	roi_y2 = roi_y1 + roi_h;
	texture_imgroi = Mat(texture_img, Rect(roi_x1, roi_y1, roi_w, roi_h));
	texture6_bottom.copyTo(texture_imgroi);
	//texture_imgroi.release();
	t6_pos.push_back(Point2f((float)roi_x1 / tex_w, 1.0 - (float)roi_y1 / tex_h));
	t6_pos.push_back(Point2f((float)roi_x1 / tex_w, 1.0 - (float)roi_y2 / tex_h));
	t6_pos.push_back(Point2f((float)roi_x2 / tex_w, 1.0 - (float)roi_y2 / tex_h));
	t6_pos.push_back(Point2f((float)roi_x2 / tex_w, 1.0 - (float)roi_y1 / tex_h));

	imshow("texture_img", texture_img);

	QString texturename = ui->in_obj_name->text();

	texturename.append(".png");
	imwrite(texturename.toStdString(), texture_img);

	texture_img = Mat();
	//destroyWindow("Target Image");


}

void MainWindow::PressedCreateOBJ_MTL()
{
	QString txt_width = ui->in_width->text();
	QString txt_height = ui->in_height->text();
	QString txt_depth = ui->in_depth->text();

	QString texturename = ui->in_obj_name->text();

	if (txt_width == "100" && txt_height == "100" && txt_depth == "100")
	{
		QMessageBox::information(0, QString("PressedCreateOBJ_MTL()"), QString("No object size in mm"), QMessageBox::Ok);
		return;
	}
	if (t1_pos.size() != 4)
	{
		//QMessageBox::information(0, QString("PressedCreateOBJ_MTL()"), QString("No texture data"), QMessageBox::Ok);
		//return;
		//PressedCombineTexturePNG();
	}

	QString objname = texturename + ".obj";
	QString mtlname = texturename + ".mtl";
	QString pngname = texturename + ".png";
	//texturename.append(".obj");

	write_file->WriteOBJFile(objname.toStdString(), mtlname.toStdString(), 
		txt_width.toFloat() / 100, txt_height.toFloat() / 100, txt_depth.toFloat() / 100,
		t1_pos, t2_pos, t3_pos, t4_pos, t5_pos, t6_pos);
	
	write_file->WriteMTLFile(mtlname.toStdString(), pngname.toStdString());


	QMessageBox::information(0, QString("PressedCreateOBJ_MTL()"), QString("Finish"), QMessageBox::Ok);


}

void MainWindow::PressedShowObject()
{
	QString txt_width = ui->in_width->text();
	QString txt_height = ui->in_height->text();
	QString txt_depth = ui->in_depth->text();

	/*QString image_1front = ui->in_1front_filename->text();
	QString image_2back = ui->in_2back_filename->text();
	QString image_3left = ui->in_3left_filename->text();
	QString image_4right = ui->in_4right_filename->text();
	QString image_5top = ui->in_5top_filename->text();
	QString image_6bottom = ui->in_6bottom_filename->text();*/
//ui->textEdit
	QStringList imagenamelist;
	/*imagenamelist
		<< ui->in_1front_filename->text()
		<< ui->in_2back_filename->text()
		<< ui->in_3left_filename->text()
		<< ui->in_4right_filename->text()
		<< ui->in_5top_filename->text()
		<< ui->in_6bottom_filename->text();
		*/
	qDebug() << ui->textEdit->textureList;


	ui->widget->ShowObject(txt_width.toInt(), txt_height.toInt(), txt_depth.toInt(), imagenamelist);
}
