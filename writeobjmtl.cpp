#include "writeobjmtl.h"

WriteOBJMTL::WriteOBJMTL()
{

}


void WriteOBJMTL::WriteOBJFile(string objname, string mtlname, float w_cm, float h_cm, float d_cm,
	std::vector<cv::Point2f> t1, std::vector<cv::Point2f> t2,
	std::vector<cv::Point2f> t3, std::vector<cv::Point2f> t4,
	std::vector<cv::Point2f> t5, std::vector<cv::Point2f> t6)
{
	ofstream outfile;
	outfile.open(objname);

	outfile << "# Blender v2.79 (sub 0) OBJ File: ''" << endl;
	outfile << "# by mionz generator; position arrange in U direction toward normal" << endl;
	outfile << "mtllib " << mtlname.c_str() << endl;
	outfile << "o Cube" << endl;

	outfile << "#1.front vertex position" << endl;
	outfile << "v " << -w_cm << " " << h_cm << " " << d_cm << endl;
	outfile << "v " << -w_cm << " " << -h_cm << " " << d_cm << endl;
	outfile << "v " << w_cm << " " << -h_cm << " " << d_cm << endl;
	outfile << "v " << w_cm << " " << h_cm << " " << d_cm << endl;
	outfile << endl;
	outfile << "#2.back vertex position" << endl;
	outfile << "v " << w_cm << " " << h_cm << " " << -d_cm << endl;
	outfile << "v " << w_cm << " " << -h_cm << " " << -d_cm << endl;
	outfile << "v " << -w_cm << " " << -h_cm << " " << -d_cm << endl;
	outfile << "v " << -w_cm << " " << h_cm << " " << -d_cm << endl;
	outfile << endl;
	outfile << "#3.left vertex position" << endl;
	outfile << "v " << -w_cm << " " << h_cm << " " << -d_cm << endl;
	outfile << "v " << -w_cm << " " << -h_cm << " " << -d_cm << endl;
	outfile << "v " << -w_cm << " " << -h_cm << " " << d_cm << endl;
	outfile << "v " << -w_cm << " " << h_cm << " " << d_cm << endl;
	outfile << endl;
	outfile << "#4.right vertex position" << endl;
	outfile << "v " << w_cm << " " << h_cm << " " << d_cm << endl;
	outfile << "v " << w_cm << " " << -h_cm << " " << d_cm << endl;
	outfile << "v " << w_cm << " " << -h_cm << " " << -d_cm << endl;
	outfile << "v " << w_cm << " " << h_cm << " " << -d_cm << endl;
	outfile << endl;
	outfile << "#5.top vertex position" << endl;
	outfile << "v " << -w_cm << " " << h_cm << " " << -d_cm << endl;
	outfile << "v " << -w_cm << " " << h_cm << " " << d_cm << endl;
	outfile << "v " << w_cm << " " << h_cm << " " << d_cm << endl;
	outfile << "v " << w_cm << " " << h_cm << " " << -d_cm << endl;
	outfile << endl;
	outfile << "#6.bottom vertex position" << endl;
	outfile << "v " << -w_cm << " " << -h_cm << " " << d_cm << endl;
	outfile << "v " << -w_cm << " " << -h_cm << " " << -d_cm << endl;
	outfile << "v " << w_cm << " " << -h_cm << " " << -d_cm << endl;
	outfile << "v " << w_cm << " " << -h_cm << " " << d_cm << endl;
	outfile << endl;


	outfile << "#1.front texture position" << endl;
	outfile << "vt " << t1[0].x << " " << t1[0].y << endl;
	outfile << "vt " << t1[1].x << " " << t1[1].y << endl;
	outfile << "vt " << t1[2].x << " " << t1[2].y << endl;
	outfile << "vt " << t1[3].x << " " << t1[3].y << endl;
	outfile << endl;
	outfile << "#2.back texture position" << endl;
	outfile << "vt " << t2[0].x << " " << t2[0].y << endl;
	outfile << "vt " << t2[1].x << " " << t2[1].y << endl;
	outfile << "vt " << t2[2].x << " " << t2[2].y << endl;
	outfile << "vt " << t2[3].x << " " << t2[3].y << endl;
	outfile << endl;
	outfile << "#3.left texture position" << endl;
	outfile << "vt " << t3[0].x << " " << t3[0].y << endl;
	outfile << "vt " << t3[1].x << " " << t3[1].y << endl;
	outfile << "vt " << t3[2].x << " " << t3[2].y << endl;
	outfile << "vt " << t3[3].x << " " << t3[3].y << endl;
	outfile << endl;
	outfile << "#4.right texture position" << endl;
	outfile << "vt " << t4[0].x << " " << t4[0].y << endl;
	outfile << "vt " << t4[1].x << " " << t4[1].y << endl;
	outfile << "vt " << t4[2].x << " " << t4[2].y << endl;
	outfile << "vt " << t4[3].x << " " << t4[3].y << endl;
	outfile << endl;
	outfile << "#5.top texture position" << endl;
	outfile << "vt " << t5[0].x << " " << t5[0].y << endl;
	outfile << "vt " << t5[1].x << " " << t5[1].y << endl;
	outfile << "vt " << t5[2].x << " " << t5[2].y << endl;
	outfile << "vt " << t5[3].x << " " << t5[3].y << endl;
	outfile << endl;
	outfile << "#6.bottom texture position" << endl;
	outfile << "vt " << t6[0].x << " " << t6[0].y << endl;
	outfile << "vt " << t6[1].x << " " << t6[1].y << endl;
	outfile << "vt " << t6[2].x << " " << t6[2].y << endl;
	outfile << "vt " << t6[3].x << " " << t6[3].y << endl;
	outfile << endl;

	outfile << "#1.front normal " << endl;
	outfile << "vn 0.0000 0.0000 1.0000" << endl;
	outfile << "vn 0.0000 0.0000 1.0000" << endl;
	outfile << "vn 0.0000 0.0000 1.0000" << endl;
	outfile << "vn 0.0000 0.0000 1.0000" << endl;
	outfile << endl;
	outfile << "#2.back normal " << endl;
	outfile << "vn 0.0000 0.0000 -1.0000" << endl;
	outfile << "vn 0.0000 0.0000 -1.0000" << endl;
	outfile << "vn 0.0000 0.0000 -1.0000" << endl;
	outfile << "vn 0.0000 0.0000 -1.0000" << endl;
	outfile << endl;
	outfile << "#3.left normal " << endl;
	outfile << "vn -1.0000 0.0000 0.0000" << endl;
	outfile << "vn -1.0000 0.0000 0.0000" << endl;
	outfile << "vn -1.0000 0.0000 0.0000" << endl;
	outfile << "vn -1.0000 0.0000 0.0000" << endl;
	outfile << endl;
	outfile << "#4.right normal " << endl;
	outfile << "vn 1.0000 0.0000 0.0000" << endl;
	outfile << "vn 1.0000 0.0000 0.0000" << endl;
	outfile << "vn 1.0000 0.0000 0.0000" << endl;
	outfile << "vn 1.0000 0.0000 0.0000" << endl;
	outfile << endl;
	outfile << "#5.top normal " << endl;
	outfile << "vn 0.0000 1.0000 0.0000" << endl;
	outfile << "vn 0.0000 1.0000 0.0000" << endl;
	outfile << "vn 0.0000 1.0000 0.0000" << endl;
	outfile << "vn 0.0000 1.0000 0.0000" << endl;
	outfile << endl;
	outfile << "#6.bottom normal " << endl;
	outfile << "vn 0.0000 -1.0000 0.0000" << endl;
	outfile << "vn 0.0000 -1.0000 0.0000" << endl;
	outfile << "vn 0.0000 -1.0000 0.0000" << endl;
	outfile << "vn 0.0000 -1.0000 0.0000" << endl;
	outfile << endl;

	outfile << "usemtl Material" << endl;
	outfile << "s off" << endl;
	outfile << "f 1/1/1 2/2/2 3/3/3 4/4/4" << endl;
	outfile << "f 5/5/5 6/6/6 7/7/7 8/8/8" << endl;
	outfile << "f 9/9/9 10/10/10 11/11/11 12/12/12" << endl;
	outfile << "f 13/13/13 14/14/14 15/15/15 16/16/16" << endl;
	outfile << "f 17/17/17 18/18/18 19/19/19 20/20/20" << endl;
	outfile << "f 21/21/21 22/22/22 23/23/23 24/24/24" << endl;

	//outfile << "v " << w_cm << " " << h_cm << " " << d_cm << endl;

	outfile.close();

}
void WriteOBJMTL::WriteMTLFile(string mtlname, string pngname)
{
	ofstream outfile;
	outfile.open(mtlname);
	
	outfile << "# Blender MTL File: 'None'" << endl;
	outfile << "# Material Count : 1"<< endl;
	outfile <<  endl;
	outfile << "newmtl Material" << endl;
	outfile << "Ns 96.078431" << endl;
	outfile << "Ka 1.000000 1.000000 1.000000" << endl;
	outfile << "Kd 0.640000 0.640000 0.640000" << endl;
	outfile << "Ks 0.500000 0.500000 0.500000" << endl;
	outfile << "Ke 0.000000 0.000000 0.000000" << endl;
	outfile << "Ni 1.000000" << endl;
	outfile << "d 1.000000" << endl;
	outfile << "illum 2" << endl;
	outfile << "map_Kd " << pngname.c_str() << endl;

	outfile.close();
}