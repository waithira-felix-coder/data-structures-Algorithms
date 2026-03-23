// Gets value of the radius from user calculates the area of the circle

#include<iostream>
using namespace std;
#define PI 3.142
int main()
{
	int RADIUS;
	float area;
	cout<<"Enter radius:";
	cin>>RADIUS;
    area=PI*RADIUS*RADIUS;
    cout<<area;
	return 0;
}