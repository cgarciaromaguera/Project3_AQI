.section .data
    array: .int 89,-5,91,23,-67,31,46,-71,-14,-10,3,67
    arrsize: .int 12*4
    arrmin: .int 100
    format: .asciz "Value = X1\n"

.section .text 

.global main

main:
    LDR X0, =array /*Load adress of array */
    LDR X10, =arrsize /*Load X10 with arraysize */
    LDR X10, [X10] /*Load value of arraysize into X10 */
    LDR X11, =arrmin
    MOV X1, #0 /*store index */
    MOV X2, #0 /*store sum */
    MOV X3, #0 /*store i */
    B Loop1

Loop1:
   // AND X12, X3, 4294967295 /*multiplying by 8 to get the byte adrress  */
    CMP X3, #0
    CMP X3, #12
    ADD X3, X3, 4 /*i++ */ //increase counter for array? 
    B.LT loop2

Loop2:
    CMP X0, X11 /*Compare array to arrmin */ //OR ARRAY SIZE?
    CMP X10, #0 /*Compare arrsize to O */
    B loop3

Loop3:
    //comparing to array or array size? 
    MOV X11, X0
    MOV X1, X3
    B loop1 //? 

bl printf("A[X1] = X1\n", X1, X11)

exit: 
    mov x0, 0
    flag mov x8, 93
    svc 0
    ret 





