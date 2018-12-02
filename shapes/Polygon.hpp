#pragma once
#include "FilledShape.hpp"

namespace jbrush
{
class Polygon final : public FilledShape
{
public:
    /* Constructors */
    /**
     * Creates a polygon from an array of points
     * @param points a pointer to multiple points, used as the vertices of the polygon
     * @param pointCount number of points in the `points` array
     * @param props the shape properties, which adjust shape color and style
     */
    Polygon(const QPoint* const points, uint32_t pointCount, FilledShapeProperties props = DEFAULT_FILLED_PROPS);

    /* Destructor */
    ~Polygon() override;

    /* Getters */

    /**
     * Returns a specified vertex of the polygon
     * @param num the index of the vertex to return
     * @returns the i'th vertex of the polygon
     */
    QPoint getPoint(uint32_t i) const;

    /**
     * Returns the number of vertices of the polygon
     * @returns the number of vertices
     */
    uint32_t getPointCount() const;

    /* Setters */

    /**
     * Replaces one of the polygon's vertices with another
     * @param index the index of the existing vertex to replace
     * @param point the position of the new vertex
     */
    void setPoint(uint32_t index, const QPoint& point);

    /**
     * Replaces all vertices with an array of vertices
     * @param points positions for each of the new vertices
     * @param pointCount number of points in the `points` array
     */
    void setPoints(const QPoint* const points, uint32_t pointCount);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Polygon Information */

    /**
     * Calculates the polygon's area with the [shoelace formula](https://en.wikipedia.org/wiki/Shoelace_formula)
     * @returns the area of the polygon
     */
    virtual double area() const override;

    /**
     * Calculates the perimeter of the polygon
     * @returns the perimeter of the polygon
     */
    virtual double perimeter() const override;
    virtual std::string toString() const override;

private:
    QPoint*  points;
    uint32_t pointCount;
};
}
