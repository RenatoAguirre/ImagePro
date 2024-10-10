/* implementation of the class NodePoint2D
 */


#include "image/nodepoint2d.hpp"
#include <iostream>

namespace image { 
  
      NodePoint2D::NodePoint2D(): point(nullptr), next(nullptr) {}
  
      NodePoint2D::NodePoint2D(Point2D* _point) : point(_point), next(nullptr) {}
  
      void NodePoint2D::setNext(NodePoint2D* _next) {
          next = _next;
      }
  
      NodePoint2D* NodePoint2D::getNext() {
          return next;
      }
  
      Point2D* NodePoint2D::getPoint() {
          return point;
      }
  
      NodePoint2D::~NodePoint2D() {}
}