#include "neural.h"
#include <time.h>

void neural_initial(){
    layers = 7;      ///////////////////////////////////////////////
    training_size=453;
    columns=32;
    total_size=569;
    input_size = 30;
    output_size = 2;
    layer_nonode = (int*) malloc ((layers+1)*sizeof(int));
    layer_nonode[0] = input_size;
    layer_nonode[1]= 30;  ///////////////////////////////////
    layer_nonode[2]= 30;
    layer_nonode[3]= 30;
    layer_nonode[4]= 30;  ///////////////////////////////////
    layer_nonode[5]= 30;
    layer_nonode[6]= 30;
    layer_nonode[7]= 30;  ///////////////////////////////////

    out_function=5;
    hidden_function=2;
    cost_function=1;
    back_propogation=1;
    learning_rate=0.001;
    iteration = 200;
    batch = 10;
    regularization=0.0001;
}

void neural_init (){
    int i,j,k;
    srand(time(0));
    cost_result=0.0;
    accuracy=0.0;
    layer_nonode[layers]=output_size;
    weight = (double***) malloc ((layers)*sizeof(double**));
    bias = (double**) malloc ((layers)*sizeof(double*));
    result = (double**) malloc ((layers)*sizeof(double*));
    input = (double*) malloc (input_size*sizeof(double));
    output = (double*) malloc (output_size*sizeof(double));
    derivative_weight = (double***) malloc ((layers)*sizeof(double**));
    derivative_bias = (double**) malloc ((layers)*sizeof(double*));
    final_weight = (double***) malloc ((layers)*sizeof(double**));
    final_bias = (double**) malloc ((layers)*sizeof(double*));
    delta = (double**) malloc ((layers)*sizeof(double*));
    data = (double**) malloc ((total_size)*sizeof(double*));

    for (i=0;i<total_size;i++){
        data[i] = (double*) malloc ((columns+1)*sizeof(double));
    }

    for (i=0;i<layers;i++){
        weight[i] = (double**) malloc ((layer_nonode[i+1])*sizeof(double*));
        bias[i] = (double*) malloc ((layer_nonode[i+1])*sizeof(double));
        result[i] = (double*) malloc ((layer_nonode[i+1])*sizeof(double));

        derivative_weight[i] = (double**) malloc ((layer_nonode[i+1])*sizeof(double*));
        derivative_bias[i] = (double*) malloc ((layer_nonode[i+1])*sizeof(double));
        final_weight[i] = (double**) malloc ((layer_nonode[i+1])*sizeof(double*));
        final_bias[i] = (double*) malloc ((layer_nonode[i+1])*sizeof(double));
        delta[i] = (double*) malloc ((layer_nonode[i+1])*sizeof(double));
        double b=2.0;

        for (j=0;j<layer_nonode[i+1];j++){
            weight[i][j] = (double*) malloc ((layer_nonode[i])*sizeof(double));
            derivative_weight[i][j] = (double*) malloc ((layer_nonode[i])*sizeof(double));
            final_weight[i][j] = (double*) malloc ((layer_nonode[i])*sizeof(double));
            result[i][j]=0.0;
            bias[i][j]=((double)rand()/RAND_MAX);
            derivative_bias[i][j]=0.0;
            final_bias[i][j]=0.0;
            delta[i][j]=0.0;
            for (k=0;k<layer_nonode[i];k++){
                int a = pow(-1,(rand())%2);
                weight[i][j][k]=((double)rand()/RAND_MAX)*a;
                derivative_weight[i][j][k]=0.0;
                final_weight[i][j][k]=0.0;
            }
        }
    }


}

double sigmoid_function(double z){
    double a = exp((-1*z));
    a=a+1;
    a=1/a;
    return a;
}

double tanh_function(double z){
    return tanh(z);
}

double relu_function(double z){
    if (z<0){
        return 0.0;
    }
    else {
        return z;
    }
}
double derivative_sigmoid_function(double a){
    return (a*(1-a));
}

double derivative_tanh_function(double a){
    return (1-(a*a));
}

double derivative_relu_function(double a){
    if (a<0){
        return 0.0;
    }
    else {
        return 1;
    }
}

void refresh_forward() {
    int i, j, k;
    for (k=0;k<layers;k++){
        for (i=0;i<layer_nonode[k+1];i++) {
            result[k][i]=0.0;
        }
    }
}
void refresh_backward() {
    int i, j, k;
    for (k=0;k<layers;k++){
        for (i=0;i<layer_nonode[k+1];i++) {
            delta[k][i]=0.0;
        }
    }
}

