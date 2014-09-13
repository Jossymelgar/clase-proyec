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
if(ui->placa->text()=="" || ui->marca->text()==""){
    QMessageBox::about(this,"Control de Seguridad","No debe dejar atributos vacios");
}else{
  Carros* car = new   Carros(ui->cilin->value(),ui->placa->text(),ui->marca->text(),"fechas");

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
      QMessageBox::about(this,"Control: ","Si existe el carro");
      ui->marca_2->setText(lista[posicion]->getmarca());
      ui->placa_2->setText(lista[posicion]->getplaca());
      ui->spcilin->setValue(lista[posicion]->getcilindraje());

}
}

void principal::on_pushButton_9_clicked()
{
  lista[posicion]->setmarca(ui->marca_2->text());
  lista[posicion]->setplaca(ui->placa_2->text());
  lista[posicion]->setcilindraje(ui->spcilin->value());
   QMessageBox::about(this,"Control  ","::Los combios fueron guardados con exito:::");
}

void principal::on_pushButton_13_clicked()
{
    ui->combo->clear();
    for(int i=0; i<lista.size();i++){
        ui->combo->addItem(lista[i]->getplaca());
    }
}



void principal::on_pushButton_12_clicked()
{
    lista[posicion]->setmarca(ui->marca_3->text());
    lista[posicion]->setplaca(ui->placa_3->text());
    lista[posicion]->setcilindraje(ui->spcilin_2->value());
    QMessageBox::about(this,"Comtrol de Cambio","::Los combios fueron guardados con exito:::");
}

void principal::on_combo_activated(int index)
{
    ui->marca_3->setText("");
    ui->placa_3->setText("");
    ui->spcilin_2->setValue(2);
    ui->marca_3->setText(lista[index]->getmarca());
    ui->placa_3->setText(lista[index]->getplaca());
    ui->spcilin_2->setValue(lista[index]->getcilindraje());
    ::posicion=index;

}

void principal::on_pushButton_14_clicked()
{
    ui->combo_2->clear();
    for(int i=0; i<lista.size();i++){
        ui->combo_2->addItem(lista[i]->getplaca());
    }
}

void principal::on_combo_2_activated(int index)
{
    ui->detalles_2->setText("");
    ui->detalles_2->append(lista[index]->toString());
    ::posicion=index;
}

void principal::on_combo_2_activated(const QString &arg1)
{

}

void principal::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton mensaje;
    mensaje = QMessageBox::question(this, "Control de eliminacion", "Seguro de Eliminar",
                                  QMessageBox::Yes|QMessageBox::No);
    if (mensaje == QMessageBox::Yes) {
       lista.erase(lista.begin()+::posicion);
       QMessageBox::about(this,"Control de Eliminacion","Fue eliminado");
       ui->combo_2->clear();
       for(int i=0; i<lista.size();i++){
           ui->combo_2->addItem(lista[i]->getplaca());
       }
    } else {
      QMessageBox::about(this,"Control de Eliminacion","Proceso Cancelado");
    }

    ui->detalles_2->setText("");
}
