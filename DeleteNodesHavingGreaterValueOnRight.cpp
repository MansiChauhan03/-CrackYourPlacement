class Solution
{
    public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    Node *compute(Node *head)
    {
        if (!head) return NULL;

        head = reverse(head);
        Node *maxNode = head;
        Node *current = head;

        while (current != NULL && current->next != NULL)
        {
            if (current->next->data < maxNode->data)
            {
                Node *temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            else
            {
                // Update max node
                current = current->next;
                maxNode = current;
            }
        }

        head = reverse(head);
        return head;
    }
    
};
