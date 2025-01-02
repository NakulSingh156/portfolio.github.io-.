//Binary Trees

#include <iostream>
using namespace std;

// Structure for TreeNode
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize node with data
    TreeNode(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert node in a binary tree (simple insert logic for demonstration)
TreeNode* insert(TreeNode* root, int value) {
    // If the tree is empty, create a new node
    if (root == nullptr) {
        return new TreeNode(value);
    }

    // Otherwise, insert the node into the left or right subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// In-order traversal (left, root, right)
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Pre-order traversal (root, left, right)
void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Post-order traversal (left, right, root)
void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Main function to test the binary tree operations
int main() {
    TreeNode* root = nullptr;

    // Inserting nodes into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "In-order traversal: ";
    inorder(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preorder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}

//Binary Search Trees

#include <iostream>
using namespace std;

// Structure for TreeNode in Binary Search Tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize node with data
    TreeNode(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a new node into the BST
TreeNode* insert(TreeNode* root, int value) {
    // If the tree is empty, create a new node
    if (root == nullptr) {
        return new TreeNode(value);
    }

    // If the value is less than the current node's data, insert in the left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // If the value is greater than the current node's data, insert in the right subtree
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Return the unchanged root pointer
    return root;
}

// In-order traversal (left, root, right)
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Pre-order traversal (root, left, right)
void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Post-order traversal (left, right, root)
void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Function to display the tree in a structured format
void display(TreeNode* root, int space = 0, int COUNT = 5) {
    if (root == nullptr) return;

    // Increase distance between levels
    space += COUNT;

    // Display right child first (indentation is applied to make the tree look better)
    display(root->right, space);

    // Print current node after space
    cout << endl;
    for (int i = COUNT; i < space; i++) {
        cout << " ";
    }
    cout << root->data << "\n";

    // Display left child
    display(root->left, space);
}

// Main function to test the BST operations
int main() {
    TreeNode* root = nullptr;

    // Inserting nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Display the tree
    cout << "Tree Structure (Display):\n";
    display(root);
    cout << endl;

    // Perform and display different tree traversals
    cout << "In-order traversal: ";
    inorder(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preorder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}

//Graphs, BFS and DFS

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Class to represent a Graph
class Graph {
private:
    int vertices;                      // Number of vertices in the graph
    vector<vector<int>> adjList;       // Adjacency list to store the graph

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    // Function to add an edge to the graph (undirected graph)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // For undirected graph, add edge in both directions
    }

    // DFS (Depth-First Search) using recursion
    void DFS(int start) {
        vector<bool> visited(vertices, false);  // To keep track of visited vertices
        cout << "DFS Traversal starting from vertex " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // Helper function for DFS (recursive)
    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";  // Visit the node

        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // BFS (Breadth-First Search)
    void BFS(int start) {
        vector<bool> visited(vertices, false);  // To keep track of visited vertices
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal starting from vertex " << start << ": ";

        while (!q.empty()) {
            int node = q.front();
            cout << node << " ";  // Visit the node
            q.pop();

            // Enqueue all the adjacent vertices of the current node
            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

// Main function to test the Graph DFS and BFS
int main() {
    // Create a graph with 6 vertices (0 to 5)
    Graph g(6);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    // Perform DFS starting from vertex 0
    g.DFS(0);

    // Perform BFS starting from vertex 0
    g.BFS(0);

    return 0;
}

//Heaps

#include <iostream>
#include<vector>
using namespace std;
vector<int> max_heap(vector<int> H, int n);


vector<int> max_heap(vector<int> H)
{
    int i,k,v,j,n;
    n=H.size()-1;
    bool heap;
    for(int i=n/2; i>=1; i--)
    {
        k=i;
        v=H[k];
        heap=false;
        while(!heap && 2*k<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(H[j]<H[j+1])
                    j=j+1;
            }
            if(v>=H[j])
                heap=true;
            else
            {
                H[k]=H[j];
                k=j;
            }
        }
        H[k]=v;
    }
    return H;
}

int main()
{
    int n,x;
    vector<int> H;
    cout<<"Enter total number of element\n";
    cin>>n;

    H.resize(n+1);

    cout<<"Enter elements\n";
    for(int i=1;i<=n;i++)
    {
        cin>>H[i];
        /*cin>>x;
        H.push_back(x);*/
    }

    H=max_heap(H);

    cout<<"Heapified array\n";
    for(int i=1;i<=n;i++)
    {
        cout<<H[i]<<"\t";
    }

    while(1)
    {
        int ch,x,p,t=0,m;
        p=H.size();
        cout<<"\nMenu\n";
        cout<<"0-Exit\n";
        cout<<"1-Insert\n";
        cout<<"2-Delete\n";
        cout<<"3-Print\n";
        cout<<"4-Print root\n";
        cout<<"5-kth largest\n";
        cout<<"Enter your choice\n";
        cin>>ch;
        switch(ch)
        {
            case 0:exit(0);break;
            case 1: cout<<"Enter new element\n";
                    cin>>x;
                    H.push_back(x);
                    H=max_heap(H);
                    break;
            case 2: cout<<"Deleted root node "<<H[1]<<"\n";
                    t=H[1];
                    H[1]=H[p-1];
                    H[p-1]=t;
                    H.pop_back();
                    H=max_heap(H);
                break;

            case 3: cout<<"Elements of heap are\n";
                    for(int i=1;i<p;i++)
                    {
                        cout<<H[i]<<"\t";
                    }
                    break;
            case 4: cout<<"Root of heap is "<<H[1]<<"\n";
                    break;
            case 5: cout<<"Enter value of k= ";
                    int k;
                    cin>>k;
                    if (k>0 && k<= p-1)
                        {
                            vector<int> tH=H;
                            for (int i=0; i<k; i++)
                            {
                                m=tH[1];
                                tH[1]=tH[p-1];
                                tH.pop_back();
                                tH=max_heap(tH);
                            }
                            cout <<k<< "th largest element is: "<< m << endl;
                        }
                    else
                            cout << "Invalid value of k.\n";
                    break;
        }
    }
}

//Sorting - Merge Sort, Quick Sort, Insertion Sort

#include <iostream>
#include <vector>
using namespace std;

// Merge Sort: Divide and Conquer algorithm
void merge(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    // Recursively divide the array into two halves
    merge(arr, left, mid);
    merge(arr, mid + 1, right);

    // Merge the two sorted halves
    vector<int> temp;
    int i = left, j = mid + 1;

    // Merge the two halves while comparing their elements
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Add remaining elements from the left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Add remaining elements from the right half
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy the merged elements back into the original array
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    merge(arr, left, right);
}

// Quick Sort: Divide and Conquer algorithm
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    // Place all elements smaller than pivot to the left and greater to the right
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]); // Place pivot in correct position
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1);  // Sort left part
        quickSort(arr, pi + 1, high); // Sort right part
    }
}

// Insertion Sort: Simple sorting algorithm
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Place the key in its correct position
    }
}

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test the sorting algorithms
int main() {
    // Sample array for testing
    vector<int> arr1 = {12, 11, 13, 5, 6, 7};
    vector<int> arr2 = {12, 11, 13, 5, 6, 7};
    vector<int> arr3 = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    printArray(arr1);

    // Merge Sort
    cout << "Array after Merge Sort: ";
    mergeSort(arr1, 0, arr1.size() - 1);
    printArray(arr1);

    // Quick Sort
    cout << "Array after Quick Sort: ";
    quickSort(arr2, 0, arr2.size() - 1);
    printArray(arr2);

    // Insertion Sort
    cout << "Array after Insertion Sort: ";
    insertionSort(arr3);
    printArray(arr3);

    return 0;
}

