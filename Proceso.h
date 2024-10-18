#pragma once

class Proceso {
	private:
		int pid;
		int ppid;
		int inicio;
		int t_vida;
		int prioridad;

	public:
		Proceso(int pid, int ppid, int inicio, int t_vida, int prioridad);
		int getPID();
		int getPPID();
		int getInicio();
		int getTiempoVida();
		int getPrioridad();
		
};