void refresh_mid() {
    int i, j, k;
    for (k=0;k<layers;k++){
        for (i=0;i<layer_nonode[k+1];i++){
            final_bias[k][i]=0.0;
            for(j=0;j<layer_nonode[k];j++){
                final_weight[k][i][j]=0.0;
            }
        }
    }
}

void forward_function(){
    int i,j,k;
    refresh_forward();
    for (i=0;i<layer_nonode[1];i++){
        for (j=0;j<layer_nonode[0];j++){
            result[0][i]=result[0][i]+weight[0][i][j]*input[j];
        }
        result[0][i]=result[0][i]+ bias[0][i];
        if(hidden_function==1){
            result[0][i]=sigmoid_function(result[0][i]) ;
        }
        else if(hidden_function==2){
            result[0][i]=tanh_function(result[0][i]);
        }
        else if(hidden_function==3){
            result[0][i]=relu_function(result[0][i]);
        }
    }
    for (k=1;k<layers-1;k++){
        for (i=0;i<layer_nonode[k+1];i++){
            for (j=0;j<layer_nonode[k];j++){
                result[k][i]=result[k][i]+weight[k][i][j]*result[k-1][j];
            }
            result[k][i]=result[k][i]+bias[k][i];
            if(hidden_function==1){
                result[k][i]=sigmoid_function(result[k][i]);
            }
            else if(hidden_function==2){
                result[k][i]=tanh_function(result[k][i]);
            }
            else if(hidden_function==3){
                result[k][i]=relu_function(result[k][i]);
            }
        }
    }
    double sum =0.0;
    for (i=0;i<layer_nonode[layers];i++){
        for (j=0;j<layer_nonode[layers-1];j++){
            result[layers-1][i]=result[layers-1][i]+weight[layers-1][i][j]*result[layers-2][j];
        }
        result[layers-1][i]=result[layers-1][i]+bias[layers-1][i];
        sum=sum+exp(result[layers-1][i]);
        if(out_function==1){
            result[layers-1][i]=sigmoid_function(result[layers-1][i]);
        }
        else if(out_function==2){
            result[layers-1][i]=tanh_function(result[layers-1][i]);
        }
        else if(out_function==3){
            result[layers-1][i]=relu_function(result[layers-1][i]);
        }
        else if(out_function==4){
            result[layers-1][i]=result[layers-1][i];
        }

    }
    if (out_function==5){
        for (i=0;i<layer_nonode[layers];i++){
            result[layers-1][i]=(exp(result[layers-1][i]))/sum;
        }
    }

}

