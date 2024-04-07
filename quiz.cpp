#include "quiz.h"
#include "question.h"

#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

Quiz::Quiz(std::map<int, MCQuestion>& mcQuestions, std::map<int, SAQuestion>& saQuestions) :
mcQuestions_(mcQuestions), saQuestions_(saQuestions)
{
    correct_ = 0;
    percentCorrect_ = 0;
    saAnswers_ = vector<string>();
    mcAnswers_ = vector<string>();
}

Quiz::~Quiz() {}

void Quiz::mark() {
    map<int, MCQuestion>::iterator mcIt;
    map<int, SAQuestion>::iterator saIt;
    // vector<int> SAQuestionNum;

    int answer = 0;
    // int questionNum = 0;

    for (mcIt=mcQuestions_.begin(); mcIt != mcQuestions_.end(); mcIt++) {

        if (mcIt->second.isCorrect(mcAnswers_[static_cast<size_t>(answer)])) {
            correct_++;
            cout<<"MCQ correct"<<endl;
        } else {

            for (size_t j=0; j < mcIt->second.tags_.size(); j++) {

                map<string, int>::iterator wrongAnsIt;
                wrongAnsIt = wrongAnswerTags_.find(mcIt->second.tags_[j]);

                if (wrongAnsIt == wrongAnswerTags_.end()) {

                    wrongAnswerTags_.insert(pair<string, int> (mcIt->second.tags_[j], 1));

                } else {
                    wrongAnswerTags_[mcIt->second.tags_[j]]++;
                }
            }
        }
        answer++;
        // questionNum++;
    }
    answer = 0;
    for (saIt=saQuestions_.begin(); saIt != saQuestions_.end(); saIt++) {

        if (saIt->second.isCorrect(saAnswers_[static_cast<size_t>(answer)], saIt->first)) {
            correct_++;
            // cout<<"SAQ correct"<<endl;
        } else {

            for (size_t j=0; j < saIt->second.tags_.size(); j++) {

                map<string, int>::iterator wrongAnsIt;
                wrongAnsIt = wrongAnswerTags_.find(saIt->second.tags_[j]);

                if (wrongAnsIt == wrongAnswerTags_.end()) {

                    wrongAnswerTags_.insert(pair<string, int> (saIt->second.tags_[j], 1));

                } else {
                    wrongAnswerTags_[saIt->second.tags_[j]]++;
                }
            }
        }
        // questionNum++;
        // SAQuestionNum.push_back(questionNum);
        answer++;
    }

    percentCorrect_ = (double) correct_ / (int) (mcQuestions_.size() + saQuestions_.size());
    system("clear");
}


void Quiz::test() {

    system("clear");
    map<int, MCQuestion>::iterator mcIt;
    map<int, SAQuestion>::iterator saIt;
    
    for (mcIt = mcQuestions_.begin(); mcIt != mcQuestions_.end(); mcIt++) {
        cout << "QUESTION " << mcIt->first << endl;
        cout << mcIt->second.getQuestionBody() << endl;
        cout << "Options: " << endl;
        for (size_t i=0; i < mcIt->second.possibleAnswers_.size(); i++){
            cout << mcIt->second.possibleAnswers_[i] << endl;
        }

        cout << "Your answer: ";
        
        string ans;
        cin >> ans;

        mcAnswers_.push_back(ans);

        system("clear");
    }
    for (saIt = saQuestions_.begin(); saIt != saQuestions_.end(); saIt++) {
        cout << "QUESTION " << saIt->first << endl;
        cout << saIt->second.getQuestionBody() << endl;

        cout << "Your answer: ";
        
        string ans;
        
        cin.ignore();
        getline(cin, ans);

        saAnswers_.push_back(ans);

        system("clear");
    }
    mark();
    cout << "Test complete!" << endl;
    cout << "Questions answered: " << mcQuestions_.size() + saQuestions_.size() << endl;
    cout << "Questions correct: " << correct_ << endl;
    cout << "Percentage: " << setw(2) << percentCorrect_ * 100.0 << '%' << endl;
    printInsights();

}

void Quiz::printInsights() {

    map<string, int>::iterator it = wrongAnswerTags_.begin();

    cout << "Errors by tag: " << endl;
    while (it != wrongAnswerTags_.end()) {

        cout << it->first << ": " << it->second << endl;
        ++it;
    }

}

