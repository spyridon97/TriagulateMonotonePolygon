/*
 * Filename:    Io.hxx
 * 
 * Description: Header file of namespace IO.
 *
 * Author:      Spyridon Tsalikis
 * Created on   2/25/2020.
 */

#ifndef TRIANGULATEMONOTONEPOLYGON_IO_HXX
#define TRIANGULATEMONOTONEPOLYGON_IO_HXX


#include <string>
#include "Mesh.hxx"


namespace IO
{
    Mesh readInputMesh(const std::string& filename);

    void writeTriangulatedMesh(const Mesh& mesh, const std::string& filename);
}


#endif /* TRIANGULATEMONOTONEPOLYGON_IO_HXX */
