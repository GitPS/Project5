#### CS 441 Project 5 ####

__Authors__

Phillip Sime and Ryan Gittins

2013-12-02

__Summary__

This software simulates five different page replacement algorithms and displays the number of pagefaults produced by each for a given number of frames.  The number of frames can be specified by the user and must range from one to seven, inclusive.  If the number of frames is not speficied, then all algorithms are against the full range of frame sizes.  The user is required to specify the name a textfile containing the reference string in a specific format.

The following page replacement algorithms are simulated by this program:

* Optimal
* First-Come, First Served (FCFS)
* Least Recently Used (LRU)
* Least Recently Used, Second Chance (LRU SC)
* Least Recently Used, Enhanced Second Chance (LRU ESC)

__Build__

To build this software, simply navigate to the directory containing the Makefile and all other included files on a unix-based machine or virtual machine. Type the command `make` into the terminal to trigger the build. This will cause the gcc build commands listed in the Makefile to execute, compiling the source code into an executable file.

__Usage__

To use this software…

__Test Cases__

__Examples__

__Known Bugs and Problem Areas__
* No bugs or problem areas are known at this time.
