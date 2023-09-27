#include <iostream>
using namespace std;


struct Element
{
	// ������
	char data;
	// ����� ���������� �������� ������
	Element* Next;
};

// ����������� ������
class List
{
	// ����� ��������� �������� ������
	Element* Head;
	// ����� ��������� �������� ������
	Element* Tail;
	// ���������� ��������� ������
	int Count;

public:
	// �����������
	List();
	// ����������
	~List();

	// ���������� �������� � ������
	// (����� ������� ���������� ���������)
	void Add(char data);
	void Insert(char data, int index);
	int Find(char c);

	// �������� �������� ������
	// (��������� �������� �������)
	void Del();
	void Del(int index);
	// �������� ����� ������
	void DelAll();

	// ���������� ����������� ������
	// (���������� ���������� � ��������� ��������)
	void Print();

	// ��������� ���������� ���������, ����������� � ������
	int GetCount();
};

List::List()
{
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// ����� ������� ��������
	DelAll();
}

int List::GetCount()
{
	// ���������� ���������� ���������
	return Count;
}

void List::Add(char data)
{
	// �������� ������ ��������
	Element* temp = new Element;

	// ���������� �������
	temp->data = data;
	// ��������� ������� �����������
	temp->Next = NULL;
	// ����� ������� ���������� ��������� ��������� ������
	// ���� �� �� ������ �����������
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// ����� ������� ���������� ������������
	// ���� �� ������ �����������
	else {
		Head = Tail = temp;
	}
}
void List::Insert(char data, int index)
{
	Element* t = new Element;
	t->data = data;
	Element* temp = Head;
	int a = 0;
	while (a < index-1)
	{
		temp = temp->Next;
		a++;
	}
	t->Next = temp->Next;
	temp->Next = t;
	Count++;
}
void List::Del(int index)
{
	Element* temp = Head;
	while (index > 2)
	{
		temp = temp->Next;
		index--;
	}
	Element* del = temp->Next;
	temp->Next = del->Next;
	delete del;
}
int List::Find(char c)
{
	Element* temp = Head;
	int i = 1;
	while (temp->Next != nullptr)
	{
		if (temp->data = c)
			return i;
		else
		{
			i++;
			temp = temp->Next;
		}
	}
	return NULL;
}

void List::Del()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ������������� ������ �� ��������� �������
	Head = Head->Next;
	// ������� ������ �������� �������
	delete temp;
}

void List::DelAll()
{
	// ���� ��� ���� ��������
	while (Head != 0)
		// ������� �������� �� ������
		Del();
}

void List::Print()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ���� ��� ���� ��������
	while (temp != 0)
	{
		// ������� ������
		cout << temp->data << " ";
		// ��������� �� ��������� �������
		temp = temp->Next;
	}

	cout << "\n\n";
}

// �������� ������
void main()
{
	// ������� ������ ������ List
	List lst;
	lst.Add('1');
	lst.Add('1');
	lst.Add('1');
	lst.Insert('2',1);
	lst.Print();
	cout << lst.Find('2');
}

