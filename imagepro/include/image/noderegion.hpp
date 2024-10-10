/*
 Class NodeRegion
*/
#include "region.hpp"
#if !defined(IMAGE_NODEREGION_HPP)
#define IMAGE_NODEREGION_HPP
namespace image {
	class NodeRegion{
	private:		
		NodeRegion* next;
		NodeRegion* prev;
		Region* region;
	public:		
		NodeRegion(Region* _region);
		NodeRegion* getNext();
		NodeRegion* getPrev();
		Region* getRegion();
		void setNext(NodeRegion* _next);
		void setPrev(NodeRegion* _prev);
		virtual ~NodeRegion();
	};
}
#endif // IMAGE_NODEREGION_HPP
