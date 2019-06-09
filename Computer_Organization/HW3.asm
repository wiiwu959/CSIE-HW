.data
	promptfirst: .asciiz "Please input first positive integer n:\n"
	promptsecond: .asciiz "Please input second positive integer k:\n"
	result: .asciiz "The binomial coefficient C("
	space: .asciiz ", "
	space2: .asciiz ") = "
	
.text
	main:
	# print the string "Please input first positive integer n:\n"
	li	$v0, 4			# store 4 in $v0(print)
	la	$a0, promptfirst	# store the string in $a0
	syscall
	
	# read the first positive integer n and store in $t0
	li	$v0, 5
 	syscall
 	move	$t0, $v0
 	
 	# print the string "Please input first positive integer n:\n"
	li	$v0, 4			# store 4 in $v0(print)
	la	$a0, promptsecond	# store the string in $a0
	syscall
	
	# read the second positive integer k and store in $t1
	li	$v0, 5
 	syscall
 	move	$t1, $v0
 	
 	# print "The binomial coefficient C(n, k) ="
 	li	$v0, 4	
	la	$a0, result
	syscall
	li	$v0, 1
	move	$a0, $t0
	syscall
	li	$v0, 4
	la	$a0, space
	syscall
	li	$v0, 1
	move	$a0, $t1
	syscall
	li	$v0, 4
	la	$a0, space2
	syscall
	
	# set v1 as 0(initialize)
 	li	$v1, 0
 	# call binomial function	
	jal	bino
	
	# print the result which is store in v1
 	li	$v0, 1
	move	$a0, $v1
	syscall
	
	end:
 	li $v0, 10
 	syscall
 	
 	
 	# binomial function
 	bino: 
	addi	$sp, $sp, -12		# adjust stack for 3 items
	sw	$ra, 8($sp)		# save return address
	sw	$t0, 4($sp)		# save argument
	sw	$t1, 0($sp)
	
	# if
	beqz	$t1, return1		# if(k==0)
	beq	$t0, $t1, return1	# if(k==n), return 1
	
	#else
	sub	$t0, $t0, 1		# do C(n-1,k)
	jal	bino
	lw	$t0, 4($sp)		# load original value which maybe changed in callee
	lw	$t1, 0($sp)
	sub	$t0, $t0, 1		# do C(n-1,k-1)
	sub	$t1, $t1, 1
	jal	bino
	
	# this function is used by bino and return function to go back to last location(ra)
	back:
	lw	$ra, 8($sp)
	addi	$sp, $sp, 12		# give back the pop the data in stack
	jr	$ra			
	
	return1:
	addi	$v1, $v1, 1		# add v1 by 1, also means return 1 
	j	back
	
	
	
	
	
	
	
 	
 	
 	
 	
 	
