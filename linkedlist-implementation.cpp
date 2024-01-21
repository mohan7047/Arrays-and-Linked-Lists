// By Mohan
#include <iostream>
using namespace std;

struct Node
{
    int row;
    int col;
    int value;
    Node *next;
};

void createSparseMatrixNode(Node **head, int row, int col, int value)
{

    Node *newNode = new Node;
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = nullptr;

    if (*head == nullptr)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printMatrixResult(Node *head)
{

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->row << " " << temp->col << " " << temp->value << endl;
        temp = temp->next;
    }
}

int main()
{

    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int matrix[rows][cols];
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    Node *head = nullptr;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] != 0)
            {
                createSparseMatrixNode(&head, i, j, matrix[i][j]);
            }
        }
    }

    printMatrixResult(head);

    return 0;
}
