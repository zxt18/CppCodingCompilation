
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};







class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }

        unordered_map<Node*, Node*>map; //Hash Table
        queue<Node*>q;
        q.push(node);

        Node* n_node = new Node (node->val, {});
        map[node]=n_node;  //linking the node to the new node to keep track that we have visited it ;



        while (!q.empty()){
            Node* current_node = q.front();
            q.pop();
            Node * mapped_node = map[current_node];
            for (auto neigh : current_node->neighbors){

                if(map[neigh]){
                    mapped_node->neighbors.push_back(map[neigh]);
                }
                else {
                    Node* n_node = new Node (neigh->val, {});
                    q.push(neigh);
                    map[neigh]=n_node;
                    mapped_node->neighbors.push_back(n_node);
                }
            }
        }
        return map[node];

    }
};
