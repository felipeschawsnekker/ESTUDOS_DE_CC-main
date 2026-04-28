package model;

public class Consulta {
    protected double valorBase = 100.0; // Valor padrão para qualquer consulta

    // Método que será alterado pelas classes filhas (Polimorfismo)
    public double calcularValor(Paciente p) {
        return valorBase; 
    }
}
