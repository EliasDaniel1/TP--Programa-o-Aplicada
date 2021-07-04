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