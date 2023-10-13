/*
                                            Assignment 1 - OOP
                                                   Part 1
Date: 6 October 2023
Purpose: Demonstrate use of bmplip for handling  / load a gray image and store in another file
Supervised by Dr.Mohammad El-Ramly

Authors:
Muhammad Ahmed Fathi   -   20220280  - mohamedfaathy3@gmail.com
Ahmed Mostafa Muhammad -   20220043  - 05.ahmedmustafa@gmail.com
Muhammad Gamal ALi     -   20220284  - mohamedgamal200420042004@gmail.com

Version: 1.0 (Demo)
6 Filters Only....



*/

#include <bits/stdc++.h>
#include "bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];

string select ; // Global variable

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

//_________________________________________

string menu(){
    string choice ;
    choice = "." ;
    // this loop checks if your choice exists or not
    // if not choose again
    while (choice == "."){
        cout << "Filter 1: Black and White Image\nFilter 2: Invert Image\n";
        cout << "Filter 3: Merge Images\nFilter 4: Flip Image\n";
        cout << "Filter 5: Rotate Image\nFilter 6: Darken and Lighten Image\n";
        cout << "s: Save the image to a file \n";
        cout << "0: Exit\n";
        cin >> choice ;
        if (!(choice >= "0" && choice <= "6" || choice =="s")){
            cout << "==============\nWrong Number, Please TRY Again !\n\n";
            choice = "." ; // loop keep working
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
            cout << "========\n\nWrong Number, Please TRY Again  *_*\n\n";
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
            cout << "========\n\nWrong Number, Please TRY Again  *_*\n\n";
            n6 = -1 ; // loop keep working
        }
    }
}

//_____________________________________________

void shrink_image(){
    for(int i = 0 ; i < SIZE ; i++)
        for(int j = 0 ; j < SIZE ; j++){
            image[i][j] = 255 ;
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
        cout<<"========\n\nWrong Number, Please TRY Again  *_*\n\n";


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
void doSomethingForImage() {

    while (true) {
        string num = menu() ; // return what we choice from menu
        select = num ;
        if (select == "1"){
            loadImage();
            black_white();
        }
        else if (select == "2"){
            loadImage();
            invert();
        }
        else if (select == "3"){
            loadImage();
            // This to add second image it .bmp extension and
            //load image to merge with first image
            load_to_merge();
            merge();
        }
        else if (select == "4"){
            loadImage();
            flip();
        }
        else if (select == "5"){
            loadImage();
            rotate_image();
        }
        else if (select == "6"){
            loadImage();
            darken_lighten(); // to make the image darken or lighten
        }
        else if (select == "7"){
            loadImage();
            detect_edge();
        }
//         else if (select == "8"){
// // code block
//         }
        else if (select == "9"){
            shrink_image();
        }
        else if (select == "10"){
            loadImage();
            mirror();
        }
//         else if (select == "11"){
// // code block
//         }
//         else if (select == "12"){
// // code block
//         }
//         else if (select == "13"){
// // code block
//         }
//         else if (select == "14"){
// // code block
//         }
//         else if (select == "15"){
// // code block
//         }
        else if (select == "s"){
            saveImage ();
        }
        else    
            return ;
        
    }

}






//_____________________________________________


int main()
{
    while (true ){
        doSomethingForImage();
        if (select == "0")
            return 0;
    }
}
