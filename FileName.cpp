#include <iostream>
using namespace std;

class GraphNode
{
public:
    int id;
    GraphNode* next;

    GraphNode(int _id) : id(_id), next(nullptr) {}

    void addNeighbor(GraphNode* neighbor)
    {
        if (next == nullptr)
        {
            next = neighbor;
        }
        else
        {
            GraphNode* temp = next;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = neighbor;
        }

        neighbor->next = new GraphNode(id);
    }

    int getID() const
    {
        return id;
    }

    GraphNode* getNeighbors() const
    {
        return next;
    }
};

class Graph
{
private:
    GraphNode* nodes;

public:
    Graph() : nodes(nullptr) {}

    void addNode(int id)
    {
        if (findNode(id) == nullptr)
        {
            GraphNode* newNode = new GraphNode(id);
            newNode->next = nodes;
            nodes = newNode;
        }
        else
        {
            cout << "Node with ID " << id << " already exists!" << endl;
        }
    }

    void addEdge(int from, int to)
    {
        GraphNode* fromNode = findNode(from);
        GraphNode* toNode = findNode(to);

        if (fromNode != nullptr && toNode != nullptr && from != to)
        {
            fromNode->addNeighbor(toNode);
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }

    GraphNode* findNode(int id)
    {
        GraphNode* temp = nodes;
        while (temp != nullptr)
        {
            if (temp->getID() == id)
            {
                return temp;
            }
            temp = temp->getNeighbors();
        }
        return nullptr;
    }

    void printGraph()
    {
        GraphNode* temp = nodes;
        while (temp != nullptr)
        {
            cout << "Node " << temp->getID() << " -> ";

            GraphNode* neighbors = temp->getNeighbors();
            while (neighbors != nullptr)
            {
                cout << neighbors->getID() << " ";
                neighbors = neighbors->getNeighbors();
            }

            cout << endl;
            temp = temp->getNeighbors();
        }
    }
};

int main()
{
    Graph myGraph;

    myGraph.addNode(1);
    myGraph.addNode(2);
    myGraph.addNode(3);
    myGraph.addNode(4);

    myGraph.addEdge(1, 2);
    myGraph.addEdge(1, 3);
    myGraph.addEdge(2, 3);

    myGraph.printGraph();

    return 0;
}