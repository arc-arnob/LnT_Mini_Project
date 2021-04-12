#include "prototypes.h"

error_t delete_rec_file(FILE **fptr,FILE **ft, int id){
    patient rec;
    *ft = fopen("TEMP.DAT","wb+");
    
    rewind(*fptr);
    while(fread(&rec, sizeof(rec),1,*fptr) == 1){
        if(rec.uniq_id != id){
            fwrite(&rec,sizeof(rec), 1, *ft);
        }
        
    }
    return SUCCESS;

}

error_t delete_index_file(FILE **fptr,FILE **ft, int id){
    int idx;
    *ft = fopen("TEMP.DAT","wb+");
    
    rewind(*fptr);
    while(fread(&idx, 4,1,*fptr) == 1){
        if(idx != id){
            fwrite(&idx,4, 1, *ft);
        }
        
    }
    fclose(*ft);
    return SUCCESS;

}