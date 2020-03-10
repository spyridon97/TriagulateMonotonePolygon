/*
 * Filename:    Mesh.hxx
 *
 * Description: Header file of Mesh struct.
 *
 * Author:      Spyridon Tsalikis
 * Created on   3/2/2020.
 */

#ifndef TRIANGULATEMONOTONEPOLYGON_MESH_HXX
#define TRIANGULATEMONOTONEPOLYGON_MESH_HXX


#include <vector>


struct Mesh
{
    struct Point
    {
        //  coordinate of point
        double coordinates[2];

        //  a boolean value which indicates if a point is on the left chain
        bool onLeftChain;

        //  a boolean value which indicates if a point is on the right chain
        bool onRightChain;

        //  id on the global points vector (+1)
        size_t id;

        //  id on the leftChainId points vector
        size_t leftChainId;

        //  id on the rightChainId points vector
        size_t rightChainId;

        //  check if two points are on the same chain.
        bool sameChain(const Point& point)
        {
            return this->onRightChain == point.onRightChain || this->onLeftChain == point.onLeftChain;
        }
    };

    struct Edge
    {
        //  id of point 1
        size_t pointIndex1;

        //  id of point 2
        size_t pointIndex2;
    };

    size_t numberOfPoints;

    std::vector<Point> points;
    std::vector<Point> rightChainPoints;
    std::vector<Point> leftChainPoints;

    std::vector<Edge> edges;
};


#endif /* TRIANGULATEMONOTONEPOLYGON_MESH_HXX */
