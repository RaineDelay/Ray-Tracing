#include <iostream>
#include <fstream>
using namespace std;

int main(){

    int img_width = 256;
    int img_height = 256;
    
    fstream image ("image.ppm");
    if(image.is_open()){
        image << "P3\n" << img_width << " " << img_height << "\n255\n";
        // Main render loop
        for(int j = 0; j < img_height; j++){
            for(int i = 0; i < img_width; i++){
                auto r = double(i) / (img_width - 1);
                auto g = double(j) / (img_height - 1);
                auto b = 0.0;

                int ir = int(255.999 * r);
                int ig = int(255.999 * g);
                int ib = 0;

                image << ir << " " << ig << " " << ib << "\n";
            }
        }
    }
    else cout << "Image not opened" << endl;
}