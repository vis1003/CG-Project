#include<iostream>
#include<string>
#include <windows.h>
#include<math.h>
#include "GL/glut.h"
using namespace std;

float M_C[] = { 0.52940, 0.80780, 0.9800 };
float N_C[] = { 0.0784,0.0941,0.32156 };

int B_H = 1; // Start Position Of bird
int S = 0; // Start Condition
int D = 7; // Distance between two Poles
int PX[4]; // Poles position X
int PY[4]; // Poles position Y
int A[4]; // Random pole Gap
int F_C = 0; // Fly Sequence
int P_G = 3; // POLE GAPS
int Score = 0; // Score
float Col[3];
float Diff[3];
int SR = 8;
float theta = 0;
int SR_X = -8;
int SR_Y = 0;
int C = 0;
int T = 0;
bool Back_COl = 0;
float WC[] = { 0.67843, 0.8470, 0.9019 };
float WB[] = { 0.67843, 0.8470, 0.9019 };
float WY[] = { 1.0, 1.0, 0.0 };

void Jump(int btn, int state, int x, int y);
void display();

void Circle(float X, float Y, float r, int S, int Q)
{
	glBegin(GL_POLYGON);
	for (int i = S; i < Q; i++) {
		float th = i * 3.142 / 180;
		glVertex2f(X + r * cos(th), Y + r * sin(th));
	}
	glEnd();
}

void Flap(float Y)
{
	if (F_C == 0)
	{
		glColor3f(0.0, 0.0, 0.0);
		Circle(-5.36, Y + 0.2, 0.34, 0, 360);
		glColor3f(1.0, 1.0, 1.0);
		Circle(-5.36, Y + 0.2, 0.3, 0, 360);

		glColor3f(0.0, 0.0, 0.0);
		Circle(-5.37, Y + 0.24, 0.34, 180, 360);
		glColor3f(0.90, 0.90, 0.90);
		Circle(-5.37, Y + 0.24, 0.3, 180, 360);

		F_C = 1;
	}
	else if (F_C == 1)
	{
		glColor3f(0.0, 0.0, 0.0);
		Circle(-5.36, Y + 0.2, 0.34, 0, 180);
		glColor3f(1.0, 1.0, 1.0);
		Circle(-5.36, Y + 0.2, 0.3, 0, 180);

		glColor3f(0.0, 0.0, 0.0);
		Circle(-5.4, Y + 0.24, 0.34, 0, 360);
		glColor3f(0.90, 0.90, 0.90);
		Circle(-5.4, Y + 0.24, 0.3, 0, 360);

		F_C = 2;
	}
	else if (F_C == 2)
	{
		glColor3f(0.0, 0.0, 0.0);
		Circle(-5.36, Y + 0.2, 0.34, 180, 360);
		glColor3f(1.0, 1.0, 1.0);
		Circle(-5.36, Y + 0.2, 0.3, 180, 360);

		glColor3f(0.0, 0.0, 0.0);
		Circle(-5.43, Y + 0.24, 0.34, 0, 180);
		glColor3f(0.90, 0.90, 0.90);
		Circle(-5.43, Y + 0.24, 0.3, 0, 180);

		F_C = 0;
	}
}

void Bird(float Y)
{
	// Body
	glColor3f(0.0, 0.0, 0.0);
	Circle(-5, Y, 0.63, 0, 360);
	glColor3f(1.0, 0.0, 0.0); // Change to red
	Circle(-5, Y, 0.6, 0, 360);

	// Eyes
	glColor3f(0.0, 0.0, 0.0);
	Circle(-4.7, Y + 0.1, 0.28, 0, 360);
	glColor3f(1.0, 1.0, 1.0);
	Circle(-4.7, Y + 0.1, 0.24, 0, 360);
	glColor3f(0.0, 0.0, 0.0);
	Circle(-4.7, Y + 0.14, 0.1, 0, 360);

	// Lips
	glColor3f(0.0, 0.0, 0.0);
	Circle(-4.5, Y - 0.23, 0.3, 0, 180);
	glColor3f(1.0, 0.27, 0.0); // Change to orange
	Circle(-4.5, Y - 0.23, 0.28, 0, 180);
	glColor3f(0.0, 0.0, 0.0);
	Circle(-4.5, Y - 0.257, 0.3, 180, 360);
	glColor3f(1.0, 0.27, 0.0); // Change to orange
	Circle(-4.5, Y - 0.254, 0.28, 180, 360);

	// Flaps
	Flap(Y);

	Sleep(50);
}

