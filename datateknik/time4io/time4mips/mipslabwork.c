/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */
volatile int* b = (volatile int*)0xbf886110;
volatile int *pek = &0xbf886100;
int i=0;
int mytime = 0x5957;
int timeoutCounter = 0;
char textstring[] = "text, more text, and even more text!";
int prime =1234567;

// int timer(void)
// {
//   if (IFS(0) & 0x100) //testa time out flaggan
//   {
//     IFS(0) = 0;        //reset flaggan
//     timeoutCounter++;
//   }
// }
/* Interrupt Service Routine */
void user_isr( void )
{

  if (IFS(0) & 0x100) //testa time out flaggan
  {
    IFS(0) = 0;        //reset flaggan
    timeoutCounter++;
  }
  if((IFS & 0x8000)
  {
    *b = i;
    i++;
  }
  if(timeoutCounter >= 10) {
    time2string( textstring, mytime );
    display_string( 3, textstring );
    display_update();
    tick( &mytime );
    // i++;
    //
    // *b = i;
    display_image(96, icon);
    timeoutCounter = 0;
  return;

}
}

/* Lab-specific initialization goes here */
void labinit( void )
{

  #define TMRPERIOD ((80 000 000/64)/100)
  #if TMRPERIOD > 0xffff
  #error "timer period is too big"
  #endif
  PR2 = TMRPERIOD;        //ld period register
  T2CON =0x70;            //stop tmr
  TMR2=0x0;             //clr timer register
  T2CONSET = 0x8000    //start
  *b=*b & 0xffffff00
  IFSCLR(0)= 0x100;    //sätta interrupt bitarna
  IPCSET(2)=0x4;
  IECSET(0) = 0x100;
  IPC(3)=0x5;


  *pek = 0;

  TRISDSET = 0x0fe0;
  enable_i();
  return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
  prime = nextprime (prime);
  display_string(0,itoaconv(prime));
  display_update();

  }

 // if(getbtns() & 0x1==1)
 //  {
 //    mytime= mytime & 0xff0f |getsw() << 4; //skifta och få in rätt info                                          //från switcharna
 //  }
 // if(getbtns() & 0x2 ==0x2)
 //  {
 //    mytime = mytime &0xf0ff |getsw()<< 8;
 //  }
 // if(getbtns() & 0x4 == 0x4)
 //  {
 //    mytime =mytime & 0x0fff |getsw()<< 12;
 //  }
}
