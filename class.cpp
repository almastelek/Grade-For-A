#include <_stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

using std::string, std::unordered_map, std::cout, std::cin, std::stoi, std::fixed, std::setprecision;

struct grade_t 
{
    string assignment_name;
    float grade;
    float weight;
};

class Class
{
static unordered_map<string, grade_t> grades;

public:
    Class();

    void addGrade(string name, float grade, float weight){
        grade_t g;

        g.assignment_name = name;
        g.grade = grade;
        g.weight = weight;

        grades[name] = g;
    }

    void showGrades(){
        std::cout << std::fixed << std::setprecision(4);
        for (const auto& [name, g] : grades){
            cout << name << " " << g.grade << " " << g.weight << "\n";
        }
    }

    void updateGrade(string name, float grade){
        grades[name].grade = grade;
    }

    void deleteGrade(string name){
        grades.erase(name);
    }

    float calculateAverage(){
        float total = 0;
        for (const auto& [name, g] : grades){
            total += g.grade * g.weight;
        }
        return total;
    }
    
};

int main(){
    Class dmt = Class();

    string input;

    while (1){
        cout << "Select: <add>, <show>, <update>, <delete>, <average>, <quit>\n";
        cin >> input;

        if (input == "add") {

            cout << "Input: <name> <grade> <weight>\n";
            string name, grade, weight;
            cin >> name >> grade >> weight;
            int g = stoi(grade), w = stoi(weight);

            dmt.addGrade(name, g, w);

            cout << name << " added.\n";
            break;

        } else if (input == "show") {

            dmt.showGrades();

        } else if (input == "update") {

            cout << "Input: <name> <grade>\n";
            string name, grade;
            cin >> name >> grade;
            int g = stoi(grade);

            dmt.updateGrade(name, g);

            cout << name << " updated to " << g << "\n";
            break;

        } else if (input == "delete") {

            cout << "Input: <name>\n";
            string name;
            cin >> name;

            dmt.deleteGrade(name);

            cout << name << " deleted.\n";
            break;

        } else if (input == "average") {

            std::cout << std::fixed << std::setprecision(4);
            cout << "Average: " << dmt.calculateAverage() << "\n";
            break;

        } else if (input == "quit") {
            break;
        } else {
            cout << "Invalid input\n";
        }
    }

    return 0;
}