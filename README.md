# Triangulate Monotone Polygon

--------------------------------------------------------------------------------
## Description

Given a Y-Monotone Polygon, using a greedy algorithm we can triangulate it.

There is no warranty whatsoever. Use at your own risk.

--------------------------------------------------------------------------------
## Programming Language & Build System
* C++, (v17 or newer)
* CMAKE/CCMAKE, (v3.1 or newer)

--------------------------------------------------------------------------------
## Structure of repository
*   InputFiles:
    *   This directory includes input files.
*   include/src:
    *   This directory contains the header and sources files of the TriangulateMonotonePolygon program.
*   .gitignore
    *   This file includes what git should ignore.
*   CmakeLists.txt
    *   This file defines the building properties of this Repository.
*   LICENCE
    *   The file which includes the GNU 3 Licence.
*   README.md            
    *   This file.
*   Requirements.md            
    *   This file includes the requirements of the library along with the upcoming functionality that needs to be implemented.

--------------------------------------------------------------------------------
## Installation & Compilation
* create a build directory inside the root of this project
* cd into the build directory
* `cmake  ..`

--------------------------------------------------------------------------------
## Input and Output files of PODM
Input files format:
*   First line: n 
    *   which is an integer specifying the number of vertices in the polygon.
*  n lines: x y l r
    *   where x and y (real) are coordinates of each vertex, l and r (0 or 1) are boolean values indicating
        whether the vertex belongs to the left and/or to the right chain. The vertices are sorted in the order
        of decreasing y coordinate. Your code is not required to handle duplicate y coordinates, however,
        if it does it certainly is a good feature to have.
*   n lines: i j
    *   These are the indices of the end vertices for each edge. All indices in the input/output start with 1
        (not 0!).

Output files
* [.poly](http://www.cs.cmu.edu/~quake/triangle.poly.html) which can be visualized using [ShowMe](http://www.cs.cmu.edu/~quake/showme.html).

--------------------------------------------------------------------------------
## Usage
```
TriangulateMonotonePolygon
Usage: ./triangulateMonotonePolygon [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  -i,--input TEXT:FILE REQUIRED
                              Input file to triangulate.

  -o,--output TEXT REQUIRED   Output file that includes triangulation.
```

--------------------------------------------------------------------------------
## Contact Information
```
Maintainers:
    Spyridon Tsalikis
    Department of Computer Science,
    Old Dominion University,
    5115 Hampton Blvd, Norfolk, VA 23529, USA,
    email: stsaliki@odu.edu

Supervisor:
    Nikos P. Chrisochoides,
    Department of Computer Science,
    Old Dominion University,
    5115 Hampton Blvd, Norfolk, VA 23529, USA,
    phone: +1-757-683-7715,
    email: nchrisoc@odu.edu
```
--------------------------------------------------------------------------------
Copyright (C) 2020 Spyridon Tsalikis
