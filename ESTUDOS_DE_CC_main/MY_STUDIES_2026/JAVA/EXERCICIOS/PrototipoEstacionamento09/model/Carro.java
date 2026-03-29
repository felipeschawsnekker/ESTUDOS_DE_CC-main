
package ESTUDOS_DE_CC_main.MY_STUDIES_2026.JAVA.EXERCICIOS.PrototipoEstacionamento09.model;



public class Carro extends Veiculo{

    public Carro(String modelo, String placa){
        super(modelo,placa);
    }
    @Override
    public int getValorPorHora(){
        if(getFidelizado()==true){
        System.out.println("Veiculo fidelizado!");
        return 4;
    }
        else{
            return 5;
        }
}
}
