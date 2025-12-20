#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>

using namespace std;

class ItemTracker {
public:
    // Build the frequency map from the input file and create frequency.dat backup
    bool LoadFromFile(const string& inputFileName) {
        ifstream inFS(inputFileName);
        if (!inFS.is_open()) {
            return false;
        }

        itemFrequency.clear();

        string item;
        while (inFS >> item) {
            itemFrequency[item]++;
        }

        inFS.close();

        // Create backup file automatically
        WriteBackupFile("frequency.dat");
        return true;
    }

    // Menu Option 1: return frequency for a specific item
    int GetItemFrequency(const string& item) const {
        auto it = itemFrequency.find(item);
        if (it == itemFrequency.end()) {
            return 0;
        }
        return it->second;
    }

    // Menu Option 2: print all item frequencies
    void PrintAllFrequencies() const {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Menu Option 3: print histogram
    void PrintHistogram(char symbol = '*') const {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << symbol;
            }
            cout << endl;
        }
    }

private:
    map<string, int> itemFrequency;

    void WriteBackupFile(const string& outputFileName) const {
        ofstream outFS(outputFileName);
        if (!outFS.is_open()) {
            // If backup fails, we just silently continue (or you can print an error)
            return;
        }

        for (const auto& pair : itemFrequency) {
            outFS << pair.first << " " << pair.second << endl;
        }

        outFS.close();
    }
};

// Helper: show menu
void PrintMenu() {
    cout << "\n========== CORNER GROCER ITEM TRACKER ==========\n";
    cout << "1. Look up an item frequency\n";
    cout << "2. Print all item frequencies\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "Enter your choice (1-4): ";
}

// Helper: safe integer input (keeps prompting until valid int)
int GetValidatedMenuChoice() {
    int choice;
    while (true) {
        cin >> choice;

        if (!cin.fail() && choice >= 1 && choice <= 4) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }

        cout << "Invalid input. Please enter a number from 1 to 4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    ItemTracker tracker;

    const string inputFileName = "CS210_Project_Three_Input_File.txt";
    if (!tracker.LoadFromFile(inputFileName)) {
        cout << "Error: Could not open input file: " << inputFileName << endl;
        cout << "Make sure the file is in the same folder as this program.\n";
        return 1;
    }

    // Menu loop
    while (true) {
        PrintMenu();
        int choice = GetValidatedMenuChoice();

        if (choice == 1) {
            // Option 1: prompt for item, return numeric frequency
            cout << "Enter the item to search for: ";
            string item;
            getline(cin, item);

            int freq = tracker.GetItemFrequency(item);
            cout << item << " occurs " << freq << " time(s)." << endl;

        }
        else if (choice == 2) {
            // Option 2: print list with numeric frequencies
            cout << "\nITEM FREQUENCIES\n";
            tracker.PrintAllFrequencies();

        }
        else if (choice == 3) {
            // Option 3: print histogram
            cout << "\nHISTOGRAM\n";
            tracker.PrintHistogram('*');

        }
        else { // choice == 4
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}
