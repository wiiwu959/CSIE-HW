.data
	prompt: .asciiz "Please input an identification number:\n"
	legaltext: .asciiz "The number is legal.\n"
	illegaltext: .asciiz "The number is illegal.\n"
	input: .space 15
.text
	main:
	# when $v0 is 4,system call will print the string in $a0
	li $v0, 4		# store 4 in $v0
	la $a0, prompt		# store the string in $a0
	syscall
	
	# when $v0 is 8,system call will read the string and store to
	# the address $a0, then load input address into $a0
	li $v0, 8
	la $a0, input
	la $a1, 15		# length of buffer is 15
 	syscall
 	la $t0, input		# store the input address into $t0
 	
 	FirstWord:
 	lb $t1, 0($t0)		# load a byte to $t1 from address $t0
	beq $t1, 65, FirstA	# jump to different label according to 
	beq $t1, 66, FirstB	# their first word
	beq $t1, 67, FirstC
	beq $t1, 68, FirstD
	beq $t1, 69, FirstE
	beq $t1, 70, FirstF
	beq $t1, 71, FirstG
	beq $t1, 72, FirstH
	beq $t1, 73, FirstI
	beq $t1, 74, FirstJ
	beq $t1, 75, FirstK
	beq $t1, 76, FirstL
	beq $t1, 77, FirstM
	beq $t1, 78, FirstN
	beq $t1, 79, FirstO
	beq $t1, 80, FirstP
	beq $t1, 81, FirstQ
	beq $t1, 82, FirstR
	beq $t1, 83, FirstS
	beq $t1, 84, FirstT
	beq $t1, 85, FirstU
	beq $t1, 86, FirstV
	beq $t1, 87, FirstW
	beq $t1, 88, FirstX
	beq $t1, 89, FirstY
	beq $t1, 90, FirstZ
	
	# $t4 is sum
	# calculate the sum
	cal:
	move $t4, $t2		# sum = a0
	mul $t3, $t3, 9		# $t3 = a1 * 9
	add $t4, $t3, $t4	# sum += a1 * 9
		
	lb $t1, 1($t0)		# get a2
	sub $t1, $t1, 48	# transform ASCII code to int
	mul $t1, $t1, 8		# $t1 = a2 * 8
	add $t4, $t1, $t4	# sum += a2 * 8
	
	lb $t1, 2($t0)		# get a3
	sub $t1, $t1, 48
	mul $t1, $t1, 7		# $t1 = a3 * 7
	add $t4, $t1, $t4	# sum += a3 * 7
	
	lb $t1, 3($t0)		# get a4
	sub $t1, $t1, 48
	mul $t1, $t1, 6		# $t1 = a4 * 6
	add $t4, $t1, $t4	# sum += a4 * 6
	
	lb $t1, 4($t0)		# get a5
	sub $t1, $t1, 48
	mul $t1, $t1, 5		# $t1 = a5 * 5
	add $t4, $t1, $t4	# sum += a5 * 5
	
	lb $t1, 5($t0)		# get a6
	sub $t1, $t1, 48
	mul $t1, $t1, 4		# $t1 = a6 * 4
	add $t4, $t1, $t4	# sum += a6 * 4
	
	lb $t1, 6($t0)		# get a7
	sub $t1, $t1, 48
	mul $t1, $t1, 3		# $t1 = a7 * 3
	add $t4, $t1, $t4	# sum += a7 * 3
	
	lb $t1, 7($t0)		# get a8
	sub $t1, $t1, 48
	mul $t1, $t1, 2		# $t1 = a8 * 2
	add $t4, $t1, $t4	# sum += a8 * 2
	
	lb $t1, 8($t0)		# get a9
	sub $t1, $t1, 48
	add $t4, $t1, $t4	# sum += a9(*1)
	
	compare:
	lb $t1, 9($t0)		# get a10
	sub $t1, $t1, 48
	add $t4, $t1, $t4	# sum += a10
	rem $t4, $t4, 10	# mod 10
	beq $t4, 0, legal	# if result equal 0, it is legal
	j illegal		# else, illegal
	
	legal:
	li $v0, 4
	la $a0, legaltext
	syscall			# print legaltext 
	li $v0, 10
 	syscall			# end the program
	
	
	illegal:
	li $v0, 4
	la $a0, illegaltext
	syscall			# print illegaltext
	li $v0, 10
 	syscall			# end the program
	
	
	
	
	
	
	# $t2 store a0
	# $t3 store a1
	# do each alphabet seperately
	# after finished it, jump back to label cal
	FirstA:
	li $t2, 1
	li $t3, 0
	j cal
	
	FirstB:
	li $t2, 1
	li $t3, 1
	j cal
	
	FirstC:
	li $t2, 1
	li $t3, 2
	j cal
	
	FirstD:
	li $t2, 1
	li $t3, 3
	j cal
	
	FirstE:
	li $t2, 1
	li $t3, 4
	j cal
	
	FirstF:
	li $t2, 1
	li $t3, 5
	j cal
	
	FirstG:
	li $t2, 1
	li $t3, 6
	j cal
	
	FirstH:
	li $t2, 1
	li $t3, 7
	j cal
	
	FirstI:
	li $t2, 3
	li $t3, 4
	j cal
	
	FirstJ:
	li $t2, 1
	li $t3, 8
	j cal
	
	FirstK:
	li $t2, 1
	li $t3, 9
	j cal
	
	FirstL:
	li $t2, 2
	li $t3, 0
	j cal
	
	FirstM:
	li $t2, 2
	li $t3, 1
	j cal
	
	FirstN:
	li $t2, 2
	li $t3, 2
	j cal
	
	FirstO:
	li $t2, 3
	li $t3, 5
	j cal
	
	FirstP:
	li $t2, 2
	li $t3, 3
	j cal
	
	FirstQ:
	li $t2, 2
	li $t3, 4
	j cal
	
	FirstR:
	li $t2, 2
	li $t3, 5
	j cal
	
	FirstS:
	li $t2, 2
	li $t3, 6
	j cal
	
	FirstT:
	li $t2, 2
	li $t3, 7
	j cal
	
	FirstU:
	li $t2, 2
	li $t3, 8
	j cal
	
	FirstV:
	li $t2, 2
	li $t3, 9
	j cal
	
	FirstW:
	li $t2, 3
	li $t3, 2
	j cal
	
	FirstX:
	li $t2, 3
	li $t3, 0
	j cal
	
	FirstY:
	li $t2, 3
	li $t3, 1
	j cal
	
	FirstZ:
	li $t2, 3
	li $t3, 3
	j cal
	
	
		
 	
 	
	
	