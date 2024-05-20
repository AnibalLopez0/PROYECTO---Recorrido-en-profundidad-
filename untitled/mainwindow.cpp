#include "mainwindow.h"
#include <vector>
#include "stdio.h"
#include "ui_mainwindow.h"
#include "neuron.h"
#include "QPlainTextEdit"
#include "QSpinBox"
#include "QFile"
#include "QTextStream"
#include "QFileDialog"
#include "QLCDNumber"
#include <QLineEdit>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QBrush>
#include <QColor>
#include <QGraphicsEllipseItem>
#include <QGraphicsSimpleTextItem>


AdministradorNeuronas administrador;


//Neurona neurona1(ID, VOL, X, Y, R, G, B);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->progressBar->setValue(administrador.numeroDeNeuronas());
    ui->lineEdit->setPlaceholderText("Aqui va el ID");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BuscarNeurona()
{

}

void MainWindow::on_pushButton_2_clicked()//mostrar
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->insertPlainText(administrador.obtenerInformacion());
    ui->lcdNumber->display(administrador.numeroDeNeuronas());
    ui->progressBar->setValue(administrador.numeroDeNeuronas());
}


void MainWindow::on_plainTextEdit_modificationChanged(bool arg1)//muestra caja
{
    ui->plainTextEdit->setReadOnly(true);
}


void MainWindow::on_pushButton_clicked()//añadir inicio
{
    int ID;
    float VOL;
    int X, Y;
    int R, G, B;
    ID = ui->spinBox->value();
    VOL = ui->doubleSpinBox->value();
    X = ui->spinBox_2->value();
    Y = ui->spinBox_3->value();
    R = ui->spinBox_4->value();
    G = ui->spinBox_5->value();
    B = ui->spinBox_6->value();
    Neurona n(ID, VOL, X, Y, R, G, B);
    administrador.agregarInicio(n);
    ui->progressBar->setValue(administrador.numeroDeNeuronas());

}


void MainWindow::on_pushButton_3_clicked()//añadir final
{
    //administrador.agregarFinal(neurona1);
    int ID;
    float VOL;
    int X, Y;
    int R, G, B;
    ID = ui->spinBox->value();
    VOL = ui->doubleSpinBox->value();
    X = ui->spinBox_2->value();
    Y = ui->spinBox_3->value();
    R = ui->spinBox_4->value();
    G = ui->spinBox_5->value();
    B = ui->spinBox_6->value();
    Neurona n(ID, VOL, X, Y, R, G, B);
    administrador.agregarFinal(n);
    ui->progressBar->setValue(administrador.numeroDeNeuronas());
}


void MainWindow::on_spinBox_valueChanged(int arg1)//no borrar, no sabes que pasa
{

}


void MainWindow::on_actionAbrir_archivo_triggered()//abrir
{
    // Obtener el nombre del archivo seleccionado
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Abrir archivo", "", "Archivos de texto (*.txt)");

    if (!fileName.isEmpty()) {
        // Intentar abrir el archivo
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {

            // Crear un QTextStream para leer del archivo
            QTextStream in(&file);

            // Leer el contenido del archivo línea por línea
            while (!in.atEnd()) {
                // Leer una línea del archivo
                QString line = in.readLine();

                // Separar las neuronas utilizando el separador "/"
                QStringList neuronas = line.split("/");

                // Procesar cada neurona
                for (const QString& neuronaStr : neuronas) {
                    // Separar los valores de la neurona utilizando el separador "|"
                    QStringList valores = neuronaStr.split("|");

                    // Verificar si la neurona tiene la cantidad esperada de valores
                    if (valores.size() == 7) {
                        int id = valores[0].toInt();
                        float voltaje = valores[1].toFloat();
                        int posX = valores[2].toInt();
                        int posY = valores[3].toInt();
                        int red = valores[4].toInt();
                        int green = valores[5].toInt();
                        int blue = valores[6].toInt();

                        // Crear una neurona con los datos obtenidos y agregarla al administrador
                        Neurona neurona(id, voltaje, posX, posY, red, green, blue);
                        administrador.agregarFinal(neurona);
                    }
                }
            }

            // Cerrar el archivo después de leerlo
            file.close();

            // Aquí puedes utilizar el administrador de neuronas para realizar alguna acción,
            // como mostrar las neuronas en un QPlainTextEdit o hacer cualquier otra cosa que necesites.
        } else {
            // Mostrar un mensaje de error si no se pudo abrir el archivo
            qDebug() << "Error: no se pudo abrir el archivo para leer";
        }
    }
    ui->progressBar->setValue(administrador.numeroDeNeuronas());
    ui->lcdNumber->display(administrador.numeroDeNeuronas());


}




