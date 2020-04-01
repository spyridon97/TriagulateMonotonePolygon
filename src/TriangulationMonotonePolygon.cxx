/*
 * Filename:    TriangulationMonotonePolygon.cxx
 * 
 * Description: Source file of TriangulationMonotonePolygon class.
 *
 * Author:      Spyridon Tsalikis
 * Created on   3/2/20.
 */

#include <stack>
#include "TriangulationMonotonePolygon.hxx"


extern "C" {
#define REAL double
void exactinit();
REAL orient2d(REAL* pa, REAL* pb, REAL* pc);
}


TriangulationMonotonePolygon::TriangulationMonotonePolygon()
{
    exactinit();
}

TriangulationMonotonePolygon::~TriangulationMonotonePolygon() = default;

bool TriangulationMonotonePolygon::diagonalInsidePolygon(Point& edgePoint1, Point& edgePoint2, Point& pointOnStack)
{
    double orientationTestValue = orient2d(edgePoint1.coordinates, edgePoint2.coordinates, pointOnStack.coordinates);
    if (edgePoint2.onLeftChain) {
        return orientationTestValue > 0;
    } else {
        return orientationTestValue < 0;
    }
}

Mesh TriangulationMonotonePolygon::generateTriangulation(Mesh& inputMesh)
{
    //  initialize stack of points
    std::stack<Point> stackOfPoints{};

    stackOfPoints.push(inputMesh.points[0]);
    stackOfPoints.push(inputMesh.points[1]);

    for (size_t i = 2; i < inputMesh.numberOfPoints - 1; i++) {
        if (!inputMesh.points[i].sameChain(stackOfPoints.top())) {
            std::stack<Point> poppedPoints{};

            //  pop all points
            while (!stackOfPoints.empty()) {
                auto point = stackOfPoints.top();
                stackOfPoints.pop();
                //  preserve every point apart from the last one
                if (!stackOfPoints.empty()) {
                    poppedPoints.push(point);
                }
            }

            //  insert diagonals from all preserved popped points to currentPoint
            while (!poppedPoints.empty()) {
                auto point = poppedPoints.top();
                poppedPoints.pop();

                Edge edge{};
                edge.pointIndex1 = point.id;
                edge.pointIndex2 = inputMesh.points[i].id;
                inputMesh.edges.push_back(edge);
            }

            //  push points u[i - 1] and u[i] to the stack
            stackOfPoints.push(inputMesh.points[i - 1]);
            stackOfPoints.push(inputMesh.points[i]);
        } else {
            std::stack<Point> poppedPoints{};

            //  pop one point
            poppedPoints.push(stackOfPoints.top());
            stackOfPoints.pop();

            Point edgePoint1;
            Point edgePoint2 = inputMesh.points[i];
            //  get the previous point of edgePoint2 that is in the same chain as edgePoint2
            if (edgePoint2.onLeftChain) {
                edgePoint1 = inputMesh.leftChainPoints[edgePoint2.leftChainId - 1];
            } else {
                edgePoint1 = inputMesh.rightChainPoints[edgePoint2.rightChainId - 1];
            }

            while (!stackOfPoints.empty() && diagonalInsidePolygon(edgePoint1, edgePoint2, stackOfPoints.top())) {
                auto pointWithCorrectDiagonal = stackOfPoints.top();
                poppedPoints.push(pointWithCorrectDiagonal);
                stackOfPoints.pop();

                Edge edge{};
                edge.pointIndex1 = pointWithCorrectDiagonal.id;
                edge.pointIndex2 = edgePoint2.id;
                inputMesh.edges.push_back(edge);
            }

            //  push the last point that has been popped
            stackOfPoints.push(poppedPoints.top());

            //  push point u[i] to the stack
            stackOfPoints.push(inputMesh.points[i]);
        }
    }

    //  pop first point in stack
    stackOfPoints.pop();

    auto lastPoint = inputMesh.points[inputMesh.points.size() - 1];

    //  add diagonals from the last point to all stack vertices
    //  except the first (which has been popped already) and the last one
    while (!stackOfPoints.empty()) {
        auto point = stackOfPoints.top();
        stackOfPoints.pop();

        //  if it's not the last point in stack, insert a diagonal
        if (!stackOfPoints.empty()) {
            Edge edge{};
            edge.pointIndex1 = point.id;
            edge.pointIndex2 = lastPoint.id;
            inputMesh.edges.push_back(edge);
        }
    }

    return inputMesh;
}
