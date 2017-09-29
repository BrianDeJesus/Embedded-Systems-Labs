/*----------------------------------------------------------------------------
LAB EXERCISE 5.1 - PROCESSING TEXT IN ASSEMBLY LANGUAGE
 ----------------------------------------------
Examine program execution at the processor level using the debugger
 *----------------------------------------------------------------------------*/

__asm void my_strcpy(const char *src, char *dst){
	//This function makes a copy of a string
	//Write your code here
loop
	LDRB  r2, [r0] ; Load byte into r2 from mem. pointed to by r0 (src pointer)
	ADDS r0, #1 ; Increment src pointer
	STRB  r2, [r1] ; Store byte in r2 into memory pointed to by (dst pointer)
	ADDS r1, #1 ; Increment dst pointer
	CMP   r2, #0 ; Was the byte 0?
	BNE   loop ; If not, repeat the loop
	BX    lr ; Else return from subroutine
}

__asm void my_capitalize(char *str){
	//This function capitalizes the whole string
	//Write your code here
cap_loop
	LDRB  r1, [r0] ; Load byte into r1 from memory pointed to by r0 (str pointer)
	CMP r1, #'a'-1 ; compare it with the character before 'a'
	BLS cap_skip ; If byte is lower or same, then skip this byte
	CMP r1, #'z' ; Compare it with the 'z' character
	BHI cap_skip ; If it is higher, then skip this byte
	SUBS r1,#32 ; Else subtract out difference to capitalize it
	STRB  r1, [r0] ; Store the capitalized byte back in memory

cap_skip
	ADDS r0, r0, #1 ; Increment str pointer
	CMP  r1, #0 	 					; Was the byte 0?
	BNE   cap_loop 					; If not, repeat the loop
	BX    lr 								 ; Else return from subroutine
}

__asm void my_lower(char *str){
	//This function lowercases the string
low_loop
	LDRB r1, [r0]		  ; Load byte from memory pointed to by r0
	CMP r1, #'Z'+1		; compare with char after 'Z'
	BHI low_skip		  ; skip if already lower case
	CMP r1, #'A'-1 		; Compare with 'A' character
	BLS low_skip			; Skip char before A
	ADDS r1, #32			; Else Add difference to lowercase it
	STRB r1, [r0]			; store lowercased char back in memory

low_skip
	ADDS r0, r0, #1	 ; Increment str pointer
	CMP r1, #0		   ; Check byte 0?
	BNE low_loop	   ; if not done, repeat loop
	BX lr					   ; Else return from subroutine

}

__asm void cap_first_and_last(char *str){
	//This function capitalizes the first and last letter of a string
check_first_loop
	LDRB r1, [r0]		  ; Load byte from memory pointed by r0
	CMP r1, #'a'-1		; If chars before 'a' skip
	BLS find_first_loop		; skip chars before 'a'
	SUBS r1, #32			; Else subtract difference and capitalize
	STRB r1, [r0]			; Replace first lower with capitalized letter
	B skip_mid_loop		;

find_first_loop
	CMP	r1, #'A'-1		; Coming into this loop already means that the char is before 'a'
	BHI skip_mid_loop	; Skip if first letter already capital
	ADDS r0, r0, #1		;
	LDRB r1, [r0]			;
	CMP r1, #'z'			;
	BLS check_first_loop		;

skip_mid_loop
	ADDS r0, r0, #1 	; Increment str pointer
	LDRB r1, [r0]			; Load byte from memory
	CMP  r1, #0 	 					; Was the byte 0?
	BNE  skip_mid_loop 		; If not, repeat the loop
	CMP  r1, #0				; if it is the end
	BEQ  exit_loop		; Exit loop

exit_loop
	SUBS r0, r0, #1   ; Decrement to get to last index
	LDRB r1, [r0]		  ; Load byte from memory pointed by r0
	CMP r1, #'A'-1	  ; if Capital or anything besides lower
	BLS exit_loop						; Backtrack if not
	CMP r1, #'Z'		  ; Compare with Z
	BLS exit_routine   	; Exit routine if last letter is already capital
	SUBS r1, #32			; Else subtract difference and capitalize
	STRB r1, [r0]			; Replace first lower with capitalized letter
	B exit_routine		; Exit subroutine

exit_routine
	BX lr				   ; Exit subroutine

}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(void){

	//Write your code here
	const char a[] = "!!Hello! world!";
	char b[20];
	my_strcpy(a, b);
	my_capitalize(b);
	my_lower(b);
	cap_first_and_last(b);
	while (1)
		;
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************