void Rand()
{
	for (int i = 0; i < 4; i++)
	{
		int Y = rand();
		Y = Y % 7;
		A[i] = Y;
	}
	PX[0] = 8;
	PY[0] = 9;
	PX[1] = PX[0] + D;
	PY[1] = PY[0] + D;
	PX[2] = PX[1] + D;
	PY[2] = PY[1] + D;
	PX[3] = PX[2] + D;
	PY[3] = PY[2] + D;
}

void PIPE1(int X)
{
	int Y = A[0];
	float AD = 0.02;
	float OPE = 0.7;
	if (PX[0] < 0)
		AD = -0.02;

	// Up
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(PX[0] + X - AD, 50);
	glVertex2f(PX[0] + X - AD, Y + P_G - AD);
	glVertex2f(PY[0] + X + AD, Y + P_G - AD);
	glVertex2f(PY[0] + X + AD, 50);
	glEnd();

	glColor3f(0.0, 0.5, 0.0); // Change to dark green
	glBegin(GL_POLYGON);
	glVertex2f(PX[0] + X, 50);
	glVertex2f(PY[0] + X, 50);
	glVertex2f(PX[0] + X, Y + P_G);
	glVertex2f(PY[0] + X, Y + P_G);
	glEnd();

	AD = 0.07;
	OPE = 0.7;
	if (PX[0] < 0)
		AD = -0.07;

	// ENTRY
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(PX[0] + X - AD, Y + P_G + OPE + AD);
	glVertex2f(PX[0] + X - AD, Y + P_G - AD);
	glVertex2f(PY[0] + X + AD, Y + P_G - AD);
	glVertex2f(PY[0] + X + AD, Y + P_G + OPE + AD);
	glEnd();

	glColor3f(0.0, 1.0, 0.0); // Change to green
	glBegin(GL_POLYGON);
	glVertex2f(PX[0] + X, Y + P_G + OPE);
	glVertex2f(PX[0] + X, Y + P_G);
	glVertex2f(PY[0] + X, Y + P_G);
	glVertex2f(PY[0] + X, Y + P_G + OPE);
	glEnd();

	// Down
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(PX[0] + X - AD, -50);
	glVertex2f(PX[0] + X - AD, Y - P_G + AD);
	glVertex2f(PY[0] + X + AD, Y - P_G + AD);
	glVertex2f(PY[0] + X + AD, -50);
	glEnd();

	glColor3f(0.0, 0.5, 0.0); // Change to dark green
	glBegin(GL_POLYGON);
	glVertex2f(PX[0] + X, -50);
	glVertex2f(PY[0] + X, -50);
	glVertex2f(PX[0] + X, Y - P_G);
	glVertex2f(PY[0] + X, Y - P_G);
	glEnd();
}

