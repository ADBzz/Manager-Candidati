/********************************************************************************
** Form generated from reading UI file 'aggiungi_candidato.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGGIUNGI_CANDIDATO_H
#define UI_AGGIUNGI_CANDIDATO_H

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

class Ui_Aggiungi_candidato
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

    void setupUi(QDialog *Aggiungi_candidato)
    {
        if (Aggiungi_candidato->objectName().isEmpty())
            Aggiungi_candidato->setObjectName(QString::fromUtf8("Aggiungi_candidato"));
        Aggiungi_candidato->resize(469, 453);
        Aggiungi_candidato->setMinimumSize(QSize(469, 453));
        Aggiungi_candidato->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(Aggiungi_candidato);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        nome_lay = new QVBoxLayout();
        nome_lay->setObjectName(QString::fromUtf8("nome_lay"));
        nome_lay->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(Aggiungi_candidato);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(189, 16));

        nome_lay->addWidget(label);

        nome_text = new QTextEdit(Aggiungi_candidato);
        nome_text->setObjectName(QString::fromUtf8("nome_text"));
        nome_text->setMaximumSize(QSize(9999, 27));

        nome_lay->addWidget(nome_text);


        verticalLayout_2->addLayout(nome_lay);

        nome_lay_2 = new QVBoxLayout();
        nome_lay_2->setObjectName(QString::fromUtf8("nome_lay_2"));
        nome_lay_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_2 = new QLabel(Aggiungi_candidato);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(189, 16));

        nome_lay_2->addWidget(label_2);

        cognome_text = new QTextEdit(Aggiungi_candidato);
        cognome_text->setObjectName(QString::fromUtf8("cognome_text"));
        cognome_text->setMaximumSize(QSize(999999, 27));

        nome_lay_2->addWidget(cognome_text);


        verticalLayout_2->addLayout(nome_lay_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(Aggiungi_candidato);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(189, 16));

        verticalLayout->addWidget(label_5);

        dateEdit = new QDateEdit(Aggiungi_candidato);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setMaximumSize(QSize(99999, 27));

        verticalLayout->addWidget(dateEdit);


        verticalLayout_2->addLayout(verticalLayout);

        nome_lay_3 = new QVBoxLayout();
        nome_lay_3->setObjectName(QString::fromUtf8("nome_lay_3"));
        nome_lay_3->setSizeConstraint(QLayout::SetMaximumSize);
        uomo_radio = new QRadioButton(Aggiungi_candidato);
        uomo_radio->setObjectName(QString::fromUtf8("uomo_radio"));

        nome_lay_3->addWidget(uomo_radio);

        donna_radio = new QRadioButton(Aggiungi_candidato);
        donna_radio->setObjectName(QString::fromUtf8("donna_radio"));
        donna_radio->setMaximumSize(QSize(437, 22));

        nome_lay_3->addWidget(donna_radio);


        verticalLayout_2->addLayout(nome_lay_3);

        nome_lay_4 = new QVBoxLayout();
        nome_lay_4->setObjectName(QString::fromUtf8("nome_lay_4"));
        nome_lay_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        occupazione_label = new QLabel(Aggiungi_candidato);
        occupazione_label->setObjectName(QString::fromUtf8("occupazione_label"));
        occupazione_label->setMaximumSize(QSize(189, 16));

        nome_lay_4->addWidget(occupazione_label);

        occupazione_text = new QTextEdit(Aggiungi_candidato);
        occupazione_text->setObjectName(QString::fromUtf8("occupazione_text"));
        occupazione_text->setMaximumSize(QSize(9999, 27));

        nome_lay_4->addWidget(occupazione_text);


        verticalLayout_2->addLayout(nome_lay_4);


        verticalLayout_3->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(Aggiungi_candidato);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setMinimumSize(QSize(441, 61));
        buttonBox->setMaximumSize(QSize(16777215, 61));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(Aggiungi_candidato);
        QObject::connect(buttonBox, SIGNAL(accepted()), Aggiungi_candidato, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Aggiungi_candidato, SLOT(reject()));

        QMetaObject::connectSlotsByName(Aggiungi_candidato);
    } // setupUi

    void retranslateUi(QDialog *Aggiungi_candidato)
    {
        Aggiungi_candidato->setWindowTitle(QCoreApplication::translate("Aggiungi_candidato", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Aggiungi_candidato", "Nome", nullptr));
        label_2->setText(QCoreApplication::translate("Aggiungi_candidato", "Cognome", nullptr));
        label_5->setText(QCoreApplication::translate("Aggiungi_candidato", "TextLabel", nullptr));
        uomo_radio->setText(QCoreApplication::translate("Aggiungi_candidato", "Uomo", nullptr));
        donna_radio->setText(QCoreApplication::translate("Aggiungi_candidato", "Donna", nullptr));
        occupazione_label->setText(QCoreApplication::translate("Aggiungi_candidato", "Occupazione", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Aggiungi_candidato: public Ui_Aggiungi_candidato {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGGIUNGI_CANDIDATO_H
