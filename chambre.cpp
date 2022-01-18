#include "chambre.h"
#include <string>

namespace hotel{

    Chambre::Chambre(int Numerodechambre, int prix, std::string type) : 
        _Numerodechambre(Numerodechambre),
        _prix(prix),
        _type(type){
    }

    int Chambre::getroomnumber() const {
        return _Numerodechambre;
    }
    
    int Chambre::getprice() const {
        return _prix;
    }

    std::string Chambre::gettype() const {
        return _type;
    }
    
    void Chambre::updatePrice(int price){
        _prix = price;
    }

    std::ostream& operator<<(std::ostream& os, const Chambre& Chambre){
        os << " Chambre numero : " << Chambre.getroomnumber() << " \n " << "Prix : " << Chambre.getprice() <<" euros" << "\n" << " Type : " << Chambre.gettype();

        return os << std::endl ;
    }
    bool operator == (const Chambre& c1, const Chambre& c2 ){
        if((c1.getprice() == c2.getprice()) && (c1.getroomnumber() == c2.getroomnumber()) && (c1.gettype() == c2.gettype())){
            return true;
        }

        return false;
        
    }     
}