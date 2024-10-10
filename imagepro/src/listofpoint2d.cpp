/* implementation of the class ListOfPoint2D
 */

#include "image/listofpoint2d.hpp"
#include <iostream>
#include "image/nodepoint2d.hpp"
#include "image/point2D.hpp"

namespace image {
  
      ListOfPoint2D::ListOfPoint2D() : head(nullptr), tail(nullptr), size(0) {}
  
      void ListOfPoint2D::add(Point2D* _point) {
          NodePoint2D* node = new NodePoint2D(_point);
          if (head == nullptr) {
              head = node;
              tail = node;
          } else {
              tail->setNext(node);
              tail = node;
          }
          size++;
      }
  
      void ListOfPoint2D::remove(int _index) {
          if (_index < size) {
              NodePoint2D* current = head;
              NodePoint2D* previous = nullptr;
              int i = 0;
              while (i < _index) {
                  previous = current;
                  current = current->getNext();
                  i++;
              }
              if (current != nullptr) {
                  if (previous != nullptr) {
                      previous->setNext(current->getNext());
                  } else {
                      head = current->getNext();
                  }
                  delete current;
                  size--;
              }
          }
      }
  
      Point2D* ListOfPoint2D::get(int _index) {
          if (_index < size) {
              NodePoint2D* current = head;
              int i = 0;
              while (i < _index) {
                  current = current->getNext();
                  i++;
              }
              return current->getPoint();
          }
          return nullptr;
      }
  
      int ListOfPoint2D::getSize() {
          return size;
      }
  
      ListOfPoint2D::~ListOfPoint2D() {
          NodePoint2D* current = head;
          NodePoint2D* next = nullptr;
          while (current != nullptr) {
              next = current->getNext();
              delete current;
              current = next;
          }
      }

}