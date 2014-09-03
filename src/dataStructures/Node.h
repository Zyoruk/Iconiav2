#ifndef NODE_H
#define NODE_H
//template < class K >
class Node {
public:
    Node();
    //Node(K pElement);
    virtual ~Node();
    int getElement();
    void setElement(int pElement);
private:
    int _element;
};
#endif // NODE_H
