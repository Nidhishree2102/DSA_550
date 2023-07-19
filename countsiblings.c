#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}


int height(Node* node)
{
    if (node == NULL)
    return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
        return (lheight + 1);
        else
        return (rheight + 1);
    }
}

void printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
    return;
    if (level == 1)
    printf("%d     ", root->data);
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(Node* root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printCurrentLevel(root, i);
        printf("\n");
    }
}

int main()
{
    Node* root = NULL;
    FILE* file = fopen("numbers.txt", "w");

    srand(time(0));
    int lower=1,upper=100,count=10;
    int arr[count];

    printf("The random nos are\n");
    for(int j=0;j<count;j++)
    {
        arr[j]=(rand()%(upper-lower+1))+lower;
        fprintf(file,"%d ",arr[j]);
        printf("%d ",arr[j]);
    }

    for (int i = 0; i < count; i++)
    {
        root = insert(root, arr[i]);
    }


    printf("\n\n");
    printLevelOrder(root);

    fclose(file);

    return 0;
}
