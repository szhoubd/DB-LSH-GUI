// PM_LSH.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>

#include <FL/Fl.h>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include "impressionistUI.h"
#include "impressionistDoc.h"

ImpressionistUI* impUI;
ImpressionistDoc* impDoc;

#include <iostream>
#include <fstream>
#include "Preprocess.h"
#include "dblsh.h"
#include "Query.h"
#include <time.h>
#include "basis.h"

void lshknn(float c, int k, Hash& myslsh, Preprocess& prep, float beta, std::string& datasetName, std::string& data_fold, std::stringstream& ss);
void expe_k(float c, Hash& myslsh, Preprocess& prep, float beta, std::string& datasetName, std::string& data_fold);
void querry(ImpressionistUI* impUI){
	float c = impUI->c;
	unsigned k = impUI->k;
	unsigned L = impUI->L, K = impUI->K;//NUS
	
	float beta = impUI->beta;
	unsigned Qnum = 100;
	float R_min = impUI->Rmin;

	const std::string datas[] = { "audio","mnist","cifar","NUS","Trevi","gist","deep1m" };
	std::string datasetName = datas[0];

	//todo: change parameter from your UI
	//if (argc == 2) {
	//	datasetName = argv[1];
	//	set_rmin(datasetName, R_min);
	//}
	//else if (argc > 2) {
	//	if ((argc < 6 || argc > 8)) {
	//		std::cerr << "Usage: ./dblsh datasetName approx_ratio k L K beta R_min(optinal)\n\n";
	//		exit(-1);
	//	}
	//	datasetName = argv[1];//audio
	//	c = std::atof(argv[2]);   //c=2
	//	k = std::atoi(argv[3]);//50
	//	L = std::atoi(argv[4]);//5
	//	K = std::atoi(argv[5]);//10
	//	beta = std::atof(argv[6]);//0.1
	//	if (argc == 8) {
	//		R_min = std::atof(argv[7]);//0.3
	//	}
	//	else {
	//		set_rmin(datasetName, R_min);
	//	}
	//}
	//else//only for debug, not advised for user
	//{
	//	//std::cerr << "Usage: ./dblsh datasetName approx_ratio k L K beta R_min(optinal)\n\n";
	//	//exit(-1);

	//	
	//	datasetName = "audio";
	//	set_rmin(datasetName, R_min);
	//	std::cout << "Using the default configuration!\n\n";
	//}


	//todo end

	/// <summary>
	/// Show the configuration
	/// </summary>
	/// <param name="argc"></param>
	/// <param name="argv"></param>
	/// <returns></returns>
	std::stringstream ss;
	ss << "Using DB-LSH for " << datasetName << " ..." << std::endl;
	ss << "c=        " << c << std::endl;
	ss << "k=        " << k << std::endl;
	ss << "L=        " << L << std::endl;
	ss << "K=        " << K << std::endl;
	ss << "beta=     " << beta << std::endl;
	//std::cout << "R_min=    " << R_min << std::endl << std::endl;



#if defined(unix) || defined(__unix__)
	std::string data_fold = "./../dataset/", index_fold = "";
#else
	std::string data_fold = "D:/3311_database_concept/DB-LSH/DB-LSH/dataset/", index_fold = "";
#endif

	Preprocess prep(data_fold + datasetName + ".data", data_fold + "ANN/" + datasetName + ".bench", beta);

	showMemoryInfo();

	Parameter param(prep, L, K, R_min);
	Hash myslsh(prep, param, index_fold.append(datasetName));

	lshknn(c, k, myslsh, prep, beta, datasetName, data_fold, ss);

	//todo: transport ss to UI

	//std::cout << ss;


	impUI->printInfo = ss.str();
	
	//todo end
	
}
int main(int argc, char const* argv[])
{

	impDoc = new ImpressionistDoc();

	// Create the UI
	impUI = new ImpressionistUI();

	// Set the impDoc which is used as the bridge between UI and brushes
	impUI->setDocument(impDoc);
	impDoc->setUI(impUI);

	Fl::visual(FL_DOUBLE | FL_INDEX);

	impUI->show();
	return Fl::run();

	//float c = 1.5;
	//unsigned k = 50;
	//unsigned L = 8, K = 10;//NUS
	//L = 5, K = 10;
	//float beta = 0.1;
	//unsigned Qnum = 100;
	//float R_min = 1.0f;

	//const std::string datas[] = { "audio","mnist","cifar","NUS","Trevi","gist","deep1m" };
	//std::string datasetName = datas[0];

	////todo: change parameter from your UI
	////if (argc == 2) {
	////	datasetName = argv[1];
	////	set_rmin(datasetName, R_min);
	////}
	////else if (argc > 2) {
	////	if ((argc < 6 || argc > 8)) {
	////		std::cerr << "Usage: ./dblsh datasetName approx_ratio k L K beta R_min(optinal)\n\n";
	////		exit(-1);
	////	}
	////	datasetName = argv[1];//audio
	////	c = std::atof(argv[2]);   //c=2
	////	k = std::atoi(argv[3]);//50
	////	L = std::atoi(argv[4]);//5
	////	K = std::atoi(argv[5]);//10
	////	beta = std::atof(argv[6]);//0.1
	////	if (argc == 8) {
	////		R_min = std::atof(argv[7]);//0.3
	////	}
	////	else {
	////		set_rmin(datasetName, R_min);
	////	}
	////}
	////else//only for debug, not advised for user
	////{
	////	//std::cerr << "Usage: ./dblsh datasetName approx_ratio k L K beta R_min(optinal)\n\n";
	////	//exit(-1);

	////	
	////	datasetName = "audio";
	////	set_rmin(datasetName, R_min);
	////	std::cout << "Using the default configuration!\n\n";
	////}

	//
	////todo end

	///// <summary>
	///// Show the configuration
	///// </summary>
	///// <param name="argc"></param>
	///// <param name="argv"></param>
	///// <returns></returns>
	//std::stringstream ss;
	//ss << "Using DB-LSH for " << datasetName << " ..." << std::endl;
	//ss << "c=        " << c << std::endl;
	//ss << "k=        " << k << std::endl;
	//ss << "L=        " << L << std::endl;
	//ss << "K=        " << K << std::endl;
	//ss << "beta=     " << beta << std::endl;
	////std::cout << "R_min=    " << R_min << std::endl << std::endl;

	//

	//#if defined(unix) || defined(__unix__)
	//	std::string data_fold = "./../dataset/", index_fold = "";
	//#else
	//	std::string data_fold = "D:/3311_database_concept/DB-LSH/DB-LSH/dataset/", index_fold = "";
	//#endif

	//Preprocess prep(data_fold + datasetName + ".data", data_fold + "ANN/" + datasetName + ".bench", beta);

	//showMemoryInfo();

	//Parameter param(prep, L, K, R_min);
	//Hash myslsh(prep, param, index_fold.append(datasetName));

	//lshknn(c, k, myslsh, prep, beta, datasetName, data_fold, ss);

	////todo: transport ss to UI

	////std::cout << ss;
	//
	//
	//impUI->printInfo = ss.str();
	//cout << impUI->printInfo;
	////todo end
	//system("pause");
	//return 0;
}

