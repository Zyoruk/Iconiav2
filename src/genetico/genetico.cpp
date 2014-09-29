#include <iostream>
#include <stdlib.h>

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
cout << "Generacion: " << i << endl;
       for ( short j = 0 ; j < Densidad/2 ; j++){
          Reproducir(j ,Densidad);
//cout << j << " " << this->nuevaGeneracion->getLenght() << endl;
       }
        cambiarGeneraciones();
   }
}

/*     Se consigue a partir de openCV
*
*/
void Genetico::conseguirFitness () {
    this->Fitness = 255;
 }

/* crea un población al azar
*
*
*
*/
void Genetico::crearPoblacion (short Densidad) {
    conseguirFitness();
    srand (static_cast <unsigned> (time(0)));
    for (short i = 0; i<Densidad; i++) {
        this->Poblacion->append(static_cast <int> (rand()) / (static_cast <int> (RAND_MAX/Fitness)) );
    }
//cout << "Poblacion creada, densidad: " << this->Poblacion->getLenght() << endl;
}

// /////////////////////////////////////////////////////////////////////// //


/* Escoge a un padre basado en una posibilidad que aumenta entre mejor sea su fitness
 *
 *
 *
 */
//short Genetico::escogerPadre () {

//    float FitnessTotal=0;
//    unsigned short Index = 0;

//    for (unsigned short i = 0; i<(this->Poblacion->getLenght()); i++) {
//       //cout << fitnessTest(*this->Poblacion->elementAt(i)->getElement()) << " ";
//       FitnessTotal =+ 1.0/(fitnessTest(*this->Poblacion->elementAt(i)->getElement()))+1;
//    }

//    //cout << FitnessTotal;

//    srand (static_cast <unsigned> (time(0)));
//    float RandPadre = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/FitnessTotal));

//    //cout << RandPadre;

//    FitnessTotal = 0;

//    for (unsigned short i = 0; i<this->Poblacion->getLenght(); i++) {
//        FitnessTotal =+ 1/(fitnessTest(*this->Poblacion->elementAt(i)->getElement()))+1;
//        if (RandPadre <= FitnessTotal) {
//            Index = i;
//        }
//    }
//    return (short)Index;
//}

/* toma un elemento y lo compara con su fitness ideal (obtenido de la imagen), devuelve el fitness real
 * entre menor sea el fitness, se considera mejor
 *
 *
 */
short Genetico::fitnessTest (short SubjectD) {
    return abs(Fitness - SubjectD);
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
    SimpleList<short>* numbers = new SimpleList<short>();
    numbers->append(A);
    numbers->append(B);
    numbers->append(C);
    numbers->append(D);
    //appends best element to nuevaGeneracion
    if ( *numbers->getHead()->getElement() == A){
        this->nuevaGeneracion->append(SubjectA);
    }else if ( *numbers->getHead()->getElement() == B){
        this->nuevaGeneracion->append(SubjectB);
    }else if ( *numbers->getHead()->getElement() == C){
        this->nuevaGeneracion->append(SubjectC);
    }else{
        this->nuevaGeneracion->append(SubjectD);
    }
    //appends second best element to nuevaGeneracion
    if ( *numbers->getHead()->getNext()->getElement() == A){
        this->nuevaGeneracion->append(SubjectA);

    }else if ( *numbers->getHead()->getNext()->getElement()== B){
        this->nuevaGeneracion->append(SubjectB);

    }else if (*numbers->getHead()->getNext()->getElement() == C){
        this->nuevaGeneracion->append(SubjectC);

    }else{
        this->nuevaGeneracion->append(SubjectD);
    }
}


/* Este metodo toma dos elementos al azar de la lista, crea dos nuevos y los compara,
* añade los mejores a una segunda lista, "nuevaGeneracion"
*
* Se puede agregar una máscara rand()%(sumadefitness) para que los mejores se reproduscan más
*
*
*/
void Genetico::Reproducir (int seed, short Densidad) {
    SimpleList<short>* iChoose = new SimpleList<short>();
    srand (static_cast <unsigned> (time(0)));
    for (short i = 0; i<2; i++){
//half the population, in case the last object gets the biggest seed
        short RandPadre = static_cast <int> (rand()) / (static_cast <int> (RAND_MAX/(Densidad/2)));
        iChoose->append(RandPadre);
    }

//Due to the nature of the generic funciton we add a seed, j from the for loop, this makes random numbers n every iteration
    short iPadre = *iChoose->elementAt(0)->getElement()+seed;
    short iMadre = *iChoose->elementAt(1)->getElement()+seed;

    short Padre = *this->Poblacion->elementAt(iPadre)->getElement();
    short Madre = *this->Poblacion->elementAt(iMadre)->getElement();

//    cout << "Padre: " << Padre << " ";
//    cout << "Madre: " << Madre << " ";

    srand (static_cast <unsigned> (time(0)));
    short iSplit = static_cast <int> (rand()) / (static_cast <int> (RAND_MAX/14));
    iSplit += 1;

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

//   cout << "hijoa:" << hijoA << " ";
//   cout << "hijob: " << hijoB <<endl;

   if (iSplit>10) {
       //cout << "Mutatron activado, iSplit: " << iSplit <<endl;
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

    SimpleListNode<short>* temp = nuevaGeneracion->getHead();
    int i = 0;
    while (nuevaGeneracion->getLenght() != 0 ){
        Poblacion->elementAt(i)->setElement(*temp->getElement());
        nuevaGeneracion->deleteHead();
        temp = nuevaGeneracion->getHead();
        i++;
    }
    cout << "\n";
    this->Poblacion->describe();
    cout << " \n";
    cout << this->nuevaGeneracion->getLenght()<<endl;
    cout << this->Poblacion->getLenght()<<endl;
}
