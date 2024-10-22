#include<stdio.h>
#include<math.h>
int main(){
float a,b,c,D,r1,r2,realP, imagP;
printf( "Enter the value of a: ");
scanf ("%f" ,&a);
printf("Enter the value of b: ");
scanf ("%f", &b);
printf("Enter the value of c: ");
scanf ("%f", &c);
D=b*b-4*a*c;
int p=sqrt(b*b-4*a*c);
if (D>0){
printf("The roots are real and distinct");
r1=(-b+p) / (2*a);
r2= (-b-p) /(2*a);
printf("The roots are %f and %f", r1,r2);
}
else if(D==0){
printf("The roots are real and equal");
r1=r2=-b/ (2*a);
printf("The roots are %f and %f", r1,r2);
}
else{
realP = -b / (2*a);
imagP = sqrt(-D) / (2 * a);
printf("root1 = %f+%fi and root2 = %f-%fi", realP, imagP, realP, imagP);
}
return 0;
}