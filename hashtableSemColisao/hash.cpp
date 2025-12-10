#include <iostream>
#include "hash.hpp"

    int Hash::funcaoHash(Aluno aluno)
    {
        return (aluno.obterRa()%hash_lenght);
    }



    Hash::Hash(int tam_vetor, int max_permitido)
    {
        qtditens_atual=0;
        qtditens_permitidos=max_permitido;
        hash_lenght=tam_vetor;
        estrutura=new Aluno[tam_vetor];
    }

    Hash::~Hash()
    {
        delete[] estrutura;
    }

    bool Hash::estaCheio()
    {
        return (qtditens_atual==qtditens_permitidos);
    }


    int Hash::obtertamanho_atual()
    {
        return qtditens_atual;
    }

    void Hash::inserir(Aluno aluno)
    {
        int indice=funcaoHash(aluno);
        estrutura[indice]=aluno;
        qtditens_atual++;
    }

    void Hash::deletar(Aluno aluno)
    {
        int indice=funcaoHash(aluno);
        if (estrutura[indice].obterRa()!=-1){
            estrutura[indice]=Aluno(-1, " ");
            qtditens_atual--;
        }
    }

    void Hash::buscar(Aluno& alunoBuscado, bool& busca)
    {
        int indice=funcaoHash(alunoBuscado);
        Aluno aux=estrutura[indice];
        if (alunoBuscado.obterRa()!=aux.obterRa()){
            busca=false;
        } else{
            busca=true;
            alunoBuscado=aux;
        }  
    }

    void Hash::imprimir(){
        cout<<"Tabela Hash:\n";
        for (int i=0; i<hash_lenght; i++){
            if (estrutura[i].obterRa()!=1){
                cout<<i<<estrutura[i].obterRa();
                cout<<estrutura[i].obterNome()<<endl;
            }
        }
    }