# Machine Learning: K-Means Algorithm
What is the k-means algorithm?:<br/>
https://towardsdatascience.com/understanding-k-means-clustering-in-machine-learning-6a6e67336aa1

## How to Compile and Run
Assuming you have installed the [MinGW Compiler](http://www.mingw.org/) or are using a terminal that comes with it, such as [Cygwin](https://www.cygwin.com/), the project can be compiled by running `g++ main.cpp -o main.exe` and run by running `./main.exe`.

The resulting output should look like: <br/>
```
The Data set contains 8 samples:
(2, 10) (2, 5) (8, 4) (5, 8) (7, 5) (6, 4) (1, 2) (4, 9)

Round 1. The initial centoids are:
(2, 10) (1, 2) (4, 9)
3 iterations of reclustering have been run for this round.

The final clustering result is:
Cluster 1 : (A1, A8, )
Cluster 2 : (A2, A3, A5, A6, A7, )
Cluster 3 : (A4, )
--------------------------------

Round 2. The initial centoids are:
(2, 5) (6, 4) (4, 9)
2 iterations of reclustering have been run for this round.

The final clustering result is:
Cluster 1 : (A2, A7, )
Cluster 2 : (A3, A5, A6, )
Cluster 3 : (A1, A4, A8, )
--------------------------------

Round 3. The initial centoids are:
(8, 4) (7, 5) (6, 4)
3 iterations of reclustering have been run for this round.

The final clustering result is:
Cluster 1 : (A3, A5, A6, )
Cluster 2 : (A1, A4, A8, )
Cluster 3 : (A2, A7, )
--------------------------------

Round 4. The initial centoids are:
(2, 5) (8, 4) (1, 2)
3 iterations of reclustering have been run for this round.

The final clustering result is:
Cluster 1 : (A1, A4, A8, )
Cluster 2 : (A3, A5, A6, )
Cluster 3 : (A2, A7, )
--------------------------------

Round 5. The initial centoids are:
(6.90001, 5.05418) (5.91491, 5.54785) (3.78429, 2.57732)
3 iterations of reclustering have been run for this round.

The final clustering result is:
Cluster 1 : (A3, A5, A6, )
Cluster 2 : (A1, A4, A8, )
Cluster 3 : (A2, A7, )
--------------------------------
```
