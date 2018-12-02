#include<iostream>
#include<stdlib.h>
#include<climits>

using namespace std;

/**
 * create a node
 */
struct node
{
	int data;
	int degree;
	struct node *child;
	struct node *sibling;
	struct node *parent;
};

class binomialheap
{
	public:
	
	node *head;
	
	binomialheap()
	{
		head=NULL;
	}
	
    /**
     * create a binomial queue/tree node
     * 
     */
	node *createnode(int key)
	{
		node *root; //root node 
		root=new node;
		root->child=NULL; 
		root->sibling=NULL;
		root->parent=NULL;
		root->degree=0;
		root->data=key;
	}
	
	void insert(node *root)
	{
		head=merge(head, root); 
		cout<<"CP1"<<endl;
		head=align(head);
		cout<<"CP2"<<endl;
	}
	
	int printmin()
	{
		int min;
		node *temp;
		temp=head;
		if(!head)
			return INT_MAX;
		min=head->data;
		head=head->sibling;
		while(head)
		{
			if(head->data<min)
				min=head->data;
			head=head->sibling;
		}
		head=temp;
		return min;
	}
	
	int printheadnode()
	{
		node *temp;
		temp=head;
		if(!head)
			return INT_MAX;
		head=temp;
		return head->data;
	}
	
    /* 
     * merge two binomial trees
     */
	node *merge(node *root1, node *root2)
	{
		node *head1;
		node *temp;
		if(!root1)
			return root2;
		if(!root2)
			return root1;
		if(root1->degree<=root2->degree)
		{
			head1=root1;
			root1=root1->sibling;
		}
		else
		{
			head1=root2;
			root2=root2->sibling;
		}
		temp=head1;
		while(root1 && root2)
		{
			if(root1->degree<=root2->degree)
			{
				temp->sibling=root1;
				root1=root1->sibling;
			}
			else
			{
				temp->sibling=root2;
				root2=root2->sibling;
			}
			temp=temp->sibling;
		}
		if(root1)
			temp->sibling=root1;
		else temp->sibling=root2;
		return head1;
	}
	
    /**
     * realign the binomial queue so that it is in increasing order
     * no two binomial trees should have the same degree here
     */
	node *align(node *root)
	{
		node *temp;
		node *prev;
		node *current;
		node *next;
		node *head1;
		prev=NULL;
		current=root;
		next=current->sibling;
		if(!root->sibling)
			return root;
		while(next)
		{
			if(current->degree!=next->degree)
			{
				if(!prev)
					head1=current;
				prev=current;
				current=next;
				next=next->sibling;
			}
			else
			{
				if(next->sibling && next->sibling->degree==current->degree)
				{
					if(!prev)
						head1=current;
					prev=current;
					current=next;
					next=next->sibling;
				}
				else
				{
					if(current->data>next->data)
					{
						if(prev)
							prev->sibling=next;
						current->sibling=NULL;
						link(next, current);
						current=next;
						next=next->sibling;
					}
					else
					{
						current->sibling=next->sibling;
						next->sibling=NULL;
						link(current, next);
						next=current->sibling;
					}
				}
			}
		}
		if(!prev)
			head1=current;
		return head1;
	}
	
	void link(node *root1, node *root2)
	{
		root1->degree++;
		root2->parent=root1;
		if(!root1->child)
		{
			root1->child=root2;
			return;
		}
		root1=root1->child;
		while(root1->sibling)
			root1=root1->sibling;
		root1->sibling=root2;
	}

    /**
     * print the heap 
     
    void DisplayHeap()
    {

    cout << endl;
    int* pos = &data[0];
    cout<<"Heap -->  ";
    while (*pos != data[0])
    {
        cout<<*pos<<" ";
        pos++;
    }
    cout<<endl;
    } */
	
	node *extractmin()
	{
		node *temp;
		node *x;
		if(!head)
			return NULL;
		getmin(temp);
		if(temp==head)
		{
			head=head->sibling;
			if(!head && temp->degree==0)
				return temp;
		}
		else
		{
			x=head;
			while(x->sibling!=temp)
				x=x->sibling;
			x->sibling=x->sibling->sibling;
		}
		temp->sibling=NULL;
		x=temp->child;
		while(x)
		{
			x->parent=NULL;
			x=x->sibling;
		}
		x=temp->child;
		temp->child=NULL;
		head=merge(head, x);
		head=align(head);
		temp->degree=0;
		return temp;
	}
	
	void getmin(node *&minimum)
	{
		int min;
		node *temp;
		temp=head;
		min=head->data;
		minimum=head;
		head=head->sibling;
		while(head)
		{
			if(head->data<min)
			{
				min=head->data;
				minimum=head;
			}
			head=head->sibling;
		}
		head=temp;
	}
	
	bool found(node *root, int key)
	{
		if(!root)
			return false;
		while(root)
		{
			if(root->data==key)
			{
				root->data=INT_MIN;
				while(root->parent)
				{
					root->data=root->parent->data;
					root->parent->data=INT_MIN;
					root=root->parent;
				}
				return true;
			}
			else if(root->data<key)
				if(found(root->child, key))
					return true;
			root=root->sibling;
		}
		return false;
	}
	