void backward_function(){
    int i,j,k;
    refresh_backward();
    for (i=0;i<layer_nonode[layers];i++){
        if(out_function==1){
            delta[layers-1][i]=(result[layers-1][i]-output[i])* derivative_sigmoid_function(result[layers-1][i]);
        }
        else if(out_function==2){
            delta[layers-1][i]=(result[layers-1][i]-output[i])* derivative_tanh_function(result[layers-1][i]);
        }
        else if(out_function==3){
            delta[layers-1][i]=(result[layers-1][i]-output[i])* derivative_relu_function(result[layers-1][i]);
        }
        else if(out_function==4){
            delta[layers-1][i]=(result[layers-1][i]-output[i]);
        }
        else if(out_function==5){
            delta[layers-1][i]=(result[layers-1][i]-output[i])* derivative_sigmoid_function(result[layers-1][i]);
        }
        if (cost_function==1){
            delta[layers-1][i]=delta[layers-1][i]/(result[layers-1][i]*(1-result[layers-1][i]));
        }
    }

    for (k=layers-2;k>=0;k--){
        for (i=0;i<layer_nonode[k+1];i++) {
            for (j=0;j<layer_nonode[k+2];j++) {
                delta[k][i] = delta[k][i] + (weight[k + 1][j][i] * delta[k+1][j]);
            }
            if (hidden_function == 1) {
                delta[k][i] = delta[k][i]* derivative_sigmoid_function(result[k][i]);
            }
            else if (hidden_function == 2) {
                delta[k][i] = delta[k][i]* derivative_tanh_function(result[k][i]);
            }
            else if (hidden_function == 3) {
                delta[k][i] = delta[k][i]* derivative_relu_function(result[k][i]);
            }
        }
    }
    for (i=0;i<layer_nonode[1];i++) {
        derivative_bias[0][i]=delta[0][i];
        for (j=0;j<layer_nonode[0];j++) {
            derivative_weight[0][i][j]=delta[0][i]*input[j];

        }
    }
    for (k=1;k<layers;k++){
        for (i=0;i<layer_nonode[k+1];i++) {
            derivative_bias[k][i]=delta[k][i];
            for (j=0;j<layer_nonode[k];j++) {
                derivative_weight[k][i][j]=delta[k][i]*result[k-1][j];
            }
        }
    }
}
void costfn(){
    int i,j,k,l,m;
    cost_result=0.0;
    for (l=0;l<training_size;l++) {
        for (m = output_size+1; m < (input_size+output_size+1); m++) {
            input[m-(output_size+1)]=data[l][m];
        }
        for (m = 1; m < (output_size+1); m++) {
            output[m-1]=data[l][m];
        }
        forward_function();
        for (i=0;i<layer_nonode[layers];i++){
            if(cost_function==2){
                double a= (result[layers-1][i]-output[i]);
                cost_result=cost_result+((a*a)/2);
            }
            else if(cost_function==1){
                double a= (output[i]*log(result[layers-1][i]+0.00000000000000001));
                double b= (1-output[i])*log((1-result[layers-1][i]+0.00000000000000001));
                cost_result=cost_result+(a+b);
            }

        }

    }
    cost_result=cost_result/training_size;
    printf ("THE LOST FUNCTION VALUE IS :%lf \n",cost_result);
}
void neural_train(){
    int i,j,k,l,m,n;

    if (back_propogation==1){
        for (n=0;n<iteration;n++) {
            refresh_mid();
            for (l=0;l<training_size;l++) {
                for (m = output_size+1; m < (input_size+output_size+1); m++) {
                    input[m-(output_size+1)]=data[l][m];
                }
                for (m = 1; m < (output_size+1); m++) {
                    output[m-1]=data[l][m];
                }
                forward_function();
                backward_function();
                for (k=0;k<layers;k++){
                    for (i=0;i<layer_nonode[k+1];i++){
                        final_bias[k][i]=final_bias[k][i]+derivative_bias[k][i];
                        for(j=0;j<layer_nonode[k];j++){
                            final_weight[k][i][j]=final_weight[k][i][j]+derivative_weight[k][i][j];

                        }
                    }
                }
            }
            for (k=0;k<layers;k++) {
                for (i = 0; i < layer_nonode[k + 1]; i++) {
                    bias[k][i] = bias[k][i] - ((learning_rate * final_bias[k][i]) / training_size);
                    for (j = 0; j < layer_nonode[k]; j++) {
                        weight[k][i][j] = (weight[k][i][j] - ((learning_rate * final_weight[k][i][j]) / training_size))-(learning_rate * regularization * weight[k][i][j]); ;
                    }
                }
            }
            costfn();
        }
    }
    else if (back_propogation==2){
        for (n=0;n<iteration;n++) {
            for (l=0;l<training_size;l++) {
                for (m = output_size+1; m < (input_size+output_size+1); m++) {
                    input[m-(output_size+1)]=data[l][m];
                }
                for (m = 1; m < (output_size+1); m++) {
                    output[m-1]=data[l][m];
                }
                forward_function();
                backward_function();
                for (k=0;k<layers;k++) {
                    for (i = 0; i < layer_nonode[k + 1]; i++) {
                        bias[k][i] = bias[k][i] - ((learning_rate * derivative_bias[k][i]));
                        for (j = 0; j < layer_nonode[k]; j++) {
                            weight[k][i][j] = weight[k][i][j] - ((learning_rate * derivative_weight[k][i][j])) -
                                              (learning_rate * regularization * weight[k][i][j]);
                        }
                    }
                }
            }
            costfn();
        }
    }
    else if (back_propogation==3){
        for (n=0;n<iteration;n++) {
            refresh_mid();
            for (l=0;l<training_size;l++) {
                for (m = output_size+1; m < (input_size+output_size+1); m++) {
                    input[m-(output_size+1)]=data[l][m];
                }
                for (m = 1; m < (output_size+1); m++) {
                    output[m-1]=data[l][m];
                }
                forward_function();
                backward_function();
                for (k=0;k<layers;k++){
                    for (i=0;i<layer_nonode[k+1];i++){
                        final_bias[k][i]=final_bias[k][i]+derivative_bias[k][i];
                        for(j=0;j<layer_nonode[k];j++){
                            final_weight[k][i][j]=final_weight[k][i][j]+derivative_weight[k][i][j];
                        }
                    }
                }
                if ((l%batch==(batch-1))||(l==training_size-1)){
                    for (k=0;k<layers;k++) {
                        for (i = 0; i < layer_nonode[k + 1]; i++) {
                            bias[k][i] = bias[k][i] - ((learning_rate * final_bias[k][i]) / batch);
                            for (j = 0; j < layer_nonode[k]; j++) {
                                weight[k][i][j] = weight[k][i][j] - ((learning_rate * final_weight[k][i][j]) / batch) -
                                                  (learning_rate * regularization * weight[k][i][j]);
                            }
                        }
                    }
                    refresh_mid();
                }
            }
            costfn();
        }
    }
}

