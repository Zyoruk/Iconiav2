#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;


/*   Muestra los cromosomas booleanos del elemento dado,
 * se utiliza principalmente para depurar individualmente
 *
 *
 */
void printBits(unsigned int num)
{
   for(int bit=0;bit<(sizeof(unsigned int) * 8); bit++)
   {
      printf("%i ", num & 0x01);
      num = num >> 1;
   }
   cout << endl;
}


/*   Crea un mutageno a partir de un numero aleatorio que indica la posicion de este
 * el mutageno es un vector de bits con un único elemento en 1 (los demás están en cero)
 *
 * return vector de bits; el mutageno
 */
unsigned int crearMutageno (unsigned int Individuo) {

    srand (time(NULL));
    unsigned int RandomGen = rand() % sizeof(Individuo)*8+1;

    unsigned int Vial = 0;
    Vial = ~Vial;
    Vial=Vial>>31;                                                         //Da problemas convirtiendo sizeof()...
    Vial=Vial<<RandomGen;

    return Vial;
}


/*   Utiliza la funcion XOR para unir los vectores de bits de esta forma
 *
 *
 * return vector de bits; el individuo mutado
 */
unsigned int mutar (unsigned int Individuo, unsigned int Mutageno) {
    unsigned int Xperson = Individuo^Mutageno;
    return Xperson;
}


/*   Esta función maneja la mutacion del individuo que toma como argumento.
 *  siempre devuelve al Individuo con un bit diferente, en forma de  int*
 *
 *
 */
unsigned int mutatron (unsigned int Individuo) {

    unsigned int Mutageno=crearMutageno(Individuo);
    unsigned int Xperson = mutar(Individuo, Mutageno);
    return Xperson;
}


int mainMutatron()
{
    unsigned int paciente;
    cin >> paciente;
    int Mutante = mutatron(paciente);

    return Mutante;
}
