#include<iostream>
#include<string>
#include<cstdlib>
#include<math.h>
#include <stdbool.h>

using namespace std;

int Number_Polygons(string polygon)
{
	int  numb = 0, l;
	l = polygon.length();
	for (int i = 0; i < l; i++)
	{
		if (polygon[i] == ';')
			numb ++;
	}
	return 1 + numb;
}

int Total_Number_Points(string polygon)
{
	int numb = 0, l;
	l = polygon.length();

	for (int i = 0; i < l; i++)
	{
		if (polygon[i] == '(')
			numb++;
	}
	return numb;
}

int Number_Points_Of_Polygons(string polygon,int s)
{
	int numb = 0, m=1,j;
	for (j = 0; j < polygon.length(); j++)
	{
		if (polygon[j] == ';')
			m++;
			if (m == s)
				break;
	}
	for (int i = j+1; i < polygon.length(); i++)
	{
		if (polygon[i] == '(')
			numb++;
		if (polygon[i] == ';'|| polygon[i] == ']')
			break;

	}
	return numb;
}

float Maximum_X(float X_points[], string polygon)
{
	float max_x = X_points[0];
	for (int i = 1; i < Total_Number_Points(polygon); i++)
	{
		if (X_points[i] > max_x)
			max_x = X_points[i];
	}
	return max_x;
}

float Maximum_Y(float Y_points[], string polygon)
{
	float max_y = Y_points[0];
	for (int i = 1; i < Total_Number_Points(polygon); i++)
	{
		if (Y_points[i] > max_y)
			max_y = Y_points[i];
	}
	return max_y;
}

float Minimum_X(float X_points[], string polygon)
{
	float min_x = X_points[0];
	for (int i = 1; i < Total_Number_Points(polygon); i++)
	{
		if (X_points[i] < min_x)
			min_x = X_points[i];
	}
	return min_x;
}

float Minimum_Y(float Y_points[], string polygon)
{
	float min_y = Y_points[0];
	for (int i = 1; i < Total_Number_Points(polygon); i++)
	{
		if (Y_points[i] < min_y)
			min_y = Y_points[i];
	}
	return min_y;
}

bool isvalueinarray(int val, int *arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (arr[i] == val)
			return true;
	}
	return false;
}

void Non_Redundant_Points(float X_points[], float Y_points[], float points[][100], string polygon)
{
	int m = 0, l, i = 2, v = 0, f = 0;
	float slope1, slope2, slope3, slope4, d = 0, slopee = 0;

	for (m = 1; m <= Number_Polygons(polygon); m++)
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		f = v - Number_Points_Of_Polygons(polygon, m);
		for (i; i <= v; i++)
		{
			if ((Y_points[i - 2] == Y_points[i - 1]) && (X_points[i - 2] == X_points[i - 1]))
			{
				points[i - 1][0] = 2000;
				points[i - 1][1] = 2000;

				if (i != v)
				{
					slope1 = (Y_points[i - 2] - Y_points[i - 3]) / (X_points[i - 2] - X_points[i - 3]);
					slope2 = (Y_points[i - 2] - Y_points[i]) / (X_points[i - 2] - X_points[i]);
					if (slope1 == slope2)
					{
						points[i - 2][0] = 2000;
						points[i - 2][1] = 2000;
					}
				}
				if (i == v)
				{
					slope1 = (Y_points[i - 2] - Y_points[i - 3]) / (X_points[i - 2] - X_points[i - 3]);
					slope2 = (Y_points[i - 2] - Y_points[f]) / (X_points[i - 2] - X_points[f]);
					if (slope1 == slope2)
					{
						points[i - 2][0] = 2000;
						points[i - 2][1] = 2000;
					}
				}
			}

			if (X_points[i - 2] == X_points[i - 1] == X_points[i])
			{
				if ((Y_points[i - 2] == Y_points[i - 1]) || (Y_points[i - 1] == Y_points[i]))
					if ((X_points[i - 2] == X_points[i] == X_points[i + 1]))
					{
						points[i - 1][0] = 2000;
						points[i - 1][1] = 2000;
					}
				if ((Y_points[i - 2] == Y_points[i - 1]) && (X_points[i - 2] == X_points[i - 1]))
				{
					points[i - 1][0] = 2000;
					points[i - 1][1] = 2000;
				}
			}

			if (i != v)
			{
				slope1 = (Y_points[i - 2] - Y_points[i - 1]) / (X_points[i - 2] - X_points[i - 1]);
				slope2 = (Y_points[i - 1] - Y_points[i]) / (X_points[i - 1] - X_points[i]);
				if (slope1 == slope2)
				{
					points[i - 1][0] = 2000;
					points[i - 1][1] = 2000;
				}
			}
			if (i == v)
			{
				slopee = (Y_points[i - 1] - Y_points[f]) / (X_points[i - 1] - X_points[f]);
				slope3 = (Y_points[i - 1] - Y_points[i - 2]) / (X_points[i - 1] - X_points[i - 2]);
				slope4 = (Y_points[f] - Y_points[f + 1]) / (X_points[f] - X_points[f + 1]);
				
				if ((Y_points[i - 1] == Y_points[f]) && (X_points[i - 1] == X_points[f]))
				{
					points[i - 1][0] = 2000;
					points[i - 1][1] = 2000;
					if ((Y_points[i - 2] == Y_points[f]) && (X_points[i - 2] == X_points[f]))
					{
						points[i - 2][0] = 2000;
						points[i - 2][1] = 2000;
					}

				}

				if (points[i - 1][0] == 2000 && points[i - 2][0] == 2000)
				{
					float slope5 = (Y_points[i - 3] - Y_points[f]) / (X_points[i - 3] - X_points[f]);
					if (slope4 == slope5)
					{
						points[f][0] = 2000;
						points[f][1] = 2000;
					}
				}

				if (slopee == slope3)
				{
					points[i - 1][0] = 2000;
					points[i - 1][1] = 2000;
				}

				if (slopee == slope4)
				{
					points[f][0] = 2000;
					points[f][1] = 2000;
				}
			}
		}
	}
}

