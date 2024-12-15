//MUHAMMAD ARIFUDDIN BIN AZMAN (B032310638)
#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H

#include <vector>
#include "User.h"
#include "Flight.h"

class ReservationSystem {
private:
    std::vector<User> users;
    std::vector<Flight> flights;

public:
    ReservationSystem();
    void addUser(User user);
    void addFlight(Flight flight);
    User* login(std::string email);
    std::vector<Flight> searchFlightsByDestination(const std::string& destination);
    Flight* searchFlightByNumber(const std::string& flightNumber);
    bool bookFlight(User* user, const std::string& flightNumber, const std::string& classType);
    void cancelFlight(User* user, const std::string& flightNumber, const std::string& classType);
};

#endif // RESERVATIONSYSTEM_H
