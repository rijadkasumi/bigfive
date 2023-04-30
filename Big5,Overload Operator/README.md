# Rijad Kasumi - rijad.kasumi11@myhunter.cuny.edu
# Date 09-09-2022
# Assignment 1
# CSCI 335 Software Analysis and Design 3
# The main focus of this program is the creating of a Points2D class and implementation of Big Five and Overload Operators so we can read sequences of two dimensional array of points.
# The requirement of the assignment was to modify the points2d.h file.
# Implementation of Big Five (The Desctructor, Copy Constructor, Copy Assignment Operator, Move Constructor, Move Assignment Operator)
# Implementation of Overload Operators (Inseriton Operator(<<), Extraction Operator(>>), Additon Operator (+), Operator[])
# The program was tested locally on a Mac Machine and the program's requirements were properly completed and the program is exectuded as expected.

# Information about the repository

This repository contains the following:
- Starter code: `points2d.h`, `points2d.cc`, `test_points2d.cc`,`test_input_file.txt`, `expected_output.txt`, `Makefile` and `README.md`
- Assignment specification: `Fall22-Assignment1.pdf`
- Testing Document: `Testing_Document.pdf`

## Running the assignment

You will use this exact `Makefile` for your Assignment 1. Failure to do so will result in *deduction* of points.

To compile on terminal, type:

```bash
make clean
make all
```

To delete executables and object files, type:

```bash
make clean
```

To run, type:

```bash
./test_points3d
```

## Providing Input from Standard Input

To run with a given file that is redirected to standard input:

```bash
./test_points2d < test_input_file.txt
```
