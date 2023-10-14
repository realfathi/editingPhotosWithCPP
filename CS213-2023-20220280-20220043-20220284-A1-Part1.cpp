/*
                                            Assignment 1 - OOP
                                                   Part 2
Date: 13 October 2023
Purpose: Demonstrate use of bmplip for handling  / load a gray image and store in another file
Supervised by Dr.Mohammad El-Ramly

Authors:
Muhammad Ahmed Fathi   -   20220280  - mohamedfaathy3@gmail.com
Ahmed Mostafa Muhammad -   20220043  - 05.ahmedmustafa@gmail.com
Muhammad Gamal ALi     -   20220284  - mohamedgamal200420042004@gmail.com

Version: 1.0 (Demo)
15 Filters Black and White images....



*/

#include <bits/stdc++.h>
#include "bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char croppedImage[SIZE][SIZE];

char select ; // Global variable

void loadImage ();
void saveImage ();
void doSomethingForImage ();
void rotate_180 ();
void rotate_90 ();
void rotate_270();
void negative();
void black_white();
void flip();
void darken();
void lighten();
void mirror();
void enlarge();
void detect_edge();
void crop();
//_________________________________________

char menu(){
    char choice ;
    choice = '.' ;
    // this loop checks if your choice exists or not
    // if not choose again
    while (choice == '.'){
        cout << "Filter 1: Black and White Image\nFilter 2: Invert Image\n";
        cout << "Filter 3: Merge Images\nFilter 4: Flip Image\n";
        cout << "Filter 5: Rotate Image\nFilter 6: Darken and Lighten Image\n";
        cout << "Filter 7: Detect Image Edges\nFilter 8: Enlarge Image\n";
        cout << "Filter 9: Shrink Image\nFilter a: Mirror Image\n";
        cout << "Filter b: Shuffle Image\nFilter c: Blur Image\n";
        cout << "Filter d: Crop Image\nFilter e: Skew Horizontally Image\n";
        cout << "Filter f: Skew Vertically Image\n";
        cout << "s: Save the image to a file \n";
        cout << "0: Exit\n";
        cin >> choice ;
        if (!(choice >= '0' && choice <= '9' || choice >= 'a' && choice <= 'f' || choice == 's')){
            cout << "==============\nWrong Number, Please TRY Again !\n\n";
            choice = '.' ; // loop keep working
        }
    }

    return choice ;
}


//_________________________________________

void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);

}

//_________________________________________

void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "\nEnter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

//__________________________________________

void load_to_merge(){ // this function to add second image to merge
    char imageFileName2[100];

    // Get gray scale image file name
    cout << "Enter the source image2 file name:";
    cin >> imageFileName2;

    // Add to it .bmp extension and load image
    strcat (imageFileName2, ".bmp");
    readGSBMP(imageFileName2, image2);

}

//_________________________________________

void invert() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++)
            image[i][j] = 255 - image[i][j] ;
    }
    // getting the negative of the image by subtracting each pixel from 255
}

//____________________________________________

void rotate_90(){
    /*
    rotating the image 90 degrees clockwise by switching
    the rows with the columns and reversing the columns order
    */
    unsigned char tmp [SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++)
            tmp[i][j]=image[i][j];
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++){
            image[i][j] = tmp[255-j][i];
        }
    }
}

//____________________________________________

void rotate_180(){
    rotate_90();rotate_90();
}

//____________________________________________

void rotate_270(){
    rotate_90();rotate_90();rotate_90();
}

//_____________________________________________

void black_white(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (image[i][j] > 127)
                image[i][j] = 255 ;
            else
                image[i][j] = 0 ;
        }
    }
    /*decide if pixel is light or dark then make it black and white*/
}

//_____________________________________________

void flip(){

    int n4 = -1 ;
    // this loop checks if your choice exists or not
    // if not choose again
    while (n4 == -1 ){
        cout<<"1:vertically\n2:horizontally\n";
        cout<<"Enter a number to select horizontally or vertically: ";
        cin>>n4;

        if (n4==1){ // vertically
            /*swapping the values between the top and bottom rows*/
            for (int i = 0; i < SIZE/2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    int tmp = image[i][j];
                    image[i][j]=image[SIZE-i][j];
                    image[SIZE-i][j]=tmp;
                }
            }
        }
            /*swapping the values between the top and bottom column*/
        else if (n4==2){ // horizontally
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE/2; j++) {
                    int tmp = image[i][j];
                    image[i][j]=image[i][SIZE-j];
                    image[i][SIZE-j]=tmp;
                }
            }
        }
        else {
            cout << "========\n\nWrong Number, Please TRY Again  *_*\n\n";
            n4 = - 1 ; // loop keep working
        }
    }
}

//_____________________________________________

void darken(){
    // make the image darken by 50%
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] /= 2 ;
        }
    }
}

//_____________________________________________

void lighten(){
    // make the image lighten by 50%
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] <= 205)
                image[i][j] += 50;
        }
    }
}

//_____________________________________________

void merge(){
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            image[i][j] = (image[i][j] + image2[i][j]) / 2;
    // divide by 2 to make pixel between 0 & 255
}

//_____________________________________________

void rotate_image(){
    int n5 = -1 ;
    // this loop checks if your choice exists or not
    // if not choose again
    while (n5 == -1 ){
        cout << "1: 90º\n2: 180º\n3: 270º\n";
        cout << "Enter a number to select the angel:\n";
        cin >> n5;
        if (n5 == 1)
            rotate_90();
        else if (n5 == 2)
            rotate_180();
        else if (n5 == 3)
            rotate_270();
        else {
            cout << "\n========\n\nWrong Number, Please TRY Again  *_*\n\n";
            n5 = -1 ; // loop keep working
        }
    }
}

