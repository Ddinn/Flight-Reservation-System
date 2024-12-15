//MUHAMMAD ARIFUDDIN BIN AZMAN (B032310638)
#include "ReservationSystem.h"
#include <algorithm>

// Utility function for quick sort
int partition(std::vector<Flight>& flights, int low, int high) {
    std::string pivot = flights[high].getFlightNumber();
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (flights[j].getFlightNumber() < pivot) {
            i++;
            std::swap(flights[i], flights[j]);
        }
    }
    std::swap(flights[i + 1], flights[high]);
    return (i + 1);
}

void quickSort(std::vector<Flight>& flights, int low, int high) {
    if (low < high) {
        int pi = partition(flights, low, high);
        quickSort(flights, low, pi - 1);
        quickSort(flights, pi + 1, high);
    }
}

// Utility function for binary search
int binarySearch(const std::vector<Flight>& flights, const std::string& flightNumber, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (flights[mid].getFlightNumber() == flightNumber) {
            return mid;
        }
        if (flights[mid].getFlightNumber() > flightNumber) {
            return binarySearch(flights, flightNumber, low, mid - 1);
        }
        return binarySearch(flights, flightNumber, mid + 1, high);
    }
    return -1;
}

// Sequential search utility function
std::vector<Flight> sequentialSearch(const std::vector<Flight>& flights, const std::string& destination) {
    std::vector<Flight> results;
    for (const auto& flight : flights) {
        if (flight.getDestination() == destination) {
            results.push_back(flight);
        }
    }
    return results;
}

ReservationSystem::ReservationSystem() {
    // Add pre-existing flight information
    flights.push_back(Flight("UA123", "Thailand", 200, 400, 30));
    flights.push_back(Flight("AA456", "Vietnam", 180, 380, 25));
    flights.push_back(Flight("DL789", "Los Angeles", 220, 450, 35));
    flights.push_back(Flight("OA678", "Japan", 250, 350, 40));
    flights.push_back(Flight("EF234", "China", 180, 240, 20));
    flights.push_back(Flight("JP546", "Japan", 260, 280, 35));
}

void ReservationSystem::addUser(User user) {
    users.push_back(user);
}

void ReservationSystem::addFlight(Flight flight) {
    flights.push_back(flight);
}

User* ReservationSystem::login(std::string email) {
    for (auto& user : users) {
        if (user.getEmail() == email) {
            return &user;
        }
    }
    return nullptr;
}

std::vector<Flight> ReservationSystem::searchFlightsByDestination(const std::string& destination) {
    return sequentialSearch(flights, destination);
}

Flight* ReservationSystem::searchFlightByNumber(const std::string& flightNumber) {
    quickSort(flights, 0, flights.size() - 1);
    int index = binarySearch(flights, flightNumber, 0, flights.size() - 1);
    if (index != -1) {
        return &flights[index];
    }
    return nullptr;
}

bool ReservationSystem::bookFlight(User* user, const std::string& flightNumber, const std::string& classType) {
    Flight* flight = searchFlightByNumber(flightNumber);
    if (flight) {
        double price = (classType == "Economy") ? flight->getEconomyPrice() : flight->getBusinessPrice();
        if (user->getBalance() >= price && flight->bookSeat(classType)) {
            user->reserveFlight(flightNumber);
            user->addBalance(-price);
            return true;
        }
    }
    return false;
}

void ReservationSystem::cancelFlight(User* user, const std::string& flightNumber, const std::string& classType) {
    user->cancelFlight(flightNumber);
    Flight* flight = searchFlightByNumber(flightNumber);
    if (flight) {
        flight->cancelSeat(classType);
    }
    if (flight) {
        double price = (classType == "Economy") ? flight->getEconomyPrice() : flight->getBusinessPrice();
        if (user->getBalance() >= price && flight->bookSeat(classType)) {
            user->addBalance(+price);
        }
    }
}
