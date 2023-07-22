#include "managercandidati.h"
#include "aggiungi_candidato.h"
#include "dialogmodifica.h"
#include "qdatetime.h"
ManagerCandidati::ManagerCandidati(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ManagerCandidati)
{
    ui->setupUi(this);
}

ManagerCandidati::~ManagerCandidati()
{
    delete ui;
}

// Viene chiamata all'apertura del programma, carica i dati contenuti nel savefile
// all'interno della lista di candidati per poi chiamare createTable() per la creazione della tabella.
void ManagerCandidati::load(){

    if(!(QFileInfo::exists(savefile))){
        QFile filename(QDir::currentPath());
        filename.setFileName("savefile.csv");
        filename.open(QIODevice::ReadOnly);
    }
    else {
        QFile data(savefile);
        data.open(QIODevice::ReadOnly);
        QTextStream stream(&data);
        QStringList listaCandidati;
        while(!stream.atEnd()){
            QString data = stream.readLine();
            listaCandidati.append(data.split(','));
        }
        for(int i = 0; i < listaCandidati.size();){
            Candidato cd;
            for(int j = 0; j < 6; ++j){
                switch(j){
                case 0: cd.nome = listaCandidati[i];
                    break;
                case 1: cd.cognome = listaCandidati[i];
                    break;
                case 2: cd.data_di_nascita = listaCandidati[i];
                    break;
                case 3: cd.genere = listaCandidati[i];
                    break;
                case 4:
                    cd.occupazione = listaCandidati[i];
                    break;
                case 5: {
                    cd.idoneita = listaCandidati[i];
                    candidati.append(cd);
                }

                }
                    ++i;

            }
        }
        data.close();
    }

    ui->rimuovi_btn->setDisabled(1);
    ui->modifica_btn->setDisabled(1);

    createTable();
}

// Legge un file *.csv e ne aggiunge i candidati all'interno della tabella.
// il file deve essere così strutturato: nome,cognome,data_di_nascita,genere,occupazione
void ManagerCandidati::add_from_file(QString dir)
{

    QFile data(dir);

    data.open(QIODevice::ReadOnly);
    QTextStream stream(&data);
    QStringList listaCandidati;
    while(!stream.atEnd()){
        QString data = stream.readLine();
        listaCandidati.append(data.split(','));
    }
    for(int i = 0; i < listaCandidati.size();){
        Candidato cd;
        for(int j = 0; j < 5; ++j){
            if(i < listaCandidati.size()){
                switch(j){
                case 0: cd.nome = listaCandidati[i];
                        break;
                case 1: cd.cognome = listaCandidati[i];
                        break;
                case 2: cd.data_di_nascita = listaCandidati[i];
                        break;
                case 3: cd.genere = listaCandidati[i];
                        break;
                case 4: {
                        cd.occupazione = listaCandidati[i];
                        cd.idoneita = "0";
                        candidati.append(cd);
                }
                break;

                }
                ++i;

            } else {
                QMessageBox::warning(this, "Formato non valido", "Candidati non inseriti, selezionare un file valido.");
                return;
            }
        }
    }
    data.close();
    createTable();

}


//Crea la tabella dei candidati a partire dalla lista "candidati"
void ManagerCandidati::createTable()
{

    ui -> tableWidget -> setRowCount(candidati.size());
    QHeaderView* header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    lineEdits.clear();

    for(int i = 0; i < candidati.size(); ++i){
        Candidato candidato = candidati.at(i);

        QTableWidgetItem* nomeItem = new QTableWidgetItem(candidato.nome);
        QTableWidgetItem* cognomeItem = new QTableWidgetItem(candidato.cognome);
        QTableWidgetItem* dataNascitaItem = new QTableWidgetItem(candidato.data_di_nascita);
        QTableWidgetItem* genereItem = new QTableWidgetItem(candidato.genere);
        QTableWidgetItem* occupazioneItem = new QTableWidgetItem(candidato.occupazione);
        QLineEdit *lineEdit = new QLineEdit();
        QIntValidator *intValidator = new QIntValidator();
        lineEdit->setValidator(intValidator);
        lineEdit ->insert(candidato.idoneita);
        lineEdits.append(lineEdit);

        ui -> tableWidget -> setItem(i, 0, nomeItem);
        ui -> tableWidget -> setItem(i, 1, cognomeItem);
        ui -> tableWidget -> setItem(i, 2, dataNascitaItem);
        ui -> tableWidget -> setItem(i, 3, genereItem);
        ui -> tableWidget -> setItem(i, 4, occupazioneItem);
        ui->tableWidget->setCellWidget(i,5, lineEdit);


    }

    if(ui -> tableWidget -> rowCount() == 0){
        ui -> rimuovi_btn -> setDisabled(1);
        ui -> modifica_btn -> setDisabled(1);
    }

}



