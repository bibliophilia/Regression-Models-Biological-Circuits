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

float f(float x, float y,float s){
    return 0.01+1*s;

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
    outfile.open("1(a)prod.csv");

	float x0 = 0, y = 1, y_max = 50, h = 0.01;
    float s;
    for(int i = 1; i<=5; i++){
        s = i;
        outfile << "for S =" << s << " :" << endl;
        Printer_f.clear();
        Printer_x.clear();
        Printer_y.clear();
        rk4Single(x0,y,y_max,h,s);

        outfile << "y, x, f(x)" << endl;
        for(int i = 0; i < Printer_y.size(); i++){
            outfile << Printer_y[i] <<","<<Printer_x[i] <<","<<Printer_f[i] <<endl;
        }
    }
}