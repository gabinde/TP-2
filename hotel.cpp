#include "hotel.h"

namespace hotel{
    std::vector<std::string> listehotelID;
    Hotel::Hotel(std::string name,std::string ville,  std::vector<hotel::Chambre> listeChambre,std::string uniqueID):
    _name(name),
    _ville(ville),
    _listeChambre(listeChambre),
    _uniqueID(uniqueID){
        for(auto i = listehotelID.begin(); i != listehotelID.end(); ++i){
            if( *i == _uniqueID){
                assert("L'identifiant de l'hotel éxiste déjà" && 0);
                
            }
        }
        listehotelID.push_back(_uniqueID);
    }
    void Hotel::addroom(Chambre& chambre){
        _listeChambre.push_back(chambre);
    }

    void Hotel::delroom(Chambre& chambre){
        for(auto i = _listeChambre.begin() ; i != _listeChambre.end(); ++i){
            if( i->getroomnumber() == chambre.getroomnumber()){
                _listeChambre.erase(i);
            }
        }
    }

    std::string Hotel::getname() const{
        return _name;
    }
    std::string Hotel::getville() const{
        return _ville;
    }
    std::vector<hotel::Chambre> Hotel::getliste() const{
        return _listeChambre;
    }
    hotel::Chambre& Hotel::findchambre(int roomnumber){
        for(auto i = _listeChambre.begin(); i !=_listeChambre.end(); ++i ){
            if((*i).getroomnumber() == roomnumber ){
                std::cout << *i;
                return *i;
            }
        }
    }

    
    std::ostream& operator<<(std::ostream& os, const Hotel& hotel){
        std::string to_display = " Nom : " + hotel._name + "  \n "+ "Location : " + hotel._ville + "\n" + "chambres : " ;
        
        os << to_display << std::endl;
        for (auto i = hotel._listeChambre.begin(); i != hotel._listeChambre.end(); i++ ){
            os << *i ;
        }
        return os;
    }

}
