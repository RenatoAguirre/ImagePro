/*
 Class ListOfPoint2D
*/
#include "nodepoint2d.hpp"


#if !defined(IMAGE_LISTOFPOINT2D_HPP)
#define IMAGE_LISTOFPOINT2D_HPP
namespace image {
	class ListOfPoint2D;
	class ListOfPoint2D{
	private:
		NodePoint2D* head;
		NodePoint2D* tail;
		int size;
	public:		
		ListOfPoint2D();
		void add(Point2D* _point);
		void remove(int _index);
		Point2D* get(int _index);
		int getSize();
		virtual ~ListOfPoint2D(); 		
	};
}
#endif // IMAGE_LISTOFPOINT2D_HPP)
