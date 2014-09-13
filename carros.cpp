#include "carros.h"
#include "llenado.h"
#include <QString>
#include  <QVector>
Carros::Carros(){
}

Carros::Carros(int cilindraje, QString placa, QString marca, QString fecha)
{
    this->cilindraje=cilindraje;
    this->placa =placa;
    this->marca = marca;
    this->fecha = fecha;
}
void Carros::setcilindraje(int cilindraje){
     this->cilindraje=cilindraje;
}
void  Carros::setLista(llenado  &obj){
       this->lista.push_back(obj);
}

void Carros::setplaca(QString placa){
this->placa =placa;
}

void Carros::setmarca(QString marca){
 this->marca = marca;
}

int Carros::getcilindraje(){
return this->cilindraje;
}

QString Carros::getplaca(){
return placa;
}

QString Carros::getmarca(){
return marca;
}
QString Carros::getfecha(){
    return fecha;
}
 QVector<llenado> Carros::getLista(){
  return lista;
 }
