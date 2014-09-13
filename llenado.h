#ifndef LLENADO_H
#define LLENADO_H
#include <QString>
#include <QVector>
class llenado
{
   QString fecha;
   int lempiras;
   int litros;
   int kilometros;
public:
    llenado();
    llenado(QString fecha, int lempiras, int litros, int kilometros);
    QString getfecha();
    int getlempiras();
    int getlitros();
    int getkilometros();
};

#endif // LLENADO_H