void PIPE2(int X)
{
	int Y = A[1];
	float AD = 0.02;
	float OPE = 0.7;
	if (PX[1] < 0)
		AD = -0.02;

	// Up
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(PX[1] + X - AD, 50);
	glVertex2f(PX[1] + X - AD, Y + P_G - AD);
	glVertex2f(PY[1] + X + AD, Y + P_G - AD);
	glVertex2f(PY[1] + X + AD, 50);
	glEnd();

	glColor3f(0.0, 0.5, 0.0); // Change to dark green
	glBegin(GL_POLYGON);
	glVertex2f(PX[1] + X, 50);
	glVertex2f(PY[1] + X, 50);
	glVertex2f(PX[1] + X, Y + P_G);
	glVertex2f(PY[1] + X, Y + P_G);
	glEnd();

	AD = 0.07;
	OPE = 0.7;
	if (PX[1] < 0)
		AD = -0.07;

	// ENTRY
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(PX[1] + X - AD, Y + P_G + OPE + AD);
	glVertex2f(PX[1] + X - AD, Y + P_G - AD);
	glVertex2f(PY[1] + X + AD, Y + P_G - AD);
	glVertex2f(PY[1] + X + AD, Y + P_G + OPE + AD);
	glEnd();

	glColor3f(0.0, 1.0, 0.0); // Change to green
	glBegin(GL_POLYGON);
	glVertex2f(PX[1] + X, Y + P_G + OPE);
	glVertex2f(PX[1] + X, Y + P_G);
	glVertex2f(PY[1] + X, Y + P_G);
	glVertex2f(PY[1] + X, Y + P_G + OPE);
	glEnd();

	// Down
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(PX[1] + X - AD, -50);
	glVertex2f(PX[1] + X - AD, Y - P_G + AD);
	glVertex2f(PY[1] + X + AD, Y - P_G + AD);
	glVertex2f(PY[1] + X + AD, -50);
	glEnd();

	glColor3f(0.0, 0.5, 0.0); // Change to dark green
	glBegin(GL_POLYGON);
	glVertex2f(PX[1] + X, -50);
	glVertex2f(PY[1] + X, -50);
	glVertex2f(PX[1] + X, Y - P_G);
	glVertex2f(PY[1] + X, Y - P_G);
	glEnd();
}

void PIPE3(int X)
{
	int Y = A[2];
	float AD = 0.02;
	float OPE = 0.7;
	if (PX[2] < 0)
		AD = -0.02;

	// Up
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(PX[2] + X - AD, 50);
	glVertex2f(PX[2] + X - AD, Y + P_G - AD);
	glVertex2f(PY[2] + X + AD, Y + P_G - AD);
	glVertex2f(PY[2] + X + AD, 50);
	glEnd();

	glColor3f(0.0, 0.5, 0.0); // Change to dark green
	glBegin(GL_POLYGON);
	glVertex2f(PX[2] + X, 50);
	glVertex2f(PY[2] + X, 50);
	glVertex2f(PX[2] + X, Y + P_G);
	glVertex2f(PY[2] + X, Y + P_G);
	glEnd();

	AD = 0.07;
	OPE = 0.7;
	if (PX[2] < 0)
		AD = -0.07;

	// ENTRY
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(PX[2] + X - AD, Y + P_G + OPE + AD);
	glVertex2f(PX[2] + X - AD, Y + P_G - AD);
	glVertex2f(PY[2] + X + AD, Y + P_G - AD);
	glVertex2f(PY[2] + X + AD, Y + P_G + OPE + AD);
	glEnd();

	glColor3f(0.0, 1.0, 0.0); // Change to green
	glBegin(GL_POLYGON);
	glVertex2f(PX[2] + X, Y + P_G + OPE);
	glVertex2f(PX[2] + X, Y + P_G);
	glVertex2f(PY[2] + X, Y + P_G);
	glVertex2f(PY[2] + X, Y + P_G + OPE);
	glEnd();

	// Down
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(PX[2] + X - AD, -50);
	glVertex2f(PX[2] + X - AD, Y - P_G + AD);
	glVertex2f(PY[2] + X + AD, Y - P_G + AD);
	glVertex2f(PY[2] + X + AD, -50);
	glEnd();

	glColor3f(0.0, 0.5, 0.0); // Change to dark green
	glBegin(GL_POLYGON);
	glVertex2f(PX[2] + X, -50);
	glVertex2f(PY[2] + X, -50);
	glVertex2f(PX[2] + X, Y - P_G);
	glVertex2f(PY[2] + X, Y - P_G);
	glEnd();
}

