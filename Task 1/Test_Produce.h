/*
* File: Test_Produce.h
* Title: This file tests if the program can produce correctly, by adding 3 sets of data into the buffer
* Version: 0.2
* Created: 16/11/2019
*

*/


#define BUFFER_LENGTH 10
//modify select_operation to change sequences of operation
int select_operation[] = {1,1,1,4};

//modify input_data to change value when entering (produce) data into buffer
int input_data[] = {1,2,3};

//modify expected buffer to the expected contents in buffer after each operation
int expected_buffer[][BUFFER_LENGTH] = {
{0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,0},
{1,2,0,0,0,0,0,0,0,0},
{1,2,3,0,0,0,0,0,0,0},
};
