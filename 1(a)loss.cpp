#include<iostream>
#include<cmath>
#include<fstream>
#include<vector>

using namespace std;

vector<float> Printer_y;
vector<float> Printer_x;
vector<float> Printer_f;

float f(float x, float y) {
	return 5*y;
}
float rk4Single(float x0, float y0, float y_max, float h)
{

    float k1, k2, k3, k4, k5;
	float y = y0;

		while(y<y_max)
		{
			float yi = y;

			k1 = h*f(x0, y);
			k2 = h*f(x0 + 0.5*h, y + 0.5*k1);
			k3 = h*f(x0 + 0.5*h, y + 0.5*k2);
			k4 = h*f(x0 + h, y + k3);

			y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);;

			x0 = x0 + h;
			Printer_y.push_back(y);
            Printer_x.push_back(x0);
            Printer_f.push_back(f(x0,y));


	}

    return 0;
}

int main()
{
    ofstream outfile;
    outfile.open("1(a)loss.csv");

	float x0 = 0, y = 1, y_max = 50, h = 0.0001;

	rk4Single(x0,y,y_max,h);

    outfile << "y, x, f(x)" << endl;
    for(int i = 0; i < Printer_y.size(); i++){
        outfile << Printer_y[i] <<"," << Printer_x[i] <<","<< Printer_f[i] <<endl;
    }

}