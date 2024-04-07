#include "paper.h"
#include <iostream>

using namespace std;

Paper::Paper() {

}

Paper::Paper(int count) {


}

void Paper::addQuestion(int qID) {

    questionIDs_.push_back(qID);
}


void Paper::printPaper() const {

    for (unsigned int i=0; i < questions_.size(); i++)
    {
        cout << questions_[i].getQuestionText() << endl;
    }
}