#include "algorithms.hpp"

using jbrush::Comparator;

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
