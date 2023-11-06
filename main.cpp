#include <fstream>
#include <vector>

#include "./include/edge.hpp"
#include "./include/point.hpp"
#include "./include/triangle.hpp"

using namespace std;

int n;
const int NMAX = 1000;

vector<triangle> triangles;

ifstream in("./input.txt");
ofstream out("./output.txt");

// Reads the input data into a vector of triangles.
void read_data(vector<triangle>& triangles) {
    int x1, y1, x2, y2, i;
    edge e1, e2, e3;

    in >> n;

    for (i = 0; i < n; ++i) {
        in >> x1 >> y1 >> x2 >> y2;
        edge e1(point(x1, y1), point(x2, y2));

        in >> x1 >> y1 >> x2 >> y2;
        edge e2(point(x1, y1), point(x2, y2));

        in >> x1 >> y1 >> x2 >> y2;
        edge e3(point(x1, y1), point(x2, y2));

        triangle temp(e1, e2, e3);
        triangles.push_back(temp);
    }
}

// Prints the triangulation data to the output file.
void print_triangulation(const vector<triangle>& triangles) {
    out << n << "\n";

    for (const triangle& triangle : triangles) {
        out << triangle.e1.start.x << ' ' << triangle.e1.start.y << ' ' << triangle.e1.end.x << ' ' << triangle.e1.end.y << '\n';
        out << triangle.e2.start.x << ' ' << triangle.e2.start.y << ' ' << triangle.e2.end.x << ' ' << triangle.e2.end.y << '\n';
        out << triangle.e3.start.x << ' ' << triangle.e3.start.y << ' ' << triangle.e3.end.x << ' ' << triangle.e3.end.y << "\n\n";
    }
}

// Checks if triangles i and j share a common edge.
bool common_edge(int i, int j, const vector<triangle>& triangles) {
    if (i != j) {
        return triangle::common_edge(triangles[i], triangles[j]);
    }

    return false;
}

// Tests if a flip is possible between triangles i and j and performs it if possible.
bool test_flip(int i, int j, vector<triangle>& triangles) {
    return triangle::test_flip(triangles[i], triangles[j]);
}

// Performs Delaunay triangulation on the input data.
void delaunay_triangulation(vector<triangle>& triangles) {
    int i, j;
    bool flipped = true;

    while (flipped) {
        flipped = false;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (common_edge(i, j, triangles) && test_flip(i, j, triangles)) {
                    flipped = true;
                }
            }
        }
    }

    triangle::ended();
}

int main() {
    read_data(triangles);
    delaunay_triangulation(triangles);
    print_triangulation(triangles);
    out << "-------------------- End --------------------\n\n";
}