void MainWindow::on_actionGuardar_2_triggered()//guardar
{
    QString rutaArchivo = QFileDialog::getSaveFileName(this, "Guardar archivo", "", "Archivos de texto (*.txt)");

    // Verificar si el usuario canceló la selección del archivo
    if (rutaArchivo.isEmpty()) {
        return; // Salir sin hacer nada
    }

    // Crear un objeto QFile para el archivo seleccionado
    QFile archivo(rutaArchivo);

    // Intentar abrir el archivo en modo de escritura
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Crear un objeto QTextStream para escribir en el archivo
        QTextStream out(&archivo);

        // Escribir la información en el archivo
        out << administrador.archivoSeparado();

        // Cerrar el archivo
        archivo.close();
    } else {
        // Mostrar un mensaje de error si no se pudo abrir el archivo
        qDebug() << "Error: no se pudo abrir el archivo para escribir";
    }

}

Neurona* buscarNeuronaPorID(int idBuscado, const std::list<Neurona>& listaNeuronas) {
    // Iterar sobre la lista de neuronas
    for (const Neurona& neurona : listaNeuronas) {
        // Comparar el ID de la neurona con el ID buscado
        if (neurona.Id() == idBuscado) {
            // Si se encuentra la neurona, devolver un puntero a ella
            return const_cast<Neurona*>(&neurona); // Usamos const_cast para eliminar la constante de la neurona
        }
    }
    // Si no se encuentra la neurona, devolver un puntero nulo
    return nullptr;
}


void MainWindow::on_pushButton_4_clicked()//buscar
{
    QString ayd = ui->lineEdit->text();
    int AYDI = ayd.toInt();
    ui->tableWidget->clear();

    Neurona *N = administrador.buscarNeuronaPorID(AYDI);
    if (N != nullptr) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        //variables
        int id = N->Id();
        float Vol = N->Voltaje();
        int X = N->PosicionX();
        int Y = N->PosicionY();
        int R = N->Red();
        int G = N->Green();
        int B = N->Blue();



        // Insertar los valores de la neurona en las celdas de la fila
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(id))); // ID
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(Vol))); // Voltaje
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(X))); // Posición X
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(Y))); // Posición Y
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(R))); // Componente Red
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(G))); // Componente Green
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(B))); // Componente Blue
    } else {
        qDebug() << "Neurona no encontrada con el ID" << AYDI;
        QString error;
        error += "No se encontro la neurona con el ID: " + ayd;
        QMessageBox::critical(this, "Error 404", error);

    }
}


