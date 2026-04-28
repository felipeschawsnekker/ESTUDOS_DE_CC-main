package model;

// Situação 1: Consulta via Plano de Saúde
public class ConsultaPlano extends Consulta {
    @Override
    public double calcularValor(Paciente p) {
        return valorBase * 0.2; // O paciente paga apenas 20% de taxa de coparticipação
    }
}

// Situação 2: Consulta Particular (Com acréscimo)
public class ConsultaParticular extends Consulta {
    @Override
    public double calcularValor(Paciente p) {
        return valorBase + 50.0; // Taxa adicional de conveniência
    }
}