int Total_Redundant_Points(float X_points[], float Y_points[], float float_xy[][100],int RedunNumbPoly[], string polygon)
{
	int counter=0, m = 0, i = 0, v = 0, f = 0;
	Non_Redundant_Points(X_points, Y_points, float_xy, polygon);

	for (m = 1; m <= Number_Polygons(polygon); m++)
	{
		counter = RedunNumbPoly[m - 1] + counter;
	}
	return counter;
}

void Polygon_Points(string polygon, string polygons[][100], float X_points[], float Y_points[], float points[][100], int PolyNumber)
{
	int counter = 0, v = 0, f = 0;
	Non_Redundant_Points(X_points, Y_points, points, polygon);
	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		f = v - Number_Points_Of_Polygons(polygon, m);
		if (PolyNumber == m)
			break;
	}
	for (int i = f; i < v; i++)
	{
		if (points[i][1] != 2000 && points[i][0] != 2000)
		{
			if (counter == 0)
				cout << '(' << X_points[i] << ',' << Y_points[i] << ')';
			else
				cout << ',' << '(' << X_points[i] << ',' << Y_points[i] << ')';
			counter++;
		}
	}
	if (counter == 0)
		cout << "none";
}

void Point_Polygons(string polygon, int RedunNumbPoly[], float X_points[], float Y_points[], float points[][100], float  x, float y)
{
	int n = 0, v = 0, counter = 0, j = 0, i = 0, output[100], u = 0;

	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		for (i; i < v; i++)
		{
				if ((Y_points[i] == y) && (X_points[i] == x))
				{
					output[u] = m;
					if (counter <= 0)
						cout << m;
					else
						if(isvalueinarray(m, output, u)==0)
						cout << ',' << m;
					counter++;
				}
				u++;
		}
	}
	if (counter == 0)
		cout << "none";
}

int Point_Polygons(string polygon, float X_points[], float Y_points[], float  x, float y)
{
	int n = 0, v = 0, counter = 0, j = 0, i = 0, u = 0, output[100];

	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		for (i; i < v; i++)
		{
			if ((Y_points[i] == y) && (X_points[i] == x))
			{
				if (isvalueinarray(m, output, u) == 0)
				{
					output[u] = m;
					u++;
				}
				
			}
		}
	}
	return u;
}

void List_Polygons_Points_More(string polygon, int RedunNumbPoly[], float X_points[], float Y_points[],int o)
{
	int counter = 0;

	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		if (o < Number_Points_Of_Polygons(polygon, m) - RedunNumbPoly[m - 1])
		{
			if (counter <= 0)
				cout << m;
			else
				cout << ',' << m;
			counter++;
		}
	}
	if (counter == 0)
		cout << "none";
}

void List_Polygons_Points_Less(string polygon, int RedunNumbPoly[], float X_points[], float Y_points[], int o)
{
	int counter = 0;

	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		if (o > Number_Points_Of_Polygons(polygon, m) - RedunNumbPoly[m - 1])
		{
			if (counter <= 0)
				cout << m;
			else
				cout << ',' << m;
			counter++;
		}
	}
	if (counter == 0)
		cout << "none";
}

