#include <iostream>
#include <vector>
#include "question.h"
#include "quiz.h"
#include "extractQuestion.h"
#include <unordered_map>
#include <map>

using namespace std;



int main(int argc, char** argv)
{
    if (argc < 2) {

        cout << "Usage: ./revision <question file>" << endl;
        return 1;
    }

    int globalIds = 0;
    ifstream rawQuestions(argv[1]);

    map<int, MCQuestion> mcQuestions;
    map<int, SAQuestion> saQuestions;

    string line;
    while(getline(rawQuestions, line)) {
        stringstream ss(line);
        string questionType;
        ss >> questionType;

        if(questionType == "Multiple") {
            MCQuestion mcQuestion = parseMCQuestion(globalIds++, rawQuestions);
            mcQuestions.insert(std::pair<int, MCQuestion> (globalIds, mcQuestion));
        }
        else if(questionType == "Short") {
            SAQuestion saQuestion = parseSAQuestion(globalIds++, rawQuestions);
            saQuestions.insert(std::pair<int, SAQuestion> (globalIds, saQuestion));
        }
    }

    // vector<string> tags;
    // tags.push_back("Date");
    // tags.push_back("Time");
    // vector<string> posAnswers;
    // posAnswers.push_back("a) Sunday");
    // posAnswers.push_back("b) Monday");
    // posAnswers.push_back("c) Tuesday");

    // MCQuestion test(5, 0, "What is the day today?", "a", tags, posAnswers);

    // mcQuestions.insert(pair<int,MCQuestion> (5, test));
    Quiz quiz(mcQuestions, saQuestions);


    char userChoice{};
    string userBuffer{};
    int quitCheck{0};
    while(!quitCheck) {
        cout << "Choose an option: (e) begin exam; (q) quit\n";
        cin >> userChoice;
        switch(userChoice) {
            case 'q':
                quitCheck = 1;
                cout << "Exiting question practice.\n";
                break;

            case 'e':
                cout << "Begin test\n";
                quiz.test();

                break;
            
            default:
                cout << "Invalid option.\n";
                break;
                        
        }
    }
    rawQuestions.close();
    

    return 0;
}