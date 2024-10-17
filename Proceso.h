#pragma once

class Proceso {
	private:
		int pid;
		int ppid;
		string inicio;
		string t_vida;
		int prioridad;
		int nucleo;
	public:
		Proceso(int pid, int ppid, string inicio, string t_vida, int prioridadm int nucleo);
		~Proceso();

};