void List_Polygons_Points_Equal(string polygon, int RedunNumbPoly[], float X_points[], float Y_points[], int o)
{
	int counter = 0;

	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		if (o == Number_Points_Of_Polygons(polygon, m) - RedunNumbPoly[m - 1])
		{
			if (counter <= 0)
				cout << m;
			else
				cout << ',' << m;
			counter++;
		}
	}
	if (counter == 0)
		cout << "none";
}

void List_Points_Polygons_More(string polygon, float X_points[], float Y_points[], int  x)
{
	int counter = 0, count, v = 0, f = 0, i = 0, b = 0, outputx[100], outputy[100], tru = 0;
	
	for (int m = 1; m <= Number_Polygons(polygon); m++) 
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		f = v - Number_Points_Of_Polygons(polygon, m);

		for (i = f; i < v; i++)
		{
			count=Point_Polygons(polygon, X_points, Y_points, X_points[i], Y_points[i]);
		
			if (count > x)
			{
				outputx[b] = X_points[i];
				outputy[b] = Y_points[i];
				if (counter == 0)
					cout << '(' << X_points[i] << ',' << Y_points[i] << ')';
				else
				{
					for (int s = 0; s < b; s++)
					{
						if (((outputx[s] == X_points[i]) && (outputy[s] == Y_points[i])))
							tru = 0;
						
						else
							tru = 1;
					}
					if(tru == 1)
					cout << ',' << '(' << X_points[i] << ',' << Y_points[i] << ')';
				}
				counter++;
				b++;
			}
			
		}
		
	}
	if (counter == 0)
		cout << "none";
}

void List_Points_Polygons_Less(string polygon, float X_points[], float Y_points[], int  x)
{
	int counter = 0, count, v = 0, f = 0, i = 0, b = 0, outputx[100], outputy[100], tru = 0;

	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		f = v - Number_Points_Of_Polygons(polygon, m);

		for (i = f; i < v; i++)
		{
			count = Point_Polygons(polygon, X_points, Y_points, X_points[i], Y_points[i]);

			if (count < x)
			{
				outputx[b] = X_points[i];
				outputy[b] = Y_points[i];
				if (counter == 0)
					cout << '(' << X_points[i] << ',' << Y_points[i] << ')';
				else
				{
					for (int s = 0; s < b; s++)
					{
						if (((outputx[s] == X_points[i]) && (outputy[s] == Y_points[i])))
							tru = 0;

						else
							tru = 1;
					}
					if (tru == 1)
						cout << ',' << '(' << X_points[i] << ',' << Y_points[i] << ')';
				}
				counter++;
				b++;
			}

		}

	}
	if (counter == 0)
		cout << "none";
}

void List_Points_Polygons_Equal(string polygon, float X_points[], float Y_points[], int  x)
{
	int counter = 0, count, v = 0, f = 0, i = 0, b = 0, outputx[100], outputy[100], tru = 0;

	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		f = v - Number_Points_Of_Polygons(polygon, m);

		for (i = f; i < v; i++)
		{
			count = Point_Polygons(polygon, X_points, Y_points, X_points[i], Y_points[i]);

			if (count == x)
			{
				outputx[b] = X_points[i];
				outputy[b] = Y_points[i];
				if (counter == 0)
					cout << '(' << X_points[i] << ',' << Y_points[i] << ')';
				else
				{
					for (int s = 0; s < b; s++)
					{
						if (((outputx[s] == X_points[i]) && (outputy[s] == Y_points[i])))
							tru = 0;

						else
							tru = 1;
					}
					if (tru == 1)
						cout << ',' << '(' << X_points[i] << ',' << Y_points[i] << ')';
				}
				counter++;
				b++;
			}

		}

	}
	if (counter == 0)
		cout << "none";
}

float Polygon_Perimeter(string polygon, float X_points[], float Y_points[], int PolyNumber)
{
	int i, v = 0, f = 0;
	float Perimeter = 0, dist = 0;
	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		f = v - Number_Points_Of_Polygons(polygon, m);
		if (PolyNumber == m)
			break;
	}
	
	for (i = f; i < v - 1; i++)
	{
		dist = sqrt(pow((Y_points[i] - Y_points[i + 1]), 2) + pow((X_points[i] - X_points[i + 1]), 2));
		Perimeter = Perimeter + dist;
	}
		float dist2 = sqrt(pow((Y_points[i] - Y_points[f]), 2) + pow((X_points[i] - X_points[f]), 2));

		return Perimeter + dist2;
}

void List_Triangles(string polygon, int RedunNumbPoly[], float X_points[], float Y_points[])
{
	int counter = 0;
	for (int i = 1; i <= Number_Polygons(polygon); i++)
	{
		if (Number_Points_Of_Polygons(polygon, i) - RedunNumbPoly[i - 1] == 3)
		{
			if (counter <= 0)
			{
				cout << i;
				counter++;
			}
			else
				cout << ',' << i;
		}
	}
	if (counter == 0)
		cout << "none";
}

