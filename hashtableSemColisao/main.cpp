#include <iostream>
#include "hash.hpp"

using namespace std;

int main(){
    int length, max_itens;
    cout<<"Programa gerador de Hash's!\n";
    cout<<"Digite a capacidade da Hash\n";
    cin>>length;
    cout<<"Digite o número máximo de elementos permitidos na Hash\n";
    cin>>max_itens;
    cout<<"O fator de carga é: "<<(float)max_itens/(float)length;

    Hash bancoDeAlunos(length, max_itens);
    int opcao;
    int ra;
    string nome;
    bool busca;

    do{
        cout<<"Escolha uma opção de 0 a 4\n";

        if (opcao==1){
            cout<<"Digite o RA do novo aluno\n";
            cin>>ra;
            cout<<"Digite o nome do novo aluno\n";
            cin>>nome;

            Aluno alunoNovo(ra, nome);
            bancoDeAlunos.inserir(alunoNovo);
        } else if (opcao==2){
            cout<<"Digite o RA do aluno a remover\n";
            cin>>ra;

            Aluno alunoNovo(ra, " ");
            bancoDeAlunos.deletar(alunoNovo);
        } else if (opcao==3){
            cout<<"Digite o RA do aluno procurado\n";
            cin>>ra;

            Aluno alunoNovo(ra, " ");
            bancoDeAlunos.buscar(alunoNovo, busca);

            if (busca){
                cout<<"Aluno encontrado:\n";
                cout<<"RA: "<<alunoNovo.obterRa()<<endl;
                cout<<"Nome: "<<alunoNovo.obterNome()<<endl;
            } else{
                cout<<"Aluno não encontrado:\n";
            }
        } else if (opcao==4){
            bancoDeAlunos.imprimir();
        }



    } while (opcao!=0);



    return 0;
}