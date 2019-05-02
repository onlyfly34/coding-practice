#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"
#include "binary_search.h"

int find_LIS_string(Array *source_string, Array *LIS_string){
    if(source_string->used == 0) return 0;
	int i,j,k,len=0;
	Array fake_LIS_string, dirty_flag;
	initArray(&fake_LIS_string, 5);
    initArray(&dirty_flag, 5);
    insertArray(LIS_string, source_string->array[0]);
    insertArray(&fake_LIS_string, source_string->array[0]);
    insertArray(&dirty_flag, 0);
    len++;
	for(i=1;i<(int)source_string->used;i++){
		int location = BinarySearch(&fake_LIS_string,source_string->array[i],0,(int)fake_LIS_string.used-1);
		if(location>LIS_string->used-1){
		    for(j=0;j<(int)dirty_flag.used;j++){
                if(dirty_flag.array[j] == 0) break;
                if(j == (int)dirty_flag.used-1) {
                    for(k=0;k<LIS_string->used;k++) {
                        LIS_string->array[k] = fake_LIS_string.array[k];
                        dirty_flag.array[k] = 0;
                    }
                }
		    }
			insertArray(LIS_string, source_string->array[i]);
			insertArray(&fake_LIS_string, source_string->array[i]);
			insertArray(&dirty_flag, 0);
			len++;
		}
		else{
            fake_LIS_string.array[location] = source_string->array[i];
            dirty_flag.array[location] = 1;
		}
		if(location==LIS_string->used-1){
			LIS_string->array[location] = source_string->array[i];
		}
	}
	freeArray(&fake_LIS_string);
	freeArray(&dirty_flag);
	return len;
}

int main(int argc, char **argv){
	Array source_string, LIS_string;
	FILE *fp;
	int input,i;

	initArray(&source_string, 5);
	initArray(&LIS_string, 5);

	fp = fopen(argv[1],"r");
    if(!fp) perror("Error reading file.");
    else{
        while(fscanf(fp, "%d", &input) != EOF){
            insertArray(&source_string, input);
        }
        fclose(fp);
    }

	printf("Length of LIS: %d\n",find_LIS_string(&source_string, &LIS_string));

	printf("Longest increasing subsequence: [ ");
	for(i=0;i<(int)LIS_string.used;i++)
		printf("%d ",LIS_string.array[i]);
	printf("]\n");

	freeArray(&source_string);
	freeArray(&LIS_string);
	return 0;
}
