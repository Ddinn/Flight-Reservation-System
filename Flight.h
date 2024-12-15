//MUHAMMAD ARIFUDDIN BIN AZMAN (B032310638)
#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

class Flight {
private:
    std::string flightNumber;
    std::string destination;
    double economyPrice;
    double businessPrice;
    int availableEconomySeats;
    int availableBusinessSeats;

public:
    Flight(std::string flightNumber, std::string destination, double economyPrice, double businessPrice, int availableSeats);
    std::string getFlightNumber() const;
    std::string getDestination() const;
    double getEconomyPrice() const;
    double getBusinessPrice() const;
    int getAvailableEconomySeats() const;
    int getAvailableBusinessSeats() const;
    bool bookSeat(const std::string& classType);
    void cancelSeat(const std::string& classType);
};

#endif // FLIGHT_H
