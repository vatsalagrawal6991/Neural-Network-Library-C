**************************HOW TO MAKE EXECUTABLE AND RUN PROGRAMME******************************
 1) Unzip File at location x
2) Open Terminal and change directory to that location x
3) Now enter command make.
This will create Executables
4) Now type
export LD_LIBRARY_PATH=${pwd} //give the path of the current
working directory.
5) Then type executable name with the arguments
6) For the plot of cross-entropy, type make plot1
7) For the plot of MSE, type make plot2
8) For different propagation comparisons, type make plot3
9) Type make run for classification data set with tanh
10) Type make run1 for regression data set with tanh
11) Type make run2 for vanishing gradient with logistic
12) Type make run3 for solving vanishing gradient through relu
13) Type make run8 for seeing the accuracy of the normalized data
set
14) Type make run9 for seeing the accuracy of the standardized data
set
15) Type make run4 for classification in python
16) Type make run5 for Regression in python
17) Type make run6 for own data set
18) Type make run7 for own dataset in python

