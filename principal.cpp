#include "principal.h"
#include <iostream>
#include <QDebug>
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
#include<QList>
#include "llenado.h"
#include "QList"
QVector <Carros*> lista;
int posicion;
principal::principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principal)
{
    ui->setupUi(this);
    QFile  archivo("/home/jossy/proyecto/base09.txt");
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream escribir(&archivo);
    QString line;
     while (!escribir.atEnd()){
             line = escribir.readLine();
             qDebug() << "linea: "<<line;
             QRegExp rx(",");
             QStringList query = line.split(rx);
             Carros* car = new   Carros(query[2].toInt(0,10),query[0],query[1],"");
             lista.push_back(car);
        }

     QFile  archivo1("/home/jossy/proyecto/llenados.txt");
     archivo1.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream escribir1(&archivo1);
     QString line1;
     while (!escribir1.atEnd()){
             line1 = escribir1.readLine();
             QRegExp rx1(":");
             QStringList query1 = line1.split(rx1);
             for(int q=0;q<lista.size();q++){
                if(lista[q]->getplaca()==query1[0]){
                     for(int o=0;o<query1.size();o++){
                          if(o>0){
                              QRegExp rx2(",");
                               QStringList query2 = query1[o].split(rx2);
                              qDebug() << "sub listas"<<query2;
                              llenado n (query2[0],query2[1].toDouble(0),query2[2].toDouble(0),query2[3].toDouble(0));
                              lista[q]->setLista(n);
                  }
              }
              }
             }
     }


}

principal::~principal()
{
    delete ui;
}

void principal::on_pushButton_clicked()
{
bool Existe=false;

for(int i=0; i<lista.size();i++){
    if(ui->placa->text()==lista[i]->getplaca()){
        Existe=true;
    }
}

if(Existe==true){
      QMessageBox::about(this,"Control de Seguridad","Ya Existe Ese Numero de Placa");
}else{
if(ui->placa->text()=="" || ui->marca->text()==""){
    QMessageBox::about(this,"Control de Seguridad","No debe dejar atributos vacios");
}else{
  Carros* car = new   Carros(ui->cilin->value(),ui->placa->text(),ui->marca->text(),"");
  lista.push_back(car);
  QFile  archivo1("/home/jossy/proyecto/llenados.txt");
  archivo1.open(QIODevice::WriteOnly | QIODevice::Truncate);
  QFile  archivo("/home/jossy/proyecto/base09.txt");
  archivo.open(QIODevice::WriteOnly | QIODevice::Truncate); //
  QTextStream escribir(&archivo);
  QTextStream escribir1(&archivo1);
  for(int i=0; i<lista.size();i++){
     QString txt= lista[i]->getplaca()+","+lista[i]->getmarca()+","+QString::number(lista[i]->getcilindraje());
        escribir << txt <<endl;
        QString subtxt =lista[i]->getplaca();
        for(int r=0; r<lista[i]->getLista().size();r++){
            subtxt +=lista[i]->getLista()[r].toString();

   }
   escribir1 << subtxt <<endl;

 }

archivo.close();
archivo1.close();
QMessageBox::about(this,"Control","Guardado con exito");


  ui->placa->setText("");
  ui->marca->setText("");
  ui->cilin->setValue(2);
}
}
}
void principal::on_pushButton_3_clicked(){
    ui->textEdit->setText("");
    ui->detalles->setText("");
    if(ui->txtbuscart->text()=="" ){
    QMessageBox::about(this,"Control","Ingrese numero de placa porfavor");
    }else{
    double k=0,l=0,lp=0;
    bool tiene_sublista=false;
    int posi;
     for(int y=0;y<lista.size();y++){
        if(ui->txtbuscart->text()==lista[y]->getplaca()){
           QString cadena;
           cadena="Marca:  "+lista[y]->getmarca()+" Placa:  "+lista[y]->getplaca()+" Cilindraje:   "+QString::number(lista[y]->getcilindraje());
           ui->textEdit->append(cadena);
           int tamano =lista[y]->getLista().length();
           posi=y;
           for(int u=0;u<tamano;u++){
             k +=lista[y]->getLista()[u].getkilometros();
             l +=lista[y]->getLista()[u].getlitros();
             lp +=lista[y]->getLista()[u].getlempiras();
             QString gasolina;
                tiene_sublista= true;
             gasolina= "Fecha: "+lista[y]->getLista()[u].getfecha()+" Lempiras: "+QString::number(lista[y]->getLista()[u].getlempiras())+" Litros: "+QString::number(lista[y]->getLista()[u].getlitros())+" Kilometros: "+QString::number(lista[y]->getLista()[u].getkilometros());
              ui->detalles->append(gasolina);
            }
          }else{

        }
     }
     if(tiene_sublista==true){
         double lit=l;
         double galones = (double)lit*(double)0.2642;
     ui->kd->setText(QString::number(k/lista[posi]->getLista().size()));
     ui->porl->setText(QString::number(k/l));
     ui->pork->setText(QString::number(lp/lista[posi]->getLista().size()));
     ui->porlt->setText(QString::number(lp/k));
     ui->tlp->setText(QString::number(lp));
     ui->tl->setText(QString::number(l));
     ui->tk->setText(QString::number(k));

     ui->galon->setText(QString::number((double)k/galones));
     }else{
         QMessageBox::about(this,"Control","Vehiculo sin historial de Combustible");
     }
    }
}
void principal::on_pushButton_6_clicked()
{
 bool entro=false;
 if(ui->txtbusca->text()=="" || ui->txtbusca->text()==" "){
    QMessageBox::about(this,"Control ","Ingrese la placa porfavor");
 }else{
    for(int y=0;y<lista.size();y++){
       if(ui->txtbusca->text()==lista[y]->getplaca()){
              ::posicion=y;
           entro=true;
       }else{
       }
    }
   if(entro==true){
        QMessageBox::about(this,"Control ","Si Existe Vehiculo con placa: "+ui->txtbusca->text());
       ui->pushButton_5->setEnabled(true);
}else{
        QMessageBox::about(this,"Control ","N0 Existe Vehiculo con placa: "+ui->txtbusca->text());
   }
}
}

