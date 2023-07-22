#ifndef DIALOGMODIFICA_H
#define DIALOGMODIFICA_H

#include <QDialog>
#include "managercandidati.h"

namespace Ui {
class DialogModifica;
}

class DialogModifica : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModifica(Candidato *cd, QWidget *parent = nullptr);
    ~DialogModifica();

signals:
    void modifica_signal();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogModifica *ui;
    Candidato* cd;
};

#endif // DIALOGMODIFICA_H