void neural_test(){
    int i,j,k,l,m;
    double count=0.0;
    printf ("S.NO.      Class0      Class1      Predicted Value\n" );
    for (l=training_size;l<total_size;l++) {
        for (m = output_size+1; m < (input_size+output_size+1); m++) {
            input[m-(output_size+1)]=data[l][m];
        }
        for (m = 1; m < (output_size+1); m++) {
            output[m-1]=data[l][m];
        }
        forward_function();
        printf("%lf     ",data[l][0]);
        for (i=0;i<layer_nonode[layers];i++){
            printf("%lf     ",result[layers-1][i]);
        }
        count++;
        if ((result[layers-1][0])>(result[layers-1][1])){
            printf("1");
            if (output[0]==1){
                accuracy++;
            }
        }
        else{
            printf("0");
            if (output[0]==0){
                accuracy++;
            }
        }
        printf("\n");
    }
    //printf("Accuracy is :%lf %lf",accuracy,count);
    printf("Accuracy is :%lf\n",(accuracy/count)*100);
}

void neural_multi_test(){
    int i,j,k,l,m;
    double count=0.0;
    printf ("S.NO.      Class0      Class1      Predicted Value\n" );
    for (l=training_size;l<total_size;l++) {
        for (m = output_size+1; m < (input_size+output_size+1); m++) {
            input[m-(output_size+1)]=data[l][m];
        }
        for (m = 1; m < (output_size+1); m++) {
            output[m-1]=data[l][m];
        }
        forward_function();
        printf("%lf     ",data[l][0]);
        int max=0;
        for (i=0;i<layer_nonode[layers];i++){
            printf("%lf     ",result[layers-1][i]);
        }
        for (i=1;i<layer_nonode[layers];i++){
            if ((result[layers-1][i])>(result[layers-1][i-1])){
                max++;
            }
        }
        if (output[max]==1){
            accuracy++;
        }
        printf("%d\n",max);
    }
    //printf("Accuracy is :%lf %lf",accuracy,count);
    printf("Accuracy is :%lf",(accuracy/count)*100);
}

void neural_classify(){
    int i,j,k,l,m;
    double count=0.0;
    printf ("S.NO.      Class0      Class1      Predicted Value\n" );
    for (l=training_size;l<total_size;l++) {
        for (m = output_size+1; m < (input_size+output_size+1); m++) {
            input[m-(output_size+1)]=data[l][m];
        }
        for (m = 1; m < (output_size+1); m++) {
            output[m-1]=data[l][m];
        }
        forward_function();
        printf("%lf     ",data[l][0]);
        int max=0;
        for (i=0;i<layer_nonode[layers];i++){
            printf("%lf     ",result[layers-1][i]);
        }
        for (i=1;i<layer_nonode[layers];i++){
            if ((result[layers-1][i])>(result[layers-1][i-1])){
                max++;
            }
        }

        printf("%d\n",max);
    }
    //printf("Accuracy is :%lf %lf",accuracy,count);
}

void neural_regressor(){
    int i,j,k,l,m;
    double count=0.0;
    printf ("S.NO.      Predicted Value\n" );
    for (l=training_size;l<total_size;l++) {
        for (m = output_size+1; m < (input_size+output_size+1); m++) {
            input[m-(output_size+1)]=data[l][m];
        }
        for (m = 1; m < (output_size+1); m++) {
            output[m-1]=data[l][m];
        }
        forward_function();
        printf("%lf     ",data[l][0]);
        for (i=0;i<layer_nonode[layers];i++){
            printf("%lf     ",result[layers-1][i]);
            if (output[i]>result[layers-1][i]-2 && output[i]<result[layers-1][i]+2){
                accuracy++;
            }
            count++;
        }
        printf("\n");
    }
    //printf("Accuracy is :%lf %lf",accuracy,count);
    printf("Accuracy is :%lf \n",accuracy/count*100);
}


