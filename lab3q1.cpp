/*Implement Doubly Linked List using C++. Make sure the following functions are implemented: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 
*/
//library
#include <iostream>
using namespace std;
class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    Node * prev;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        prev = NULL;
        data = value;
    }
};

class DLL{
    public:
    Node * head;
    DLL(){
        head = NULL;
    }
    void insert(int value){
        // Create a new node
        Node * temp = new Node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ // If not empty list. 
            Node * current = head;
            while(current->next != NULL)
                current = current->next;
            current->next = temp;
            temp->prev = current;    
        }
    }
    void display(){
        Node *current = head;
        Node *last;
        cout << "Print in   order : ";
        while(current!=NULL){
            cout <<current->data<< "->"; 
            // Store the current in last (to catch the tail to print in reverse)
            last = current;
            // Move Forward
            current = current->next;
        }
        cout << endl;
        cout << "Print in R order : ";
        while(last!=NULL){
            cout <<last->data<< "->";
            // Move backwards 
            last = last->prev;
        }
        cout << endl;   
    }
    void InsertAt(int value, int pos){
	Node * temp = new Node(value);
        Node * current = head;
	int i = 1;
	if(pos==1)
	{
		temp->next = current;
		current->prev = temp;
		head = temp;
	}
	else
	{
		while(i<(pos-1))
		{
			i++;
			if(current->next == NULL)
			{	
				cout<<"linkedlist does not have that many elements"<<endl;
				break;
			}
			else
			{
				current = current->next;
			}
		}
		temp->next = current->next;
		current->next = temp;
		temp->prev = current;
		temp->next->prev = temp;
	}
    }
    void DeleteAt(int pos){
	Node * temp;
	Node * current = head;
	if(pos == 1)
	{
		head = current->next;
		current->next->prev = NULL;
		delete current;
	}
	else
	{
		int i = 1;
		while(i<(pos-1))
		{
			i++;
			current = current->next;
		}
		temp = current->next;
		current->next = temp->next;
		current->next->prev = current;
		delete temp;
	}
	
    }
    void Del(){
	Node * current = head;
        while(current->next->next != NULL)
	{
		current = current->next;
	}
	Node * temp = current->next;
	current->next = NULL;
	delete temp;
    }
    void CountItems(){
        //declaring variables
	int i=0;
	//point current to head
	Node * current = head;
	//use while loop
	while(current!= NULL)
	{
		i++;
		current = current->next;
	}
	cout<<"The number of items is "<<i<<endl;
    }

};

int main(){
    DLL dll1;
    for(int i= 1; i < 11; i++){
        dll1.insert(i);
    }
    dll1.display();
    dll1.Del();
    dll1.display();
    dll1.CountItems();
    dll1.InsertAt(5,4);
    dll1.display();
    dll1.DeleteAt(4);
    dll1.display();
}

