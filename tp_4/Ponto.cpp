//implementation

#include "Ponto.hpp"
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> Ponto2D::listId;

void Ponto2D:: print(){
    cout << "(" << this->x;
    cout << "," << this->y << ")" << endl;

}

Ponto2D *Ponto2D::sumof(Ponto2D *point){
    Ponto2D *p = new Ponto2D();

    p->setx(this->x + (*point).getx());
    p->sety(this->y + (*point).gety());

    return p;
}

void Ponto2D::sumof(Ponto2D point){
    this->x += point.getx();
    this->y += point.gety();
}

double Ponto2D::distToOrig() const{
    double d = hypot(this->x, this->y);
    return d;
}

double Ponto2D::distTo(Ponto2D p) const{
    double d = hypot((this->x - p.getx()), (this->y - p.gety()));
    return d;
}

int Ponto2D::getNextId(){
    int quantidadeId = listId.size();
    int tamanhoId = 0;
    int newId = -1;

    if(quantidadeId >= 1001){
        cout << "ERRO! Não há mais espaço para criar um objeto do tipo Ponto2D";
        exit(1);
    }else{
        while(true){
            //listId.push_back(random()%1000);
            newId = random()%1000;
            int tamanhoId = listId.size();
            bool IdOccupaded = false;

            IdOccupaded = occupaded(newId);
            if(!IdOccupaded){
                break;
            }
        }
    }
    return newId;
}

bool Ponto2D::occupaded(int newId){
    for(int i = 0; i < listId.size(); i++){
        if(newId == listId[i]){
            return true;
        }
    }
    return false;
}

Ponto2D::~Ponto2D(){
    int tamanhoList = listId.size();
    int id = this->id;

    for(int i = 0; i < tamanhoList; i++){
        if(listId[i] == id && i != 0 ){
            listId.erase(listId.begin() + (i-1) );
        }else if (listId[i] == id){
            listId.erase(listId.begin());
        }
    }
}