void List_Rectangles(string polygon, int RedunNumbPoly[], float X_points[], float Y_points[], float points[][100])
{
	int counter = 0, j = 0, i = 1, v = 0, f = 0;
	float point1x, point2x, point3x, point4x, point1y, point2y, point3y, point4y, dist1, dist2, dist3, dist4, diagonal1, diagonal2;
	Non_Redundant_Points(X_points, Y_points, points, polygon);

	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		f = v - Number_Points_Of_Polygons(polygon, m);
		if (Number_Points_Of_Polygons(polygon, m) - RedunNumbPoly[m - 1] == 4)
		{
			for (i = f + 1; i <= v; i++)
			{
				if (points[i - 1][1] != 2000 && points[i - 1][0] != 2000)
				{
					point1x = points[i - 1][0];   point1y = points[i - 1][1];
					j = i + 1;
					break;
				}
			}
			for (i = j; i <= v; i++)
			{
				if (points[i - 1][1] != 2000 && points[i - 1][0] != 2000)
				{
					point2x = points[i - 1][0];   point2y = points[i - 1][1];
					j = i + 1;
					break;
				}
			}

			for (i = j; i <= v; i++)
			{
				if (points[i - 1][1] != 2000 && points[i - 1][0] != 2000)
				{
					point3x = points[i - 1][0];   point3y = points[i - 1][1];
					j = i + 1;
					break;
				}
			}

			for (i = j; i <= v; i++)
			{
				if (points[i - 1][1] != 2000 && points[i - 1][0] != 2000)
				{
					point4x = points[i - 1][0];   point4y = points[i - 1][1];
					j = i + 1;
					break;
				}
			}
			dist1 = sqrt(pow((point1y - point2y), 2) + pow((point1x - point2x), 2));
			dist2 = sqrt(pow((point2y - point3y), 2) + pow((point2x - point3x), 2));
			dist3 = sqrt(pow((point3y - point4y), 2) + pow((point3x - point4x), 2));
			dist4 = sqrt(pow((point4y - point1y), 2) + pow((point4x - point1x), 2));
			diagonal1 = sqrt(pow((point1y - point3y), 2) + pow((point1x - point3x), 2));
			diagonal2 = sqrt(pow((point2y - point4y), 2) + pow((point2x - point4x), 2));

			if ((dist1 == dist3) && (dist2 == dist4))
				if (diagonal1 == diagonal2)
				{
					{
						if (counter <= 0)
						{
							cout << m;
							counter++;
						}
						else
							cout << ',' << m;
					}
				}
		}
	}

	if (counter == 0)
		cout << "none";
}

void List_Trapezoid(string polygon, int RedunNumbPoly[], float X_points[], float Y_points[], float points[][100])
{
	int counter = 0, j = 0, i = 1, v = 0, f = 0;
	float point1x, point2x, point3x, point4x, point1y, point2y, point3y, point4y, slope1, slope2, slope3, slope4, dist1, dist2, dist3, dist4;
	Non_Redundant_Points(X_points, Y_points, points, polygon);

	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		f = v - Number_Points_Of_Polygons(polygon, m);
		if (Number_Points_Of_Polygons(polygon, m) - RedunNumbPoly[m - 1] == 4)
		{
			for (i = f + 1; i <= v; i++)
			{
				if (points[i - 1][1] != 2000 && points[i - 1][0] != 2000)
				{
					point1x = points[i - 1][0];   point1y = points[i - 1][1];
					j = i + 1;
					break;
				}
			}
			for (i = j; i <= v; i++)
			{
				if (points[i - 1][1] != 2000 && points[i - 1][0] != 2000)
				{
					point2x = points[i - 1][0];   point2y = points[i - 1][1];
					j = i + 1;
					break;
				}
			}

			for (i = j; i <= v; i++)
			{
				if (points[i - 1][1] != 2000 && points[i - 1][0] != 2000)
				{
					point3x = points[i - 1][0];   point3y = points[i - 1][1];
					j = i + 1;
					break;
				}
			}

			for (i = j; i <= v; i++)
			{
				if (points[i - 1][1] != 2000 && points[i - 1][0] != 2000)
				{
					point4x = points[i - 1][0];   point4y = points[i - 1][1];
					j = i + 1;
					break;
				}
			}
			slope1 = (point1y - point2y) / (point1x - point2x);
			slope2 = (point2y - point3y) / (point2x - point3x);
			slope3 = (point3y - point4y) / (point3x - point4x);
			slope4 = (point1y - point4y) / (point1x - point4x);
			dist1 = sqrt(pow((point1y - point2y), 2) + pow((point1x - point2x), 2));
			dist2 = sqrt(pow((point2y - point3y), 2) + pow((point2x - point3x), 2));
			dist3 = sqrt(pow((point3y - point4y), 2) + pow((point3x - point4x), 2));
			dist4 = sqrt(pow((point4y - point1y), 2) + pow((point4x - point1x), 2));

			if (((slope1 == slope3) && (slope2 != slope4)) || ((slope1 != slope3) && (slope2 == slope4)))
			{
					if (counter <= 0)
					{
						cout << m;
						counter++;
					}
					else
						cout << ',' << m;
			}
		}
	}
	if (counter == 0)
		cout << "none";
}

