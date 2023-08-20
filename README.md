# PES_ASIC_CLASS
**Course Name** : VLSI Physical Design for ASICs  
**Instructor** : Kunal Ghosh   
**About Course** : This course covers key aspects of RISC-V and chip design, spanning design cycles, RISC-V ISA, analog IPs, and mixed-signal flow. It delves into process design kits, libraries, RTL design synthesis, and gate-level simulation. The curriculum also includes RTL-to-GDS flow, encompassing SoC design implementation from floor planning to post-layout timing analysis.<br>

## Skill Outcomes
1. Architectural Design
2. RTL Design/Behavioral Modeling
3. Floorplanning
4. Placement
5. CTS
6. Routing 

## Installation
https://github.com/kunalg123/riscv_workshop_collaterals/blob/master/run.sh
1. Open Terminal<br>
2. Run the commands in run.sh file one after the another.

## Course
<details>
<summary> Day 1 </summary><br>

### Contents of Day 1
+ Introduction
+ Program to compute the Sum of Natural numbers till n.
+ Assembly code of sumNn.c
+ Spike Simulations and Debug.
### Introduction
Software --> **ISA** --> Hardware     
**ISA** is Instruction Set Architecture: It the language the processor understands.   

Application(C code) -> Compiler(ISA) -> Assembler(Machine code) -> Processor  

1. Application performing some operation is written in C language.
2. Compiler converts the C language into ISA.
3. Assembler Converts these instructions into machine code(binary).
4. Processor only undersands o's and 1's.  

### Program to compute the Sum of Natural numbers till n.
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
#### 1. Executing using GCC Complier<br>
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

#### 2. Executing using RISC-V Complier<br>
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
   
### Assembly code of sumNn.c
Run the code and check is ouput file is generated or not.<br>
(view the code to complie sumNn.c in risc-v  complier above)<br>
![D1_23_L2_code](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/23ea33f9-39dd-452e-b0fe-804f1dfe12dd)
To view the assembly code of sumNn.c 
```
riscv64-unknown-elf-objdump -d sumNn.o | less
```
Since we have written our code in 'int main()'<br>
Search main by typing
```
/main
```
Press 'n' so that the address where the main file is present.
![less_main_no_instru](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/09db068c-ad45-4f1e-aac7-9a308f46603d)
<br>
To find the number of instructions in main file.
To find the number of instructions<br>
* **((Last address + 4) - initial address) / 4**
* Using **-O1** to compile.
  ![D1_23_L2_gen_of_op_file](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/e41bb0e1-02f7-43ff-82ca-1e9a63f0e0e0)

  ![less_no_instru](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/9c2a0fda-ed31-45b5-bb02-50f70bdd173f)
  ![less_no_instru_dec](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/ff0f901b-d268-48b1-9bab-ea84dd065a03)
  <br>
  Got **11** instructions.
* Usig **-Ofast** to complie.
  ![D1_23_L2_code](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/91ceaaf0-461b-4405-bb18-ea119292ed11)
  ![fast_no_instru_hexa](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/b84020a8-5e1a-47ac-be8b-35e1defecb3f)
  ![fast_no_instru_dec](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/4047f7f8-71f3-4dcb-9e9f-b06db83e8748)
  <br>
  Got **11** instructions.

### Spike Simulations and Debug
Compile the code in riscv compiler.<br>
To debug 
```
spike -d pk sumNn.o
```
Run the code till the address 100b0.
```
until pc 0 100b0
```
To view the content of register.
```
reg 0 a0
```
Press ENTER to run the next command.<br>
Then type 'reg 0 a0' see the content of a0, it will be updated.<br>
```
reg 0 sp
```
Next press ENTER to run the next command.<br>
```
reg 0 sp
```
'sp' register will be updated with addi command.<br>
The object dump file
![obj_dump](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/33db1008-ce14-4db4-9a71-899d5d50777c)
![D1_23_L3_code](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/fe04100a-cdac-4134-9719-9756b6471258)
<br>
**lui** - load upper immediate
**lui a0, %hi(.LC1)**<br>
  lui destn_reg, offset(immediate_value) 
<br>
**addi** - add immediate<br>
**addi destn_reg, src_reg_1, imm_value**
<br>
<br>
**Byte Addressing** - It is the method in which each address location in the memory is having unique address of 1 Byte or 8 bit.
In RISC-V architecture we use Byte addressing because it is much effecient use of memory.
<br>
And **each and every instruction** in RISC-v is of **32 Bit** in length.
<br>

</details>
