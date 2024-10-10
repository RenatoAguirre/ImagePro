/*
 Class ListOfRegion
*/
#include "region.hpp"
#include "noderegion.hpp"

#if !defined(IMAGE_LISTOFREGION_HPP)
#define IMAGE_LISTOFREGION_HPP

namespace image {
	class ListOfRegion{
	private:
		NodeRegion* head;
		NodeRegion* tail;
		int size;
	public:		
		ListOfRegion();
		void add(Region* _region);
		void remove(int _index);
		Region* get(int _index);
		int getSize();
		virtual ~ListOfRegion();
	};
}

#endif // IMAGE_LISTOFREGION_HPP