// Si attiva alla pressione del bottone "Nuovo candidato" e crea un form "Aggiungi_candidato"
// dove poter creare il nuovo candidato da aggiungere alla lista "candidati".
// La connect viene attivata una volta chiuso il form per l'aggiornamento della tabella.
void ManagerCandidati::on_nuovoCandidato_btn_clicked()
{

    Aggiungi_candidato *aggiungi = new Aggiungi_candidato(this);
    aggiungi->setWindowTitle("Nuovo Candidato");
    aggiungi->show();

    connect(aggiungi, SIGNAL (add_signal(Candidato)), this, SLOT(add_slot(Candidato)));

}

// Aggiunge il candidato creato dal form "Aggiungi_candidato" ed aggiorna la tabella.
void ManagerCandidati::add_slot(Candidato cd)
{
    candidati.append(cd);
    createTable();
}

// Aggiorna la tabella dopo la modifica di un candidato
void ManagerCandidati::modifica_slot(){
    createTable();
}


// Si attiva al click del bottone "Carica_file" ed apre il file explorer per ottenere
// il path del file *.csv da cui aggiungere i candidati.
void ManagerCandidati::on_caricaFile_btn_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this, tr("Open File"), "/", tr("CSV Files (*.csv)"));
    add_from_file(dir);

}

// Si attiva alla pressione del bottone "Rimuovi", se la condizione è soddisfatta elimina il candidato dalla lista e chiama createTable()
void ManagerCandidati::on_rimuovi_btn_clicked()
{
    if(currRow <= ui->tableWidget->rowCount()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,"Rimuovi Candidato", "Vuoi rimuovere questo candidato?", QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes){
            ui->tableWidget->removeRow(currRow);
            candidati.removeAt(currRow);
            lineEdits.removeAt(currRow);
            currRow = 0;
            if(ui -> tableWidget -> rowCount() == 0){
                    ui -> rimuovi_btn -> setDisabled(1);
                    ui -> modifica_btn -> setDisabled(1);
            }
        }
    }

    if(currRow >= ui->tableWidget->rowCount()){
        currRow = 0;
        ui->modifica_btn->setDisabled(1);
    }

}

// Si attiva al click del bottone "Modifica", crea un form DialogModifica
// dove inserire i dati del candidato da modificare.
//Alla chiusura del form aggiorna la tabella.
void ManagerCandidati::on_modifica_btn_clicked()
{
    Candidato &cd = candidati[currRow];
    DialogModifica *dialog = new DialogModifica(&cd, this);
    dialog->setWindowTitle("Modifica candidato");
    dialog->show();
    connect(dialog, SIGNAL(modifica_signal()), this, SLOT(modifica_slot()));

}

// Si attiva al click su una qualsiasi cella della tabella, serve ad identificare
// il candidato da modificare/rimuovere
void ManagerCandidati::on_tableWidget_cellClicked(int row, int)
{
    currRow = row;
    ui -> rimuovi_btn -> setEnabled(1);
    ui -> modifica_btn -> setEnabled(1);
}

// Salva i dati dei candidati sul file "savefile.csv": alcuni antivirus potrebbero dare
// problemi con i permessi di scrittura, nel caso stampa un errore.
// Struttura file: nome,cognome,data_di_nascita,genere,occupazione,idoneità.
void ManagerCandidati::save_data()
{
    QFile file(savefile);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        for (int i = 0; i < candidati.size(); ++i)
        {
            const Candidato& candidato = candidati.at(i);
            stream << candidato.nome << "," << candidato.cognome << "," << candidato.data_di_nascita << ","
                   << candidato.genere << "," << candidato.occupazione << "," << lineEdits.at(i)->text();
            stream << Qt::endl;
            stream.flush();
        }
        file.close();
        qDebug() << "Dati salvati correttamente su file.";
    }
    else
    {
        qDebug() << "Impossibile aprire il file per la scrittura: " << file.errorString();
    }
}

// Si attiva alla chisura del programma, chiama save_data() per salvare i dati su file.
void ManagerCandidati::closeEvent(QCloseEvent *event){
    save_data();
    QMainWindow::closeEvent(event);

}

