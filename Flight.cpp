//MUHAMMAD ARIFUDDIN BIN AZMAN (B032310638)
#include "Flight.h"

Flight::Flight(std::string flightNumber, std::string destination, double economyPrice, double businessPrice, int availableSeats)
    : flightNumber(flightNumber), destination(destination), economyPrice(economyPrice), businessPrice(businessPrice),
    availableEconomySeats(availableSeats / 2), availableBusinessSeats(availableSeats / 2) {}

std::string Flight::getFlightNumber() const {
    return flightNumber;
}

std::string Flight::getDestination() const {
    return destination;
}

double Flight::getEconomyPrice() const {
    return economyPrice;
}

double Flight::getBusinessPrice() const {
    return businessPrice;
}

int Flight::getAvailableEconomySeats() const {
    return availableEconomySeats;
}

int Flight::getAvailableBusinessSeats() const {
    return availableBusinessSeats;
}

bool Flight::bookSeat(const std::string& classType) {
    if (classType == "Economy" && availableEconomySeats > 0) {
        availableEconomySeats--;
        return true;
    }
    else if (classType == "Business" && availableBusinessSeats > 0) {
        availableBusinessSeats--;
        return true;
    }
    return false;
}

void Flight::cancelSeat(const std::string& classType) {
    if (classType == "Economy") {
        availableEconomySeats++;
    }
    else if (classType == "Business") {
        availableBusinessSeats++;
    }
}
