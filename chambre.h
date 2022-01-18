#include <iostream>
#include <assert.h>
#include "date.h"

#ifndef CHAMBRE_H
#define CHAMBRE_H

namespace hotel {
    

    class Chambre {
    public:
    Chambre(int Numerodechambre, int prix, std::string type);

    int getroomnumber() const;
    int getprice() const;
    std::string gettype() const;
    void updatePrice(int price) ;
    friend std::ostream& operator<<(std::ostream& os, const Chambre& Chambre);


    private:
    int _Numerodechambre;
    int _prix;
    std::string _type;
    
    };
    bool operator == (const Chambre& , const Chambre& ); 
}
    

#endif