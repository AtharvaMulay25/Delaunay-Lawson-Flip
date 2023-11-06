#include "../include/edge.hpp"

edge::edge() {}

edge::~edge() {}

edge::edge(point a, point b) {
    start = a, end = b;
}

point edge::get_start() {
    return start;
}

point edge::get_end() {
    return end;
}

bool edge::operator==(const edge &other) {
    if ((this->start == other.start) && (this->end == other.end)) {
        return true;
    }

    if ((this->end == other.start) && (this->start == other.end)) {
        return true;
    }

    return false;
}