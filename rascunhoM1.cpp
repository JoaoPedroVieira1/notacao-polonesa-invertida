#include <iostream>
#include "pilhaFila.hpp"
using namespace std;

bool ehOperando(char elemento){
    return (((elemento >= 'a') && (elemento <= 'z')) || ((elemento >= 'A') && (elemento <= 'Z'))
    || ((elemento >= '0') && (elemento <= '9'))) ? true : false;
}

bool polonesa(Fila<char> &f, Pilha<char> &p, char elemento){
    char aux;
    bool flag = false;
    if(ehOperando(elemento)){
        return true;
    } 
    if(elemento == '('){ 
        inserirPilha(p, elemento);
        return true;
    }
    if (elemento == ')')
    {
        if(!pilhaVazia(p)){
            retirarPilha(p, aux);
            if(aux == '('){
                return false;
            }
        }
        return true;
    }
    if (elemento == '^')
    {
        inserirPilha(p, elemento);
        return true;
    }
    if (elemento == '*' || elemento == '/')
    {
        if(!pilhaVazia(p)) retirarPilha(p, aux);
        if (aux == '+' || aux == '-' || aux == '(')
        {
            inserirPilha(p, aux);
            inserirPilha(p, elemento);
            return true;
        }else{
            inserirPilha(p, aux);
            return false;
        }
    }
    if (elemento == '+' || elemento == '-')
    {
        if(!pilhaVazia(p)) retirarPilha(p, aux);
        if (aux == '(')
        {
            inserirPilha(p, aux);
            inserirPilha(p, elemento);
            return true;
        }else{
            inserirPilha(p, aux);
            return false;
        }
    }
}

int main(){
    Fila <char> f, res;
    Pilha <char> p;
    string expressao;

    inicializarFila(f);
    inicializarFila(res);
    inicializarPilha(p);

    cout << "Digite a expressao: ";
    cin >> expressao;

    for (int i = 0; i < expressao.length(); i++)
    {
        if(polonesa(f, p, expressao[i])){
            inserirFila(res, expressao[i]);
        }else{
            cout << "expressao invalida!";
            return 0;
        }
    }
}