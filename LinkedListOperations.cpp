#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node(int data) {
			this->data = data;
			this->next = NULL;
		}
};

Node *takeInput() {
	int data;
	cin>>data;
	Node *head = NULL, *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
		cin>>data;
	}
	return head;
}

void print(Node *head) {
	Node *temp = head;
	while(temp != NULL) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

void reverse(Node *head) {
	if(head == NULL) {
		return ;
	}
	reverse(head->next);
	cout<<head->data<<" ";
} 

Node *Sort(Node *head1, Node *head2) {
	if(head1 == NULL) {
		return head2;
	}
	if(head2 == NULL) {
		return head1;
	}
	Node *fh = NULL, *ft = NULL;
	while(head1 != NULL && head2 != NULL) {
		if(head1->data <= head2->data) {
			if(fh == NULL) {
				fh = head1;
				ft = head1;
				head1 = head1->next;
			} else {
				ft->next = head1;
				ft = ft->next;
				head1 = head1->next;
			}
		} else {
			if(fh == NULL) {
				fh = head2;
				ft = head2;
				head2 = head2->next;
			} else {
				ft->next = head2;
				ft = ft->next;
				head2 = head2->next;
			}
		}
	}
	while(head1 != NULL) {
		ft->next = head1;
		ft = ft->next;
		head1 = head1->next;
	}
	while(head2 != NULL) {
		ft->next = head2;
		ft = ft->next;
		head2 = head2->next;
	}
	return fh;
}

Node *mergeSort(Node *head) {
	if(head == NULL || head->next == NULL) {
		return head;
	}
	Node *temp = head, *temp1 = head, *head2;
	int a, count = 0;
	while(temp != NULL) {
		temp = temp->next;
		count++;
	}
	a = (count-1)/2;
	while(a) {
		temp1 = temp1->next;
		a--;
	}
	head2 = temp1->next;
	temp1->next = NULL;
	Node *first = mergeSort(head);
	Node *second = mergeSort(head2);
	Node *sorted = Sort(first, second);
	return sorted;
}

Node *reverse1(Node *head) {
	if(head == NULL || head->next == NULL) {
		return head;
	}
	Node *temp = reverse1(head->next);
	Node *temprev = temp;
	while(temprev->next != NULL) {
		temprev = temprev->next;
	}
	temprev->next = head;
	head->next = NULL;
	return temp;
}

bool check(Node *head) {
	Node *temp = head, *temp1 = head, *head2;
	int a, count = 0;
	while(temp != NULL) {
		temp = temp->next;
		count++;	
	}
	a = (count-1)/2;
	while(a) {
		temp1 = temp1->next;
		a--;
	} 
	head2 = temp1->next;
	temp1->next = NULL;
	Node *rev = reverse1(head2);
	while(head != NULL && rev != NULL) {
		if(head->data != rev->data) {
			return false;
		}
		head = head->next;
		rev = rev->next;
	}
	return true;
}

int main() {
	Node *head = takeInput();
	cout<<endl;
	cout<<"Printing all the nodes"<<endl;
	print(head);
	cout<<endl;
	cout<<endl;
	cout<<"Reversing all the nodes"<<endl;
	reverse(head);
//	cout<<endl;
//	cout<<endl;
//	cout<<"After merge sort"<<endl;
//	head = mergeSort(head);
//	print(head);
	cout<<endl;
	cout<<endl;
	cout<<"Checking whether linked list is palindrome or not"<<endl;
	bool ans = check(head);
	if(ans) {
		cout<<"Yes";
	} else {
		cout<<"No";
	}
	return 0;
}
