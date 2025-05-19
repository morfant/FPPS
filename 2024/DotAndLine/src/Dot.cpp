#include "Dot.h"
#include "Line.h"

Line Dot::operator+(Dot* other) {
    return Line(this, other);
}
