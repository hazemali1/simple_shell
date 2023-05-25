#include "shell.h"

/**
 * main - Main function
 *
 * @argc: P1
 * @argv: P2
 *
 * Return: Always 0
*/
int main(int argc, char *argv[])
{
	char *buff[1024], *buf, *Buff, *BUf = NULL,
		*home = my_getenv("HOME"), **REad, symo[1024], *Echo, ec[1024];
	ssize_t size_getline;
	size_t d = 0;
	pid_t s, pid;
	int w = -1, size = 1, e = 0, non = 0, cd = 0, ch = -1, v = 0, er = 0,
	    f = 0, i = 0, fr = 0, _cd = 0, sy = 0, che = 1, count = 0, Ec = 1,
	    status, And = 0, pop = 0, Sta = 0, Ee = 0;
	path_node *node = NULL, *head, *h;
	struct stat Buf;

	Echo = malloc(sizeof(char) * 1024);
	Ee = 1;
	if (Echo == NULL)
		exit(1);
	if (isatty(STDIN_FILENO) == 0)
		non = 1;
	if (argc == 2)
		REad = read_file(argv[1], &non, &f);
	head = get_path_list();
while (1)
{
	if (non == 0 && count == 0)
		write(STDOUT_FILENO, "($) ", 4);
	if (f == 0 && count == 0)
		buf = read_input(&size_getline);
	else if (count != 0)
		buf = my_buff(symo, &size_getline, &count);
	else
		buf = read_file_as_input(&fr, &size_getline, REad, &i, &f);
	parse_input(buf, symo, &pop, &And, &count);
	Buff = handle_input(buf, &er, &w, &e, &cd, &v, &Buf, &sy, &Sta);
	parse_command(BUf, buf, buff, &size, Buff, &w, &e);
	if (e == 0)
		handle_echo(buff, Buff, ec, &Ec, Echo, &w, &v, &pid, &status);
	handle_exit(buf, buff, node);
	if (cd == 1)
		ch_dir(buff, home, symo, &count, &_cd, &Sta, &Buf, &ch);
	h = head;
	if(w == -1 && h != NULL)
		Buff = set_path(h, &w, &size_getline, buff, &Buf);
	handle_error(&w, &non, buff, Buff, argv[1], &Sta, &er, &sy);
	if (w == 0 && e == 0 && cd == 0 && v == 0)
		execute_command(buff, &s, &status);
if (er == 1)
	free(Buff);
if (Ee == 1)
{
	free(Echo);
	Ee = 0;
}
free(head)
reset_arr(&count, &status, &Sta, &And, &pop, symo);
reset(&Sta, &pop, &And, &Ec, &che, &sy, &_cd, &v, &cd, &e, &w, &size, &d);
free_buf(&fr, &count, buf, &f, node);
}
	_free(node);
	return (0);
}
