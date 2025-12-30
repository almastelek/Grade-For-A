#ifndef GRADEMANAGER_H
#define GRADEMANAGER_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

struct Grade {
    float score;
    float weight;
};

class GradeManager {
private:
    std::unordered_map<std::string, Grade> grades;

public:
    GradeManager() = default;

    void showGrades() const;

    void addOrUpdate(const std::string& name, float score, float weight);

    bool remove(const std::string& name);

    float calculateAverage() const;

    const std::unordered_map<std::string, Grade>& getGrades() const;
};

#endif // GRADE_MANAGER_H