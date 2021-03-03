#include "types.h"
#include "user.h"
#include "syscall.h" 


void printaddr(unsigned int* pa, void* va)
{
   if (v2paddr(pa,va) == 0)
      {
            printf(1,"%x \n",*pa);
      }
      else
      {
          printf(1,"-1 \n");
      }
}

int
main()
{     
      int arr[] = {1,2,3};
      unsigned int pa;
      unsigned int* va = (uint *)0xface; 
      printaddr(&pa, va);
      printaddr(&pa, &arr[0]);
      printaddr(&pa, &arr[1]);
      exit();
}
