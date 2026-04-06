#include <bits/stdc++.h>
using namespace std;
/**
简易环形队列
**/
int capacity=10;
int queue[capacity]={0};
//front指向队列的第一个元素，rear指向队列最后一个有效元素的下一个位置
int front=-1,rear=0;

void add_element(int element){
	if(rear==front)
		front=(front+1)%capacity;
	else
		front=0;
	queue[rear]=element;
	rear=(rear+1)%capacity;
}

int main(){
	add_element(1);
	
	

	
	
	return 0;
}