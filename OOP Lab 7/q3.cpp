#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;
    bool isReserved;

public:
    Ticket(int id, string name, double p, string d, string dest)
        : ticketID(id), passengerName(name), price(p), date(d), destination(dest), isReserved(false) {}

    virtual void reserve() {
        isReserved = true;
        cout << "Ticket reserved successfully." << endl;
    }

    virtual void cancel() {
        isReserved = false;
        cout << "Ticket cancelled successfully." << endl;
    }

    virtual void displayTicketInfo() const {
        cout << "\nTicket ID: " << ticketID
             << "\nPassenger Name: " << passengerName
             << "\nPrice: $" << price
             << "\nDate: " << date
             << "\nDestination: " << destination
             << "\nStatus: " << (isReserved ? "Reserved" : "Not Reserved") << endl;
    }

    virtual ~Ticket() {}
};

class FlightTicket : public Ticket {
private:
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, double p, string d, string dest, string airline, string flight, string seat)
        : Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flight), seatClass(seat) {}

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Airline Name: " << airlineName
             << "\nFlight Number: " << flightNumber
             << "\nSeat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
private:
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, double p, string d, string dest, string train, string coach, string time)
        : Ticket(id, name, p, d, dest), trainNumber(train), coachType(coach), departureTime(time) {}

    void reserve() override {
        isReserved = true;
        cout << "Train ticket reserved. Auto-assigning seat." << endl;
    }

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Train Number: " << trainNumber
             << "\nCoach Type: " << coachType
             << "\nDeparture Time: " << departureTime << endl;
    }
};

class BusTicket : public Ticket {
private:
    string busCompany;
    string seatNumber;

public:
    BusTicket(int id, string name, double p, string d, string dest, string company, string seat)
        : Ticket(id, name, p, d, dest), busCompany(company), seatNumber(seat) {}

    void cancel() override {
        if (isReserved) {
            isReserved = false;
            cout << "Bus ticket cancelled successfully. Last-minute refund allowed." << endl;
        } else {
            cout << "Ticket is not reserved yet." << endl;
        }
    }

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Bus Company: " << busCompany
             << "\nSeat Number: " << seatNumber << endl;
    }
};

class ConcertTicket : public Ticket {
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double p, string d, string dest, string artist, string v, string seat)
        : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(seat) {}

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Artist Name: " << artistName
             << "\nVenue: " << venue
             << "\nSeat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket flight(101, "Abeer", 150.0, "2025-04-15", "Paris", "AirFrance", "AF101", "Economy");
    TrainTicket train(102, "Abeer", 50.0, "2025-04-16", "London", "EuroStar", "First Class", "10:00 AM");
    BusTicket bus(103, "Abeer", 20.0, "2025-04-17", "Berlin", "FlixBus", "B12");
    ConcertTicket concert(104, "Abeer", 80.0, "2025-04-18", "New York", "Taylor Swift", "Madison Square Garden", "VIP");

    flight.displayTicketInfo();
    train.displayTicketInfo();
    bus.displayTicketInfo();
    concert.displayTicketInfo();

    flight.reserve();
    train.reserve();
    bus.reserve();
    bus.cancel();
    concert.reserve();

    return 0;
}
