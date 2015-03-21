/********************************************************************************
** Form generated from reading UI file 'tabwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABWIDGET_H
#define UI_TABWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabWidget
{
public:
    QWidget *tabGeneral;
    QVBoxLayout *verticalLayout;
    QLineEdit *editWorldName;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_9;
    QLabel *label_9;
    QSlider *sliderWindPower;
    QWidget *tabModel;
    QVBoxLayout *verticalLayout_3;
    QPushButton *buttonAddModel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *editModelName;
    QGraphicsView *graphicsView;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QFormLayout *formLayout;
    QLabel *label_7;
    QDoubleSpinBox *spinboxFreq;
    QLabel *label;
    QDoubleSpinBox *spinboxScaleX;
    QLabel *label_2;
    QDoubleSpinBox *spinboxScaleY;
    QLabel *label_3;
    QDoubleSpinBox *spinboxScaleZ;
    QFrame *line_2;
    QLabel *label_8;
    QLabel *label_4;
    QSpinBox *spinboxRotX;
    QLabel *label_6;
    QSpinBox *spinboxRotY;
    QLabel *label_5;
    QSpinBox *spinboxRotZ;
    QFrame *line;
    QLabel *label_10;
    QPushButton *buttonDelModel;
    QWidget *tabAlgo;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QButtonGroup *groupTerrain;
    QButtonGroup *groupClimat;

    void setupUi(QTabWidget *TabWidget)
    {
        if (TabWidget->objectName().isEmpty())
            TabWidget->setObjectName(QStringLiteral("TabWidget"));
        TabWidget->resize(198, 418);
        tabGeneral = new QWidget();
        tabGeneral->setObjectName(QStringLiteral("tabGeneral"));
        verticalLayout = new QVBoxLayout(tabGeneral);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        editWorldName = new QLineEdit(tabGeneral);
        editWorldName->setObjectName(QStringLiteral("editWorldName"));

        verticalLayout->addWidget(editWorldName);

        groupBox = new QGroupBox(tabGeneral);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioButton_5 = new QRadioButton(groupBox);
        groupTerrain = new QButtonGroup(TabWidget);
        groupTerrain->setObjectName(QStringLiteral("groupTerrain"));
        groupTerrain->addButton(radioButton_5);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        gridLayout->addWidget(radioButton_5, 1, 1, 1, 1);

        radioButton = new QRadioButton(groupBox);
        groupTerrain->addButton(radioButton);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_4 = new QRadioButton(groupBox);
        groupTerrain->addButton(radioButton_4);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        gridLayout->addWidget(radioButton_4, 0, 1, 1, 1);

        radioButton_3 = new QRadioButton(groupBox);
        groupTerrain->addButton(radioButton_3);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        gridLayout->addWidget(radioButton_3, 2, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox);
        groupTerrain->addButton(radioButton_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setChecked(false);

        gridLayout->addWidget(radioButton_2, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tabGeneral);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        radioButton_6 = new QRadioButton(groupBox_2);
        groupClimat = new QButtonGroup(TabWidget);
        groupClimat->setObjectName(QStringLiteral("groupClimat"));
        groupClimat->addButton(radioButton_6);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, radioButton_6);

        radioButton_7 = new QRadioButton(groupBox_2);
        groupClimat->addButton(radioButton_7);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, radioButton_7);

        radioButton_8 = new QRadioButton(groupBox_2);
        groupClimat->addButton(radioButton_8);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, radioButton_8);

        radioButton_9 = new QRadioButton(groupBox_2);
        groupClimat->addButton(radioButton_9);
        radioButton_9->setObjectName(QStringLiteral("radioButton_9"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, radioButton_9);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_9);

        sliderWindPower = new QSlider(groupBox_2);
        sliderWindPower->setObjectName(QStringLiteral("sliderWindPower"));
        sliderWindPower->setOrientation(Qt::Horizontal);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, sliderWindPower);


        verticalLayout->addWidget(groupBox_2);

        TabWidget->addTab(tabGeneral, QString());
        tabModel = new QWidget();
        tabModel->setObjectName(QStringLiteral("tabModel"));
        verticalLayout_3 = new QVBoxLayout(tabModel);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        buttonAddModel = new QPushButton(tabModel);
        buttonAddModel->setObjectName(QStringLiteral("buttonAddModel"));

        verticalLayout_3->addWidget(buttonAddModel);

        scrollArea = new QScrollArea(tabModel);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 172, 109));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout_2->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout_2->addWidget(pushButton_7);

        verticalSpacer_3 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        editModelName = new QLineEdit(tabModel);
        editModelName->setObjectName(QStringLiteral("editModelName"));

        verticalLayout_3->addWidget(editModelName);

        graphicsView = new QGraphicsView(tabModel);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout_3->addWidget(graphicsView);

        scrollArea_2 = new QScrollArea(tabModel);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, -181, 155, 250));
        formLayout = new QFormLayout(scrollAreaWidgetContents_2);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_7 = new QLabel(scrollAreaWidgetContents_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_7);

        spinboxFreq = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        spinboxFreq->setObjectName(QStringLiteral("spinboxFreq"));

        formLayout->setWidget(0, QFormLayout::FieldRole, spinboxFreq);

        label = new QLabel(scrollAreaWidgetContents_2);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        spinboxScaleX = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        spinboxScaleX->setObjectName(QStringLiteral("spinboxScaleX"));

        formLayout->setWidget(3, QFormLayout::FieldRole, spinboxScaleX);

        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_2);

        spinboxScaleY = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        spinboxScaleY->setObjectName(QStringLiteral("spinboxScaleY"));

        formLayout->setWidget(4, QFormLayout::FieldRole, spinboxScaleY);

        label_3 = new QLabel(scrollAreaWidgetContents_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_3);

        spinboxScaleZ = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        spinboxScaleZ->setObjectName(QStringLiteral("spinboxScaleZ"));

        formLayout->setWidget(5, QFormLayout::FieldRole, spinboxScaleZ);

        line_2 = new QFrame(scrollAreaWidgetContents_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(6, QFormLayout::SpanningRole, line_2);

        label_8 = new QLabel(scrollAreaWidgetContents_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(7, QFormLayout::SpanningRole, label_8);

        label_4 = new QLabel(scrollAreaWidgetContents_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_4);

        spinboxRotX = new QSpinBox(scrollAreaWidgetContents_2);
        spinboxRotX->setObjectName(QStringLiteral("spinboxRotX"));

        formLayout->setWidget(8, QFormLayout::FieldRole, spinboxRotX);

        label_6 = new QLabel(scrollAreaWidgetContents_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        formLayout->setWidget(9, QFormLayout::LabelRole, label_6);

        spinboxRotY = new QSpinBox(scrollAreaWidgetContents_2);
        spinboxRotY->setObjectName(QStringLiteral("spinboxRotY"));

        formLayout->setWidget(9, QFormLayout::FieldRole, spinboxRotY);

        label_5 = new QLabel(scrollAreaWidgetContents_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        formLayout->setWidget(10, QFormLayout::LabelRole, label_5);

        spinboxRotZ = new QSpinBox(scrollAreaWidgetContents_2);
        spinboxRotZ->setObjectName(QStringLiteral("spinboxRotZ"));

        formLayout->setWidget(10, QFormLayout::FieldRole, spinboxRotZ);

        line = new QFrame(scrollAreaWidgetContents_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(1, QFormLayout::SpanningRole, line);

        label_10 = new QLabel(scrollAreaWidgetContents_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(2, QFormLayout::SpanningRole, label_10);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_3->addWidget(scrollArea_2);

        buttonDelModel = new QPushButton(tabModel);
        buttonDelModel->setObjectName(QStringLiteral("buttonDelModel"));

        verticalLayout_3->addWidget(buttonDelModel);

        TabWidget->addTab(tabModel, QString());
        tabAlgo = new QWidget();
        tabAlgo->setObjectName(QStringLiteral("tabAlgo"));
        comboBox = new QComboBox(tabAlgo);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 20, 69, 22));
        comboBox_2 = new QComboBox(tabAlgo);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(110, 170, 69, 22));
        TabWidget->addTab(tabAlgo, QString());

        retranslateUi(TabWidget);

        TabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TabWidget);
    } // setupUi

    void retranslateUi(QTabWidget *TabWidget)
    {
        TabWidget->setWindowTitle(QApplication::translate("TabWidget", "TabWidget", 0));
        groupBox->setTitle(QApplication::translate("TabWidget", "Terrain", 0));
        radioButton_5->setText(QApplication::translate("TabWidget", "Plage", 0));
        radioButton->setText(QApplication::translate("TabWidget", "Plaine", 0));
        radioButton_4->setText(QApplication::translate("TabWidget", "D\303\251sert", 0));
        radioButton_3->setText(QApplication::translate("TabWidget", "For\303\252t", 0));
        radioButton_2->setText(QApplication::translate("TabWidget", "Montagne", 0));
        groupBox_2->setTitle(QApplication::translate("TabWidget", "Climat", 0));
        radioButton_6->setText(QApplication::translate("TabWidget", "Pluie", 0));
        radioButton_7->setText(QApplication::translate("TabWidget", "Neige", 0));
        radioButton_8->setText(QApplication::translate("TabWidget", "D\303\251gag\303\251", 0));
        radioButton_9->setText(QApplication::translate("TabWidget", "Brume", 0));
        label_9->setText(QApplication::translate("TabWidget", "Force du vent", 0));
        TabWidget->setTabText(TabWidget->indexOf(tabGeneral), QApplication::translate("TabWidget", "General", 0));
        buttonAddModel->setText(QApplication::translate("TabWidget", "Ajouter", 0));
        pushButton_5->setText(QApplication::translate("TabWidget", "A", 0));
        pushButton_6->setText(QApplication::translate("TabWidget", "Implementer", 0));
        pushButton_7->setText(QApplication::translate("TabWidget", "Plus tard", 0));
        editModelName->setInputMask(QString());
        editModelName->setText(QApplication::translate("TabWidget", "(nom) et en dessous preview", 0));
        label_7->setText(QApplication::translate("TabWidget", "Fr\303\251quence", 0));
        label->setText(QApplication::translate("TabWidget", "X", 0));
        label_2->setText(QApplication::translate("TabWidget", "Y", 0));
        label_3->setText(QApplication::translate("TabWidget", "Z", 0));
        label_8->setText(QApplication::translate("TabWidget", "Rotation", 0));
        label_4->setText(QApplication::translate("TabWidget", "X", 0));
        label_6->setText(QApplication::translate("TabWidget", "Y", 0));
        label_5->setText(QApplication::translate("TabWidget", "Z", 0));
        label_10->setText(QApplication::translate("TabWidget", "Echelle", 0));
        buttonDelModel->setText(QApplication::translate("TabWidget", "Supprimer", 0));
        TabWidget->setTabText(TabWidget->indexOf(tabModel), QApplication::translate("TabWidget", "Mod\303\250les", 0));
        TabWidget->setTabText(TabWidget->indexOf(tabAlgo), QApplication::translate("TabWidget", "Algos", 0));
    } // retranslateUi

};

namespace Ui {
    class TabWidget: public Ui_TabWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABWIDGET_H
