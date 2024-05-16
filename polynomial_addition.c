#include<stdio.h>
#include<stdlib.h>
struct Term{
    int coefficient;
    int exponent;
};
void inputPolynomial(struct Term *poly,int degree){
    printf("Enter the coefficients for the polynomial:\n");
    for (int i=0;i<=degree;i++){
        printf("Coefficient for x^%d:",i);
        scanf("%d",&poly[i].coefficient);
        poly[i].exponent=i;
    }
}
void addPolynomials(struct Term *poly1,struct Term *poly2,struct Term *result,int degree){
    for(int i=0;i<=degree;i++){
        result[i].coefficient=poly1[i].coefficient+poly2[i].coefficient;
        result[i].exponent=i;
    }
}
void displayPolynomial(struct Term *poly,int degree){
    printf("Resultant Polynomial:");
    for(int i=degree;i>=0;i--){
        if(poly[i].coefficient!=0){
            printf("%dx^%d",poly[i].coefficient,poly[i].exponent);
            if(i>0&&poly[i-1].coefficient!=0){
                printf(" + ");
            }
        }
    }
    printf("\n");
}
int main(){
    int degree;
    printf("Enter the degree of the polynomials:");
    scanf("%d",&degree);
    struct Term *poly1=(struct Term *)malloc((degree+1)*sizeof(struct Term));
    struct Term *poly2=(struct Term *)malloc((degree+1)*sizeof(struct Term));
    struct Term *result=(struct Term *)malloc((degree+1)*sizeof(struct Term));
    printf("For the first polynomial:\n");
    inputPolynomial(poly1,degree);
    printf("For the second polynomial:\n");
    inputPolynomial(poly2,degree);
    addPolynomials(poly1,poly2,result,degree);
    displayPolynomial(result,degree);
    free(poly1);
    free(poly2);
    free(result);
    return 0;
}