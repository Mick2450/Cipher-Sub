#include <stdio.h>

int main(void){
    char c, eN; //c is character from message & eN is is the encrypted character
    int eLibU[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90}; //library of encryption values from A to Z
    int asc[1024]; //ascii array
    int i = 0, e = 0, count = 0, j = 0;
    int freq[1024];
    int array[1024];
    int max = 0,  maxLoc;
      
    /*Open message file and output file*/
    FILE *input, *output;        //File points to input and output
    input = fopen("input.txt", "r");   //open file name and read format
    output = fopen("output.txt", "w");
    
    if(input == NULL) {         //Error message incase input file directory not found
        perror("fopen()");
    return 0;
    }
    if(output == NULL) {         //Error message incase output file directory not found
        perror("fopen()");
    return 0;
    }
    
   
        
     /*while loop scans input file for characters, prints them to terminal, 
     encrypts them with key value, writes this to an output, and loops until no characters are left in the input file*/   
     while(!feof(input)){ //loops until no characters are left in the input file
        fscanf(input,"%c", &c); //Scans file for characters and stores them as a variable c
         i++; //increments array pointer with every loop and assigns the input read ascii value to it, i.e. asc[0] = "first input character read from file"
       
       if(c >= 65 && c <= 90){  //if upper case
            
            asc[i] = c;     //assigns array at array point i with value c
            c = c - 65;     //A = 0
            e = c; //encryption algorithm 
            if(e >= 26){     //if array pointer value is exceeded
                e = e - 26;    //starts array pointers over again plus difference between total value (>26) and max pointer value (26)    
              }
             eN = eLibU[e]; //selects encrypted value from upper case array
             array[i] = eN;
             freq[i] = -1;
        }  
        
        else if(c >= 97 && c <= 122){  //if lower case 
            
            asc[i] = c;     //assigns array at array point i with value c
            c = c - 32;     //a = 0
            e = c -65; //encryption algorithm 
            if(e >= 26){     //if array pointer value is exceeded
                e = e - 26;    //starts array pointers over again plus difference between total value (>26) and max pointer value (26)    
              }
             eN = eLibU[e]; //selects ascii value from upper case array
             array[i] = eN; //stores selected ascii value in an array
             freq[i] = -1;  //Initialise frequency to -1
        }   

        /*The following 3 'else if' statements leave common punctuation unmodified*/
        else if(c == 46){ //if full stop
            asc[i] = 46;  //sets ASCII value full stop
            eN = 46;  //sets ASCII value to full stop
        }
        
         else if(c == 44){ //if comma
            asc[i] = 44;  //sets ASCII value to comma
            eN = 44;  //sets ASCII value to comma
        }
        
        else if(c == 39){ //if apostrophe 
            asc[i] = 39;  //sets ASCII value to apostrophe
            eN = 39;  //sets ASCII value to apostrophe
        }  
          else if(c == 58){ //if colon
            asc[i] = 58;  //sets ASCII value to colon
            eN = 58;  //sets ASCII value to colon
        }  
               
        else if(c < 65 || (c >= 91 && c <= 96) || c > 122 ){ //excludes any ASCII value that isn't a letter
           
            asc[i] = 32;  //sets ASCII value to space
            eN = 32;  //sets ASCII value to space
        }   

        printf("%c %d encrypted: %d %c\n", asc[i], asc[i], eN, eN);
        fputc(eN, output); //prints encrypted message to output file
     
    }
      
   /*------Determines frequency of character occurrence for statistical analysis------*/   
    for(i=0; i <= 1024; i++){
        count = 1;
        for(j=i+1; j <= 1024 ; j++){
            if(array[i]==array[j]){
                count++;
                freq[j] = 0;
            }
        }

        if(freq[i] != 0){
            freq[i] = count;
        }
    }
    
    printf("\nThe frequency of all elements of array : \n");
    
    for(i=0; i <= 1024; i++){
        if(freq[i] != 0){
            printf("%c (%d) occurs %d times\n", array[i], array[i], freq[i]);
        }
    }
    
     for(i=0; i <= 1024; i++){
        if(freq[i] > max){
            max = freq[i];
            maxLoc = array[i];
        }
    }   

    printf("\n%c occurs the most: %d times\n", maxLoc, max);
    
    
    
            
/*----------------------------------------------------------------------------------*/    

/*--------------Decryption/Encryption Based on Statistical Analysis------------------*/
    

        
   
        
    fclose(input); //closes input file
    fclose(output);
    
    return 0;     
}
   

    


    
