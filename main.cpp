//MUHAMMAD ARIFUDDIN BIN AZMAN (B032310638)
#include <iostream>
#include <limits>
#include "User.h"
#include "Flight.h"
#include "ReservationSystem.h"

void clearInputStream() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}

int main() {
    ReservationSystem system;
    User* currentUser = nullptr;

    while (true) {
        std::cout << "\nFlight Reservation System\n";
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Search Flights by Destination\n";
        std::cout << "4. Search Flight by Flight Number\n";
        std::cout << "5. Book Flight\n";
        std::cout << "6. Cancel Flight\n";
        std::cout << "7. View Reserved Flights\n";
        std::cout << "8. Logout\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        clearInputStream(); // Clear the input stream to avoid issues with newlines

        if (choice == 1) {
            // Register
            std::string email, name, country;
            double balance;
            std::cout << "\nEnter email: ";
            std::getline(std::cin, email);
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter country: ";
            std::getline(std::cin, country);
            std::cout << "Enter balance: ";
            std::cin >> balance;
            clearInputStream(); // Clear the input stream to avoid issues with newlines
            system.addUser(User(email, name, country, balance));
            std::cout << "User registered successfully.\n\n";

        }
        else if (choice == 2) {
            // Login
            std::string email;
            std::cout << "\nEnter email: ";
            std::getline(std::cin, email);
            currentUser = system.login(email);
            if (currentUser) {
                std::cout << "Logged in as: " << currentUser->getName() << "\n\n";
            }
            else {
                std::cout << "Login failed.\n\n";
            }

        }
        else if (choice == 3) {
            // Search Flights by Destination
            if (currentUser) {
                std::string destination;
                std::cout << "\nEnter destination: ";
                std::getline(std::cin, destination);
                std::vector<Flight> flights = system.searchFlightsByDestination(destination);
                for (const auto& flight : flights) {
                    std::cout << "Flight Number: " << flight.getFlightNumber() << ", Destination: " << flight.getDestination()
                        << ", Economy Price: " << flight.getEconomyPrice() << ", Business Price: " << flight.getBusinessPrice()
                        << ", Available Economy Seats: " << flight.getAvailableEconomySeats() << ", Available Business Seats: "
                        << flight.getAvailableBusinessSeats() << "\n\n";
                }
            }
            else {
                std::cout << "Please login first.\n\n";
            }

        }
        else if (choice == 4) {
            // Search Flight by Flight Number
            if (currentUser) {
                std::string flightNumber;
                std::cout << "\nEnter flight number: ";
                std::getline(std::cin, flightNumber);

                Flight* flight = system.searchFlightByNumber(flightNumber);
                if (flight) {
                    std::cout << "Found Flight Number: " << flight->getFlightNumber() << ", Destination: " << flight->getDestination()
                        << ", Economy Price: " << flight->getEconomyPrice() << ", Business Price: " << flight->getBusinessPrice()
                        << ", Available Economy Seats: " << flight->getAvailableEconomySeats() << ", Available Business Seats: "
                        << flight->getAvailableBusinessSeats() << "\n\n";
                }
                else {
                    std::cout << "Flight not found.\n\n";
                }
            }
            else {
                std::cout << "Please login first.\n\n";
            }

        }
        else if (choice == 5) {
            // Book Flight
            if (currentUser) {
                std::string flightNumber, classType;
                std::cout << "\nEnter flight number: ";
                std::getline(std::cin, flightNumber);
                std::cout << "Enter class type (Economy/Business): ";
                std::getline(std::cin, classType);

                if (system.bookFlight(currentUser, flightNumber, classType)) {
                    std::cout << "Flight booked successfully.\n\n";
                }
                else {
                    std::cout << "Failed to book flight.\n\n";
                }
            }
            else {
                std::cout << "Please login first.\n\n";
            }

        }
        else if (choice == 6) {
            // Cancel Flight
            if (currentUser) {
                std::string flightNumber, classType;
                std::cout << "\nEnter flight number: ";
                std::getline(std::cin, flightNumber);
                std::cout << "Enter class type (Economy/Business): ";
                std::getline(std::cin, classType);

                system.cancelFlight(currentUser, flightNumber, classType);
                std::cout << "Flight cancelled.\n\n";
            }
            else {
                std::cout << "Please login first.\n\n";
            }

        }
        else if (choice == 7) {
            // View Reserved Flights
            if (currentUser) {
                std::cout << "\nUser Information: \n";
                std::cout << "Name: " << currentUser->getName() << "\n";
                std::cout << "Email: " << currentUser->getEmail() << "\n";
                std::cout << "Balance: " << currentUser->getBalance() << "\n";
                std::cout << "Reserved Flights: \n";
                for (const auto& reserved : currentUser->getReservedFlights()) {
                    std::cout << "Flight Number: " << reserved << "\n\n";
                }
            }
            else {
                std::cout << "\nPlease login first.\n\n";
            }

        }
        else if (choice == 8) {
            // Logout
            currentUser = nullptr;
            std::cout << "\nLogged out.\n\n";

        }
        else if (choice == 9) {
            // Exit
            break;
        }
        else {
            std::cout << "\nInvalid choice. Please try again.\n\n";
        }
    }

    return 0;
}
  