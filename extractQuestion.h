#pragma once

#include "question.h"
#include "quiz.h"
#include <fstream>

MCQuestion parseMCQuestion(int id, std::ifstream &ifile);

SAQuestion parseSAQuestion(int id, std::ifstream &ifile);