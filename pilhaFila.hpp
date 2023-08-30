#include <iostream> 
using namespace std;

#define TAMF 50
#define TAMP 50

template <typename T>
struct Fila{
    T vetor[TAMF];
    int comeco, fim;
};

template <typename T>
struct Pilha{
    T vetor[TAMP];
    int topo;
};

template <typename T>
void inicializarFila(Fila <T> &f){
    f.comeco = 0;
    f.fim = -1;
}

template <typename T>
bool inserirFila(Fila <T> &f, T valor){
    if(f.fim == TAMF - 1) return false;
    f.fim++;
    f.vetor[f.fim] = valor;
    return true; 
}

template <typename T>
bool retirarFila(Fila <T> &f, T &valor){
    if(f.comeco > f.fim) return false;
    valor = f.vetor[f.comeco];
    f.comeco++;
    return true;
}

template <typename T>
bool filaVazia(Fila <T> f){
    return (f.comeco > f.fim) ? true : false;
}

template <typename T>
void mostrarFila(const Fila <T> &f){
    Fila <T> copia = f;
    T aux;
    while (retirarFila(copia, aux))
    {
        cout << aux << " ";
    }
    cout << endl;
}

template <typename T>
void inicializarPilha(Pilha <T> &p){
    p.topo = -1;
}

template <typename T>
bool inserirPilha(Pilha <T> &p, T valor){
    if(p.topo == TAMP - 1) return false;
    p.topo++;
    p.vetor[p.topo] = valor;
    return true;
}

template <typename T>
bool retirarPilha(Pilha <T> &p, T &valor){
    if(p.topo == -1) return false;
    valor = p.vetor[p.topo];
    p.topo--;
    return true;
}

template <typename T>
bool pilhaVazia(Pilha <T> p){
    return (p.topo == -1) ? true : false;
}

template <typename T>
void mostrarPilha(Pilha <T> p){
    T aux;
    while (retirarPilha(p, aux))
    {
        cout << aux << " ";
    }
    cout << endl;
}