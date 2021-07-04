#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct tComplexo {
  float a;
  float b;
  tComplexo* proximo;
};

tComplexo* criatComplexo(float real1, float imaginario1 ){
  tComplexo* tComplex = new tComplexo;
  tComplex->a = real1;
  tComplex->b = imaginario1;

  return tComplex;
}
struct tLista {
    tComplexo* primeiro;
    tComplexo* ultimo;
    tComplexo* marcador;
    int tamanho;
};

void iniciaLista(tLista* pLista) {
    pLista->primeiro = NULL;
    pLista->ultimo = NULL;
    pLista->marcador = NULL;
    pLista->tamanho = 0;
}

int obterTamanho(tLista* pLista) {
    return pLista->tamanho;
}

bool listaVazia(tLista* pLista) {
    return (pLista->tamanho == 0);
}

bool finalLista(tLista* pLista) {
    return (pLista->marcador == NULL);
}