#include "question.h"

using namespace std;

/*
example MC question stored in file
<id (int)>`<question type (int)>`<question body (string)>`<answer options(vec string)>`<answer (char)>`<tags (vec string)>

example SA question stored in file
<id (int)>`<question type (int)>`<question body (string)>`<explanation (string)>`<answer (string)>`<tags (vec string)>

```````````````````````````````````````````````````````````````````
Multiple Choice
Would this code have a memory error: vector<int> a; a[0] = 5;

a) Yes
b) No
Answer: 
a
Tags: vectors, memory

Short Answer
Explain how to allocate an array of variable size in C++ in words.
Answers:
dynamic allocation
Tags: arrays, dynamic allocation
``````````````````````````````````````````````````````````````````
*/

// main.cpp will identify the type, then call parseMC/SAQuestion accordingly

MCQuestion parseMCQuestion(int id, ifstream &ifile) {
    // ifstream ifile(fileName);
    string line, questionBody, correctAns;
    vector<string> possibleAnswers, tags;

    // Assume the first line has been read and determined it's a MC question
    getline(ifile, questionBody); // Read the question body

    // Read possible answers until "Answer: "
    while (getline(ifile, line) && line != "Answer:") {
        possibleAnswers.push_back(line);
    }

    // Next line after "Answer:" is the correct answer
    getline(ifile, correctAns);

    // Read until "Tags:"
    while (getline(ifile, line) && line != "Tags:");

    // Remaining lines are tags, split by spaces or some delimiter
    getline(ifile, line); // Read the line containing tags
    stringstream ss(line);
    string tag;
    while(getline(ss, tag, ','))
        tags.push_back((tag));

    MCQuestion ret_question(id, 0, questionBody, correctAns, tags, possibleAnswers);
    return ret_question;
}

SAQuestion parseSAQuestion(int id, ifstream &ifile) {
    // ifstream ifile(fileName);
    string line, questionBody, correctAns;
    vector<string> tags;

    // Assume the first line has been read and determined it's a SA question
    getline(ifile, questionBody); // Read the question body

    // Skip to "Answer:"
    while (getline(ifile, line) && line != "Answer:");

    // Next line after "Answers:" is the correct answer
    getline(ifile, correctAns);

    // Read until "Tags:"
    while (getline(ifile, line) && line != "Tags:");

    // Remaining lines are tags, split by spaces or some delimiter
    getline(ifile, line); // Read the line containing tags
    stringstream ss(line);
    string tag;
    while(getline(ss, tag, ','))
        tags.push_back((tag));

    SAQuestion ret_question(id, 1, questionBody, correctAns, tags);
    return ret_question;
}


/*
Question extractQuestion(ifstream inStream, int questionId) {
    inStream.seekg(questionId, inStream.beg);   // seek to question in DB file
    string line{getline(inStream)}, buffer;     // extract question as string
    
    stringstream ss;
    int id{getline(ss, buffer, '`')};
    int type{getline(ss, buffer, '`')};
    string questionBody{getline(ss, buffer, '`')};
    if(!type) {                                 // create multiple choice question

    } else {                                    // create short answer question
        string correctAnswer{getline(ss, buffer, '`')};
        string tags{getline(ss, buffer, '`')};
    }
}
*/
/*
void parseQuestion(string fileName) {
    ifstream ifile(fileName);
    string line, oneWordBuffer, questionBody, correctAns;
    vector<string> possibleAnswers;
    int type;
    vector<string> tags;

    getline(ifile, line);


    // stringstream ss(oneWordBuffer);
    // getline(ss, oneWordBuffer, '`');

    stringstream ss(line);
    ss >> oneWordBuffer;
    ss.clear();

    if(oneWordBuffer == "Multiple") {
        type = 0;
    }
    else if(oneWordBuffer == "Short") {
        type = 1;
    }

    getline(ifile, line);
    getline(ifile, questionBody);

    getline(ifile, line);
    if(type == 0) { // MCQ
        getline(ifile, line);
        ss(line);
        while(ss >> oneWordBuffer && oneWordBuffer != "Answer") {
            possibleAnswers.push_back(line);
        }
        getline(ifile, line);
        getline(ifile, line);
        line >> correctAns;
    }
    else { // SAQ
        getline(ifile, line); // "Answer: "
        getline(ifile, line);
        getline(ifile, line); // actual answer
        line >> correctAns;
    }

    // now tags part
    getline(ifile, line);
    getline(ifile, line, "Tags:"); // Tags: ...
    getline(ifile, line) // actual keywords
    ss.clear();
    ss(line);
    while(ss >> oneWordBuffer) {
        tags.push_back(oneWordBuffer);
    }
}
*/