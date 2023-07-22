/********************************************************************************
** Form generated from reading UI file 'managercandidati.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERCANDIDATI_H
#define UI_MANAGERCANDIDATI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerCandidati
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *modifica_btn;
    QPushButton *rimuovi_btn;
    QPushButton *nuovoCandidato_btn;
    QPushButton *caricaFile_btn;
    QPushButton *grafico_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ManagerCandidati)
    {
        if (ManagerCandidati->objectName().isEmpty())
            ManagerCandidati->setObjectName(QString::fromUtf8("ManagerCandidati"));
        ManagerCandidati->resize(738, 512);
        centralwidget = new QWidget(ManagerCandidati);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setAutoFillBackground(true);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setStretchLastSection(false);

        horizontalLayout->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        modifica_btn = new QPushButton(centralwidget);
        modifica_btn->setObjectName(QString::fromUtf8("modifica_btn"));
        modifica_btn->setFlat(false);

        verticalLayout->addWidget(modifica_btn);

        rimuovi_btn = new QPushButton(centralwidget);
        rimuovi_btn->setObjectName(QString::fromUtf8("rimuovi_btn"));

        verticalLayout->addWidget(rimuovi_btn);

        nuovoCandidato_btn = new QPushButton(centralwidget);
        nuovoCandidato_btn->setObjectName(QString::fromUtf8("nuovoCandidato_btn"));
        QFont font;
        font.setPointSize(9);
        nuovoCandidato_btn->setFont(font);

        verticalLayout->addWidget(nuovoCandidato_btn);

        caricaFile_btn = new QPushButton(centralwidget);
        caricaFile_btn->setObjectName(QString::fromUtf8("caricaFile_btn"));

        verticalLayout->addWidget(caricaFile_btn);

        grafico_btn = new QPushButton(centralwidget);
        grafico_btn->setObjectName(QString::fromUtf8("grafico_btn"));

        verticalLayout->addWidget(grafico_btn);


        horizontalLayout->addLayout(verticalLayout);

        ManagerCandidati->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ManagerCandidati);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 738, 21));
        ManagerCandidati->setMenuBar(menubar);
        statusbar = new QStatusBar(ManagerCandidati);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ManagerCandidati->setStatusBar(statusbar);

        retranslateUi(ManagerCandidati);

        modifica_btn->setDefault(false);


        QMetaObject::connectSlotsByName(ManagerCandidati);
    } // setupUi

    void retranslateUi(QMainWindow *ManagerCandidati)
    {
        ManagerCandidati->setWindowTitle(QCoreApplication::translate("ManagerCandidati", "ManagerCandidati", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ManagerCandidati", "Nome", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ManagerCandidati", "Cognome", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ManagerCandidati", "Data di Nascita", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ManagerCandidati", "Genere", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ManagerCandidati", "Occupazione", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ManagerCandidati", "Idoneit\303\240", nullptr));
        modifica_btn->setText(QCoreApplication::translate("ManagerCandidati", "Modifica", nullptr));
        rimuovi_btn->setText(QCoreApplication::translate("ManagerCandidati", "Rimuovi", nullptr));
        nuovoCandidato_btn->setText(QCoreApplication::translate("ManagerCandidati", "Nuovo Candidato", nullptr));
        caricaFile_btn->setText(QCoreApplication::translate("ManagerCandidati", "Carica file", nullptr));
        grafico_btn->setText(QCoreApplication::translate("ManagerCandidati", "Mostra Grafico", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagerCandidati: public Ui_ManagerCandidati {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERCANDIDATI_H
