/*
 Class NodeRegion
*/
#include <region.hpp>
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
