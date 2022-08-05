/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

   vector<int> nodes;

	// Perform a recursive in-order traversal and ensure order is strictly increasing
	void inOrderTraversal(Node* node) {
		if(node == NULL) {
			return;
		}
		inOrderTraversal(node->left);
		nodes.push_back(node->data);
		inOrderTraversal(node->right);
	}

	bool checkBST(Node* root) {
        inOrderTraversal(root);
		for(int i = 1; i < nodes.size(); i++) {
			if(nodes[i] <= nodes[i-1]) {
				return false;
			}
		}
		return true;
	}
