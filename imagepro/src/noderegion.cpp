/* implementation of the class NodeRegion
 */


#include "image/noderegion.hpp"
#include <iostream>

namespace image {

    NodeRegion::NodeRegion(Region* _region) : region(_region), next(nullptr), prev(nullptr) {}

    NodeRegion* NodeRegion::getNext() {
        return next;
    }

    NodeRegion* NodeRegion::getPrev() {
        return prev;
    }

    Region* NodeRegion::getRegion() {
        return region;
    }

    void NodeRegion::setNext(NodeRegion* _next) {
        next = _next;
    }

    void NodeRegion::setPrev(NodeRegion* _prev) {
        prev = _prev;
    }

    NodeRegion::~NodeRegion() {}
}