/*
 Class NodePoint2D
*/

#include <point2D.hpp>


namespace image {
	class NodePoint2D{
	private:
		int index;
		Point2D* point;
		NodePoint2D* next;
	public:		
		NodePoint2D();
		NodePoint2D(int _index, Point2D* _point);
		void setNext(NodePoint2D* _next);
		NodePoint2D* getNext();
		Point2D* getPoint();
		int getIndex();
		virtual ~NodePoint2D(); 		
	};
}
