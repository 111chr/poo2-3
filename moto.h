#include <string>
#include "vehicul.h"

using namespace std;

#ifndef POO_MOTO_H
#define POO_MOTO_H

class Moto : public Vehicul {
private:
    float kw; //decapotabila sau sedane
public:
    
    Moto();
    
    Moto(const string &marca, const string &model, const string &culoare, const string &combustibil, float cc,
         float pret, int an, float kw);
    
    Moto(const Vehicul &other, float kw);
    
    ~ Moto();
    
    Moto &operator=(const Moto &other);
    
    friend ostream &operator<<(ostream &out, const Moto &Moto);
    
    friend istream &operator>>(istream &in, Moto &Moto);
    
    const string &getMarca() const override;
    
    const string &getModel() const override;
    
    float calculCostTotal() const override;
};


#endif
