# SPIMCORE

A program that simulates the MIPS Single Cycle datapath.

## Compilation

The files `spimcore.c` and `project.c` should be compiled together.
Using gcc, this can be done by the following command:

```sh
gcc -o spimcore project.c spimcore.c
```

## Usage

To start the simulator, run the following command in a UNIX environment:

```sh
./spimcore <filename>.asc
```

A command prompt

`cmd:`

should appear. The simulation works with the following commands (case independent):

| Key | Meaning                                                           |
|-----|-------------------------------------------------------------------|
| r   | “Register” - Display register contents                            |
| m   | “Memory” - Display memory contents                                |
| s   | “Step” – Attempt to run the instruction located at the current PC |
| c   | “Continue” – Attempt to run all instructions, beginning with PC   |
| h   | “Halt” – Check to see if the simulation has halted                |
| p   | “Print” – Prints a copy of the input file                         |
| g   | “Controls” – Display the most recent control signals              |
| x   | “Quit” – terminate the simulation                                 |

## Format of input files

The input file should contain hexadecimal formatted MIPS machine codes.
Text after # on any line is treated as comments.

```
20010000    # addi $1, $0, 0
200200c8    # addi $2, $0, 200
10220003    # beq $1, $2, 3
00000020    # delay slot
20210001    # addi $1, $1, 1
00000020    # noop
```

The simulation ends when an illegal instruction, such as 0x00000000, is encountered.
