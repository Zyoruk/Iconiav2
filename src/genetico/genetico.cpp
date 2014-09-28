#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "src/dataStructures/SimpleList/SimpleList.h"
#include "src/genetico/genetico.h"
#include "src/genetico/mutatron.h"
using namespace std;

/* corre el programa por x generaciones (iteraciones)
* a partir de una poblacion de X elementos, X par X/2 par, creada al azar
*
* reproduce hasta que las generaciones tenga la misma cantidad de elementos
*/
Genetico::Genetico (short Generaciones, short Densidad) {
   this->nuevaGeneracion = new SimpleList<short>();
   this->Poblacion = new SimpleList<short>();
   crearPoblacion(Densidad);
   for (short i = 0; i<Generaciones; i++) {
       cout << "Generacion" << i << endl;
       for ( short j = 0 ; j < Densidad/2 ; j++){          //Se obtienen dos elementos de cada reproduccion -> Densidad/2 reproducciones = Densidad elementos
          Reproducir();
          cout << j << " " << this->nuevaGeneracion->getLenght() << endl;
       }
       cambiarGeneraciones();
   }
}

/*     Se consigue a partir de openCV
*
*/
short Genetico::conseguirFitness () {
 return 158;
 }

/* crea un población al azar
*
*
*
*/
void Genetico::crearPoblacion (short Densidad) {
    srand (static_cast <unsigned> (time(0)));
    for (short i = 0; i<Densidad; i++) {
        this->Poblacion->append(static_cast <int> (rand()) / (static_cast <int> (RAND_MAX/225)) );
    }
}

// /////////////////////////////////////////////////////////////////////// //


/* Escoge a un padre basado en una posibilidad que aumenta entre mejor sea su fitness
 *
 *
 *
 */
short Genetico::escogerPadre () {

    float FitnessTotal=0;
    unsigned short Index = 0;

    for (unsigned short i = 0; i<(this->Poblacion->getLenght()); i++) {
       //cout << fitnessTest(*this->Poblacion->elementAt(i)->getElement()) << " ";
       FitnessTotal =+ 1.0/(fitnessTest(*this->Poblacion->elementAt(i)->getElement()))+1;
    }

    //cout << FitnessTotal;

    srand (static_cast <unsigned> (time(0)));
    float RandPadre = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/FitnessTotal));

    //cout << RandPadre;

    FitnessTotal = 0;

    for (unsigned short i = 0; i<this->Poblacion->getLenght(); i++) {
        FitnessTotal =+ 1/(fitnessTest(*this->Poblacion->elementAt(i)->getElement()))+1;
        if (RandPadre <= FitnessTotal) {
            Index = i;
        }
    }
    return (short)Index;
}

/* toma un elemento y lo compara con su fitness ideal (obtenido de la imagen), devuelve el fitness real
 * entre menor sea el fitness, se considera mejor
 *
 *
 */
short Genetico::fitnessTest (short SubjectD) {
    return abs(conseguirFitness() - SubjectD);
}

/* Toma tres elementos y los compara entre ellos, agrega los mejores dos elementos a nuevaGeneracion
 *
 *
 *
 */
void Genetico::seleccionNatural (short SubjectA, short SubjectB, short SubjectC, short SubjectD) {
    short A=fitnessTest(SubjectA);
    short B=fitnessTest(SubjectB);
    short C=fitnessTest(SubjectC);
    short D=fitnessTest(SubjectD);
    short flag= 0;
    //cout << A << " ";
    //cout << B << " ";
    //cout << C << " ";
    //cout << D << " ";
    if (A<B) {
        if (B<=C || B<=D) {
            flag++;
            this->nuevaGeneracion->append(A);
            //cout << nuevaGeneracion->getLenght();
        }
    }
    if (B<=A) {
        if (B<=C || B<=D) {
            flag++;
            this->nuevaGeneracion->append(B);
            //cout << nuevaGeneracion->getLenght();
        }
   }
   if (flag<2) {                                                      // no han habido dos hijos
       if (C<D) {
           if (C<=A || C<=B) {
               flag++;
               this->nuevaGeneracion->append(C);
               //cout << nuevaGeneracion->getLenght();
           }
       }

       if (D<=C) {
           if (D<=A || D<=B) {
               flag++;
               this->nuevaGeneracion->append(D);
               //cout << nuevaGeneracion->getLenght();
           }
       }
   }
   if (flag<2) {                                                     // no han habido dos hijos, agregue uno
       this->nuevaGeneracion->append(D);
   }
}


/* Este metodo toma dos elementos al azar de la lista, crea dos nuevos y los compara,
* añade los mejores a una segunda lista, "nuevaGeneracion"
*
* Se puede agregar una máscara rand()%(sumadefitness) para que los mejores se reproduscan más
*
*
*/
void Genetico::Reproducir () {
    SimpleList<short>* iChoose = new SimpleList<short>();
    srand (static_cast <unsigned> (time(0)));
    for (short i = 0; i<2; i++){
        short RandPadre = static_cast <int> (rand()) / (static_cast <int> (RAND_MAX/225));
        //cout << RandPadre << endl;
        iChoose->append(RandPadre);
    }
    short iPadre = *iChoose->elementAt(0)->getElement();
    short iMadre = *iChoose->elementAt(1)->getElement();

   //short iPadre = 39;
   //short iMadre = 25;

   //short iPadre = escogerPadre ();
   //short iMadre = escogerPadre ();

   short Padre = *this->Poblacion->elementAt(iPadre)->getElement();
   short Madre = *this->Poblacion->elementAt(iMadre)->getElement();

   //cout << Padre << " ";
   //cout << Madre << " ";

   srand (static_cast <unsigned> (time(0)));
   short iSplit = static_cast <int> (rand()) / (static_cast <int> (RAND_MAX/14));
   iSplit += 2;

   cout << iSplit;

   short tempPadre = Padre;
   short tempMadre = Madre;
   tempPadre = tempPadre<<iSplit;
   tempMadre = tempMadre>>iSplit;
   short hijoA = tempMadre^tempPadre;

   tempPadre = Padre;
   tempMadre = Madre;
   tempPadre = tempPadre>>iSplit;
   tempMadre = tempMadre<<iSplit;
   short hijoB = tempMadre^tempPadre;

   if (iSplit<10) {
       Mutatron* mt = new Mutatron(hijoA);
       //hijoA = mt.mutatron(hijoA);
       cout << "Mutatron activado" << endl;
       seleccionNatural(Padre, Madre, hijoA, hijoB);         //se agregan los dos mejores a nuevaGeneracion
   } else {
       seleccionNatural(Padre, Madre, hijoA, hijoB);         //se agregan los dos mejores a nuevaGeneracion
   }

}

/* agrega los mejores elementos en NuevaGeneracion a Poblacion,
* ie, cambia las generaciones
*
*
*/
void Genetico::cambiarGeneraciones () {
//    cout << this->Poblacion->getLenght()<<endl;
   Poblacion=nuevaGeneracion;
//    cout << this->Poblacion->getLenght() << " ";
   this->nuevaGeneracion->clear();
//    cout << this->nuevaGeneracion->getLenght()<<endl;
//    cout << this->Poblacion->getLenght()<<endl;
//    cout << "Cambio de Generacion" << endl;
//    cout << endl;

}

