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
void mergeimage ();
void darkenandlightenimage ();
void shrinkimage ();
void blurimage();

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

void mergeimage (){
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
                for(int g= 0 ;g<RGB;g++){
            image2[i][j][g] = image[i][j][g];}
        }
    }
    cout <<"Enter the file name of the second photo\n";
    loadImage();
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            for(int g = 0 ;g<RGB;g++){
            image[i][j][g] = (image2[i][j][g]+image[i][j][g])/2;}
        }
    }
}
void darkenandlightenimage (){
    char choose6;
    cout<<"Do you want to (d)arken or (l)ighten :";
    cin>>choose6;
    if(choose6=='d'){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++){
                for (int c=0;c<3;++c)
                    image[i][j][c] /=2;
            }
        }
    }
    else if(choose6=='l'){
        int num=0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++){
                for (int c=0;c<3;++c){
                    num=image[i][j][c]*2;
                    if (num>255)    num=255;
                    image[i][j][c]=num;
                }
            }
        }
    }
    else cout<<"ERROR INVALID CHOOSE";
}

void shrinkimage (){
    float choose9;
    cout<<"1-Shrink to (1/2)\n2-Shrink to (1/3) \n3-Shrink to (1/4) \nchoose :";
    cin>>choose9;
    if (choose9==1){
        for (int i = 0; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                for (int c=0 ; c<RGB ; c++){
                image[i/2][j/2][c]=image[i][j][c];
                }
            }
        }
        for (int i = 0; i < SIZE; i++){
            for (int j =SIZE/2 ; j <SIZE; j++){
                    for (int c=RGB/255 ; c<RGB ; c++){
                image[i][j][c]=255;
                    }
            }
        }
        for (int i = SIZE/2; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                    for(int c=RGB/255 ; c<RGB ; c++){
                image[i][j][c]=255;
                    }
            }
        }
    }
    if (choose9==2){
        for (int i = 0; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                for (int c=0 ; c<RGB ; c++){
                image[i/3][j/3][c]=image[i][j][c];
                }
            }
        }
        for (int i = 0; i < SIZE; i++){
            for (int j =SIZE/3 ; j <SIZE; j++){
                    for (int c=RGB/255 ; c<RGB ; c++){
                image[i][j][c]=255;
                    }
            }
        }
        for (int i = SIZE/3; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                    for(int c=RGB/255 ; c<RGB ; c++){
                image[i][j][c]=255;
                    }
            }
        }
    }
    if (choose9==3){
        for (int i = 0; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                for (int c=0 ; c<RGB ; c++){
                image[i/4][j/4][c]=image[i][j][c];
                }
            }
        }
        for (int i = 0; i < SIZE; i++){
            for (int j =SIZE/4 ; j <SIZE; j++){
                    for (int c=RGB/255 ; c<RGB ; c++){
                image[i][j][c]=255;
                    }
            }
        }
        for (int i = SIZE/4; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                    for(int c=RGB/255 ; c<RGB ; c++){
                image[i][j][c]=255;
                    }
            }
        }
    }
}

void blurimage()
{
    char choosec;
    for(int p = 0; p < 7; p++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j =0 ; j <SIZE; j++)
            {
                 for (int c =0 ; c <RGB; c++)
                 {
                     image[i][j][c]= (image[i+1][j][c]+ image[i-1][j][c]+ image[i][j+1][c]+ image[i][j-1][c]) /4; 
            }
        } 

    }
  }
}