#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
struct info{
	int id;
	string fname;
	float gpa;
	int age;
	float testscore;
};
struct node{
	info data;
	node *left,*right;
};

node *newnode(int a,string &b,int c,float d,float e)
{
	node *temp=new node;
	temp->data.id=a;
	temp->data.fname=b;
	temp->data.age=c;
	temp->data.gpa=d;
	temp->data.testscore=e;
	temp->left=temp->right=NULL;
	return temp;
}
node *insertion(node *Node,int a,string &b,int c,float d,float e)
{
	if (Node==NULL)
		return newnode(a,b,c,d,e);

	if(a<Node->data.id)
		Node->left=insertion(Node->left,a,b,c,d,e);
	else
		Node->right=insertion(Node->right,a,b,c,d,e);

	return Node;
}
node *search;
node *searching_id(node *temp,int ID)
{
	if(temp==NULL)
	{
		return NULL;
	}
	if(temp->data.id==ID)
	{
		search=temp;
		cout<<temp->data.id<<endl;
		cout<<temp->data.fname<<endl;
		cout<<temp->data.age<<endl;
		cout<<temp->data.testscore<<endl;
		cout<<temp->data.gpa<<endl;
	}
	temp->left=searching_id(temp->left,ID);
	temp->right=searching_id(temp->right,ID);
	return search;
}
node *searching_name(node *temp,string name)
{
	if(temp==NULL)
	{
		return NULL;
	}
	if(temp->data.fname==name)
	{
		search=temp;
		cout<<temp->data.id<<endl;
		cout<<temp->data.fname<<endl;
		cout<<temp->data.age<<endl;
		cout<<temp->data.testscore<<endl;
		cout<<temp->data.gpa<<endl;
	}
	temp->left=searching_name(temp->left,name);
	temp->right=searching_name(temp->right,name);
	return search;
}
node *searching_age(node *temp,int AGE)
{
	if(temp==NULL)
	{
		return NULL;
	}
	if(temp->data.age==AGE)
	{
		search=temp;
		cout<<temp->data.id<<endl;
		cout<<temp->data.fname<<endl;
		cout<<temp->data.age<<endl;
		cout<<temp->data.testscore<<endl;
		cout<<temp->data.gpa<<endl;
	}
	temp->left=searching_age(temp->left,AGE);
	temp->right=searching_age(temp->right,AGE);
	return search;
}
node *searching_cgpa(node *temp,float cgpa)
{
	if(temp==NULL)
	{
		return NULL;
	}
	if(temp->data.gpa==cgpa)
	{
		search=temp;
		cout<<temp->data.id<<endl;
		cout<<temp->data.fname<<endl;
		cout<<temp->data.age<<endl;
		cout<<temp->data.testscore<<endl;
		cout<<temp->data.gpa<<endl;
	}
	temp->left=searching_cgpa(temp->left,cgpa);
	temp->right=searching_cgpa(temp->right,cgpa);
	return search;
}
node *searching_testscore(node *temp,float ts)
{
	if(temp==NULL)
	{
		return NULL;
	}
	if(temp->data.testscore==ts)
	{
		search=temp;
		cout<<temp->data.id<<endl;
		cout<<temp->data.fname<<endl;
		cout<<temp->data.age<<endl;
		cout<<temp->data.testscore<<endl;
		cout<<temp->data.gpa<<endl;
	}
	temp->left=searching_testscore(temp->left,ts);
	temp->right=searching_testscore(temp->right,ts);
	return search;
}
void inorder(node *temp)
{
	if(!temp)
		return;
	inorder(temp->left);
	cout<<temp->data.id<<endl;
	cout<<temp->data.fname<<endl;
	cout<<temp->data.age<<endl;
	cout<<temp->data.testscore<<endl;
	cout<<temp->data.gpa<<endl;
	inorder(temp->right);
}
void preorder(node *temp)
{
	if(!temp)
		return;
	
	cout<<temp->data.id<<endl;
	cout<<temp->data.fname<<endl;
	cout<<temp->data.age<<endl;
	cout<<temp->data.testscore<<endl;
	cout<<temp->data.gpa<<endl;
	inorder(temp->left);
	inorder(temp->right);
}
void postorder(node *temp)
{
	if(!temp)
		return;
	inorder(temp->left);
	inorder(temp->right);
	cout<<temp->data.id<<endl;
	cout<<temp->data.fname<<endl;
	cout<<temp->data.age<<endl;
	cout<<temp->data.testscore<<endl;
	cout<<temp->data.gpa<<endl;
	
}
int height(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		int left1=height(root->left);
		int right1=height(root->right);
		if(left1>right1)
		{
			return(left1+1);
		}
		else
		{
			return(right1+1);
		}
	}
}
int nodeheight(node *temp,int ID,int a)
{
	int height1;
	
	if(temp==NULL)
	{
		return -1;
	}
	if(temp->data.id==ID)
	{

		return a;
	}
	height1=nodeheight(temp->left,ID,a++);
	if(height1!=-1)
	{
		return height1;
	}
	height1=nodeheight(temp->right,ID,a++);
	return height1;
}
int getheight(node *temp,int data)
{
	return nodeheight(temp,data,1);
}
node *deletion_id(node *temp,int ID)
{
	if(temp==NULL)
	{
		return temp;
	}
	if(ID<temp->data.id)
	{
		temp->left=deletion_id(temp->left,ID);
	}
	else if(ID>temp->data.id)
	{
		temp->right=deletion_id(temp->right,ID);
	}
	else
	{
		if(temp->left==NULL)
		{
			node *temp1=temp->right;
			free(temp);
			return temp1;
		}
		else if(temp->right==NULL)
		{
			node *temp1=temp->left;
			free(temp);
			return temp1;
		}
		node *temp1=minVALUE(temp->right);

		temp->data.id=temp1->data.id;
		temp->data.fname=temp1->data.fname;
		temp->data.age=temp1->data.age;
		temp->data.gpa=temp1->data.gpa;
		temp->data.testscore=temp1->data.testscore;

		temp->right=deletion_id(temp->right,temp->data.id);
	}
	return temp;
}
node *deletion_name(node *temp,string name)
{
	if(temp==NULL)
	{
		return temp;
	}
	if(name!=temp->data.fname)
	{
		temp->left=deletion_name(temp->left,name);
		temp->right=deletion_name(temp->right,name);
	}
	else
	{
		if(temp->left==NULL)
		{
			node *temp1=temp->right;
			free(temp);
			return temp1;
		}
		else if(temp->right==NULL)
		{
			node *temp1=temp->left;
			free(temp);
			return temp1;
		}
		node *temp1=minVALUE(temp->right);

		temp->data.id=temp1->data.id;
		temp->data.fname=temp1->data.fname;
		temp->data.age=temp1->data.age;
		temp->data.gpa=temp1->data.gpa;
		temp->data.testscore=temp1->data.testscore;

		temp->right=deletion_name(temp->right,temp->data.fname);
	}
	return temp;
}
node *deletion_cgpa(node *temp,float cgpa)
{
	if(temp==NULL)
	{
		return temp;
	}
	if(cgpa!=temp->data.gpa)
	{
		temp->left=deletion_cgpa(temp->left,cgpa);
		temp->right=deletion_cgpa(temp->right,cgpa);
	}
	else
	{
		if(temp->left==NULL)
		{
			node *temp1=temp->right;
			free(temp);
			return temp1;
		}
		else if(temp->right==NULL)
		{
			node *temp1=temp->left;
			free(temp);
			return temp1;
		}
		node *temp1=minVALUE(temp->right);

		temp->data.id=temp1->data.id;
		temp->data.fname=temp1->data.fname;
		temp->data.age=temp1->data.age;
		temp->data.gpa=temp1->data.gpa;
		temp->data.testscore=temp1->data.testscore;

		temp->right=deletion_cgpa(temp->right,temp->data.gpa);
	}
	return temp;
}
node *minVALUE(node *temp)
{
	node *current=temp;
	while(current->left!=NULL)
	{
		current=current->left;
	}
	return current;
}
void empty(node *temp)
{
	if (temp==NULL)
	{
		cout<<"empty"<<endl;
	}
	else
	{
		cout<<"Not empty"<<endl;
	}
}
int main()
{
	int y=0;
	int a;
	int a1,a3;
		string a2;
		float a4,a5;
	node *root=NULL;
	do
	{
		cout<<"enter 1 to insert the student data:"<<endl;
		cout<<"2 for order traversal:"<<endl;
		cout<<"	3 to search:"<<endl;
		cout<<"	4 to check tree height:"<<endl;
		cout<<"	5 to check height of particular node"<<endl;
		cout<<"6 to delete node:"<<endl;
		cout<<"7 to check empty:"<<endl;
		cout<<"0 to exit :"<<endl;
		cin>>a;
		if(a==1)
		{
			system("CLS");
			cout<<"enter id:"<<endl;
			cin>>a1;
			cout<<"enter name:"<<endl;
			cin>>a2;
			cout<<"enter age:"<<endl;
			cin>>a3;
			cout<<"enter gpa:"<<endl;
			cin>>a4;
			cout<<"enter testscore:"<<endl;
			cin>>a5;
			root=insertion(root,a1,a2,a3,a4,a5);
			y++;
		}
		if(a==2)
		{
			system("CLS");
			inorder(root);
			preorder(root);
			postorder(root);
		}
		if(a==3)
		{
			int x;
			int x1,x2;
			string x3;
			float x4,x5;
			cout<<"press 1 to search by id,2 to search by name,3 by age,4 by cgpa and 5 for testscore "<<endl;
			cin>>x;
			if(x==1)
			{
				cout<<"enter id :"<<endl;
				cin>>x1;
				searching_id(root,x1);
			}
			if(x==2)
			{
				cout<<"enter name :"<<endl;
				cin>>x3;
				searching_name(root,x3);
			}
			if(x==3)
			{
				cout<<"enter age :"<<endl;
				cin>>x2;
				searching_age(root,x2);
			}
			if(x==4)
			{
				cout<<"enter cgpa :"<<endl;
				cin>>x4;
				searching_cgpa(root,x4);
			}
			if(x==5)
			{
				cout<<"enter test score :"<<endl;
				cin>>x5;
				searching_testscore(root,x5);
			}
		}
		if(a==4)
		{
			cout<<height(root)<<endl;
		}
		if(a==5)
		{
			int a;
			system("CLS");
			cout<<"Enter the node id :"<<endl;
			cin>>a;
		
			cout<<"Height of node is:"<<getheight(root,a)<<endl;
				
		}
		if(a==6)
		{ int z1,z2;
		string z3;
		float z4;
		system("CLS");
			cout<<"press 1 to delete by id, 2 to delete by name , 3 to delete by cgpa"<<endl;
			cin>>z1;
			if(z1==1)
			{
				cout<<"enter id :"<<endl;
				cin>>z2;
				deletion_id(root,z2);
			}
			if(z1==2)
			{
				cout<<"enter name :"<<endl;
				cin>>z3;
				deletion_name(root,z3);
			}
			if(z1==3)
			{
				cout<<"enter cgpa :"<<endl;
				cin>>z4;
				deletion_cgpa(root,z4);
			}
		}
		if(a==7)
		{
			empty(root);
		}
	}
	while(a!=0);

	system("pause");
	return 0;
}
