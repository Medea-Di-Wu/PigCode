/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)  return NULL;
        UndirectedGraphNode* newNode;
        if(m.find(node) != m.end()) {
            return m[node];
        }
        else {
            newNode = new UndirectedGraphNode(node->label);
            m[node] = newNode;
        }
        for(int i = 0; i < node->neighbors.size(); i++) {
            if(m.find(node->neighbors[i]) != m.end()) {
                newNode->neighbors.push_back(m[node->neighbors[i]]);
            }
            else {
                UndirectedGraphNode* neighbor = cloneGraph(node->neighbors[i]);
                newNode->neighbors.push_back(neighbor);
            }
        }
        return newNode;
    }
private:
    map <UndirectedGraphNode*, UndirectedGraphNode*> m;
};