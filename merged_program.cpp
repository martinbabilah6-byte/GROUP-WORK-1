#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


class CircuitProtection {
private:
    string circuitName;
    double supplyVoltage;
    double totalPower;
    double loadCurrent;
    double designCurrent;
    int recommendedRating;
    string protectionStatus;

public:
    void setCircuitDetails() {
        cout << "Enter circuit name " << endl;
        cin >> ws;
        getline(cin, circuitName);

        cout << "Enter supply voltage (V) ";
        cin >> supplyVoltage;

        cout << "Enter total load power (W) ";
        cin >> totalPower;
    }

    bool validateDetails() {
        if (supplyVoltage <= 0 || totalPower <= 0) {
            cout << "Invalid input. Please enter positive values." << endl;
            return false;
        }
        return true;
    }

    void calculateLoadCurrent() {
        loadCurrent = totalPower / supplyVoltage;
    }

    void calculateDesignCurrent() {
        designCurrent = loadCurrent * 1.25;
    }

    void recommendProtectionRating() {
        vector<int> ratings = {6, 10, 16, 20, 25, 32, 40, 63};
        recommendedRating = -1;

        for (int rating : ratings) {
            if (rating >= designCurrent) {
                recommendedRating = rating;
                protectionStatus = "Device selected.";
                break;
            }
        }

        if (recommendedRating == -1) {
            protectionStatus = "No standard rating available for this design current.";
        }
    }

    void displayProtectionReport() {
        cout << endl << "--- Protection Report ---" << endl;
        cout << "Circuit: " << circuitName << endl;
        cout << "Load Current: " << loadCurrent << " A" << endl;
        cout << "Design Current: " << designCurrent << " A" << endl;

        if (recommendedRating != -1) {
            cout << "Recommended Device: " << recommendedRating << " A" << endl;
        }

        cout << "Status: " << protectionStatus << endl;
    }

    void saveReportToFile(ofstream &report) {
        report << endl << "--- Protection Report ---" << endl;
        report << "Circuit: " << circuitName << endl;
        report << "Load Current: " << loadCurrent << " A" << endl;
        report << "Design Current: " << designCurrent << " A" << endl;

        if (recommendedRating != -1) {
            report << "Recommended Device: " << recommendedRating << " A" << endl;
        }

        report << "Status: " << protectionStatus << endl;
    }
};

int main() {
    cout << "====================================" << endl;
    cout << "WELCOME TO THE CIRCUIT PROTECTION SYSTEM" << endl;
    cout << "Project Title: Circuit Breaker and Fuse Selection System" << endl;
    cout << "====================================" << endl;
    cout << endl;

    int numberOfCircuits;
    cout << "Enter number of circuits to assess: ";
    cin >> numberOfCircuits;

    if (numberOfCircuits <= 0) {
        cout << "Please enter a valid number of circuits." << endl;
        return 1;
    }

    ofstream report("protection_report.txt");
    if (!report) {
        cerr << "Failed to open report file." << endl;
        return 1;
    }

    for (int i = 0; i < numberOfCircuits; i++) {
        CircuitProtection circuit;

        do {
            circuit.setCircuitDetails();
        } while (!circuit.validateDetails());

        circuit.calculateLoadCurrent();
        circuit.calculateDesignCurrent();
        circuit.recommendProtectionRating();

        circuit.displayProtectionReport();
        circuit.saveReportToFile(report);
    }

    report.close();
    cout << endl << "Protection selection report saved to protection_report.txt" << endl;

    return 0;
}