void lshknn(float c, int k, Hash& myslsh, Preprocess& prep, float beta, std::string& datasetName, std::string& data_fold, std::stringstream& ss) {
	lsh::timer timer;
	ss << std::endl << "RUNNING QUERY ..." << std::endl;
	int Qnum = 100;
	lsh::progress_display pd(Qnum);
	Performance perform;
	for (unsigned j = 0; j < Qnum; j++)
	{
		Query query(j, c, k, myslsh, prep, beta);
		perform.update(query, prep);
		++pd;
	}

	//showMemoryInfo();

	float mean_time = (float)perform.time_total / perform.num;
	ss << "AVG QUERY TIME:    " << mean_time * 1000 << "ms." << std::endl << std::endl;
	//std::cout << "SORT TIME:         " << ((float)perform.time_sift) / (perform.num) << std::endl;
	//std::cout << "AVG QUERY TIME:    " << (float)perform.time_verify / perform.num * 1000 << "ms." << std::endl << std::endl;
	ss << "AVG RECALL:        " << ((float)perform.NN_num) / (perform.num * k) << std::endl;
	ss << "AVG RATIO:         " << ((float)perform.ratio) / (perform.res_num) << std::endl;
	ss << "AVG COST:          " << ((float)perform.cost) / ((float)perform.num * prep.data.N) << std::endl;
	ss << "AVG ROUNDS:        " << ((float)perform.rounds) / (perform.num) << std::endl;
	//std::cout << "AVG ACCESSES:      " << ((float)perform.num_access_in_RTree) / (perform.num) << std::endl;
	ss << "\nFINISH... \n\n\n";

	time_t now = std::time(0);
	time_t zero_point = 1635153971;//Let me set the time at 2021.10.25. 17:27 as the zero point
	float date = ((float)(now - zero_point)) / 86400;
	std::ofstream os(data_fold + "DB-LSH_result.csv", std::ios_base::app);
	os.seekp(0, std::ios_base::end); // 移动到文件尾
	int tmp = (int)os.tellp();
	if (tmp == 0) {
		os << "Dataset,c,k,L,K,R_min,RATIO,RECALL,AVG_TIME,COST,DATE" << std::endl;
	}
	std::string dataset = datasetName; 
	os << dataset << ',' << c << ',' << k << ',' << myslsh.L << ',' << myslsh.K << ',' << myslsh.R_min << ','
		<< ((float)perform.ratio) / (perform.res_num) << ','
		<< ((float)perform.NN_num) / (perform.num * k) << ','
		<< mean_time * 1000 << ','
		<< ((float)perform.cost) / (perform.num * prep.data.N) << ','
		<< date << ','
		<< std::endl;
	os.close();
}

