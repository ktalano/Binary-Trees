#include<iostream>
#include<string>
#include"trees.hpp"
#include<time.h>
    
int main(){
    srand(time(NULL));
    Tree *arbol = new(Tree);
    for(int x=0;x<10;x++){
        arbol->insert_data(rand()%50);
    }
    arbol->printBT();
    system("pause");
    return 0;
}

//Constructor
Tree::Tree(){
    root=NULL;
}

//Insert First Node
void Tree::insert_data(const int _data){
    if (root!=NULL){
        insert_data(root,_data);
    }else{
        root= new node;
        root->data = _data;
        root->left = NULL;
        root->right = NULL;
    }
}

//Insert Node to Tree recursively
void Tree::insert_data(const Node nodo,const int _data){
    if(_data < nodo->data){
        if(nodo->left != NULL) insert_data(nodo->left,_data);
        else{
            nodo->left = new node;
            nodo->left->data = _data;
            nodo->left->left = NULL; nodo->left->right = NULL; 
        }
    }else{
        if(nodo->right != NULL) insert_data(nodo->right,_data);
        else{
            nodo->right = new node;
            nodo->right->data = _data;
            nodo->right->left = NULL; nodo->right->right = NULL; 
        }
    }
}

//Destructor
Tree::~Tree(){
    destroy_tree();
}

//Destroy Tree for public
void Tree::destroy_tree(){
    destroy_tree(root);
}


//Destroy tree recursively
void Tree::destroy_tree(const Node nodo){
    if(nodo!=NULL){
        destroy_tree(nodo->left);
        destroy_tree(nodo->right);
        delete nodo;
    }
}

//Print copy & paste
void Tree::printBT(const std::string& prefix, const Node nodo, bool isLeft)
{
    if (nodo != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        // print the value of the node
        std::cout << nodo->data << std::endl;
        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), nodo->right, true);
        printBT(prefix + (isLeft ? "|   " : "    "), nodo->left, false);
    }
}

//Print copy & paste for public
void Tree::printBT(){
    printBT("", root, false);
}



