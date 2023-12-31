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

## Day wise Contents

### Week 1

### +  Contents of Day 1
* Introduction
* Program to compute the Sum of Natural numbers till n.
* Assembly code of sumNn.c
* Spike Simulations and Debug.
* 64 Bit Signed ans Unsigned Binary Integer Numbers.
* Program to find the maximum and minimum values of Signed and Unsigned numbers.
  
### + Contents of Day 2
* Application Binary Interface(ABI)
* ABI function calls
* Running C program on RISC-V CPU

### Week 2

### + Contents of Day 1
* Introduction to Open Source Simulator - IVERILOG
* Installation and Lab using Iverilog and GTKWAVE
* Introduction to Yosys and Logic Synthesis
* Labs using Yosys and Sky130 library

### + Contents of Day 2
* Introduction to timing .lib
* Hierarchical vs Flat Synthesis
* Various Flop Coding styles and Optimsation

### + Contents of Day 3
* Introduction to Optimisation.
* Combinational Logic Optimisation.
* Sequential Logic Optimisation.
* Sequential Optimisation for unused outputs.

### + Contents of Day 4
* GLS, Synthesis-Simulation mismatch and Blocking/Non-blocking statements
* Labs on GLS, Synthesis-Simulation mismatch
* Labs on Synthesis-Simulation mismatch and Blocking/Non-blocking statements

### Week 3

### + Contents of Day 1
* How to talk to computers.
* Soc Design and Openlane
* Open Source EDA Tools.

## Course
<details>
<summary> Week 1 -> Day 1 </summary><br>

## Contents of Day 1
+ Introduction
+ Program to compute the Sum of Natural numbers till n.
+ Assembly code of sumNn.c
+ Spike Simulations and Debug.
+ 64 Bit Signed ans Unsigned Binary Integer Numbers.
+ Program to find the maximum and minimum values of Signed and Unsigned numbers.

## Introduction
Software --> **ISA** --> Hardware     
**ISA** is Instruction Set Architecture: It the language the processor understands.   

Application(C code) -> Compiler(ISA) -> Assembler(Machine code) -> Processor  

1. Application performing some operation is written in C language.
2. Compiler converts the C language into ISA.
3. Assembler Converts these instructions into machine code(binary).
4. Processor only undersands o's and 1's.  

## Program to compute the Sum of Natural numbers till n.
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
   
## Assembly code of sumNn.c
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

## Spike Simulations and Debug
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

## 64 Bit Signed ans Unsigned Binary Integer Numbers
- Humans understand **Decimal** numbers.
- Computers understand **Binary** numbers.
<br>
  MSB - Most Significant Bit<br>
  LSB - Least Significant Bit<br>
<br>
  * 1 Bit<br>
  * 1 Byte = 8 Bits<br>
  * 1 Halfword = 16 Bits<br>
  * 1 Word = 32 Bits = 4 Bytes<br>
  * 1 Doubleword = 64 Bits = 8 Bytes<br>

#### Range of Unsigned Integers<br>
For  n Bit --> 0 to (2^n - 1)<br>
For  2 Bit --> 0 to (2^2 - 1) = 0 to 3<br>
For  4 Bit --> 0 to (2^4 - 1) = 0 to 15<br>
For 64 Bit --> 0 to (2^64 - 1) = 0 to 18446744073709551999<br>

#### Range of Signed Integer<br>
For  n Bit --> (-2^(n-1))  to (2^(n-1) - 1)<br>
For  2 Bit --> (-2^1)  to (2^1 - 1)  = -2 to 1 <br>
For  4 Bit --> (-2^4)  to (2^4 - 1)  = -8 to 7 <br>
For 64 Bit --> (-2^64) to (2^64 - 1) = -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807<br>

#### 2's Compliment(Representation of Negative Numbers in Binary)
1. Write the magitude in binary format.
2. Invert the numbers(0 -> 1)(1 -> 0).
3. Add 1
4. We have got the 2'c compliment form of the negative number.
<br>

( 2)dec = (0010)bin<br>
(-2)dec = (1110)bin<br>
<br>

#### MSB for Signed Number
+ Postive Number has MSB as **0** for signed number.
+ Negative Number has MSB as **1** for Signed number.
<br>

## Program to find the maximum and minimum values of Signed and Unsigned numbers

<br>

#### 1. For Unsigned Numbers.<br>

#### Code
```
#include <stdio.h>
#include <math.h>

int main()
{
	unsigned long long int max = (unsigned long long int) (pow(2,64)-1);
	unsigned long long int bey_max = (unsigned long long int) (pow(2,99)-1);
	unsigned long long int min = (unsigned long long int) (pow(2,64)*-1);
	unsigned long long int mid = (unsigned long long int) (pow(2,10)-1);
	printf("The highest value of unsigned long long int = %llu\n",max);
	printf("The value of bey_max(if value more than max) = %llu\n",bey_max);
	printf("The lowest value of unsigned long long int = %llu\n",min);
	printf("The value of mid = %llu\n",mid);
	return 0;
}
```
![code_unsigned](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/54928a06-d7ee-4ff9-bf84-739eae56800f)
![exe_code_unsigned](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/00d452bd-bc10-4bf8-b6d9-cc7dfe77e2c9)
<br>

#### 2. For Signed Numbers.<br>

```
#include <stdio.h>
#include <math.h>

int main()
{
	long long int max = (long long int) (pow(2,63)-1);
	long long int min = (long long int) (pow(2,63)*-1);
	long long int bey_max = (long long int) (pow(2,99)-1);
	long long int bey_min = (long long int) (pow(2,99)*-1);
	printf("The maximum value of signed long long int = %lld\n",max);
	printf("The minimum value of signed long long int = %lld\n",min);
	printf("The value if beyond maximum = %lld\n",bey_max);
	printf("The value if less then minimum = %lld\n",bey_min);
	return 0;
}
```
![code_signed](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/1a4058a2-4773-4549-9377-019b49aafcad)
![exe_code_signed](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/9eb1d2ef-a5b0-4f8b-8eab-21b8a02820f6)
<br>
End of Day 1.
<br>
</details>

