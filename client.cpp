#include "client.h"

namespace hotel{
    std::vector<std::string> listeID;
    Client::Client(std::string firstname, std::string lastname): 
    _firstname(firstname), 
    _lastname(lastname), 
    _uniqueID(firstname[0] + lastname){ 
        for(auto i = listeID.begin(); i != listeID.end(); ++i){
            if( *i == _uniqueID){
                assert("Votre Identifiant personnel existe deja" && 0);
                
            }
        }
            
    }

    std::string Client::firstname() const{
        return _firstname;
    }
    std::string Client::lastname() const{
        return _lastname;
    }
    std::string Client::uniqueID() const{
        return _uniqueID;
    }

    
    


    std::ostream& operator<<(std::ostream& os, const Client& Client){
        os << " Prenom : " << Client.firstname() << "  - Nom : " << Client.lastname() << "\n" << " ID : " << Client.uniqueID();
        
        return os << std::endl ;
    }


}