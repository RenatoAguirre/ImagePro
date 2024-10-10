/* implementation of the class ListOfRegion
 */

#include "image/listofregion.hpp"
#include <iostream>
#include <stack>
#include <vector>
#include "image/region.hpp"
#include "image/point2D.hpp"


namespace image {

    ListOfRegion::ListOfRegion() : head(nullptr), tail(nullptr), size(0) {}

    void ListOfRegion::add(Region* _region) {
        NodeRegion* node = new NodeRegion(_region);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->setNext(node);
            node->setPrev(tail);
            tail = node;
        }
        size++;
    }
    void ListOfRegion::remove(int _index) {
        if (_index < 0 || _index >= size) {
            return;
        }
        NodeRegion* current = head;
        for (int i = 0; i < _index; i++) {
            current = current->getNext();
        }
        NodeRegion* prev = current->getPrev();
        NodeRegion* next = current->getNext();
        if (prev != nullptr) {
            prev->setNext(next);
        } else {
            head = next;
        }
        if (next != nullptr) {
            next->setPrev(prev);
        } else {
            tail = prev;
        }
        delete current;
        size--;
    }
    Region* ListOfRegion::get(int index) {
        NodeRegion* current = head;
        int count = 0;

        // Recorremos la lista enlazada hasta llegar al índice deseado
        while (current != nullptr) {
            if (count == index) {
                return current->getRegion(); // Devolver el puntero a Region
            }
            count++;
            current = current->getNext();
        }
        return nullptr; // Si el índice no es válido
    }
    int ListOfRegion::getSize() {
        return size;
    }
    ListOfRegion::~ListOfRegion() {
        NodeRegion* current = head;
        while (current != nullptr) {
            NodeRegion* next = current->getNext();
            delete current;
            current = next;
        }
    }

}