void principal::on_pushButton_7_clicked(){
    QFile  archivo("/home/jossy/proyecto/base09.txt");
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream escribir(&archivo);
    QString line;
     while (!escribir.atEnd()){
             line = escribir.readLine();
             qDebug() << "linea: "<<line;
             QRegExp rx(",");
             QStringList query = line.split(rx);
             Carros* car = new   Carros(query[2].toInt(0,10),query[0],query[1],"");
             lista.push_back(car);
        }

     QFile  archivo1("/home/jossy/proyecto/llenados.txt");
     archivo1.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream escribir1(&archivo1);
     QString line1;
     while (!escribir1.atEnd()){
             line1 = escribir1.readLine();
             QRegExp rx1(":");
             QStringList query1 = line1.split(rx1);
             for(int q=0;q<lista.size();q++){
                if(lista[q]->getplaca()==query1[0]){
                     for(int o=0;o<query1.size();o++){
                          if(o>0){
                              QRegExp rx2(",");
                               QStringList query2 = query1[o].split(rx2);
                              qDebug() << "sub listas"<<query2;
                              llenado n (query2[0],query2[1].toDouble(0),query2[2].toDouble(0),query2[3].toDouble(0));
                              lista[q]->setLista(n);
                  }
              }
              }
             }
     }







}



void principal::on_pushButton_5_clicked()
{
 llenado n (ui->fechag->text(),ui->splp->value(),ui->splitro->value(),ui->spkilometro->value());
 lista[::posicion]->setLista(n);
 QMessageBox::about(this,"Se Cargo Gasolina al  Carro con placa: ",ui->txtbusca->text());
 QFile  archivo1("/home/jossy/proyecto/llenados.txt");
 archivo1.open(QIODevice::WriteOnly | QIODevice::Truncate);
 QFile  archivo("/home/jossy/proyecto/base09.txt");
 archivo.open(QIODevice::WriteOnly | QIODevice::Truncate); //
 QTextStream escribir(&archivo);
 QTextStream escribir1(&archivo1);
 for(int i=0; i<lista.size();i++){
    QString txt= lista[i]->getplaca()+","+lista[i]->getmarca()+","+QString::number(lista[i]->getcilindraje());
       escribir << txt <<endl;
       QString subtxt =lista[i]->getplaca();
       for(int r=0; r<lista[i]->getLista().size();r++){
           subtxt +=lista[i]->getLista()[r].toString();

  }
  escribir1 << subtxt <<endl;
  ui->pushButton_5->setEnabled(false);

}

archivo.close();
archivo1.close();
QMessageBox::about(this,"Control","Guardado con exito");
ui->txtbusca->setText("");
ui->splp->setValue(0);
ui->splitro->setValue(0);
ui->spkilometro->setValue(0);
}

