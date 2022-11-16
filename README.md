<br><br> I decided to write the program mostly static because it was easier for me, especially
that I did not notice constraints to allocate the data exclusively dynamically.
<br><br>

Until the actual solving of the tasks, I prepared the data to be processed,
like this: I read in turn the number of nodes, the number of edges and then the number of deposits,
then I read the m rows with the start node (u), the arrival node (v) and the cost (w).
For each read date, we built the adjacency and cost matrices (g
being the adjacency matrix of the graph, gr being a copy of it and a being the matrix of
costs, not before being initialized on all positions with 0): for g and gr: on
line u and column v I put 1 and in a on line u and on column v I put w. After that, I have
I read each deposit and put them in a vector of deposits, then the number of requirements and
for each request, I read the request and checked what type of request it is.
<br><br>

At e1: I used a modified version of the Dijsktra algorithm, but twice: once
for the outgoing route, so to speak, and another for the return route.
following this dijkstra function, I put the visited nodes in a vector, but in order
reverse. I had to invert that vector to process and display it. then I
made a vector of costs/distances for each node from the source (src) in which I have
collected the respective cost on the specific position of the node and found the minimum.
The program first displays the node for which the dijtra made a round trip, then the costs
from the shower and from the return, then again use a kind of dijsktra to display the knots
through which he went to calculate those costs shown previously, but this after they
put in a vector. At the end I displayed the vector.
<br><br>

At e2: I didn't do it with kosarakju or tarjan like the majority did, but I tried one
own version. I took each deposit from the vector of deposits and tried to
I remove from the graph everything related to that node, then I used the traversal function
(I'll explain what it does right away) for each deposit, then I deleted the duplicates from the vector
cc in which the traversed nodes from the "traversal" were placed. Then from the vector cc in
depending on how I found a node that represented a warehouse, I put the elements from the vector on
lines, in a matrix. then I sorted each line in ascending order. if there were duplicates,
I removed them, and at the end I displayed the lines from the matrix, only after displaying them
the number of lines, which is, in fact, the number of connected components in the graph. The function
"traversal" puts one node (repository) on the stack, marks it as visited, and for how long
finds an arc (an edge) ("arch" graph function, number of nodes and respective node) of that node, searches recursively. when it has not found any more edges, it exits the recursion, removes
the node on the stack and adds it to the vector of nodes in the related component. and at the end
do this again.
<br><br>

At e3: even if it doesn't show on the checker, I tried my own solution: I read, in addition, r
what is the number of routes (that is, related components to be repaired), and for each one I have read
one k each, what is the number of nodes in the component, and the actual nodes that I have
placed in a vector x. I then made a matrix of size 2 X k in which on the first line
I put the stored values in the x vector and on the second line I initialized it with zero for
to use it as a visitor vector. I then took each deposit, I have it
marked as a start (point of departure) and then I searched for the point of arrival
(yes, it really has to go back to the same depot, but the stop is, in fact,
the node in the data component that has access to that repository. I added the cost to the amount
at the start node at the stop node. then for each node in the vector x we searched which
it is the first node in the unvisited vector and I added the cost to an amount. after all from the vector
were visited (line two of the matrix created at this point is filled with 1) then
looks for a node that is part of the x vector and that is related to the stop node. on
along the route it searches for and finds nodes in x that come close to the stop, add to the sum
the cost. the final amount is displayed, per deposit. so: more clearly: take the start line and the column
x[i] (0<=i<k) and check if there is an element different from zero. if yes, mark as
visited elementuk x[i], stops searching, the start becomes x[i], and adds to the sum
the cost, until all x[i]s have been visited. if they were visited but they were not
reached the stop node, in the same way, a column x[i] that represents the node is searched for on the start line
stop, as well, adding up along the way, the cost.
