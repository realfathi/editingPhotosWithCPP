/*
                                            Assignment 1 - OOP
                                                   Part 2 - (FULL)
Date: 18 October 2023
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
// =================================
void rotate_180 ();
void rotate_90 ();
void rotate_270();
void invert();
void black_white();
void flip();
void darken();
void lighten();
void mirror();
void enlarge();
void detect_edge();
void crop();
// =========================================================================

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
        if (!((choice >= '0' && choice <= '9') || (choice >= 'a' && choice <= 'f' ) || choice == 's')){
            cout << "==============\nWrong Number, Please TRY Again !\n\n";
            choice = '.' ; // loop keep working
        }
    }

    return choice ;
}


// =========================================================================

void loadImage () {
    char imageFileName[100];

    // Get grayscale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);

}

// =========================================================================

void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "\nEnter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

// =========================================================================

void load_to_merge(){ // this function to add second image to merge
    char imageFileName2[100];

    // Get gray scale image file name
    cout << "Enter the source image2 file name: ";
    cin >> imageFileName2;

    // Add to it .bmp extension and load image
    strcat (imageFileName2, ".bmp");
    readGSBMP(imageFileName2, image2);

}

// =========================================================================

void invert() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++)
                image[i][j] = 255 - image[i][j] ;
    }
    // getting the negative of the image by subtracting each pixel from 255

}

// =========================================================================

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

// =========================================================================

void rotate_180(){
    rotate_90();rotate_90();
}

// =========================================================================

void rotate_270(){
    rotate_90();rotate_90();rotate_90();
}

// =========================================================================

void black_white(){

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (image[i][j] > 127)
                image[i][j] = 255 ;
            else
                image[i][j] = 0 ;
        }
    }   /*decide if pixel is light or dark then make it black and white*/

}

// =========================================================================

void flip(){

    int n4 = -1 ;
    //This loop checks whether your choice exists or not 
    //If not choose again
    while (n4 == -1 ){
        cout<<"1:vertically\n2:horizontally\n";
        cout<<"Enter a number to select horizontally or vertically: ";
        cin>>n4;
        if (n4==1){ // vertically
            for (int i = 0; i < SIZE/2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    int tmp = image[i][j];
                    image[i][j] = image[SIZE-i][j];
                    image[SIZE-i][j] = tmp;
                }
            }
        }
        else if (n4==2){ // horizontally
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE/2; j++) {
                    int tmp = image[i][j];
                    image[i][j] = image[i][SIZE-j];
                    image[i][SIZE-j] = tmp;
                }
            }
        }
        else {
            cout << "========\n\nWrong Number, Please TRY Again  *_*\n\n";
            n4 = - 1 ; // loop keep working
        }
    }

}


// =========================================================================

void darken(){

    // make the image darken by 50% 
    // by division value of pixel by 2 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] /= 2 ;
        }
    }
    
}

// =========================================================================

void lighten(){

    // make the image lighten by 50%
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
                if (image[i][j] <= 205)
                    image[i][j] += 50;
                else 
                    image[i][j] = 255 ;   
        }
    }

}

// =========================================================================

void merge(){

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
                image[i][j] = ( image[i][j] + image2[i][j] ) / 2;
    // divide by 2 to make pixel between 0 & 255

}

// =========================================================================
void enlarge(){
        cout<<"Pick a quarter to enlarge: "; 
  /*initially i and j equal zero and loop ends at 128*/
        int x=0, a=0, b=0, ni=128, nj=128, q;
        cin>>q;
  /*if the input is even then j starts from 128 if odd it starts from 0  */ 
        if(!(q&1)) b=128,nj=SIZE;
        if(q>2 and q<5) a=128,ni=SIZE;
        while(4<q or q<1){
            cout<<"Wrong number!\nEnter a number between 1 and 4: ";
            cin>>q;
        }
/*enlarging a quarter of the image by repeating each pixel 4 times in the new image*/
        for (int i=a; i < ni; i++) {
            int y=0;
            for (int j=b; j<nj; j++){
                image2[x][y]=image[i][j];
                image2[x+1][y]=image[i][j];
                image2[x][y+1]=image[i][j];
                image2[x+1][y+1]=image[i][j];
                y+=2;
            }
            x+=2;
        }
      for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            image[i][j] = image2[i][j];
    }
}
// =========================================================================
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

