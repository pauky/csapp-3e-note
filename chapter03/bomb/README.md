This is an x86-64 bomb for self-study students. 

## Answer
(ps: I just understand this two phases.)

### phase_1
Border relations with Canada have never been better.

1. check the main func, and find input param of phase_1

```
gdb bomb
disas main
```
you can find this code:
```
0x0000000000400e37 <+151>:	mov    %rax,%rdi
0x0000000000400e3a <+154>:	callq  0x400ee0 <phase_1>
0x0000000000400e3f <+159>:	callq  0x4015c4 <phase_defused>
```
then print the rdi
```
x/s $rdi
```
you can get your input param.

show the assembly code of  phase_1
```
disas phase_1
Dump of assembler code for function phase_1:
   0x0000000000400ee0 <+0>:	sub    $0x8,%rsp
   0x0000000000400ee4 <+4>:	mov    $0x402400,%esi
   0x0000000000400ee9 <+9>:	callq  0x401338 <strings_not_equal>
   0x0000000000400eee <+14>:	test   %eax,%eax
   0x0000000000400ef0 <+16>:	je     0x400ef7 <phase_1+23>
   0x0000000000400ef2 <+18>:	callq  0x40143a <explode_bomb>
   0x0000000000400ef7 <+23>:	add    $0x8,%rsp
   0x0000000000400efb <+27>:	retq
End of assembler dump.
```

I guess then %esi is the input param of strings_not_equal, so I try to get the its value.
```
b *0x0000000000400ee9
continue
x/s $rsi
```
then you will get the phase_1
```
0x402400:	"Border relations with Canada have never been better."
```


### phase_2
1 2 4 8 16 32

get the phase_2
```
disas phase_2
```

```
Dump of assembler code for function phase_2:
   0x0000000000400efc <+0>:	push   %rbp
   0x0000000000400efd <+1>:	push   %rbx
   0x0000000000400efe <+2>:	sub    $0x28,%rsp
   0x0000000000400f02 <+6>:	mov    %rsp,%rsi
   0x0000000000400f05 <+9>:	callq  0x40145c <read_six_numbers>
   0x0000000000400f0a <+14>:	cmpl   $0x1,(%rsp)
   0x0000000000400f0e <+18>:	je     0x400f30 <phase_2+52>
   0x0000000000400f10 <+20>:	callq  0x40143a <explode_bomb>
   0x0000000000400f15 <+25>:	jmp    0x400f30 <phase_2+52>
   0x0000000000400f17 <+27>:	mov    -0x4(%rbx),%eax
   0x0000000000400f1a <+30>:	add    %eax,%eax
   0x0000000000400f1c <+32>:	cmp    %eax,(%rbx)
   0x0000000000400f1e <+34>:	je     0x400f25 <phase_2+41>
   0x0000000000400f20 <+36>:	callq  0x40143a <explode_bomb>
   0x0000000000400f25 <+41>:	add    $0x4,%rbx
   0x0000000000400f29 <+45>:	cmp    %rbp,%rbx
   0x0000000000400f2c <+48>:	jne    0x400f17 <phase_2+27>
   0x0000000000400f2e <+50>:	jmp    0x400f3c <phase_2+64>
   0x0000000000400f30 <+52>:	lea    0x4(%rsp),%rbx
   0x0000000000400f35 <+57>:	lea    0x18(%rsp),%rbp
   0x0000000000400f3a <+62>:	jmp    0x400f17 <phase_2+27>
   0x0000000000400f3c <+64>:	add    $0x28,%rsp
   0x0000000000400f40 <+68>:	pop    %rbx
   0x0000000000400f41 <+69>:	pop    %rbp
   0x0000000000400f42 <+70>:	retq
End of assembler dump.
```

get its relative function
```
disas read_six_numbers
```

```
Dump of assembler code for function read_six_numbers:
   0x000000000040145c <+0>:	sub    $0x18,%rsp
   0x0000000000401460 <+4>:	mov    %rsi,%rdx
   0x0000000000401463 <+7>:	lea    0x4(%rsi),%rcx
   0x0000000000401467 <+11>:	lea    0x14(%rsi),%rax
   0x000000000040146b <+15>:	mov    %rax,0x8(%rsp)
   0x0000000000401470 <+20>:	lea    0x10(%rsi),%rax
   0x0000000000401474 <+24>:	mov    %rax,(%rsp)
   0x0000000000401478 <+28>:	lea    0xc(%rsi),%r9
   0x000000000040147c <+32>:	lea    0x8(%rsi),%r8
   0x0000000000401480 <+36>:	mov    $0x4025c3,%esi
   0x0000000000401485 <+41>:	mov    $0x0,%eax
   0x000000000040148a <+46>:	callq  0x400bf0 <__isoc99_sscanf@plt>
   0x000000000040148f <+51>:	cmp    $0x5,%eax
   0x0000000000401492 <+54>:	jg     0x401499 <read_six_numbers+61>
   0x0000000000401494 <+56>:	callq  0x40143a <explode_bomb>
   0x0000000000401499 <+61>:	add    $0x18,%rsp
   0x000000000040149d <+65>:	retq
End of assembler dump.
```
then break in __isoc99_sscanf and fetch the input param.

```
b * 0x000000000040148a
continue
x/s $rdi
```
found
```
0x4025c3:	"%d %d %d %d %d %d"
```
So the input is siz number with space. And they had been stored to stack where start with %rsp.

according the phase_2 code, you can translate it to c code
```
int sp[7];
sscanf(input,"%d %d %d %d %d %d",sp);
if(!(sp[0]==1)){
	BOOM();
}
bx=sp+1;
bp=sp+7;
do{
	ax=*(bx-1);
	ax+=ax;
	if(!(ax==*bx)){
		BOOM();
	}
	bx+=1;
	if(bx==bp){
		break;
	}
}while(1);
return;
```

So we can get the phase_2 is: "1 2 4 8 16 32".



## reference
[bomb lab record](https://www.cnblogs.com/kangyupl/p/13052593.html)