#include <stdio.h>
#include <stdlib.h>


struct node
{
    int key;
    struct node* parent;
    struct node* left;
    struct node* right;
};

struct node * tree_search(struct node *root,int key)
{
    struct node* x=root;
    if(x==NULL)
    {
        return x;
    }
    while(x!=NULL&&key!=x->key)
    {
        if(key<x->key)
            x=x->left;
        else
            x=x->right;
    }
    return x;
}

struct node * minimum(struct node* x)
{
    if(x->left!=NULL)
        x=x->left;
    return x;
}

struct node * maximum(struct node* x)   
{
    if(x->right!=NULL)
        x=x->right;
    return x;
}

struct node * successor(struct node *x)
{
    if(x->right!=NULL)
    {
        return minimum(x->right);
    }
    struct node *y=x->parent;
    if(y!=NULL&&x==y->right)
    {
        x=y;
        y=y->parent;
    }
    return y;
}

struct node * predecessor(struct node *x)
{
    if(x->left!=NULL)
    {
        return maximum(x->left);
    }
    struct node *y=x->parent;
    if(y!=NULL&&x==y->left)
    {
        x=y;
        y=y->parent;
    }
    return y;
}

struct node *tree_insert(struct node **root,int key)
{
    struct node *x=*root;
    struct node *ret=(struct node*)malloc(sizeof(struct node));
    if(ret==NULL)
    {
        perror("malloc\n");
        return NULL;
    }
    ret->key=key;
    ret->left=NULL;
    ret->right=NULL;
    struct node *y=x;
    while(x!=NULL)
    {
        if(key<=x->key)
        {
            y=x;
            x=x->left;
        }
        else
        {
            y=x;
            x=x->right;
        }
    }
    if(y==NULL)
    {
        *root=ret;
        ret->parent=NULL;
    }
    else
    {
        ret->parent=y;
        if(key<=y->key)
            y->left=ret;
        else
            y->right=ret;
    }
    return ret;
}

struct node *tree_delete(struct node *root,struct node *del)
{
    struct node *x, *y;
    if(del->left==NULL||del->right==NULL)
    {
        y=del;
    }
    else
    {
        y=successor(del);
    }

    if(y->left!=NULL)
    {
        x=y->left;
    }
    else
    {
        x=y->right;
    }

    if(x)
    {
        x->parent=y->parent;
    }
    if(y->parent==NULL)
    {
        root=x;
    }
    if(y==y->parent->left)
    {
        x=y->parent->left;
    }
    else
    {
        x=y->parent->right;
    }
    if(y!=del)
    {
        del->key=y->key;
    }
    return y;

}

void tree_traverse(struct node *root)
{
    struct node* x=root;
    if(x!=NULL)
    {
        tree_traverse(x->left);
        printf("%d\n",x->key);
        tree_traverse(x->right);
    }
}

int main(void)
{
    struct node*root=NULL;
    tree_insert(&root,10);
    tree_insert(&root,7);
    tree_insert(&root,8);
    tree_insert(&root,13);
    tree_insert(&root,11);
    tree_traverse(root);
    return 0;
}
