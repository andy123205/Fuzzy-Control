#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

float max(float, float);
float min(float, float);
void Gas_Blur_Infer(int);
void Gas_Deblur(void);

float Gas_NM[] = { 1,0.8,0.6,0.4,0.2,0,0,0,0,0,0 };
float Gas_Z[] = { 0,0,0,0,0,1,0,0,0,0,0 };
float Gas_PM[] = { 0,0,0,0,0,0,0.2,0.4,0.6,0.8,1 };

int Gas_output;
float M_value, M_x, area = 0.0, moment = 0.0;
float u_T;
float u_Gas[11];
//float *u_Gas;


int main()
{
	//u_Gas = (float *)calloc(11, sizeof(float));

	int T = 64;
	Gas_Blur_Infer(T);
	Gas_Deblur();

	printf("T = %d Gas_output = %d\n", T, Gas_output);

	system("pause");

	return 0;
}


float max(float a, float b) {
	float output;
	if (a >= b) {
		output = a;
	}
	else {
		output = b;
	}
	return output;
}

float min(float a, float b) {
	float output;
	if (a >= b) {
		output = b;
	}
	else {
		output = a;
	}
	return output;
}



void Gas_Blur_Infer(int T) {

	/***************RULE1*****************/
	//if T is PM then Gas is NM
	u_T = 0.0;
	//Blur
	if ((T >= 74) && (T <= 86)) {
		u_T = (float)(T - 74) / 12;
	}

	printf("Rule 1:%f\n", u_T);

	//Infer ,use Mamdani Max-min 
	if (u_T != 0.0) {
		for (int i = 0;i<11;i++) {
			u_Gas[i] = max(u_Gas[i], min(u_T, Gas_NM[i]));
		}
	}


	/***************RULE2*****************/
	/*if T is Z then Gas is Z*/
	u_T = 0.0;
	//Blur 
	if ((T >= 60) && (T <= 70)) {
		u_T = (float)(T - 60) / 10;
	}
	else if ((T>70) && (T <= 80)) {
		u_T = (float)(80 - T) / 10;
	}

	printf("Rule 2:%f\n", u_T);

	//Infer ,use Mamdani Max-min 
	if (u_T != 0.0) {
		for (int i = 0;i<11;i++) {
			u_Gas[i] = max(u_Gas[i], min(u_T, Gas_Z[i]));
		}
	}


	/***************RULE3*****************/
	/*if T is NM then Gas is PM*/
	u_T = 0.0;
	//Blur 
	if ((T >= 54) && (T <= 66)) {
		u_T = (float)(66 - T) / 12;
	}

	printf("Rule 3:%f\n", u_T);

	//Infer ,use Mamdani Max-min 
	if (u_T != 0.0) {
		for (int i = 0;i<11;i++) {
			u_Gas[i] = max(u_Gas[i], min(u_T, Gas_PM[i]));
		}
	}


}

void Gas_Deblur() {

	for (int i = 0;i<11;i++) {
		M_value = u_Gas[i];
		printf("i =%2d,M_value = %f\n", i, M_value);
		M_x = -5 + i;
		//area = Sigma u_Gas(x)
		//moment = Sigma x*u_Gas(x)
		area = area + M_value;
		moment = moment + M_x*M_value;
	}

	printf("area = %f, moment = %f\n", area, moment);

	if (area == 0) {
		Gas_output = 5;
	}
	else {
		Gas_output = (int)(moment / area);
	}

	//free(u_Gas);

}