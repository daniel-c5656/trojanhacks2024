#include "question.h"

using namespace std;

Question::Question() : questionId{totalIds++} {
    // Use OCR here...

}

Question::Question(std::string text) {
    questionText_ = text;
}

Question::~Question() {}

string Question::getQuestionText() const {
    return questionText_;
}

void Question::parseTopics() {
    // Do something with the text to pull out major topics...
    
}

string Question::getAnswer() const {
    return answer_;
}

strVec Question::getTopics() const {
    return topics_;
}