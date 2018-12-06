#include "algorithms.hpp"
#include <QDebug>

using jbrush::Comparator;

namespace jbrush {

int compareId(const Shape* a, const Shape* b)
{
    return a->getId() - b->getId();
}

int compareArea(const Shape* a, const Shape* b)
{
    return a->area() - b->area();
}

int comparePerimeter(const Shape* a, const Shape* b)
{
    return a->perimeter() - b->perimeter();
}

void sort(Vector<Shape*>& vector, Comparator cmp)
{
    if (vector.getSize() == 0) return;

    uint32_t min;
    for (uint32_t i = 0; i < vector.getSize() - 1; i++)
    {
        min = i;
        for (uint32_t j = i + 1; j < vector.getSize(); j++)
        {
            if (cmp(vector[j], vector[min]) < 0)
            {
                min = j;
            }
        }

        std::swap(vector[min], vector[i]);
    }
}

// Moves the text stream up to the character specified
void getTo(QTextStream &qin, const QChar &target)
{
    QChar buffer;

    do
    {
        qin >> buffer;
    }while(buffer != target && !qin.atEnd());
}

}

