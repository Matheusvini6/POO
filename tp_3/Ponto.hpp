//Header file

#include <iostream>
#include <vector>

#ifndef PONTO_HPP
#define PONTO_HPP


class Ponto2D{
    private:

        double x, y;
        int getNextId();
        static std::vector<int> listId;
        int id;
        //verifica se o id gerado já esta em listId
        bool occupaded(int numeroId);
        

    public:
        //construtores e destrutor
        Ponto2D(): x(0), y(0){this->id = getNextId();}
        Ponto2D(double x_, double y_): x(x_), y(y_){this->id = getNextId(); listId.push_back(id);}
        ~Ponto2D();

        //set and get
        void setx(double x_) {x = x_;}
        void sety(double y_) {y = y_;}
        double getx() {return x;}
        double gety() {return y;}
        int getId() {return id;}
        void setId(int id){this->id = id;}

        //other functions

        // Função membro para escrever (imprimir) as coordenadas do ponto na tela
        void print();

        // Função membro que retorna um ponto p3 que é o resultado da soma entre dois pontos
        // p1 e p2, onde p1 é o objeto que chama a função. 
        Ponto2D* sumof(Ponto2D *ponto);

        // Função membro que modifica as coordenadas do objeto corrente p1 somando às 
        // suas coordenadas um novo ponto p2, que deve ser passado por argumento. 
        void sumof(Ponto2D point);

        //Função membro para calcular a distância do ponto a origem do sistema de coordenadas 
        //cartesiano
        double distToOrig() const;

        // unção membro para calcular a distância entre dois pontos p1 e p2, 
        //onde p1 é o objeto que chama a função
        double distTo(Ponto2D point) const;
        
};

#endif