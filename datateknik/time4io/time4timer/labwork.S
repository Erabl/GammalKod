  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #

.data
	.global hexasc
	.global time2string
	.global delay
	.global loop
	.align 2
mytime:	.word 0x5957
timstr:	.ascii "text more text lots of text\0"
	.text
main:
	# print timstr
	la	$a0,timstr
	li	$v0,4
	syscall
	nop
	# wait a little
	li	$a0,2
	jal	delay
	nop
	# call tick
la	$a0,mytime
	jal	tick
	nop
	# call your function time2string
	la	$a0,timstr
	la	$t0,mytime
	lw	$a1,0($t0)
	jal	time2string
	nop
	# print a newline
	li	$a0,10
	li	$v0,11
	syscall
	nop
	# go back and do it all again
	j	main
	nop
# tick: update time pointed to by $a0
tick:	lw	$t0,0($a0)	# get time
	addiu	$t0,$t0,1	# increase
	andi	$t1,$t0,0xf	# check lowest digit
	sltiu	$t2,$t1,0xa	# if digit < a, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0x6	# adjust lowest digit
	andi	$t1,$t0,0xf0	# check next digit
	sltiu	$t2,$t1,0x60	# if digit < 6, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0xa0	# adjust digit
	andi	$t1,$t0,0xf00	# check minute digit
	sltiu	$t2,$t1,0xa00	# if digit < a, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0x600	# adjust digit
	andi	$t1,$t0,0xf000	# check last digit
	sltiu	$t2,$t1,0x6000	# if digit < 6, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0xa000	# adjust last digit
tiend:	sw	$t0,0($a0)	# save updated result
	jr	$ra		# return
	nop

delay:


       li $t0, 0
       li $t1, 1      #MS?
       li $t4, 0
       li $t5, 471    #loop konstant


       ble $t0, $t1, loop
       nop
       sub $t1, $t1, 1
       nop
loop:

      ble $t4, $t5, loop
      addi $t4, $t4, 1
      nop

      jr $ra
      nop
time2string:
          PUSH $s7
	  PUSH $ra
	  move $s7,$a0
          move $s4,  $a1

          srl $a0, $s4, 12
          jal hexasc
          nop
          sb $v0, 0($s7)
#10talsminut^^
          srl $a0, $s4, 8
          jal hexasc
          nop
          sb $v0, 1($s7)
 #heltalsminut^^
          li $t9, 0x3b
          sb $t9, 2($s7)
 #semikolon^^

          srl $a0, $s4, 4
          jal hexasc
          nop
          sb $v0, 3($s7)
#tiotalssekund^^
          srl $a0, $s4,0
          jal hexasc
          nop
          sb $v0, 4($s7)
#heltalssekund^^
          li $t6, 0x00
          sb $t6, 5($s7)
 	  POP $ra
          POP $s7
          jr $ra
  # you can write your code for subroutine "hexasc" below this line
hexasc:
      andi $a0, $a0, 0xf
      addi $a0, $a0, 0x30
      move $v0,$a0
      nop


      li $t0, 0x39
      ble $a0, $t0,end
      nop
      addi $v0, $a0, 7
      jr $ra
      nop
end:
jr $ra
nop
