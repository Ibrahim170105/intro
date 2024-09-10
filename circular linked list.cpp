#include <iostream>
using namespace std;
class list
{
	struct node
	{
		int data;
		node*next;	
	};
	
	public:
		
	node*head;
	
	list()
	{
		head = NULL;
	}
	 void add_node_tail(int val)
    {
        node* ptrnew = new node;
        node* ptrtemp = head;
        ptrnew->data = val;
        ptrnew->next = NULL;
        if (head == NULL)
        {
            head = ptrnew;
            return;
        }
        while (ptrtemp->next != NULL)
        {
            ptrtemp = ptrtemp->next;
        }
        ptrtemp->next = ptrnew;
    }
    
    void circular_convert()
	{
		node*temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = head;
	}
	void display()
    {
        node*temp = head;
        cout << endl;
        cout << temp->data << ",";
        temp = temp->next;
        
        while (temp != head)
        {
            cout << temp->data << ",";
            temp = temp->next;
        }
	}
	node* get_node(int val)
	{
		node* temp=head;
		
		while(temp->data != val)
		{
			temp=temp->next;
		}
		
		return temp;
	}
	void make_head(node* temp)
	{
		head=temp;
	}
	
	void split_merge(node*head1)
	{
		node*temp = head;
		
		while (temp->next != head)
		{
			temp = temp->next;
		}
		node*temp1 = head1;
		while (temp1->next != head1)
		{
			temp1 = temp1->next;
		}
		temp->next = head1;
		temp1->next = head;
	}
};
int main()
{

	list l1,l2;
	l1.add_node_tail(23);
	l1.add_node_tail(245);
	l1.add_node_tail(1);
	l1.add_node_tail(2);
	l1.circular_convert();
	l2.add_node_tail(9);
	l2.add_node_tail(13);
	l2.add_node_tail(4);
	l2.add_node_tail(7);
	l2.circular_convert();
	cout<<endl<<"Initially "<<endl;
	cout<<endl<<"l1 : ";
	l1.display();
	cout<<endl<<endl<<"l2 : ";
	l2.display();
	cout<<endl<<endl<<"Merge"<<endl;
	l1.split_merge(l2.head);
	cout<<endl<<"l1 : ";
	l1.display();
	cout<<endl<<endl<<"l2 : ";
	l2.display();
	cout<<endl<<endl<<"Split"<<endl;
	l1.split_merge(l2.head);
	cout<<endl<<"l1 : ";
	l1.display();
	cout<<endl<<endl<<"l2 : ";
	l2.display();
	cout<<endl<<endl<<"Merge"<<endl;
	l1.split_merge(l2.head);
	cout<<endl<<"l1 : ";
	l1.display();
	cout<<endl<<endl<<"l2 : ";
	l2.display();
	//l1.make_head(l1.get_node(245));
	//l1.display();
	return 0;
}
