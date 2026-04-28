package model;

public class ConsultaParticular extends Consulta {
    @Override
    public double calcularValor(Paciente p) {
        return valorBase + 50.0; // Valor com acréscimo
    }
}
