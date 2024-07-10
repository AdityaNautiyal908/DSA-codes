#include <iostream>
#include <vector>
using namespace std;

// Function to check if a given number of flowers is valid and return all possible distributions
vector<vector<int>> getAllInvalidDistributions(int flowers) {
    vector<vector<int>> invalidDistributions;
    
    for (int i = 1; i <= flowers; ++i) {
        int currentFlowers = flowers;
        vector<int> possibleDistribution;
        bool valid = true;
        
        for (int j = 0; j < 3; ++j) {
            if (currentFlowers < i) {
                valid = false;
                break;
            }
            possibleDistribution.push_back(i);
            currentFlowers = (currentFlowers - i) * 2;
        }
        
        if (!valid || currentFlowers != 0) {
            invalidDistributions.push_back(possibleDistribution);
        }
    }
    
    return invalidDistributions;
}

// Function to check if a given number of flowers is valid and return the number of flowers given to each temple
vector<int> isValidFlowers(int flowers) {
    vector<int> distribution;
    
    for (int i = 1; i <= flowers; ++i) {
        int currentFlowers = flowers;
        vector<int> possibleDistribution;
        bool valid = true;
        
        for (int j = 0; j < 3; ++j) {
            if (currentFlowers < i) {
                valid = false;
                break;
            }
            possibleDistribution.push_back(i);
            currentFlowers = (currentFlowers - i) * 2;
        }
        
        if (valid && currentFlowers == 0) {
            distribution = possibleDistribution;
            return distribution;
        }
    }
    
    return distribution; // Return empty vector if no valid distribution found
}

int main() {
    int flowers;
    cout << "Enter the number of flowers: ";
    cin >> flowers;

    vector<int> result = isValidFlowers(flowers);
    if (!result.empty()) {
        cout << "The flower count is correct for equal distribution to the three temples." << endl;
        cout << "Possible distribution: ";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i < result.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        cout << "The flower count is NOT correct for equal distribution to the three temples." << endl;
        
        vector<vector<int>> invalidDistributions = getAllInvalidDistributions(flowers);
        if (!invalidDistributions.empty()) {
            cout << "Possible incorrect distributions:" << endl;
            for (const auto& distribution : invalidDistributions) {
                for (int i = 0; i < distribution.size(); ++i) {
                    cout << distribution[i];
                    if (i < distribution.size() - 1) {
                        cout << " -> ";
                    }
                }
                cout << endl;
            }
        } else {
            cout << "No possible incorrect distributions found." << endl;
        }
    }

    return 0;
}
