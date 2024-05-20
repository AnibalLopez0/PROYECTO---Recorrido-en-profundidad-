#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <list>
#include <Qstring>
#include <QGraphicsScene>
#include <QBrush>
#include <QColor>
#include <QStack>
#include <QQueue>
#include <QVector>
#include <QSet>


class MatrizCuadrada {
private:
    int size;
    QVector<QVector<int>> matriz;

public:
    MatrizCuadrada(int size)
        : size(size), matriz(size, QVector<int>(size, 0)) {}

    void insertarDato(int fila, int columna, int valor) {
        if (fila >= 0 && fila < size && columna >= 0 && columna < size) {
            matriz[fila][columna] = valor;
        }
    }

    QString imprimir() const {
        QString resultado;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                resultado += QString::number(matriz[i][j]) + " ";
            }
            resultado += "\n";
        }
        return resultado;
    }

    QString buscarProfundidad(int nodoInicial) const {
        QSet<int> visitados;
        QString resultado;
        dfs(nodoInicial, visitados, resultado);
        return resultado;
    }

    void dfs(int nodo, QSet<int>& visitados, QString& resultado) const {
        QStack<int> pila;
        pila.push(nodo);

        while (!pila.isEmpty()) {
            int nodoActual = pila.pop();

            if (!visitados.contains(nodoActual)) {
                visitados.insert(nodoActual);
                resultado += QString::number(nodoActual) + " ";

                for (int i = size - 1; i >= 0; --i) {
                    if (matriz[nodoActual][i] != 0 && !visitados.contains(i)) {
                        pila.push(i);
                    }
                }
            }
        }
    }

    QString buscarAmplitud(int nodoInicial) const {
        QSet<int> visitados;
        QString resultado;
        bfs(nodoInicial, visitados, resultado);
        return resultado;
    }

    void bfs(int nodo, QSet<int>& visitados, QString& resultado) const {
        QQueue<int> cola;
        cola.enqueue(nodo);

        while (!cola.isEmpty()) {
            int nodoActual = cola.dequeue();

            if (!visitados.contains(nodoActual)) {
                visitados.insert(nodoActual);
                resultado += QString::number(nodoActual) + " ";

                for (int i = 0; i < size; ++i) {
                    if (matriz[nodoActual][i] != 0 && !visitados.contains(i)) {
                        cola.enqueue(i);
                    }
                }
            }
        }
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << matriz[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    QString obtenerInformacion() const {
        QString informacion;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                informacion += QString::number(matriz[i][j]) + " ";
            }
            informacion += "\n";
        }
        return informacion;
    }
};



class Neurona {
private:
    int id;
    float voltaje;
    int posX;
    int posY;
    int red;
    int green;
    int blue;

public:
    Neurona(int _id, float _voltaje, int _posX, int _posY, int _red, int _green, int _blue)
        : id(_id), voltaje(_voltaje), posX(_posX), posY(_posY), red(_red), green(_green), blue(_blue) {}

    int Id() const { return id; }
    float Voltaje() const { return voltaje; }
    int PosicionX() const { return posX; }
    int PosicionY() const { return posY; }
    int Red() const { return red; }
    int Green() const { return green; }
    int Blue() const { return blue; }

    QString obtenerInformacion() const {
        QString informacion;
        informacion += "ID: " + QString::number(id) + "\n";
        informacion += "Voltaje: " + QString::number(voltaje) + "\n";
        informacion += "Posición X: " + QString::number(posX) + "\n";
        informacion += "Posición Y: " + QString::number(posY) + "\n";
        informacion += "Red: " + QString::number(red) + "\n";
        informacion += "Green: " + QString::number(green) + "\n";
        informacion += "Blue: " + QString::number(blue) + "\n";
        return informacion;
    }

    QString InfoArchivo() const {
        QString informacion;
        informacion +=  QString::number(id) + "|";
        informacion +=  QString::number(voltaje) + "|";
        informacion +=  QString::number(posX) + "|";
        informacion +=  QString::number(posY) + "|";
        informacion +=  QString::number(red) + "|";
        informacion +=  QString::number(green) + "|";
        informacion +=  QString::number(blue) + "/";
        return informacion;
    }

    void print() const {
        std::cout << "ID: " << id << "\n"
                  << "Voltaje: " << voltaje << "\n"
                  << "Posición X: " << posX << "\n"
                  << "Posición Y: " << posY << "\n"
                  << "Red: " << red << "\n"
                  << "Green: " << green << "\n"
                  << "Blue: " << blue << "\n";
    }
};

class AdministradorNeuronas {
private:
    std::list<Neurona> listaNeuronas;

public:
    void agregarInicio(const Neurona& neurona) {
        listaNeuronas.push_front(neurona);
    }

    void agregarFinal(const Neurona& neurona) {
        listaNeuronas.push_back(neurona);
    }

    void mostrar() const {
        for (const auto& neurona : listaNeuronas) {
            neurona.print();
            std::cout << "------------------------\n";
        }
    }

    QString obtenerInformacion() const {
        QString informacion;
        for (const auto& neurona : listaNeuronas) {
            informacion += neurona.obtenerInformacion();
            informacion += "------------------------\n";
        }
        return informacion;
    }

    QString archivoSeparado() const {
        QString informacion;
        for (const auto& neurona : listaNeuronas) {
            informacion += neurona.InfoArchivo();

        }
        return informacion;
    }

    int numeroDeNeuronas() const {
        return listaNeuronas.size();
    }

    Neurona * buscarNeuronaPorID(int id) {
        for (auto& neurona : listaNeuronas) {
            if (neurona.Id() == id) {
                return &neurona;
            }
        }
        return nullptr;
    }

    Neurona * next(){
        for (auto& neurona : listaNeuronas)
        {
            return &neurona;
        }
        return nullptr;
    }

    // Ordenar las neuronas por voltaje
    void ordenarPorVoltaje() {
        for (auto it1 = listaNeuronas.begin(); it1 != listaNeuronas.end(); ++it1) {
            for (auto it2 = std::next(it1); it2 != listaNeuronas.end(); ++it2) {
                if (it1->Voltaje() > it2->Voltaje()) {
                    std::swap(*it1, *it2);
                }
            }
        }
    }

    // Ordenar las neuronas por ID ascendente
    void ordenarPorIDAscendente() {
        for (auto it1 = listaNeuronas.begin(); it1 != listaNeuronas.end(); ++it1) {
            for (auto it2 = std::next(it1); it2 != listaNeuronas.end(); ++it2) {
                if (it1->Id() > it2->Id()) {
                    std::swap(*it1, *it2);
                }
            }
        }
    }

    // Función para obtener el iterador al primer elemento de la lista
    std::list<Neurona>::iterator begin() {
        return listaNeuronas.begin();
    }

    // Función para obtener el iterador al último elemento de la lista
    std::list<Neurona>::iterator end() {
        return listaNeuronas.end();
    }

    // Función para obtener la primera neurona de la lista
    Neurona* obtenerPrimeraNeurona() {
        if (!listaNeuronas.empty()) {
            return &listaNeuronas.front();
        }
        return nullptr;
    }



};

#endif // NEURON_H
