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
void mostrarCromosomas (int Cromo) {
    for (int i = 0; i<sizeof(Cromo); i++) {

        Cromo=Cromo<<i;
        Cromo=Cromo>>sizeof(Cromo);
        cout << Cromo;               //imprime el valor despues del corrimiento (0 v 1)

    }
    cout << endl;
}


/*   Crea un mutageno a partir de un numero aleatorio que indica la posicion de este
 * el mutageno es un vector de bits con un único elemento en 1 (los demás están en cero)
 *
 * return vector de bits; el mutageno
 */
int crearMutageno (int Individuo) {

    srand (time(NULL));
    int RandomGen = rand() % sizeof(Individuo);

    int Vial = 0;
    Vial = ~Vial;
    Vial=Vial>>RandomGen;
    Vial=Vial<<(sizeof(Individuo)-1);
    Vial=Vial>>(sizeof(Individuo)-RandomGen);      //pone al mutageno en su posicion original

    int Mutante = Individuo^Vial;
    return Mutante;
}


/*   Utiliza la funcion XOR para unir los vectores de bits de esta forma
 *
 *
 * return vector de bits; el individuo mutado
 */
int mutar (int Individuo, int Mutageno) {
    int Xperson = Individuo^Mutageno;
    return Xperson;
}


/*   Esta función maneja la mutacion del individuo que toma como argumento.
 *  siempre devuelve al Individuo con un bit diferente, en forma de  int*
 *
 *
 */
int mutatron (int Individuo) {

    cout<< "El individuo original: "<<endl;
    mostrarCromosomas(Individuo);

    int Mutageno=crearMutageno(Individuo);
    cout<< "El mutageno: "<<endl;
    mostrarCromosomas(Mutageno);

    int Xperson = mutar(Individuo, Mutageno);
    cout<< "El individuo mutado: "<<endl;
    mostrarCromosomas(Xperson);

    return Xperson;
}


int main()
{
    int paciente;
    cin >> paciente;
    cout << paciente << endl;
    mutatron(paciente);
    return 0;
}

