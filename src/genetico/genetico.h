#ifndef GENETICO_H
#define GENETICO_H

class Genetico
{
public:
    Genetico();
    /*!
     * \brief start creates and reproduces a genetic algorythm
     * \param Generaciones the amount of generations that the program is going to run
     * \return The object with the most fitness after X generations
     */
    int start(int Generaciones);
private:
    /*!
     * \brief crearIndividuo
     * \return an int with a new, random, object
     */
    int crearIndividuo();
    /*!
     * \brief crearPoblacion creates a random population of X elements
     * \param Densidad the amount of objects the population has
     */
    int crearPoblacion(int Densidad);
    /*!
     * \brief Reproducir takes a random pair of elements (may be the same) from the population
     *        to create other 2 objects, then it runs them through a fitness test
     */
    void Reproducir();
    /*!
     * \brief fitnessTest runs an object against the determined test (in this case a getFitness)
     * \param SubjectD the subject to be tested
     * \return the fitness value of the object
     */
    int fitnessTest (int* SubjectD);
    /*!
     * \brief fitnessTest adds the best objects to a temporal list
     * \param SubjectA
     * \param SubjectB
     * \param SubjectC
     * \param SubjectD
     */
    void fitnessTest (int* SubjectA, int* SubjectB, int* SubjectC, int* SubjectD);
    /*!
     * \brief cambiarGeneraciones convierte la lista temporal con los mejores (probablemente) individuos en la lista principal
     */
    void cambiarGeneraciones ();
    /*!
     * \brief conceguirMejorIndividuo
     * \return the object with best fitness
     */
    int conseguirMejorIndividuo ();
};

#endif // GENETICO_H
