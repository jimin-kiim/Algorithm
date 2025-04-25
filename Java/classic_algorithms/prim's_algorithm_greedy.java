// A Java program for Prim's Minimum Spanning Tree (MST)
// algorithm. The program is for adjacency matrix
// representation of the graph

// https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

import java.lang.*;

// MST is for Minimum Spanning Tree; all the sum of the weights of the edges are to be minimum
class MST {

    // A utility function to find the vertex with minimum key value, from the set of vertices not yet included in MST
    int minVertexIndex(int vertex_key[], Boolean isAdded[])
    {
        // Initialize min value
        int min = Integer.MAX_VALUE, min_index = -1;

        for (int v = 0; v < isAdded.length; v++)
            if (isAdded[v] == false && vertex_key[v] < min) { // cover the nodes not yet added and 
            // the key value for the node should be smaller than the min value. 
                min = vertex_key[v]; // if the key value for the vertex handled at this point is smaller than the crtiera,
                // then update the min value as its value. 
                min_index = v; // and store the index value for the vertex whose key value is the smallest one until the point, too. 
            }

        return min_index; // return the final value; the index of the vertex whose key is the smallest one. 
    }

    // A utility function to print the constructed MST
    // stored in parent[]
    void printMST(int parent[], int graph[][])
    {
        System.out.println("Edge \tWeight");
        for (int i = 1; i < graph.length; i++)
            System.out.println(parent[i] + " - " + i + "\t"
                               + graph[parent[i]][i]);
    }

    // Function to construct and print MST for a graph
    // represented using adjacency matrix representation
    void primMST(int graph[][])
    {
        int n = graph.length; // |V| = n
        
        // Array to store constructed MST
        int parent[] = new int[n];

        // Key values used to pick minimum weight edge in
        // cut
        int vertex_key[] = new int[n];

        // To represent set of vertices included in MST
        Boolean isAdded[] = new Boolean[n];

        // Initialize all keys as INFINITE
        for (int i = 0; i < n; i++) {
            vertex_key[i] = Integer.MAX_VALUE;
            isAdded[i] = false; // not yet included to the result set 
        }

        // Always include 1st vertex in MST. - single source spanning tree SSST
        // Make vertex_index 0 so that this vertex is picked as a first one
        vertex_key[0] = 0;
      
        // First node is always root of the MST
        parent[0] = -1;

        // The MST will have |V| = n vertices
        for (int count = 0; count < n - 1; count++) {
            
            // Pick the minimum key vertex from the set of vertices not yet included in MST
            int u = minVertexIndex(vertex_key, isAdded);  // select the node from the pending Nodes. 

            // Add the picked vertex to the MST Set
            isAdded[u] = true; // mark as visited

            // Update the key value and parent index of 
            // the adjacent vertices of the picked vertex; u - graph[u][v]: non zero
            // Consider only unvisited nodes - isAdded[v]: false
            for (int v = 0; v < n; v++)
                // vertices not yet included in MST Update
                // the key only if graph[u][v] is smaller than key[v]
                if (graph[u][v] != 0 && isAdded[v] == false
                    && graph[u][v] < vertex_key[v]) {
                    parent[v] = u;
                    vertex_key[v] = graph[u][v];
                }
        }

        // Print the constructed MST
        printMST(parent, graph);
    }

    public static void main(String[] args)
    {
        MST tree = new MST(); // containing methods that would be used to implement the Prim's algorithm-greedy approach
        int graph[][] = new int[][] { { 0, 2, 0, 6, 0 },
                                      { 2, 0, 3, 8, 5 },
                                      { 0, 3, 0, 0, 7 },
                                      { 6, 8, 0, 0, 9 },
                                      { 0, 5, 7, 9, 0 } };
        // the graph input would be dealed with the datastructure, array. it can be fibonacci heap or binary heap
        // but the array is the classic one. 
        // 2 dimensional array; as a adjacency matrix 


        // Print the solution
        tree.primMST(graph);
    }
}

// Time Complextiy: O(V^2)
   // |V| = n -> O(n^2)
// if I use the data structure to handle the input graph with binary heap, instead of an array, 
 // the time complexity can be improved with the value of O((E +V)*logV)
  // |V| = n,  |E\ = m -> O((m + n)*logn) -> O(mlogn + nlogn)