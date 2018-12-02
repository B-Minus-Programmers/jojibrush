#pragma once
#include "GeometricShape.hpp"

namespace jbrush
{
class Polyline final : public GeometricShape
{
public:
    /* Constructors */
    /**
     * Creates a polyline from a set of points
     * @param points a pointer to multiple points, used as the vertices of the polyline
     * @param pointCount number of points in the `points` array
     * @param props the shape properties, which adjust shape color and style
     */
    Polyline(const QPoint* const points, uint32_t pointCount, GeometricShapeProperties props = DEFAULT_GEOMETRIC_PROPS);

    /* Destructor */
    ~Polyline() override;

    /* Getters */

    /**
     * Returns a point from a given index
     * @param i index of the point to return
     * @returns the i'th point of the polyline
     */
    QPoint getPoint(uint32_t i) const;

    /**
     * Returns the number of points in the polyline
     * @returns number of points
     */
    uint32_t getPointCount() const;

    /* Setters */

    /**
     * Replaces a point of the polyline with another point
     * @param index index of the point to remove
     * @param point point to replace the removed point with
     */
    void setPoint(uint32_t index, const QPoint& point);

    /**
     * Replaces all points of the polyline
     * @param points a pointer to multiple points, used as the vertices of the polyline
     * @param pointCount number of points in the `points` array
     */
    void setPoints(const QPoint* const points, uint32_t pointCount);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Polyline Information */

    /**
     * Returns -1, as area is not defined for a polyline
     * @returns -1
     */
    virtual double area() const override;

    /**
     * Returns -1, as perimeter is not defined for a polyline
     * @returns -1
     */
    virtual double perimeter() const override;
    virtual std::string toString() const override;

private:
    QPoint*  points;
    uint32_t pointCount;
};
}
