#include "neural.h"

void read(){
    int i,j;
    FILE* datam = fopen("/home/baadalvm/CLionProjects/Lab4/Lab4_IDE/Neural/data.csv","r");
    if (datam==NULL){
        printf ("ERROR");
        return;
    }
    char a[2000];

    //printf("%s",a);
    //fflush(stdout);
    fgets(a, 2000, datam);
    for (j=0;j<total_size;j++){
        fgets(a, 2000, datam);
        //  printf("%s",a);
        //fflush(stdout);
        char* point =strtok(a,",");
        for (i=0;i<(columns+1);i++){
            if(i==1){
                /* if (*point=='M'){
                     data[j][i]=0;
                     i++;
                     data[j][i]=1;
                 }
                 if (*point=='B'){
                     data[j][i]=1;
                     i++;
                     data[j][i]=0;
                 } */
                if (*point=='0'||*point=='B'){
                    data[j][i]=0;
                    i++;
                    data[j][i]=1;
                }
                if (*point=='1'||*point=='M'){
                    data[j][i]=1;
                    i++;
                    data[j][i]=0;
                }
            }
            else{
                data[j][i]=atof(point);
            }
            point =strtok(NULL,",");
        }
    }
    fclose(datam);
}

int main(int argc, char** argv){
    neural_initial();
    layers=4;
    //training_size=400;
    //columns=4;
    //total_size=400;
    //input_size = 2;
    //output_size = 2;
    //layer_nonode[1]= 7;  ///////////////////////////////////
    //layer_nonode[2]= 5;
    //layer_nonode[3]= 10;
    //out_function=1;
    hidden_function=2;
    //cost_function=2;
    //back_propogation=1;
    //learning_rate=0.1;
    //iteration = 3000;
    //batch = 1000;
    //regularization=0.1;
    if (argc==6){
        layers=atoi(argv[1]);
        out_function=atoi(argv[2]);
        hidden_function=atoi(argv[3]);
        cost_function=atoi(argv[4]);
        back_propogation=atoi(argv[5]);
    }
    if (argc==9){
        layers=atoi(argv[1]);
        out_function=atoi(argv[2]);
        hidden_function=atoi(argv[3]);
        cost_function=atoi(argv[4]);
        back_propogation=atoi(argv[5]);
        learning_rate=atof(argv[6]);
        iteration=atoi(argv[7]);
        regularization=atof(argv[8]);
    }
    if (argc==10){
        layers=atoi(argv[1]);
        out_function=atoi(argv[2]);
        hidden_function=atoi(argv[3]);
        cost_function=atoi(argv[4]);
        back_propogation=atoi(argv[5]);
        learning_rate=atof(argv[6]);
        iteration=atoi(argv[7]);
        regularization=atof(argv[8]);
        batch=atof(argv[9]);
    }
    if (argc==11){
        layers=atoi(argv[1]);
        out_function=atoi(argv[2]);
        hidden_function=atoi(argv[3]);
        cost_function=atoi(argv[4]);
        back_propogation=atoi(argv[5]);
        learning_rate=atof(argv[6]);
        iteration=atoi(argv[7]);
        regularization=atof(argv[8]);
        batch=atof(argv[9]);
        layer_nonode[1]=atoi(argv[10]);
    }
    if (argc==12){
        layers=atoi(argv[1]);
        out_function=atoi(argv[2]);
        hidden_function=atoi(argv[3]);
        cost_function=atoi(argv[4]);
        back_propogation=atoi(argv[5]);
        learning_rate=atof(argv[6]);
        iteration=atoi(argv[7]);
        regularization=atof(argv[8]);
        batch=atof(argv[9]);
        layer_nonode[1]=atoi(argv[10]);
        layer_nonode[2]=atoi(argv[11]);
    }
    if (argc==13){
        layers=atoi(argv[1]);
        out_function=atoi(argv[2]);
        hidden_function=atoi(argv[3]);
        cost_function=atoi(argv[4]);
        back_propogation=atoi(argv[5]);
        learning_rate=atof(argv[6]);
        iteration=atoi(argv[7]);
        regularization=atof(argv[8]);
        batch=atof(argv[9]);
        layer_nonode[1]=atoi(argv[10]);
        layer_nonode[2]=atoi(argv[11]);
        layer_nonode[2]=atoi(argv[12]);
    }
    neural_init();
    read();
    neural_train();
    neural_test();

/*
    int i,j,k;
    for(i=0;i<total_size;i++){
        for(j=0;j<4;j++){
            printf("%lf ",data[i][j]);
        }
        printf("\n");
    }
    for (i=0;i<layers;i++){
        for (j=0;j<layer_nonode[i+1];j++){
            printf("\n%lf ",bias[i][j]);
            for (k=0;k<layer_nonode[i];k++){
                printf("%lf ",weight[i][j][k]);

            }
        }
    }
    neural_test();
    backward_function();
    for (i=0;i<layers;i++){
        printf("\n ",result[i][j]);
        for (j=0;j<layer_nonode[i+1];j++){
            printf("\n ",result[i][j]);
            //printf("\n%lf ",bias[i][j]);
            printf("%lf ",result[i][j]);
            printf("%lf ",delta[i][j]);
            printf("%lf a ",derivative_bias[i][j]);
            for (k=0;k<layer_nonode[i];k++){
                printf("%lf b ",derivative_weight[i][j][k]);
            }
        }
    }*/
    return 0;
}
