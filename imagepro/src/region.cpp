/* implementation of the class Region
 */

#include "image/region.hpp"
#include <iostream>

namespace image {

    Region::Region() : id(0), size(0) {}

    void Region::showRegion() {
        std::cout << "Region: " << id << std::endl;
        for (int i = 0; i < points.getSize(); i++) {
            Point2D* p = points.get(i);
            std::cout << "Point: " << p->getX() << " " << p->getY() << std::endl;
        }
    }
    

    Region::~Region() {}
}