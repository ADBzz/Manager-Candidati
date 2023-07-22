#ifndef AGGIUNGI_CANDIDATO_H
#define AGGIUNGI_CANDIDATO_H
#include <managercandidati.h>

#include <QDialog>

namespace Ui {
class Aggiungi_candidato;
}

class Aggiungi_candidato : public QDialog
{
    Q_OBJECT

public:
    explicit Aggiungi_candidato(QWidget *parent = nullptr);
    ~Aggiungi_candidato();

signals:
    void add_signal(Candidato cd);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Aggiungi_candidato *ui;
    friend class ManagerCandidati;



};

#endif // AGGIUNGI_CANDIDATO_H