void PIPE4(int X)
{
	int Y = A[3];
	float AD = 0.02;
	float OPE = 0.7;
	if (PX[3] < 0)
		AD = -0.02;

	// Up
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(PX[3] + X - AD, 50);
	glVertex2f(PX[3] + X - AD, Y + P_G - AD);
	glVertex2f(PY[3] + X + AD, Y + P_G - AD);
	glVertex2f(PY[3] + X + AD, 50);
	glEnd();

	glColor3f(0.0, 0.5, 0.0); // Change to dark green
	glBegin(GL_POLYGON);
	glVertex2f(PX[3] + X, 50);
	glVertex2f(PY[3] + X, 50);
	glVertex2f(PX[3] + X, Y + P_G);
	glVertex2f(PY[3] + X, Y + P_G);
	glEnd();

	AD = 0.07;
	OPE = 0.7;
	if (PX[3] < 0)
		AD = -0.07;

	// ENTRY
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(PX[3] + X - AD, Y + P_G + OPE + AD);
	glVertex2f(PX[3] + X - AD, Y + P_G - AD);
	glVertex2f(PY[3] + X + AD, Y + P_G - AD);
	glVertex2f(PY[3] + X + AD, Y + P_G + OPE + AD);
	glEnd();

	glColor3f(0.0, 1.0, 0.0); // Change to green
	glBegin(GL_POLYGON);
	glVertex2f(PX[3] + X, Y + P_G + OPE);
	glVertex2f(PX[3] + X, Y + P_G);
	glVertex2f(PY[3] + X, Y + P_G);
	glVertex2f(PY[3] + X, Y + P_G + OPE);
	glEnd();

	// Down
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(PX[3] + X - AD, -50);
	glVertex2f(PX[3] + X - AD, Y - P_G + AD);
	glVertex2f(PY[3] + X + AD, Y - P_G + AD);
	glVertex2f(PY[3] + X + AD, -50);
	glEnd();

	glColor3f(0.0, 0.5, 0.0); // Change to dark green
	glBegin(GL_POLYGON);
	glVertex2f(PX[3] + X, -50);
	glVertex2f(PY[3] + X, -50);
	glVertex2f(PX[3] + X, Y - P_G);
	glVertex2f(PY[3] + X, Y - P_G);
	glEnd();
}

void GameCheck(int X)
{
	bool L = false;

	for (int i = 0; i < 4; i++)
	{
		if (abs(B_H + 0.63) >= 10 || abs(B_H - 0.63) <= -10)
		{
			L = true;
			break;
		}
		
		if (-5 == PX[i] + X || -5 == PY[i] + X)
		{
			if (abs(B_H + 0.63) >= A[i] + P_G || abs(B_H - 0.63) <= A[i] - P_G)
			{
				L = true;
				break;
			}
			else
			{
				Score++;
			}
		}
	}
	if (L)
	{
		cout << "Game Over " << endl;
		S = 3;
		B_H = 0;
	}
	else
	{
		//cout << "CONTINUE" << endl;
	}
}

void SUN_MOON(float X, float Y)
{
	glColor3f(0.8352, 1.0, 0.0);

	glBegin(GL_LINES);
	for (int ang = 0; ang <= 360; ang += 20)
	{
		glVertex2f(X, Y);
		glVertex2f(X + 0.48 * cos(ang), Y + 0.48 * sin(ang));
	}
	glEnd();

	//Circle(X, Y, 0.48, 0, 360);

	glColor3f(1.0, 1.0, 0.0);
	Circle(X, Y, 0.33, 0, 360);


	glColor3f(0.90, 0.90, 0.90);
	Circle(X * -1, Y * -1, 0.48, 0, 360);

	glColor3f(1.0, 1.0, 1.0);
	Circle(X * -1, Y * -1, 0.23, 0, 360);

}


