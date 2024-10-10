
#include "image/image.hpp"
#include <iostream>
#include <string>
#include <cassert>
#include "image/listofregion.hpp"
#include "image/region.hpp"
#include <stack>




int main(int nargs, char** vargs) {
    std::string filename("../images/image_2.bmp"); // Cambia la ruta según sea necesario
    std::cout << "Cargando imagen desde: " << filename << std::endl;
    
    image::Image* im = image::Image::readImage(filename); // Cargar la imagen
    im->show(); // Mostrar la imagen (según tu implementación)
    
    // Obtener las regiones
    image::ListOfRegion regions = im->getRegions(); 

    // Mostrar el número total de regiones
    std::cout << "La imagen tiene " << regions.getSize() << " regiones" << std::endl;

    // Mostrar detalles de cada región
    for (int i = 0; i < regions.getSize(); ++i) {
        image::Region* region = regions.get(i); // Obtener la región i-ésima
        if (region != nullptr) {
            region->showRegion(); // Mostrar información de la región
        } else {
            std::cerr << "Error: no se pudo obtener la región " << i << std::endl;
        }
    }

    delete im; // Liberar memoria de la imagen
    return 0;
}