/*MIT License

Copyright(c) 2020 Thibaut Vidal

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

#include <iostream>
#include <string>
#include <climits>

class CommandLine
{
public:

	int nbIter		= 20000;		// Number of iterations without improvement until termination. Default value: 20,000 iterations
	int timeLimit   = INT_MAX;		// CPU time limit until termination in seconds. Default value: infinity
	int seed		= 0;			// Random seed. Default value: 0
	int nbVeh		= INT_MAX;		// Number of vehicles. Default value: infinity
	std::string pathInstance;		// Instance path
	std::string pathSolution;		// Solution path
	std::string pathBKS = "";		// BKS path

	// Reads the line of command and extracts possible options
	CommandLine(int argc, char* argv[])
	{
//		if (argc % 2 != 1 || argc > 13 || argc < 3)
//		{
//			std::cout << "----- NUMBER OF COMMANDLINE ARGUMENTS IS INCORRECT: " << argc << std::endl;
//			display_help(); throw std::string("Incorrect line of command");
//		}
//		else
//		{
			pathInstance = std::string(argv[1]);
			pathSolution = std::string(argv[2]);
//			for (int i = 3; i < argc; i += 2)
//			{
//				if (std::string(argv[i]) == "-t")
//					timeLimit = atoi(argv[i+1]);
//				else if (std::string(argv[i]) == "-it")
//					nbIter  = atoi(argv[i+1]);
//				else if (std::string(argv[i]) == "-bks")
//					pathBKS = std::string(argv[i+1]);
//				else if (std::string(argv[i]) == "-seed")
//					seed    = atoi(argv[i+1]);
//				else if (std::string(argv[i]) == "-veh")
//					nbVeh = atoi(argv[i+1]);
//				else
//				{
//					std::cout << "----- ARGUMENT NOT RECOGNIZED: " << std::string(argv[i]) << std::endl;
//					display_help(); throw std::string("Incorrect line of command");
//				}
//			}
//		}
	}

	// Printing information about how to use the code
	void display_help()
	{
		std::cout << std::endl;
		std::cout << "-------------------------------------------------- HGS-CVRP algorithm (2020) --------------------------------------------------" << std::endl;
		std::cout << "Call with: ./genvrp instancePath solPath [-it nbIter] [-t myCPUtime] [-bks bksPath] [-seed mySeed] [-veh nbVehicles]           " << std::endl;
		std::cout << "[-it nbIterations] sets a maximum number of iterations without improvement. Defaults to 20,000                                 " << std::endl;
		std::cout << "[-t myCPUtime] sets a time limit in seconds. If this parameter is set the code will be run iteratively until the time limit    " << std::endl;
		std::cout << "[-bks bksPath] sets an optional path to a BKS. This file will be overwritten in case of improvement                            " << std::endl;
		std::cout << "[-seed mySeed] sets a fixed seed. Defaults to 0                                                                                " << std::endl;
		std::cout << "[-veh nbVehicles] sets a prescribed fleet size. Otherwise a reasonable UB on the the fleet size is calculated                  " << std::endl;
		std::cout << "-------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	};
};
#endif
