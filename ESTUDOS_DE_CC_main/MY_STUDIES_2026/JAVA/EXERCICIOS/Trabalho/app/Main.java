package app;

import java.util.Scanner;
import model.*;

public class Main {
    public static void main(String[] args) {
System.out.println("VERSAO COM SCANNER!!!");
        Scanner sc = new Scanner(System.in);

        // Dados do médico
        System.out.print("Digite o nome do médico: ");
        String nomeMedico = sc.nextLine();

        System.out.print("Digite a especialidade: ");
        String especialidade = sc.nextLine();

        Medico medico = new Medico(nomeMedico, especialidade);

        System.out.println("\n=== CADASTRO DE PACIENTES ===");

        // Paciente 1
        System.out.print("Nome do paciente 1: ");
        String nomeP1 = sc.nextLine();

        System.out.println("Paciente 1 tem plano?");
        System.out.println("1 - Sim");
        System.out.println("2 - Não");
        int opcaoP1 = sc.nextInt();
        sc.nextLine(); // limpar buffer

        boolean planoP1;
        if (opcaoP1 == 1) {
            planoP1 = true;
        } else {
            planoP1 = false;
        }

        Paciente p1 = new Paciente(nomeP1, planoP1);

        System.out.println("---------------------------");

        // Paciente 2
        System.out.print("Nome do paciente 2: ");
        String nomeP2 = sc.nextLine();

        System.out.println("Paciente 2 tem plano?");
        System.out.println("1 - Sim");
        System.out.println("2 - Não");
        int opcaoP2 = sc.nextInt();

        boolean planoP2;
        if (opcaoP2 == 1) {
            planoP2 = true;
        } else {
            planoP2 = false;
        }

        Paciente p2 = new Paciente(nomeP2, planoP2);

        System.out.println("\n=== RECIBOS DE CONSULTA ===");
        System.out.println("Médico: " + medico.getNome());

        System.out.println("---------------------------");

        // Consulta paciente 1
        Consulta c1;
        if (p1.isTemPlano()) {
            c1 = new ConsultaPlano();
        } else {
            c1 = new ConsultaParticular();
        }

        System.out.println("Paciente: " + p1.getNome());
        System.out.println("Valor: R$ " + c1.calcularValor(p1));

        System.out.println("---------------------------");

        // Consulta paciente 2
        Consulta c2;
        if (p2.isTemPlano()) {
            c2 = new ConsultaPlano();
        } else {
            c2 = new ConsultaParticular();
        }

        System.out.println("Paciente: " + p2.getNome());
        System.out.println("Valor: R$ " + c2.calcularValor(p2));

        sc.close();
    }
}
