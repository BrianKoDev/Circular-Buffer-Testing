# Project Description
A report on assessment of the quality of given software.

[Software Quality Assessment](https://github.com/BrianKoDev/Circular-Buffer-Testing/blob/main/SQA.pdf)

## Task 1
Circular Buffer Testing
1. Allow entry (production) of test data items for the circular buffer.
2. Allow extraction (consuming) of test data items from the circular buffer.
3. The definition and execution of sequences consisting of the operations 1 and 2 above. The
sequences should allow any combination and number of operations 1 and 2.
4. Automated testing of the current state of the buffer against its expected state.


## Task 2
The program is able to perform the following RTOS operations.
1. Receive input continuously from the generate_data task (given in the initial code). The
data generated should be altered only by changing the value of NUM_SAMPLES within the
range 0 to 255.
2. Filter the data received in the manner now described. Each set of seven values from the
buffer obtained need to be processed by the filter_data task and used to produce a
single output in the process_ buffer. The output is calculated as a weighted sum of seven
inputs with the set of weight values being as follows {-0.5,1.0,-2.0,3.0,-2.0,1.0,-
0.5}.
3. Continually calculate the mean of the most recent five data values in the process_buffer.
As new data values are arriving continuously, the calculations need to take place continuously.
The mean values need to be stored in the log_output.
4. Continually calculate the variance of the most recent five data values in the
process_buffer. Again, as new data values are arriving continuously, the calculations need
to take place continuously. The variance values also need to be stored in the log_output.
5. Keep the values obtained in points 3 and 4 above by storing them in memory. These values
should be made easily accessible for testing purposes.
6. Obtain input from the user to permit their selection of whether only the mean values are
needed, only the variance values are needed or whether both sets of values are needed. The
user button should be used to select these options and the current option that is selected should
be indicated by individual LEDs (you specify which LEDs are used).