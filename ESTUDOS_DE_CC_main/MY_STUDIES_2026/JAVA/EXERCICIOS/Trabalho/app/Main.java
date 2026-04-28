package app;

import model.*;

public class Main {
    public static void main(String[] args) {

        Medico medico = new Medico("Dr. Silva", "Cardiologia");

        Paciente p1 = new Paciente("João", true);
        Paciente p2 = new Paciente("Maria", false);

        System.out.println("=== RECIBOS DE CONSULTA ===");
        System.out.println("Médico: " + medico.getNome());

        System.out.println("---------------------------");

        // Decide o tipo de consulta baseado no paciente
        Consulta c1;
        if (p1.isTemPlano()) {
            c1 = new ConsultaPlano();
        } else {
            c1 = new ConsultaParticular();
        }

        System.out.println("Paciente: " + p1.getNome());
        System.out.println("Valor: R$ " + c1.calcularValor(p1));

        System.out.println("---------------------------");

        Consulta c2;
        if (p2.isTemPlano()) {
            c2 = new ConsultaPlano();
        } else {
            c2 = new ConsultaParticular();
        }

        System.out.println("Paciente: " + p2.getNome());
        System.out.println("Valor: R$ " + c2.calcularValor(p2));
    }
}