void Inside_Rectangle(string polygon, int RedunNumbPoly[], float X_points[], float Y_points[], float points[][100], float x[4], float y[4])
{
	int tru = 0, f = 0, v = 0, counter = 0, i;
	float s = 0, t = 0, d = 0;
	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		f = v - Number_Points_Of_Polygons(polygon, m);
		for (i = f; i < v; i++)
		{
			float c = ((x[1] - x[0])*(X_points[i] - x[0])) + ((y[1] - y[0])*(Y_points[i] - y[0]));  //dot(AB,AM)
			float n = ((x[2] - x[1])*(X_points[i] - x[1])) + ((y[2] - y[1])*(Y_points[i] - y[1]));  //dot(AB,AM)
			float b = ((x[1] - x[0])*(x[1] - x[0])) + ((y[1] - y[0])*(y[1] - y[0]));    //dot(AB,AB)
			float u = ((x[2] - x[1])*(x[2] - x[1])) + ((y[2] - y[1])*(y[2] - y[1]));    //dot(BC,BC)
			if (((0 <= c) && (c <= b)) && ((0 <= n) && (n <= u)))
				tru=1;		
			else
			{
				tru = 0;
				break;
			}
		}
		if (tru == 1)
		{
			if (counter <= 0)
				cout << m;
			else
				cout << ',' << m;
			counter++;
		}
	}
	if (counter == 0)
		cout << "none";
}

float Polygon_Area(string polygon, float X_points[], float Y_points[], int PolyNumber)
{
	int i, v = 0, f = 0;
	float area = 0, first_Multiply = 0, second_Multiply = 0;
	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		f = v - Number_Points_Of_Polygons(polygon, m);
		if (PolyNumber == m)
			break;
	}

	for (i = f; i < v-1; i++)
	{
		
			first_Multiply = first_Multiply + (X_points[i] * Y_points[i + 1]);
			second_Multiply = second_Multiply + (X_points[i + 1] * Y_points[i]);
		
	}
	first_Multiply = first_Multiply + (X_points[v-1] * Y_points[f]);
	second_Multiply = second_Multiply + (X_points[f] * Y_points[v-1]);

	return area = abs((second_Multiply - first_Multiply) / 2);
}

void Polygons_Area_Range(string polygon, float X_points[], float Y_points[], int PolyNumber, float Amax, float Amin)
{
	int counter = 0;
	float area = 0;
	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		area = Polygon_Area(polygon, X_points, Y_points, m);
	if (area <= Amax && area >= Amin)
	{
		if (counter <= 0)
			cout << m;
		else
			cout << ',' << m;
		counter++;
	}
}
if (counter == 0)
cout << "none";
}

void Inside_Circle(string polygon, float X_points[], float Y_points[], float points[][100], float x, float y, float r)
{
	int i, v = 0, f = 0, tru = 0, counter = 0;
	float d = 0;
	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		f = v - Number_Points_Of_Polygons(polygon, m);
		for (i = f; i < v; i++)
		{
			d = pow((Y_points[i] - y), 2) + pow((X_points[i] - x), 2);
			if (d <= (r*r))
				tru = 1;

			else
			{
				tru = 0;
				break;
			}
		}
		if (tru == 1)
		{
			if (counter <= 0)
				cout << m;
			else
				cout << ',' << m;
			counter++;
		}
	}
	if (counter == 0)
		cout << "none";
}

void Polygons_Enclosing_Point(string polygon, float vertx[], float verty[], float testx, float testy)
{
	int i, j, c = 0, v = 0, f = 0, counter = 0;
	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		f = v - Number_Points_Of_Polygons(polygon, m);
		c = 0;
		for (i = f, j = v - 1; i < v; j = i++) {
			if ((((verty[i] > testy) != (verty[j] > testy)) &&
				(testx < (vertx[j] - vertx[i]) * (testy - verty[i]) / (verty[j] - verty[i]) + vertx[i])) || ((verty[i] == testy) && (vertx[i] == testx)))
				c = !c;
		}
		if (c == 1)
		{
			if (counter <= 0)
				cout << m;
			else
				cout << ',' << m;
			counter++;
		}
	}
	if (counter == 0)
		cout << "none";
}

