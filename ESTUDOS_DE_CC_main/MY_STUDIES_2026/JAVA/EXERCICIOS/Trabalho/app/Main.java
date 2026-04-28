package app;

import model.*;

public class Main {
    public static void main(String[] args) {
        // Criando os objetos
        Medico medico = new Medico("Dr. Silva", "Cardiologia");
        Paciente paciente1 = new Paciente("João", true);  // Tem plano
        Paciente paciente2 = new Paciente("Maria", false); // Não tem plano

        // Criando as situações de cobrança
        Consulta cPlano = new ConsultaPlano();
        Consulta cParticular = new ConsultaParticular();

        System.out.println("--- RECIBOS DE CONSULTA ---");

        // Executando a lógica
        System.out.println("Médico: " + medico.getNome());
        
        System.out.println("Paciente: " + paciente1.getNome());
        System.out.println("Cobrança (Plano): R$ " + cPlano.calcularValor(paciente1));
        
        System.out.println("---------------------------");

        System.out.println("Paciente: " + paciente2.getNome());
        System.out.println("Cobrança (Particular): R$ " + cParticular.calcularValor(paciente2));
    }
}
