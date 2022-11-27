/*
* File: Test_Consume.h
* Title: This file tests for the consume operation by first producing 3 sets of data into the array the consuming 2
* Version: 0.2
* Created: 16/11/2019
*
*/


#define BUFFER_LENGTH 10
//modify select_operation to change sequences of operation
int select_operation[] = {1,1,1,2,2,4};

//modify input_data to change value when entering (produce) data into buffer
int input_data[] = {1,2,3};

//modify expected buffer to the expected contents in buffer after each operation
int expected_buffer[][BUFFER_LENGTH] = {
{0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,0},
{1,2,0,0,0,0,0,0,0,0},
{1,2,3,0,0,0,0,0,0,0},
{2,3,0,0,0,0,0,0,0,0},
{3,0,0,0,0,0,0,0,0,0},
};
