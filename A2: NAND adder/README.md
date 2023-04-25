## A2: NAND adder

### Abstract
The foundation of the fabricating processes that make the computers you use daily is the ability to represent anything computable as NANDs only. Reducing all computation to one type of gate results in incredible economies of scale that makes it feasible to create very high density and efficient CPUs.

### Introduction
We've learned about digital logic and functional completeness, however seeing can be quite a bit more convincing than just believing. For this project, you'll implement a series of logical functions using only NOT and NAND. Once you have built AND, OR and XOR, you'll see that a full adder can be implemented using only the NAND-based logic you built. If a full adder works, then we have both addition and subtraction (presuming twos complement).

### Methodology
In nandAdder.c in the "Files / A2" directory I've built a basic framework for you. You have NAND and I've implemented NOT using NAND. I've also stubbed out the three other logical functions you need to implement. The interface to each function is a truth value as 1 or 0 and each should return a 1 for true and a 0 for false. I've also implemented a full adder as two half adders with overflow detection.

In order to help you develop your logical functions I've built a diagnostic mode in to nandAdder.c.

The order of the arguments is A, then B. In diagnostic mode, you'll get the truth value your functions have computed, then the actual truth value. By default the functions send back false (i.e. '0').
        
To turn on diagnostic mode, use the switch '-d' before you supply your two inputs:
e.g.:

    ./a.out -d 0 0
    ****************Diagnostic mode*****************
    Initialized with bits:
    A: 0  B: 0

    Computed                Actual
    not A: 1                1
    not B: 1                1
    A and B: 0              0
    A or B: 0               0
    A xor B: 0              0
    ************************************************
    
    
    ./a.out -d 0 1
    ****************Diagnostic mode*****************
    Initialized with bits:
    A: 0  B: 1

    Computed                Actual
    not A: 1                1
    not B: 0                0
    A and B: 0              0
    A or B: 0               1
    A xor B: 0              1
    ************************************************
    
    
    ./a.out -d 1 1
    ****************Diagnostic mode*****************
    Initialized with bits:
    A: 1  B: 1

    Computed                Actual
    not A: 0                0
    not B: 0                0
    A and B: 0              1
    A or B: 0               1
    A xor B: 0              0
    ************************************************

You may only use the NAND and NOT I've provided to define the other logic gates. You may not use any of the built-in C logical or bitwise or mathematical operators, including but not limited to: !, ||, or &&. 

Once your logic is testing as correct, call the executable without the '-d' to turn on compute mode. Compute mode takes three arguments: A, B and a carry in bit.


    ./a.out 0 1 0
    ================Compute mode====================
    Initialized with bits:
    A: 0  B: 1  Cin: 0

    Computed Result:
        bit: 1
    overflow:  0
    ================================================


    ./a.out 1 1 0
    ================Compute mode====================
    Initialized with bits:
    A: 1  B: 1  Cin: 0

    Computed Result:
        bit: 0
    overflow:  1
    ================================================


    ./a.out 0 0 1
    ================Compute mode====================
    Initialized with bits:
    A: 0  B: 0  Cin: 1

    Computed Result:
        bit: 1
    overflow:  0
    ================================================


    ./a.out 1 1 1
    ================Compute mode====================
    Initialized with bits:
    A: 1  B: 1  Cin: 1

    Computed Result:
        bit: 1
    overflow:  1
    ================================================



## Submission
Submit your fully functional nandAdder.c code on or before the due date.
