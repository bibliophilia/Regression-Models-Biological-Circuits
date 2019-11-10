#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<fstream>

using namespace std;

vector<float> Printer_s;
vector<float> Printer_y;
vector<float> Printer_x;
vector<float> Printer_f;

float G(float u,float v,float j,float k){
    return (2*u*k)/(v-u+v*j+u*k+sqrt(pow(v-u+v*j+u*k,2)-4*(v-u)*u*k));
}

float f(float x, float y,float s){
	return 0.4*G(y,0.2,0.05,0.05)+0.01*s;
}

void rk4Single(float x0, float y0, float y_max, float h, float s)
{
	float j = x0;
    float k1, k2, k3, k4, k5;
	float y = y0;
	x0 = j;
	while(y<y_max)
	{
		float yi = y;

		k1 = h*f(x0, y, s);
		k2 = h*f(x0 + 0.5*h, y + 0.5*k1, s);
		k3 = h*f(x0 + 0.5*h, y + 0.5*k2, s);
		k4 = h*f(x0 + h, y + k3, s);

		y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);

		x0 = x0 + h;
		Printer_y.push_back(y);
        Printer_x.push_back(x0);
        Printer_f.push_back(f(x0,y,s));
		}
}

int main(){
    ofstream outfile;
    outfile.open("1(e)prod.csv");

	float x0 = 0, y = 0.0001, y_max = 0.999, h = 0.002;
    float s;
    for(int j = 1; j<=5; j++){
        s = j;
        outfile << "for S =" << s << " :" << endl;

        Printer_y.clear();
        Printer_x.clear();
        Printer_f.clear();
        rk4Single(x0,y,y_max,h,s);

        outfile << "y,x,f(x)" << endl;
        for(int i = 0; i < Printer_y.size(); i++){
            outfile << Printer_y[i] << "," << Printer_x[i] << "," <<Printer_f[i] <<endl;
        }
    }
}