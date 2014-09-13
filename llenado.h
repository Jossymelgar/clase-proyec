#ifndef LLENADO_H
#define LLENADO_H
#include <QString>
#include <QVector>
class llenado
{
   QString fecha;
   double lempiras;
   double litros;
   double kilometros;
public:
    llenado();
    llenado(QString fecha, int lempiras, int litros, int kilometros);
    QString getfecha();
    double getlempiras();
    double getlitros();
    double getkilometros();
};

#endif // LLENADO_H
