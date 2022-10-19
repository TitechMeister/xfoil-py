#ifndef LIB_FOIL_H
#define LIB_FOIL_H

#include "core/xfoil.hpp"
#include <map>
#include <vector>

using namespace std;

class XF{
	public:
		XF();
		int Load(string filename,bool primary);
		void interpolate(double rate);
		void iter(int n);
		void tegap(double val);
		map<string,double> calc(double alpha,double Re);
		vector<double> getX()const;
		vector<double> getY()const;
		tuple<vector<double>,vector<double>> cpv(double alpha,double Re);
		int save(string filename)const;
	private:
		double x1[IBX],x2[IBX],y1[IBX],y2[IBX];
		int n1=0,n2=0;
		bool iterate();
		double Re=500000;
		double interpolate_rate=0.5;
		XFoil* xf;
		// m_InitBL:境界層の影響を評価するかどうか
		bool m_bInitBL=false;
		// m_InitBL:境界層の影響を評価するかどうか
		bool m_Viscous=true;
};

#endif