// =========================================================================

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

// =========================================================================

void blur(){
    int blurImage[SIZE][SIZE] ; // Create a temporary array to store blurred image data

    // Iterate through each pixel in the image
    for (int i = 0 ; i < SIZE ; i++ ){
        for (int j = 0 ; j < SIZE ; j++ ){
            int sum = 0 ;
            int count = 0 ;


            // this array to move to neighboring pixel
            //          { r , l , d , u , dr , dl , ur , ul } -> l = left ,u = up , d = down , r = right
            int di[8] = { 0 , 0 , 1 , -1 , 1 , 1 , -1 , -1  } ;
            int dj[8] = { 1 , -1 , 0 , 0 , 1 , -1 , 1 , -1  } ;

            // Iterate through 8 neighboring pixels
            for (int d = 0 ; d < 8 ; d++) {
                int ni  = i - di[d] , nj = j -dj[d] ;

                // Check if the neighboring pixel is within the image boundaries
                if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE) {
                    sum += image[ni][nj]; // Add neighboring pixel value to sum
                    count++; // Increment count
                }
            }

                // Calculate average value and store it in the blur array
                blurImage[i][j] = sum / count ;
        }
    }

    // Copy the blurred image data back to the original array
    for (int i = 0 ; i < SIZE ; i++ ){
        for (int j = 0 ; j < SIZE ; j++ ){
                image[i][j] = blurImage[i][j] ;
        }
    }

}


void blur_image(){
    blur();
    blur();
    blur();
    blur();
    blur();
    blur();
}

// =========================================================================

void shrink_image(){
    int shrink[SIZE][SIZE] 
    ; // Create a shrink array to store blurred image data

    int n9 = -1 ; 
    while (n9 == -1){
        cout << "shrink the image dimensions to: \n";
        cout << "1: 1/2\n2: 1/3\n3: 1/4 \n";
        cout << "Enter a number to select dimension of shrink the image: ";
        cin >> n9 ;
      
        // to make image background is white 
        for(int i = 0 ; i < SIZE ; i++){
            for(int j = 0 ; j < SIZE ; j++){
                    shrink[i][j] = image[i][j] ;
                    image[i][j] = 255 ;
            }
        }

        // Iterate through by half size to shrink by half
        if (n9 == 1 ){
            for(int i = 0 ; i < SIZE /2; i++){
                for(int j = 0 ; j < SIZE /2 ; j++){
                        image[i][j] = shrink[i*2][j*2];
                }
            }
            return ;
        }

        // Iterate through by a third of size to shrink by half
        else if (n9 == 2 ){
            for(int i = 0 ; i < SIZE /3; i++){
                for(int j = 0 ; j < SIZE /3 ; j++){
                        image[i][j] = shrink[i*3][j*3] ;
                }
            }
            return ;
        }

    
        // Iterate through by quarter of size to shrink by half    
        else if (n9 == 3 ){
            for(int i = 0 ; i < SIZE /4; i++){
                for(int j = 0 ; j < SIZE /4 ; j++){
                        image[i][j] = shrink[i*4][j*4] ;
                }
            }
            return ;
        }
        else{
            cout << "\n========\n\nWrong Number, Please TRY Again  *_*\n\n";
            n9 = -1 ; // loop keep working if selection is wrong 
        }
    }
    
}

// =========================================================================

