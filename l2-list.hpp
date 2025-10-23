#include <cstddef>
#include <cassert>
#include <string>

using namespace std;



class LinkedList {
    struct No{
        int chave;
        No* proximo;
}

        No* primeiro;
        size_t tamanho; 
public:
    LinkedList(); //OK
    ~LinkedList(); //OK

    size_t size(); //OK
    string at(size_t pos); //OK
    void insert(size_t pos, string value); //OK
    void push_back(string value); //insere elementos no final do vetor //OK
    void remove(size_t pos);

};

// ADD LINKEDLIST IMPLEMENTATION
LinkedList::LinkedList()
{
    primeiro=new No;
    primeiro->chave=-1;
    primeiro->proximo=nullptr;
    tamanho=0;
}

LinkedList::~LinkedList()
{
    No* atual=primeiro;
    No* proximo;
    while(atual!=nullptr){
        proximo=atual->proximo;
        delete atual;
        atual=proximo;
    }
}

size_t LinkedList::size(){
        return tamanho;
    }

string LinkedList::at(size_t pos){
    assert(pos<size());
    No *atual=primeiro;
    size_t i=0;
    while(i<pos && atual->proximo!=nullptr){
        atual=atual->proximo;
        i++;
    }
    return atual->proximo->chave;
}

void LinkedList::insert(size_t pos, string value){
    No* atual=primeiro;
    size_t i=0;
    while(i<pos && atual->proximo!=nullptr){
        atual=atual->proximo;
        i++;
    }

    No* novoNo=new No;
    novoNo->chave=value;

    novoNo->proximo=atual->proximo;
    atual->proximo=novoNo;
    tamanho++;
}

void LinkedList::push_back(string value){
    No* novoNo=new No;
    No* atual=primeiro;
    novoNo->chave=value;
    
    if (atual==nullptr){
        novoNo->proximo=nullptr;
        primeiro=novoNo;
        return;
    }
    while(atual->proximo!=nullptr){
        atual=atual->proximo;
    }
    novoNo->proximo=nullptr;
    atual->proximo=novoNo;
}

void LinkedList::remove(size_t pos){
    No* atual=primeiro;
    size_t i=0;
    while(i<pos && atual->proximo!=nullptr){
        atual=atual->proximo;
        i++;
    }
    No* retirar=atual->proximo;
    assert(retirar);
    atual->proximo=retirar->proximo;
    delete retirar;
    tamanho--;
}












class Stack {
    // ADD CODE HERE
public:
    size_t size();
    void push(string value);
    void pop();
    string top();
};

// ADD STACK IMPLEMENTATION


class Queue {
    // ADD CODE HERE
public:
    size_t size();
    void push(string value);
    void pop();
    string front();
};

// ADD QUEUE IMPLEMENTATION