void MainWindow::on_pushButton_5_clicked()//dibujar
{
    // Obtener la escena del QGraphicsView
    QGraphicsScene* scene = ui->graphicsView->scene();
    if (!scene) {
        scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);
    } else {
        scene->clear(); // Limpiar la escena antes de dibujar nuevas neuronas y líneas
    }

    // Iterar sobre las neuronas en el administrador
    for (auto it = administrador.begin(); it != administrador.end(); ++it) {
        Neurona& neuronaActual = *it;

        // Crear un círculo para representar la neurona actual
        qreal radio = neuronaActual.Voltaje() / 2.0; // El voltaje determina el tamaño del círculo
        qreal x = neuronaActual.PosicionX() - radio;
        qreal y = neuronaActual.PosicionY() - radio;
        qreal diametro = radio * 2;
        QString id = QString::number(neuronaActual.Id());

        // Crear un rectángulo que represente el círculo y el numero
        QGraphicsEllipseItem* circulo = new QGraphicsEllipseItem(x, y, diametro, diametro);
        QGraphicsSimpleTextItem* numero = new QGraphicsSimpleTextItem(id);

        //Poner el numero en la posicion
        QRectF br = numero ->boundingRect();
        numero->setPos(x+10, y+10);

        // Establecer el color del círculo
        QColor color(neuronaActual.Red(), neuronaActual.Green(), neuronaActual.Blue());
        circulo->setBrush(color);

        // Agregar el círculo a la escena
        scene->addItem(circulo);
        scene->addItem(numero);

        // Buscar la neurona más cercana a la neurona actual
        Neurona* neuronaMasCercana = nullptr;
        qreal distanciaMinima = std::numeric_limits<qreal>::max();
        for (auto it2 = administrador.begin(); it2 != administrador.end(); ++it2) {
            if (&(*it) != &(*it2)) { // Evitar comparar la neurona actual consigo misma
                Neurona& neuronaCandidata = *it2;
                qreal distancia = std::sqrt(std::pow(neuronaActual.PosicionX() - neuronaCandidata.PosicionX(), 2) +
                                            std::pow(neuronaActual.PosicionY() - neuronaCandidata.PosicionY(), 2));
                if (distancia < distanciaMinima) {
                    distanciaMinima = distancia;
                    neuronaMasCercana = &neuronaCandidata;
                }
            }
        }

        /*if (neuronaMasCercana) {
            //matrizAdyacencia[neuronaActual.Id()][neuronaMasCercana->Id()] = true;
            matrizCuadrada.insertarDato(neuronaActual.Id(), neuronaMasCercana->Id(), 0);
        }*/

        // Dibujar una línea que conecte la neurona actual con la neurona más cercana
        if (neuronaMasCercana) {
            QGraphicsLineItem* linea = new QGraphicsLineItem(x + radio, y + radio,
                                                             neuronaMasCercana->PosicionX(), neuronaMasCercana->PosicionY());
            QString cerca = QString::number(distanciaMinima);
            QGraphicsSimpleTextItem* peso = new QGraphicsSimpleTextItem(cerca);
            peso->setPos(x+ radio, y+radio);
            scene->addItem(linea);
            scene->addItem(peso);
        }
    }

    // Actualizar la vista
    ui->graphicsView->update();
}


void MainWindow::on_pushButton_6_clicked()//ordenar por id
{
    administrador.ordenarPorIDAscendente();
}


void MainWindow::on_pushButton_7_clicked()//ordenar por voltaje
{
    administrador.ordenarPorVoltaje();
}


void MainWindow::on_pushButton_8_clicked()//imprimir matriz de adyacencia
{

    MatrizCuadrada matriz(administrador.numeroDeNeuronas());
    // Iterar sobre las neuronas en el administrador
    for (auto it = administrador.begin(); it != administrador.end(); ++it) {
        Neurona& neuronaActual = *it;


        // Buscar la neurona más cercana a la neurona actual
        Neurona* neuronaMasCercana = nullptr;
        qreal distanciaMinima = std::numeric_limits<qreal>::max();
        for (auto it2 = administrador.begin(); it2 != administrador.end(); ++it2) {
            if (&(*it) != &(*it2)) { // Evitar comparar la neurona actual consigo misma
                Neurona& neuronaCandidata = *it2;
                qreal distancia = std::sqrt(std::pow(neuronaActual.PosicionX() - neuronaCandidata.PosicionX(), 2) +
                                            std::pow(neuronaActual.PosicionY() - neuronaCandidata.PosicionY(), 2));
                if (distancia < distanciaMinima) {
                    distanciaMinima = distancia;
                    neuronaMasCercana = &neuronaCandidata;
                }
            }
        }

        if (neuronaMasCercana) {
            //matrizAdyacencia[neuronaActual.Id()][neuronaMasCercana->Id()] = true;
            matriz.insertarDato(neuronaActual.Id(),neuronaMasCercana->Id(), 1);
        }

    }

    ui->plainTextEdit_2->clear();
    ui->plainTextEdit_2->setPlainText(matriz.imprimir());

}