	bool search(node *root, int key, node *&temp)
	{
		if(!root)
			return false;
		while(root)
		{
			if(root->data==key)
			{
				temp=root;
				root->data=INT_MIN;
				while(root->parent)
				{
					root->data=root->parent->data;
					root->parent->data=INT_MIN;
					root=root->parent;
				}
				return true;
			}
			else if(root->data<key)
				if(found(root->child, key))
					return true;
			root=root->sibling;
		}
		return false;
	}
};

int main()
{
	
	binomialheap bh;
	binomialheap bh1;
	node *root;
	int i;
	int size; 
	char ch;
	char ch1;
	int x;
	ch='1';

	/*

	// enter size of the first heap
	cout << endl << "Enter the size of your heap ";
	cin >> size;


	// make heap 1
	// insert data 
	for(i = 0; i < size; i++) {
		cout << endl << "Enter your data for heap 1: ";
		cin >> x;
		root = bh.createnode(x);
		bh.insert(root);
	}

	// print heap 1
	cout << "The first heap is: ";
	for(i = 0; i < size; i++){
		//cout << ;
	}

	// make heap 2
	// insert data 
	for(i = 0; i < size; i++) {
		cout << endl << "Enter your data for heap 1: ";
		cin >> x;
		root = bh1.createnode(x);
		bh1.insert(root);
	}

	// merge the heaps
	bh.insert(bh1.head);	

	*/


	// I DONT LIKE THIS WAY... 	
	while(ch!='0')
	{
		cout<<"Enter your choice"<<endl;
		cout<<"Press '1' to insert"<<endl;
		cout<<"Press '2' to printmin"<<endl;
		cout<<"Press '3' to print head node"<<endl;
		cout<<"Press '4' to merge two binomial heaps"<<endl;
		cout<<"Press '5' to extract minimum"<<endl;
		cout<<"Press '6' to delete a key"<<endl;
		cout<<"Press '7' to decrease a key"<<endl;
		cout<<"Press '0' to exit\t";
		cin>>ch;
		switch(ch)
		{
			case '0':
				break;
			case '1':
			{
				cout<<endl<<"Enter data to be entered\t";
				cin>>x;
				root=bh.createnode(x);
				bh.insert(root);
				break;
			}
			case '2':
			{
				x=bh.printmin();
				if(x==INT_MAX)
					cout<<"Empty"<<endl;
				else cout<<endl<<x<<endl;
				break;
			}
			case '3':
			{
				x=bh.printheadnode();
				if(x==INT_MAX)
					cout<<"Empty"<<endl;
				else cout<<endl<<x<<endl;
				break;
			}
			case '4':
			{
				ch1='5';
				while(ch1!='0')
				{
					cout<<"Enter your choice"<<endl;
					cout<<"Press '1' to insert"<<endl;
					cout<<"Press '2' to printmin"<<endl;
					cout<<"Press '3' to print head node"<<endl;
					cout<<"Press '0' to exit\t";
					cin>>ch1;
					switch(ch1)
					{
						case '0':
							break;
						case '1':
						{
							cout<<endl<<"Enter data to be entered\t";
							cin>>x;
							root=bh1.createnode(x);
							bh1.insert(root);
							break;
						}
						case '2':
						{
							x=bh1.printmin();
							if(x==INT_MAX)
								cout<<"Empty"<<endl;
							else cout<<endl<<x<<endl;
							break;
						}
						case '3':
						{
							x=bh1.printheadnode();
							if(x==INT_MAX)
								cout<<"Empty"<<endl;
							else cout<<endl<<x<<endl;
							break;
						}
						default:
							cout<<endl<<"Invalid input"<<endl;
					}
				}
				bh.insert(bh1.head);
				break;
			}
			case '5':
			{
				root=bh.extractmin();
				if(!root)
					cout<<endl<<"empty"<<endl;
				else cout<<endl<<root->data<<endl;
				break;
			}
			case '6':
			{
				cout<<endl<<"Enter key to be deleted\t";
				cin>>x;
				if(!bh.found(bh.head, x))
					cout<<endl<<"Not found"<<endl;
				else
					bh.extractmin();
				break;
			}
			case '7':
			{
				cout<<endl<<"Enter key to be decreased\t";
				cin>>x;
				if(!bh.search(bh.head, x, root))
					cout<<endl<<"Not found"<<endl;
				else
				{
					cout<<"Enter data to replaced\t";
					cin>>x;
					cout<<endl;
					root->data=x;
					while(root->parent && root->data<root->parent->data)
					{
						x=root->data;
						root->data=root->parent->data;
						root->parent->data=x;
						root=root->parent;
					}
					while(root->child && root->child->data<root->data)
					{
						x=root->data;
						root->data=root->child->data;
						root->child->data=x;
						root=root->child;
					}
				}
				break;
			}
			default:
				cout<<endl<<"Invalid input"<<endl;
		}
	}
	return 0;  
}