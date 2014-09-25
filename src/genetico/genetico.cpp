#include <iostream>
#include <stdlib.h>
#include <string.h>
#include"src/dataStructures/SimpleList/Node/SimpleListNode.h"
using namespace std;


int Individuo = 120;
int[100] Poblacion;

int conseguirFitness () {
  return 12658;
  }

// Valor de fitness (obtenido de open cv)
// ListaSimple Poblacion [100];
// ListaSimple nuevaGeneracion [100];

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
         Poblacion[i]=crearIndividuo();
     }
}



// /////////////////////////////////////////////////////////////////////// //



 /*    Escoge a un padre basado en una posibilidad que aumenta entre mejor sea su fitness
  *
  *
  *
  */
 int escogerPadre () {

     for (int i = 0; i<Poblacion::getLenght(); i++) {
         int FitnessTotal =+ Poblacion[i]+conceguirFitness();   //Manejamos el fitness de manera diferente
     }

     int RandPadre = rand()%FitnessTotal;

     for (int i = 0; i<sizeof(Poblacion); i++) {
         int FitnessTotal =+ Poblacion[i];
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

    //int Padre = Poblacion.getNodo(iPadre);
    //int Madre = Poblacion.getNodo(iMadre);

    int Padre = Poblacion[iPadre];
    int Madre = Poblacion[iMadre];

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
        cout << "mutatron activado" << endl;
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
    return abs(conceguirFitness() - SubjectD);
}

/* Toma tres elementos y los compara entre ellos, agrega los mejores dos elementos a nuevaGeneracion
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
            nuevaGeneracion.add(A);
        }
    } if (B<A) {
        if (B<C || B<D) {
            nuevaGeneracion.add(B);
        }
    } if (C<D) {
        if (C<A || C<B) {
            nuevaGeneracion.add(C);
        }
    } if (D<C) {
        if (D<A || D<B) {
            nuevaGeneracion.add(D);
        }
    }
}

/* agrega los mejores elementos en NuevaGeneracion a Poblacion,
 * ie, cambia las generaciones
 *
 *
 */
void cambiarGeneraciones (SimpleListNode Poblacion, SimpleListNode nuevaGeneracion) {
    for (int i = 0; i<Poblacion::getLenght(); i++) {
        Poblacion[i]=nuevaGeneracion[i];
    }
}

/* devuelve el mejor elemento de la lista simple Poblacion
 *
 *
 *
 */
int conseguirMejorIndividuo() {
    int Mejor = 0;
    for (int i = 0; i<Poblacion::getLenght(); i++) {
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
int start (int Generaciones) {
    crearPoblacion(50);
    for (int i = 0; i<Generaciones; i++) {

        for (int i = 0; i<20; i++) {            //reproducciones por generacion
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
    cout << "Ingrese la cantidad de generaciones: " << endl;
    cin >> G >> endl;
    start (G);
    return 0;
}
