#include "image/image.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>
#include <stack>
#include "image/listofregion.hpp"
#include "image/region.hpp"
#include "image/point2D.hpp"


namespace image{

    Image::Image(): width(0), height(0), th_value(120), data(nullptr){

    }

    Image::Image(int w, int h): width(w), height(h), th_value(120),  data(nullptr){

    }

    Image::Image(int w, int h, uchar* _data): width(w), height(h), th_value(100), data(_data){
       threshold();
    }

    void Image::threshold(){
        if (data != nullptr) {
            for(int i = 0; i < height*width; i++){            
                if (static_cast<int>(data[i]) < th_value){
                    data[i] = static_cast<char>(0);
                }
                else{
                    data[i] = static_cast<char>(1);                    
                }
            }
        }
    }
    int Image::getValue(int row, int col){
        int pos = row*width + col;
        return static_cast<int>(data[pos]);
    }

    void Image::show(){
        std::cout << "----------------------" << std::endl;
        std::cout << "size [ (w: " << width << ") x   ( h:" << height << ")]" <<  std::endl;        
        std::cout << "---------------------" << std::endl;
        for(int i = 0 ; i < height ; i++ ){
            for(int j = 0; j < width; j++ ){
                //std::cout<< getValue(i,j) << " "; 
                if (getValue(i,j) == 0) {
                    std::cout<<" ";
                }
                else{
                    std::cout<<"*";
                }
            }
            std::cout<<std::endl;
        }
    }

    Image::~Image(){

    }

    Image* Image::readImage(std::string &path){

        Image* im = nullptr;
        std::ifstream fin(path, std::ios::binary);
        char info[54];
        // read the 54-byte header
        fin.read(info, 54);
        // extract image height and width from header
        int width = *(int*)&info[18];
        int height = *(int*)&info[22];
        short int planes = *(short int*)&info[26];
        short int bits = *(short int*)&info[28];
        int imagesize = *(int*)&info[34];
        int numcolors = *(int*)&info[46];
        assert(info[0]=='B' && info[1] =='M');
        assert(bits == 8);
        // std::cout<< "planes " << planes << std::endl;
        // std::cout<< "bits " << bits << std::endl;
        // std::cout<< "imagesize " << imagesize << std::endl;
        // std::cout<< "numcolors " << numcolors << std::endl;
        // std::cout<< info[0] << info[1] << std::endl;
        //reading colortable
        char  colors[numcolors*4];
        fin.read(colors, numcolors*4);        
        if (imagesize == height * width) {            
            char* data = new char[imagesize];
            //read the pixel values
            fin.read(data, imagesize); 
            fin.close();
            char* ordered_data = new char[imagesize];
            //copy data in in a proper order            
            std::cout<< "----------------" <<std::endl;
            for(int i = 0; i < height ; i++){
                std::memcpy(ordered_data + width*i, data + width*(height - 1 - i ), width);
            }                    
            delete[]  data;            
            im = new Image(width, height, reinterpret_cast<uchar*>(ordered_data));        
        }
        assert(im != nullptr);
        return im;
    }

    ListOfRegion Image::getRegions() {
		ListOfRegion regions;
		int regionId = 0;
		std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

		for (int row = 0; row < height; ++row) {
			for (int col = 0; col < width; ++col) {
				if (getValue(row, col) == 1 && !visited[row][col]) {
					regionId++;
					int size = 0;
					Region* newRegion = new Region(); // Creamos una nueva región

					// DFS stack
					std::stack<Point2D*> stack;
					stack.push(new Point2D(col, row)); // Punto inicial

					while (!stack.empty()) {
						Point2D* point = stack.top();
						stack.pop();

						int x = point->getX();
						int y = point->getY();

						if (visited[y][x]) {
							delete point; // Liberamos la memoria
							continue;
						}

						visited[y][x] = true;
						size++;

						// Añadimos el punto a la región
						newRegion->addPoint(new Point2D(x, y));

						// Explorar píxeles vecinos (4 conectividades)
						for (int dx = -1; dx <= 1; dx++) {
							for (int dy = -1; dy <= 1; dy++) {
								if ((dx == 0) != (dy == 0) && (dx == 0 || dy == 0)) { // Asegúrate de no visitar la misma celda
									int newX = x + dx;
									int newY = y + dy;
									
									// Verificar límites y si el nuevo píxel es parte de la región
									if (newX >= 0 && newX < width && newY >= 0 && newY < height && getValue(newY, newX) == 1 && !visited[newY][newX]) {
										stack.push(new Point2D(newX, newY));
									}
								}
							}
						}

						delete point; // Liberamos memoria del punto actual
					}

					// Una vez completada la región, la agregamos a la lista
					regions.add(newRegion);
				}
			}
		}
		return regions; // Devolver todas las regiones encontradas
	}

}

