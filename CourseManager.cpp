#include "CourseManager.h"

#include <iostream>
#include <string>
#include <unordered_map>

using std::string, std::cout;

const std::unordered_map<std::string, GradeManager>& CourseManager::getCourses() const {
    return courses;
}

void CourseManager::showCourses() {
    if (courses.empty()) {
        std::cout << "No courses recorded.\n";
        return;
    }

    std::cout << "Courses:\n";
    for (const auto& [name, _] : courses) {
        cout << "- " << name << "\n";
    }
};

GradeManager& CourseManager::getOrCreateCourse(const std::string& name) {
        return courses[name];
};

void CourseManager::addCourse(const string& name) {
    courses[name] = GradeManager();
    cout << "Added course: " << name << "\n";
};

void CourseManager::removeCourse(const string& name) {
    if (courses.erase(name) > 0) {
        cout << "Removed course: " << name << "\n";
    } else {
        cout << "Course not found: " << name << "\n";
    }
};

void CourseManager::showCourseGrades(const string& name) {
    if (courses.find(name) == courses.end()) {
        cout << "Course not found: " << name << "\n";
        return;
    }

    cout << "Average: " << courses.at(name).calculateAverage() << "\n";
};