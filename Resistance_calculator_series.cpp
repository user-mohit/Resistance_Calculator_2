#include <iostream>
#include <vector>

using namespace std;

// Function to calculate resistance of resistors in parallel
double calculateParallelResistance(const vector<double>& resistors) {
    double totalInverseResistance = 0.0;
    for (double resistance : resistors) {
        totalInverseResistance += 1.0 / resistance;
    }
    return 1.0 / totalInverseResistance;
}

int main() {
    // Initialize the resistance values
    vector<double> resistances = {1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4,
                                  2.7, 3.0, 3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2,
                                  6.8, 7.5, 8.2, 9.1};

    // Prompt the user for a desired resistance value
    double desiredResistance;
    cout << "Enter a desired resistance value: ";
    cin >> desiredResistance;

    cout<<"==========================================================================================="<<endl ;
    cout<<"==========================================================================================="<<endl;

    // Find combinations of at most four resistors in series
    cout << "Combinations of up to four resistors in series to achieve " << desiredResistance << " ohms: " << endl;

    bool found = false;
    bool parallelFound = false;

    for (size_t i = 0; i < resistances.size(); ++i) {
        double sum1 = resistances[i];
        if (sum1 == desiredResistance) {
            cout<<resistances[i] << endl;
            found = true;
        }
        for (size_t j = i + 1; j < resistances.size(); ++j) {
            double sum2 = sum1 + resistances[j];
            if (sum2 == desiredResistance) {
                cout <<resistances[i] << " + " << resistances[j] << endl;
                  found = true;
            }
            for (size_t k = j + 1; k < resistances.size(); ++k) {
                double sum3 = sum2 + resistances[k];
                if (sum3 == desiredResistance) {
                    cout <<resistances[i] << " + " << resistances[j] << " + " << resistances[k] << endl;
                      found = true;
                }
                for (size_t l = k + 1; l < resistances.size(); ++l) {
                    double sum4 = sum3 + resistances[l];
                    if (sum4 == desiredResistance) {
                        cout <<resistances[i] << " + " << resistances[j] << " + " << resistances[k] << " + " << resistances[l] << endl;
                          found = true;
                    }
                }
            }
        }
    }

    if (!found) {
        cout << "No combination of up to four resistors in series can achieve the desired resistance." << endl;
    }

    cout<<"==========================================================================================="<< endl;
    cout<<"==========================================================================================="<< endl;

    // Find combinations of up to four resistors in parallel
    cout << "Parallel combinations to achieve " << desiredResistance << " ohms:" << endl;
    for (size_t i = 0; i < resistances.size(); ++i) {
        for (size_t j = i + 1; j < resistances.size(); ++j) {
            double parallelSum2 = calculateParallelResistance({resistances[i], resistances[j]});
            if (parallelSum2 == desiredResistance) {
                cout << "(" << resistances[i] << " || " << resistances[j] << ")" << endl;
                parallelFound = true;
            }
            for (size_t k = j + 1; k < resistances.size(); ++k) {
                double parallelSum3 = calculateParallelResistance({resistances[i], resistances[j], resistances[k]});
                if (parallelSum3 == desiredResistance) {
                    cout << "(" << resistances[i] << " || " << resistances[j] << " || " << resistances[k] << ")" << endl;
                    parallelFound = true;
                }
                for (size_t l = k + 1; l < resistances.size(); ++l) {
                    double parallelSum4 = calculateParallelResistance({resistances[i], resistances[j], resistances[k], resistances[l]});
                    if (parallelSum4 == desiredResistance) {
                        cout << "(" << resistances[i] << " || " << resistances[j] << " || " << resistances[k] << " || " << resistances[l] << ")" << endl;
                        parallelFound = true;
                    }
                }
            }
        }
    }

    if (!parallelFound)
        cout << "No parallel combination found for " << desiredResistance << " ohms." << endl;

    return 0;
}
