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
void incluirNoFim(tLista* pLista, float real1, float imaginario1)
{
  tComplexo* tComplex = criatComplexo(real1, imaginario1);

     if (listaVazia(pLista)) {
        pLista->primeiro = tComplex;
    } else {
        pLista->ultimo->proximo = tComplex;
    }

    pLista->ultimo = tComplex;
    pLista->marcador = tComplex;
    pLista->tamanho++;
}
void gravarLista(tLista* pLista, ofstream* outfile) {
    pLista->marcador = pLista->primeiro;

    while (!finalLista(pLista)) {
        float real1 = pLista->marcador->a;
        float imag1 = pLista->marcador->b;

        cout << "Número Complexo:" << " " << real1 << "+" << imag1 << "i" << endl;
        *outfile << real1 << " " << imag1 << endl;

        pLista->marcador = pLista->marcador->proximo;
    }
    *outfile << flush;
}

void escrever(int quant, tLista* pLista) {
    ofstream arquivo("db.txt", ios::out);
    if (!arquivo) {
        cout << "Arquivo db.txt nao pode ser aberto" << endl;
        abort();
    }

    for (int i = 0; i < quant; i++) {
        float a = 0;
        float b = 0;
       
        while(1){
            {
                cout << "\nRegistro numero: " << i + 1 << endl;
                cout << "Digite o número real: ";
                cin >> a;
                cout << "Digite o número imaginário: ";
                cin >> b;             
                break;
            }
        }
        incluirNoFim(pLista, a, b);

    }
    cout << "\nGravado: " << endl;
    gravarLista(pLista, & arquivo);
    arquivo.close();
}
void ler() {
    string line;
    tLista* leitura = new tLista;
    iniciaLista(leitura);

    ifstream inFile("db.txt", ios:: in );
    if (!inFile) {
        cout << "Arquivo db.txt nao pode ser aberto" << endl;
        abort();
    }
    if (inFile.peek() == ifstream::traits_type::eof()) {
        cout << "Arquivo vazio\n";
    }
    while(getline(inFile, line)){
            float a = 0;
            float b = 0;
            
            string sreal, simaginario;
            int wordpos = 0;
            
        for(int i = 0; i < line.length(); i++){
            if(wordpos == 0){
                if(line[i] != ' '){
                    sreal += line[i];
                }
                else{
                    wordpos++;
                    continue;
                }
            }
            if(wordpos == 1){
                if(line[i] != ' '){
                    simaginario += line[i];
                }
                else{
                    wordpos++;
                    continue;
                }
            }  
        }
        a = stof(sreal);
        b = stof(simaginario);
        incluirNoFim(leitura, a, b);
    }
    
    leitura->marcador = leitura->primeiro;

    while (!finalLista(leitura)) {
        float a= leitura->marcador->a;
        float b = leitura->marcador->b;
        cout << "Real: " << a << " - " << "Imaginário: " << b << " = " << a << "+" << b << "i" << endl;

        leitura->marcador = leitura->marcador->proximo;
    }
    free(leitura);
    inFile.close();
}