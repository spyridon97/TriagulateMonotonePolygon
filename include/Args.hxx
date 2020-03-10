/*
 * Filename:    Args.hxx
 *
 * Description: Header file of namespace Args.
 *
 * Author:      Spyridon Tsalikis
 * Created on   9/10/19.
 */

#ifndef REMOVELABELFROMIMAGE_ARGS_HXX
#define REMOVELABELFROMIMAGE_ARGS_HXX


#include <iosfwd>
#include <string>

/**
 * @brief Facilitates CLI argument parsing
 * and holds CLI argument and configuration values.
 */
namespace Args
{
    ////////////////////////////////////////////
    // CLI Arguments
    ////////////////////////////////////////////
    extern std::string inputFileName;
    extern std::string outputFileName;

    /**
     * @brief Parse Command line Arguments.
     */
    int parseArguments(int argc, char** argv);

    /**
     * @brief Display TriangulateMonotonePolygon argument values.
     */
    void display(std::ostream& out);
}


#endif /* PODM_ARGS_HXX */
