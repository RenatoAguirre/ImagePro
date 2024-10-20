/**
 * Class Image
 */
#include "string"
#include "listofregion.hpp"



#if !defined(IMAGE_IMAGE_HPP)
#define IMAGE_IMAGE_HPP

namespace image {
	class Image; 
	typedef unsigned char uchar;
	

	class Image{
	private:
		int th_value;
		uchar* data;
	public:
	  int width;
		int height;
		Image();
		Image(int w, int h);
		Image(int w, int h, uchar* _data);
		void threshold(); 
    	int getValue(int row, int col);
		void show();
		ListOfRegion getRegions();
    virtual ~Image(); 
		static Image* readImage(std::string &path);        
	};
}

#endif // IMAGE_IMAGE_HPP)