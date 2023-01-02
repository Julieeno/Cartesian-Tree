#include <iostream>
#include <vector>
using namespace std;

struct Node  {
        int data;
        Node* left; 
        Node* right;
        Node* parent;
        Node()  {
            data = 0;
            parent = NULL;
            left = NULL; 
            right = NULL;
        }
}; 
  
class CartesianTree  {
    private:
        Node *root, *last;

        Node * lowestNode(Node *node, int x)    {
            if(node == NULL)
                return NULL;
            if(node->data < x)
                return node;
            else if(node->parent != NULL)
                return lowestNode(node->parent, x);
            else 
                return NULL;
        }
    public:
        Node * getRoot()    {
            return root;
        }

        void addNode(int x) {
            Node *new_node = new Node;
            new_node->data = x;
            if(root == NULL)    {
                last = new_node;
                root = new_node;
                return;
            }
            Node *aux = new Node;
            aux = lowestNode(last, x);
            if(aux == NULL)   {
                new_node->left = root;
                root->parent = new_node;
                root = new_node;
            }
            else    {
                new_node->parent = aux;
                new_node->left = aux->right;
                if(aux->right!=NULL)
                  aux->right->parent = new_node;
                aux->right = new_node;
            }
            last = new_node;
        }

        CartesianTree(int arr[], int n)    {
            root = NULL;
            last = NULL;
            for(int i=0; i<n; i++)
                addNode(arr[i]);
        }
        
        void printInorder (Node* node) { 
            if (node == NULL) 
                return; 
            printInorder (node->left); 
            cout << node->data<<" ";
            printInorder (node->right); 
        }

        /* The post-order traversal has been implemented
        just to proof the correctness of the tree;
        if the relationships among the nodes are respected,
        it means that the tree is correct*/
        void printPostorder(Node* node)    {
            if (node == NULL) return;
            printPostorder(node->left);
            printPostorder(node->right);
            cout << node->data << " ";
        }

        /*printAdvancedInorder is an upgraded version of the function printInorder, 
        because it prints the in-order traversal of the tree and
        also all the relationships of the nodes*/ 
        void printAdvancedInorder (Node* node) { 
            if (node == NULL) 
                return; 
            printAdvancedInorder (node->left); 
            cout << node->data;
            if(node->parent!=NULL)
                cout<<", son of "<<node->parent->data;
            if(node->left!=NULL || node->right!=NULL)
                cout<<", parent of ";
            if(node->left!=NULL)
                cout<<node->left->data;
            if(node->left!=NULL && node->right!=NULL)
                cout<<" and ";
            if(node->right!=NULL)
                cout<<node->right->data;
            cout<<"."<<endl;
            printAdvancedInorder (node->right); 
        }

        /* ExtractMin is a function that works similarly to HeapSort, because it removes 
        from the tree every node starting from the lowest to arrive to the highest.
        In fact in this program it has been implemented also to give back the sorted 
        array of the tree.*/
        void ExtractMin(int arr[], int n)    {
            int aux[n];
            for(int i=0; i<n; i++)
                aux[i] = arr[i];
            int minArr[n];
            int count = n;
            int m = 0;
            while(n>0)  {
                int min = 10000;
                int k = 0;
                for(int j=0; j<n; j++)  {
                    if(aux[j]<min)  {
                        min = aux[j];
                        k = j;
                    }
                }
                minArr[m] = min;
                m++;
                for(int l=k; l<n-1; l++)
                    aux[l] = aux[l+1];
            
                CartesianTree tree = CartesianTree(arr, n-1);
                cout<<min<<" removed, remining nodes: ";
                tree.printInorder(tree.getRoot());
                cout<<endl;
                n--;
            }
            cout<<"Sorted array: ";
            for(int i=0; i<count; i++)
                    cout<<minArr[i]<<" ";
            cout<<endl;
        }
        /* ExtractMax is a function that works similarly to HeapSort, because it removes 
        from the tree every node starting from the highest to arrive to the lowest.
        In fact in this program it has been implemented also to give back the sorted 
        array of the tree.*/
        void ExtractMax(int arr[], int n)    { 
            int aux[n];
            for(int i=0; i<n; i++)
                aux[i] = arr[i];
            int MaxArr[n];
            int count = n;
            int m = 0;
            while(n>0)  {
                int max = -1000;
                int k = 0;
                for(int j=0; j<n; j++)  {
                    if(aux[j]>max)  {
                        max = aux[j];
                        k = j;    
                    }
                }
                MaxArr[m] = max;
                m++;
                for(int l=k; l<n-1; l++)
                    aux[l] = aux[l+1];
            
                CartesianTree tree = CartesianTree(arr, n-1);
                cout<<max<<" removed, remining nodes: ";
                tree.printInorder(tree.getRoot());
                cout<<endl;
                n--;
            }
            cout<<"Sorted array: ";
            for(int i=0; i<count; i++)
                    cout<<MaxArr[i]<<" ";
            cout<<endl;
        }

        Node* Search(int x)  {
            Node* current = getRoot();

            if(search(current, x))
                return current;
            else    {
                cout<<"Node "<<x<<" not found!";
                return NULL;
            }
        }
        /* The implementation of this function Search
        has been based on the in-order traversal of the tree*/
        bool search(Node* current, int x)   {
            if(current==NULL)
                return false;

            if(current->data==x)    {
                cout<<"Node found!: "<<current->data;
                if(current->right!=NULL)
                    cout<<", right child: "<<current->right->data;
                if(current->left!=NULL)
                    cout<<", left child: "<<current->left->data;
                if(current->parent!=NULL)
                    cout<<", parent: "<<current->parent->data;
                return true;
            }
            //Here is possible to see the in.order traversal logic:
            bool sinistra = search(current->left, x); 
            if(sinistra)
                return true;

            bool destra = search(current->right, x);
            return destra;
        }
};