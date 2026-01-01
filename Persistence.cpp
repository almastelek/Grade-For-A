#include "Persistence.h"

#include <fstream>
#include <sstream>
#include "GradeManager.h"

using std::string;

void Persistence::saveToFile(const string& filename, const CourseManager& manager) {
    std::ofstream file(filename);
    // We iterate through the grades and save as CSV: name,score,weight
    for (const auto& [courseName, gradeManager] : manager.getCourses()) {
        for (const auto& [gradeName, grade] : gradeManager.getGrades()) {
            file << courseName << "," << gradeName << "," << grade.score << "," << grade.weight << "\n";
        }
    }
}

void Persistence::loadFromFile(const string& filename, CourseManager& manager) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        string courseName, gradeName, sScore, sWeight;

        if (!std::getline(ss, courseName, ',')) continue;
        if (!std::getline(ss, gradeName, ',')) continue;
        if (!std::getline(ss, sScore, ',')) continue;
        if (!std::getline(ss, sWeight, ',')) continue; // reads rest if no trailing comma

        try {
            float score = std::stof(sScore);
            float weight = std::stof(sWeight);

            GradeManager& course = manager.getOrCreateCourse(courseName);
            course.addOrUpdate(gradeName, score, weight);
        } catch (...) {
            // skip malformed line
            continue;
        }
    }
}