<details>
<summary> Week 1 -> Day 2 </summary><br>

## Contents of Day 2
+ Application Binary Interface(ABI)
+ ABI function calls
+ Running C program on RISC-V CPU

## Application Binary Interface
An Application Binary Interface (ABI) defines how binary code interacts at a low level, specifying data structures, calling conventions, and system-level details to ensure compatibility between compiled software components on a given platform.
<br>

**Application software**  -(API)->  **Standard Libraries**  ->  **OS**  -(ISA)->  **Processor Architecture**  -(RTL)->  **Hardware**
<br>
API - Application Programming Interface<br>
ISA - Intruction Set Architecture<br>
RTL - Register transfer level<br>

Some part of the ISA availabe to OS and to the User
- User and System ISA
- User ISA
<br>

Application program can access some of the system or hardware directly by **System Calls**(like accessing register).<br>
We call this ABI aka Sytem call interface.<br>

ABI <-register-> registers

* RV32 has 32 32bit size registers.
* RV64 has 32 64bit size registers.
<br>

There are 2 different ways to load the data
1. Load and Store method.(RISC-V uses this method)
2. Direct memory accessing.
<br>

RISC-V uses **Little endian** Memory Addressing, meaning the LSB is loaded first then till MSB.
<br>

**Intructions size is always ***32 bit*** no matter is RV32 or RV64.**
<br>

#### Basic Integer Instruction
1. Load (I Type instruction)
2. Add (R Type instruction)
3. Store (S Type instruction)

##### Load Instruction
syntax - ld rd, imm(rs1);<br>
ld = load doubleword<br>
rd = destination register<br>
rs1 = source register 1<br>
imm = immediate value or offest<br>
[immediate value][rs1][func3][rsd][opcode]<br>

#### Add Instruction
syntax - add rd, rs1, rs2;
rd = destination register<br>
rs1 = source register 1<br>
rs2 = source register 2<br>
[func7][rs2][rs1][func3][rd][opcode]<br>

#### Store Instruction
syntax - sd rs2,imm(rs1);
sd = store doubleword<br>
rs1 = source register 1<br>
rs2 = source register 2<br>
imm = immediaate value or offset<br>
[imm(11:5)][rs2][rs1][func3][imm(4:0)][opcode]<br>

**Instruction Format**
+ R Type : All the operands are of register type.
+ I Type : One immediate value of 12 bit is use along with registers.
+ S Type : Stores value has immediate value and register.

#### Why are there only 32 registers in number?<br>
Because, all register has 5 bits of address, and **Total number of registers = 2^5 = 32 registers**.<br> 
These 32 registers are named as x0 till x31.<br>
and given some function.<br>
![Screenshot from 2023-08-20 17-30-37](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/0339c4e1-6464-4f9f-bb1b-b751f1496135)
<br>

## ABI function calls
Basic idea how we are going to call the function and execute the code.<br>
![C_to_ASM](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/71436b7f-51ea-4837-930f-1572f4443caa)
<br>

#### Code(Contain's the function call(load))
```
#include <stdio.h>

extern int load(int x, int y);

int main()
{
	int result = 0;
	int count = 9;
	result = load(0x0, count+1);//function call
	printf("Sum of numbers from 1 to %d = %d\n", count, result);
	
}
```
#### Assembly code of the above flow of instructions
```
.section .text
.global load
.type load, @function

load:
	add	a4, a0, zero //Initialize sum register a4 with 0x0
	add	a2, a0, a1   // store count of 10 in register a2. Register a1 is loaded with 0xa (decimal 10) from main
	add	a3, a0, zero // initialize intermediate sum register a3 by 0
loop:	add	a4, a3, a4   // Incremental addition
	addi	a3, a3, 1    // Incremental intermediate register by 1
	blt	a3, a2, loop // If a3 is less than a2, branch to label named <loop>
	add	a0, a4, zero // Store final result to register a0 so that it can be read by main program
	ret 
```

#### Executing the code<br>
![code](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/d1e75c68-2cfc-47aa-ad91-763f39829efb)
obj dump file<br>
![obj_dump](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/ebd5dca0-cd85-4d9a-93ea-86946585af58)
We can see some of the ABI are updated according to our load.S code.
<br>

## Running C program on RISC-V CPU
Before we can run the C program, we need to have the RISC-V CPU, testbench and other files.<br>
open terminal.<br>
```
git clone https://github.com/kunalg123/riscv_workshop_collaterals.git
```
```
cd riscv_workshop_collaterals/labs
```
We will abe able to see the files required installed.<br>
To run the code.<br>
```
chmod 777 rv32im.sh
```
```
./rv32im.sh
```
![Screenshot from 2023-08-20 19-59-59](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/d555d95c-f668-43d6-9539-99acfaff54c0)
<br>

Flow of ecexuting the code on RISC-V CPU<br>
![Screenshot from 2023-08-20 19-24-23](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/fd9b0343-b81f-4e64-b20f-74d34e42b28d)

**Later in this course we are going to build our RISC-V processor from scratch and run our C code.**
<br>
End of Day 2.
<br>
</details>

<details>
<summary>Week 2 -> Day 1 </summary><br>

## Contents of Day 1

* Introduction to Open Source Simulator - IVERILOG
* Lab using Iverilog and GTKWAVE
* Introduction to Yosys and Logic Synthesis
* Labs using Yosys and Sky130 library

## Introduction to Simulator(Open source)

+The verification of RTL design's compliance with specifications is accomplished through simulation of the design.<br>
+Simulator is used to simulate the design.<br>

We are going to use a **Simulator** known as **IVERILOG**.<br>

The Test Bench is used to check the **Functionality** if it is working as expected or not.<br>

- The design file is written in HDL(Hardware Descriptive Language - verilog or system verilog)
- The test bench is also written in HDL.

**The SIMULATOR works upon change in input and then the output will be EVALUATED.**<br>

#### + Working of TEST BENCH<br>

[Stimulus Generator] --inputs--> [Design] --outputs--> [Stimulus Observer]<br>

#### + Working of IVERILOG<br>

