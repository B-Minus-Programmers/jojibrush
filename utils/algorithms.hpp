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

template <typename T>
void sort(T*, T*, std::function<int(const T, const T)> = compareId);

void getTo(QTextStream&, const QChar&);

template <typename T>
void sort(T* start, T* end, std::function<int(const T, const T)> cmp)
{
    T* min;

    while (start != end)
    {
        if (cmp(*start, *min) < 0)
        {
            min = start;
        }

        std::iter_swap(min, start);
    }
}
}