// Si attiva al click del bottone "Mostra grafici", prepara le mappe per la creazione dei grafi
// ed infine chiama la creazione di ogni grafico.
void ManagerCandidati::on_grafico_btn_clicked(){

    QMap<QString, unsigned int> genereMap;
    QMap<unsigned int, unsigned int> etaMap;
    QMap<QString, unsigned int> occupazioneMap;


    //Inserisce i dati nelle mappe corrispondenti
    for(int i = 0; i < candidati.size(); ++i){
        Candidato &cd = candidati[i];

        QDate dataNascita = QDate::fromString(cd.data_di_nascita, "dd/MM/yyyy");
        QDate dataCorrente = QDate::currentDate();
        int eta = dataNascita.daysTo(dataCorrente) / 365;

        if(!genereMap.contains(cd.genere)){
            genereMap.insert(cd.genere, 1);
        } else {
            ++genereMap[cd.genere];
        }

        if(!etaMap.contains(eta)){
            etaMap.insert(eta, 1);
        } else {
            ++etaMap[eta];
        }

        if(!occupazioneMap.contains(cd.occupazione)){
            occupazioneMap.insert(cd.occupazione, 1);
        } else {
            ++occupazioneMap[cd.occupazione];
        }
    }

    //Prepara i dati delle eta per scaglioni
    QMap<QString, unsigned int> etaMap2;
    etaMap2.insert("Minorenne",0);
    etaMap2.insert("18-25",0);
    etaMap2.insert("26-35",0);
    etaMap2.insert("36-54",0);
    etaMap2.insert(">54",0);
    QMap<unsigned int, unsigned int>::Iterator it,ite;
    it = etaMap.begin();
    ite = etaMap.end();
    for(; it!=ite; ++it){
        if (it.key() <= 17) {
            //In origine era "<18", ma non mostra la label (bug?)
            etaMap2["Minorenne"] += it.value();
        } else if (it.key() >= 18 && it.key() <= 25) {
            etaMap2["18-25"] += it.value();
        } else if (it.key() >= 26 && it.key() <= 35) {
            etaMap2["26-35"] += it.value();
        } else if (it.key() >= 36 && it.key() <= 54) {
            etaMap2["36-54"] += it.value();
        } else {
            etaMap2[">54"] += it.value();
        }
    }
    //Chiama le funzioni per la creazione dei grafici
    genereChart(genereMap);
    occupazioneChart(occupazioneMap);
    etaChart(etaMap2);
}

// Crea il grafico a torta per genere
void ManagerCandidati::genereChart(QMap<QString, unsigned int> &map){
    QMap<QString, unsigned int>::Iterator it,ite;
    it = map.begin();
    ite = map.end();
    QtCharts::QPieSeries *pieSeries = new QtCharts::QPieSeries();
    it = map.begin();
    ite = map.end();

    for (; it != ite; ++it) {
        QString genere = it.key();
        unsigned int valore = it.value();

        pieSeries->append(genere, valore);
    }

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(pieSeries);
    chart->setTitle("Distribuzione per genere");
    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing); // Esempio di animazione sul primo slice


    QMainWindow *window = new QMainWindow();
    QVBoxLayout *verticalLayout = new QVBoxLayout(window->centralWidget());
    verticalLayout->addWidget(chartView);

    window->resize(900,600);
    chartView->resize(900,600);

    chartView->show();


}

// Crea l'istogramma per occupaizone
void ManagerCandidati::occupazioneChart(QMap<QString, unsigned int> &map){
    QMap<QString, unsigned int>::Iterator it,ite;
    QtCharts::QBarSeries *barSeries = new QtCharts::QBarSeries();
    barSeries->setBarWidth(0.5);
    it = map.begin();
    ite = map.end();
    for(; it != ite; ++it){
        QString genere = it.key();
        unsigned int valore = it.value();

        QtCharts::QBarSet *barSet = new QtCharts::QBarSet(genere);
        *barSet << valore;
        barSeries->append(barSet);
    }

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart -> setTitle("Distribuzione per occupazione:");
    chart -> addSeries(barSeries);

    QtCharts::QBarCategoryAxis *axisX = new QtCharts::QBarCategoryAxis();
    axisX->append("   ");
    chart->setAxisX(axisX, barSeries);

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
    axisY->setTickCount(5);
    axisY->setLabelFormat("%d");
    chart->setAxisY(axisY, barSeries);

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow *window = new QMainWindow();
    QVBoxLayout *verticalLayout = new QVBoxLayout(window->centralWidget());
    verticalLayout->addWidget(chartView);

    window->resize(900,600);
    chartView->resize(900,600);

    chartView->show();
}

// Crea il grafico a torta per età
void ManagerCandidati::etaChart(QMap<QString, unsigned int> &map){

    QMap<QString, unsigned int>::Iterator it,ite;
    it = map.begin();
    ite = map.end();
    QtCharts::QPieSeries *pieSeries = new QtCharts::QPieSeries();
    int cnt = 0;

    for (; it != ite; ++it) {
        QString eta = it.key();
        unsigned int valore = it.value();
        ++cnt;

        pieSeries->append(eta, valore);
    }

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(pieSeries);
    chart->setTitle("Distribuzione per età");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    QMainWindow *window = new QMainWindow();
    QVBoxLayout *verticalLayout = new QVBoxLayout(window->centralWidget());
    verticalLayout->addWidget(chartView);

    window->resize(900,600);
    chartView->resize(900,600);

    chartView->show();

}
