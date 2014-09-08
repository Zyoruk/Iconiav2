#ifndef NODE_H
#define NODE_H
//template < class K >
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
