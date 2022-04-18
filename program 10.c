//-----binary search tree------//

#include <stdio.h>
#include <stdlib.h>
int flag=0;
//-----BST struct-------//
typedef struct bst{
    int data;
    struct bst *lchild,*rchild;
}node;
//----functions--------//
void insert(node *,node*);
void inorder(node*);
void preorder(node*);
void postorder(node*);
//---//
node*search(node*,int,node**);

//-----main program-----//
int main()
{
    int choice,ans=1,key;
    node*new,*root,*tmp,*parent;
    node*get_node();
    root=NULL;
    do{
        printf("\n1.create\n2.search\n3.recursive traversal\n4.exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:do{
                new=get_node();
                printf("\nEnter the Data:");
                scanf("%d",&new->data);
                if(root==NULL)
                root=new;
                else
                insert(root,new);
                printf("\nwant to insert more node?(0/1)\n");
                scanf("%d",&ans);
                }while(ans);
                break;
            
            case 2:
                printf("\nenter the element to search:");
                scanf("%d",&key);
                tmp=search(root,key,&parent);
                if(flag==1){
                    printf("\nThe parent node of %d is %d",tmp->data,parent->data);
                }
                else{
                    printf("\nThe %d Element is not found...!!!",key);
                }
                flag=0;
                break;
            case 3:
                if(root==NULL)
                printf("tree is empty");
                else{
                    printf("\ninorder:");
                    inorder(root);
                    printf("\npreorder:");
                    preorder(root);
                    printf("\npostorder:");
                    postorder(root);
                    
                }
                break;
            default:printf("\ninvalid choice...!!!");
                    break;
        }
        
    }while(choice!=4);
    
    return 0;
}
//---get node-----//
node*get_node(){
    node*temp;
    temp=(node*)malloc(sizeof(node));
    //temp->data=NULL;
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}

//-------insert-------//
void insert(node*root,node*new){
    if(new->data<root->data)
    {
        if(root->lchild==NULL)
        root->lchild=new;
        else
        insert(root->lchild,new);
    }
    if(new->data>root->data)
    {
        if(root->rchild==NULL)
        root->rchild=new;
        else
        insert(root->rchild,new);
    }
}

//-------search---------//
node*search(node*root,int key,node**parent)
{
    node*temp;
    temp=root;
    while(temp!=NULL)
    {
        if(key==temp->data)
        {
            flag=1;
            printf("\nThe Element %d is present",temp->data);
            return temp;
        }
        *parent=temp;
        if(temp->data>key)
            temp=temp->lchild;
        else
            temp=temp->rchild;
    }
    return NULL;
}

//------inorder---------//
void inorder(node*root){
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("%d\t",root->data);
        inorder(root->rchild);
    }
}
//-------preorder-------//
void preorder(node*root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
//-------postorder-------//
void postorder(node*root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d\t",root->data);
    }
}