void Cloud(int X, int Y)
{

	glColor3f(1.0, 1.0, 1.0);

	Circle(X, Y, 0.36, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X - 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X + 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);

	X = X + 4;
	Y = Y + 2;
	Circle(X, Y, 0.56, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);


	X = X + 4;
	Y = Y - 4;
	Circle(X, Y, 0.56, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X - 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);


	X = X + 4;
	Y = Y + 5;
	Circle(X, Y, 0.56, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X + 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X - 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);

	X = X + 4;
	Y = Y - 8;
	Circle(X, Y, 0.36, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X - 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X + 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);

	X = X + 4;
	Y = Y + 2;
	Circle(X, Y, 0.56, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);


	X = X + 4;
	Y = Y - 4;
	Circle(X, Y, 0.56, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X - 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);


	X = X + 4;
	Y = Y + 5;
	Circle(X, Y, 0.56, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X + 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X - 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);

	Circle(X, Y, 0.36, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X - 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X + 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);

	X = X + 4;
	Y = Y + 2;
	Circle(X, Y, 0.56, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);


	X = X + 4;
	Y = Y - 4;
	Circle(X, Y, 0.56, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X - 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);


	X = X + 4;
	Y = Y + 5;
	Circle(X, Y, 0.56, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X + 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X - 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);

	X = X + 4;
	Y = Y - 8;
	Circle(X, Y, 0.36, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X - 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X + 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);

	X = X + 4;
	Y = Y + 2;
	Circle(X, Y, 0.56, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);


	X = X + 4;
	Y = Y - 4;
	Circle(X, Y, 0.56, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X - 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);


	X = X + 4;
	Y = Y + 5;
	Circle(X, Y, 0.56, 0, 360);
	Circle(X - 0.3, Y + 0.3, 0.36, 0, 360);
	Circle(X + 0.6, Y, 0.36, 0, 360);
	Circle(X + 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X - 0.3, Y - 0.3, 0.36, 0, 360);
	Circle(X - 0.6, Y, 0.36, 0, 360);
}



void drawString(float x, float y, float z, string CH) {
	glRasterPos3f(x, y, z);
	for (char c : CH) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);  // Updates the position
	}
}

void drawStringsmall(float x, float y, float z, string CH) {
	glRasterPos3f(x, y, z);
	for (char c : CH) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);  // Updates the position
	}
}

