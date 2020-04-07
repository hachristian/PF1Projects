/*
 * project 3
 * Julio sibrian
 * Professor John Gauch
 * Fall 2019
 */

#include <iostream>
#include <fstream>
using namespace std;

int main (){
    
    // fstream dout command
    ofstream dout;
    // declare and initialize variables
    int col = 0;
    int row = 0;

    // ask the user for input
    cout << "Please enter the amount of columns you want. within (100-1000) ";
   
    cin >> col;
    // while loop making sure they use the right range

    while(col < 100 || col > 1000){
        cout << "Incorrect range!" << endl << "Please enter the amount of columns you want. within (100-1000) ";
        cin >> col;
    }


    // asking for rows
    cout << "Now enter how many rows. within (100-1000) ";
    cin >> row;
    // error checking 
      while(row < 100 || row > 1000){
        cout << "Incorrect range!" << endl << "Please enter the amount of rows you want. within (100-1000) ";
        cin >> row;
    }

        

        
    // making the country boolean values so my program does thing only when its told to
    bool countryanswer = false;
    string country;

    bool Belgium = false;
    bool Benin = false;
    bool Colombia = false;
    bool Denmark = false;
    bool Botswana = false;

    cout << "Please pick one of the following country's." << endl <<
            "Belgium, Benin, Colombia, Denmark, or Botswana. ";
    cin >> country;
    // picking which flag you want error checking making sure they choose a country supported.
    while(countryanswer != true){
        if(country == "Belgium" || country == "belgium"){
            Belgium = true;
            countryanswer = true;
        }
        else if(country == "Benin" || country == "benin"){
            Benin = true;
            countryanswer = true;
        }
        else if(country == "Colombia" || country == "colombia"){
            Colombia = true;
            countryanswer = true;
        }
        else if(country == "Denmark" || country == "denmark"){
            Denmark = true;
            countryanswer = true;
        }
        else if(country == "Botswana" || country == "botswana"){
            Botswana = true;
            countryanswer = true;
        }
        else {
            cout << "Please enter a supported country! ";
            cin >> country;
            countryanswer = false;
        }
    }
    // for loops for the rows and columns

    // make Belgium flag with for loops and if statements and outputting to file
    if(Belgium == true){
    dout.open("Belgium.ppm");
    
    dout << "P3" << endl;
    dout << col << " " << row << endl;
    dout <<"255" << endl;

    for(int x = 0; x < row; x++){
            for(int y = 0; y < col; y++){
                if(y < col /3){
                    dout << "0 0 0 ";
                }
                else if(y < 2 * col / 3){
                    dout << "255 179 0 ";
                }
                else{
                    dout << "255 26 0 ";
                }
           
            }
            cout << endl;
            
 
        }
   dout.close();
    }
    // make Benin flag with for loops and if statements  and outputting to file 
    
     if(Benin == true){
         dout.open("Benin.ppm");
         
         dout << "P3" << endl;
         dout << col << " " << row << endl;
         dout <<"255" << endl;

         for(int x = 0; x < row; x++){
             for(int y = 0; y < col; y++){
                 if( y < 3 * col / 8){
                     dout << "0 135 41 ";
                 }
                     else if ( x < row / 2){
                         dout << "255 179 0 ";
                     }
                     else {
                             dout << "255 26 0 ";
                         }          
                 }
                 
             cout << endl;
         }
         dout.close();
         }
     
    // make Colombia flag with loops and outputting to a file
    if(Colombia == true){
        dout.open("Colombia.ppm");
        
         dout << "P3" << endl;
         dout << col << " " << row << endl;
         dout <<"255" << endl;
         
        for(int x = 0; x < row; x++){
           
            for(int y = 0; y < col; y++){
              if(x < 9 * row / 20){
                dout << "255 179 0 ";
            }
            else if( x < 3 * row / 4){
                dout << "0 0 255 ";
            }
            else{
                dout << "255 6 0 ";
            }  
            }
            cout << endl;
            
        }
         dout.close();
     }
    // make Denmark flag and then outputting the results to a file
    if(Denmark == true){
        dout.open("Denmark.ppm");
        
         dout << "P3" << endl;
         dout << col << " " << row << endl;
         dout <<"255" << endl;
         
         for(int x = 0; x < row; x++){
            for(int y = 0; y < col; y++){
                if(y < 2 * col / 6 && x < 6 * row / 14){
                dout << "223 0 0 ";
                }
                else if(y > 4* col / 10 && x < 6 * row / 14){
                    dout << "223 0 0 ";
                }
                else if(y < 2 * col / 6 && x > 7 * row / 14){
                    dout << "233 0 0 ";
                }
                else if(y > 4 * col / 10 && x > 7 * row / 14){
                    dout << "233 0 0 ";
                }
                else{
                    dout << "255 255 255 ";
                }
            }
            cout << endl;
        }
         
        
         dout.close();
    }
    // makeing Botswana flag and outputting it to a file
    if(Botswana == true){
        dout.open("Botswana.ppm");
        
         dout << "P3" << endl;
         dout << col << " " << row << endl;
         dout <<"255" << endl;
         
        for(int x = 0; x < row; x++){
            for(int y = 0; y < col; y++){
                
                if( x < 2* row / 8){
                    
                    dout << "120 184 201 ";
                }
                else if ( x < 3 * row / 10){
                    dout << "255 255 255 ";
                }
                else if (x < 5 * row / 8){
                    dout << "0 0 0 ";
                }
                else if ( x < 6 * row / 9 ){
                    dout << " 255 255 255 ";
                }
                else {
                    dout << "120 184 201 ";
                }
              }
            
            
            }
            dout << endl;
        }
     



    system("pause");
   return 0;

}




