#include "algorithms.hpp"

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

