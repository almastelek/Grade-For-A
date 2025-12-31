#include "GradeManager.h"
#include "Persistence.h"

using std::string, std::cin, std::cout;

float getFloatInput(const string& prompt) {
    string raw;
    while (true) {
        cout << prompt;
        cin >> raw;
        try {
            return std::stof(raw);
        } catch (...) {
            cout << "Invalid number. Try again.\n";
        }
    }
}

int main() {
    GradeManager manager;
    Persistence::loadFromFile("grades.csv", manager);
    manager.showGrades();
    
    string choice;

    while (true) {
        cout << "[add, show, delete, average, quit]: ";
        cin >> choice;

        if (choice == "add") {
            string name;
            cout << "Assignment name: ";
            cin.ignore();
            std::getline(cin, name); 
            
            float g = getFloatInput("Grade: ");
            float w = getFloatInput("Weight (e.g., 0.25): ");
            
            manager.addOrUpdate(name, g, w);
        } else if (choice == "show") {
            manager.showGrades();
        } else if (choice == "delete") {
            string name;
            cout << "Assignment name: ";
            cin.ignore();
            std::getline(cin, name); 
            manager.remove(name);
        } else if (choice == "average") {
            cout << "Current Average: " << manager.calculateAverage() << "\n";
        } else if (choice == "quit") {
            Persistence::saveToFile("grades.csv", manager);
            cout << "Goodbye!\n";
            break;
        }
    }
    return 0;
}
