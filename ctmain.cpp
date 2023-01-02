#include "cartesianTree.cpp"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    unsigned seed = time(0);
    srand(seed);

    int i = rand() % 25+3;
    cout<<"Size of the Array: "<<i<<"\n";
    int arr[i];
    cout<<"Random Array: ";
    for(int j=0; j<i; j++)  { 
        arr[j] = rand() %100;
        cout<<arr[j]<<", ";
    }
    cout<<endl<<endl;

    //int arr[] = {10, 44, 22, 27, 37, 15, 48, 8, 36, 52, 24, 81};

    int n = sizeof(arr)/sizeof(arr[0]);

    CartesianTree tree = CartesianTree(arr, n); 
  
    printf("Inorder traversal of the constructed tree: \n"); 
    tree.printInorder(tree.getRoot());
    cout<<endl<<endl;

    printf("Postorder traversal of the constructed tree: \n"); 
    tree.printPostorder(tree.getRoot());
    cout<<endl<<endl;

    /*printAdvancedInorder print the inorder traversal 
    of the tree and all the relations among the nodes */
    printf("Upgraded Inorder traversal of the constructed tree \n");
    tree.printAdvancedInorder(tree.getRoot());
    cout<<endl<<endl;

    printf("Extract Max: \n");
    tree.ExtractMax(arr, n);
    cout<<endl<<endl;

    printf("Extract Min: \n");
    tree.ExtractMin(arr, n);
    cout<<endl<<endl; 

    printf("Now let's show the functions AddNode and Search \n");
    printf("Let's Search the number 101! \n");
    tree.Search(101); 
    cout<<endl;  
    printf("The function Search is going to be called again,\n");
    printf("but this time the number 101 is going to be present: \n");
    tree.addNode(101);
    tree.Search(101);

    cout<<endl<<endl;

    printf("Some examples of research with random numbers: \n");
    cout<<endl;
    tree.Search(rand()%100);
    cout<<endl;
    tree.Search(rand()%100);
    cout<<endl;
    tree.Search(rand()%100);
    cout<<endl;
    tree.Search(rand()%100);
    cout<<endl;
    tree.Search(rand()%100);

    return(0); 
} 