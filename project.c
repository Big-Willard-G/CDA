#include "spimcore.h"


/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{
	unsigned Z;

	// Compute operation according to ALUControl
	switch (ALUControl)
	{
		case 0:
			// Z = A + B
			Z=A+B;
			break;
		case 1:
			// Z = A - B
			Z=A-B;
			break;
		case 2:
			// if A < B, Z = 1; otherwise, Z = 0
			Z=A<B;
			break;
		case 3:
			// if A < B, Z = 1; otherwise, Z = 0 (unsigned)
			Z=A<B;
			break;
		case 4:
			// Z = A AND B
			Z=A&B;
			break;
		case 5:
			// Z = A OR B
			Z=A|B;
			break;
		case 6:
			// Z = Shift B left by 16 bits
			Z=B>>16;
			break;
		case 7:
			// Z = NOT A
			Z=~A;
			break;
		default:
			// Not a valid ALUControl
			break;
	}

	// Output the result (Z) to ALUResult
	*ALUResult == Z;

	// Assign Zero to 1 if the result is zero; otherwise, assign 0
	if (Z == 0) 
	{
		*Zero = 1;
	}
	else
	{
		*Zero = 0;
	}
}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{
	*instruction = *(Mem + PC);

	// Check halt condition
	if (*instruction == 0) return 1;

	return 0
}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{
	*op	= instruction >> 26;
	*r1	= (instruction & 00000011111000000000000000000000) >> 21;
	*r2 	= (instruction & 00000000000111110000000000000000) >> 16;
	*r3 	= (instruction & 00000000000000001111100000000000) >> 11;
	*offset = (instruction & 00000000000000000000011111000000) >> 6;
	*funct	= (instruction & 00000000000000000000000000111111);
	*jsec	= (instruction & 00000011111111111111111111111111) >> 6;
}



/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{
	switch (op)
	{
		default:
			// Not a valid op code
			break;
	}
}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{

}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{

}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{

}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{

}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{

}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{

}

