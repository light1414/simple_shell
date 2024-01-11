#include "main.h"

/**
 * get_error - Calls the error as the builtin, syntax or access
 * @datash: data stur that contains arguments
 * @eval_rr: error numb
 * Return: error
 */
int get_error(data_shell *datash, int eval_rr)
{
	char *error;

	switch (eval_rr)
	{
	case -1:
		error = error_env(datash);
		break;
	case 126:
		error = error_path_126(datash);
		break;
	case 127:
		error = error_not_found(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			error = error_exit_shell(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			error = error_get_cd(datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = eval_rr;
	return (eval_rr);
}
