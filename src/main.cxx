/*
 * Filename:    main.cxx
 *
 * Description: File that contains the main function.
 *
 * Author:      Spyridon Tsalikis
 * Created on   02/26/20.
 */

#include <iostream>
#include "Args.hxx"
#include "IO.hxx"
#include "TriangulationMonotonePolygon.hxx"


int main(int argc, char** argv)
{
    //  Parse CLI arguments
    int result = Args::parseArguments(argc, argv);
    if (result != 0) {
        return 1;
    }
    Args::display(std::cout);

    Mesh inputMesh = IO::readInputMesh(Args::inputFileName);

    TriangulationMonotonePolygon triangulation = TriangulationMonotonePolygon();
    const Mesh outputMesh = triangulation.generateTriangulation(inputMesh);

    IO::writeTriangulatedMesh(outputMesh, Args::outputFileName);

    return EXIT_SUCCESS;
}
