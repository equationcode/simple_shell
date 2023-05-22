#include "manshell.h"
/**
 * cmd_exec - Executes a command by creating a new
 * process using fork() and execvp().
 *
 * @arg: Array of pointers to the arguments
 * of the command.
 *
 * Return: Nothing.
 */

void cmd_exec(char **arg)
{
	pid_t my_id;

	if (arg[0] == NULL)
		return;
	my_id = fork();
	if (my_id == 0)
	{
		execvp(arg[0], arg);
		perror(arg[0]);
		exit(1);
	}
	else if (my_id > 0)
		wait(NULL);
	else
	{
		perror("fork");
		exit(1);
	}
}
