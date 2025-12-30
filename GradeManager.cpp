#include "GradeManager.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

using std::string, std::unordered_map, std::cout, std::cin, std::fixed, std::setprecision;

void GradeManager::showGrades() const {
    cout << fixed << setprecision(2);
    if (grades.empty()) {
        cout << "No grades recorded.\n";
        return;
    }
    for (const auto& [name, g] : grades) {
        cout << "- " << name << ": " << g.score << " (Weight: " << g.weight << ")\n";
    }
}

void GradeManager::addOrUpdate(const string& name, float score, float weight) {
    grades[name] = {score, weight};
}

bool GradeManager::remove(const string& name) {
    return grades.erase(name) > 0;
}

float GradeManager::calculateAverage() const {
    if (grades.empty()) return 0.0f;
    float total = 0;
    for (const auto& [name, g] : grades) {
        total += g.score * g.weight;
    }
    return total;
}

const unordered_map<string, Grade>& GradeManager::getGrades() const {
    return grades;
}