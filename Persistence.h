#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <fstream>
#include <sstream>
#include "GradeManager.h"
#include "CourseManager.h"

class Persistence {
public:
    static void saveToFile(const std::string& filename, const CourseManager& manager);

    static void loadFromFile(const std::string& filename, CourseManager& manager);
};

#endif // PERSISTENCE_H