void expe_k(float c, Hash& myslsh, Preprocess& prep, float beta, std::string& datasetName, std::string& data_fold) {
	lsh::timer timer;
	std::cout << std::endl << "RUNNING QUERY ..." << std::endl;
	int Qnum = 100;
	lsh::progress_display pd(Qnum);
	

	int k = 100;
	Performance performs[11];
	int Ks[] = { 1,10,20,30,40,50,60,70,80,90,100 };
	for (unsigned j = 0; j < Qnum; j++)
	{
		Query query(j, c, k, myslsh, prep, beta);
		for (int m = 0; m < 11; ++m) {
			query.k = Ks[m];
			performs[m].update(query, prep);
		}
		++pd;
	}

	showMemoryInfo();

	for (int m = 0; m < 11; ++m) {
		Performance perform = performs[m];
		k = Ks[m];
		float mean_time = (float)perform.time_total / perform.num;
		std::cout << "k=                 " << k << std::endl << std::endl;
		std::cout << "AVG QUERY TIME:    " << mean_time * 1000 << "ms." << std::endl << std::endl;
		//std::cout << "SORT TIME:         " << ((float)perform.time_sift) / (perform.num) << std::endl;
		//std::cout << "AVG QUERY TIME:    " << (float)perform.time_verify / perform.num * 1000 << "ms." << std::endl << std::endl;
		std::cout << "AVG RECALL:        " << ((float)perform.NN_num) / (perform.num * k) << std::endl;
		std::cout << "AVG RATIO:         " << ((float)perform.ratio) / (perform.res_num) << std::endl;
		std::cout << "AVG COST:          " << ((float)perform.cost) / ((float)perform.num * prep.data.N) << std::endl;
		std::cout << "AVG ROUNDS:        " << ((float)perform.rounds) / (perform.num) << std::endl;
		std::cout << "\nFINISH... \n\n\n";

		time_t now = std::time(0);
		time_t zero_point = 1635153971;//Let me set the time at 2021.10.25. 17:27 as the zero point
		float date = ((float)(now - zero_point)) / 86400;
		std::ofstream os(data_fold + "ANN/DB-LSH_result.csv", std::ios_base::app);
		os.seekp(0, std::ios_base::end); // 移动到文件尾
		int tmp = (int)os.tellp();
		if (tmp == 0) {
			os << "Dataset,c,k,L,K,R_min,RATIO,RECALL,AVG_TIME,COST,DATE" << std::endl;
		}
		std::string dataset = datasetName;
		os << dataset << ',' << c << ',' << k << ',' << myslsh.L << ',' << myslsh.K << ',' << myslsh.R_min << ','
			<< ((float)perform.ratio) / (perform.res_num) << ','
			<< ((float)perform.NN_num) / (perform.num * k) << ','
			<< mean_time * 1000 << ','
			<< ((float)perform.cost) / (perform.num * prep.data.N) << ','
			<< date << ','
			<< std::endl;
		os.close();
	}
	
}
