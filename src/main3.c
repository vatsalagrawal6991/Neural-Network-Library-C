#include "neural.h"

void read(){
    int i,j;
    FILE* datam = fopen("/home/baadalvm/CLionProjects/Lab4/Lab4_IDE/Neural/data3.txt","r");
    if (datam==NULL){
        printf ("ERROR");
        return;
    }
    char a[2000];
    double ab=1.0;

    //printf("%s",a);
    //fflush(stdout);

    for (j=0;j<total_size;j++){
        fgets(a, 2000, datam);
        //  printf("%s",a);
        //fflush(stdout);
        char* point =strtok(a," ");
        for (i=0;i<(columns+2);i++){
            if(i==0){
                     data[j][i]=ab;
                     ab++;
                     i++;
                 }
            else if(i==(columns+1)) {
                data[j][1]=atof(point);
                point =strtok(NULL," ");

            }
            else{
                data[j][i]=atof(point);
                point =strtok(NULL," ");
            }

        }
    }
    fclose(datam);
}

int main(int argc, char**argv){
    neural_initial();


    layers =4 ;      ///////////////////////////////////////////////
    training_size=401;
    columns=14;
    total_size=506;
    input_size = 13;
    output_size = 1;
    layer_nonode[0] = input_size;
    layer_nonode[1]= 30;  ///////////////////////////////////
    layer_nonode[2]= 30;
    layer_nonode[3]= 30;
    out_function=4;
    hidden_function=2;
    cost_function=2;
    back_propogation=1;
    learning_rate=0.001;
    iteration = 300;
    batch = 10;
    regularization=0.0001;


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
    neural_regressor();

    /*
       int i,j,k;
       for(i=0;i<total_size;i++){
           for(j=0;j<columns+1;j++){
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
