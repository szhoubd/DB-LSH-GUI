////
//// impressionist.cpp
////
//// The main driver program for the other parts. We have two major components,
//// UI and Doc.
//// They do have a link to each other as their member such that they can 
//// communicate.
////
//
//#include <stdio.h>
//
//#include <FL/Fl.h>
//#include <FL/Fl_Window.H>
//#include <FL/Fl_Box.H>
//
//#include "impressionistUI.h"
//#include "impressionistDoc.h"
//
//#include <iostream>
//#include <fstream>
//#include "Preprocess.h"
//#include "dblsh.h"
//#include "Query.h"
//#include <time.h>
//#include "basis.h"
//ImpressionistUI* impUI;
//ImpressionistDoc* impDoc;
//void lshknn(float c, int k, Hash& myslsh, Preprocess& prep, float beta, std::string& datasetName, std::string& data_fold);
//void expe_k(float c, Hash& myslsh, Preprocess& prep, float beta, std::string& datasetName, std::string& data_fold);
//void cb_void(Fl_Menu_* o, void* v)
//{
//}
//
//
//
//    int main(int	argc,
//        char** argv) {
//		impDoc = new ImpressionistDoc();
//		impUI = new ImpressionistUI();
//		impUI->setDocument(impDoc);
//		impDoc->setUI(impUI);
//
//		Fl::visual(FL_DOUBLE | FL_INDEX);
//
//		impUI->show();
//
//		return Fl::run();
//    }
//
//// global functions
//float frand()
//{
//	return (float)rand() / RAND_MAX;
//}
//
//int irand(int max)
//{
//	return rand() % max;
//}
