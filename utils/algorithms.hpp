#pragma once

#include <functional>
#include <QTextStream>

#include "../shapes/Shape.hpp"
#include "vector.hpp"

using jbrush::Vector;
using jbrush::Shape;

namespace jbrush {

template <typename T>
using Comparator = std::function<int(const T, const T)>;

int compareId(const Shape*, const Shape*);
int compareArea(const Shape*, const Shape*);
int comparePerimeter(const Shape*, const Shape*);

template <typename T>
void sort(typename Vector<T>::iterator, typename Vector<T>::iterator, Comparator<T> = compareId);

void getTo(QTextStream&, const QChar&);

template <typename T>
void sort(typename Vector<T>::iterator start, typename Vector<T>::iterator end, Comparator<T> cmp)
{
    typename Vector<T>::iterator min;

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
