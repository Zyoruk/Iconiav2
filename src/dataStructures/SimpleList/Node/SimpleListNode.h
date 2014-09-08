#ifndef SIMPLELISTNODE_H
#define SIMPLELISTNODE_H
#include "src/dataStructures/Node.h"
/*!
 * \brief The SimpleListNode class. A simple list node is the corresponding node to the data structure
 * "simple linked list".
 */
class SimpleListNode: public Node {
public:
    /*!
     * \brief SimpleListNode is the constructor
     */
    SimpleListNode();
    virtual ~SimpleListNode();
    /*!
     * \brief setElement function that sets the element of the node
     * \param pElement the element that is going to be set
     */
    void setElement(int pElement);
    /*!
     * \brief getElement
     * \return the element that contains the node.
     */
    int* getElement();
    /*!
     * \brief setNext
     * \param pNextNode
     */
    void setNext(SimpleListNode* pNextNode);
    /*!
     * \brief getNext
     * \return
     */
    SimpleListNode* getNext();
    /*!
     * \brief setPrevious
     * \param pPreviousNode
     */
    void setPrevious(SimpleListNode* pPreviousNode);
    /*!
     * \brief getPrevious
     * \return
     */
    SimpleListNode* getPrevious();
private:
    /*!
     * \brief _next this is a pointer to a node that is said is next to the current one
     */

    Node* _next ;
    /*!
     * \brief _previous pointer to the node is said is before the current one
     */
    Node* _previous;
};

#endif // SIMPLELISTNODE_H

