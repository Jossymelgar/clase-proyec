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

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_13_clicked();



    void on_combo_activated(int index);

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_combo_2_activated(int index);

    void on_combo_2_activated(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::principal *ui;
};

#endif // PRINCIPAL_H
