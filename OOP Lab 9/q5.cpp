#include <iostream>
#include <string>

using namespace std;


class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string tNum, double wt) : trackingNumber(tNum), weight(wt) {}

    virtual double estimateDeliveryTime() const = 0; 
    virtual void showDetails() const = 0;           

    virtual ~Shipment() {}
};

class AirFreight : public Shipment {
public:
    AirFreight(string tNum, double wt) : Shipment(tNum, wt) {}

    double estimateDeliveryTime() const override {
        // whatver weight be multiplied by 0.4 to determine time
        return weight * 0.4;
    }

    void showDetails() const override {
        cout << "Air Freight Shipment\n";
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Estimated Delivery Time: " << estimateDeliveryTime() << " hours\n";
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string tNum, double wt) : Shipment(tNum, wt) {}

    double estimateDeliveryTime() const override {
        return weight * 1.5;
    }

    void showDetails() const override {
        cout << "Ground Shipment\n";
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Estimated Delivery Time: " << estimateDeliveryTime() << " hours\n";
    }
};

int main() {
    Shipment* shipments[2];
    shipments[0] = new AirFreight("ABR123", 10.5);
    shipments[1] = new GroundShipment("OMR456", 10.5);

    for (int i = 0; i < 2; ++i) {
        shipments[i]->showDetails();
    }

    for (int i = 0; i < 2; ++i) {
        delete shipments[i];
    }

    return 0;
}