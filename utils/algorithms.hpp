#pragma once

#include <functional>

#include "../shapes/shape.hpp"
#include "vector.hpp"

using jbrush::Vector;
using jbrush::Shape;

namespace jbrush {
using Comparator = std::function<int(const Shape*, const Shape*)>;

int compareId(const Shape*, const Shape*);
int compareArea(const Shape*, const Shape*);
int comparePerimeter(const Shape*, const Shape*);
void sort(Vector<Shape*>&, Comparator = compareId);
}