#include <iostream>
#include <string>

using namespace std;

int tabs = 0; 

int kol_vo = 0;


struct Branch

{
	int Data; 
	char Ch;

	Branch* LeftBranch; 
	Branch* RightBranch;

};


void Add(int aData, Branch*& aBranch)

{

	if (!aBranch)

	{ //создадим ее и зададим в нее данные

		aBranch = new Branch;

		aBranch->Data = aData;

		aBranch->LeftBranch = 0;

		aBranch->RightBranch = 0;

		return;

	}

	else 

		if (aBranch->Data > aData)

		{ //Если оно меньше того, что в этой ветке - добавим влево

			Add(aData, aBranch->LeftBranch);

		}

		else

		{ //Иначе в ветку справа

			Add(aData, aBranch->RightBranch);

		};

}



void print(Branch* aBranch)

{

	if (!aBranch) return; 

	tabs += 5; 

	print(aBranch->RightBranch); 

	for (int i = 0; i < tabs; i++) cout << " "; 

	cout << aBranch->Data << endl; 

	print(aBranch->LeftBranch);

	tabs -= 5; 

	return;

}


void pr_obh(Branch*& aBranch)

{

	if (NULL == aBranch) return; 

	cout << aBranch->Data << endl; 

	pr_obh(aBranch->LeftBranch); 

	pr_obh(aBranch->RightBranch); 

}


void add_elem(int aData, Branch*& aBranch)

{

	if (!aBranch)

	{

		aBranch = new Branch;

		aBranch->Data = aData;

		aBranch->LeftBranch = 0;

		aBranch->RightBranch = 0;

		return;

	}

	else

	{

		if (aData < aBranch->Data) {

			add_elem(aData, aBranch->LeftBranch);

		}

		else if (aData > aBranch->Data) 
		{

			add_elem(aData, aBranch->RightBranch);

		}

	}

}

Branch* del_elem(Branch*& aBranch, int aData) //если у удаляемого элемента есть хотябы 1 дочерни, то дочерни переходит на его место
{

	if (aBranch == NULL)

		return aBranch;

	if (aData == aBranch->Data)
	{

		Branch *tmp;

		if (aBranch->RightBranch == NULL)

			tmp = aBranch->LeftBranch;

		else 
		{

			Branch* ptr = aBranch->RightBranch;

			if (ptr->LeftBranch == NULL)
			{

				ptr->LeftBranch = aBranch->LeftBranch;

				tmp = ptr;

			}

			else 
			{

				Branch* pmin = ptr->LeftBranch;

				while (pmin->LeftBranch != NULL) 
				{

					ptr = pmin;

					pmin = ptr->LeftBranch;

				}

				ptr->LeftBranch = pmin->RightBranch;

				pmin->LeftBranch = aBranch->LeftBranch;

				pmin->RightBranch = aBranch->RightBranch;

				tmp = pmin;

			}

		}

		delete aBranch;

		return tmp;

	}

	else if (aData < aBranch->Data)
	{
		aBranch->LeftBranch = del_elem(aBranch->LeftBranch, aData);
	}

	else
	{
		aBranch->RightBranch = del_elem(aBranch->RightBranch, aData);
	}
	return aBranch;

}



int node_pairs(const Branch* Root) 
{
	if (Root == nullptr)
	{
		return 0;
	}

	int n = ((Root->LeftBranch != nullptr) && (Root->RightBranch != nullptr));

	if (Root->LeftBranch != nullptr)
	{
		n += node_pairs(Root->LeftBranch);
	}

	if (Root->RightBranch != nullptr)
	{
		n += node_pairs(Root->RightBranch);
	}

	return n;
}

int main()

{

	setlocale(LC_ALL, "rus");

	Branch* Root = 0;

	int vel;

	int element;

	int k;

	cout << "Введите кол-во элементов для будущего дерева: ";

	cin >> vel;



	cout << endl;

	for (int i = 0; i < vel; i++)

	{

		Add(rand() % 100, Root);

	}


	cout << endl;

	cout << "Вывод бинарного дерева: " << endl;

	print(Root);

	cout << endl;

	cout << "Прямой обход бинарного дерева: " << endl;

	pr_obh(Root);

	cout << endl;


    cout << "Добавим новый элемент в бинарное дерево? 1-yes, 2-no" << endl;
	int y;
	cin >> y;
	if (y == 1)
	{
		cout << "Введите новый элемент: ";

		cin >> element;

		add_elem(element, Root);

		cout << "Вывод бинарного дерева: " << endl;

		print(Root);

		cout << endl;
		
		cout << "Удалим элемент из бинарного дерева? 1-yes, 2-no" << endl;
		int x;
		cin >> x;
		if (x == 1)
		{
			cout << "Введите нэлемент: ";

			cin >> element;

			del_elem(Root, element);

			cout << "Вывод бинарного дерева: " << endl;

			print(Root);

			cout << endl;

			cout << "Колличество =  " << node_pairs(Root) << endl;

		}
		else if (x == 2)
		{
			cout << "Вывод бинарного дерева: " << endl;

			print(Root);

			cout << endl;


			cout << "Колличество =  " << node_pairs(Root) << endl;
		}
	}
	else if (y == 2)
	{
		cout << "Удалим элемент из бинарного дерева? 1-yes, 2-no" << endl;
		int x;
		cin >> x;
		if (x == 1)
		{
			cout << "Введите нэлемент: ";

			cin >> element;

			del_elem(Root, element);

			cout << "Вывод бинарного дерева: " << endl;

			print(Root);

			cout << endl;

			cout << "Колличество =  " << node_pairs(Root) << endl;

		}
		else if (x == 2)
		{
			cout << "Вывод бинарного дерева: " << endl;

			print(Root);

			cout << endl;

			cout << "Колличество =  " << node_pairs(Root) << endl;
		}
	}
	return 0;
}
		
	
	