//_____________________________________________

void darken_lighten(){
    int n6 = -1 ;
    // this loop checks if your choice exists or not
    // if not choose again
    while (n6 == -1 ){
        cout << "1: Darken Image \n2: Lighten Image \n";
        cout << "Enter a number to select Darken or Lighten Image: ";
        int n6;
        cin >> n6;
        if (n6 == 1) {
            darken(); // this to make it darken
            return ;
        }
        else if (n6 == 2){
            lighten(); // this to make it lighten
            return ;
        }
        else{
            cout << "\n========\n\nWrong Number, Please TRY Again  *_*\n\n";
            n6 = -1 ; // loop keep working
        }
    }
}

//_____________________________________________

void shrink_image(){

    int n9 = -1 ; 
    while (n9 == -1){
        cout << "shrink the image dimensions to: \n";
        cout << "1: 1/2\n2: 1/3\n3: 1/4 \n";
        cout << "Enter a number to select dimension of shrink the image: ";
        cin >> n9 ;
        // to make image background is wihte 
        for(int i = 0 ; i < SIZE ; i++){
            for(int j = 0 ; j < SIZE ; j++){
                image2[i][j] = image[i][j] ;
                image[i][j] = 255 ;
            }
        }
      
        // first condition
        if (n9 == 1 ){
            for(int i = 0 ; i < SIZE /2; i++){
                for(int j = 0 ; j < SIZE /2 ; j++){
                    image[i][j] = image2[i*2][j*2] ;
                }
            }
            return ;
        }
          
        // second condition
        else if (n9 == 2 ){
            for(int i = 0 ; i < SIZE /3; i++){
                for(int j = 0 ; j < SIZE /3 ; j++){
                    image[i][j] = image2[i*3][j*3] ;
                }
            }
            return ;
        }
          
        // third condition
        else if (n9 == 3 ){
            for(int i = 0 ; i < SIZE /4; i++){
                for(int j = 0 ; j < SIZE /4 ; j++){
                    image[i][j] = image2[i*4][j*4] ;
                }
            }
            return ;
        }
        else{
            cout << "\n========\n\nWrong Number, Please TRY Again  *_*\n\n";
            n9 = -1 ; // loop keep working
        }
    }
    
}

//_____________________________________________

void enlarge(){
        int x=0;
        for (int i = SIZE/2; i < SIZE; i++) {
            int y=0;
            for (int j = SIZE/2; j<SIZE; j++){
                image2[x][y]=image[i][j];
                image2[x+1][y]=image[i][j];
                image2[x][y+1]=image[i][j];
                image2[x+1][y+1]=image[i][j];
                y+=2;
            }
            x+=2;
        }
}
//_____________________________________________
void mirror(){
    cout<<"1:Left 1/2\n2:Right 1/2\n3:Upper 1/2\n4:Lower 1/2.\n";
    cout<<"Enter a number to select the type of mirroring: ";
    int n10; cin>>n10;
    if (n10==1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][SIZE-j] = image[i][j];
            }
        }
    }
    else if (n10==2){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[i][SIZE-j];
            }
        }}
    else if(n10==3){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[SIZE -i][j] = image[i][j];
            }
        }
    }
    else if(n10==4){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[SIZE-i][j];
            }
        }
    }
    else 
        cout<<"\n========\n\nWrong Number, Please TRY Again  *_*\n\n";


}
//_____________________________________________
void detect_edge(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((abs(image[i][j]) - abs(image[i][j + 1])) >= 32 || (abs(image[i][j]) - abs(image[i + 1][j])) >= 30)
                image[i][j] = 0;
            else
                image[i][j] = 255;

        }
    }
}
//_____________________________________________
void crop() {
    cout<<"Enter x ,y ,width ,height:";
    int x, y, width, height;
    cin >> x >> y >> width >> height;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            croppedImage[i][j] = image[x + i][y + j];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = 255;
        }
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            image[i + x][y + j] = croppedImage[i][j];
        }
    }
}
//_____________________________________________
void doSomethingForImage() {

    char num;
    bool loaded = false ;
    while (true) {
        num = menu() ; // return what we choice from menu
        select = num ; 
        switch (select) {
            case '1':
                if (loaded == false)
                    loadImage();
                black_white();
                loaded = true ; 
                break;

            case '2':
                if (loaded == false)
                    loadImage();
                invert();
                loaded = true ;
                break;

            case '3':
                if (loaded == false)
                    loadImage();
                // This to add second image it .bmp extension and
                //load image to merge with first image
                load_to_merge();
                merge();
                loaded = true ;
                break;

            case '4':
                if (loaded == false)
                    loadImage();
                flip();
                loaded = true ;
                break;

            case '5':
                if (loaded == false)
                    loadImage();
                rotate_image();
                loaded = true ;
                break;

            case '6':
                if (loaded == false)
                    loadImage();
                darken_lighten(); // to make the image darken or lighten
                loaded = true ;
                break;
            case '7':
                if (loaded == false)
                    loadImage();
                detect_edge();
                loaded = true ;
                break;
            case '8':
// code block
                break;
            case '9':
                if (loaded == false)
                    loadImage ();
                shrink_image(); 
                loaded = true ;        
                break;
            case 'a':
                if (loaded == false)
                    loadImage();
                mirror();
                loaded = true ;
                break;
            case 'b':
// code block
                break;
            case 'c':
// code block
                break;
            case 'd':
                if (loaded == false)
                    loadImage();
                crop();
                loaded = true ;
                break;

            case 'e':
// code block
                break;
            case 'f':
// code block
                break;
            case 's':
                saveImage ();
                break;
            default : // close the program if you choice zero 
                return ;
        }
    }
}

//_____________________________________________


int main()
{
  doSomethingForImage();
  return 0;
}