[[Design][Test bench]] --> [IVERILOG SIMU.] --> vcd file generation --> [GTK Wave]<br>

We use a software called GTK Wave for **viewing the ***output waveforms*****.<br>

## Installation and Lab of Iverilog and GTK Wave

+ Step 1 : Installation of **VSDFLOW**

Execute the following commands one after the another.<br>
```
sudo apt-get install git
```
```
git clone https://github.com/kunalg123/vsdflow.git
```
```
cd vsdflow
```
```
chmod 777 opensource_eda_tool_install.sh
```
```
sudo ./opensource_eda_tool_install.sh
```
```
./vsdflow spi_slave_design_details.csv
```
```
./vsdflow picorv32_design_details.csv
```
Please refer the below link if you face an issues.<br>
https://www.vlsisystemdesign.com/probable-errors-while-installing-vsdflow-and-its-solutions/<br>

+ Step 2 : Installation of Sky130 Library

Execute the following commands in another terminal one after the another.<br>
```
git clone https://github.com/kunalg123/sky130RTLDesignAndSynthesisWorkshop.git
```
After cloning, lets see what we have installed<br>
```
cd sky130RTLDesignAndSynthesisWorkshop/
```
To see all the design and respective testbench files
```
cd verilog_files
```
```
ls
```
![Screenshot from 2023-08-27 22-11-27](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/aef79242-651c-4600-a374-d809bf9a438c)
<br>
To see the library file
```
cd sky130RTLDesignAndSynthesisWorkshop/
```
```
cd my_lib
```
```
ls
```
![Screenshot from 2023-08-27 22-14-23](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/adc4698e-10d9-480f-9aa2-f4fe02df333b)

How to simulate the design in Iverilog (we are using god_mux.v as example which is already present in the verilog folder)<br>
```
iverilog good_mux.v tb_good_mux.v
```
The output is generated and stored in a.out file(which is default because we didnt specify any output file name)
```
./a.out
```
Next we are going to open the .vcd file in GTK wave
```
gtkwave tb_good_mux.vcd
```
Then we should drag the ports from the UUT into the signals region, and the zoom to fit the waveform so that we can view the entire waveform in less space.
![gtk_test_1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/5adce324-6967-45ad-8212-cd1d19c47d0a)

Next,<br>
Let us look into what is present in these design and testbench files
```
cd sky130RTLDesignAndSynthesisWorkshop/
```
```
cd verilog_files
```
```
gvim tb_good_mux.v -o good_mux.v
```
![Screenshot from 2023-08-27 15-58-42](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/ba9cb4d4-70f0-454b-8217-ba895a8be57d)


## Introduction to Yosys and Logic Synthesis

#### Installation of Yosys<br>

Run the below command in terminals to install **Yosys**.
```
git clone https://github.com/YosysHQ/yosys.git
```
```
cd yosys
```
```
sudo apt install make
```
```
sudo apt-get update
```
```
sudo apt-get install build-essential clang bison flex  libreadline-dev gawk tcl-dev libffi-dev git  graphviz xdot pkg-config python3 libboost-system-dev libboost-python-dev libboost-filesystem-dev zlib1g-dev
```
```
make config-gcc
```
```
make
```
```
sudo make install
```
After installation
```
yosys
```
![Screenshot from 2023-08-27 16-51-41](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/47c82b86-98f6-4ae5-a86d-b9efef1c424a)

show yosys is installed and version

#### Installation of GTK Wave

Run the below commands in terminal
```
sudo apt install gtkwave
```

#### **Introduction of YOSYS**

**Synthsizer** : Tool used for converting the RTL(Register Transfer Level) to netlistt.<br>

+ RTL - Anything that can be synthsisable.
+ Netlist - A textual description of a circuit made of components(such as gates, etc).

**YOSYS** : Synthsizer<br>

[[ Design ][ .lib ]] --> [ YOSYS ] --> [ Netlist file ]<br>

.lib - The file is an ASCII representation og the timing and power parameters associated with any cell in a particular foundry.<br>

**Working of Yosys**<br>
* Step 1 : To read the design.
```
read_verilog
```
* Step 2 : To read the .lib file.
```
read_liberty
```
* Step 3 : To write the output in netlist file from the synthesizer.
```
write_verilog
```

**NOTE : **<br>
The netlist file is the representation of the design in the form of standard cells(these cells come from the .lib file).<br>

How to verify th Synthesis?<br>
[[ Netlist ][ Test bench ]] --> [ IVERILOG ] --> [ VCD file ] --> [ GTK Wave ]<br>

Vcd file : comprises a header section with date, simulator, and timescale information; a variable definition section; and a value change section, in that order.(the output is in the form of wave).<br>

Iverilog is a "simulator"<br>
THe output must be same as RTL output.<br>

**NOTE :**<br>
The set of primary inputs / primary outputs will remain same betweeen RTL anf Netlist --> The same Test Bench can be used.(because of same primary inputs).<br>

#### **Logic Synthisis**

RTL DEsign -  Behavioral representation of requires specification.(verilog or system verilog code).<br>

[ RTL ] --> [ Synthesis ] --> [ Gate Level translation ]<br>
The design is cnverted into gates and conncetions is made.(aka NETLIST).<br>

.lib - Collection of logical modules, buckets of standard cells(different flavous, functionalities)<br>

Why different flavors of gate?<br>
Combinational delay in logic path determines the maximum speed f operaion of digital logic circuit.<br>

[ Flip flop A ] --> [Combinational Logic ] --> [ Flip flop B ]<br>

![Screenshot from 2023-08-27 23-44-31](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/882c682f-e53a-4c73-ad1c-08513ebf52a5)

What is the maximum speed it can work?<br>

What is the max clock rate?<br>

**Tclk** is one on and one off state.<br>

![Screenshot from 2023-08-27 23-45-02](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/9e0219c7-004d-4427-9d99-fdd3f34a65b9)

![Screenshot from 2023-08-27 23-44-19](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/5239a2f4-ea9d-4dcd-88c9-18a0aa738864)

tpcq - propagation delay of combinational circuit<br>

when the logic value is either in tpcq or tsetup then the **value must be stable**.<br>

