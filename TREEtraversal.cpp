#include<bits/stdc++.h>
using namespace std;

map < int, vector<int> > M;

struct s
{
	struct s *left;
	int data;
	struct s *right;
};
typedef struct s node;
node* BST(node *head,int value)
{
	if(head==NULL)
	{
		node *p=(node*)malloc(sizeof(node));
		p->data=value;
		p->left=p->right=NULL;
		head=p;
		return head;
	}
	//node *p=head;
	
	if(value>head->data)
	head->right=BST(head->right,value);
	else
	head->left=BST(head->left,value);
	return head;
}
void inorder(node *head)
{
	if(head==NULL)
	return;
	inorder(head->left);
	cout<<head->data;
	inorder(head->right);
}
void pre(node *head)
{
	if(head==NULL)
	return;
	cout<<head->data;
	pre(head->left);
	pre(head->right);
}
void post(node *head)
{
	if(head==NULL)
	return;
	post(head->left);
	post(head->right);
	cout<<head->data;
}
void VerticalTraversal(node *head,int level)
{
	if(head==NULL)
	return;
	M[level].push_back(head->data);
	VerticalTraversal(head->left,level-1);
	VerticalTraversal(head->right,level+1);
}

void galaxyVT(node *root){
	queue< pair< node *, int> > q;
	q.push(make_pair(root, 0));
	while(!q.empty()){
		pair< node *, int> top = q.front();
		q.pop();
		
		if(top.first==NULL) continue;
		
		M[top.second].push_back(top.first->data);
		q.push(make_pair(top.first->left, top.second-1));
		q.push(make_pair(top.first->right, top.second+1));
	}
}

int main()
{
	int a;
	node *head;
	head='\0';
	/*//head=(node*)malloc(sizeof(node));
	//head->data=2;
	//head->left=head->right='\0';
	head=BST(head,5);
	head=BST(head,6);
	head=BST(head,4);
	head=BST(head,3);
	head=BST(head,7);
	//inorder(head);*/
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a, head=BST(head,a);
	// VerticalTraversal(head,0);
	galaxyVT(head);
	map<int , vector<int> >::iterator it;
	for(it=M.begin();it!=M.end();it++)
	{
		vector <int>::iterator pt;
		for(pt=(it->second).begin();pt!=(it->second).end();pt++)
		{
			cout<<*pt<<" ";
		}
		cout<<endl;
	}
	cout<<"TOP VIEW"<<endl;
	for(it=M.begin();it!=M.end();it++)
	{
		vector <int>::iterator pt;
		pt=(it->second).begin();
		cout<<*(pt);
		cout<<endl;
	}
	cout<<"BOTTOM VIEW"<<endl;
	for(it=M.begin();it!=M.end();it++)
	{
		vector <int>::iterator pt;
		int p=(it->second).size()-1;
		cout<<(it->second)[p];
		cout<<endl;
	}
}
