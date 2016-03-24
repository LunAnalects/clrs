#ifndef MACROS_H
#define MACROS_H

#include "string.h"

/*------swap macro
*/
#define swap(x,y) do \
{ unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
     memcpy(swap_temp,&y,sizeof(x)); \
     memcpy(&y,&x,       sizeof(x)); \
     memcpy(&x,swap_temp,sizeof(x)); \
    } while(0)
    

#endif