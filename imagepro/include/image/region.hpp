/*
 Class Region
*/
#include "listofpoint2d.hpp"

#if !defined(IMAGE_REGION_HPP)
#define IMAGE_REGION_HPP

namespace image {
	class Region{
	private:
		int id;
		int size;
		ListOfPoint2D points;		
	public:
		Region();
		void showRegion(int imgWidth, int imgHeight);
        virtual ~Region(); 		
		void addPoint(Point2D* point);
	};
}
#endif // IMAGE_REGION_HPP