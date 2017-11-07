/********************************************************************************
** Form generated from reading UI file 'profilerMain.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILERMAIN_H
#define UI_PROFILERMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CProfilerMainClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_btnStart;
    QPushButton *m_btnStop;
    QSpacerItem *horizontalSpacer;
    QStatusBar *m_statusBar;

    void setupUi(QMainWindow *CProfilerMainClass)
    {
        if (CProfilerMainClass->objectName().isEmpty())
            CProfilerMainClass->setObjectName(QStringLiteral("CProfilerMainClass"));
        CProfilerMainClass->resize(658, 585);
        centralWidget = new QWidget(CProfilerMainClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_btnStart = new QPushButton(centralWidget);
        m_btnStart->setObjectName(QStringLiteral("m_btnStart"));
        m_btnStart->setEnabled(false);
        m_btnStart->setCheckable(false);

        horizontalLayout->addWidget(m_btnStart);

        m_btnStop = new QPushButton(centralWidget);
        m_btnStop->setObjectName(QStringLiteral("m_btnStop"));
        m_btnStop->setEnabled(false);
        m_btnStop->setCheckable(false);

        horizontalLayout->addWidget(m_btnStop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        CProfilerMainClass->setCentralWidget(centralWidget);
        m_statusBar = new QStatusBar(CProfilerMainClass);
        m_statusBar->setObjectName(QStringLiteral("m_statusBar"));
        CProfilerMainClass->setStatusBar(m_statusBar);

        retranslateUi(CProfilerMainClass);

        QMetaObject::connectSlotsByName(CProfilerMainClass);
    } // setupUi

    void retranslateUi(QMainWindow *CProfilerMainClass)
    {
        CProfilerMainClass->setWindowTitle(QApplication::translate("CProfilerMainClass", "CProfilerMain", Q_NULLPTR));
        m_btnStart->setText(QApplication::translate("CProfilerMainClass", "&Start", Q_NULLPTR));
        m_btnStop->setText(QApplication::translate("CProfilerMainClass", "S&top", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CProfilerMainClass: public Ui_CProfilerMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILERMAIN_H
