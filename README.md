# Rubik's Cube Solver C++
C++ program that takes the initial and final configurations of the cube and will find a sequence of moves that will transform the initial state into the final state. The solutions is found by using one uninformed search strategy i.e. iterative-deepening and one informed search strategy named A*

# About the Project
In this part of the assignment write a C++ program that will take the initial and
final configurations of the cube and will find a sequence of moves that will transform the initial
state into the final state. The solutions will be found by using one uninformed search strategy i.e.
iterative-deepening and one informed search strategy named A*

For this assignment it is assumed that turning a face of the Rubik’s cube by 90o either in
clockwise or counter clockwise direction is considered one move each
Program takes as input a file containing the initial and final configuration pair and will
output the set of moves needed to solve the puzzle

# Input File Format
The first line of the file will contains the initial configuration (a space separated list of 54 digit
code of the colors) the second line contains the final configuration.
A complete configuration of a puzzle consists of 54 space separated digits which give the color
information on each of the six sides of the cube. A color on each of the nine cubes on a given side
is a digit from the set {1, 2, 3, 4, 5, 6}. The first 9 digits of these 54 digits specifying the colors of
the 9 cubes faces on the front side (left-right and top-bottom), the next 9 numbers specifying the
color information on the back side and then comes the color information of top, bottom, left and
right sides.

# Results/ Report
Introduction
We are writing a C++ program that will takes the initial and
final configurations of the cube and will find a sequence of moves that will transform the initial
state into the final state. The solutions will be found by using one uninformed search strategy i.e.
iterative-deepening and one informed search strategy named A*.

### Methodology
### Iterative Deepening Algorithm
In this algorithm, we used a stack to maintain the nodes and we simply pop the node (at the top) and compares with goal state then if it is not goal then check depth has it reached the limit if yes then stop and remove it from stack else make its 12 childs and push in the stack and repeat until the goal is found.

### A* Algorithm:
In this technique, we for choosing a child we used a heuristic function which gave us a score by comparing two states and telling how much nodes of it are matching. So instead of blindly picking a child node we picked with the highest score and add the cost from start to that node and cost from that node to goal (guess given by our heuristic function) and maintain two lists (Open and Closed). At each step we compare this cost if a node with the same position as successor is in the OPEN list which has a lower cost than successor, skip this successor if a node with the same position as successor is in the CLOSED list which has a lower cost than successor, skip this successor otherwise, add the node to the open list and repeat this until the goal is found.

### Results
In Iterative Deepening, if the cube is 5-10 moves away it usually finds the solution in seconds but if current state is messed up then it takes a lot time and consumes more memory 12depth, usually program stops due to filling of all the memory and takes hours, may be days in solving and program closes due to short memory. But in contrast, A* guess it in less moves with more efficiency in much less time and finds the solution. However, the heuristic should be good enough to guess correct moves. 
Our heuristic was number of mismatches at a given state from the goal state.

### Conclusions
As we can see the results, it clearly shows that A* algorithm is far better than Iterative Deepening.
A* algorithm gives solution in much less time and more optimal solution. In contrast, Iterative deepening takes much more memory, time and is far less efficient than A*. It makes 12Depth nodes which requires much memory and processing time. But A* solves the problem in much less time and taking less memory by making wise decisions. But A* mainly depends on the heuristic function, the more the guess of heuristic is correct, the less and more optimal solution it will give. However, a bad heuristic can guide us to a wrong path and may take more time. 
In short, A* is much better technique than Iterative Deepening in solving the required problem.
