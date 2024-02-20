	# x = $t0
	# y = $t1

	.text
main:
	# printf("Enter a number: ");
	la	$a0, prompt	
	li	$v0, 4
	syscall

	# scanf("%d", &x);
	li	$v0, 5
	syscall
	move	$t0, $v0

	# y = x * x;
	mul	$t1, $t0, $t0

	# printf("%d\n", y);
	li	$v0, 1
	move	$a0, $t1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

	# return
	jr	$ra


	.data
prompt:
	.asciiz	"Enter a number: "
