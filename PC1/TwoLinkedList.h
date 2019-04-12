//
// Created by ruben on 4/12/19.
//

#ifndef PC1_TWOLINKEDLIST_H
#define PC1_TWOLINKEDLIST_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

namespace UTEC {
    struct Node{
        int value;
        Node *next;
        Node(int n_value);
        ~Node();
    };

    class TwoLinkedList {
    private:
        Node *head1;
        Node *head2;
        Node *head;
        Node *tail1;
        Node *tail2;
        Node *tail;
    public:
        TwoLinkedList();
        ~TwoLinkedList();
        void push_back1(int value);
        void push_back2(int value);
        std::string merge(int value);
        bool is_merged();
        std::string list(int option, char sep);
        std::string getlist(int option);
        Node *search(int value);
        void save(std::string fname);
        void load(std::string rname);
    };
}

#endif //PC1_TWOLINKEDLIST_H
