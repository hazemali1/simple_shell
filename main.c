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
	char *buff[1024], *buf, *path, *tok, *Buff, *env, *BUf = NULL,
		*home = my_getenv("HOME"), **REad, symo[1024], *Echo, ec[1024];
	ssize_t size_getline;
	size_t d = 0;
	pid_t s, pid;
	int w = -1, size = 1, e = 0, non = 0, cd = 0, ch = -1, v = 0, er = 0,
	    f = 0, i = 0, fr = 0, _cd = 0, sy = 0, che = 1, count = 0, Ec = 1,
	    status, And = 0, pop = 0, Sta = 0;
	path_node *node, *head = get_path_list();
	struct stat Buf;

	if (isatty(STDIN_FILENO) == 0)
		non = 1;
	if (argc == 2)
		REad = read_file(argv[1], &non, &f);
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
	parse_input(buf, symo, &pop, &and, &count);
	handle_input(buf, Buff, &er, &w, &e, &cd, &v, &Buf, &sy, &Sta);
	parse_command(BUf, buf, env, buff, &size, Buff, &w, &e);
	if (e == 0)
		handle_echo(buff, Buff, ec, &Ec, Echo, &w, &v, &pid, &status);
	handle_exit(buf, buff, node);
	if (cd == 1)
		ch_dir(buff, home, symo, &count, &_cd, &Sta, &Buf, &ch);
	path_node *h = head;

	Buff = set_path(h, &w, &size_getline, buff, &Buf);
	handle_error(&w, &non, buff, Buff, argv[1], &Sta, &er, &sy);
	if (w == 0 && e == 0 && cd == 0 && v == 0)
		execute_command(buff, &s, &status);
reset_arr(&count, &status, &Sta, &and, &pop, symo);
reset(&Sta, &pop, &and, &Ec, &che, &sy, &_cd, &v, &cd, &e, &w, &size, &d);
free_buf(&fr, &count, buf, env, &f, node);
}
	_free(node);
	return (0);
}
