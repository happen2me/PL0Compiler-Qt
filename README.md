# PL/0 Compiler (GUI program)

This is the assignment of the class Compilers Principle and Crafts. 

It is is a GUI version of the [console version Pl0Compiler](https://github.com/happen2me/PL0Compiler-Console)

The project uses Visual Studio as development environment.

![User Interface](https://imgur.com/download/hke0Wj6)

## PL/0 grammar

```
<程序> ::= <分程序>.
<分程序> ::= [<常量说明部分>][变量说明部分>][<过程说明部分>]<语句>
<常量说明部分> ::= const<常量定义>{,<常量定义>};
<常量定义> ::= <标识符>=<无符号整数>
<无符号整数> ::= <数字>{<数字>}
<标识符> ::= <字母>{<字母>|<数字>}
<变量说明部分>::= var<标识符>{,<标识符>};
<过程说明部分> ::= <过程首部><分程序>;{<过程说明部分>}
<过程首部> ::= procedure<标识符>;
<语句> ::= <赋值语句>|<条件语句>|<当型循环语句>|<过程调用语句>|<读语句>|<写语句>|<复合语句>|<重复语句>|<空>
<赋值语句> ::= <标识符>:=<表达式>
<表达式> ::= [+|-]<项>{<加法运算符><项>}
<项> ::= <因子>{<乘法运算符><因子>}
<因子> ::= <标识符>|<无符号整数>|'('<表达式>')‘
<加法运算符> ::= +|-
<乘法运算符> ::= *|/
<条件> ::= <表达式><关系运算符><表达式>|odd<表达式>
<关系运算符> ::= =|<>|<|<=|>|>=
<条件语句> ::= if<条件>then<语句>[else<语句>]
<当型循环语句> ::= while<条件>do<语句>
<过程调用语句> ::= call<标识符>
<复合语句> ::= begin<语句>{;<语句>}end
<重复语句> ::= repeat<语句>{;<语句>}until<条件>
<读语句> ::= read'('<标识符>{,<标识符>}')'
<写语句> ::= write'('<标识符>{,<标识符>}')'
<字母> ::= a|b|...|X|Y|Z
<数字> ::= 0|1|2|...|8|9
```

## Explanation of the generated instructions

```
LIT	0, M	Push constant value (literal) M onto the stack
OPR	0, M	Operation to be performed on the data at the top of the stack
LOD	L, M	Load value to top of stack from the stack location at offset M 
			L lexicographical levels down
STO	L, M	Store value at top of stack in the stack location at offset M 
			L lexicographical levels down
CAL	L, M	Call procedure at code index M
INC	0, M	Allocate M locals (increment sp by M).
JMP	0, M	Jump to instruction M
JPC	0, M	Jump to instruction M if top stack element is 0
WRT	0, 1	Write the top stack element to the screen
RED	0, 2	Read in input from the user and store it at the top of the stack
```

