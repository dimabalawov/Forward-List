#include <iostream>
using namespace std;


struct Element
{
	// Данные
	char data;
	// Адрес следующего элемента списка
	Element* Next;
};

// Односвязный список
class List
{
	// Адрес головного элемента списка
	Element* Head;
	// Адрес головного элемента списка
	Element* Tail;
	// Количество элементов списка
	int Count;

public:
	// Конструктор
	List();
	// Деструктор
	~List();

	// Добавление элемента в список
	// (Новый элемент становится последним)
	void Add(char data);
	void Insert(char data, int index);
	int Find(char c);

	// Удаление элемента списка
	// (Удаляется головной элемент)
	void Del();
	void Del(int index);
	// Удаление всего списка
	void DelAll();

	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();
};

List::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// Вызов функции удаления
	DelAll();
}

int List::GetCount()
{
	// Возвращаем количество элементов
	return Count;
}

void List::Add(char data)
{
	// создание нового элемента
	Element* temp = new Element;

	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// новый элемент становится единственным
	// если он первый добавленный
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
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// перебрасываем голову на следующий элемент
	Head = Head->Next;
	// удаляем бывший головной элемент
	delete temp;
}

void List::DelAll()
{
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
}

void List::Print()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}

	cout << "\n\n";
}

// Тестовый пример
void main()
{
	// Создаем объект класса List
	List lst;
	lst.Add('1');
	lst.Add('1');
	lst.Add('1');
	lst.Insert('2',1);
	lst.Print();
	cout << lst.Find('2');
}

