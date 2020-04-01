/*
 * Filename:    Io.cxx
 * 
 * Description: Source file of namespace IO.
 *
 * Author:      Spyridon Tsalikis.
 * Created on   2/25/2020.
 */

#include <fstream>
#include <iostream>
#include "IO.hxx"


namespace IO
{
    Mesh readInputMesh(const std::string& filename)
    {
        Mesh mesh;

        std::ifstream inputFile;
        inputFile.open(filename.c_str());

        if (inputFile) {
            inputFile >> mesh.numberOfPoints;
            mesh.points.reserve(mesh.numberOfPoints);

            size_t leftChainCounter = 0;
            size_t rightChainCounter = 0;
            for (size_t i = 0; i < mesh.numberOfPoints; i++) {
                Mesh::Point point{};
                inputFile >> point.coordinates[0] >> point.coordinates[1] >> point.onLeftChain >> point.onRightChain;
                point.id = i + 1;

                if (point.onLeftChain) {
                    point.leftChainId = leftChainCounter;
                    mesh.leftChainPoints.push_back(point);
                    leftChainCounter++;
                }
                if (point.onRightChain) {
                    point.rightChainId = rightChainCounter;
                    mesh.rightChainPoints.push_back(point);
                    rightChainCounter++;
                }

                mesh.points.push_back(point);
            }

            for (size_t i = 0; i < mesh.numberOfPoints; i++) {
                Mesh::Edge edge{};
                inputFile >> edge.pointIndex1 >> edge.pointIndex2;
                mesh.edges.push_back(edge);
            }
        } else {
            std::cerr << "Could not open " << filename << " file" << std::endl;
            exit(1);
        }

        return mesh;
    }

    void writeTriangulatedMesh(const Mesh& mesh, const std::string& filename)
    {
        std::ofstream outputFile;
        outputFile.open(filename.c_str());

        if (outputFile) {
            outputFile << mesh.numberOfPoints << " 2 0 0" << std::endl;

            //  print points
            for (size_t i = 0; i < mesh.numberOfPoints; i++) {
                outputFile << i + 1 << " " << mesh.points[i].coordinates[0] << " " << mesh.points[i].coordinates[1]
                           << std::endl;
            }

            outputFile << mesh.edges.size() << " 0" << std::endl;

            //  print segments
            size_t counter = 1;
            for (Mesh::Edge edge : mesh.edges) {
                outputFile << counter << " " << edge.pointIndex1 << " " << edge.pointIndex2 << std::endl;
                counter++;
            }

            outputFile << "0" << std::endl;
        } else {
            std::cerr << "Could not open " << filename << " file" << std::endl;
            exit(1);
        }
    }
}
