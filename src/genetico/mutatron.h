#ifndef MUTATRON_H
#define MUTATRON_H

class Mutatron
{
public:
    Mutatron();
private:
    /*!
     * \brief mostrarCromosomas se utiliza principalmente para depurar el programa
     *                          muestra los cromosomas del objeto en unos y ceros en consola
     * \param Cromo el int que se va a mostrar en consola
     */
    void mostrarCromosomas (int Cromo);
    /*!
     * \brief crearMutageno crea un elemento cuyos cromosomas, excepto uno, son ceros.
     *                      El 1, se crea al azar
     * \return Mutante es el int creado
     */
    int crearMutageno ();
    /*!
     * \brief mutar toma el mutageno y el individuo y utiliza la funcion binaria XOR para modificar
     *        al individuo
     * \param Individuo el int a modificar
     * \param Mutageno el int que va a provocar la modificacion
     * \return XPerson, el int del individuo modificado
     */
    int mutar (int Individuo, int Mutageno);
    /*!
     * \brief mutatron maneja al int y crea el mutageno los une y los devuelve como int*, es una funciona para controlar
     * \param Individuo es obtenido del tester, es el individuo a mutar
     */
    int mutatron (int Individuo);
};

#endif // MUTATRON_H