int pnpoly(string polygon, int nvert, float *vertx, float *verty, float testx, float testy)
{
	int i, j, c = 0, v = 0, f = 0;
	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v = v + Number_Points_Of_Polygons(polygon, m);
		f = v - Number_Points_Of_Polygons(polygon, m);
		if (m == nvert)
			break;
	}
	for (i = 0, j = nvert - 1; i < nvert; j = i++) {
		if (((verty[i]>testy) != (verty[j]>testy)) &&
			(testx < (vertx[j] - vertx[i]) * (testy - verty[i]) / (verty[j] - verty[i]) + vertx[i]))
			c = !c;
		}
		return c;
	}

string Is_Intersecting(string polygon, float X_points[], float Y_points[], int poly1, int poly2)
{
	int i, v1 = 0, f1 = 0, v2 = 0, f2 = 0, u = 0, p = 0;
	float xp1[50], xp2[50], yp1[50], yp2[50];
	string a = "TRUE", b = "FALSE";
	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v1 = v1 + Number_Points_Of_Polygons(polygon, m);
		f1 = v1 - Number_Points_Of_Polygons(polygon, m);
		if (poly1 == m)
			break;
	}

	for (int m = 1; m <= Number_Polygons(polygon); m++)
	{
		v2 = v2 + Number_Points_Of_Polygons(polygon, m);
		f2 = v2 - Number_Points_Of_Polygons(polygon, m);
		if (poly2 == m)
			break;
	}

	for (int n = f1; n < v1; n++)
	{
		xp1[u] = X_points[n];
		yp1[u] = Y_points[n];
			u++;
	}

	for (int n = f2; n < v2; n++)
	{
		xp2[p] = X_points[n];
		yp2[p] = Y_points[n];
		p++;
	}

	for (i = f1; i < v1; i++)
	{
		if (pnpoly(polygon, poly2, xp2, yp2, X_points[i], Y_points[i]) != 0)
			return a;
	}

	for (i = f2; i < v2; i++)
	{
		if (pnpoly(polygon, poly2, xp1, yp1, X_points[i], Y_points[i]) != 0)
			return a;
	}
	return b;
}

string Intersecting_Group(string polygon, float X_points[], float Y_points[], int arrpolygons[],int s)
{
	int tru = 0;
	for (int i = 0; i < s; i++)
	{
		for (int m = 0; m < s; m++)
		{
			if (Is_Intersecting(polygon, X_points, Y_points, arrpolygons[i], arrpolygons[m]) == "TRUE")
				tru = 1;
			else 
				return "FALSE";
		}
	}
	if (tru==1)
		return "TRUE";
 return "FALSE";
}

void Largest_Intersecting_Pair(string polygon, float X_points[], float Y_points[], float Area[])
{
	int i, v = 0, f = 0, tru = 0, counter = 0, p1=0, p2=0;
	float Max_Sum = 0, Max_Intersect_Sum;
	for (int i = 1; i <= Number_Polygons(polygon); i++)
	{
		for (int m = 1; m <= Number_Polygons(polygon); m++)
		{
			if (i == m)
				continue;

			if (Is_Intersecting(polygon, X_points, Y_points, i, m) == "TRUE")
			{
				Max_Intersect_Sum = Area[m - 1] + Area[i-1];
				if (Max_Intersect_Sum > Max_Sum)
				{
					Max_Sum = Max_Intersect_Sum;
					p1 = i;  p2 = m;
				}
			}
		}
	}
	cout << p1 << ',' << p2;
}

