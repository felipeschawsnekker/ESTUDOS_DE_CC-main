/* Objetivo:
Desenvolver um sistema simples em Java para registrar veículos em um estacionamento e calcular o valor a pagar com base no tempo.
Passos principais:
Modelagem do veículo:
Criar uma classe Veículo com atributos essenciais:
Placa ou identificação (String)
Tipo de veículo (carro, moto)
Hora de entrada (int ou double)
Hora de saída (int ou double)
Status de estacionamento (boolean)
Comportamentos (métodos):
Entrada: registrar dados do veículo e atualizar status para estacionado = true.
Saída: calcular valor a pagar baseado em horas e preço por hora, atualizar status para false.
Exibir dados: imprimir informações do veículo e recibo.
Validações:
Não permitir hora de saída menor que a entrada → retorna 0 e exibe erro.
Só finalizar se estacionado == true.
Regras adicionais (desafios):
Diferenciar valores por tipo de veículo (carro, moto).
Aplicar desconto para clientes fidelizados.
Garantir que o estoque de vagas/tempo não fique inconsistente.
Demonstração:
Criar pelo menos dois veículos diferentes.
Mostrar recibo com dados e valor total. 

O sistema de estacionamento cresceu!
Agora, para seguir as boas práticas do mercado, precisamos
organizar o caos de arquivos soltos e garantir que dados
sensíveis (como o faturamento) não sejam acessados por
qualquer classe.
Aula 09

Exercício

● Crie as pastas físicas no seu projeto: model e app.
● Mova os arquivos: * Veiculo.java, Carro.java e Moto.java → para
a pasta model.
● Principal.java → para a pasta app.
● Declare o endereço: Adicione a instrução package na primeira
linha de cada arquivo conforme sua pasta.
● Resolva o Conflito: A classe Principal agora dará erro de
compilação. Use o import correto para conectar as classes
novamente.

Aula 09

Exercício

● Ocultação Total: No arquivo Veiculo.java, mude o atributo placa para
private.
● Pergunta: A Principal ainda consegue ler a placa diretamente? O que você
deve criar para permitir a leitura segura?
● O Segredo de Pacote (Default): Remova o modificador public do método
calcularCobranca na classe Veiculo (deixe sem nada).
● Desafio: Tente chamar esse método de dentro da Principal (que está no
pacote app). O que o Java diz?
● Acesso de Herança: Mude o valorHora para protected.

Aula 09

Exercício

● Ocultação Total: No arquivo Veiculo.java, mude o atributo placa para
private.
● Pergunta: A Principal ainda consegue ler a placa diretamente? O que você
deve criar para permitir a leitura segura?
● O Segredo de Pacote (Default): Remova o modificador public do método
calcularCobranca na classe Veiculo (deixe sem nada).
● Desafio: Tente chamar esse método de dentro da Principal (que está no
pacote app). O que o Java diz?
● Acesso de Herança: Mude o valorHora para protected.

*/


public class Veiculo{
    private String placa;
    private String modelo;
    private double total,entrada,saida;
    private int valor_por_hora=4;
    private static int VeiculosAtuais=0;
    private static final int LimiteVagas=6;
    boolean status;
    boolean fidelizado;

    public int getValorPorHora(){
        return this.valor_por_hora;
    }
    //getter
    public boolean getFidelizado(){
        return this.fidelizado;
    }

    public void setFidelizado(boolean fidelizado) {
    this.fidelizado = fidelizado;
}
    public Veiculo(String modelo, String placa){
    this.modelo = modelo;
    this.placa = placa;
    this.status = false; 
    this.fidelizado = false;
}

public Veiculo(String placa) {
    this("Generico", placa); 
}

    public void Estacionar(double entrada){
        this.entrada=entrada;
        if(VeiculosAtuais<LimiteVagas){
        VeiculosAtuais++;
        this.status=true;
        System.out.println("O modelo "+this.modelo+",com placa "+this.placa+" estacionou! Entrada: "+this.entrada+"h");
        }
        else{
            System.out.println("Limite de veiculos estacionados");
            return;
        }
    }      
        

    

    public void Sair(double saida) {
    if(!status) {
        System.out.println("Este veículo não está estacionado!");
        return;
    }
    this.saida = saida;
    total = saida - entrada;

    System.out.println("O modelo " + this.modelo + ", com placa " + this.placa + " saiu! Saída: " + this.saida + "h");
    if(total >= 0) {
        double valor = this.total * getValorPorHora();
        System.out.println("Horário de permanência: " + this.total + "h | Valor a ser pago: " +"R$"+valor+"\n");
        this.status = false;
        VeiculosAtuais--;
    } else {
        System.out.println("Horário inválido");
    }
}
}

    
    
    
        




    