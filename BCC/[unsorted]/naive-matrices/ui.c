#include "ui.h"


int usemode(int argc, char* argv[]){
    if(argc==2 && (strlen(argv[1])==2 || strlen(argv[1])==6) && (!strcmp("-h", argv[1]) || !strcmp("--help", argv[1])))
        return 1;
    // for(;argc>0;argc--){
        
    // }
    return 0;
}