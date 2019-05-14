# Dante's Star
The goal of this project is to generate mazes (in a reasonable amount of time), solve them (in a reasonable amount of time), and print the solution

*This is a school project and it may only work under a Unix environment*

### How to test it
First of all, what are *mazes*? Here is the maze format description:
- Mazes are rectangular, they are coded in ASCII.
- The 'X's represent the walls and the '*'s represent the free spaces.
- It is possible to move to the four surrounding squares from a free space to a free space (up, down, right, left) but not diagonally.
- "Start" is in the upper left-hand corner (0, 0)
- "Finish" is in the bottom right-hand corner.
- To mark down the solution path of a maze, we use 'o's.

Executing the solver or the generator will print the maze (solved or generated on the standard output of a command prompt).

***You need to compile the source files using `make` before trying to execute the binaries.***

###### Solver
`./solver/solver mazefile.txt`

###### Generator
`./generator/generator x_size y_size [perfect]`

If the `perfect` flag is present, a perfect maze will be generated.

A perfect maze is a maze that has no loops and no clusters. Therefore, it has a single solution, unlike imperfect. 
