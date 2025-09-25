#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

//classe cliente ----------------------
class Cliente{
public:
    int cpf;
    string nome;

    Cliente(string s, int n){
        nome = s;
        cpf = n;
    }
    Cliente(){
        nome = "Laranja";
        cpf = 00000000001;
    }

    void exibirInfoCliente(){
        cout << "Nome do Cliente: " << nome << ",\nCPF: " << cpf << endl;
    }
};


// classe Conta Bancária -------------------------
class ContaBancaria{
public:
    int numero;
    double saldo;
    Cliente titular;

    ContaBancaria(int num, Cliente &c){      //contrutor "minimo", com número e titular
        numero = num;
        titular = c;
        saldo = 0.0;
    }
    ContaBancaria(int num, Cliente &c, double sal){       //construtor com saldo
        numero = num;
        titular = c;
        saldo = sal;
    }

    void depositar(double n){       // método de depósito (erro se informado valores negativos)
        if(n<0){
            cout << "valor de depósito inválido!" << endl;
        }else{
            saldo += n;
            cout << "Depósito no valor de R$" << n << " realizado." << endl;
            exibirSaldo();
        }
    }

    void sacar(double n){       // método de saque (erro se informado valores negativos)
        if(n<0){
            cout << "valor de saque inválido!" << endl;
        }else if(n>saldo){
            cout << "Saldo Insuficiente para saque!" << endl;
        }else{
            saldo -= n;
            cout << "Saque efetuado no valor de R$" << n << endl;
            exibirSaldo();
        }
    }

    void transferir(double num, ContaBancaria &p){      // método de transferencia passando valor e um destinatário
        if (num<0){
            cout << "valor de saque inválido!" << endl;
        }else if(num>saldo){
            cout << "Saldo Insuficiente para transferência!" << endl;
        }else{
            saldo -= num;
            p.saldo += num;
            cout << "Transferência realizada para a conta: " << p.numero << endl;
        }
    }

    void transferir(double num, ContaBancaria &p, ContaBancaria &q){      // método de transferencia passando valor e dois destinatários
        if (num<0){
            cout << "valor de saque inválido!" << endl;
        }else if(num>saldo){
            cout << "Saldo Insuficiente para transferência!" << endl;
        }else{
            saldo -= num;
            p.saldo += (num/2);
            q.saldo += (num/2);
            cout << "Transferência realizada para as contas: " << p.numero << ", " << q.numero << endl;
        }
    }

    void exibirInformacoes(){
        cout << "Titular: " << titular.nome << ",\nCPF: " << titular.cpf << ",\nnumero da conta: " << numero << endl;
        exibirSaldo();
    }

    void exibirSaldo(){
        cout << "\nSaldo na conta: R$" << saldo << endl;
    }

};

int main()
{
    setlocale(LC_ALL, "Portuguese");



    return 0;
}
