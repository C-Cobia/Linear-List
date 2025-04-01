#include"func.h"
void func(int*a,int*b) {
	int tem = *a;
	*a = *b;
	*b = tem;
}
int main() {
	/*initiate(L1);
	
	insert_Toward_L(L1, 99, 1);
	delete_ele(L1, 3);
	search(L1, 10);
	
	cout << endl;
	cout << L1.length << '\t' << sizeof(L1.data) << endl;*/
	//Seq *List;
	Node* Shit = iniation();
	insert_CHead(Shit, 45);
	insert_CTail(Shit, 67);
	show_C(Shit);

	
	return 0;
}
