#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "src/dataStructures/SimpleList/SimpleList.h"
#include "src/genetico/mutatron.cpp"
using namespace std;


SimpleList<int> Poblacion;
SimpleList<int> nuevaGeneracion;

/* Valor de fitness (obtenido de open cv)
 *
 *
 *
 */
int conseguirFitness () {
  return 158;
  }

/* Crea un individuo al azar
 *
 *
 * return int con el valor del individuo
 */
int crearIndividuo () {
  int RandomInd = rand()%225;     //numero al azar entre 0 y 225
  return RandomInd;
  }

/* crea un población al azar
 *
 *
 *
 */
 void crearPoblacion (int Densidad) {
     for (int i = 0; i<Densidad; i++) {
         this.Poblacion::elementAt(i)=crearIndividuo();
     }
}



// /////////////////////////////////////////////////////////////////////// //



 /*    Escoge a un padre basado en una posibilidad que aumenta entre mejor sea su fitness, i.e.,
  * ente mayor sea el fitness (peor) menor es la posibilidad de reproducirse ya que (1/fitness) generará un número menor
  *
  *
  *
  */
 int escogerPadre () {

     for (int i = 0; i<this.Poblacion::getLenght(); i++) {
        float FitnessTotal =+ 1/conseguirFitness();   //Manejamos el fitness de manera diferente, ente mayor sea el fitness (peor) menor es la posibilidad de reproducirse
     }

     float RandPadre = rand()%FitnessTotal;

     for (int i = 0; i<this.Poblacion::getLenght(); i++) {
         float FitnessTotal =+ 1/conseguirFitness();
         if (RandPadre <= FitnessTotal) {
             return i;
         }
     }
 }

/* Este metodo toma dos elementos al azar de la lista, crea dos nuevos y los compara,
 * añade los mejores a una segunda lista, "nuevaGeneracion"
 *
 * Se puede agregar una máscara rand()%(sumadefitness) para que los mejores se reproduscan más
 *
 *
 */
void Reproducir () {
    int iPadre = escogerPadre ();
    int iMadre = escogerPadre ();

    int Padre = this.Poblacion::elementAt(iPadre);
    int Madre = this.Poblacion::elementAt(iMadre);

    int iSplit = rand()%30+2;      //para 1 int 2<iSplit<30
    int iMutate = rand()%32;

    int tempPadre = Padre;
    int tempMadre = Madre;
    tempPadre = tempPadre<<iSplit;
    tempMadre = tempMadre>>iSplit;
    int hijoA = tempMadre^tempPadre;

    int tempPadre = Padre;
    int tempMadre = Madre;
    tempPadre = tempPadre>>iSplit;
    tempMadre = tempMadre<<iSplit;
    int hijoB = tempMadre^tempPadre;
    if (iSplit==iMutate) {
        mutatron(hijoA);
        fitnessTest(Padre, Madre, hijoA, hijoB);         //se agregan los dos mejores a nuevaGeneracion
    } else {
        fitnessTest(Padre, Madre, hijoA, hijoB);         //se agregan los dos mejores a nuevaGeneracion
    }

}

/* toma un elemento y lo compara con su fitness ideal (obtenido de la imagen), devuelve el int con el fitness
 * menor==mejor
 *
 *
 */
int fitnessTest (int SubjectD) {
    return abs(conseguirFitness() - SubjectD);
}


/* Toma cuatro elementos y los compara entre ellos, agrega los mejores dos elementos a nuevaGeneracion
 *
 *
 *
 */
void fitnessTest (int SubjectA, int SubjectB, int SubjectC, int SubjectD) {
    int A=fitnessTest(SubjectA);
    int B=fitnessTest(SubjectB);
    int C=fitnessTest(SubjectC);
    int D=fitnessTest(SubjectD);
    if (A<B) {
        if (B<C || B<D) {
            this.nuevaGeneracion::append(A);
        }
    } if (B<A) {
        if (B<C || B<D) {
            this.nuevaGeneracion::append(B);
        }
   } if (C<D) {
        if (C<A || C<B) {
            this.nuevaGeneracion::append(C);
        }
    } if (D<C) {
        if (D<A || D<B) {
            this.nuevaGeneracion::append(D);
        }
    }
}

/* agrega los mejores elementos en NuevaGeneracion a Poblacion,
 * ie, cambia las generaciones
 *
 *
 */
void cambiarGeneraciones () {
    for (int i = 0; i<this.Poblacion::getLenght(); i++) {
        this.Poblacion::elementAt(i)=this.nuevaGeneracion::elementAt(i);
    }
    this.nuevaGeneracion::clear();
}


/* devuelve el mejor elemento de la lista simple Poblacion
 *
 *
 *
*/
int conseguirMejorIndividuo() {
    int Mejor=32766;
    for (int i = 0; i<this.Poblacion::getLenght(); i++) {
        if (fitnessTest(this.Poblacion::elementAt(i)<Mejor)) {
            Mejor = this.Poblacion::elementAt(i);
       }
    }
    return Mejor;
}



/* corre el programa por x generaciones (iteraciones)
* a partir de una poblacion de X elementos creada al azar
 *
 * reproduce hasta que las generaciones tenga la misma cantidad de elementos
 */
int start (int Generaciones, int pPoblacion) {
    crearPoblacion(pPoblacion);
    for (int i = 0; i<Generaciones; i++) {

        while (this.nuevaGeneracion::getLenght()<this.Poblacion)) {            //
           Reproducir();
        }
        cambiarGeneraciones();
    }
    return conseguirMejorIndividuo();
}

/*   Corre el prorama
*
 */
int main()
{
    int G = 0;
    int P = 0;
    cout << "Ingrese la cantidad de generaciones: " << endl;
    cin >> G >> endl;
    cout << "Ingrese la población máxima: " << endl;
    cin >> P >> endl;
    start (G, P);
    return 0;
}