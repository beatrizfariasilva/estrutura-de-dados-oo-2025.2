#include "aluno.hpp"

class Hash{
private:
    int funcaoHash(Aluno aluno);
    int qtditens_permitidos;
    int hash_lenght;
    int qtditens_atual;
    Aluno* estrutura;

public:
    Hash(int tam_vetor, int max_permitido);
    ~Hash();
    bool estaCheio();
    int obtertamanho_atual();
    void inserir(Aluno aluno);
    void deletar(Aluno aluno);
    void buscar(Aluno& aluno, bool& busca);
    void imprimir();
};