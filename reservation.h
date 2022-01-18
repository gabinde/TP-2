#include <iostream>
#include <assert.h>
#include <vector>
#include "date.h"
#include "hotel.h"
#include "chambre.h"
#include "client.h"

#ifndef RESERVATION_H
#define RESERVATION_H

namespace hotel {
    class Reservation{
    public:
    Reservation(date::Date datedebut,int nombreDeNuits ,Hotel hotel, Chambre Chambre, Client Client);

    date::Date getdate() const;
    hotel::Chambre getchambre() const;
    int getnombtreDeNuit() const;
    Hotel getHotel() const;
    int getnumeroDeChambre() const;
    Client getclient() const;
    int getprixtot() const;
    

    void updateDuree(int nombreDeNuits); 
    void updateDateDebut(date::Date date); 
    void updateChambre(Chambre newChambre);
    void updateClient(Client newClient);
    
    friend std::ostream& operator<<(std::ostream& os, const Reservation& Reservation);
    
    private:
    date::Date _datedebut;
    Chambre _Chambre;
    int _nombreDeNuits;
    Hotel _hotel;
    int _numeroDeChambre;
    Client _client;
    int _prixtot;
    
    };
}

#endif