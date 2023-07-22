#include "aggiungi_candidato.h"
#include "ui_aggiungi_candidato.h"

Aggiungi_candidato::Aggiungi_candidato(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aggiungi_candidato)
{
    ui->setupUi(this);
}

Aggiungi_candidato::~Aggiungi_candidato()
{
    delete ui;
}

void Aggiungi_candidato::on_buttonBox_accepted()
{
    QString nome = ui->nome_text->toPlainText();
    QString cognome = ui->cognome_text->toPlainText();
    QString occupazione = ui->occupazione_text->toPlainText();
    QString genere;
    QString data_di_nascita = ui->dateEdit->date().toString("dd/MM/yyyy");

    if (ui->donna_radio->isChecked())
        genere = ui->donna_radio->text();
    else if (ui->uomo_radio->isChecked())
        genere = ui->uomo_radio->text();

    // Verifica se tutti i campi sono stati compilati
    if (nome.isEmpty() || cognome.isEmpty() || occupazione.isEmpty() || genere.isEmpty() || data_di_nascita.isEmpty()) {
        QMessageBox::warning(this, "Errore", "Candidato non inserito, compila tutti i campi.");
        return;
    } else if(ui->dateEdit->date() > QDate::currentDate()){
        QMessageBox::warning(this, "Data non valida", "Candidato non inserito, inserire una data di nascita valida.");
        return;
    }

    Candidato cd;
    cd.nome = nome;
    cd.cognome = cognome;
    cd.occupazione = occupazione;
    cd.genere = genere;
    cd.data_di_nascita = data_di_nascita;
    cd.idoneita = "0";
    emit add_signal(cd);

}

