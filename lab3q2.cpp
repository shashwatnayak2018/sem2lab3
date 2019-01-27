/*Implement Circular Linked List using C++. Make sure the following functions are implemented: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
	It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 ” for a linked list holding integers in the order 1,2,3,4. 
*/
//library
#include <iostream>
using namespace std;
//declare a class node
class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        data = value;
    }
};

class CSLL{
    public:
    Node * head;
    CSLL(){
        head = NULL;
    }
    // Inserts to the end of the linked list.
    void insert(int value){
        
        // Create a new node
        Node * temp = new Node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ // If not empty list. 
            Node * current = head;
            while(current->next != head)
                current = current->next;
            current->next = temp;
        }
        temp->next = head;
    }
    // Displays the linked list.
    void display(){
        Node * current = head;
        if(current == NULL) {
            cout << "No elements " << endl;
            return;
        }
        while(current->next != head){ // Stopping at head
            cout << current -> data << "->";
            current = current -> next;
        }
        // Printing the last element
        cout << current -> data ;
        cout << endl;
    }
    void InsertAt(int value, int pos)
	{
		Node * temp = new Node(value);
		Node * current = head;
		int i = 1;
		if(pos==1)
			{
			Node * last = head;
			while(last->next!=head)
			{
				last = last->next;
			}
			
			temp->next = current;
			head = temp;
			last->next = head;
		}
		else{
			while(i<(pos-1))
				{
					i++;
					current = current->next;
				}
				
				if(current->next == head)
				{
					temp->next = head;
					current->next = temp;
				}
				else
				{
					temp->next = current->next;
					current->next = temp;
				}
		}
    }
    void DeleteAt(int pos)
	{
		int i = 1;
		Node * current = head;
		while(i<(pos-1))
		{
			i++;
			current = current->next;
		}
		Node * temp;
		if(pos == 1)
		{
			Node * last = head;
			while(last->next!=head)
			{
				last = last->next;
			}
			temp = head;
			head = current->next;
			last->next = head;
			delete temp;
		}
		else
		{
			temp = current->next;
			current->next = temp->next;
			delete temp;
		}
    }
    void Delet()
	{
		Node * current = head;
		while(current->next->next != head)
		{
			current = current->next;
		}
		Node * temp;
		temp = current->next;
		current->next = temp->next;
		delete temp;
    }
    void CountItems()
	{
		int i = 1;
		Node * current = head;
		while(current->next != head)
		{
			i++;
			current = current->next;
		}
		cout<<"The number of elements is "<<i<<endl;
    }

};

int main(){
    CSLL csll1;
    for(int i= 1; i < 11; i++){
       csll1.insert(i);
    }
	csll1.InsertAt(2,11);
 csll1.display();
	csll1.InsertAt(4,8);
 csll1.display();
	csll1.Delet();
 csll1.display();
	csll1.DeleteAt(8);
 csll1.display();
	csll1.InsertAt(3,1);
    csll1.display();
	csll1.CountItems();
}
