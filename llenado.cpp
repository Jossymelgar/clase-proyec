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

double llenado::getlempiras(){
    return lempiras;
}

double llenado::getlitros(){
    return litros;
}

double llenado::getkilometros(){
    return kilometros;
}
 llenado::llenado(){

 }
  QString llenado::toString(){
      QString ss = ":"+getfecha()+","+QString::number(getlempiras())+","+QString::number(getlitros())+","+QString::number(getkilometros());
      return ss;
  }
