/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir_archivo;
    QAction *actionGuardar;
    QAction *actionGuardar_2;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QProgressBar *progressBar;
    QLabel *label_8;
    QLCDNumber *lcdNumber;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QTableWidget *tableWidget;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *tab_3;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_5;
    QWidget *tab_4;
    QPushButton *pushButton_8;
    QPlainTextEdit *plainTextEdit_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuArchivo_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(830, 480);
        actionAbrir_archivo = new QAction(MainWindow);
        actionAbrir_archivo->setObjectName("actionAbrir_archivo");
        actionGuardar = new QAction(MainWindow);
        actionGuardar->setObjectName("actionGuardar");
        actionGuardar_2 = new QAction(MainWindow);
        actionGuardar_2->setObjectName("actionGuardar_2");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(40, 10, 751, 431));
        tab = new QWidget();
        tab->setObjectName("tab");
        progressBar = new QProgressBar(tab);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(280, 290, 191, 41));
        progressBar->setValue(24);
        label_8 = new QLabel(tab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(260, 40, 191, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        label_8->setFont(font);
        lcdNumber = new QLCDNumber(tab);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(320, 160, 101, 111));
        plainTextEdit = new QPlainTextEdit(tab);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(480, 30, 261, 361));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(580, 0, 80, 24));
        formLayoutWidget = new QWidget(tab);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 140, 191, 221));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        spinBox = new QSpinBox(formLayoutWidget);
        spinBox->setObjectName("spinBox");
        spinBox->setMaximum(1000);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox);

        doubleSpinBox = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setMaximum(100000000.000000000000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, doubleSpinBox);

        spinBox_2 = new QSpinBox(formLayoutWidget);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setMaximum(10000);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox_2);

        spinBox_3 = new QSpinBox(formLayoutWidget);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setMaximum(1000);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox_3);

        spinBox_4 = new QSpinBox(formLayoutWidget);
        spinBox_4->setObjectName("spinBox_4");
        spinBox_4->setMaximum(10000);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBox_4);

        spinBox_5 = new QSpinBox(formLayoutWidget);
        spinBox_5->setObjectName("spinBox_5");
        spinBox_5->setMaximum(1000);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBox_5);

        spinBox_6 = new QSpinBox(formLayoutWidget);
        spinBox_6->setObjectName("spinBox_6");
        spinBox_6->setMaximum(10000);

        formLayout->setWidget(6, QFormLayout::FieldRole, spinBox_6);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 70, 101, 31));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(120, 70, 81, 31));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 30, 261, 24));
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(90, 0, 80, 24));
        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 70, 261, 291));
        pushButton_6 = new QPushButton(tab_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(280, 10, 111, 21));
        pushButton_7 = new QPushButton(tab_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(400, 10, 111, 21));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        graphicsView = new QGraphicsView(tab_3);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 40, 731, 351));
        pushButton_5 = new QPushButton(tab_3);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(340, 10, 80, 24));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        pushButton_8 = new QPushButton(tab_4);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(20, 20, 80, 24));
        plainTextEdit_2 = new QPlainTextEdit(tab_4);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(150, 10, 581, 371));
        pushButton_9 = new QPushButton(tab_4);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(20, 60, 80, 24));
        pushButton_10 = new QPushButton(tab_4);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(20, 100, 80, 24));
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 830, 21));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName("menuArchivo");
        menuArchivo_2 = new QMenu(menubar);
        menuArchivo_2->setObjectName("menuArchivo_2");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuArchivo_2->menuAction());
        menuArchivo->addAction(actionAbrir_archivo);
        menuArchivo_2->addAction(actionGuardar_2);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbrir_archivo->setText(QCoreApplication::translate("MainWindow", "Abrir", nullptr));
        actionGuardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        actionGuardar_2->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Total de neuronas", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Mostrar", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "voltaje", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "posicion x", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "posicion y", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "red", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "green", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "blue", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "A\303\261adir Inicio", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "A\303\261adir Final", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Buscar ", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Voltaje", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Ordenar por Id", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Ordenar por Voltaje", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Dibujar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Page", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Matriz", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Produndidad", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Amplitud", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Page", nullptr));
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        menuArchivo_2->setTitle(QCoreApplication::translate("MainWindow", "Archivo 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
