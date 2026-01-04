#include "CourseManager.h"
#include "Persistence.h"

#include <iostream>
#include <string>
#include <limits>

using std::string, std::cin, std::cout;

static void flushLine() {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static string getLineInput(const string& prompt) {
    cout << prompt;
    string s;
    std::getline(cin, s);
    return s;
}

static float getFloatInput(const string& prompt) {
    while (true) {
        cout << prompt;
        string raw;
        std::getline(cin, raw);
        try {
            size_t idx = 0;
            float v = std::stof(raw, &idx);
            while (idx < raw.size() && std::isspace(static_cast<unsigned char>(raw[idx]))) idx++;
            if (idx != raw.size()) throw 1;
            return v;
        } catch (...) {
            cout << "Invalid number. Try again.\n";
        }
    }
}

int main() {
    CourseManager manager;
    Persistence::loadFromFile("grades.csv", manager);

    string currentCourse;

    cout << "Loaded courses:\n";
    manager.showCourses();
    cout << "\n";

    cout << "Commands:\n"
         << "  courses | addcourse | select | removecourse\n"
         << "  add | show | delete | average\n"
         << "  quit\n\n";

    while (true) {
        cout << "[course=" << (currentCourse.empty() ? "(none)" : currentCourse) << "] > ";
        string choice;
        if (!(cin >> choice)) break;
        flushLine();

        if (choice == "courses") {
            manager.showCourses();
        }
        else if (choice == "addcourse") {
            string name = getLineInput("Course name: ");
            if (name.empty()) {
                cout << "Course name cannot be empty.\n";
                continue;
            }
            manager.addCourse(name);
            if (currentCourse.empty()) currentCourse = name;
        }
        else if (choice == "select") {
            string name = getLineInput("Select course: ");
            if (name.empty()) {
                cout << "Course name cannot be empty.\n";
                continue;
            }
            try {
                (void)manager.getOrCreateCourse(name);
                currentCourse = name;
                cout << "Selected: " << currentCourse << "\n";
            } catch (...) {
                cout << "Course not found: " << name << "\n";
            }
        }
        else if (choice == "removecourse") {
            string name = getLineInput("Remove course: ");
            if (name.empty()) {
                cout << "Course name cannot be empty.\n";
                continue;
            }
            manager.removeCourse(name);
            if (currentCourse == name) currentCourse.clear();
        }
        else if (choice == "add" || choice == "show" || choice == "delete" || choice == "average") {
            if (currentCourse.empty()) {
                cout << "No course selected. Use addcourse or select first.\n";
                continue;
            }

            GradeManager* gm = nullptr;
            try {
                gm = &manager.getOrCreateCourse(currentCourse);
            } catch (...) {
                cout << "Selected course no longer exists. Select another.\n";
                currentCourse.clear();
                continue;
            }

            if (choice == "add") {
                string assignment = getLineInput("Assignment name: ");
                if (assignment.empty()) {
                    cout << "Assignment name cannot be empty.\n";
                    continue;
                }
                float score = getFloatInput("Grade: ");
                float weight = getFloatInput("Weight (e.g., 0.25): ");
                gm->addOrUpdate(assignment, score, weight);
            }
            else if (choice == "show") {
                cout << "Course: " << currentCourse << "\n";
                gm->showGrades();
            }
            else if (choice == "delete") {
                string assignment = getLineInput("Assignment name: ");
                if (!gm->remove(assignment)) {
                    cout << "Not found: " << assignment << "\n";
                }
            }
            else if (choice == "average") {
                cout << "Course: " << currentCourse << "\n";
                cout << "Current Average: " << gm->calculateAverage() << "\n";
            }
        }
        else if (choice == "quit") {
            Persistence::saveToFile("grades.csv", manager);
            cout << "Saved. Goodbye!\n";
            break;
        }
        else {
            cout << "Unknown command.\n";
        }
    }

    return 0;
}
