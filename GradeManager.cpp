#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

using std::string, std::unordered_map, std::cout, std::cin, std::fixed, std::setprecision;

struct Grade {
    float score;
    float weight;
};

class GradeManager {
private:
    unordered_map<string, Grade> grades;

public:
    void showGrades() const {
        cout << fixed << setprecision(2);
        if (grades.empty()) {
            cout << "No grades recorded.\n";
            return;
        }
        for (const auto& [name, g] : grades) {
            cout << "- " << name << ": " << g.score << " (Weight: " << g.weight << ")\n";
        }
    }

    void addOrUpdate(const string& name, float score, float weight) {
        grades[name] = {score, weight};
    }

    bool remove(const string& name) {
        return grades.erase(name) > 0;
    }

    float calculateAverage() const {
        if (grades.empty()) return 0.0f;
        float total = 0;
        for (const auto& [name, g] : grades) {
            total += g.score * g.weight;
        }
        return total;
    }
};

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
    GradeManager dmt;
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
            
            dmt.addOrUpdate(name, g, w);
        } else if (choice == "show") {
            dmt.showGrades();
        } else if (choice == "delete") {
            string name;
            cout << "Assignment name: ";
            cin.ignore();
            std::getline(cin, name); 
            dmt.remove(name);
        } else if (choice == "average") {
            cout << "Current Average: " << dmt.calculateAverage() << "\n";
        } else if (choice == "quit") {
            break;
        }
    }
    return 0;
}
