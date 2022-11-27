/*
* File: circular.c
* Title: Demonstrate operation of circular buffer with automated testing
* Version: 0.2
* Created: 16/11/2019
*
*/

// A program to demonstrate the operation of a circular buffer.
//
// General description
// A circular buffer is a type of first-in first-out queue, normally fixed in length
// and is used as a temporary store of information that needs to be transmitted 
// asynchronously from one process to another.
//
// Implementation details
// The circular buffer holds messages entered by the user which are to be sent to the
// screen. The operation of the buffer is controlled by a menu from which the user can
// choose one of the following: enter a new message, send (consume) a message from the
// buffer or display the contents of the buffer.
//
// The buffer is implemented as a fixed length array. Once all the elements in the array
// have been filled, the first element will need to be used again. As an example of the
// operation of the circular buffer, assume that there are 10 elements in the array,
// 9 messages have been entered by the producer, 6 have been consumed and then a further
// 5 produced. The next message to be consumed (tail of the buffer) would be the 7th
// element in the array and the next message entered (head of the buffer) would
// become the 5th element in the array.
//
// If the number of messages in the buffer is equal to the length of the array and a
// new message is entered, this simply overwrites the last message at the tail of the
// buffer. This is termed an overflow.

//Portable types                                                             
#include <stdio.h>

// switch to turn on testing
#define TESTING

// the format of the messages in the buffer
typedef struct {
  unsigned long index;  // index number of the data item
  unsigned char data;  // single byte of information to be sent
} Message;


// the length of the fixed array to be used for the FIFO buffer - must be at least one
// and no greater than half the maximum value allowed in an unsigned long (see
// the file limits.h)
#define BUFFER_LENGTH 10

//initialise array to store buffer
int buffer_state[BUFFER_LENGTH] = {0};

// function prototypes
void Produce(Message*, unsigned long*, unsigned long*);
void Consume(const Message*, unsigned long*, unsigned long*);
void Show(const Message*, unsigned long, unsigned long);

//include test code and data if testing enabled
#ifdef TESTING
#include "test.h"
#endif

// Control the entering, sending and displaying of messages in the buffer.
// Arguments: None
// Returns: 0 on completion
int main()
{
  Message buffer[BUFFER_LENGTH];   // the message buffer
  unsigned long buffer_tail = 0;  // position of the tail in the message buffer -
                                  // the next message will be consumed from here
  unsigned long buffer_length = 0;  // number of messages in the buffer
  int UserInput;
                      
  // loop until the user wishes to exit
  while (1) {
    
		#ifndef TESTING
			// show the menu of options
			printf("\n");
			printf("Buffer Management Menu\n");
			printf("----------------------\n");
			printf("1. Produce a new message for the buffer\n");
			printf("2. Consume a message from the buffer\n");
			printf("3. View the contents of the buffer\n");
			printf("4. Exit from the program\n\n");
			
			// get the user's choice
			printf("Enter your option: ");
			scanf("%i", &UserInput);
			printf("\n\n");
		
		#else
			UserInput=MenuTest();//get menu option from function MenuTest
			Show(buffer, buffer_tail, buffer_length);//call function to find valid items in buffer
			BufferTest(buffer_state); //check if buffer matches expected outputs
			
		#endif
    
    // act on the user's input
    switch(UserInput) {
      case 1:
        Produce(buffer, &buffer_tail, &buffer_length);
        break;
      
      case 2:
        Consume(buffer, &buffer_tail, &buffer_length);
        break;
      
      case 3:
        Show(buffer, buffer_tail, buffer_length);
        break;

      case 4:
				PrintResults();
        return 0;

      default:
        printf("Invalid entry\n\n");
        break;
    }
  }
}

 
// Create a new message and add it to the head of the buffer.
// The data for the message is obtained from the user and the index from the
// static variable 'index' defined in this function
// Arguments:
//   (1) start of the buffer
//   (2) position of the tail of the buffer
//   (3) number of messages in the buffer
// Returns: void
void Produce(Message* buffer, unsigned long* buffer_tail, unsigned long* buffer_len)
{  
  static unsigned long index = 0; 
  unsigned long buffer_head;

  // find the element of the buffer in which to store the message
  buffer_head = (*buffer_tail + *buffer_len) % BUFFER_LENGTH;

	#ifndef TESTING
  // get the value of the data for the message from the user
		printf("Add new data\n");
		printf("------------\n");
		printf("Enter data: ");
		scanf("%hhu", &buffer[buffer_head].data);
		printf("\n");
	#else
		buffer[buffer_head].data = (unsigned char)ProduceTest();//get new data from function ProduceTest
	#endif

  // get the value of the index for the message
  buffer[buffer_head].index = index++;  
	
  // if no buffer overflow has occurred, adjust the buffer length
  if (*buffer_len < BUFFER_LENGTH) {
    (*buffer_len)++;
  }

  // if a buffer overflow has occurred, display an error statement
  else {
    *buffer_tail = (*buffer_tail+1) % BUFFER_LENGTH;
    printf("Overflow error\n");
  }  
}