void principal::on_pushButton_4_clicked()
{
     ui->txtbuscart->setText("");
     ui->textEdit->setText("");
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
    if(ui->marca_2->text()=="" || ui->placa_2->text()==""){
        QMessageBox::about(this,"Control","Ocurrio un Error \n No puede dejar espacios en blacos o Debe seleccionar un Vehiculo");

    }else{
   lista[posicion]->setmarca(ui->marca_2->text());
   lista[posicion]->setplaca(ui->placa_2->text());
   lista[posicion]->setcilindraje(ui->spcilin->value());
   QMessageBox::about(this,"Control  ","::Los combios fueron guardados con exito:::");
   QFile  archivo1("/home/jossy/proyecto/llenados.txt");
   archivo1.open(QIODevice::WriteOnly | QIODevice::Truncate);
   QFile  archivo("/home/jossy/proyecto/base09.txt");
   archivo.open(QIODevice::WriteOnly | QIODevice::Truncate); //
   QTextStream escribir(&archivo);
   QTextStream escribir1(&archivo1);
   for(int i=0; i<lista.size();i++){
      QString txt= lista[i]->getplaca()+","+lista[i]->getmarca()+","+QString::number(lista[i]->getcilindraje());
         escribir << txt <<endl;
         QString subtxt =lista[i]->getplaca();
         for(int r=0; r<lista[i]->getLista().size();r++){
             subtxt +=lista[i]->getLista()[r].toString();

    }
    escribir1 << subtxt <<endl;

  }

 archivo.close();
 archivo1.close();
 QMessageBox::about(this,"Control","Guardado con exito");
   ui->marca_2->setText("");;
   ui->spcilin->setValue(2);
   ui->busca->setText("");
   ui->placa_2->setText("");
    }
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
    if(ui->marca_3->text()=="" || ui->placa_3->text()==""){
        QMessageBox::about(this,"Control","Ocurrio un Error \n No puede dejar espacios en blacos o Debe seleccionar un Vehiculo");
   }else{
    lista[posicion]->setmarca(ui->marca_3->text());
    lista[posicion]->setplaca(ui->placa_3->text());
    lista[posicion]->setcilindraje(ui->spcilin_2->value());
    QMessageBox::about(this,"Comtrol de Cambio","::Los combios fueron guardados con exito:::");
    QFile  archivo1("/home/jossy/proyecto/llenados.txt");
    archivo1.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QFile  archivo("/home/jossy/proyecto/base09.txt");
    archivo.open(QIODevice::WriteOnly | QIODevice::Truncate); //
    QTextStream escribir(&archivo);
    QTextStream escribir1(&archivo1);
    for(int i=0; i<lista.size();i++){
       QString txt= lista[i]->getplaca()+","+lista[i]->getmarca()+","+QString::number(lista[i]->getcilindraje());
          escribir << txt <<endl;
          QString subtxt =lista[i]->getplaca();
          for(int r=0; r<lista[i]->getLista().size();r++){
              subtxt +=lista[i]->getLista()[r].toString();

     }
     escribir1 << subtxt <<endl;

   }

  archivo.close();
  archivo1.close();
  QMessageBox::about(this,"Control","Guardado con exito");
    ui->marca_3->setText("");
    ui->placa_3->setText("");
    ui->spcilin_2->setValue(2);
    ui->combo->clear();
    for(int i=0; i<lista.size();i++){
        ui->combo->addItem(lista[i]->getplaca());
    }
}

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
       QFile  archivo1("/home/jossy/proyecto/llenados.txt");
       archivo1.open(QIODevice::WriteOnly | QIODevice::Truncate);
       QFile  archivo("/home/jossy/proyecto/base09.txt");
       archivo.open(QIODevice::WriteOnly | QIODevice::Truncate); //
       QTextStream escribir(&archivo);
       QTextStream escribir1(&archivo1);
       for(int i=0; i<lista.size();i++){
          QString txt= lista[i]->getplaca()+","+lista[i]->getmarca()+","+QString::number(lista[i]->getcilindraje());
             escribir << txt <<endl;
             QString subtxt =lista[i]->getplaca();
             for(int r=0; r<lista[i]->getLista().size();r++){
                 subtxt +=lista[i]->getLista()[r].toString();

        }
        escribir1 << subtxt <<endl;

      }

     archivo.close();
     archivo1.close();
       ui->combo_2->clear();
       for(int i=0; i<lista.size();i++){
           ui->combo_2->addItem(lista[i]->getplaca());
       }
    } else {
      QMessageBox::about(this,"Control de Eliminacion","Proceso Cancelado");
    }

    ui->detalles_2->setText("");
}

void principal::on_pushButton_8_clicked(){
     QFile  archivo1("/home/jossy/proyecto/llenados.txt");
     archivo1.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QFile  archivo("/home/jossy/proyecto/base09.txt");
    archivo.open(QIODevice::WriteOnly | QIODevice::Truncate); //
    QTextStream escribir(&archivo);
    QTextStream escribir1(&archivo1);
    for(int i=0; i<lista.size();i++){
      QString txt= lista[i]->getplaca()+","+lista[i]->getmarca()+","+QString::number(lista[i]->getcilindraje());
      escribir << txt <<endl;
      QString subtxt =lista[i]->getplaca();
      for(int r=0; r<lista[i]->getLista().size();r++){
          subtxt +=lista[i]->getLista()[r].toString();

      }
      escribir1 << subtxt <<endl;

    }

 archivo.close();
 archivo1.close();
 QMessageBox::about(this,"Control","Grabado con exito");


 }

void principal::on_pushButton_11_clicked()
{

}
