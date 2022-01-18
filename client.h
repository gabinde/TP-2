#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <assert.h>
#include <vector>

namespace hotel {
    
    class Client{
    public:
        Client(std::string firstname, std::string lastname);

        std::string firstname() const;
        std::string lastname() const;
        std::string uniqueID() const;
        
        
        friend std::ostream& operator<<(std::ostream& os, const Client& Client);
    private:
        std::string _firstname;
        std::string _lastname;
        std::string _uniqueID;

    };
}
#endif