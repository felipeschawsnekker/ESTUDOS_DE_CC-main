package model;

public class Medico extends Pessoa {
    private String especialidade;

    public Medico(String nome, String especialidade) {
        super(nome); // Passa o nome para a classe Pessoa
        this.especialidade = especialidade;
    }

    public String getEspecialidade() { return especialidade; }
}
