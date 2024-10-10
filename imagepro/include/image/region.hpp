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
		void showRegion();
        virtual ~Region(); 		
	};
}
#endif // IMAGE_REGION_HPP