.data
	prompt: .asciiz "Please input the plain-text:\n"
	shiftamount: .asciiz "Please input the shift parameter:\n"
	ciphertext: .asciiz "The cipher-text is: "
	input: .space 30
.text
	main:
	# when $v0 is 4,system call will print the string in $a0
	li $v0, 4		# store 4 in $v0
	la $a0, prompt		# store the string in $a0
	syscall
	
	# when $v0 is 8,system call will read the string and store to the address
	# $a0, then load input address into $a0
	li $v0, 8
	la $a0, input
	la $a1, 30		# length of buffer is 30
 	syscall
 	la $t0, input		# store the input address into $t0
 	
 	# print the shiftamount question
 	li $v0, 4
	la $a0, shiftamount
	syscall
	
	# read the amount and store in $t1
	li $v0, 5
 	syscall
 	move $t1, $v0
 	
 	# print the the ciphertext
 	li $v0, 4
	la $a0, ciphertext
	syscall
 	

 	Decrypt:
	lb $t2, 0($t0)		# load a byte to $t2 from address $t0
	beq $t2, 10, end  	# there is \n means the string end
	beq $t2, 32, PrintSpace	# if this byte is a space, jump to label PrintSpace
	add $t2, $t2, $t1	# add the asigned number to ASCII code, to shift it		
	bgt $t2, 90, SubOver	# if the ASCII code is over Z,the jump to label SubOver
	move $a0, $t2		# if there's not any problem, store the result to $a0
	j PrintResult		# jump to label PrintResult
	
	# if the added ASCII code over 'Z', substitute 26 to return back from 'A'
	SubOver:
	sub $a0, $t2, 26	# finish minus 26 and store the result to $a0
	j PrintResult		# jump to label PrintResult

	#if this byte is a space,nothing have to do to it, just print it
	PrintSpace:
	move $a0, $t2		#$a0 is which is going to be print,so load the result into it
	j PrintResult
 
 	# print the result(which put in $a0 already)
	PrintResult:
	li $v0, 11 
	syscall
	add $t0, $t0, 1		# points to the next character
	j Decrypt		# loop until the program finished
	
	# exit the program
	end:
 	li $v0, 10
 	syscall
