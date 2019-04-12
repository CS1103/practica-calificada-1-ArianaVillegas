//
// Created by ruben on 4/12/19.
//

#include "TwoLinkedList.h"

UTEC::Node::Node(int n_value) {
    value=n_value;
    next= nullptr;
}

UTEC::Node::~Node() {
    if(next!= nullptr)
        delete next;
}

UTEC::TwoLinkedList::TwoLinkedList() {
    head1= nullptr;
    head2= nullptr;
    head= nullptr;
    tail1= nullptr;
    tail2= nullptr;
    tail= nullptr;
}

UTEC::TwoLinkedList::~TwoLinkedList() {
    Node *actual=head1;
    while (actual!=head){
        delete actual;
        actual=actual->next;
    }
    actual=head2;
    while (actual!=head){
        delete actual;
        actual=actual->next;
    }
    actual=head;
    while (actual!= nullptr){
        delete actual;
        actual=actual->next;
    }
}

void UTEC::TwoLinkedList::push_back1(int value) {
    Node *temp= new Node(value);
    if(tail== nullptr) {
        if (head1 == nullptr) {
            head1 = temp;
            tail1 = temp;
        } else {
            tail1->next = temp;
            tail1 = temp;
        }
    }else{
        tail->next=temp;
        tail=temp;
    }
}

void UTEC::TwoLinkedList::push_back2(int value) {
    Node *temp= new Node(value);
    if(tail== nullptr) {
        if (head2 == nullptr) {
            head2 = temp;
            tail2 = temp;
        } else {
            tail2->next = temp;
            tail2 = temp;
        }
    }else {
        tail->next = temp;
        tail = temp;
    }
}

std::string UTEC::TwoLinkedList::merge(int value) {
    Node *temp= new Node(value);
    if(head1!= nullptr && head2!= nullptr){
        if(tail== nullptr){
            tail1->next=temp;
            tail2->next=temp;
            head=temp;
            tail=temp;
            return "Operación Exitosa";
        }else{
            return "Operación duplicada";
        }
    }
}

bool UTEC::TwoLinkedList::is_merged() {
    if(tail!= nullptr)
        return true;
    else
        return false;
}

std::string UTEC::TwoLinkedList::list(int option, char sep) {
    std::string answer="";
    if(option==1){
        Node *actual=head1;
        while (actual!=head){
            std::string a=std::to_string(actual->value);
            answer+=a;
            answer+=sep;
            actual=actual->next;
        }
    }else if(option==2){
        Node *actual=head2;
        while (actual!=head){
            std::string a=std::to_string(actual->value);
            answer+=a;
            answer+=sep;
            actual=actual->next;
        }
    }else if(option==0){
        if(tail!= nullptr){
            Node *actual=head;
            while (actual!= nullptr){
                std::string a=std::to_string(actual->value);
                answer+=a;
                answer+=sep;
                actual=actual->next;
            }
        }
    }
    return answer;
}

std::string UTEC::TwoLinkedList::getlist(int option) {
    std::string answer=list(option,' ');
    return answer;
}

UTEC::Node* UTEC::TwoLinkedList::search(int value) {
    Node *datanode= nullptr;
    Node *actual=head1;
    while (actual!=head){
        if(actual->value==value){
            datanode=actual;
        }
        actual=actual->next;
    }
    actual=head2;
    while (actual!=head){
        if(actual->value==value){
            datanode=actual;
        }
        actual=actual->next;
    }
    actual=head;
    while (actual!= nullptr){
        if(actual->value==value){
            datanode=actual;
        }
        actual=actual->next;
    }
    return datanode;
}

void UTEC::TwoLinkedList::save(std::string fname) {
    std::ofstream sfile(fname);
    sfile<<list(1,',')<<'\n';
    sfile<<list(2,',')<<'\n';
    sfile<<list(0,',')<<'\n';
}

void UTEC::TwoLinkedList::load(std::string rname) {
    std::ifstream rfile(rname);
    if(rfile.is_open()){
        std::string line;
        line.pop_back();
        //list 1
        getline(rfile,line);
        std::istringstream sub1(line);
        while (getline(sub1,line,',')){
            push_back1(std::stoi(line));
        }
        //list 2
        getline(rfile,line);
        std::istringstream sub2(line);
        while (getline(sub2,line,',')){
            push_back2(std::stoi(line));
        }
        //merge list 1 and list 2
        getline(rfile,line);
        if(line!="") {
            std::istringstream sub(line);
            getline(sub, line, ',');
            merge(std::stoi(line));
            while (getline(sub, line, ',')) {
                push_back1(std::stoi(line));
            }
        }
    }
}