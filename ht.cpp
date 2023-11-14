#include <iostream>
using namespace std;
class Node 											// Node class for linked list
{
public:
    int data;       								// Data of the node
    Node* next;     								// Pointer to the next node in the list
    Node(int value)									// Constructor
	{
		data=value;
		next=nullptr;
	}
};

class LinkedList 									// LinkedList class to manage the linked list operations
{
private:
    Node* head;      								// Pointer to the head of linked-list

public:
    LinkedList() 									// Constructor
	{
		head=nullptr;
	}
	
	void insert(int value) 	  						// insert a new node at the end of the list
	{
		Node* newNode = new Node(value);			// Create a new node
    	if (head==nullptr) 	  			 			// if the list is empty
		{
        	head=newNode;	  						// set the new node as the head
    	} 
		else	 									// If the list is not empty, move to the last node in the linkedlist
		{
        	Node* temp=head;						//initialize temp pointer with the head
        	while (temp->next!=nullptr) 			//iterate as long as the next pointer of temp node is not pointing to the nullptr
			{
            	temp=temp->next;					//moves the temp pointer to the next node in each iteration
        	}
        	temp->next=newNode;						// temp now points to the last node where it  adds the newNode
    	}
	}
    
	bool search(int value) 							// search for a value in the linked list
	{
        Node* temp=head;							//initialize temp pointer with the head
        // move to the list
        while (temp != nullptr)		 				//iterate as long as the next pointer of temp node is not pointing to the nullptr
		{
            if (temp->data==value) 					// If the value is found, return true
			{
                return true;
            }
            temp=temp->next;						//moves the temp pointer to the next node in each iteration
        }
        return false;								// If the value is not found, return false
    }

	bool update(int position,int newValue) 			//update for a value at a specific position
	{
    	Node* temp=head;               				// Create a temp pointer and initialize it with the head
    	int cposition=0;         					// Variable to track the current position while moving
    	while (temp!=nullptr&&cposition<position) 	// moving in the list to find the node at specified position
		{
        	temp=temp->next;           				// Move the temp pointer to the next node in each iteration
        	cposition++;          					// Increment the current position
    	}
    	if (temp!=nullptr) 							// If the position is valid
		{
        	temp->data=newValue;       				// Update the value of the node at the specified position
        	cout<<"Value at "<<position<<" position, updated to "<<newValue<<endl;
        	return true;
    	} 
		else										// If the position is invalid
		{
        	cout<<"Invalid position"<<endl;
        	return false;               
    	}
	}

    void insert_npos(int position, int value) 		// insert a new node with a given value at a specific position
	{
        Node* newNode=new Node(value);				//Create a new node to be inserted in linkedlist with the given value
        if (position==0) 							// Insert at the beginning
		{
            newNode->next=head;		 				//Update the next pointer of the new node to point to the current head of the list
            head=newNode;							// Set the head of the list to the new node
        } 
		else 
		{
            Node* temp=head;						//Create a temp pointer and initialize it with the head
            int currentPosition=0;					//initialize current position at 0 index
            while (temp!=nullptr && currentPosition<position-1) 	// move through the node just before the specified position
			{
                temp=temp->next;					//Move the temp pointer to next node in each iteration.
                currentPosition++;					//Increment in the current position
            }
            if (temp!=nullptr) 
			{
                newNode->next=temp->next;			//set the next pointer of the new node to the next node of temp
                temp->next=newNode;					//Update the next pointer of temp to point to the new node
            } 
			else	 								// If the position is invalid
			{
                cout<<"Invalid position."<<endl;
            }
        }
    }

    void delfromBeginning() 						// delete the node from beginning of the list
	{
    	if (head!=nullptr) 							// Check if the list is not empty
		{   
        	Node* temp = head;  					// Create a temp pointer and initialize it with the head
        	head = head->next;    					// Move the head to the next node
        	delete temp;          					// Delete the first node
        	cout << "Node deleted from the beginning of the list." << endl;
    	} 
		else 										// If the list is empty
		{
        	cout << "Empty." << endl;
    	}
	}