f(clk,Max) = 1 / t(clk,min)<br>

For the circuit to work faster, we need lesser t(clk).<br>
Then we need **Faster working cells**.<br>

Then when do we need slow working cells?<br>

To prevent any missing of any values.<br>
To ensure that there are no HOLD time constraints at the next flip flop, we need the cells to work slowly.<br>

![Screenshot from 2023-08-27 23-45-21](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/7d035d49-c66f-4486-8bf8-ffd308108802)

![Screenshot from 2023-08-27 23-44-07](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/41fba451-fa28-4f6b-ac16-600dd684ec1e)

##### **Finally we have to choose which type of cells to use.**<br>

Charging and Discharging is done by capacitors in the circuits.<br>

| Faster cells | Slower cells |
| ------------ | ------------ |
| Wide transistors, low delay but needs more area and power. | Narrow transistors, more delay but requires less area and power. |

Hence we need to provide guidance to the sysntesizer which are called constraints.<br>

Synthesis steps :

1. Check syntax in code.
2. Mapping the ports.
3. Mapping the cells that can be used in the design.

## Labs using Yosys and Sky130 library

How to use Yosys<br>

change the directory to the location where the folder verilog_files is present.<br>
```
cd /sky130RTLDesignAndSynthesisWorkshop/verilog_files
```
then start yosys<br>
```
yosys
```

![Screenshot from 2023-08-27 16-51-41](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/3da71f2f-fb72-40f8-b0a9-881c5acaf078)

To read the lbrary file
```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
To read the design file
```
read_verilog good_mux.v
```
![Screenshot from 2023-08-27 16-53-20](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/a9fad7d3-2a97-4a1b-83ee-845c510ab946)

**We must get Successfully finished Verilog frontend.**<br>

To Synthesis the design
```
synth -top good_mux
```
syntax - synth -top <module_name><br>

![Screenshot from 2023-08-27 16-54-10](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/c6bbe6c3-0ec4-4c9c-975c-beb0a8f1ec6f)

To convert rtl to gates and what gates used in library or netlist.<br>
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
![Screenshot from 2023-08-27 16-56-12](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/6531fcd2-549d-4e74-9e88-e92ce37277fc)

To see the netlist
```
show
```
![Screenshot from 2023-08-27 16-56-35](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/b75febbc-5c77-4c9e-bebf-ad11d26d5491)

![Screenshot from 2023-08-27 16-49-57](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/99fac8f0-28db-425e-94fb-fbaa93ef66e2)

![WhatsApp Image 2023-08-28 at 00 29 10](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/cd76983d-ab61-449d-8458-cd23e0d5a9ce)

To view the netlist, we are going to write in another .v file<br>
```
write_verilog -noattr good_mux_netlist.v
```
Then to view the netlist code
```
gvim good_mux_netlist.v
```
![netlist_1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/d99311cd-9f05-4a14-8fc3-631ffc3bbd70)

or<br>

![netlist_2](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/90b04bf7-c5e6-4c72-888c-6941253fa6ca)

There are many ways to write the code form multiplexer but in our case it is using terenary operator -> [] ? [] : []<br>

</details>

<details>
<summary>Week 2 -> Day 2 </summary><br>

## Contents of Day 2

* Introduction to timing .lib
* Hierarchical vs Flat Synthesis
* Various Flop Coding styles and Optimsation

## Introduction to timing .lib

Lets go through library<br>
.lib is a collection of the standard cells, etc.<br>

To view .lib file, first we need to change the directory<br>
```
cd ~/sky130RTLDesignAndSynthesisWorkshop/verilog_files
```
Then type
```
gvim ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
![Screenshot from 2023-08-28 14-18-47](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/ce5bbfb3-2c49-48f3-85df-8c14bc3b759c)

To display the line numbers<>
Press **Shift + : **<br>
then
```
se nu
```

To turn off the syntax check<br>
Press **Shift + : **<br>
then
```
syn off
```

**NOTE : We must not Edit this file.** <br>

***Now Lets us Understand the name of our library file.*** <br>

![Screenshot from 2023-08-28 14-27-53](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/f9653a8d-1f4a-442e-8fff-e5e238f0d56f)

+ **sky130** : The library is using 130nm foundry.<br>
+ **tt** : typical process<br>
+ **025C** : 25 degree Celcius temperature.<br>
+ **1v8** : Voltage<br>
+ **Technology** : CMOS<br>
+ **Delay model** : lookup table<br>

#### Units
+ **time units** : 1ns<br>
+ **Voltage units** : 1V<br>
+ **Leakage Power units** : 1nW<br>
+ **Current unit** : 1mA<br>
+ **Pulling resistance units** : 1Kohms<br>
+ **Capacitance units** : 1pF<br>

![Screenshot from 2023-08-28 14-28-05](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/ad3f1ad9-e1d9-4217-962f-6404423bbbfb)

+ **Operations Conditions :**<br>
voltage : 1.8<br>
processor : 1.00<br>
temperature : 25.00<br>
tree_type : balanced tree<br>

![Screenshot from 2023-08-28 14-28-23](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/2ec2d903-e65d-4b30-b0b6-dbfd3c0ce64b)

#### **PVT : Process Voltage Temperature**
PVT is very important for the design to work.<br>

* **Process Variation** : Variation due to fabrication, we wont get exacty same fabrication output everytime. There would be some variations(very small).<br>
* **Voltage Variation** : When we vary voltage there is going to be variation in the behavior of the circuit.<br>
* **Temperature Variation** : Semiconductors are very sensitve to temerature.<br>

PVT determines how my IC is going to work, either faster or slower.<br>

No matter any variations we wat the IC to work without any issues or without any change in the expected output.<br>
eg. Amplifer, we are usign mos in the ampifer which is sensitive to temperature, if we are using the amplifer either in Thar desert or Himalayas we need it work as expected.<br>

**There for we need to factor in the variations while we are designing the circuit.** <br>

