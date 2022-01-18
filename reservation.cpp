#include "reservation.h"

namespace hotel{
    
    Reservation::Reservation(date::Date datedebut,int nombreDeNuits ,Hotel hotel,Chambre Chambre, Client Client): 
    _datedebut(datedebut), 
    _nombreDeNuits(nombreDeNuits), 
    _hotel(hotel),
    _client(Client),
    _numeroDeChambre(Chambre.getroomnumber()),
    _Chambre(Chambre)
    {
    };
    hotel::Chambre Reservation::getchambre() const{
        return _Chambre;
    }
    
    date::Date Reservation::getdate() const{
        return _datedebut;
    }
    int Reservation::getnombtreDeNuit() const{
        return _nombreDeNuits;
    }
    Hotel Reservation::getHotel() const{
        return _hotel;
    }
    int Reservation::getnumeroDeChambre() const{
        return _numeroDeChambre;
    }
    Client Reservation::getclient() const{
        return _client;
    }
    int Reservation::getprixtot() const{
        return _nombreDeNuits * _Chambre.getprice();
    }
    std::ostream& operator<<(std::ostream& os, const Reservation& Reservation){
        os << "Debut de la rervation : " << date::toString(Reservation._datedebut) << "\n" <<" Nombre de nuit : " << Reservation._nombreDeNuits 
            << "\n" << "dans l'hotel : " << (Reservation._hotel).getname() << "\n" << " Votre numero de chambre est le : " << Reservation._numeroDeChambre <<
            "\n" << "Merci pour votre reservation : " << Reservation._client << "\n" << "Prix :" << Reservation.getprixtot();
        return os;

    }
    

    void Reservation::updateDuree(int nombreDeNuits){
        _nombreDeNuits = nombreDeNuits;
    }
    void Reservation::updateDateDebut(date::Date date){
        _datedebut = date;
    }
    void Reservation::updateChambre(Chambre newChambre){
        _Chambre = newChambre;
    }
    void Reservation::updateClient(Client Client){
        _client = Client;
    }


}