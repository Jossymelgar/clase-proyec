#include "llenado.h"
#include <QVector>
#include <QString>
llenado::llenado(QString fecha,int lempiras,int litros,int kilometros)
{
   this->fecha=fecha;
    this->lempiras=lempiras;
    this->litros=litros;
    this->kilometros=kilometros;
}
QString llenado::getfecha(){
    return fecha;
}

int llenado::getlempiras(){
    return lempiras;
}

int llenado::getlitros(){
    return litros;
}

int llenado::getkilometros(){
    return kilometros;
}
 llenado::llenado(){

 }
