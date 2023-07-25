#include "sort.h"
/**
 * insertion_sort_list - insert an element in a sorted list
 * @list: list
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux, *temp, *ayu;

	if (!list || !*list)
		return;
	aux = *list;
	while (aux->next)
	{
		if (aux->n > (aux->next)->n)
		{
			temp = aux->next, aux->next = temp->next;
			if (temp->next)
				(temp->next)->prev = aux;
			temp->prev = aux->prev;
			if (aux->prev)
				(aux->prev)->next = temp;
			aux->prev = temp, temp->next = aux;
			if (!(temp->prev))
				*list = temp;
			print_list(*list);
			while (temp->prev)
			{
				if (temp->n < (temp->prev)->n)
				{
					ayu = temp->prev, temp->prev = ayu->prev;
					(temp->next)->prev = ayu, ayu->next = temp->next;
					temp->next = ayu;
					if (ayu->prev)
						(ayu->prev)->next = temp;
					ayu->prev = temp;
					if (!(temp->prev))
						*list = temp;
					print_list(*list);
				}
				else
					break;
			}
		}
		else
			aux = aux->next;
	}
}
