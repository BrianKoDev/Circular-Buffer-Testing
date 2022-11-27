/*
* File: test.c
* Title: Demonstrate operation of circular buffer with automated testing
* Version: 0.2
* Created: 16/11/2019
*

*/

// allow portable types
#include <stdint.h>
#include <stdio.h>

//change to set test data
#include "Test_BufferOverflow.h"

//access functional prototypes
#define BUFFER_LENGTH 10


//initialize counts
int operation_count = -1;
int input_data_count = -1;
int flag=0;

//function to get operation selection
int MenuTest(void){
	operation_count++;
	return(select_operation[operation_count]);
}

//function to get input data into buffer (Produce)
int ProduceTest(void){
	input_data_count++;
	return(input_data[input_data_count]);
}
	
//function to check current state of buffer against expected state
void BufferTest(int buffer_state[]){

	for (int i=0;i<BUFFER_LENGTH;i++)//check each element in buffer
	{
		if ((buffer_state[i])!=(expected_buffer[operation_count][i]))
			{
				flag=1;
			}
	}
}

void PrintResults(void){
		if (flag == 0) printf("Program passed test as specified in test data file.\n\n"); //print message if matches
		else printf("ERROR! Test Failed,  Program does not passed test as specified in test data file. \n\n"); //print error if not match	
}
	
