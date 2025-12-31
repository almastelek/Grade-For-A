#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <fstream>
#include <sstream>
#include "GradeManager.h"

class Persistence {
public:
    static void saveToFile(const std::string& filename, const GradeManager& manager);

    static void loadFromFile(const std::string& filename, GradeManager& manager);
};

#endif // PERSISTENCE_H