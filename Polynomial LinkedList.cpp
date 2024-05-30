#include <iostream>

class Term{
public:
Term(){
coef = 0;
exp = 0;
variable = 'X';
}
Term(int coef,int exp,char variable){
Term::coef = coef;
Term::exp = exp;
Term::variable = variable;
}
void display(){
std::cout<<coef<<" X ^ "<<exp;
}

int getCoef() const {
return coef;
}

void setCoef(int coef) {
Term::coef = coef;
}

int getExp() const {
return exp;
}

void setExp(int exp) {
Term::exp = exp;
}

char getVariable() const {
return variable;
}

void setVariable(char variable) {
Term::variable = variable;
}

private:
int coef;
int exp;
char variable;
};

class Polynomial{
public:
Polynomial(int deg){
degree = deg;
size = degree + 1;
terms = new Term*[size];
for (int i = 0; i < size; ++i) {
terms[i] = new Term(0,0,'X');
}
}
Polynomial(int deg,int x[]){
degree = deg;
size = degree + 1;
terms = new Term *[size];
for (int i = 0, j =size-1; i < size; ++i,j--) {
terms[i] = new Term(x[j],j,'X');
}
}
void display(){
for (int i = 0; i < size; i++) {
terms[i]->display();
std::cout<<" + ";
}
std::cout<<std::endl;
}
private:
Term **terms;
int degree;
int size;
};

int main() {
int x1[] = {6,5,2};
Polynomial polynomial1(2,x1);
polynomial1.display();
std::cout<<std::endl;
int x2[] = {7,0,2,0,5};
Polynomial polynomial2(4,x2);
polynomial2.display();

return 0;
}