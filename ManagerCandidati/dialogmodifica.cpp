#include "dialogmodifica.h"
#include "ui_dialogmodifica.h"

// Costruttore del form per la modifica di un candidato
DialogModifica::DialogModifica(Candidato *cand, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModifica),
    cd(cand)
{
    ui->setupUi(this);

    ui->nome_text->setText(cd->nome);
    ui->cognome_text->setText(cd->cognome);
    ui->dateEdit->setDate(QDate::fromString(cd->data_di_nascita));
    if(cd->genere == "Uomo")
        ui->uomo_radio->setChecked(true);
    else if(cd->genere == "Donna")
        ui->donna_radio->setChecked(true);
    ui->occupazione_text->setText(cd->occupazione);
    QDate data = QDate::fromString(cand->data_di_nascita, "dd/MM/yyyy");
    ui->dateEdit->setDate(data);

}

DialogModifica::~DialogModifica()
{
    delete ui;
}

//Si attiva al click del bottone "ok", modifica i dati del candidato
void DialogModifica::on_buttonBox_accepted()
{
    QString nome = ui->nome_text->toPlainText().trimmed();
    QString cognome = ui->cognome_text->toPlainText().trimmed();
    QString occupazione = ui->occupazione_text->toPlainText().trimmed();
    QString genere;
    QString dataDiNascita = ui->dateEdit->date().toString("dd/MM/yyyy");


    if (ui->donna_radio->isChecked())
        genere = ui->donna_radio->text();
    else if (ui->uomo_radio->isChecked())
        genere = ui->uomo_radio->text();

    if (nome.isEmpty() || cognome.isEmpty() || occupazione.isEmpty() || genere.isEmpty())
    {
        QMessageBox::warning(this, "Campi vuoti", "Modifica non effettuata, non lasciare campi vuoti.");
        return;
    } else if(ui->dateEdit->date() > QDate::currentDate()){
        QMessageBox::warning(this, "Data non valida", "Modifica non effettuata, inserire una data di nascita valida.");
    }

    cd->nome = nome;
    cd->cognome = cognome;
    cd->occupazione = occupazione;
    cd->genere = genere;
    cd->data_di_nascita = dataDiNascita;

    emit modifica_signal();
}

