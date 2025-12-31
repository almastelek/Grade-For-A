#include "Persistence.h"

#include <fstream>
#include <sstream>
#include "GradeManager.h"

void Persistence::saveToFile(const std::string& filename, const GradeManager& manager) {
    std::ofstream file(filename);
    // We iterate through the grades and save as CSV: name,score,weight
    for (const auto& [name, g] : manager.getGrades()) {
        file << name << "," << g.score << "," << g.weight << "\n";
    }
}

void Persistence::loadFromFile(const std::string& filename, GradeManager& manager) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, sScore, sWeight;

        if (std::getline(ss, name, ',') && 
            std::getline(ss, sScore, ',') && 
            std::getline(ss, sWeight, ',')) {
            manager.addOrUpdate(name, std::stof(sScore), std::stof(sWeight));
        }
    }
}