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

Conclusion
1. Gradient Vanishing Problem can be seen clearly with seven
layers
2. With 3 Layer Gradient vanishing Problem occurs sometimes
depending on random initialization with logistics
3. Relu most of the time give NAN because of range overflow
4. The best-hidden layer function is Tanh
5. Increasing no of neurons to 100 gives the best answer but
increases time drastically
6. The optimal no of neurons is found out to be 30, which takes less
time and also performs best
7. The best no of hidden layers is found to be 3 with tanh
8. Other activations need 2 or 1 layer for their consistent result
9. Modified relu is giving the same result as logistics.
10. For the classification data set, accuracy ranges from 70 to 95%
for tanh with a 0.001 learning rate with three layers of 100
neurons each.
11. Accuracy with sigmoid ranges from 20% to 75% for three layers
12. Tanh also gives the same accuracy
13. Batch gives the best result, but batch size finding is difficult
optimum half of training size, gives accuracy 90%.
14. Stochastic gives result in less iteration, but the result cannot be
of high accuracy sometimes, but most of the time it ranges to
75%, can be biased sometimes. It can contain noise.
15. Basic gives the highest accuracy ranging to 90%
16. Basic gives high accuracy but again needs time
17. Normalized data set gives an accuracy of 98% on avg.
18. For classification, I have used Cross entropy
19. For MSE in classification, the accuracy severely decreases to 60%
for tanh
20. For regression data set again, the best model is found to be tanh
21. Accuracy range from 8% to 40% for tanh with three layers, 100
neurons each.
22. Accuracy dips to 0% to 20% for other activation function
23. Regression gives an accuracy of 70% with a +-2 error rate and a
max 40% with a +-1 error rate
24. For other relatively less complex data set accuracy to turn out to
be ranging from 87% to 100%
25. Increasing no of layers to four increases accuracy for tanh
26. Increasing no of layer till two increase accuracy for logistic and
relu
27. Increasing no of neurons beyond 150 has negative effect only
28. More no of neurons, more time will be needed for calculation
29. Python calculation time is relatively short as compared to ours
30. Scikit also calculate relu for some cases (not all) before crossing
maximum bound
31. For tanh and logistics, our and python library performance is
similar, considering avg performance for large run
32. In one run, only any of the python and my implementation can
perform better
33. Loss function value for MSE and cross-entropy for different
functions in python and my implementation is given below
34. For normalized data set, both python and c implementation
works till layer 4 for relu
35. Normalized and normal data set has the almost same accuracy
36. Standardized data set have somewhat less performance than
normalized
37. I have not implemented any normalization or standardization
function. Instead, I have used weka for this
38. For Regression, relu is not working for later 4 in python
39. For classification, relu is working for layer 4 in python
40. Most of the time gradient vanishing problem is seen in layer 4
for logistic
41. For normalized data set, this can be seen clearly that running
relu for layer 4 removes the gradient vanishing problem
42. Loss function graphs are given below
43. Note in python plot straight line after some point is due to no
significant change in the loss. Thus copying the last value for all
iterations
44. Relu for c is modified in both loss graphs because the original
relu is giving nan due to the large number
45. Relu modified is when derivative and original value is divided by
100000
46. Python gives nan for relu of MSE. Thus no plot for it