Library is having cells, to view them<br>
Press **/**<br>
then
```
cell 
```
we are to view a cell 
* leakage power of all combinaions of inputs(we will have 32 combinations because 5 input, 2^5=32)

![Screenshot from 2023-08-28 14-45-36](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/70ff14f4-afeb-4f57-ab0c-ff05fe59b339)

* Capacitance and internal power of ports  and Area

![Screenshot from 2023-08-28 14-45-52](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/b05baedb-1d7d-487f-afab-b25a0cf49c77)

* Timing

![Screenshot from 2023-08-28 14-46-44](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/d561e235-9205-4357-ac4a-07920e333b53)

To see the verilog model of the cell<br>
```
sp ../my_lib/verilog_mode/sky130_fd_sc_hd__a2111o.behavioral.v
```
(🟥NOTE🟥: The below three images of verilog modules are from **gedit text editor** and not gvim as it wasnt showing me the verilog module, you can use the above code in gvim if it works for you.)<br>

![Screenshot from 2023-08-28 15-16-31](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/722b33d9-3cc7-46dc-b751-7e147e02b09a)

![Screenshot from 2023-08-28 15-17-43](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/781d0748-0782-43e1-8eb7-9407f38dd167)

![Screenshot from 2023-08-28 15-18-21](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/721c221f-a2ba-4d5e-90e1-55ead02caff6)

To search a word in gvim
```
/<word you want to search>
```
**Comparing the types of flavors of a cell(and2)** <br>
type in gvim
```
:vsp
```
then
```
:vs
```
and one more time
```
:vs
```
Then we would have threee windows of the same file.<br>

In each page search **and2_0**, **and2_2**, **and2_4**

![Screenshot from 2023-08-28 15-42-24](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/daf3c93e-b60d-477d-a660-3cd8493cedff)

We can observe that the area of and2_0 is smaller than and2_4.<br>

**Larger Area** => Wider trasistors => less delay(faster charging and discharging of capacitors, but occupies more area and draws more power.)<br>

**Smaller Area** => Narrower transistors => more delay(slower charging and dischaging of capacitors, occupies less area and uses less power.)<br>

The verilog module of and2<br>
(🟥NOTE🟥 : The below  image are from gedit text editor and not gvim as it wasnt showing me the verilog module)<br>

![Screenshot from 2023-08-28 15-19-39](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/fe70c728-5345-4f83-b415-76c22ebe511a)

## Hierarchical vs Flat Synthesis

What is meant by synth -top?<br>
With this command we can synthesize the entire top module or indivisual module
> synth -top <module_name>

We are also going to see what is **hierarchial and flatten synthesis** :<br>

we are going to use multiple_modules.v<br>

```
cd ~/sky130RTLDesignAndSynthesisWorkshop/verilog_files
```
```
gvim mulitple_modules.v
```

![1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/76662b8a-9f8c-4a8a-bc3c-b839e133eaee)
![WhatsApp Image 2023-09-03 at 16 25 04](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/c6b8a89f-5971-4c37-8ebb-4d53e2ffb2c9)

Then lauch yosys
```
yosys
```
reading library
```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
reading verilog file
```
read_verilog multiple_modules.v
```
![2](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/5a27faa6-d3a8-4425-a913-de987b9477fd)
![3](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/5098451d-c840-4e7d-bffd-e6f2fdd56761)

synthesizing the code
```
synth -top multiple_modules
```
linking design to library
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
to dsplay the design
```
show multiple_modules
```
![hier_dsgn_4](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/7eb4ca53-3063-42c1-ba3f-61932a0e3d57)

writing out the netlist
```
write_verilog -noattr multiple_modules_hier.v
```
to view the netlist
```
!gvim multiple_modules_hier.v
```
![6](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/2d37066f-f39c-4438-a850-2f9ce7019b5b)
![7](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/d16b5ab5-0366-405f-9f05-4e9411e4d688)

The above netlist code is from the hierarchial synthesis.<br>

now lets go to flatten<br>
```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
read_verilog multiple_modules.v
```
```
synth -top multiple_modules
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
now we need to flatten the netlist
```
flatten
```
```
write_verilog -noattr multiple_modules_flat.v
```
```
!gvim multiple_modules_flat.v
```
![89](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/2cba67a1-5e66-4ac3-9dfb-5527f2849cea)
```
show
```
![flat_dsgn_11](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/3a05fcef-aaba-4dee-aea5-221ba0ad78dd)

In the flattened netlist we cant see submodules being initialised as in hierarchial.(Everything is initialised under multiple_modules)<br>

To synthesize indvidual module
```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
read_verilog multiple_modules.v
```
```
synth -top sub_module1
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![Screenshot from 2023-09-03 16-00-01](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/d216b5d2-ed55-4511-b408-d05fbd54c4a7)

## Various Flop Coding styles and Optimsation

#### Why are Flip Flops used?

for example if we are having a combinational circuit should be givving an stable output for the previous inputs and next inputs, but due to different delays of the cells inside could change the output value, which is called as **Gitches**. And if there are many other combinational circuit is series then there would be more glitches.
These glitches could change the entre expected output.
To prevent these glitches from happening we use flip flops in between the combinational circuits and which will give the output at the positive edge or negative edge of the clock and would be stable untill the next clock, by this method all the glitches are reduced.
The initial state of flip flops can be set either using **Reset or Set** and the also we have **synchronous and Asynchronous**.
* Synchronous - the output will be reset or set only at the edge of clock
* Asynchronous -  the output will be reset or set immediately when reset or set is high.

Different Types of Flip Flops:<br>
1. Synchronous Reset D Flip Flop
2. Asynchronous Reset D Flip Flop
3. Asynchronous and Synchronous Reset D Flip Flop

![WhatsApp Image 2023-09-03 at 17 37 08](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/102d8f17-c8d3-4391-822b-f3085869bc57)

![1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/0bfbe092-f1dc-417a-8021-7fad23e2a20c)

![2](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/4e5d2578-4c7b-467a-8dba-45b2591c52c6)

![3](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/127c9ce1-ace8-417e-82d2-fbb83b944e7b)

The always statement is evaluated only if there is change in the value of the elements of **Sensitivity List**.<br>

Lets check the waveforms of the D flip flops

![Screenshot from 2023-09-03 18-36-54](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/7c414c0e-7a8a-403b-af45-408139e7b017)

+ D flip flop with Asynchronous Reset(dff_asyncres)
![Screenshot from 2023-09-03 18-26-49](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/a809c943-f913-4a50-b9c2-26191d9a8400)
![Screenshot from 2023-09-03 18-27-03](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/349b0135-c282-4fd0-9b97-753d91eea9ce)
![Screenshot from 2023-09-03 18-27-14](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/73e52d50-c500-4ec8-8155-a3cbfdb74245)

+ D flip flop with Asynchronous with Set(dff_async_set)
![Screenshot from 2023-09-03 18-28-45](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/b7adf6dd-a842-42d6-aea5-fdfb1ed0f3be)
![Screenshot from 2023-09-03 18-28-52](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/b67a656c-8cd6-478e-8753-db1d5b7b5f5a)
![Screenshot from 2023-09-03 18-30-05](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/a11dacf5-0267-4f3a-b125-fb6b3304012f)

+ D flip flop with Synchronous Reset(dff_syncres)
![31](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/c80a17d3-203f-4e33-853d-04d57d044ac0)
![32](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/55e9e555-c30f-426c-ae1c-0c2169f62beb)

+ D flip flop with Asynchronous and Synchronous Reset(dff_asyncres_syncres)
![41](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/02f8d1b2-06e6-41f5-81ff-a6873f903f98)
![42](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/ab6c6c0d-7c95-4ef0-aec2-1422b4782d6c)

Checking the Design of Flip Flops
```
cd ~/sky130RTLDesignAndSynthesisWorkshop/verilog_files
```
```
yoys
```
```
read_liberty -lib  ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
+ D flip flop with Asynchronous Reset(dff_asyncres)
```
read_verilog dff_asyncres.v
```
```
synth -top dff_asyncres
```
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![11](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/5b92e680-953e-4f64-ad63-b541fc0c3b28)

+ D flip flop with Asynchronous with Set(dff_async_set)
```
read_verilog dff_async_set.v
```
```
synth -top dff_async_set
```
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![21](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/34b83f55-3e4d-46e0-b037-8ba9cdf16691)

+ D flip flop with Synchronous Reset(dff_syncres)
```
read_verilog dff_syncres.v
```
```
synth -top dff_syncres
```
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![31](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/f1d26b91-964c-456b-beb0-65b949ead28d)

![WhatsApp Image 2023-09-03 at 19 16 00](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/b5984ac6-796d-4e6c-b943-d597988fe1e0)

+ D flip flop with Asynchronous and Synchronous Reset(dff_asyncres_syncres)
```
read_verilog dff_asyncres_syncres.v
```
```
synth -top dff_asyncres_syncres
```
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![41](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/b9dfeced-da06-4593-b134-3ae4f3ebaf92)

Multiplication Circuit
```
gvim mult_*.v -o
```
```
yosys
```
```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
read_verilog mult_2.v
```
```
synth -top mul2
```
![11](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/967ddd36-0d0e-42c0-959f-fe910c7e4151)

```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
![12](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/66f2de11-7965-4ff7-bd21-50338cd7cf66)

```
show
```
![13](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/b602bdba-55cc-4fc6-8edc-225268354950)

```
read_verilog mult_8.v
```
```
synth -top mult8
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![2](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/a389e259-1214-4ffc-8917-82f87a18028d)

For multiplication by 2 we are adding one binary 0 at the end of orignial binary value (LEFT SHIFT)

| INP(%b) | INP(%d) | OUTP(%b) | OUTP(%d) |
|-----|------|-----|-----|
| 000 | (0) | 0000 | (0) |
| 001 | (1) | 0010 | (2) |
| 010 | (2) | 0100 | (4) |
| 011 | (3) | 0110 | (6) |
| 100 | (4) | 1000 | (8) |
| 101 | (5) | 1010 | (10) |
| 110 | (6) | 1100 | (12) |
| 111 | (7) | 1110 | (14) |

similary for mult_8 we have to add 3 binary 0 to the end of the orignal binary value.<br>

Now lets see multiplication of a number by 9.
![WhatsApp Image 2023-09-03 at 20 33 35](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/90f725d4-8f30-4863-8f43-6cd30e38a63f)
```
yosys
```
```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
read_verilog mult_8.v
```
```
synth -top mult8
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![show](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/67eb59fa-1e8e-4f0e-b3f8-53db32c04114)
```
write_verilog -noattr mult8_net.v
```
```
gvim mult8_net.v
```
![net](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/45a02ad8-84dc-42ed-b999-6ce475443a48)

End of Week 2 Day 2

</details>

<details>
<summary>Week 2 -> Day 3 </summary><br>

## Contents of Week 2 Day 3
1. Introduction to Optimisation.
2. Combinational Logic Optimisation.
3. Sequential Logic Optimisation.
4. Sequential Optimisation for unused outputs.

## Introduction to Optimisation

### Logical Optimisation
There are two types of optimisations, combinational and sequential logic optimisation

Combinational logic optimisation
* squeez the logic to get the most effectient design, Area and Power saving.
* Constant Propagtion
	* Direct Optimisation
* Boolean Logic Optimisation
	*K amp
	* Quine McKluskey

### Constant Propagation example
Y=((AB)+C)'<br>
if A or B = 0<br>
then Y = C'<br>
which can simplified into an inverted with input C<br>
![cpeg](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/3c2f445f-13d8-4ca2-add1-f404ca6588f9)

and the original circuit uses 6 Transistors and while the inverter only uses 2 Transistors, we have saved in area and power.<br>

### Boolean Logic Optimsation
assign y = a?(b?c:(c?a:0)):(!c)<br>

this terenary operator statement has boiled down to a xnor gate.<br>

### Sequential Logic optimisation
* Basic
	* Sequential constant propagation 
* Advanced(not part of our course)
	* State optmisation
	* Retiming
	* Sequentil logic cloning(Floor plan aware synthesis)

Sequential Constant Propagation
Assume we have a D flip flop with reset, and the input is 0.<br>
when Reset = 1, Q = 0<br>
When Reset = 0, Q = D = 0<br>
No matter during the reset or clock the output of flip flop is always 0.<br>
then we can use q = 0.

similary if we a SET D flip flop, we cant assign Q = 0, because<br>
when Set = 1, Q = 1<br>
When Set = 0, Q = D = 0<br>
Here we need to use the flip flop itself, because the output of D flip flop is not at a stable value.<br>

* State Optimization: State optimization is a technique in sequential logic design where unused or redundant flip-flops (state elements) in a digital circuit are identified and removed to reduce the hardware's complexity and power consumption, without affecting its functionality.<br>

* Retiming: Retiming is a sequential logic optimization method that involves rearranging the placement of flip-flops in a digital circuit to improve its critical path timing, making it faster while maintaining the same functionality and minimizing the need for additional hardware.<br>

* Sequential Logic Cloning: Sequential logic cloning is a technique that duplicates specific parts of a circuit to create multiple parallel paths for data processing. This can enhance performance by allowing for parallel processing of data, but it may increase hardware complexity and power consumption.<br>

## Combinational Logic Optimisation
Multiplexer and other logic based on input are being simplified into basic gates.<br>
![code](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/25ee71c9-7629-43a0-964d-a2faa30b79c4)

![code2](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/ff9b8315-fff1-4b19-be7e-1c55c04da47b)

```
cd ~/sky130RTLDesignAndSynthesisWorkshop/verilog_files
```
```
yoys
```
```
read_liberty -lib  ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
**opt_check.v**
```
read_verilog opt_check
```
```
synth -top opt_check
```
```
opt_clean -purge
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![oc1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/c420430c-4a73-47dc-8ffd-d7c64ea3a3c9)


**opt_check2.v**
```
read_verilog opt_check2
```
```
synth -top opt_check2
```
```
opt_clean -purge
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![oc2](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/cfa97c58-b7ec-464b-a283-3dfb8a75b331)

**opt_check3.v**
```
read_verilog opt_check3
```
```
synth -top opt_check3
```
```
opt_clean -purge
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![oc3](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/bc2a49e8-a9db-4daa-bc80-dfcde0c75e4a)

**opt_check4.v**
```
read_verilog opt_check4
```
```
synth -top opt_check4
```
```
opt_clean -purge
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![oc4](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/8d302f65-a3c1-4c88-a1c2-ed3e528e9ca0)

**multiple_module_opt.v**
```
read_verilog multiple_module_opt
```
```
synth -top multiple_module_opt
```
```
flatten
```
```
opt_clean -purge
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![mo1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/80f1be7e-2817-49ae-8dcc-c51d4a2d874a)


**multiple_module_opt2.v**
```
read_verilog multiple_module_opt2
```
```
synth -top multiple_module_opt2
```
```
flatten
```
```
opt_clean -purge
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![mo2](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/73e377fe-d0a6-444c-bcf7-f32003f708b2)

## Sequential Logic Optimisation.
We are going to see the optimisation of sequential logic which is having d flip flops<br>

code of dff_const<br>

![code_1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/35544a87-39dd-42a3-ac8f-6e8385ee1d81)
![code_2](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/76898070-0ed6-4c8d-8e48-b5f12edf6030)

![gtkcode1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/2fb71c98-2379-46fd-8e76-7f64824c9c59)
![gtkcode2](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/766584bf-7062-47a2-9dbc-a2f9d7fca112)

![gtk1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/77c3c37b-7c03-419d-8255-9b041e5c7ba2)
![gtk2](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/0af333e2-0502-4ecf-8874-936032446482)
![gtk3](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/e968cf1d-c9f7-4c12-ba08-780952c7ca14)
![gtk4](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/60363019-a909-4f59-abdd-1d218650ad5d)
![gtk5](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/1f4184e3-b092-40ea-9b51-e8ab5823c10d)

```
yosys
```
```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
**dff_const1.v**
```
read_verilog dff_const1.v
```
```
synth -top dff_const1
```
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![s1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/ca086f46-4128-4eb7-9752-09bd958081e3)

**dff_const2.v**
```
read_verilog dff_const2.v
```
```
synth -top dff_const2
```
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![s2](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/828bb066-220e-47e4-9c8d-c85963d2457b)

**dff_const3.v**
```
read_verilog dff_const3.v
```
```
synth -top dff_const3
```
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![s3](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/e720930e-0b46-4a6f-922f-847f59340746)

**dff_const4.v**
```
read_verilog dff_const4.v
```
```
synth -top dff_const4
```
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![s4](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/4e60cd2a-0c26-402e-898d-92dc05b89a6a)

**dff_const5.v**
```
read_verilog dff_const5.v
```
```
synth -top dff_const5
```
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![s5](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/033c4b2f-b887-4776-bf30-263bbd54bf8e)

## Sequential Optimisation for unused outputs.

Now we are going to see the optimisation of unused logic.<br>
3 bit Up counter<br>
the 3 bit upcounter uses 3 flip flops but we are using only one bit of output and leaving the other 2 bits unused, and those unused 2 flipflops are removed and only one is being used.<br>

![code_c1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/dbd62ed8-f157-47d1-852e-2979f583f689)

```
cd ~/sky130RTLDesignAndSynthesisWorkshop/verilog_files
```
```
yoys
```
```
read_liberty -lib  ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
read_verilog counter_opt.v
```
```
synth -top counter_opt
```
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![c1_show](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/a4d8a5e2-364d-4800-a649-e4b4a96b56ca)

from the above image we can observe only on flip flop is being used.<br>

now lets see what will happen is 3 bit of output are used.<br>
(outside yosys)<br>

```
cd ~/sky130RTLDesignAndSynthesisWorkshop/verilog_files
```
```
cp counter_opt.v counter_opt2.v
```
```
gvim counter_opt2.v
```
change the output to 3 bit
```
module counter_opt (input clk , input reset , output q);
reg [2:0] count;
assign q = (count[2:0] == 3'b100);

always @(posedge clk ,posedge reset)
begin
	if(reset)
		count <= 3'b000;
	else
		count <= count + 1;
end
endmodule
```
![c2_code](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/d621741c-2a7c-47a9-9754-fc2fd5a262c4)

```
yosys
```
```
read_verilog counter_opt2.v
```
```
synth -top counter_opt
```
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
show
```
![c2_show](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/53153edd-33bb-4a66-a2f8-800f53e18542)

![c_exp](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/f369d5a8-2fef-444d-b283-034c04dd7e12)
The expression is Q = <br>
Q = ((count[0])+(count[1])+(count[2])')'<br>
Q = (count[2]).(count[1])'.(count[2])'

End of Week 2 Day 3.
</details>

<details>
<summary> Week 2 -> Day 4 </summary><br>
	
## Contents of Day 4
* GLS, Synthesis-Simulation mismatch and Blocking/Non-blocking statements
* Labs on GLS, Synthesis-Simulation mismatch
* Labs on Synthesis-Simulation mismatch and Blocking/Non-blocking statements

## GLS, Synthesis-Simulation mismatch and Blocking/Non-blocking statements

GLS -Gate Level Simulation
Gate-level simulation, often referred to as GLS (GLS-Gate Level Simulation), is a critical step in electronic design verification. It assesses the functionality and timing of a digital circuit at the gate level, providing a more accurate representation of hardware behavior compared to higher-level abstractions. GLS ensures that the synthesized netlist, comprising logic gates and flip-flops, behaves as intended and meets timing constraints, enhancing the reliability of integrated circuits in various applications, from consumer electronics to aerospace systems.<br>

* Running the test bench with Netlist as Design Under Test
* Netlist is logically same as RTL Code.
	* Same Test Bench will align with the Design
	
Why do we need GLS?
* Verification is logic is correct or not.
* Ensuring the timing of the design is met.
	* For this GLS needs to be run with delay annoations.(not now)

![iv_wok](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/990a261d-1135-4650-8c04-bd2b8ad5611c)

Note: If the Gate level Models are delay annotated, then we can use GLS for timing vadiation


Synthesis Simulation Mismatch could happen because of the following:
* Missing Sensitivity list
* Blocking vs Non Blocking Assignments
* Non Standard Verilog Coding

### Missing Senstivty list
always statement gets evaluated if there is change in the value of sensitivity list and if any port is missing the always statement wouldnt get executed and would result in a different result.<br>

to prevent this we can use always@(*), which will evaluate is there is any change in the inputs.<br>

### Blocking and Non Blocking Statements in Verilog

Inside always block

* = --> Blocking
	* Executes the statements in the order it is written in.
	* First satement is evaluated  before the next statement.
* <= --> Non Blocking
	* Executes all the RHS when always block is entered and assigns to RHS
	* Prallel Evaluation
	

To prevent error use **non blocking statments for writing sequential cicuits**.<br>


## Labs on GLS, Synthesis-Simulation mismatch

```
cd ~/sky130RTLDesignAndSynthesisWorkshop/verilog_files
```
```
iverilog ternary_operator_mux.v tb_ternary_operator_mux.v 
```
```
./a.out
```
```
gtkwave tb_ternary_operator_mux.vcd
```
![er_iv_gtk](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/82b7a738-20ff-4cbd-86af-aae75ef7c358)

```
yosys
```
```
read_liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
read_verilog ternary_opertator_mux.v
```
```
synth -top ternary_operator_mux
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
write_verilog -noattr ternary_opertator_mux_net.v
```
```
show
```
![s1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/dd87c4c5-d214-4836-bf27-708e5910f081)

to invoke the GLS<br>
come outside yosys<br>
```
iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v ternary_operator_mux_net.v tb_ternary_operator_mux.v 
```
```
./a.out
```
```
gtkwave tb_ternary_operator_mux.v
```
![gls_gtk1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/734c0d56-0307-4197-bb98-20f2f39d9f9c)

next
```
cd ~/sky130RTLDesignAndSynthesisWorkshop/verilog_files
```
```
iverilog bad_mux.v tb_bad_mux.v 
```
```
./a.out
```
```
gtkwave tb_bad_mux.vcd
```
![ive_gtk_2](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/dae45a44-7aef-42e4-89be-88e7f6d172ae)

```
yosys
```
```
read_liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
read_verilog bad_mux.v
```
```
synth -top bad_mux
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
write_verilog -noattr bad_mux_net.v
```
```
show
```
![s2](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/fba71373-b584-4fdf-b2fe-41db8cb1a85b)


to invoke the GLS<br>
come outside yosys<br>
```
iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v bad_mux_net.v tb_bad_mux.v 
```
```
./a.out
```
```
gtkwave tb_bad_mux.v
```
![gls_gtk2](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/14e2d60a-be3a-4d69-93f4-65a574889c4a)

We can observe that is GLS we are getting the expected output.

## Labs on Synthesis-Simulation mismatch and Blocking/Non-blocking statements

```
cd ~/sky130RTLDesignAndSynthesisWorkshop/verilog_files
```
```
iverilog blocking_caveat_net.v tb_blocking_caveat_net.v
```
```
./a.out
```
```
gtkwave tb_blocking_caveat_net.v
```
![gtk_1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/840fbf8d-f5be-47df-a583-bd9a93fc9e8f)


```
yosys
```
```
read_liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
read_verilog blocking_caveat.v
```
```
synth -top blocking_caveat
```
```
abc -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
```
write_verilog -noattr blocking_caveat_net.v
```
```
show
```
![s1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/49864a8c-fba1-4544-978c-cd93852b159e)

to invoke the GLS<br>
come outside yosys<br>
```
iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v  blocking_caveat_net.v tb_blocking_caveat.v
```
```
./a.out
```
```
gtkwave tb_blocking_caveat.v
```
![gls_gtk_1](https://github.com/vamsi-2312/pes_asic_class/assets/142248038/758c3559-3586-4715-9ccb-f85ce7928f33)

We can observe the difference in betweeen the normal gtkwave waveforms and gls waveforms.<br>
Hence we need to be very very careful while useing bocking and non blocking statements.<br>

</details>

<details>
	
<summary> Week 3 </summary><br>
Physical Design part of our course is updated in this repository https://github.com/vamsi-2312/pes_pd
</details>
