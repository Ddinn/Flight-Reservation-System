//MUHAMMAD ARIFUDDIN BIN AZMAN (B032310638)
#include "User.h"

User::User(std::string email, std::string name, std::string country, double balance)
    : email(email), name(name), country(country), balance(balance) {}

std::string User::getEmail() const {
    return email;
}

std::string User::getName() const {
    return name;
}

std::string User::getCountry() const {
    return country;
}

double User::getBalance() const {
    return balance;
}

void User::addBalance(double amount) {
    balance += amount;
}

void User::reserveFlight(std::string flightNumber) {
    reservedFlights.push_back(flightNumber);
}

void User::cancelFlight(std::string flightNumber) {
    auto it = std::find(reservedFlights.begin(), reservedFlights.end(), flightNumber);
    if (it != reservedFlights.end()) {
        reservedFlights.erase(it);
    }
}

std::vector<std::string> User::getReservedFlights() const {
    return reservedFlights;
}
