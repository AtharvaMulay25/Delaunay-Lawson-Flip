#ifndef EDGE_H
#define EDGE_H

#include "point.hpp"

class edge {
   public:
    point start, end;

    edge();
    edge(point a, point b);
    point get_start();
    point get_end();
    virtual ~edge();
    bool operator==(const edge &other);
};

#endif