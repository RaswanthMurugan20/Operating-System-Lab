#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "elf.h"

int
sys_fork(void)
{
  myproc()->syscallno[1] += 1;
  return fork();
}

int
sys_exit(void)
{
  myproc()->syscallno[2] += 1;
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  myproc()->syscallno[3] += 1;
  return wait();
}

int
sys_kill(void)
{
  int pid;
  myproc()->syscallno[6] += 1;
  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  myproc()->syscallno[11] += 1;
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;
  myproc()->syscallno[12] += 1;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  myproc()->syscallno[13] += 1;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;
  myproc()->syscallno[14] += 1;
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_getcount(void)
{
	int n;
	argint(0, &n);
	myproc()->syscallno[22] += 1;
	return getcount(n);
}

int 
sys_v2paddr(void)
{
  uint* va;
  uint* pa;
  if ( argptr(1,(void*)&va, sizeof(va)) < 0 || argptr(0,(void*)&pa, sizeof(pa)) < 0)
  {
	  return -1;
  }

  return v2paddr(pa,va);

}

