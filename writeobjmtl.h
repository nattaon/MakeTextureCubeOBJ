#ifndef WRITEOBJMTL_H
#define WRITEOBJMTL_H

#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

class WriteOBJMTL
{
public:
    WriteOBJMTL();

	void WriteOBJFile(std::string objname, std::string mtlname, 
		float w_cm, float h_cm, float d_cm,
		std::vector<cv::Point2f> t1, std::vector<cv::Point2f> t2, 
		std::vector<cv::Point2f> t3, std::vector<cv::Point2f> t4,
		std::vector<cv::Point2f> t5, std::vector<cv::Point2f> t6);
	void WriteMTLFile(std::string mtlname, std::string pngname);

};

#endif // WRITEOBJMTL_H