void mirror(){

    cout<<"1:Left 1/2\n2:Right 1/2\n3:Upper 1/2\n4:Lower 1/2.\n";
    cout<<"Enter a number to select the type of mirroring: ";
    int n10; 
    cin >> n10;
    if (n10==1){
        //write the first col. to last col
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                    image[i][SIZE-j] = image[i][j];
            }
        }
    }

    else if (n10==2){
        //write the last col. to first col.
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                    image[i][j] = image[i][SIZE-j];
            }
        }
    }

    else if(n10==3){
        //write the upper(first) row to the last row
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                    image[SIZE -i][j] = image[i][j];
            }
        } 
    }

    else if(n10==4){
        //write the last row to the first row
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                    image[i][j] = image[SIZE-i][j];
            }
        }
    }

    else{
        cout<<"\n========\n\nWrong Number, Please TRY Again  *_*\n\n";
        mirror(); // function keep working if selection is wrong 
    }

}

// =========================================================================

void detect_edge() {

    black_white();
    unsigned char temp[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            temp[i][j]=255;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
                int v= image[i][j];
                if ((v^image[i][j + 1]) or (v^image[i + 1][j]))
                    temp[i][j] = 0;
                if((v^image[i][j - 1]) or (v^image[i - 1][j]))
                    temp[i][j]=0;
        }   
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            image[i][j]=temp[i][j];
        }
    }

}



// =========================================================================

void shuffle(){
    cout<<"Enter the order in numbers:\n";
    int o[4] , freq[5]={0};

    for(int i = 0; i < 4 ; i++){
        cin >> o[i];
        if(o[i] > 4 || o[i] < 1)//checking if the order is valid or not
            o[i] = -1 ;
        else if( freq[o[i]] )//checking if the number is repeated
            o[i] = 0 ;
        else 
            freq[o[i]]++;//counting the appearances of each number
    }

    string q[] = {"first", "second", "third", "fourth"};

    for(int i = 0; i < 4; i++){
      //correcting the invalid numbers
        while(o[i] == -1 || !o[i] ){
            int x;
            if(o[i])
                cout << q[i] << " number is wrong!\nEnter a number between 1 and 4: ";
            else 
                cout << q[i] << " number is repeated!\nEnter a number between 1 and 4: ";
            cin >> x;
            o[i] = x ;
            if(o[i] > 4 || o[i] < 1)
                o[i]=-1;
            else if(freq[o[i]])
                o[i] = 0 ;
            else 
                freq[o[i]]++;
        }
    }

    for(int k=0; k<4; ++k){
        if(o[k] == 1){
            int x = 128 , y ;
            if(k< 2)
                x=0;
            for (int i = 0; i < SIZE/2; i++){
                y=0;
                if(k&1)
                    y=128;
                for (int j =0; j<SIZE/2; j++){
                    image2[x][y] = image[i][j];
                    y++;
                }
                x++;
            }
        }
        else if(o[k]==2){
            int x = 128 , y ;
            if(k<2)
                x=0;
            for (int i = 0; i < SIZE/2; i++) {
                y=0;
                if(k&1)
                    y=128;
                for (int j = SIZE/2; j<SIZE; j++){
                    image2[x][y] = image[i][j];
                    y++;
                }
                x++;
            }
        }
        else if(o[k] == 3){
            int x = 128 , y ;
            if(k<2)
                x=0;
            for (int i = SIZE/2; i < SIZE; i++) {
                y=0;
                if(k&1)
                    y=128;
                for (int j = 0; j<SIZE/2; j++){
                    image2[x][y] = image[i][j];
                    y++;
                }
                x++;
            }
        }
        else if(o[k] == 4){
            int x = 128 , y ;
            if(k<2)
                x=0;
            for (int i = SIZE/2; i < SIZE; i++) {
                y=0;
                if(k&1)
                    y=128;
                for (int j = SIZE/2 ; j<SIZE; j++){
                    image2[x][y] = image[i][j];
                    y++;
                }
                x++;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            image[i][j] = image2[i][j];
    }
//I apologize for the complexity of this code.
}

// =========================================================================

void shrink_h(float d){

    float step = SIZE/d;//number of pixels to skip to get the shrunk image

    for(int i=0; i<SIZE; i++){
        float y=0;
        for(int j=0; j<d; j++){
            y+=step;
            image2[i][j]=image[i][int(y)];
        }
    }

}

int cnt=0;
void skew_h(){
    int b;
    if(!cnt)cout<<"Enter your angle: ";
    cin>>b;
    if(b<0 or b>90){
        cout<<"Wrong number!\nEnter an angle between 0 and 90: ";
        cnt++;
        skew_h();
    }
    else {
    cnt=0;
    double a = tan((M_PI/180)*(90-b));
    float x = floor(256/ (1 + 1/a));//calculating the base of the new image
    shrink_h(x);

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++)image[i][j]=255;//whitening the image
    }

    double step = SIZE - x; double move = step/SIZE;

    for(int i=0; i<SIZE; i++){
        int ct = step + x, y=0;
        for(int j=step; j<ct; ++j){
            image[i][j]=image2[i][y];
            y++;
        }
        step-=move;
    }
    }

}
// =========================================================================