int main()
{
	string polygon, operation, x_array[100], y_array[100], polygons[100][100];
	int s = Total_Number_Points(polygon), RedunNumbPoly[100], output[1000];
	int indx_x = s, indx_y = s, l, a = 0, b = 0, c = 0, indx_poly = 0, indx_points = 0;
	float f1[100], f2[100], float_xy[100][100], area[100];
	cin >> polygon;
	l = polygon.length();
	for (int i = 0; i < l; i++)
	{
		if (polygon[i] == '(')
			a = i;
		
		b = polygon.find(',', a);

		if (polygon[i] == ')')
		{
			c = i;
			x_array[indx_x] = polygon.substr(a + 1, b - a - 1);
			y_array[indx_y] = polygon.substr(b + 1, c - b - 1);
			indx_y++;
			indx_x++;
		}
	}

	for (int j = 0; j < indx_x; j++)
		f1[j] = atof(x_array[j].c_str());

	for (int k = 0; k < indx_y; k++)
		f2[k] = atof(y_array[k].c_str());

	for (int i = 0; i < Total_Number_Points(polygon); i++)
	{
		float_xy[i][0] = f1[i];
		float_xy[i][1] = f2[i];
	}

	for (int i = 0; i < l; i++)
	{
		int	t1 = polygon.find('(', i);
		int	t2 = polygon.find(')', t1);
		polygons[indx_poly][indx_points] = polygon.substr(t1, t2 - t1 + 1);
		i = t2;
		if (polygon[t2 + 1] == ',')
			indx_points++;
		
		if (polygon[t2 + 1] == ';')
		{
			indx_poly++;
			indx_points = 0;
		}
		if (polygon[t2 + 1] == ']')
			break;
	}

	for (int i = 0; i < 100; i++)
	{
		RedunNumbPoly[i] = 0;
		area[i] = 0;
	}

	int counter, m = 0, i = 0, v = 0, f = 0;
	float slope1, slope2, slope3, slope4, d = 0, slopee = 0;

	Non_Redundant_Points(f1, f2, float_xy, polygon);

	for (m = 1; m <= Number_Polygons(polygon); m++)
	{
		counter = 0;
		v = v + Number_Points_Of_Polygons(polygon, m);
		for (i; i < v; i++)
		{
			if (float_xy[i][0] == 2000)
				counter++;
			else
				continue;
		}
		RedunNumbPoly[m-1] = counter;
	}

	for (int i = 1; i <= Number_Polygons(polygon); i++)
		area[i-1] = Polygon_Area( polygon, f1,f2, i);
	
	do {
		getline(cin, operation);

		if (operation == "Number_Polygons")
			cout << Number_Polygons(polygon) << endl;

		else if (operation == "Total_Number_Points")
			cout << Total_Number_Points(polygon) << endl;

		else if (operation == "Minimum_X")
			cout << Minimum_X(f1, polygon) << endl;

		else if (operation == "Minimum_Y")
			cout << Minimum_Y(f2, polygon) << endl;

		else if (operation == "Maximum_X")
			cout << Maximum_X(f1, polygon) << endl;

		else if (operation == "Maximum_Y")
			cout << Maximum_Y(f2, polygon) << endl;

		else if (operation == "Enclosing_Rectangle")
			cout << "(" << Maximum_X(f1, polygon) << "," << Maximum_Y(f2, polygon) << ")" << "(" << Maximum_X(f1, polygon) << "," << Minimum_Y(f2, polygon) << ")" << "(" << Minimum_X(f1, polygon) << "," << Minimum_Y(f2, polygon) << ")" << "(" << Minimum_X(f1, polygon) << "," << Maximum_Y(f2, polygon) << ")" << endl;

		else if (operation == "Total_Redundant_Points")
			if (Total_Redundant_Points(f1, f2, float_xy, RedunNumbPoly, polygon) == 0)
				cout << "none" << endl;
			else
				cout << Total_Redundant_Points(f1, f2, float_xy, RedunNumbPoly, polygon) << endl;

		else if (operation.substr(0, 14) == "Polygon_Points")
		{
			int m = atof((operation.substr(15)).c_str());
			Polygon_Points(polygon, polygons, f1, f2, float_xy, m);
		}

		else if (operation.substr(0, 14) == "Point_Polygons")
		{
			int a, b, c, d;
			a = operation.find('(', 14);
			b = operation.find(',', 14);
			c = operation.find(')', 14);
			string xs = operation.substr(a + 1, b - a - 1);
			string ys = operation.substr(b + 1, c - b - 1);
				float x = atof(xs.c_str());
				float y = atof(ys.c_str());

				Point_Polygons(polygon, RedunNumbPoly, f1, f2, float_xy,x, y);
		}

		else if (operation.substr(0, 25) == "List_Polygons_Points More")
		{
			int m, o = atof((operation.substr(25)).c_str());
			List_Polygons_Points_More(polygon, RedunNumbPoly, f1, f2,o);
		}

		else if (operation.substr(0, 25) == "List_Polygons_Points Less")
		{
			int m, o = atof((operation.substr(25)).c_str());
			List_Polygons_Points_Less(polygon, RedunNumbPoly, f1, f2, o);
		}

		else if (operation.substr(0, 26) == "List_Polygons_Points Equal")
		{
			int m, o = atof((operation.substr(26)).c_str());
			List_Polygons_Points_Equal(polygon, RedunNumbPoly, f1, f2, o);
		}

		else if (operation.substr(0, 25) == "List_Points_Polygons More")
		{
			int m = atof((operation.substr(26)).c_str());
			List_Points_Polygons_More(polygon, f1, f2, m);
		}

		else if (operation.substr(0, 25) == "List_Points_Polygons Less")
		{
			int m = atof((operation.substr(25)).c_str());
			List_Points_Polygons_Less(polygon, f1, f2, m);
		}

		else if (operation.substr(0, 26) == "List_Points_Polygons Equal")
		{
			int m = atof((operation.substr(26)).c_str());
			List_Points_Polygons_Equal(polygon, f1, f2, m);
		}

		else if (operation.substr(0, 17) == "Polygon_Perimeter")
		{
			int m = atof((operation.substr(17)).c_str());
			cout << Polygon_Perimeter(polygon, f1, f2, m);
		}

		else if (operation == "List_Triangles")
			List_Triangles(polygon, RedunNumbPoly, f1, f2);
		
		else if (operation == "List_Rectangles")
			List_Rectangles(polygon, RedunNumbPoly, f1, f2, float_xy);
		
		else if (operation == "List_Trapezoid")
			List_Trapezoid(polygon, RedunNumbPoly, f1, f2, float_xy);
		
		else if (operation.substr(0, 16) == "Inside_Rectangle")
		{
			int a, b, c, d, m = 0, i=16;
			float x[4], y[4];
			for (i; i < operation.length(); i++)
			{
				a = operation.find('(', i);
				b = operation.find(',', a);
				c = operation.find(')', b);
				string xs = " ", ys = " ";
				xs = operation.substr(a + 1, b - a - 1);
				ys = operation.substr(b + 1, c - b - 1);
				if ((xs != " ") && (ys != " "))
				{
					x[m] = atof(xs.c_str());
					y[m] = atof(ys.c_str());
					m++;
				}
				if (m == 4)
					break;
				i = c;
			}
			Inside_Rectangle(polygon, RedunNumbPoly, f1, f2, float_xy, x, y);
		}

		else if (operation.substr(0, 13) == "Inside_Circle")
		{
			string XR = operation.substr(15, operation.find(',', 13) - 1);
			string YR = operation.substr(operation.find(',', 13) + 1, (operation.find(')', 13) - operation.find(',', 13) + 1));
			string R = operation.substr(operation.find(',', operation.find(')', 13)) + 1);
			float xr = atof(XR.c_str());
			float yr = atof(YR.c_str());
			float r = atof(R.c_str());
			Inside_Circle(polygon, f1, f2, float_xy, xr, yr, r);
		}

		else if (operation.substr(0, 12) == "Polygon_Area")
		{
			int m = atof((operation.substr(12)).c_str());
			cout << Polygon_Area(polygon, f1, f2, m);
		}

		else if (operation.substr(0, 19) == "Polygons_Area_Range")
		{
			string XA = operation.substr(19, operation.find(',', 19) - 1);
			string YA = operation.substr(operation.find(',', 19) + 1);
			float min = atof(XA.c_str());
			float max = atof(YA.c_str());
			Polygons_Area_Range(polygon, f1, f2, m, max, min);
		}
		
		else if (operation.substr(0, 24) == "Polygons_Enclosing_Point")
		{
			int a, b, c, d, counter = 0, u;
			a = operation.find('(', 24);
			b = operation.find(',', 24);
			c = operation.find(')', 24);
			string xs = operation.substr(a + 1, b - a - 1);
			string ys = operation.substr(b + 1, c - b - 1);
			float x = atof(xs.c_str());
			float y = atof(ys.c_str());

			Polygons_Enclosing_Point(polygon, f1, f2, x, y);
		}

		else if (operation.substr(0, 15) == "Is_Intersecting")
		{
			string XA = operation.substr(15, operation.find(',', 15) - 1);
			string YA = operation.substr(operation.find(',', 15) + 1);
			int p1 = atof(XA.c_str());
			int p2 = atof(YA.c_str());
			cout << Is_Intersecting(polygon, f1, f2, p1, p2) << endl;
		}

		else if (operation.substr(0, 18) == "Intersecting_Group")
		{
			int arrpolygons[20], i = 18, m = 1,u=0;
			string xs = " ", ys = " ";
			ys = operation.substr(19, 19 - a - 1);
			arrpolygons[0] = atof(ys.c_str());

			for (int b=18; b < operation.length(); b++)
			{
				if (operation[b] == ',')
					u++;
			}
			for (i; i < operation.length(); i++)
			{
				a = operation.find(',', i);				
				xs = operation.substr(a + 1);
				if ((xs != " "))
				{
					arrpolygons[m] = atof(xs.c_str());
					m++;
				}
				i = a;
				if (m == u+1)
					break;
			}
			cout << Intersecting_Group(polygon, f1, f2, arrpolygons, m) << endl;
		}
		
		else if (operation == "Largest_Intersecting_Pair")
		{
			Largest_Intersecting_Pair(polygon, f1, f2, area);
		}

	} while (operation != "Quit");

	return 0;
}