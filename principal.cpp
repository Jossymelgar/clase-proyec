#include "principal.h"
#include <iostream>
#include <stdio.h>
#include <QFile>
#include <fstream>
#include <QDataStream>
#include <QDebug>
#include <QFileSystemModel>
#include "ui_principal.h"
#include "carros.h"
#include  <QVector>
#include <QString>
#include <vector>
#include <QMessageBox>
#include <QDate>
#include <QTextStream>
#include "llenado.h"
#include "QList"
QVector <Carros*> lista;
int posicion;
principal::principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principal)
{
    ui->setupUi(this);

}

principal::~principal()
{
    delete ui;
}

void principal::on_pushButton_clicked()
{

  Carros* car = new   Carros(1,ui->placa->text(),ui->marca->text(),"fechas");

  lista.push_back(car);
  /*  QFile archivo("/home/jossy/hola mundo.dat");
    archivo.open(QIODevice::WriteOnly);
    QDataStream out(&archivo);
    out << QString("hola munda");
    out << (qint32)41;
    archivo.close();
    */
   QMessageBox::about(this,"Control de LLenado",ui->placa->text());

  ui->placa->setText("");
}
void principal::on_pushButton_3_clicked(){
    double k=0,l=0,lp=0;
    int posi;
     for(int y=0;y<lista.size();y++){
        if(ui->txtbuscart->text()==lista[y]->getplaca()){
           QString cadena;
           cadena="Marca:  "+lista[y]->getmarca()+" Placa:  "+lista[y]->getplaca()+" Cilindraje:   "+QString::number(lista[y]->getcilindraje())+" Fecha"+lista[y]->getfecha();
           ui->textEdit->append(cadena);
           int tamano =lista[y]->getLista().length();
           posi=y;
           for(int u=0;u<tamano;u++){
             k +=lista[y]->getLista()[u].getkilometros();
             l +=lista[y]->getLista()[u].getlitros();
             lp +=lista[y]->getLista()[u].getlempiras();
             QString gasolina;
             gasolina= "Fecha: "+lista[y]->getLista()[u].getfecha()+" Lempiras: "+QString::number(lista[y]->getLista()[u].getlempiras())+" Litros: "+QString::number(lista[y]->getLista()[u].getlitros())+" Kilometros: "+QString::number(lista[y]->getLista()[u].getkilometros());
              ui->detalles->append(gasolina);
            }
          }else{

        }
     }
     ui->porl->setText(QString::number(k/l));
     ui->pork->setText(QString::number(lp/k));
     ui->porlt->setText(QString::number(lp/lista[posi]->getLista().size()));
     ui->tlp->setText(QString::number(lp));
     ui->tl->setText(QString::number(l));
     ui->tk->setText(QString::number(k));
}
void principal::on_pushButton_6_clicked()
{
    for(int y=0;y<lista.size();y++){
       if(ui->txtbusca->text()==lista[y]->getplaca()){
              ::posicion=y;
       }else{
       }
    }
if(::posicion>0){
    QMessageBox::about(this,"Si existe el Carro con placa: ",ui->txtbusca->text());
}
}

void principal::on_pushButton_7_clicked(){
    QFile archivo("/home/jossy/hola mundo.dat");
    archivo.open(QIODevice::WriteOnly);
    QDataStream in(&archivo);
    QString str;
    qint32 a;
    in >> str >> a;
}

void principal::on_pushButton_5_clicked()
{
 llenado n (ui->fechag->text(),ui->txtlempira->text().toInt(0,10),ui->txtlitro->text().toInt(0,10),ui->txtkilometro->text().toInt(0,10));
 lista[::posicion]->setLista(n);
 QMessageBox::about(this,"Se Cargo Gasolina al  Carro con placa: ",ui->txtbusca->text());

}

void principal::on_pushButton_4_clicked()
{
    ui->detalles->setText("");
}

void principal::on_pushButton_10_clicked()
{
    for(int y=0;y<lista.size();y++){
       if(ui->busca->text()==lista[y]->getplaca()){
              ::posicion=y;
       }else{
       }
    }
    if(::posicion>=0){
      QMessageBox::about(this,"Si existe el Carro con placa: ",ui->txtbusca->text());
      /*ui->marca_2->setText(lista[posicion]->getmarca());
      ui->placa_2->setText(lista[posicion]->getplaca());
      ui->cilindraje_2->setText(lista[posicion]->getcilindraje());
*/
}
}