void BACK()
{
	// MORNING - NIGHT

	glColor3f(Col[0], Col[1], Col[2]);
	for (int i = 0; i < 3; i++)
	{

		if (Col[i] <= N_C[i] && Back_COl == 0)
		{
			Back_COl = 1;
			for (int L = 0; L < 3; L++)
				WC[L] = WY[L];
		}

		if (Col[i] >= M_C[i] && Back_COl == 1)
		{
			Back_COl = 0;
			for (int L = 0; L < 3; L++)
				WC[L] = WB[L];
		}

		if (Back_COl == 0)
			Col[i] -= Diff[i];

		if (Back_COl == 1)
			Col[i] += Diff[i];
	}

	//cout << Col[0] << " " << Col[1] << " " << Col[2] << endl;
	glRectd(-10, 10, 10, -10);

	// SUN - MOON
	SUN_MOON(SR_X, SR_Y);
	SR_X = SR * cos(theta);
	SR_Y = SR * sin(theta);
	theta += 0.033;
	if (theta == 360)
	{
		theta = 0;
	}

	//Mountains

	glColor3f(0.5450, 0.2705, 0.0745);
	int L = -10;
	float W = 7;
	while (L <= 10)
	{
		glBegin(GL_POLYGON);
		glVertex2f(L + W, -10);
		glVertex2f(L + W, 0);
		glVertex2f(L, -10);
		glVertex2f(L, 0);
		L += 7;
		glEnd();
	}

	glColor3f(0.1705, 0.12, 0.0847);
	L = -14;
	W = 6;
	while (L <= 10)
	{
		glBegin(GL_POLYGON);
		glVertex2f(L + W, -10);
		glVertex2f(L + W, -2);
		glVertex2f(L, -10);
		glVertex2f(L, -2);
		L += 6;
		glEnd();
	}

	

	// Ground

	glColor3f(0.549, 0.6313, 0.41);
	L = -10;
	W = 1;
	while (L <= 10)
	{
		glBegin(GL_POLYGON);
		glVertex2f(L + W, -10);
		glVertex2f(L + W, -9.4);
		glVertex2f(L, -10);
		glVertex2f(L, -9.4);
		L += 1;
		glEnd();
	}

	glColor3f(0.1960, 0.8039, 0.196);
	L = -11;
	W = 0.5;
	while (L <= 10)
	{
		glBegin(GL_POLYGON);
		glVertex2f(L + W, -10);
		glVertex2f(L + W, -9.4);
		glVertex2f(L, -10);
		glVertex2f(L, -9.4);
		L += 1;
		glEnd();
	}

	glColor3f(0.3921, 0.161, 0.2768);
	L = -11;
	W = 0.5;
	while (L <= 10)
	{
		glBegin(GL_POLYGON);
		glVertex2f(L + W, -10);
		glVertex2f(L + W, -9.4);
		glVertex2f(L, -10);
		glVertex2f(L, -9.4);
		L += 6;
		glEnd();
	}

	glColor3f(0.1372, 0.5450, 0.133);
	L = -10;
	W = 1;
	while (L <= 10)
	{
		glBegin(GL_POLYGON);
		glVertex2f(L + W, -10);
		glVertex2f(L + W, -9.7);
		glVertex2f(L, -10);
		glVertex2f(L, -9.7);
		L += 1;
		glEnd();
	}

}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	Bird(B_H);

	if (S == 0)
	{
		glColor3f(0.0, 0.0, 0.0);
		string Ch = "START";
		drawString(-1, 0, 0, Ch);
		glColor3f(1.0, 1.0, 1.0);
		Ch = "Press Any Key";
		drawStringsmall(-1.5, -0.8, 0, Ch);
		Rand();
		Score = 0;
	}

	if (S == 3)
	{
		int TS = Score / 2;
		string CH;

		if (Score == 0)
		{
			CH = '0';
			cout << Score << endl;
		}
		else
		{
			while (TS != 0)
			{
				char TC = '0' + (TS % 10);
				CH = TC + CH;
				TS /= 10;
			}
		}
		//cout << CH << endl;
		glColor3f(0.0, 0.0, 0.0);
		drawString(0, 2, 0, CH);
		string Ch = "Final Score";
		drawStringsmall(-1.3, 1, 0, Ch);

		glColor3f(0.0, 0.0, 0.0);
		Ch = "Game Over";
		drawString(-1.5, 0, 0, Ch);
		glColor3f(1.0, 1.0, 1.0);
		Ch = "Press Any Key";
		drawStringsmall(-1.5, -0.8, 0, Ch);
	}

	if (S == 1)
	{
		//Score /= 2;
		int TS = Score / 2;
		string CH;
		while (TS != 0)
		{
			char TC = '0' + (TS % 10);
			CH = TC + CH;
			TS /= 10;
		}

		if (B_H > 10 || B_H < -10)
		{
			B_H = 8;
		}

		if(CH.length()>0)
			cout << " SCORE : "<< CH << endl;

		if (C <= -37)
		{
			Rand();
			C = 0;
		}
		glClear(GL_COLOR_BUFFER_BIT);
		BACK();
		//cout << S << " : " << B_H << endl;
		//Cloud
		Cloud(C, 5);

		Bird(B_H);
		PIPE1(C);
		PIPE2(C);
		PIPE3(C);
		PIPE4(C);
		C--;
		B_H--;
		GameCheck(C);
		Sleep(100);
	}

	glFlush();
	glutPostRedisplay();
}

void Jump(int btn, int state, int x, int y) {

	if (btn == GLUT_LEFT_BUTTON)
	{
		//cout << "Clicked" << endl;
		if (state == GLUT_DOWN && S != 3)
		{
			B_H = B_H + 2;
			Bird(B_H);
		}
	}
}


void Start(unsigned char key, int x, int y)
{

	//cout<<" "<< key << " " << x << " " << y << endl;

	if (key)
	{
		glFlush();
		cout << "Started" << endl;
		if (S == 3)
			S = 0;
		else
			S = 1;

		Bird(B_H);
	}
}


void myinit()
{
	for (int i = 0; i < 3; i++)
	{
		Col[i] = M_C[i];
		Diff[i] = (M_C[i] - N_C[i]) / 120;
	}

	glClearColor(Col[0], Col[1], Col[2], 0);

	//glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(550, 50);
	glutCreateWindow("Flappy_Bird");
	glutDisplayFunc(display);
	glutKeyboardFunc(Start);
	glutMouseFunc(Jump);
	myinit();
	glutMainLoop();
}
