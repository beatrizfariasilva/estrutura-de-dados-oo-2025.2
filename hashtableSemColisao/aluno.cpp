#include "aluno.hpp"    

    Aluno::Aluno(){
        RA=-1;
        nome=" ";
    }


    Aluno::Aluno(int r, string n){
        RA=r;
        nome=n;
    }


    int Aluno::obterRa(){
        return RA;
    }


    string Aluno::obterNome(){
        return nome;
    }