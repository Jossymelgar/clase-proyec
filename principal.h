#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

namespace Ui {
class principal;
}

class principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit principal(QWidget *parent = 0);
    ~principal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::principal *ui;
};

#endif // PRINCIPAL_H