void MainWindow::on_pushButton_9_clicked()//profundidad
{
    MatrizCuadrada matriz(administrador.numeroDeNeuronas());
    QVector<Neurona*> neuronas; // Para almacenar punteros a neuronas por índice

    // Iterar sobre las neuronas en el administrador y almacenarlas en el vector
    for (auto it = administrador.begin(); it != administrador.end(); ++it) {
        neuronas.push_back(&(*it));
    }

    // Rellenar la matriz de adyacencia con las distancias mínimas
    for (int i = 0; i < neuronas.size(); ++i) {
        Neurona& neuronaActual = *neuronas[i];
        Neurona* neuronaMasCercana = nullptr;
        qreal distanciaMinima = std::numeric_limits<qreal>::max();

        for (int j = 0; j < neuronas.size(); ++j) {
            if (i != j) { // Evitar comparar la neurona actual consigo misma
                Neurona& neuronaCandidata = *neuronas[j];
                qreal distancia = std::sqrt(std::pow(neuronaActual.PosicionX() - neuronaCandidata.PosicionX(), 2) +
                                            std::pow(neuronaActual.PosicionY() - neuronaCandidata.PosicionY(), 2));
                if (distancia < distanciaMinima) {
                    distanciaMinima = distancia;
                    neuronaMasCercana = &neuronaCandidata;
                }
            }
        }

        if (neuronaMasCercana) {
            int idxMasCercana = std::distance(neuronas.begin(), std::find(neuronas.begin(), neuronas.end(), neuronaMasCercana));
            matriz.insertarDato(i, idxMasCercana, 1);
        }
    }

    ui->plainTextEdit_2->clear();
    Neurona* inicio = administrador.obtenerPrimeraNeurona();
    if (inicio) {
        int primera = std::distance(neuronas.begin(), std::find(neuronas.begin(), neuronas.end(), inicio));
        ui->plainTextEdit_2->setPlainText(matriz.buscarProfundidad(primera));
    } else {
        ui->plainTextEdit_2->setPlainText("No hay neuronas en la lista.");
    }
}


void MainWindow::on_pushButton_10_clicked()//amplitud
{
    MatrizCuadrada matriz(administrador.numeroDeNeuronas());
    QVector<Neurona*> neuronas; // Para almacenar punteros a neuronas por índice

    // Iterar sobre las neuronas en el administrador y almacenarlas en el vector
    for (auto it = administrador.begin(); it != administrador.end(); ++it) {
        neuronas.push_back(&(*it));
    }

    // Rellenar la matriz de adyacencia con las distancias mínimas
    for (int i = 0; i < neuronas.size(); ++i) {
        Neurona& neuronaActual = *neuronas[i];
        Neurona* neuronaMasCercana = nullptr;
        qreal distanciaMinima = std::numeric_limits<qreal>::max();

        for (int j = 0; j < neuronas.size(); ++j) {
            if (i != j) { // Evitar comparar la neurona actual consigo misma
                Neurona& neuronaCandidata = *neuronas[j];
                qreal distancia = std::sqrt(std::pow(neuronaActual.PosicionX() - neuronaCandidata.PosicionX(), 2) +
                                            std::pow(neuronaActual.PosicionY() - neuronaCandidata.PosicionY(), 2));
                if (distancia < distanciaMinima) {
                    distanciaMinima = distancia;
                    neuronaMasCercana = &neuronaCandidata;
                }
            }
        }

        if (neuronaMasCercana) {
            int idxMasCercana = std::distance(neuronas.begin(), std::find(neuronas.begin(), neuronas.end(), neuronaMasCercana));
            matriz.insertarDato(i, idxMasCercana, 1);
        }
    }

    ui->plainTextEdit_2->clear();
    Neurona* inicio = administrador.obtenerPrimeraNeurona();
    if (inicio) {
        int primera = std::distance(neuronas.begin(), std::find(neuronas.begin(), neuronas.end(), inicio));
        ui->plainTextEdit_2->setPlainText(matriz.buscarAmplitud(primera));
    } else {
        ui->plainTextEdit_2->setPlainText("No hay neuronas en la lista.");
    }
}

