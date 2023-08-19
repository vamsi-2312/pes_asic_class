# PES_ASIC_CLASS
**Course Name** : VLSI Physical Design for ASICs  
**Instructor** : Kunal Ghosh   
**About Course** : In this course we are going to learn how to build a chip(RISC-V Architecture) and how are instructions from the software(application) are executed in the hardware(processor) and more.

## Introduction
Software --> **ISA** --> Hardware     
**ISA** is Instruction Set Architecture: It the language the processor understands.   

Application(C code) -> Compiler(ISA) -> Assembler(Machine code) -> Processor  

1. Application performing some operation is written in C language.
2. Compiler converts the C language into ISA.
3. Assembler Converts these instructions into machine code(binary).
4. Processor only undersands o's and 1's.  

## Course
<details>
<summary> Day 1 </summary><br>
  
 **Program to compute the Sum of Natural numbers till n.**
  <br>
  #### Code -> sumNn.c
  ```
  #include <stdio.h>

  int main()
  {
    int i, sum = 0, n = 10;
    for(i = 1; i <= n; ++i)
    {
    sum += i;
    }
    printf("Sum of Numbers from 1 to %d = %d\n", n, sum);
    return 0;
  }
  ```
1. Executing using GCC Complier<br>
   ```
   gcc sumNn.c -o sumNn.o
   ```
   By using '-o' the output file is stored in ***sumNn.o***, if not mentioned by default it is stored in 'a.out'.<br>
   To display output
   ```
   ./sumNn.o
   ```
   ![gcc_sumNn_c](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/6ba8d493-d782-454f-8fb6-c442ade80b72)
   <br>

2. Executing using RISC-V Complier<br>
   Before executing we must export path.<br>
   ```
   export PATH="/home/home/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14/bin:$PATH"   
   ```
   path of file == riscv_toolchain -> risc64-unknown-eld-gcc -> bin<br>
   and then add 'bin:$PATH' at the end.
   ```
   riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sumNn.o sumNn.c
   ```
   * **-O1**: This is a compiler optimization flag. The -O1 flag indicates level 1 optimization.
   * **-mabi=lp64**: This flag specifies the ABI (Application Binary Interface) used for the compiled code.(The lp64 ABI indicates that long and pointer types are 64 bits.)
   * **-march=rv64i**: This flag specifies the target RISC-V architecture and its instruction set.
   To display output
   ```
   spike pk sumNn.o
   ```
   ![riscv_sumNn_c](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/7b4b9c2e-5dc8-4cf4-b203-28951304072b)
</details>
