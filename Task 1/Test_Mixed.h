/*
* File: Test_Mixed.h
* Title: This file tests for a combination of produce, consume operations which sometimes triggers buffer overflow
* Version: 0.2
* Created: 16/11/2019
*

*/


#define BUFFER_LENGTH 10
//modify select_operation to change sequences of operation
int select_operation[] = {1,1,1,2,2,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,4};

//modify input_data to change value when entering (produce) data into buffer
int input_data[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

//modify expected buffer to the expected contents in buffer after each operation
int expected_buffer[][BUFFER_LENGTH] = {
{0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,0},
{1,2,0,0,0,0,0,0,0,0},
{1,2,3,0,0,0,0,0,0,0},
{2,3,0,0,0,0,0,0,0,0},
{3,0,0,0,0,0,0,0,0,0},
{3,4,0,0,0,0,0,0,0,0},
{4,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{5,0,0,0,0,0,0,0,0,0},
{5,6,0,0,0,0,0,0,0,0},
{5,6,7,0,0,0,0,0,0,0},
{5,6,7,8,0,0,0,0,0,0},
{5,6,7,8,9,0,0,0,0,0},
{5,6,7,8,9,10,0,0,0,0},
{5,6,7,8,9,10,11,0,0,0},
{5,6,7,8,9,10,11,12,0,0},
{5,6,7,8,9,10,11,12,13,0},
{5,6,7,8,9,10,11,12,13,14},
{6,7,8,9,10,11,12,13,14,15},
};
