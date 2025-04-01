#pragma once
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
#define MAXNUM 100
typedef int Element;
typedef struct {
	int length;
	Element data[MAXNUM];
}List;
typedef struct {
	int length_Seq;
	Element* data;
}Seq;
Seq* initList() {
	Seq* L = (Seq*)malloc(sizeof(Seq));
	L->data = (Element*)malloc(sizeof(Element) * MAXNUM);
	L->length_Seq = 0;
	return L;
}
void initiate(List& L) {
	L.length = 0;
}
void append(List& L, Element ex) {
	if (L.length >= MAXNUM) {
		cout << "Occupied" << '\t';
	}
	L.data[L.length] = ex;
	L.length++;
}
//DO  I  HAVE TO USE INT INSTEAD OF VOID
void show(List& L) {
	int i = 0;
	for (i;i < L.length;i++) {
		cout << L.data[i] << '\t';
	}
	cout << i+1 << endl;
}
void insert_Toward_R(List& L, Element new1, Element posi) {
	int temp = 0;
	if (posi > L.length) {
		if (posi == L.length + 1) {
			append(L, new1);
		}
		else {
			cout << "Are you kidding?" << endl;
			return;
		}
	}
	for (int i = 0;i < L.length + 1;i++) {
		if (L.data[posi] == NULL) {//When it get to the edge, we have some term to put in it.
			L.data[posi] = temp;
			break;
		}
		temp = L.data[posi];//Don't have the chance to change;Temp = 76
		L.data[posi] = new1;//L.data[0] = 65
		++posi;//There isn't have third integer.
		temp = L.data[posi];//Temp = 107
		L.data[posi] = temp;//L.data[1] = 76
		++posi;//posi = 2
	}
	L.length += 1;
}
void insert_Toward_L(List& L, Element new1, Element posi) {
	if (posi <= L.length) {
		if (posi - 1 == L.length) {
			append(L, new1);
		}
		else {
			for (int i = L.length - 1;i >= posi - 1;i--) {
				L.data[i + 1] = L.data[i];
			}
			/*for (int i = L.length;i >= posi-1;i--)
				L.data[i] = [i-1];*/
		}

		L.data[posi - 1] = new1;
		L.length++;
	}
}
void delete_ele(List& L, Element posi) {
	int item = 0;
	item = L.data[posi - 1];
	if (posi <= L.length && posi > 0) {
		for (int i = posi - 1;i < L.length - 1;i++) {
			L.data[i] = L.data[i + 1];
			L.length--;
		}
	}
	cout << item << " has been removed." << endl;
}
//Use two methods to delete data----Posi or Target
void recover(List& L) {

}
//To recover the data that had been deleted already
void search(List& L, Element Target) {
	int i = 0;
	int a = 0;
	for (i = 0;i < L.length;i++) {
		if (Target == L.data[i]) {
			cout << Target << " has been found, and the data is at the " << i + 1 << endl;
		}
	}
}

typedef struct Node{
	Element data;
	Node* next;
};
Node* iniation() {
	Node* H = (Node*)malloc(sizeof(Node));
	H->data = 0;
	H->next = NULL;
	return H;
}
//Why do i need to create another pointer in this func :<
void insert_C(Node*L,Element e ) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
}
//Running Range: How do i konw How many nodes in this chain.
void show_C(Node* L) {
	Node* p = (Node*)malloc(sizeof(Node));
	p = L->next;
	while (p != NULL) {
		cout << p->data << endl;
		p = p->next;
	}
}
Node* getTail(Node*L) {
	Node* p = (Node*)malloc(sizeof(Node));
	p = L->next;
	while (p != NULL) {
		cout << p->data << endl;
		p = p->next;
	}
	return p;
}
void insert_CTail(Node* L, Element e) {
	Node* M= getTail(L);
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = NULL;
	M->next = p;
	free(p);
}


