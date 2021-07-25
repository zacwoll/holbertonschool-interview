#include "lists.h"

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL)
		return (head);

	slow = head;
	fast = head;

	while (next_two_nodes_exists(fast))
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
	}
	return (NULL);
}

int next_two_nodes_exists(listint_t *fast)
{
	if (fast == NULL)
		return (0);

	if (fast->next == NULL)
		return (0);

	if (fast->next->next == NULL)
		return (0);

	return (1);
}