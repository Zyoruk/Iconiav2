#include "genetico.h"
#include "src/dataStructures/SimpleList/Node/SimpleListNode.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

Genetico::Genetico()
{
    this->_root = new Genetico();
}

 /*
  *   int Individuo = 120 (0/225)
  *   int Poblacion = 100 (1/250)
  *
  */

// Valor de fitness (obtenido de open cv)
// ListaSimple Poblacion [100]
// ListaSimple nuevaGeneracion [100]



/* Crea un individuo al azar
 *
 * return int con el valor del individuo
 */
int Genetico::crearIndividuo () {
  int RandomInd = rand()%225;     //numero al azar entre 0 y 225
  return RandomInd;
  }

/* crea un población al azar
 *
 *
 */
 void Genetico::crearPoblacion (int Densidad) {
     for (int i = 0; i<Densidad; i++) {
         Poblacion[i]=crearIndividuo();
     }
}


// /////////////////////////////////////////////////////////////////////// //


/* Este metodo toma dos elementos al azar de la lista, crea dos nuevos y los compara,
 * añade los mejores a una segunda lista, "nuevaGeneracion"
 *
 * Se puede agregar una máscara rand()%(sumadefitness) para que los mejores se reproduscan más
 *
 *
 */
void Genetico::Reproducir () {
    int iPadre = rand()%250;
    int iMadre = rand()%250;

    int* Padre = &ListaSimple.getNodo(iPadre);
    int* Madre = &ListaSimple.getNodo(iMadre);

    int iSplit = rand()%30+2;      //para 1 int 2<iSplit<30
    int iMutate = rand()%32;

    if (iSplit==iMutate) {

        int* tempPadre = Padre;
        int* tempMadre = Madre;
        tempPadre<<iSplit;
        tempMadre>>iSplit;
        int* hijoA = tempMadre^tempPadre;

        int* tempPadre = Padre;
        int* tempMadre = Madre;
        tempPadre>>iSplit;
        tempMadre<<iSplit;
        int* hijoB = tempMadre^tempPadre;

        mutatron(hijoA);
        fitnessTest(*Padre, *Madre, *hojaA, *hijoB);
    } else {

        int* tempPadre = Padre;
        int* tempMadre = Madre;
        tempPadre<<iSplit;
        tempMadre>>iSplit;
        int* hijoA = tempMadre^tempPadre;

        int* tempPadre = Padre;
        int* tempMadre = Madre;
        tempPadre>>iSplit;
        tempMadre<<iSplit;
        int* hijoB = tempMadre^tempPadre;

        fitnessTest(*Padre, *Madre, *hojaA, *hijoB);
    }
}


/* toma un elemento y lo compara con su fitness ideal (obtenido de la imagen), devuelve el int con el fitness
 * menor==mejor
 *
 *
 *
 */
int Genetico::fitnessTest (int* SubjectD) {
    return abs(conceguirFitness() - *SubjectD);
}

/* Toma tres elementos y los compara entre ellos, agrega los mejores dos elementos a nuevaGeneracion
 *
 *
 *
 *
 */
void Genetico::fitnessTest (int* SubjectA, int* SubjectB, int* SubjectC, int* SubjectD) {
    int A=fitnessTest(SubjectA);
    int B=fitnessTest(SubjectB);
    int C=fitnessTest(SubjectC);
    int D=fitnessTest(SubjectD);
    if (A<B) {
        if (B<C || B<D) {
            nuevaGeneracion.add(A);
        }
    } if (B<A) {
        if (B<C || B<D) {
            SimpleListNodo.add(B);
        }
    } if (C<D) {
        if (C<A || C<B) {
            SimpleListNodo.add(C);
        }
    } if (D<C) {
        if (D<A || D<B) {
            SimpleListNodo.add(D);
        }
    }
}

/* agrega los mejores elementos en NuevaGeneracion a Poblacion,
 * ie, cambia las generaciones
 *
 */
void Genetico::cambiarGeneraciones (SimpleListNode Poblacion, SimpleListNode nuevaGeneracion) {
    for (int i = 0; i<sizeof(Poblacion); i++) {
        Poblacion[i]=nuevaGeneracion[i];
    }
}

/* devuelve el mejor elemento de la lista simple Poblacion
 *
 *
 *
 */
int Genetico::conseguirMejorIndividuo() {
    int Mejor = 0;
    for (int i = 0; i<sizeof(Poblacion); i++) {
        if (Poblacion[i]==0) {
            Mejor = Poblacion[i];
        }
        if (Poblacion[i]<Mejor) {
            Mejor = Poblacion[i];
        }
    }
    return Mejor;
}


/* corre el programa por x generaciones (iteraciones)
 * a partir de una poblacion de X elementos creada al azar
 *
 *
 */
int Genetico::start (int Generaciones) {
    crearPoblacion(50);
    for (int i = 0; i<Generaciones; i++) {
        for (int i = 0; i<20; i++) {            //reproducciones por generacion
            Reproducir();
        }
        cambiarGeneraciones();
    }
    return conseguirMejorIndividuo();
}


// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// //
