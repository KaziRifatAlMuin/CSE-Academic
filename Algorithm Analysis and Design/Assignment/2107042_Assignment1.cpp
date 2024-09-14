#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
const long long inf = 1e18 + 7;

ll distances[N]; // Array to store the shortest distances from the source to each vertex

// MinHeap class definition to manage the priority queue for Dijkstra's algorithm
class MinHeap {
private:
    vector<pair<ll, ll>> heap; // (key, value) pairs representing (vertex, distance)
    unordered_map<ll, ll> key_index; // maps key (vertex) to its index in the heap

    // Functions to get parent and child indices
    ll parent(ll idx) { return (idx - 1) / 2; }
    ll left_child(ll idx) { return 2 * idx + 1; }
    ll right_child(ll idx) { return 2 * idx + 2; }

    // Function to maintain the heap property by moving the element at idx up
    void heapify_up(ll idx) {
        if(idx && heap[parent(idx)].second > heap[idx].second){
            swap(heap[idx], heap[parent(idx)]);
            key_index[heap[idx].first] = idx;
            key_index[heap[parent(idx)].first] = parent(idx);
            heapify_up(parent(idx));
        }
    }

    // Function to maintain the heap property by moving the element at idx down
    void heapify_down(ll idx) {
        ll smallest = idx;
        ll left = left_child(idx);
        ll right = right_child(idx);

        if(left < heap.size() && heap[left].second < heap[smallest].second){
            smallest = left;
        }
        if(right < heap.size() && heap[right].second < heap[smallest].second){
            smallest = right;
        }

        if(smallest != idx){
            swap(heap[idx], heap[smallest]);
            key_index[heap[idx].first] = idx;
            key_index[heap[smallest].first] = smallest;
            heapify_down(smallest);
        }
    }

public:
    bool is_empty() const { return heap.empty(); }

    // Function to insert a (key, value) pair into the heap
    void insert(ll key, ll value){
        heap.push_back({key, value});
        ll index = heap.size() - 1;
        key_index[key] = index;
        heapify_up(index);
    }

    // Function to extract the minimum element from the heap
    pair<ll, ll> extract_min() {
        if(is_empty()){
            throw runtime_error("Heap is empty");
        }

        pair<ll, ll> root = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        if(!is_empty()){
            key_index[heap[0].first] = 0;
            heapify_down(0);
        }
        key_index.erase(root.first);
        return root;
    }

    // Function to decrease the value of a given key
    void decrease_key(ll key, ll new_value){
        ll idx = key_index[key];
        heap[idx].second = new_value;
        heapify_up(idx);
    }

    // Function to check if a key exists in the heap
    bool contains(ll key) const{
        return key_index.find(key) != key_index.end();
    }
};

// Dijkstra's algorithm using the MinHeap
void dijkstra(ll vertices, const vector<vector<pair<ll, ll>>>& adj_list, ll source) {
    vector<bool> visited(vertices + 1, false); // To track visited vertices
    for (int i = 0; i <= vertices; i++) distances[i] = inf; // Initialize distances to infinity

    MinHeap min_heap;
    min_heap.insert(source, 0); // Insert source with distance 0
    distances[source] = 0; // Distance to source is 0

    while (!min_heap.is_empty()) {
        auto [u, dist_u] = min_heap.extract_min(); // Get the vertex with the smallest distance

        if(visited[u]) continue;
        visited[u] = true; // Mark the vertex as visited

        for(const auto& [v, weight] : adj_list[u]){ // Iterate over adjacent vertices
            if(!visited[v] && dist_u + weight < distances[v]){
                distances[v] = dist_u + weight; // Update the distance if a shorter path is found
                if(min_heap.contains(v)){
                    min_heap.decrease_key(v, distances[v]); // Update the heap if the vertex is already present
                } 
                else{
                    min_heap.insert(v, distances[v]); // Insert the vertex with the updated distance
                }
            }
        }
    }
}

int main() {
    ll vertices, edges;
    cin >> vertices >> edges; // Input the number of vertices and edges

    vector<vector<pair<ll, ll>>> adj_list(vertices + 1); // Adjacency list to store the graph

    // Input the edges and their weights
    for (ll i = 0; i < edges; i++){
        ll u, v, weight;
        cin >> u >> v >> weight;
        adj_list[u].push_back({v, weight});
        adj_list[v].push_back({u, weight});
    }

    dijkstra(vertices, adj_list, 0); // Run Dijkstra's algorithm from the source vertex 0
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": Distance " << distances[i] << "\n"; // Output the shortest distances
    }

    return 0;
}
