/*
 Class ListOfRegion
*/
#include <region.hpp>
#include <noderegion.hpp>


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
