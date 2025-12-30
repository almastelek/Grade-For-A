#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

using std::string, std::unordered_map, std::cout, std::cin, std::stof, std::fixed, std::setprecision;

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
    Class() {}

    void addGrade(string name, float grade, float weight){
        grade_t g;

        g.assignment_name = name;
        g.grade = grade;
        g.weight = weight;

        grades[name] = g;
    }

    void showGrades(){
        cout << fixed << setprecision(4);
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

unordered_map<string, grade_t> Class::grades;

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
            float g = stof(grade), w = stof(weight);
            //
            cout << name << " " << g << " " << w << "\n";
            //

            dmt.addGrade(name, g, w);

            cout << name << " added.\n";

        } else if (input == "show") {

            dmt.showGrades();

        } else if (input == "update") {

            cout << "Input: <name> <grade>\n";
            string name, grade;
            cin >> name >> grade;
            float g = stof(grade);

            dmt.updateGrade(name, g);

            cout << name << " updated to " << g << "\n";

        } else if (input == "delete") {

            cout << "Input: <name>\n";
            string name;
            cin >> name;

            dmt.deleteGrade(name);

            cout << name << " deleted.\n";

        } else if (input == "average") {

            cout << fixed << setprecision(4);
            cout << "Average: " << dmt.calculateAverage() << "\n";

        } else if (input == "quit") {

            break;

        } else {

            cout << "Invalid input\n";

        }
    }

    return 0;
}

// main();