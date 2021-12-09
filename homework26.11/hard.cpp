#include <iostream>
#include <vector>

using namespace std;

class Graph_Edge {
public:
	int source;
	int destination;
	int weight;

	Graph_Edge(int source, int destination, int weight) {
		this->source = source;
		this->destination = destination;
		this->weight = weight;
	}
};

class Graph {
private:
	int size;
	vector<vector<Graph_Edge*>> adjacencyVector;
    vector<Graph_Edge*> edgesVector;

public:
	Graph(int size) {
		this->size = size;

		for(int i = 0; i < size; ++i) {
			adjacencyVector.push_back(vector<Graph_Edge*> ());
		}
	}

	void pushGraphEdge(Graph_Edge* edge) {
		if (edge->source < 0 || edge->source >= this->size || edge->destination < 0 || edge->destination >= this->size) {
			return;
		}

		this->adjacencyVector.at(edge->source).push_back(edge);
		this->adjacencyVector.at(edge->destination).push_back(new Graph_Edge(edge->destination, edge->source, edge->weight));
        this->edgesVector.push_back(edge);
	}

	void print()
    {
		cout << "\n-----------------------------\n";
        cout << "Graph:\n";
        for (int i = 0; i < this->size; ++i) {
            cout << i << ":";
            for(Graph_Edge* edge : adjacencyVector.at(i)) {
				cout << " " << edge->destination;
			}

			cout << "\n";
        }
		cout << "-----------------------------\n";
    }

	int findSet(vector<int> parent, int index)
    {
        if (parent.at(index) == index)
        {
            return index;
        }
        return findSet(parent, parent.at(index));
    }

    void findUnion(vector<int>& parentVector, vector<int>& rankVector, int firstValue, int secondValue)
    {
        int firstRoot = this->findSet(parentVector, firstValue);
        int secondRoot = this->findSet(parentVector, secondValue);

        if (rankVector.at(firstRoot) < rankVector.at(secondRoot)) {
            parentVector.at(firstRoot) = secondRoot;
        } else if (rankVector.at(firstRoot) > rankVector.at(secondRoot)){
            parentVector.at(secondRoot) = firstRoot;
        } else {
            parentVector.at(secondRoot) = firstRoot;
            parentVector[secondRoot] = firstRoot;
            rankVector.at(firstRoot)++;
        }
    }

    Graph* boruvkaMST()
    {
        Graph* newGraph = new Graph(this->size);
        vector<int> parentVector;
        vector<int> rankVector;

        vector<Graph_Edge*> cheapestVector(this->size);

        int counter = this->size;
        int MSTweight = 0;

        for (int i = 0; i < this->size; ++i) {
            parentVector.push_back(i);
            rankVector.push_back(0);
        }

        while (counter > 1) {
            for (int i = 0; i < this->edgesVector.size(); ++i) {
                Graph_Edge* current_edge = edgesVector.at(i);

                int firstSet = this->findSet(parentVector, current_edge->source);
                int secondSet = this->findSet(parentVector, current_edge->destination);

                if (firstSet != secondSet) {
                    if (cheapestVector.at(firstSet) == nullptr || cheapestVector.at(firstSet)->weight > current_edge->weight) {
                            cheapestVector.at(firstSet) = current_edge;
                    }

                    if (cheapestVector.at(secondSet) == nullptr || cheapestVector.at(secondSet)->weight > current_edge->weight) {
                            cheapestVector.at(secondSet) = current_edge;
                    }
                }
            }

            for (int node = 0; node < this->size; node++)
            {
                if (cheapestVector.at(node) != nullptr) {
                    Graph_Edge* current_edge = cheapestVector[node];
                    int firstSet = this->findSet(parentVector, current_edge->source);
                    int secondSet = this->findSet(parentVector, current_edge->destination);

                    if (firstSet != secondSet) {
                        MSTweight += current_edge->weight;
                        this->findUnion(parentVector, rankVector, firstSet, secondSet);
                        newGraph->pushGraphEdge(current_edge);
                        counter--;
                    }
                }
            }
            
            fill(cheapestVector.begin(), cheapestVector.end(), nullptr);
        }

        return newGraph;
    }
};

int main() {
	Graph *g = new Graph(2);
    g->pushGraphEdge(new Graph_Edge(0, 1, 7));
    g->pushGraphEdge(new Graph_Edge(1, 2, 6));
    
    Graph* graph = g->boruvkaMST();
    graph->print();
	return 0;
}
