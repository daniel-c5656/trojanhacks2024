#include "question.h"
#include <iostream>

using namespace std;

/*
example MC question stored in file
<id (int)>`<question type (int)>`<question body (string)>`<answer options(vec string)>`<answer (char)>`<tags (vec string)>

example SA question stored in file
<id (int)>`<question type (int)>`<question body (string)>`<explanation (string)>`<answer (string)>`<tags (vec string)>
*/

// Question::globalIds_ = 0;

Question::Question() {}

Question::Question(int id, int type, string questionBody, string correctAns, vector<string> tags) :
    id_(id), type_(type), questionBody_(questionBody), correctAns_(correctAns), tags_(tags)
{
    // type_ = type;
    // questionBody_ = questionBody;
    // correctAns_ = correctAns;
    // tags_ = tags;
}

Question::~Question() {}

bool MCQuestion::isCorrect(string ans) {
    return ans == correctAns_;
}

bool SAQuestion::isCorrect(string ans, int questionID) {

    system("clear");
    // cout << "Question " << questionID << " explanation: " << correctAns_ << endl;
    cout << questionID << " explanation: " << correctAns_ << endl;
    cout << "You answered: " << ans << endl;
    cout << "Be honest with yourself: Did you get this question right? (y/n) ";
    char input;
    cin >> input;
    if(input == 'y' || input == 'Y') {
        // cout << "SAQ isCorrect" << endl;
        return true;
    }
    return false;
}

string Question::getQuestionBody() {

    return questionBody_;
}

SAQuestion::SAQuestion(int id, int type, string questionBody, string correctAns, vector<string> tags)
    : Question(id, type, questionBody, correctAns, tags)
{
       
}

MCQuestion::MCQuestion(int id, int type, string questionBody, string correctAns, vector<string> tags, vector<string> possibleAnswers) 
    : Question(id, type, questionBody, correctAns, tags), possibleAnswers_(possibleAnswers)
{

}