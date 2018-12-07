#pragma once

#include <functional>
#include <QTextStream>

#include "../shapes/Shape.hpp"
#include "vector.hpp"

using jbrush::Vector;
using jbrush::Shape;

namespace jbrush {

int compareId(const Shape*, const Shape*);
int compareArea(const Shape*, const Shape*);
int comparePerimeter(const Shape*, const Shape*);

void getTo(QTextStream&, const QChar&);

template <typename T>
void sort(T* start, T* end, std::function<int(const Shape*, const Shape*)> cmp)
{
    T* min;
    for(T* tmp = start; tmp != end; ++tmp)
    {
        min = tmp;
        for(T* tmp2 = tmp + 1; tmp2 != end; ++tmp2)
        {
          if(cmp(*tmp2, *min) < 0) std::swap(*tmp2, *min);
        }
    }
}
}
