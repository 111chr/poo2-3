#include <iostream>
#include <string>

using namespace std;

#ifndef POO_VEHICUL_H
#define POO_VEHICUL_H

class Vehicul {
protected:
    string marca, model, culoare, combustibil;
    float cc, pret;
    int an;

public:
    Vehicul();
    
    Vehicul(const string &marca, const string &model, const string &culoare,
            const string &combustibil, float cc, float pret, int an);
    
    virtual ~Vehicul();
    
    Vehicul(const Vehicul &other);
    
    Vehicul &operator=(const Vehicul &other);
    
    friend ostream &operator<<(ostream &out, const Vehicul &vehicul);
    
    friend istream &operator>>(istream &in, Vehicul &vehicul);
    
    virtual const string &getMarca() const;
    
    virtual const string &getModel() const;
    
    virtual const float &getPret() const;
    
    virtual float calculCostTotal() const;
    
    virtual void AfiseazaDetalii() const;
};

#endif
