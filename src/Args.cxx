/*
 * Filename:    Args.cxx
 *
 * Description: Source file of namespace Args.
 *
 * Author:      Spyridon Tsalikis.
 * Created on   6/10/19.
 */

#include <iostream>
#include "CLI11.hpp"
#include "Args.hxx"


namespace Args
{
    ////////////////////////////////////////////
    // CLI Arguments
    ////////////////////////////////////////////
    std::string inputFileName;
    std::string outputFileName;
    ////////////////////////////////////////////

    /**
     * @brief Parse Command line Arguments.
     *
     * @return 0 on success , otherwise CLI11 error code
     */
    int parseArguments(int argc, char** argv)
    {
        constexpr char DESCRIPTION[] = "TriangulateMonotonePolygon";

        // Initialize CLI application
        std::unique_ptr<CLI::App> app = std::make_unique<CLI::App>(DESCRIPTION);

        ////////////////////////////////////////////
        // Add CLI Argument Options
        ////////////////////////////////////////////
        //  --------------------------------------------------------------------------  *

        app->add_option("-i,--input", inputFileName, "Input file to triangulate.\n")
                ->required()
                ->check(CLI::ExistingFile);

        app->add_option("-o,--output", outputFileName,
                        "Output file that includes triangulation.\n")
                ->required();

        try {
            app->parse(argc, argv);
        }
        catch (const CLI::CallForHelp& e) {
            std::cout << app->help();
            return 1;
        }
        catch (const CLI::CallForAllHelp& e) {
            std::cout << app->help();
            return 1;
        }
        catch (const CLI::ParseError& e) {
            return app->exit(e);
        }

        return 0;
    }

    /**
     * @brief Display TriangulateMonotonePolygon argument values.
     *
     * @param out Output stream to pipe output to
     */
    void display(std::ostream& out = std::cout)
    {
        constexpr char SEPARATOR[] = "================================================";
        out << "TriangulateMonotonePolygon Argument Values" << '\n';
        out << SEPARATOR << '\n';
        out << "Input Image: " << inputFileName << '\n';
        out << "Output Mesh: " << outputFileName << '\n';
        out << SEPARATOR << '\n';
    }
}

