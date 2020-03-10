/*
 * Filename:    TriangulationMonotonePolygon.hxx
 * 
 * Description: Header file of TriangulateMonotonePolygon class.
 *
 * Author:      Spyridon Tsalikis
 * Created on   3/2/20.
 */

#ifndef TRIANGULATEMONOTONEPOLYGON_TRIANGULATIONMONOTONEPOLYGON_HXX
#define TRIANGULATEMONOTONEPOLYGON_TRIANGULATIONMONOTONEPOLYGON_HXX


#include "Mesh.hxx"


class TriangulationMonotonePolygon
{
public:
    using Point = Mesh::Point;
    using Edge = Mesh::Edge;

    TriangulationMonotonePolygon();

    ~TriangulationMonotonePolygon();

    static Mesh generateTriangulation(Mesh& inputMesh);

private:
    static bool diagonalInsidePolygon(Point& edgePoint1, Point& edgePoint2, Point& pointOnStack);
};


#endif /* TRIANGULATEMONOTONEPOLYGON_TRIANGULATIONMONOTONEPOLYGON_HXX */
