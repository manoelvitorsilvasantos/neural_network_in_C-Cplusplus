#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#define TAM 3


struct neuronio{
	long input[TAM];
	double weight[TAM];
	float bias;
};

double sigmal(struct neuronio neuro);
double tanh(double y);
double sigmoid(float y);
double randf(double min, double max);

int main(void)
{
	int i = 0;
	struct neuronio n;
	
	n.bias = 0.75;
	
	srand(time(NULL));
	
	n.weight[0] = randf(-1.0,1.0);
	printf("W1 => %lf\n", n.weight[0]);
	n.weight[1] = randf(-1.0,1.0);
	printf("W2 => %lf\n", n.weight[1]);
	n.weight[2] = randf(-1.0,1.0);
	printf("W3 => %lf\n", n.weight[2]);
	/*
	n.weight[3] = randf(-1.0,1.0);
	printf("W4 => %lf\n", n.weight[3]);
	n.weight[4] = randf(-1.0,1.0);
	printf("W5 => %lf\n", n.weight[4]);
	n.weight[5] = randf(-1.0,1.0);
	printf("W6 => %lf\n", n.weight[5]);
	n.weight[6] = randf(-1.0,1.0);
	printf("W7 => %lf\n", n.weight[6]);
	n.weight[7] = randf(-1.0,1.0);
	printf("W8 => %lf\n", n.weight[7]);
	*/
	int roda = 10;
	
	while(roda >= 1)
	{
		system("cls");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		/*
		n.weight[0] = randf(-1.0,1.0);
		printf("W1 => %lf\n", n.weight[0]);
		n.weight[1] = randf(-1.0,1.0);
		printf("W2 => %lf\n", n.weight[1]);
		n.weight[2] = randf(-1.0,1.0);
		printf("W3 => %lf\n", n.weight[2]);
		n.weight[3] = randf(-1.0,1.0);
		printf("W4 => %lf\n", n.weight[3]);
		n.weight[4] = randf(-1.0,1.0);
		printf("W5 => %lf\n", n.weight[4]);
		n.weight[5] = randf(-1.0,1.0);
		printf("W6 => %lf\n", n.weight[5]);
		n.weight[6] = randf(-1.0,1.0);
		printf("W7 => %lf\n", n.weight[6]);
		n.weight[7] = randf(-1.0,1.0);
		printf("W8 => %lf\n", n.weight[7]);
		*/
		system("cls");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("W1 => %lf\n", n.weight[0]);
		printf("W2 => %lf\n", n.weight[1]);
		printf("W3 => %lf\n", n.weight[2]);
		/*
		printf("W4 => %lf\n", n.weight[3]);
		printf("W5 => %lf\n", n.weight[4]);
		printf("W6 => %lf\n", n.weight[5]);
		printf("W7 => %lf\n", n.weight[6]);
		printf("W8 => %lf\n", n.weight[7]);
		*/
		printf("============================\n");
		n.input[0] = rand()%2;
		printf("X1 => %ld\n", n.input[0]);
		n.input[1] = rand()%2;
		printf("X2 => %ld\n", n.input[1]);
		n.input[2] = rand()%2;
		printf("X3 => %ld\n", n.input[2]);
		/*
		n.input[3] = rand()%2;
		printf("X4 => %ld\n", n.input[3]);
		n.input[4] = rand()%2;
		printf("X5 => %ld\n", n.input[4]);
		n.input[5] = rand()%2;
		printf("X6 => %ld\n", n.input[5]);
		n.input[6] = rand()%2;
		printf("X7 => %ld\n", n.input[6]);
		n.input[7] = rand()%2;
		printf("X8 => %ld\n", n.input[7]);
		*/
		printf("============================\n");
		printf("BIAS => %.2f\n", n.bias);
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		
		double y = tanh(sigmal(n));
		//double y = sigmoid(sigmal(n));	
		printf("Y => %lf\n", y);
		
		int z= 0;
		for(z=0;z<TAM;z++)
		{
			printf("W%i Atual = %lf\n",z, n.weight[z]);
			n.weight[z] = n.weight[z]+0.1*(0.852699-y)+1*n.input[z];
			printf("W%i Novo = %lf\n",z, n.weight[z]);
			printf("\n");
		}
		
		/*
		if(y > 0){
			printf("Y => %lf\n", y);
			printf("\n\n");}
		else if(y == 0){
			printf("Y => 0\n");
			printf("\n\n");
		}
		else{
			printf("Y => %lf\n", y);
			printf("\n\n");
		}
		*/
		Sleep(25);
		roda--;
	}
	
	while(1)
	{
		i = 0;
		double saida = 0.0;
		for(i = 0; i <TAM; i++)
		{
			do{
				system("cls");
				printf("Digite o valor de entrada %i \n", i);
				scanf("%ld", &n.input[i]);
			}while(n.input[i] > 1);
		}
		
		saida = tanh(sigmal(n));
		printf("SAIDA => %lf\n ", saida);
		
		if(saida > 0){
			i = 0;
			for(i=0;i<TAM;i++)
			{
				printf("%ld \b", n.input[i]);
			}
			printf("\n");
			printf("Neuronio Ativado\n");
		}
		else{
			i = 0;
			for(i=0;i<TAM;i++)
			{
				printf("%ld \b", n.input[i]);
			}
			printf("\n");
			printf("Neuronio nao foi ATIVADO\n");
		}
		getch();
	}
	
	return 0;
}

double sigmal(struct neuronio neuro){
	double result = 0.0;
	int i = 0;
	for(i = 0; i < TAM; i++)
	{
		result += neuro.weight[i]*neuro.input[i];
	}
	return (result+neuro.bias);
}

double sigmoid(float y)
{
	return (1/(1+exp(-y)));
}

double tanh(double y)
{
	return (sin(y)/cos(y));
}

double randf(double min, double max){
	return min+(rand()/(RAND_MAX /(max-min)));
}