// Pop the message at the head of the buffer and display it.
// Arguments:
//   (1) start of the buffer
//   (2) position of the tail of the buffer
//   (3) number of messages in the buffer
// Returns: void
void Consume(const Message* buffer, unsigned long* buffer_tail, unsigned long* buffer_len)
{
  // if the buffer is empty, display an error statement
  if (*buffer_len == 0) {
    printf("No messages in the buffer\n");
  }
  
  // if the buffer is not empty, display the message at the tail, remove the message
  // by advancing the tail of buffer offset in a circular manner and adjust the
  // buffer length
  else {
    printf("\n");
    printf("Offset Data   Index\n");
    printf("%lu \t", *buffer_tail);
    printf("%hhu \t", buffer[*buffer_tail].data);
    printf("%lu", buffer[*buffer_tail].index);
    printf("\n");
    *buffer_tail = (*buffer_tail+1) % BUFFER_LENGTH;
    (*buffer_len)--;
  }
}

 
// Display all of the messages in the buffer.
// Arguments:
//   (1) start of the buffer
//   (2) position of the tail of the buffer
//   (3) number of messages in the buffer
// Returns: void
void Show(const Message* buffer, unsigned long buffer_tail, unsigned long buffer_len)
{
  unsigned long count; // count through the messages being displayed
  unsigned long buffer_head;  // the position at which the next message would be pushed
	int buffer_state_count = 0; //variable to store location of buffer which data has been stored
	
	for (int i=0;i<BUFFER_LENGTH;i++) buffer_state[i]=0; //make all elements in buffer_state 0
	
  // if the buffer is empty, display an error statement
  if (buffer_len == 0) {
    printf("No messages in the buffer\n");
  }

  // if the buffer is not empty, display all the messages in the buffer
  else {
    // display a title
    printf("\n");
    printf("Offset Data   Index\n");
    // display messages if they are sequential in the array
    buffer_head = (buffer_tail + buffer_len) % BUFFER_LENGTH;
    if (buffer_tail < buffer_head) {
      for (count=buffer_tail;count<buffer_head;count++) {
        printf("%lu \t", count);
        printf("%hhu \t", buffer[count].data);
				buffer_state[buffer_state_count]=buffer[count].data; //write output to array
				buffer_state_count++; //increment count
        printf("%lu \n", buffer[count].index);
      }
    }
    // display messages if part are at the end of the array and the remainder at
    // the start
    else {
      for (count=buffer_tail;count<BUFFER_LENGTH;count++) {
        printf("%lu \t", count);
        printf("%hhu \t", buffer[count].data);
				buffer_state[buffer_state_count]=buffer[count].data; //write output to array
				buffer_state_count++; //increment count
        printf("%lu \n", buffer[count].index);
      }
      for (count=0;count<buffer_head;count++) {
        printf("%lu \t", count);
        printf("%hhu \t", buffer[count].data);
				buffer_state[buffer_state_count]=buffer[count].data; //write output to array
				buffer_state_count++; //increment count
        printf("%lu \n", buffer[count].index);
      }
    }       
  }
}