    void delfromEnd() 								// delete the node from the end of the linked list
	{
    	if (head!=nullptr) 							// Check if the list is not empty (head is not nullptr)
		{  
        	if (head->next==nullptr) 				// If there is only one node in the list
			{
            	delete head;       					// Delete the only node
            	head = nullptr;   					// Set the head to nullptr since the list is now empty
        	} 
			else 
			{
            	Node* temp=head;  					// Create a temp pointer and initialize it with the head
            	Node* prev=nullptr;					// Pointer to keep track of the previous node while moving
            	while (temp->next!=nullptr) 		// move to the last node
				{
                	prev=temp;       				// Update the previous node to the current node
                	temp=temp->next; 				// Move to the next node in each iteration
            	}
            	delete temp;						// Delete the last node
            	if (prev!=nullptr) 
				{
                	prev->next=nullptr;  			// Set the next pointer of the previous node to nullptr
            	} 
				else 
				{
                	head = nullptr;					// If there was only one node, update the head to nullptr
            	}
        	}
			cout<<"Last Node deleted from the end of the list."<<endl;
    	} 
		else 
		{
        	cout<<"Empty"<<endl;
    	}
	}

	void del_npos(int position) 					//delete node from any n position
	{
    	if (head!=nullptr) 							// if the list is not empty
		{
        	Node* temp=head;  	  					// Create a temp pointer and initialize it with the head
        	Node* prev=nullptr; 	 				// Pointer to keep track of the previous node while moving
        	int cposition = 0;  					// Variable to track the current position
        	while (temp!=nullptr&&cposition<position) 
			{
            	prev=temp;       					// Update the previous node to the current node
            	temp=temp->next; 					// Move to the next node in each iteration
            	cposition++; 						// Increment the current position
        	}
        	if (temp!=nullptr) 
			{
            	if (prev==nullptr) 
				{
                	head=temp->next;  				// If the node to be deleted is the first node, update the head
            	} 
				else 
				{
                	prev->next=temp->next;  		// Update the next pointer of the previous node to skip the node to be deleted
            	}
            delete temp;  							// Delete the node at the specified position
            cout<<"Node deleted from "<<position<<" position."<<endl;
        	} 
			else 									// If the position is invalid
			{
            cout<<"Invalid position"<<endl;
        	}
    	} 
		else 										// If the list is empty
		{
        cout<<"Empty"<<endl;
    	}
	}
    
    bool search_update(int searchValue, int newValue) 
	{
    	Node* temp = head; 							// Initialize a temp pointer with the head
    	int position = 0;   						// Initialize a variable to track the position of the current node
    	while (temp != nullptr) 
    	{
        	if (temp->data == searchValue) 			// If the value is found, update it
        	{
            	temp->data = newValue;
            	cout << "Value " << searchValue << " found and updated to " << newValue << " at position " << position << "." << endl;
            	return true;
        	}
        	temp = temp->next;  					// Move to the next node in each iteration
        	position++;         					// Increment the position variable
    	}
    	// If value not found
		cout << "Value " << searchValue << " not found in the linked list." << endl;
    	return false;
	}
    
    void display() 									// display the elements of the linked list
	{
        Node* temp=head;
        while (temp!=nullptr) 
		{
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

main() 
{
    LinkedList list;
    
	// Inserting elements into the linked list
    list.insert(4);
    list.insert(3);
    list.insert(7);
    list.insert(2);
    cout<<"Linked List: ";
    list.display();
    
	// Searching
    int s=3;
    if (list.search(s)) 
	{
        cout<<s<<" found!"<<endl;
    } 
	else 
	{
        cout<<s<<" not found!"<<endl;
    }
    
	// Update
    int p=2, newValue=35;
    list.update(p,newValue);
    cout<<"Linked List after updating node at "<<p<<" position: ";
    list.display();
    
	// Insert at a specific position
    int po= 2, v=25;
    list.insert_npos(po,v);
    cout<<"Linked List after inserting value at "<<p<<" position: ";
    list.display();
    
	// Deleting from the beginning
    list.delfromBeginning();
    cout<<"Linked List after deleting node from beginning: ";
    list.display();

    // Deleting from a specific position
    int pos=2;
    list.del_npos(pos);
    cout<<"Linked List after deletion from "<<p<<" position: ";
    list.display();

    // Deleting from the end
    list.delfromEnd();
    cout<<"Linked List after deleting node from the end: ";
    list.display();
    
    // Searching and updating
    int searchValue = 3, nvalue = 42;
	list.search_update(searchValue, nvalue);
	cout<<"value found and updated. linked list:";
	list.display();
}