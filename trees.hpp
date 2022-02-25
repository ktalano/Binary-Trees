//Arboles
#ifndef TREES_H 
#define TREES_H

#include<iostream>
#include<string>

struct node{
    int data;
    struct node *left;
    struct node *right;
}; typedef node * Node;

class Tree{
    public:
        Tree();
        ~Tree();
        void destroy_tree();
        void insert_data(const int);
        void printBT();
    private:
        void printBT(const std::string&, const Node,bool);
        void destroy_tree(const Node);
        void insert_data(const Node,const int);
        Node root;
};

#endif /* TREES_H */