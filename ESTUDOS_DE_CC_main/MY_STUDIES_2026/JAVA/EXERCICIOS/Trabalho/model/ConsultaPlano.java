package model;

public class ConsultaPlano extends Consulta {
    @Override
    public double calcularValor(Paciente p) {
        return valorBase * 0.2; // 20% do valor
    }
}
