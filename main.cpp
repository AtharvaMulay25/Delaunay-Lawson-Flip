#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include "./headers/point.h"
#include "./headers/edge.h"
#include "./headers/triangle.h"
#include "./lib/point.cpp"
#include "./lib/edge.cpp"
#include "./lib/triangle.cpp"


using namespace std;

const int NMAX = 1000;

vector<triangle> T;
int n;

ifstream in("./input/input.txt");
ofstream out("./output/output.txt");

void read_data(vector<triangle> &t)
{
    int x1, y1;
    int x2, y2;
    int i;
    edge e1, e2, e3;

    in >> n;

    for (i = 0; i < n; ++i)
    {
        in >> x1 >> y1 >> x2 >> y2;
        edge e1(point(x1, y1), point(x2, y2));
        in >> x1 >> y1 >> x2 >> y2;
        edge e2(point(x1, y1), point(x2, y2));
        in >> x1 >> y1 >> x2 >> y2;
        edge e3(point(x1, y1), point(x2, y2));

        triangle temp(e1, e2, e3);
        t.push_back(temp);
    }
}

void print_triangulation(vector<triangle> &t)
{
    out<<n<<"\n";
    int i;
    for (i = 0; i < n; ++i)
    {
        out << t[i].e1.start.x << ' ' << t[i].e1.start.y << ' ' << t[i].e1.end.x << ' ' << t[i].e1.end.y << '\n';
        out << t[i].e2.start.x << ' ' << t[i].e2.start.y << ' ' << t[i].e2.end.x << ' ' << t[i].e2.end.y << '\n';
        out << t[i].e3.start.x << ' ' << t[i].e3.start.y << ' ' << t[i].e3.end.x << ' ' << t[i].e3.end.y << '\n';

        out << '\n';
    }
}

bool common_edge(int i, int j, vector<triangle> &t)
{
    if (i != j)
        return triangle::common_edge(t[i], t[j]);
    return false;
}

bool test_flip(int i, int j, vector<triangle> &t)
{
    return triangle::test_flip(t[i], t[j]);
}

void delaunay_triangluation(vector<triangle> &t)
{
    int i, j;
    bool flipped = true;

    while (flipped)
    {
        flipped = false;
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                if (common_edge(i, j, t))
                {
                    if (test_flip(i, j, t))
                        flipped = true;
                }
    }
    triangle::ended();
}

int main()
{
    read_data(T);
    delaunay_triangluation(T);
    print_triangulation(T);
    out << "---end---\n\n";
}