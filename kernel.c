typedef unsigned short uint16 ;

void kmain(void){

    const char *str ="my first kernel";
    char *vidptr = (char*)0xb8000; //video mem begin at this address
    uint16 i =0;
    uint16 j =0;
    //these loops clear the screen
    // there are 25 lines each of 80 cols; each element takes 2 bytes

    while(j<80*25*2){
        vidptr[j]=' ';
        vidptr[j+1] = 0x07;
        j=j+2;
    }

    j=0;
    // this loop writes the string to video memory

    while(str[j]!='\0'){
        // the character's ascii
        vidptr[i]=str[j];
        // attribut-byte: give character black bg and light grey fg
        vidptr[i+1] = 0x07;
        ++j;
        i=i+2;
    }

    return;

}