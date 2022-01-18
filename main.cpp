#include <iostream>
#include <vector>
#include "client.h"
#include "chambre.h"
#include "hotel.h"
#include "date.h"
#include "reservation.h"

hotel::Client getInfoClient(std::vector<hotel::Client>& liste){
    bool status = false;
    std::string prenom;
    std::string nom;
    std::cout << "entrer un prenom : ";
    std::cin >> prenom;
    std::cout << std::endl;
    std::cout << "entrer un nom: ";
    std::cin >> nom;
    std::cout << std::endl;
    for(auto i = liste.begin(); i!= liste.end(); i++){
        if((prenom == (*i).firstname()) && (nom == (*i).lastname())){
            std::cout <<"ancien client : "<< "\n" <<  *i << std::endl;
            status = true;
            return *i;
        }
    }
    if(status == false){
        hotel::Client newclient(prenom,nom);
        std::cout << "nouveau client : " << "\n" <<newclient;
        liste.push_back(newclient);
        return newclient;
    } 
} 

date::Date setDate(){
    std::cout << "entrer le jour d'arriver :";
    int jour;
    std::cin >> jour;
    std::cout << "entrer le mois d'arriver :";
    int mois;
    std::cin >> mois; 
    std::cout << "entrer l'annee d'arriver :";
    int annee;
    std::cin >> annee;  
    bool status = date::isDate(mois,jour,annee);
    if(status){
        date::Date NewDate(mois,jour,annee);
        return NewDate;
    }
    else{
        while(status == false){
        std::cout << "information sur la date incorect. Veuillez resaisir des informations viables" << std::endl;
        std::cout << "entrer le jour d'arriver :";
        std::cin >> jour;
        std::cout << "entrer le mois d'arriver :";
        std::cin >> mois;
        std::cout << "entrer l'annee d'arriver :";
        std::cin >> annee; 
        status = date::isDate(mois,jour,annee);
        }
        date::Date Newdate(mois,jour,annee);
        return Newdate;
    }  
    
} //fait

int nombredenuit(){
    std::cout << "entrer un nombre de nuit : ";
    int nbrNuits = 0;
    std::cin >> nbrNuits;
    std::cout << std::endl;
    if(nbrNuits > 0){
        std::cout << "le nombre de nuit reserve est de " << nbrNuits << std::endl;
        return nbrNuits;
    }

    else{
        while(nbrNuits <= 0){
        std::cout << "Veuillez resaisir un nombre de nuit valide : " << std::endl;
        std::cin >> nbrNuits;
        std::cout << std::endl;
        
        }
    return nbrNuits;
    }
    
}//fait



hotel::Chambre selectRoomByType(const std::vector<hotel::Chambre>& listeChambre){
    std::string Type ;
    
    std::cout << "Veuillez entrer le type de chambre souhaite : ";
    std::cin >> Type;
    
    for(auto i = listeChambre.begin(); i!=listeChambre.end(); ++i){
        if(i->gettype() == Type) {
            
            return *i;
        }   
    }

    std::cout << "Impossible de trouver une chambre de ce type; recommencer une nouvelle reservation";
}

void displayReservation(std::vector<hotel::Reservation>& liste){
    if(liste.empty()){
        std::cout << "Aucune reservation";
    }
    else{
        std::cout<< "Voici, votre liste de reservation : " << "\n";
        for(auto i = liste.begin(); i != liste.end(); i++){
            std::cout << *i << std::endl;
            
        }
    }

}

hotel::Reservation displayreservationbyID(std::vector<hotel::Reservation>& liste){
    std::cout << "Veuillez entrer le nombre de la reservation que vous souhaiter consulter";
    int place =0;
    std::cin >> place;
    auto i = liste.begin() + place;
    std::cout << *i;
    return *i;
}

void displayreservationbyclient(std::vector<hotel::Reservation> liste){
    std::cout << "Veuillez entrer le nom de la personne dont vous souhaiter consulter les reservations" << std::endl;
    std::string nom;
    std::cin >> nom;
    for(auto i = liste.begin(); i != liste.end(); ++i){
        if((i->getclient().lastname() == nom)){
            std::cout << *i;
        }
    }
}
void updatereservation(std::vector<hotel::Reservation> &listeRes, std::vector<hotel::Chambre> &listeChambre,std::vector<hotel::Client> &listeClient  );

int main(){
    hotel::Chambre C1(100,100,"Single");
    hotel::Chambre C2(102,100,"Single");
    hotel::Chambre C3(104,100,"Single");
    hotel::Chambre C4(200,125,"Double");
    hotel::Chambre C5(202,125,"Double");
    hotel::Chambre C6(204,125,"Double");
    hotel::Chambre C7(208,125,"Double");
    hotel::Chambre C8(210,125,"Double");
    hotel::Chambre C9(300,210,"Suite");
    hotel::Chambre C10(302,210,"Suite");

    hotel::Client c1("Jean","Dupond");
    hotel::Client c2("Pascal","Legrand");
    hotel::Client c3("Julien","Lebrun");
    hotel::Client c4("Maxime","Martin");
    hotel::Client c5("Antoine","Petit");

    std::vector<hotel::Client> ListingClient = {c1 , c2 , c3 , c4 , c5};
    std::vector<hotel::Chambre> ListingChambre = { C1 , C2 , C3 , C4 , C5 , C6 , C7 , C8 , C9 , C10};
    std::vector<hotel::Reservation> ListingReservation ;
    hotel::Hotel H1("The Marbella","Dijon Plage",ListingChambre,"Lapilazuli");
    
    date::Date datearrive = setDate();
    hotel::Chambre chambre =   selectRoomByType(ListingChambre) ;  
    int NumberofNight = nombredenuit();
    hotel::Client ClientReservation = getInfoClient(ListingClient);
    


    hotel::Reservation R1(datearrive,NumberofNight,H1,chambre,ClientReservation);
    ListingReservation.push_back(R1);
    std::cout << R1;

    return 0;
}

void updatereservation(std::vector<hotel::Reservation> &listeRes, std::vector<hotel::Chambre> &listeChambre,std::vector<hotel::Client> &listeClient  ){
    
    hotel::Reservation temp = displayreservationbyID(listeRes);
    
    
    std::cout << "Veuillez entrer le paramametre de la reservation que vous souhaiter modifier : " << std::endl;
    std::cout << "Taper '1' pour modifier la date de début" << "\n" << "Taper '2' pour modifier le nombre de nuit" << "\n"
        << "Taper '3' pour modifier la chambre" << "\n" <<"Taper '4' pour modifier le client" << "\n" << "Taper '5' pour annuler une reservation";
    ;
    int choice = 0;
    date::Date date = setDate();
    std::cin >> choice;
    switch (choice)
    {
    case 1:      
        temp.updateDateDebut(setDate());
        break;
    case 2:
        temp.updateDuree(nombredenuit());
        break;
    case 3:
        
        temp.updateChambre(selectRoomByType(listeChambre));
        break;
    case 4:
        temp.updateClient(getInfoClient(listeClient));
        break;
    case 5:
        for(auto i = listeRes.begin() ; i != listeRes.end() ; ++i ){
            if((i->getclient().uniqueID() == temp.getclient().uniqueID()) && (i->getdate() == temp.getdate()) && (i->getnombtreDeNuit() == temp.getnombtreDeNuit())){
                listeRes.erase(i);
            }
        }
        break;
    default:
        std::cout << "Veuillez selectionner un parametre valide." << std::endl;
        break;
    }
}