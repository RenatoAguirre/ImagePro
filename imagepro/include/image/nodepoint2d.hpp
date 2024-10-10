/*
 Class NodePoint2D
*/
#include "point2D.hpp"


#if !defined(IMAGE_NODEPOINT2D_HPP)
#define IMAGE_NODEPOINT2D_HPP


namespace image {
	class NodePoint2D{
	private:
		Point2D* point;
		NodePoint2D* next;
	public:		
		NodePoint2D();
		NodePoint2D(Point2D* _point);
		void setNext(NodePoint2D* _next);
		NodePoint2D* getNext();
		Point2D* getPoint();
		virtual ~NodePoint2D(); 		
	};
}

#endif // IMAGE_NODEPOINT2D_HPP)
