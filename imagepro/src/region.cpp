/* implementation of the class Region
 */

#include "image/region.hpp"
#include <iostream>

namespace image {

    Region::Region() : id(0), size(0) {}

    void Region::showRegion(int imgWidth, int imgHeight) {
        std::vector<std::vector<int>> matrix(imgHeight, std::vector<int>(imgWidth, 0));

        for (int i = 0; i < points.getSize(); ++i) {
            Point2D* p = points.get(i);
            int x = p->getX();
            int y = p->getY();
            matrix[y][x] = 1; 
        }

        for (int row = 0; row < imgHeight; ++row) {
            for (int col = 0; col < imgWidth; ++col) {
                std::cout << matrix[row][col];
            }
            std::cout << std::endl; 
        }
    }
    
    void Region::addPoint(Point2D* point) {
        points.add(point); 
        size++; 
    }

    Region::~Region() {}
}