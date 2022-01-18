#include <iostream>
#include <assert.h>
#include <vector>
#include "chambre.h"

#ifndef HOTEL_H
#define HOTEL_H

namespace hotel {
    class Hotel{
    public:
    Hotel(std::string name,std::string ville,  std::vector<hotel::Chambre> listeChambre, std::string uniqueID);

    void addroom(Chambre& chambre); //fait
    void delroom(Chambre& chambre); //fait
    std::string getname() const; //fait
    std::string getville() const; //fait
    std::vector<hotel::Chambre> getliste() const; //fait
    hotel::Chambre& findchambre(int roomnumber); //fait
    friend std::ostream& operator<<(std::ostream& os, const Hotel& hotel);  //fait
    
        
    private:
    std::string _name;
    std::string _ville;
    std::string _uniqueID;
    std::vector<hotel::Chambre> _listeChambre;     
    };
}

#endif