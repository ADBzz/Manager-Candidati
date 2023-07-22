/********************************************************************************
** Form generated from reading UI file 'dialogmodifica.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMODIFICA_H
#define UI_DIALOGMODIFICA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogModifica
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *nome_lay;
    QLabel *label;
    QTextEdit *nome_text;
    QVBoxLayout *nome_lay_2;
    QLabel *label_2;
    QTextEdit *cognome_text;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QVBoxLayout *nome_lay_3;
    QRadioButton *uomo_radio;
    QRadioButton *donna_radio;
    QVBoxLayout *nome_lay_4;
    QLabel *occupazione_label;
    QTextEdit *occupazione_text;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogModifica)
    {
        if (DialogModifica->objectName().isEmpty())
            DialogModifica->setObjectName(QString::fromUtf8("DialogModifica"));
        DialogModifica->resize(474, 442);
        DialogModifica->setMinimumSize(QSize(474, 442));
        DialogModifica->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(DialogModifica);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        nome_lay = new QVBoxLayout();
        nome_lay->setObjectName(QString::fromUtf8("nome_lay"));
        nome_lay->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(DialogModifica);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(189, 16));

        nome_lay->addWidget(label);

        nome_text = new QTextEdit(DialogModifica);
        nome_text->setObjectName(QString::fromUtf8("nome_text"));
        nome_text->setMaximumSize(QSize(9999, 27));

        nome_lay->addWidget(nome_text);


        verticalLayout_2->addLayout(nome_lay);

        nome_lay_2 = new QVBoxLayout();
        nome_lay_2->setObjectName(QString::fromUtf8("nome_lay_2"));
        nome_lay_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_2 = new QLabel(DialogModifica);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(189, 16));

        nome_lay_2->addWidget(label_2);

        cognome_text = new QTextEdit(DialogModifica);
        cognome_text->setObjectName(QString::fromUtf8("cognome_text"));
        cognome_text->setMaximumSize(QSize(999999, 27));

        nome_lay_2->addWidget(cognome_text);


        verticalLayout_2->addLayout(nome_lay_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(DialogModifica);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(189, 16));

        verticalLayout->addWidget(label_5);

        dateEdit = new QDateEdit(DialogModifica);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setMaximumSize(QSize(99999, 27));

        verticalLayout->addWidget(dateEdit);


        verticalLayout_2->addLayout(verticalLayout);

        nome_lay_3 = new QVBoxLayout();
        nome_lay_3->setObjectName(QString::fromUtf8("nome_lay_3"));
        nome_lay_3->setSizeConstraint(QLayout::SetMaximumSize);
        uomo_radio = new QRadioButton(DialogModifica);
        uomo_radio->setObjectName(QString::fromUtf8("uomo_radio"));

        nome_lay_3->addWidget(uomo_radio);

        donna_radio = new QRadioButton(DialogModifica);
        donna_radio->setObjectName(QString::fromUtf8("donna_radio"));
        donna_radio->setMaximumSize(QSize(437, 22));

        nome_lay_3->addWidget(donna_radio);


        verticalLayout_2->addLayout(nome_lay_3);

        nome_lay_4 = new QVBoxLayout();
        nome_lay_4->setObjectName(QString::fromUtf8("nome_lay_4"));
        nome_lay_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        occupazione_label = new QLabel(DialogModifica);
        occupazione_label->setObjectName(QString::fromUtf8("occupazione_label"));
        occupazione_label->setMaximumSize(QSize(189, 16));

        nome_lay_4->addWidget(occupazione_label);

        occupazione_text = new QTextEdit(DialogModifica);
        occupazione_text->setObjectName(QString::fromUtf8("occupazione_text"));
        occupazione_text->setMaximumSize(QSize(9999, 27));

        nome_lay_4->addWidget(occupazione_text);


        verticalLayout_2->addLayout(nome_lay_4);


        verticalLayout_3->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(DialogModifica);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setMinimumSize(QSize(456, 24));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(DialogModifica);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogModifica, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogModifica, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogModifica);
    } // setupUi

    void retranslateUi(QDialog *DialogModifica)
    {
        DialogModifica->setWindowTitle(QCoreApplication::translate("DialogModifica", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogModifica", "Nome", nullptr));
        label_2->setText(QCoreApplication::translate("DialogModifica", "Cognome", nullptr));
        label_5->setText(QCoreApplication::translate("DialogModifica", "TextLabel", nullptr));
        uomo_radio->setText(QCoreApplication::translate("DialogModifica", "Uomo", nullptr));
        donna_radio->setText(QCoreApplication::translate("DialogModifica", "Donna", nullptr));
        occupazione_label->setText(QCoreApplication::translate("DialogModifica", "Occupazione", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogModifica: public Ui_DialogModifica {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMODIFICA_H
