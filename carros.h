#ifndef CARROS_H
#define CARROS_H
#include <QString>
#include <QVector>
#include "llenado.h"
#include <QString>
class Carros
{

private:
    QVector<llenado> lista;
    int cilindraje;
    QString placa;
    QString marca;
    QString fecha;
public:
    Carros();
    Carros(int cilindraje,QString placa, QString marca,QString fecha);
    void setcilindraje(int cilindraje);
    void setplaca(QString placa);
    void setmarca(QString marca);
    int getcilindraje();
    QString getfecha();
    QString getplaca();
    QString getmarca();
    void setLista(llenado& obj);
    QVector<llenado> getLista();
    QString toString()const;

};

#endif // CARROS_H
