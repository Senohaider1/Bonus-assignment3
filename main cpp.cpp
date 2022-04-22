#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];

void loadImage ();
void saveImage ();
void blackandwhite ();

int main()
{
    char choose;
    cout<<"Ahalan ya user ya habibi\n";
    loadImage ();
    while(true){
    cout<<"Please select a filter to apply or 0 to exit:\n\n";
    cout<<"1-Black and White Filter\n2-Invert Filter\n3-Merge Filter\n4-Flip Filter\n5-Rotate Image";
    cout<<"\n6-Darken and Lighten Image\n7-Detect Image Edges\n8-Enlarge Image";
    cout<<"\n9-Shrink Image\ns-Save the image to a file\n0-EXIT\nchoose :";
    cin>>choose;
    switch(choose){
        case '1':
            blackandwhite();
            break;
        case '2':
            invertimage ();
            break;
        case '3':
            mergeimage ();
            break;
        case '4':
            flipimage();
            break;
        case '5':
            rotateimage ();
            break;
        case '6':
            darkenandlightenimage ();
            break;
        case '7':
            detectimageedges ();
            break;
        case '8':
            enlargeimage ();
            break;
        case '9':
            shrinkimage() ;
            break;
        case 's':
            saveImage();
            break;
        case '0':
            return 0;
    }
    cout<<endl<<"photo saved successfully"<<endl;
    }
    return 0;
}

//_______________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
}

//_______________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}

//_______________
void blackandwhite() {
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            for (int k = 0; k< RGB; k++){
            if (image[i][j][(RGB/3)-k]<=127.5)
                image[i][j][RGB-k]=0;
            else
               image[i][j][RGB-k]=255;
            }
        }
    }
}
