#include "main.h"

/**
 * add_rvar_node - adds  var at the end
 * of a r_var list.
 * @head: Head of the linked list.
 * @lvar: The length of the variable.
 * @val: val of the var.
 * @lval: length of the val.
 * Return: the address of the head.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *tmp;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}

	return (*head);
}

/**
 * free_rvar_list - Frees a r_var list
 * @head: Head of the linked list.
 * Retuirn: no return.
 */
void free_rvar_list(r_var **head)
{
	r_var *tmp;
	r_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((tmp = curr) != NULL)
		{
			curr = curr->next;
			free(tmp);
		}
		*head = NULL;
	}
}
