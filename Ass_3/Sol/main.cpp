#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int select, temp = 0;

// Structure to represent a fuzzy set
struct FuzzySet {
    string name;
    string type;
    vector<double> values;
};

// Structure to represent a variable in the fuzzy logic system
struct Variable {
    string name;
    string type;
    vector<double> range;
    vector<FuzzySet> fuzzySets;
};


// Structure to represent a rule in the fuzzy logic system
struct Rule {
    string inVariable1;
    string inSet1;
    string operatorString;
    string inVariable2;
    string inSet2;
    string outVariable;
    string outSet;
};

// Function to add a variable to the fuzzy logic system
void addVariable(vector<Variable>& variables) {

    string input;
    Variable variable;
    cout << "Enter the variable’s name, type (IN/OUT) and range ([lower, upper]):\n"
            "(Press x to finish)\n";
    while (true){
        cin >> input;
        if(input == "x"){ break;}
        else {variable.name = input;}
        cin >> variable.type;
        double lower, upper;
        cin >> lower >> upper;
        variable.range = {lower, upper};
        variables.push_back(variable);
    }
}

// Function to add a fuzzy set to a variable in the fuzzy logic system
void addFuzzySet(vector<Variable>& variables, vector< FuzzySet>& fuzzySet_vector) {
    string variableName;
    cout << "Enter the variable's name: ";
    cin >> variableName;
    auto it = std::find_if(variables.begin(), variables.end(), [&variableName](const Variable& variable) {
        return variable.name == variableName;
    });

    cout << "Enter the fuzzy set name, type (TRI/TRAP) and values: (Press x to finish)\n";
    FuzzySet fuzzySet; string input;
    while (true){
        cin >> input;
        if(input == "x"){ break;}
        else{ fuzzySet.name = input;}
        cin >> fuzzySet.type;
        cout << "fuzzySet.type == " << fuzzySet.type << "\n";
        double value;
        if(fuzzySet.type == "TRI"){
            for (int i = 0; i < 3; ++i) {
                cin >> value; fuzzySet.values.push_back(value);
            }
        }
        else if(fuzzySet.type == "TRAP"){
            for (int i = 0; i < 4; ++i) {
                cin >> value; fuzzySet.values.push_back(value);
            }
        }
        fuzzySet_vector.push_back(fuzzySet);
    }

}

// Function to add a rule to the fuzzy logic system
void addRule(vector<Rule>& rules) {
    Rule rule; string input;

    cout << "Enter the rule in this format: IN_variable set operator IN_variable set => OUT_variable set" << std::endl;
    while (true){
        cin >> input;
        if(input == "x"){ break;}
        else{rule.inVariable1 = input;}
        cin  >> rule.inSet1 >> rule.operatorString >> rule.inVariable2 >> rule.inSet2 >> input >> rule.outVariable >> rule.outSet;
        rules.push_back(rule);
    }
}
void with_separator(const vector<double>& vec,string sep = " ")
{
    // Iterating over all elements of vector
    for (auto elem : vec) {cout << elem << sep;}cout << endl;
}


void setDMS(const vector<Variable>& variables, int projectFund){

    for (Variable variable : variables) {
        cout << variable.name << " " << variable.type ;  with_separator(variable.range, ", ");

    }

//    if(variables[0].fuzzySets[0].type == " ")
//    if (binary_search(verylowProjectFunding.begin(),verylowProjectFunding.end(),projectFund))
//    {degreeMS.insert({"Very low", 1});}
//    if (!binary_search(verylowProjectFunding.begin(),verylowProjectFunding.end(),projectFund))
//    {degreeMS.insert({"Very low",0});}
//    if (binary_search(lowProjectFunding.begin(),lowProjectFunding.end(),projectFund))
//    {degreeMS.insert({"low",1});}
//    if (!binary_search(lowProjectFunding.begin(),lowProjectFunding.end(),projectFund))
//    {degreeMS.insert({"low",0});}
//
//    if (binary_search(mediumProjectFunding.begin(),mediumProjectFunding.end(),projectFund))
//    {degreeMS.insert({"medium",1});}
//    if (!binary_search(mediumProjectFunding.begin(),mediumProjectFunding.end(),projectFund))
//    {degreeMS.insert({"medium",0});}
//
//    if (binary_search(highProjectFunding.begin(),highProjectFunding.end(),projectFund))
//    {degreeMS.insert({"high",1});}
//
//    if (!binary_search(highProjectFunding.begin(),highProjectFunding.end(),projectFund))
//    {degreeMS.insert({"high",0});}
}


// Function to run the simulation on crisp values
void runSimulation(const vector<Variable>& variables, const vector<Rule>& rules) {
    vector<double> crispValues;
    cout << "Enter the crisp values\n";

    int res = variables.size() - 1, i = 0;
    for (const Variable& variable : variables) {
        if(i++==res){ break;}
        double value;
        cout << variable.name << ": "; cin >> value;
        setDMS(variables, value);
        crispValues.push_back(value);
    }

    // Perform fuzzification, inference, and defuzzification
    // (implementation of these steps is omitted for brevity)

   cout << "Running the simulation..." << endl;
   cout << "The predicted output is: ..." << endl;

}

void print_menu(){
    cout << "Main Menu:\n"
            "==========\n"
            "1- Add variables.\n"
            "2- Add fuzzy sets to an existing variable.\n"
            "3- Add rules.\n"
            "4- Run the simulation on crisp values.";
    cin >> select;
}
void print_error(){cout << "CAN’T START THE SIMULATION! Please add the fuzzy sets and rules first.";}



int main() {
//    string input;
//    getline(cin, input);

//    cout << (input[0]) << endl << endl;
    vector<Variable> variables;
    vector<FuzzySet> fuzzySet_vector;
    vector<Rule> rules;

    string system_name,description;
    while (true) {
        cout << "Fuzzy Logic Toolbox\n"
                "===================\n"
                "1- Create a new fuzzy system\n"
                "2- Quit\n"; cin >> select;

        if (select == 1) {
            cout << "Enter the systems name and a brief description\n";
            getline (cin,system_name);
            getline (cin,system_name);
            getline (cin, description);
            getline (cin, description);
            temp = 0;
            while (temp != -1){
                print_menu();
                if (select == 1) {
                    while (select < temp){print_error();cin >> select;}
                    addVariable(variables); temp = select;
                }
                else if (select == 2) {
                    while (select < temp){print_error();cin >> select;}
                    addFuzzySet(variables, fuzzySet_vector); temp = select;
                }
                else if(select == 3){
                    while (select < temp){print_error();cin >> select;}
                    addRule(rules); temp = select;
                }
                else if(select == 4) {
                    while (select < temp)while (select != temp + 1) {print_error();cin >> select;}
                    runSimulation(variables, rules); temp = 0;
                }
            }

        } else if (select == 2)
            return 0;
    }

}
