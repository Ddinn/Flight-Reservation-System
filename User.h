//MUHAMMAD ARIFUDDIN BIN AZMAN (B032310638)
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
private:
    std::string email;
    std::string name;
    std::string country;
    double balance;
    std::vector<std::string> reservedFlights;

public:
    User(std::string email, std::string name, std::string country, double balance);
    std::string getEmail() const;
    std::string getName() const;
    std::string getCountry() const;
    double getBalance() const;
    void addBalance(double amount);
    void reserveFlight(std::string flightNumber);
    void cancelFlight(std::string flightNumber);
    std::vector<std::string> getReservedFlights() const;
};

#endif // USER_H
