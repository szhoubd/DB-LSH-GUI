
#include <iostream>
#include <fstream>
#include "Preprocess.h"
#include "dblsh.h"
#include "Query.h"
#include <time.h>
#include "basis.h"
#include "impressionistUI.h"
#include "impressionistDoc.h"
void lshknn(float c, int k, Hash& myslsh, Preprocess& prep, float beta, std::string& datasetName, std::string& data_fold, std::stringstream& ss);
void expe_k(float c, Hash& myslsh, Preprocess& prep, float beta, std::string& datasetName, std::string& data_fold);
void querry(ImpressionistUI* impUI);
void expe_k(float c, Hash& myslsh, Preprocess& prep, float beta, std::string& datasetName, std::string& data_fold);
#pragma once
