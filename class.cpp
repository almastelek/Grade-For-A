#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using std::string, std::unordered_map, std::cout;

struct grade_t 
{
    string assignment_name;
    int grade;
    int weight;
};

class Class
{
static unordered_map<string, grade_t> grades;

public:
    Class();

    void addGrade(string name, int grade, int weight){
        grade_t g;

        g.assignment_name = name;
        g.grade = grade;
        g.weight = weight;

        grades[name] = g;
    }

    void showGrades(){
        for (const auto& [name, g] : grades){
            cout << name << " " << g.grade << " " << g.weight << "\n";
        }
    }

    void updateGrade(string name, int grade){
        grades[name].grade = grade;
    }

    void deleteGrade(string name){
        grades.erase(name);
    }

    void calculateAverage(){
        int total = 0;
        for (const auto& [name, g] : grades){
            total += g.grade * g.weight;
        }
    }
    
};