//Dijkstra's Algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <climits>  // For INT_MAX
using namespace std;

// Define a pair to store the vertex and its distance in the priority queue
typedef pair<int, int> pii; // first: vertex, second: distance

class Graph {
private:
    int vertices;  // Number of vertices in the graph
    vector<vector<pii>> adjList;  // Adjacency list to store graph

public:
    // Constructor to initialize the graph with the number of vertices
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});  // For undirected graph
    }

    // Function to perform Dijkstra's Algorithm to find the shortest path
    void dijkstra(int start) {
        // Distance vector to hold the shortest distance from start node to each node
        vector<int> dist(vertices, INT_MAX);
        dist[start] = 0;

        // Min-heap (priority queue) to select the node with the smallest distance
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, start}); // Push the source node with distance 0

        while (!pq.empty()) {
            // Extract the node with the minimum distance
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            // If the current distance is greater than the stored distance, skip it
            if (d > dist[u]) continue;

            // Explore all neighbors of the current node
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;  // Neighbor node
                int weight = neighbor.second;  // Edge weight

                // If a shorter path to v is found, update the distance and push it to the queue
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print the shortest distances from the start node to all other nodes
        cout << "Shortest distances from node " << start << ":\n";
        for (int i = 0; i < vertices; i++) {
            if (dist[i] == INT_MAX) {
                cout << "Node " << i << ": INF\n";
            } else {
                cout << "Node " << i << ": " << dist[i] << endl;
            }
        }
    }
};

// Main function to test Dijkstra's algorithm
int main() {
    Graph g(9);  // Create a graph with 9 vertices (0 to 8)

    // Add edges to the graph (u, v, weight)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    // Perform Dijkstra's Algorithm from the source node 0
    g.dijkstra(0);

    return 0;
}

//Floyd-Warshall Algorithm

#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX (infinity)
using namespace std;

class Graph {
private:
    int vertices;  // Number of vertices in the graph
    vector<vector<int>> dist;  // Matrix to store the shortest distances

public:
    // Constructor to initialize the graph with number of vertices
    Graph(int v) {
        vertices = v;
        dist.resize(v, vector<int>(v, INT_MAX));  // Initialize all distances as infinity
    }

    // Function to add an edge with a given weight
    void addEdge(int u, int v, int weight) {
        dist[u][v] = weight;
    }

    // Floyd-Warshall Algorithm to compute shortest paths between all pairs of vertices
    void floydWarshall() {
        // Distance matrix initialization: distance from a vertex to itself is 0
        for (int i = 0; i < vertices; i++) {
            dist[i][i] = 0;
        }

        // Run the Floyd-Warshall algorithm
        for (int k = 0; k < vertices; k++) {
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    // Update the distance matrix to reflect the shortest path through vertex k
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Function to print the shortest distance matrix
    void printDistanceMatrix() {
        cout << "Shortest distances between every pair of vertices:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][j] == INT_MAX) {
                    cout << "INF" << "\t";
                } else {
                    cout << dist[i][j] << "\t";
                }
            }
            cout << endl;
        }
    }
};

// Main function to test the Floyd-Warshall algorithm
int main() {
    // Create a graph with 4 vertices (0 to 3)
    Graph g(4);

    // Add edges to the graph with weights (u, v, weight)
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 7);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 1);

    // Apply Floyd-Warshall algorithm to find shortest paths
    g.floydWarshall();

    // Print the shortest distance matrix
    g.printDistanceMatrix();

    return 0;
}
