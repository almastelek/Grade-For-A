#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H

#include <iostream>
#include <string>
#include <unordered_map>
#include "GradeManager.h"

class CourseManager {
private:
    std::unordered_map<std::string, GradeManager> courses;

public:
    CourseManager() = default;

    const std::unordered_map<std::string, GradeManager>& getCourses() const;

    GradeManager& getOrCreateCourse(const std::string& name);

    void showCourses();

    void addCourse(const std::string& name);

    void removeCourse(const std::string& name);

    void showCourseGrades(const std::string& name);
};

#endif  //COURSEMANAGER_H