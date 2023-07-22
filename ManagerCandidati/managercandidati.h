#ifndef MANAGERCANDIDATI_H
#define MANAGERCANDIDATI_H

#include "qtablewidget.h"
#include <QMainWindow>
#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QLineEdit>
#include <QBarSeries>
#include <QChart>
#include <QBarCategoryAxis>
#include <QChartView>
#include <QBarSet>
#include "ui_managercandidati.h"
#include <QFileDialog>
#include <QValueAxis>
#include <QPieSeries>



QT_BEGIN_NAMESPACE
namespace Ui { class ManagerCandidati; }
QT_END_NAMESPACE


struct Candidato{
    QString nome;
    QString cognome;
    QString data_di_nascita;
    QString genere;
    QString occupazione;
    QString idoneita;

};


class ManagerCandidati : public QMainWindow
{
    Q_OBJECT

public:
    ManagerCandidati(QWidget *parent = nullptr);
    ~ManagerCandidati();
    void extracted();
    void load();
    void add_from_file(QString dir);
    void createTable();
    void genereChart(QMap<QString, unsigned int> &map);
    void occupazioneChart(QMap<QString, unsigned int> &map);
    void etaChart(QMap<QString, unsigned int> &map);

private slots:
    void on_nuovoCandidato_btn_clicked();

    void add_slot(Candidato cd);

    void on_caricaFile_btn_clicked();

    void on_rimuovi_btn_clicked();

    void on_modifica_btn_clicked();

    void on_tableWidget_cellClicked(int row, int);

    void modifica_slot();

    void on_grafico_btn_clicked();

private:

    Ui::ManagerCandidati *ui;
    QString savefile = QDir::currentPath() +"/savefile.csv";
    QList<Candidato> candidati;
    friend class Aggiungi_candidato;
    int currRow;
    void closeEvent(QCloseEvent *event); //Si attiva alla chiusura del programma
    void save_data(); //Salva i dati su file
    QList<QLineEdit*> lineEdits; //Lista di puntatori a QLineEdit dove sono salvati gli score di idoneità

};
#endif // MANAGERCANDIDATI_H
