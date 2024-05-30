#include <iostream>
#include<iostream>
#include<conio.h>

using namespace std;

class SparseMatrixNode
{
public:
SparseMatrixNode(int r=0, int c=0, int v=0)
{
row = r;
col = c;
val = v;
right = down = NULL;
}
void setSparseMatrixNode(int r=0, int c=0, int v=0)
{
row = r;
col = c;
val = v;
}
void setRow(int r){
row = r;
}
void setCol(int c){
col = c;
}
void setValue(int v){
val = v;
}
int getRow(){
return row;
}
int getCol(){
return col;
}
int getValue(){
return val;
}
void display(){
if(val < 10)
cout<<val<<" ";
else
cout<<""<<val<<" ";
}
SparseMatrixNode * getRight(){
return right;
}
SparseMatrixNode * getDown(){
return down;
}
void setRight(SparseMatrixNode *r){
right = r;
}
void setDown(SparseMatrixNode *r){
down = r;
}
private:
int row,col,val;
SparseMatrixNode * right, * down;
};

class SparseMatrix
{
public:
SparseMatrix(){
head = new SparseMatrixNode();
row = 0;
col = 0;
}
SparseMatrix(int r, int c){
head = new SparseMatrixNode(r, c);
row = r;
col = c;
insertRowHeads();
insertColHeads();
}
void insertRowHeads()
{
int i = 1;
SparseMatrixNode* temp = head;
while(i <= row){
SparseMatrixNode * n = new SparseMatrixNode(i);
temp->setDown(n);
temp = temp->getDown();
// cout<<i<<" Row Head Created "<<endl; i++;
}
temp->setDown(head);
}
void insertColHeads()
{
int i = 1;
SparseMatrixNode* temp = head;
while(i <= col){
SparseMatrixNode * n = new SparseMatrixNode(0, i);
temp->setRight(n);
temp = temp->getRight();
// cout<<i<<" Col Head Created "<<endl; i++;
}
temp->setRight(head);
}

void insert(int r,int c, int val){
SparseMatrixNode *node = new SparseMatrixNode(r, c, val);
SparseMatrixNode * rowHead = getRowHead(r);
SparseMatrixNode * colHead = getColHead(c);
insertRowWise(rowHead,node);
insertColWise(colHead, node);
}
void insertRowWise(SparseMatrixNode* rh, SparseMatrixNode *n) {

SparseMatrixNode * temp = rh;
if(temp->getRight() == NULL){
temp->setRight(n);
}
else{
while( temp->getRight() != NULL && temp->getCol() < n->getCol()){
temp = temp->getRight();
}
temp->setRight(n);
}
// cout<<"Row Wise Insertion Successfull "<<endl; }
void insertColWise(SparseMatrixNode* dh, SparseMatrixNode *n) {

SparseMatrixNode * temp = dh;
if(temp->getDown() == NULL){
temp->setDown(n);
}
else{
while( temp->getDown() != NULL && temp->getRow() < n->getRow()){
temp = temp->getDown();
}
temp->setDown(n);
}
// cout<<"Column Wise Insertion Successfull "<<endl; }
SparseMatrixNode* getRowHead(int r){
SparseMatrixNode * temp = head;
int i = 1;
while (i <= r){
temp = temp->getDown();
i++;
}
return temp;
}
SparseMatrixNode* getColHead(int c){
SparseMatrixNode * temp = head;
int i = 1;
while (i <= c){
temp = temp->getRight();
i++;
}
return temp;
}
void displaySparseMatrix(){
int i = 1;
while(i <= row){
SparseMatrixNode * temp = getRowHead(i);
displayList(temp);
cout<<endl;
i++;
}
}

void displayList(SparseMatrixNode * rh){
SparseMatrixNode * rowHead = rh->getRight();
int i = 1;
while(i <= col ){
if(rowHead != NULL && i == rowHead->getCol()) {
rowHead->display();
rowHead = rowHead->getRight();
}
else
cout<<"0 ";

i++;
}

}

private:
SparseMatrixNode * head;
int row,col;
};
int main()
{
SparseMatrix matrix1(4, 5);
matrix1.insert(1,1,5);
matrix1.insert(1,2,7);
matrix1.insert(1,4,8);
matrix1.insert(2,1,9);
matrix1.insert(2,4,3);
matrix1.insert(3,2,2);
matrix1.insert(4,1,4);
matrix1.insert(4,5,3);
matrix1.displaySparseMatrix();
cout<<endl<<endl;
SparseMatrix matrix2(4, 5);
matrix2.insert(1,2,8);
matrix2.insert(1,3,1);
matrix2.insert(1,4,7);
matrix2.insert(2,2,3);
matrix2.insert(2,3,2);
matrix2.insert(3,1,5);
matrix2.insert(3,3,7);
matrix2.insert(4,3,9);
matrix2.insert(4,4,6);
matrix2.displaySparseMatrix();

getch();
return 0;
}
1 class comment

Muhammad Ahmad IqbalApr 3
#include <iostream>
#include<conio.h>

using namespace std;

class SparseMatrixNode
{
public:
SparseMatrixNode(int r = 0, int c = 0, int v = 0)
{
row = r;
col = c;
val = v;
right = down = NULL;
}
void setSparseMatrixNode(int r = 0, int c = 0, int v = 0)
{
row = r;
col = c;
val = v;
}
void setRow(int r) {
row = r;
}
void setCol(int c) {
col = c;
}
void setValue(int v) {
val = v;
}
int getRow() {
return row;
}
int getCol() {
return col;
}
int getValue() {
return val;
}
void display() {
if (val < 10)
cout << val << " ";
else
cout << "" << val << " ";
}
SparseMatrixNode* getRight() {
return right;
}
SparseMatrixNode* getDown() {
return down;
}
void setRight(SparseMatrixNode* r) {
right = r;
}
void setDown(SparseMatrixNode* d) {
down = d;
}
private:
int row, col, val;
SparseMatrixNode* right;
SparseMatrixNode* down;
};

class SparseMatrix
{
public:
SparseMatrix() {
head = new SparseMatrixNode();
row = 0;
col = 0;
}
SparseMatrix(int r, int c) {
head = new SparseMatrixNode(r, c);
row = r;
col = c;
insertRowHeads();
insertColHeads();
}
void insertRowHeads()
{
int i = 1;
SparseMatrixNode* temp = head;
while (i <= row) {
SparseMatrixNode* n = new SparseMatrixNode(i);
temp->setDown(n);
temp = temp->getDown();
i++;
}
temp->setDown(head);
}
void insertColHeads()
{
int i = 1;
SparseMatrixNode* temp = head;
while (i <= col) {
SparseMatrixNode* n = new SparseMatrixNode(0, i);
temp->setRight(n);
temp = temp->getRight();
i++;
}
temp->setRight(head);
}

void insert(int r, int c, int val) {
SparseMatrixNode* node = new SparseMatrixNode(r, c, val);
SparseMatrixNode* rowHead = getRowHead(r);
SparseMatrixNode* colHead = getColHead(c);
insertRowWise(rowHead, node);
insertColWise(colHead, node);
}
void insertRowWise(SparseMatrixNode* rh, SparseMatrixNode* n) {

SparseMatrixNode* temp = rh;
while (temp->getRight() != NULL && temp->getRight()->getCol() < n->getCol()) {
temp = temp->getRight();
}
n->setRight(temp->getRight());
temp->setRight(n);
}
void insertColWise(SparseMatrixNode* dh, SparseMatrixNode* n) {

SparseMatrixNode* temp = dh;
while (temp->getDown() != NULL && temp->getDown()->getRow() < n->getRow()) {
temp = temp->getDown();
}
n->setDown(temp->getDown());
temp->setDown(n);
}
SparseMatrixNode* getRowHead(int r) {
SparseMatrixNode* temp = head;
int i = 1;
while (i <= r) {
temp = temp->getDown();
i++;
}
return temp;
}
SparseMatrixNode* getColHead(int c) {
SparseMatrixNode* temp = head;
int i = 1;
while (i <= c) {
temp = temp->getRight();
i++;
}
return temp;
}
void displaySparseMatrix() {
int i = 1;
while (i <= row) {
SparseMatrixNode* temp = getRowHead(i);
displayList(temp);
cout << endl;
i++;
}
}

void displayList(SparseMatrixNode* rh) {
SparseMatrixNode* rowHead = rh->getRight();
int i = 1;
while (i <= col) {
if (rowHead != NULL && i == rowHead->getCol()) {
rowHead->display();
rowHead = rowHead->getRight();
}
else
cout << "0 ";

i++;
}

}

private:
SparseMatrixNode* head;
int row, col;
};

int main()
{
SparseMatrix matrix1(4, 5);
matrix1.insert(1, 1, 5);
matrix1.insert(1, 2, 7);
matrix1.insert(1, 4, 8);
matrix1.insert(2, 1, 9);
matrix1.insert(2, 4, 3);
matrix1.insert(3, 2, 2);
matrix1.insert(4, 1, 4);
matrix1.insert(4, 5, 3);
matrix1.displaySparseMatrix();
cout << endl << endl;
SparseMatrix matrix2(4, 5);
matrix2.insert(1, 2, 8);
matrix2.insert(1, 3, 1);
matrix2.insert(1, 4, 7);
matrix2.insert(2, 2, 3);
matrix2.insert(2, 3, 2);
matrix2.insert(3, 1, 5);
matrix2.insert(3, 3, 7);
matrix2.insert(4, 3, 9);
matrix2.insert(4, 4, 6);
matrix2.displaySparseMatrix();

getch();
return 0;
}