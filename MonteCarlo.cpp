//	Monte Carlo Integration

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define		Sample_Size		1000		//	Total replication

//#define 	Total_Points	300			//	number of Ui's for each integration.

double mean;

double function(double x)
{
	return sqrt(9.0-x*x);
}

double Integration(double a, double b)
{
	double rn;
	
	rn = (b-a)*((double)rand())/(double)RAND_MAX; // Generating a random number within a & b;
	
	
	return (function(rn));		//	actually the return value is ((b-a)/3)*f(x), 
								//	here b-a itself 3, so just return f(x)
}


double FindVariance(double num[], int size, double mean)	//	
{
	double variance=0.0;

	int i;
	
	
	for(i=0;i<size;i++) variance += (num[i] - mean)*(num[i] - mean);
	
	return (variance/(double)(size-1));
	
}


double HalfWidth(double x[], int sample_size, double *mean){
	
	int i;
	double SnSquare, t95_999 = 1.962341416;
	
	//for(i=0; i<sample_size; i++) X[i] = MonteCarloIntegration();
	
	*mean=0.0;
	
	for(i=0;i<sample_size;i++) *mean += x[i];
	
	*mean /= (double)sample_size;
	
	SnSquare = FindVariance(x, sample_size, *mean);
	
	return (t95_999 * sqrt(SnSquare/sample_size));
}


void Integration_Anti(double *x1, double *x2)
{
	double rn;
	
	
	rn = 3.0*((double)rand())/(double)RAND_MAX; //printf("%lf\n", rn);
	
	*x1 = function(rn);
	
	*x2 = function(3.0-rn);	
}

int main(void)
{
	
	srand (time(NULL));		//	To initialize the rand() function
	
	double mean, X[Sample_Size], X1[Sample_Size/2], X2[Sample_Size/2];
		
	for(int i=0; i<Sample_Size; i++) X[i] = Integration(0.0, 3.0);
	
	double hw1 = HalfWidth(X, Sample_Size, &mean);
	
	printf("\tMonte Carlo Integration...\n\n\tMean = %lf and Half Width (at 95%% level) = %lf", mean, hw1);
	
	printf("\n\n\tConfidence Interval = [%lf, %lf]", mean-hw1, mean+hw1);
	
	
	for(int i=0; i<Sample_Size/2; i++) {	
		
		Integration_Anti(&X1[i], &X2[i]); X[i] = (X1[i]+X2[i])/2.0;
	}
	
	double hw2 = HalfWidth(X, Sample_Size/2, &mean);		//	new mean will be calculated
	
	printf("\n\n\n\tUsing Antithetic Variates...\n\n\tMean = %lf and Half Width (at 95%% level) = %lf", mean, hw2);
	
	printf("\n\n\tConfidence Interval = [%lf, %lf]", mean-hw2, mean+hw2);
	
	printf("\n\n\tConfidence Interval reduction = %lf%%\n", (hw1-hw2)*100.0/hw1);
	
	
	return 0;
}
