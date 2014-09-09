#ifndef NODE_H
#define NODE_H
//template < class K >
/*!
 * \brief The Node class is the base of all other data structure nodes. The idea is to keep relationship
 * between all the different nodes.
 */
class Node {
public:
    Node();
    //Node(K pElement);
    virtual ~Node();
    virtual int* getElement();
    virtual void setElement(int pElement);
protected:
    int _element;
};
#endif // NODE_H