void shrink_v(float d){

    float step = SIZE/d ;//number of pixels to skip to get the shrunk image
    float y = 0 ;

    for(int i=0; i<d; i++){
        y += step ;
        for(int j=0; j<SIZE; j++){
            image2[i][j] = image[int(y)][j] ;
        }
    }

}

void skew_v(){

    int b;
    if(!cnt)
        cout<<"Enter your angle: ";
    cin >> b;
    if(b < 0 or b > 90){
        cout<<"Wrong number!\nEnter an angle between 0 and 90: ";
        cnt++;
        skew_v();
    }
    else {
        cnt=0;
        double a = tan((M_PI/180)*(90-b));
        float x = floor(256/ (1 + 1/a));//calculating the base of the new image
        shrink_v(x);

        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++)image[i][j]=255;//whitening the image
    }

        double step = SIZE - x; double move = step/SIZE;

        for(int i=0; i<SIZE; i++){
            int ct = step + x, y=0;
            for(int j=step; j<ct; ++j){
                image[j][i]=image2[y][i];
                y++;
            }
            step -= move;
        }
    }

}

// =========================================================================

void crop() {

    cout << "Enter x ,y ,width ,height:";
    int x, y, width, height;
        int na = -1 ;
        //This loop checks whether your choice exists or not
        //If not choose again
        while (na == -1 ){
            cin >> x >> y >> width >> height;
            if (x < 0 || y < 0 || width <= 0 || height <= 0 || x + width > SIZE || y + height > SIZE) {
                cout<< "Invalid coordinates or dimensions! Try not crop more than the actual size of the image, Please TRY Again  *_*\n\n";
            na=-1;
            }else{na=10;
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j <SIZE; j++) { // fill a temp. image the cropped photo
                        croppedImage[i][j] = image[i][j];
                    }
                }

                // make original the image white
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image[i][j] = 255;
                    }
                }

                // paste the temp. to our white image
                    for (int j = y; j < y + height; j++) {
                        for (int i = x; i < x + width; i++) {
                        image[j][i] = croppedImage[j][i];
                    }
                }
            }


    }

}

// =========================================================================

void doSomethingForImage() {

    char num;
    bool loaded = false ;
    while (true) {
        num = menu() ; // return what we chose from menu
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
                if (loaded == false)
                    loadImage ();
                 enlarge();
                loaded = true ;
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
                if (loaded == false)
                    loadImage();
                shuffle();
                loaded = true ;
                break;

            case 'c':
                if (loaded == false)
                    loadImage ();
                blur_image();
                loaded = true ;
                break;

            case 'd':
                if (loaded == false)
                    loadImage();
                crop();
                loaded = true ;
                break;

            case 'e':
                if (loaded == false)
                    loadImage();
                skew_h();
                loaded = true ;
                break;

            case 'f':
                if (loaded == false)
                    loadImage();
                skew_v();
                loaded = true ;
                break;

            case 's':
                saveImage ();
                loaded = false ; /* this if you save the photo,
                                you are able to load a new photo again if you select filter */
                break;

            default : // close the program if you choose zero
                return ;
        }
    }
}

// =========================================================================

int main()
{
    doSomethingForImage();
    return 0;
}
