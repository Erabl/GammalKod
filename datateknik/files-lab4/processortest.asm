.data
.text

  addi $a0,$a0,3  #deklarera a0/n
  addi $a1,$a0,0
  addi $a2,$0,0
  addi $a3,$0,1
  
  
 loop:
  addi  $a2,$0,1
  addi $a3,$a3,1
  beq  $a3,$a2,ut
  beq  $0,$0,loop
  	
 ut: 
 add  $v0, $0, $a2
 addi $a1,$a1,-1
 beq  $a1,1, stop 
 beq  $0,$0,loop
        
  
 stop:
 beq  $0,$0,stop