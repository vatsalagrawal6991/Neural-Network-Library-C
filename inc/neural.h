#ifndef NEURAL_H
#define NEURAL_H
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>


typedef enum back {
    Basic=1,Stochastic=2,Mini=3
}bp;
typedef enum activation {
    Sigmoid=1,Tanh=2,ReLu=3,None=4,Softmax=5
}af;
typedef enum cost {
    cross=1,mean=2
}cf;


int layers ;
int input_size;
int output_size;
int columns;
int *layer_nonode;
double ***weight;
double **bias;
af out_function;
af hidden_function;
cf cost_function;
bp back_propogation;
double learning_rate;
int iteration;
int batch;
double **result;
double *input;
double **delta;
double ***derivative_weight;
double ***final_weight;
double **derivative_bias;
double **final_bias;
double *output;
int training_size;
double regularization;
double cost_result;
double **data;
double accuracy;
int total_size;
void neural_init ();
void read();
void forward_function();
void backward_function();
void neural_train();
void neural_test();
void neural_initial();
void neural_regressor();

#endif