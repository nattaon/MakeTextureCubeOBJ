/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "fileedit.h"
#include "fileeditmultiple.h"
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    GLWidget *widget;
    QLineEdit *in_width;
    QRadioButton *rb_4right;
    QLineEdit *in_height;
    QPushButton *btn_remove_point;
    QRadioButton *rb_5top;
    QPushButton *btn_save_img;
    QRadioButton *rb_6bottom;
    QPushButton *btn_new_img;
    QPushButton *btn_rot_cw;
    QLabel *label_8;
    QLabel *label_7;
    QTreeWidget *tree_src_point;
    QLabel *label_2;
    QPushButton *btn_clearall_point;
    QPushButton *btn_perspective;
    QLabel *label_5;
    QLineEdit *in_depth;
    QPushButton *btn_src_open;
    QLabel *label;
    QRadioButton *rb_2back;
    FileEdit *in_src_open;
    QRadioButton *rb_1front;
    QPushButton *btn_rot_ccw;
    QRadioButton *rb_3left;
    QPushButton *btn_tar_open;
    QLabel *label_6;
    QLabel *label_3;
    QPushButton *btn_combine_png;
    QPushButton *btn_create_obj;
    QLineEdit *in_obj_name;
    QPushButton *btn_show_obj;
    FileEditMultiple *textEdit;
    QPushButton *btn_flip_v;
    QPushButton *btn_flip_h;
    QLabel *label_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(800, 355);
        MainWindow->setMaximumSize(QSize(16777212, 16777215));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new GLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(490, 10, 300, 300));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        in_width = new QLineEdit(centralWidget);
        in_width->setObjectName(QStringLiteral("in_width"));
        in_width->setGeometry(QRect(170, 60, 40, 20));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        in_width->setFont(font);
        in_width->setFocusPolicy(Qt::ClickFocus);
        in_width->setAlignment(Qt::AlignCenter);
        rb_4right = new QRadioButton(centralWidget);
        rb_4right->setObjectName(QStringLiteral("rb_4right"));
        rb_4right->setGeometry(QRect(160, 230, 95, 20));
        in_height = new QLineEdit(centralWidget);
        in_height->setObjectName(QStringLiteral("in_height"));
        in_height->setGeometry(QRect(210, 60, 40, 20));
        in_height->setFont(font);
        in_height->setFocusPolicy(Qt::ClickFocus);
        in_height->setAlignment(Qt::AlignCenter);
        btn_remove_point = new QPushButton(centralWidget);
        btn_remove_point->setObjectName(QStringLiteral("btn_remove_point"));
        btn_remove_point->setGeometry(QRect(20, 270, 61, 28));
        rb_5top = new QRadioButton(centralWidget);
        rb_5top->setObjectName(QStringLiteral("rb_5top"));
        rb_5top->setGeometry(QRect(160, 250, 95, 20));
        btn_save_img = new QPushButton(centralWidget);
        btn_save_img->setObjectName(QStringLiteral("btn_save_img"));
        btn_save_img->setGeometry(QRect(340, 90, 141, 41));
        rb_6bottom = new QRadioButton(centralWidget);
        rb_6bottom->setObjectName(QStringLiteral("rb_6bottom"));
        rb_6bottom->setGeometry(QRect(160, 270, 95, 20));
        btn_new_img = new QPushButton(centralWidget);
        btn_new_img->setObjectName(QStringLiteral("btn_new_img"));
        btn_new_img->setGeometry(QRect(340, 10, 141, 41));
        btn_rot_cw = new QPushButton(centralWidget);
        btn_rot_cw->setObjectName(QStringLiteral("btn_rot_cw"));
        btn_rot_cw->setGeometry(QRect(300, 147, 51, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(250, 40, 41, 20));
        label_8->setFont(font);
        label_8->setFocusPolicy(Qt::NoFocus);
        label_8->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(290, 60, 41, 20));
        label_7->setFont(font);
        label_7->setFocusPolicy(Qt::NoFocus);
        label_7->setAlignment(Qt::AlignCenter);
        tree_src_point = new QTreeWidget(centralWidget);
        tree_src_point->setObjectName(QStringLiteral("tree_src_point"));
        tree_src_point->setGeometry(QRect(10, 120, 141, 141));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 130, 81, 16));
        btn_clearall_point = new QPushButton(centralWidget);
        btn_clearall_point->setObjectName(QStringLiteral("btn_clearall_point"));
        btn_clearall_point->setGeometry(QRect(90, 270, 61, 28));
        btn_perspective = new QPushButton(centralWidget);
        btn_perspective->setObjectName(QStringLiteral("btn_perspective"));
        btn_perspective->setGeometry(QRect(340, 50, 141, 41));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 40, 41, 20));
        label_5->setFont(font);
        label_5->setFocusPolicy(Qt::NoFocus);
        label_5->setAlignment(Qt::AlignCenter);
        in_depth = new QLineEdit(centralWidget);
        in_depth->setObjectName(QStringLiteral("in_depth"));
        in_depth->setGeometry(QRect(250, 60, 40, 20));
        in_depth->setFont(font);
        in_depth->setFocusPolicy(Qt::ClickFocus);
        in_depth->setAlignment(Qt::AlignCenter);
        btn_src_open = new QPushButton(centralWidget);
        btn_src_open->setObjectName(QStringLiteral("btn_src_open"));
        btn_src_open->setGeometry(QRect(20, 40, 141, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 90, 141, 16));
        label->setAlignment(Qt::AlignCenter);
        rb_2back = new QRadioButton(centralWidget);
        rb_2back->setObjectName(QStringLiteral("rb_2back"));
        rb_2back->setGeometry(QRect(160, 190, 95, 20));
        in_src_open = new FileEdit(centralWidget);
        in_src_open->setObjectName(QStringLiteral("in_src_open"));
        in_src_open->setGeometry(QRect(20, 10, 311, 22));
        rb_1front = new QRadioButton(centralWidget);
        rb_1front->setObjectName(QStringLiteral("rb_1front"));
        rb_1front->setGeometry(QRect(160, 170, 95, 20));
        btn_rot_ccw = new QPushButton(centralWidget);
        btn_rot_ccw->setObjectName(QStringLiteral("btn_rot_ccw"));
        btn_rot_ccw->setGeometry(QRect(250, 147, 51, 21));
        rb_3left = new QRadioButton(centralWidget);
        rb_3left->setObjectName(QStringLiteral("rb_3left"));
        rb_3left->setGeometry(QRect(160, 210, 95, 20));
        btn_tar_open = new QPushButton(centralWidget);
        btn_tar_open->setObjectName(QStringLiteral("btn_tar_open"));
        btn_tar_open->setGeometry(QRect(190, 90, 141, 41));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(210, 40, 41, 20));
        label_6->setFont(font);
        label_6->setFocusPolicy(Qt::NoFocus);
        label_6->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 100, 141, 20));
        label_3->setAlignment(Qt::AlignCenter);
        btn_combine_png = new QPushButton(centralWidget);
        btn_combine_png->setObjectName(QStringLiteral("btn_combine_png"));
        btn_combine_png->setGeometry(QRect(160, 300, 181, 41));
        btn_create_obj = new QPushButton(centralWidget);
        btn_create_obj->setObjectName(QStringLiteral("btn_create_obj"));
        btn_create_obj->setGeometry(QRect(350, 300, 131, 41));
        in_obj_name = new QLineEdit(centralWidget);
        in_obj_name->setObjectName(QStringLiteral("in_obj_name"));
        in_obj_name->setGeometry(QRect(10, 310, 141, 22));
        btn_show_obj = new QPushButton(centralWidget);
        btn_show_obj->setObjectName(QStringLiteral("btn_show_obj"));
        btn_show_obj->setGeometry(QRect(490, 320, 191, 31));
        textEdit = new FileEditMultiple(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(250, 170, 231, 121));
        btn_flip_v = new QPushButton(centralWidget);
        btn_flip_v->setObjectName(QStringLiteral("btn_flip_v"));
        btn_flip_v->setGeometry(QRect(360, 147, 51, 21));
        btn_flip_h = new QPushButton(centralWidget);
        btn_flip_h->setObjectName(QStringLiteral("btn_flip_h"));
        btn_flip_h->setGeometry(QRect(410, 147, 71, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(360, 130, 81, 16));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "3dbpp", 0));
        in_width->setText(QApplication::translate("MainWindow", "157", 0));
        rb_4right->setText(QApplication::translate("MainWindow", "(4) right", 0));
        in_height->setText(QApplication::translate("MainWindow", "95", 0));
        btn_remove_point->setText(QApplication::translate("MainWindow", "remove", 0));
        rb_5top->setText(QApplication::translate("MainWindow", "(5) top", 0));
        btn_save_img->setText(QApplication::translate("MainWindow", "5.Save image (bmp)", 0));
        rb_6bottom->setText(QApplication::translate("MainWindow", "(6) bottom", 0));
        btn_new_img->setText(QApplication::translate("MainWindow", "3.New image", 0));
        btn_rot_cw->setText(QApplication::translate("MainWindow", "90CW", 0));
        label_8->setText(QApplication::translate("MainWindow", "depth", 0));
        label_7->setText(QApplication::translate("MainWindow", "mm", 0));
        QTreeWidgetItem *___qtreewidgetitem = tree_src_point->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Points", 0));
        label_2->setText(QApplication::translate("MainWindow", "Rotate target", 0));
        btn_clearall_point->setText(QApplication::translate("MainWindow", "clear all", 0));
        btn_perspective->setText(QApplication::translate("MainWindow", "4.Crop perspective", 0));
        label_5->setText(QApplication::translate("MainWindow", "width", 0));
        in_depth->setText(QApplication::translate("MainWindow", "60", 0));
        btn_src_open->setText(QApplication::translate("MainWindow", "1.Open source image", 0));
        label->setText(QApplication::translate("MainWindow", "2.Select 4 points", 0));
        rb_2back->setText(QApplication::translate("MainWindow", "(2) back", 0));
        in_src_open->setText(QApplication::translate("MainWindow", "drag image to crop perspective", 0));
        rb_1front->setText(QApplication::translate("MainWindow", "(1) front", 0));
        btn_rot_ccw->setText(QApplication::translate("MainWindow", "90CCW", 0));
        rb_3left->setText(QApplication::translate("MainWindow", "(3) left", 0));
        btn_tar_open->setText(QApplication::translate("MainWindow", "(a)Open target image", 0));
        label_6->setText(QApplication::translate("MainWindow", "height", 0));
        label_3->setText(QApplication::translate("MainWindow", " (U direction)", 0));
        btn_combine_png->setText(QApplication::translate("MainWindow", "6.Combine to Texture (png)", 0));
        btn_create_obj->setText(QApplication::translate("MainWindow", "7.Create obj and mtl", 0));
        in_obj_name->setText(QApplication::translate("MainWindow", "obj_", 0));
        btn_show_obj->setText(QApplication::translate("MainWindow", "Show 6 faces object", 0));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">1.drag 6 texture images here</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">2</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">3</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size"
                        ":9pt;\">4</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">5</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">6</span></p></body></html>", 0));
        btn_flip_v->setText(QApplication::translate("MainWindow", "vertical", 0));
        btn_flip_h->setText(QApplication::translate("MainWindow", "horizontal", 0));
        label_4->setText(QApplication::translate("MainWindow", "Flip", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
