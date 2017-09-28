/*----------------------------------------------------------------------------

Brian DeJesus
cs435

LAB EXERCISE 5.2 - SQUARE ROOT APPROXIMATION
 ----------------------------------------
Write an assembly code subroutine to approximate the square root of an 
argument using the bisection method. All math is done with integers, so the 
resulting square root will also be an integer

GOOD LUCK!
 *----------------------------------------------------------------------------*/

__asm int my_sqrt(int x){// Square root using bisection algorithm
	
	//Write your code here
	PUSH {r4,r5,r7,r8,r9}  ; push registers onto stack that greater than r3
	MOVS r1, #0		;		 a
	ADDS r9, r0, #0	;  b
	MOVS r2, #-1	;		c
	MOVS r3, #0		; 	done 
	MOVS r4, #0		;		c_old
	MOVS r7, #2		;   divisor
	MOVS r8, #0		; register for c*c
	
start_loop					; beginning of loop
	ADDS r4, r2, #0		; old c gets c
	ADDS r5, r1, r9		; a+b
	UDIV r2, r5, r7   ; divide by 2 put in c
	MUL r8, r2, r2		; c*c 
	CMP r8, r0				; if c*c == x go to done true
	BEQ done_true
	CMP r8, r0 				; 
	BLO	second_true		; else if c*c less than x
	ADDS r9, r2, #0		; b = c
	B while_check			; check while condition
	

second_true						; second case true
	ADDS r1, r2, #0			;	a = c
	B while_check				;  check while condition

done_true						; Check if done is true
	ADDS r3, r3, #1 	; done = 1 
	B while_check			;  check while condition
	
while_check
	CMP r3, #1							; first while check
	BNE second_while_check  ; go to second while check
	B exit_loop							; else fails first condition exit loop
	
second_while_check				; second while condition
	CMP r2, r4							; compare c and c_old
	BNE start_loop					; if not equal go back to start of loop
	B exit_loop							; else fails second condition exit loop
	
exit_loop
	ADDS r0, r2, #0					; store c to return register
	POP {r4,r5,r7,r8,r9}		;		pop registers before exiting subroutine
	BX lr										; 	exit
	 
}

/*int my_sqrt(int x) { //C function 
	int done = 0;
	int a = 0;
	int b = x;
	int c = -1;
	int c_old = 0;
	
	do {
		c_old = c;
		c = (a+b) / 2;
		if (c*c == x){
			done = 1;
		}
		else if (c*c < x){
			a = c;
		}
		else{
			b = c;
		}
	}while ((!done) && (c != c_old));
	
	return c;
}*/
/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/
int main(void){
	volatile int r, j=0;
	int i;
  r = my_sqrt(0);     // should be 0
  r = my_sqrt(25);    // should be 5
	r = my_sqrt(133); 	// should be 11
  for (i=0; i<10000; i++){
		r = my_sqrt(i);	
    j+=r;
  }
	while(1)
		;
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************
